/*
 * Copyright (C) 2012  Free Software Foundation, Inc.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Authors:
 *	Paulo Cesar Pereira de Andrade
 */

#if defined(__linux__)
#  include <stdio.h>
#endif

#define rc(value)			jit_class_##value
#define rn(reg)				(jit_regno(_rvs[jit_regno(reg)].spec))

#define arm_patch_node			0x80000000
#define arm_patch_word			0x40000000
#define arm_patch_jump			0x20000000
#define arm_patch_load			0x00000000

#define jit_fpr_p(rn)			((rn) > 15)

/* Assume functions called never match jit instruction set, that is
 * libc, gmp, mpfr, etc functions are in thumb mode and jit is in
 * arm mode, what may cause a crash upon return of that function
 * if generating jit for a relative jump.
 */
#define jit_exchange_p()		1

/* FIXME is it really required to not touch _R10? */

/*
 * Types
 */
typedef union _jit_thumb_t {
    jit_int32_t		i;
    jit_int16_t		s[2];
} jit_thumb_t;

/*
 * Prototypes
 */
#define jit_get_reg_pair()		_jit_get_reg_pair(_jit)
static jit_int32_t _jit_get_reg_pair(jit_state_t*);
#define jit_unget_reg_pair(rn)		_jit_unget_reg_pair(_jit,rn)
static void _jit_unget_reg_pair(jit_state_t*,jit_int32_t);
#define load_const(uniq,r0,i0)		_load_const(_jit,uniq,r0,i0)
static void _load_const(jit_state_t*,jit_bool_t,jit_int32_t,jit_word_t);
#define flush_consts()			_flush_consts(_jit)
static void _flush_consts(jit_state_t*);
#define invalidate_consts()		_invalidate_consts(_jit)
static void _invalidate_consts(jit_state_t*);
#define patch(instr, node)		_patch(_jit, instr, node)
static void _patch(jit_state_t*,jit_word_t,jit_node_t*);

/* libgcc */
extern void __clear_cache(void *, void *);

#define PROTO				1
#  include "jit_arm-cpu.c"
#  include "jit_arm-swf.c"
#  include "jit_arm-vfp.c"
#undef PROTO

/*
 * Initialization
 */
jit_cpu_t		jit_cpu;
jit_flags_t		jit_flags;
jit_register_t		_rvs[] = {
    { rc(gpr) | 0x0c,			"ip" },
    { rc(sav) | rc(gpr) | 0x04,		"r4" },
    { rc(sav) | rc(gpr) | 0x05,		"r5" },
    { rc(sav) | rc(gpr) | 0x06,		"r6" },
    { rc(sav) | rc(gpr) | 0x07,		"r7" },
    { rc(sav) | rc(gpr) | 0x08,		"r8" },
    { rc(sav) | rc(gpr) | 0x09,		"r9" },
    { rc(sav) | 0x0a,			"sl" },
    { rc(sav) | 0x0b,			"fp" },
    { rc(sav) | 0x0d,			"sp" },
    { rc(sav) | 0x0e,			"lr" },
    { 0x0f,				"pc" },
    { rc(arg) | rc(gpr) | 0x03,		"r3" },
    { rc(arg) | rc(gpr) | 0x02,		"r2" },
    { rc(arg) | rc(gpr) | 0x01,		"r1" },
    { rc(arg) | rc(gpr) | 0x00,		"r0" },
    { rc(fpr) | 0x20,			"d8" },
    { 0x21,				"s17" },
    { rc(fpr) | 0x22,			"d9" },
    { 0x23,				"s19" },
    { rc(fpr) | 0x24,			"d10" },
    { 0x25,				"s21" },
    { rc(fpr) | 0x26,			"d11" },
    { 0x27,				"s23" },
    { rc(fpr) | 0x28,			"d12" },
    { 0x29,				"s25" },
    { rc(fpr) | 0x2a,			"d13" },
    { 0x2b,				"s27" },
    { rc(fpr) | 0x2c,			"d14" },
    { 0x2d,				"s29" },
    { rc(fpr) | 0x2e,			"d15" },
    { 0x2f,				"s31" },
    { rc(arg) | 0x1f,			"s15" },
    { rc(arg)|rc(sft)|rc(fpr)|0x1e,	"d7" },
    { rc(arg) | 0x1d,			"s13" },
    { rc(arg)|rc(sft)|rc(fpr)|0x1c,	"d6" },
    { rc(arg) | 0x1b,			"s11" },
    { rc(arg)|rc(sft)|rc(fpr)|0x1a,	"d5" },
    { rc(arg) | 0x19,			"s9" },
    { rc(arg)|rc(sft)|rc(fpr)|0x18,	"d4" },
    { rc(arg) | 0x17,			"s7" },
    { rc(arg)|rc(sft)|rc(fpr)|0x16,	"d3" },
    { rc(arg) | 0x15,			"s5" },
    { rc(arg)|rc(sft)|rc(fpr)|0x14,	"d2" },
    { rc(arg) | 0x13,			"s3" },
    { rc(arg)|rc(sft)|rc(fpr)|0x12,	"d1" },
    { rc(arg) | 0x11,			"s1" },
    { rc(arg)|rc(sft)|rc(fpr)|0x10,	"d0" },
    { _NOREG,				"<none>" },
};

/*
 * Implementation
 */
void
jit_get_cpu(void)
{
#if defined(__linux__)
    FILE	*fp;
    char	*ptr;
    char	 buf[128];

    if ((fp = fopen("/proc/cpuinfo", "r")) == NULL)
	return;

    while (fgets(buf, sizeof(buf), fp)) {
	if (strncmp(buf, "CPU architecture:", 17) == 0) {
	    jit_cpu.version = strtol(buf + 17, &ptr, 10);
	    while (*ptr) {
		if (*ptr == 'T' || *ptr == 't') {
		    ++ptr;
		    jit_cpu.thumb = 1;
		}
		else if (*ptr == 'E' || *ptr == 'e') {
		    jit_cpu.extend = 1;
		    ++ptr;
		}
		else
		    ++ptr;
	    }
	}
	else if (strncmp(buf, "Features\t:", 10) == 0) {
	    if ((ptr = strstr(buf + 10, "vfpv")))
		jit_cpu.vfp = strtol(ptr + 4, NULL, 0);
	    if ((ptr = strstr(buf + 10, "neon")))
		jit_cpu.neon = 1;
	    if ((ptr = strstr(buf + 10, "thumb")))
		jit_cpu.thumb = 1;
	}
    }
    fclose(fp);
#endif
#if defined(__ARM_PCS_VFP)
    if (!jit_cpu.vfp)
	jit_cpu.vfp = 3;
    if (!jit_cpu.version)
	jit_cpu.version = 7;
    jit_cpu.abi = 1;
#endif
    /* armv6t2 todo (software float and thumb2) */
    if (!jit_cpu.vfp && jit_cpu.thumb)
	jit_cpu.thumb = 0;
}

void
_jit_init(jit_state_t *_jit)
{
    jit_int32_t		regno;
    _jit->reglen = jit_size(_rvs) - 1;
    /* jit_get_cpu() should have been already called, and only once */
    if (!jit_cpu.vfp) {
	/* cause register to never be allocated, because simple
	 * software float only allocates stack space for 8 slots  */
	for (regno = _D8; regno < _D7; regno++)
	    _rvs[regno].spec = 0;
    }
    if (!jit_cpu.abi) {
	for (regno = _S15; regno <= _D0; regno++)
	    _rvs[regno].spec &= ~rc(arg);
    }
}

void
_jit_prolog(jit_state_t *_jit)
{
    jit_int32_t		 offset;

    if (_jit->function)
	jit_epilog();
    assert(jit_regset_cmp_ui(_jit->regarg, 0) == 0);
    jit_regset_set_ui(_jit->regsav, 0);
    offset = _jit->functions.offset;
    if (offset >= _jit->functions.length) {
	_jit->functions.ptr = realloc(_jit->functions.ptr,
				      (_jit->functions.length + 16) *
				      sizeof(jit_function_t));
	memset(_jit->functions.ptr + _jit->functions.length, 0,
	       16 * sizeof(jit_function_t));
	_jit->functions.length += 16;
    }
    _jit->function = _jit->functions.ptr + _jit->functions.offset++;
    _jit->function->self.size = stack_framesize;
    if (jit_cpu.abi)
	_jit->function->self.size += 64;
    _jit->function->self.argi = _jit->function->self.argf =
	_jit->function->self.alen = 0;
    if (jit_swf_p())
	/* 8 soft float registers */
	_jit->function->self.aoff = -64;
    else
	_jit->function->self.aoff = 0;
    _jit->function->regoff = calloc(_jit->reglen, sizeof(jit_int32_t));

    _jit->function->prolog = jit_new_node_no_link(jit_code_prolog);
    jit_link(_jit->function->prolog);
    _jit->function->prolog->w.w = offset;
    _jit->function->epilog = jit_new_node_no_link(jit_code_epilog);
    /*	u:	label value
     *	v:	offset in blocks vector
     *	w:	offset in functions vector
     */
    _jit->function->epilog->w.w = offset;

    jit_regset_new(_jit->function->regset);
}

jit_int32_t
_jit_allocai(jit_state_t *_jit, jit_int32_t length)
{
    assert(_jit->function);
    switch (length) {
	case 0:	case 1:						break;
	case 2:		_jit->function->self.aoff &= -2;	break;
	case 3:	case 4:	_jit->function->self.aoff &= -4;	break;
	default:	_jit->function->self.aoff &= -8;	break;
    }
    _jit->function->self.aoff -= length;
    return (_jit->function->self.aoff);
}

void
_jit_ret(jit_state_t *_jit)
{
    jit_node_t		*instr;

    assert(_jit->function);

    /* jump to epilog */
    instr = jit_jmpi();
    jit_patch_at(instr, _jit->function->epilog);
}

void
_jit_retr(jit_state_t *_jit, jit_int32_t u)
{
    jit_movr(JIT_RET, u);
    jit_ret();
}

void
_jit_reti(jit_state_t *_jit, jit_word_t u)
{
    jit_movi(JIT_RET, u);
    jit_ret();
}

void
_jit_retr_f(jit_state_t *_jit, jit_int32_t u)
{
    jit_movr_f(JIT_FRET, u);
    jit_ret();
}

void
_jit_reti_f(jit_state_t *_jit, jit_float32_t u)
{
    jit_movi_f(JIT_FRET, u);
    jit_ret();
}

void
_jit_retr_d(jit_state_t *_jit, jit_int32_t u)
{
    jit_movr_d(JIT_FRET, u);
    jit_ret();
}

void
_jit_reti_d(jit_state_t *_jit, jit_float64_t u)
{
    jit_movi_d(JIT_FRET, u);
    jit_ret();
}

/* must be called internally only */
void
_jit_epilog(jit_state_t *_jit)
{
    assert(_jit->function);
    _jit->function->stack = ((_jit->function->self.alen -
			      /* align stack at 8 bytes */
			      _jit->function->self.aoff) + 7) & -8;
    assert(_jit->function->epilog->next == NULL);
    jit_link(_jit->function->epilog);
    _jit->function = NULL;
}

jit_int32_t
_jit_arg(jit_state_t *_jit)
{
    jit_int32_t		offset;

    assert(_jit->function);
    if (_jit->function->self.argi < 4)
	offset = _jit->function->self.argi++;
    else {
	offset = _jit->function->self.size;
	_jit->function->self.size += sizeof(jit_word_t);
    }
    return (offset);
}

jit_bool_t
_jit_arg_reg_p(jit_state_t *_jit, jit_int32_t offset)
{
    return (offset >= 0 && offset < 4);
}

jit_int32_t
_jit_arg_f(jit_state_t *_jit)
{
    jit_int32_t		offset;
    if (jit_cpu.abi) {
	if (_jit->function->self.argf < 16)
	    offset = _jit->function->self.argf++;
	else {
	    offset = _jit->function->self.size;
	    _jit->function->self.size += sizeof(jit_word_t);
	}
    }
    else
	offset = _jit_arg(_jit);
    return (offset);
}

jit_bool_t
_jit_arg_f_reg_p(jit_state_t *_jit, jit_int32_t offset)
{
    return (jit_arg_reg_p(offset));
}

jit_int32_t
_jit_arg_d(jit_state_t *_jit)
{
    jit_int32_t		offset;
    if (jit_cpu.abi) {
	if (_jit->function->self.argf < 15) {
	    if (_jit->function->self.argf & 1)
		++_jit->function->self.argf;
	    offset = _jit->function->self.argf;
	    _jit->function->self.argf += 2;
	    return (offset);
	}
    }
    else {
	if (_jit->function->self.argi < 3) {
	    if (_jit->function->self.argi & 1)
		++_jit->function->self.argi;
	    offset = _jit->function->self.argf;
	    _jit->function->self.argf += 2;
	    return (offset);
	}
    }
    if (_jit->function->self.size & 7)
	_jit->function->self.size += 4;
    offset = _jit->function->self.size;
    _jit->function->self.size += sizeof(jit_float64_t);
    return (offset);
}

jit_bool_t
_jit_arg_d_reg_p(jit_state_t *_jit, jit_int32_t offset)
{
    return (jit_arg_reg_p(offset));
}

void
_jit_getarg_c(jit_state_t *_jit, jit_int32_t u, jit_int32_t v)
{
    if (v < 4)
	jit_extr_c(u, JIT_RA0 - v);
    else
	jit_ldxi_c(u, JIT_FP, v);
}

void
_jit_getarg_uc(jit_state_t *_jit, jit_int32_t u, jit_int32_t v)
{
    if (v < 4)
	jit_extr_uc(u, JIT_RA0 - v);
    else
	jit_ldxi_uc(u, JIT_FP, v);
}

void
_jit_getarg_s(jit_state_t *_jit, jit_int32_t u, jit_int32_t v)
{
    if (v < 4)
	jit_extr_s(u, JIT_RA0 - v);
    else
	jit_ldxi_s(u, JIT_FP, v);
}

void
_jit_getarg_us(jit_state_t *_jit, jit_int32_t u, jit_int32_t v)
{
    if (v < 4)
	jit_extr_us(u, JIT_RA0 - v);
    else
	jit_ldxi_us(u, JIT_FP, v);
}

void
_jit_getarg_i(jit_state_t *_jit, jit_int32_t u, jit_int32_t v)
{
    if (v < 4)
	jit_movr(u, JIT_RA0 - v);
    else
	jit_ldxi_i(u, JIT_FP, v);
}

void
_jit_getarg_f(jit_state_t *_jit, jit_int32_t u, jit_int32_t v)
{
    if (jit_cpu.abi) {
	if (v < 16)
	    jit_movr_f(u, JIT_FA0 - v);
	else
	    jit_ldxi_f(u, JIT_FP, v);
    }
    else {
	if (v < 4)
	    jit_movr_f(u, JIT_RA0 - v);
	else
	    jit_ldxi_f(u, JIT_FP, v);
    }
}

void
_jit_getarg_d(jit_state_t *_jit, jit_int32_t u, jit_int32_t v)
{
    if (jit_cpu.abi) {
	if (v < 16)
	    jit_movr_d(u, JIT_FA0 - v);
	else
	    jit_ldxi_d(u, JIT_FP, v);
    }
    else {
	if (v < 4)
	    jit_movr_d(u, JIT_RA0 - v);
	else
	    jit_ldxi_d(u, JIT_FP, v);
    }
}

void
_jit_pushargr(jit_state_t *_jit, jit_int32_t u)
{
    assert(_jit->function);
    if (_jit->function->call.argi < 4) {
	jit_movr(JIT_RA0 - _jit->function->call.argi, u);
	++_jit->function->call.argi;
    }
    else {
	jit_stxi(_jit->function->call.size, JIT_SP, u);
	_jit->function->call.size += sizeof(jit_word_t);
    }
}

void
_jit_pushargi(jit_state_t *_jit, jit_word_t u)
{
    jit_int32_t		 regno;

    assert(_jit->function);
    if (_jit->function->call.argi < 4) {
	jit_movi(JIT_RA0 - _jit->function->call.argi, u);
	++_jit->function->call.argi;
    }
    else {
	regno = jit_get_reg(jit_class_gpr);
	jit_movi(regno, u);
	jit_stxi(_jit->function->call.size, JIT_SP, regno);
	jit_unget_reg(regno);
	_jit->function->call.size += sizeof(jit_word_t);
    }
}

void
_jit_pushargr_f(jit_state_t *_jit, jit_int32_t u)
{
    assert(_jit->function);
    if (jit_cpu.abi && !(_jit->function->call.kind & jit_call_varargs)) {
	if (_jit->function->call.argf < 16) {
	    jit_movr_f(JIT_FA0 - _jit->function->call.argf, u);
	    ++_jit->function->call.argf;
	    return;
	}
    }
    else {
	if (_jit->function->call.argi < 4) {
	    jit_movr_f(JIT_RA0 - _jit->function->call.argi, u);
	    ++_jit->function->call.argi;
	    return;
	}
    }
    jit_stxi_f(_jit->function->call.size, JIT_SP, u);
    _jit->function->call.size += sizeof(jit_word_t);
}

void
_jit_pushargi_f(jit_state_t *_jit, jit_float32_t u)
{
    jit_int32_t		regno;

    assert(_jit->function);
    if (jit_cpu.abi && !(_jit->function->call.kind & jit_call_varargs)) {
	if (_jit->function->call.argf < 16) {
	    jit_movi_f(JIT_FA0 - _jit->function->call.argf, u);
	    ++_jit->function->call.argf;
	    return;
	}
    }
    else {
	if (_jit->function->call.argi < 4) {
	    jit_movi_f(JIT_RA0 - _jit->function->call.argi, u);
	    ++_jit->function->call.argi;
	    return;
	}
    }
    regno = jit_get_reg(jit_class_gpr);
    jit_movi_f(regno, u);
    jit_stxi_f(_jit->function->call.size, JIT_SP, regno);
    jit_unget_reg(regno);
    _jit->function->call.size += sizeof(jit_word_t);
}

void
_jit_pushargr_d(jit_state_t *_jit, jit_int32_t u)
{
    assert(_jit->function);
    if (jit_cpu.abi && !(_jit->function->call.kind & jit_call_varargs)) {
	if (_jit->function->call.argf < 15) {
	    if (_jit->function->call.argf & 1)
		++_jit->function->call.argf;
	    jit_movr_d(JIT_FA0 - _jit->function->call.argf, u);
	    _jit->function->call.argf += 2;
	    return;
	}
    }
    else {
	if (_jit->function->call.argi & 1)
	    ++_jit->function->call.argi;
	if (_jit->function->call.argi < 4) {
	    jit_movr_d(JIT_RA0 - _jit->function->call.argi, u);
	    _jit->function->call.argi += 2;
	    return;
	}
    }
    if (_jit->function->call.size & 7)
	_jit->function->call.size += 4;
    jit_stxi_d(_jit->function->call.size, JIT_SP, u);
    _jit->function->call.size += sizeof(jit_float64_t);
}

void
_jit_pushargi_d(jit_state_t *_jit, jit_float64_t u)
{
    jit_int32_t		regno;

    assert(_jit->function);
    if (jit_cpu.abi && !(_jit->function->call.kind & jit_call_varargs)) {
	if (_jit->function->call.argf < 15) {
	    if (_jit->function->call.argf & 1)
		++_jit->function->call.argf;
	    jit_movi_d(JIT_FA0 - _jit->function->call.argf, u);
	    _jit->function->call.argf += 2;
	    return;
	}
    }
    else {
	if (_jit->function->call.argi & 1)
	    ++_jit->function->call.argi;
	if (_jit->function->call.argi < 4) {
	    jit_movi_d(JIT_RA0 - _jit->function->call.argi, u);
	    _jit->function->call.argi += 2;
	    return;
	}
    }
    if (_jit->function->call.size & 7)
	_jit->function->call.size += 4;
    regno = jit_get_reg(jit_class_gpr);
    jit_movi_d(regno, u);
    jit_stxi_d(_jit->function->call.size, JIT_SP, regno);
    jit_unget_reg(regno);
    _jit->function->call.size += sizeof(jit_float64_t);
}

jit_bool_t
_jit_regarg_p(jit_state_t *_jit, jit_node_t *node, jit_int32_t regno)
{
    jit_int32_t		spec;

    spec = jit_class(_rvs[regno].spec);
    if (spec & jit_class_arg) {
	regno = JIT_RA0 - regno;
	if (regno >= 0 && regno < node->v.w)
	    return (1);
	if (jit_cpu.abi && spec & jit_class_fpr) {
	    regno = JIT_FA0 - regno;
	    if (regno >= 0 && regno < node->w.w)
		return (1);
	}
    }

    return (0);
}

void
_jit_finishr(jit_state_t *_jit, jit_int32_t r0)
{
    jit_node_t		*node;

    assert(_jit->function);
    if (_jit->function->self.alen < _jit->function->call.size)
	_jit->function->self.alen = _jit->function->call.size;
    node = jit_callr(r0);
    node->v.w = _jit->function->self.argi;
    node->w.w = _jit->function->call.argf;
    _jit->function->call.argi = _jit->function->call.argf =
	_jit->function->call.size = 0;
}

jit_node_t *
_jit_finishi(jit_state_t *_jit, jit_pointer_t i0)
{
    jit_node_t		*node;

    assert(_jit->function);
    if (_jit->function->self.alen < _jit->function->call.size)
	_jit->function->self.alen = _jit->function->call.size;
    node = jit_calli(i0);
    node->v.w = _jit->function->call.argi;
    node->w.w = _jit->function->call.argf;
    _jit->function->call.argi = _jit->function->call.argf =
	_jit->function->call.size = 0;
    return (node);
}

void
_jit_retval_c(jit_state_t *_jit, jit_int32_t r0)
{
    jit_extr_c(r0, JIT_RET);
}

void
_jit_retval_uc(jit_state_t *_jit, jit_int32_t r0)
{
    jit_extr_uc(r0, JIT_RET);
}

void
_jit_retval_s(jit_state_t *_jit, jit_int32_t r0)
{
    jit_extr_s(r0, JIT_RET);
}

void
_jit_retval_us(jit_state_t *_jit, jit_int32_t r0)
{
    jit_extr_us(r0, JIT_RET);
}

void
_jit_retval_i(jit_state_t *_jit, jit_int32_t r0)
{
    if (r0 != JIT_RET)
	jit_movr(r0, JIT_RET);
}

void
_jit_retval_f(jit_state_t *_jit, jit_int32_t r0)
{
    if (jit_cpu.abi) {
	if (r0 != JIT_FRET)
	    jit_movr_f(r0, JIT_FRET);
    }
    else if (r0 != JIT_RET)
	jit_movr_f(r0, JIT_RET);
}

void
_jit_retval_d(jit_state_t *_jit, jit_int32_t r0)
{
    if (jit_cpu.abi) {
	if (r0 != JIT_FRET)
	    jit_movr_d(r0, JIT_FRET);
    }
    else if (r0 != JIT_RET)
	jit_movr_d(r0, JIT_RET);
}

jit_pointer_t
_jit_emit(jit_state_t *_jit)
{
    jit_node_t		*node;
    jit_node_t		*temp;
    jit_word_t		 word;
    jit_int32_t		 value;
    jit_int32_t		 offset;
    struct {
	jit_node_t	*node;
	jit_uint8_t	*data;
	jit_word_t	 word;
	jit_uword_t	 thumb;
	jit_int32_t	 info_offset;
	jit_int32_t	 const_offset;
	jit_int32_t	 patch_offset;
    } undo;

    if (_jit->function)
	jit_epilog();
    jit_optimize();

    _jit->emit = 1;

    _jit->code.length = 16 * 1024 * 1024;
    _jit->code.ptr = mmap(NULL, _jit->code.length,
			  PROT_EXEC | PROT_READ | PROT_WRITE,
			  MAP_PRIVATE | MAP_ANON, -1, 0);
    assert(_jit->code.ptr != MAP_FAILED);
    _jit->pc.uc = _jit->code.ptr;

    /* clear jit_flag_patch from label nodes if reallocating buffer
     * and starting over
     */

    _jit->function = NULL;

    jit_reglive_setup();

    undo.word = 0;
    undo.node = NULL;
    undo.data = NULL;
    undo.thumb = 0;
    undo.info_offset = undo.const_offset = undo.patch_offset = 0;
#  define assert_data(node)		/**/
#define case_rr(name, type)						\
	    case jit_code_##name##r##type:				\
		name##r##type(rn(node->u.w), rn(node->v.w));		\
		break
#define case_rw(name, type)						\
	    case jit_code_##name##i##type:				\
		name##i##type(rn(node->u.w), node->v.w);		\
		break
#define case_vv(name, type)						\
	    case jit_code_##name##r##type:				\
		if (jit_swf_p())					\
		    swf_##name##r##type(rn(node->u.w), rn(node->v.w));	\
		else							\
		    vfp_##name##r##type(rn(node->u.w), rn(node->v.w));	\
		break
#define case_vw(name, type)						\
	    case jit_code_##name##i##type:				\
		if (jit_swf_p())					\
		    swf_##name##i##type(rn(node->u.w), node->v.w);	\
		else							\
		    vfp_##name##i##type(rn(node->u.w), node->v.w);	\
		break
#define case_wr(name, type)						\
	    case jit_code_##name##i##type:				\
		name##i##type(node->u.w, rn(node->v.w));		\
		break
#define case_wv(name, type)						\
	    case jit_code_##name##i##type:				\
		if (jit_swf_p())					\
		    swf_##name##i##type(node->u.w, rn(node->v.w));	\
		else							\
		    vfp_##name##i##type(node->u.w, rn(node->v.w));	\
		break
#define case_rrr(name, type)						\
	    case jit_code_##name##r##type:				\
		name##r##type(rn(node->u.w),				\
			      rn(node->v.w), rn(node->w.w));		\
		break
#define case_vvv(name, type)						\
	    case jit_code_##name##r##type:				\
		if (jit_swf_p())					\
		    swf_##name##r##type(rn(node->u.w),			\
				        rn(node->v.w), rn(node->w.w));	\
		else							\
		    vfp_##name##r##type(rn(node->u.w),			\
				        rn(node->v.w), rn(node->w.w));	\
		break
#define case_rrw(name, type)						\
	    case jit_code_##name##i##type:				\
		name##i##type(rn(node->u.w), rn(node->v.w), node->w.w);	\
		break
#define case_vvw(name, type)						\
	    case jit_code_##name##i##type:				\
		if (jit_swf_p())					\
		    swf_##name##i##type(rn(node->u.w),			\
				        rn(node->v.w), node->w.w);	\
		else							\
		    vfp_##name##i##type(rn(node->u.w),			\
				        rn(node->v.w), node->w.w);	\
		break
#define case_vvf(name)							\
	    case jit_code_##name##i_f:					\
		assert_data(node);					\
		if (jit_swf_p())					\
		    swf_##name##i_f(rn(node->u.w), rn(node->v.w),	\
				    node->w.f);				\
		else							\
		    vfp_##name##i_f(rn(node->u.w), rn(node->v.w),	\
				    node->w.f);				\
		break
#define case_vvd(name)							\
	    case jit_code_##name##i_d:					\
		assert_data(node);					\
		if (jit_swf_p())					\
		    swf_##name##i_d(rn(node->u.w), rn(node->v.w),	\
				    node->w.d);				\
		else							\
		    vfp_##name##i_d(rn(node->u.w), rn(node->v.w),	\
				    node->w.d);				\
		break
#define case_wrr(name, type)						\
	    case jit_code_##name##i##type:				\
		name##i##type(node->u.w, rn(node->v.w), rn(node->w.w));	\
		break
#define case_wvv(name, type)						\
	    case jit_code_##name##i##type:				\
		if (jit_swf_p())					\
		    swf_##name##i##type(node->u.w,			\
				        rn(node->v.w), rn(node->w.w));	\
		else							\
		    vfp_##name##i##type(node->u.w,			\
				        rn(node->v.w), rn(node->w.w));	\
		break
#define case_brr(name, type)						\
	    case jit_code_##name##r##type:				\
		temp = node->u.n;					\
		assert(temp->code == jit_code_label ||			\
		       temp->code == jit_code_epilog);			\
		if (temp->flag & jit_flag_patch)			\
		    name##r##type(temp->u.w, rn(node->v.w),		\
				  rn(node->w.w));			\
		else {							\
		    word = name##r##type(_jit->pc.w,			\
					 rn(node->v.w), rn(node->w.w));	\
		    patch(word, node);					\
		}							\
		break
#define case_bvv(name, type)						\
	    case jit_code_##name##r##type:				\
		temp = node->u.n;					\
		assert(temp->code == jit_code_label ||			\
		       temp->code == jit_code_epilog);			\
		if (temp->flag & jit_flag_patch) {			\
		    if (jit_swf_p())					\
			swf_##name##r##type(temp->u.w, rn(node->v.w),	\
					    rn(node->w.w));		\
		    else						\
			vfp_##name##r##type(temp->u.w, rn(node->v.w),	\
					    rn(node->w.w));		\
		}							\
		else {							\
		    if (jit_swf_p())					\
			word = swf_##name##r##type(_jit->pc.w,		\
						   rn(node->v.w),	\
						   rn(node->w.w));	\
		    else						\
			word = vfp_##name##r##type(_jit->pc.w,		\
						   rn(node->v.w),	\
						   rn(node->w.w));	\
		    patch(word, node);					\
		}							\
		break
#define case_brw(name, type)						\
	    case jit_code_##name##i##type:				\
		temp = node->u.n;					\
		assert(temp->code == jit_code_label ||			\
		       temp->code == jit_code_epilog);			\
		if (temp->flag & jit_flag_patch)			\
		    name##i##type(temp->u.w,				\
				  rn(node->v.w), node->w.w);		\
		else {							\
		    word = name##i##type(_jit->pc.w,			\
					 rn(node->v.w), node->w.w);	\
		    patch(word, node);					\
		}							\
		break;
#define case_bvf(name)							\
	    case jit_code_##name##i_f:					\
		temp = node->u.n;					\
		assert(temp->code == jit_code_label ||			\
		       temp->code == jit_code_epilog);			\
		if (temp->flag & jit_flag_patch) {			\
		    if (jit_swf_p())					\
			swf_##name##i_f(temp->u.w, rn(node->v.w),	\
					node->w.f);			\
		    else						\
			vfp_##name##i_f(temp->u.w, rn(node->v.w),	\
					node->w.f);			\
		}							\
		else {							\
		    if (jit_swf_p())					\
			word = swf_##name##i_f(_jit->pc.w,		\
					       rn(node->v.w),		\
					       node->w.f);		\
		    else						\
			word = vfp_##name##i_f(_jit->pc.w,		\
					       rn(node->v.w),		\
					       node->w.f);		\
		    patch(word, node);					\
		}							\
		break
#define case_bvd(name)							\
	    case jit_code_##name##i_d:					\
		temp = node->u.n;					\
		assert(temp->code == jit_code_label ||			\
		       temp->code == jit_code_epilog);			\
		if (temp->flag & jit_flag_patch) {			\
		    if (jit_swf_p())					\
			swf_##name##i_d(temp->u.w, rn(node->v.w),	\
					node->w.d);			\
		    else						\
			vfp_##name##i_d(temp->u.w, rn(node->v.w),	\
					node->w.d);			\
		}							\
		else {							\
		    if (jit_swf_p())					\
			word = swf_##name##i_d(_jit->pc.w,		\
					       rn(node->v.w),		\
					       node->w.d);		\
		    else						\
			word = vfp_##name##i_d(_jit->pc.w,		\
					       rn(node->v.w),		\
					       node->w.d);		\
		    patch(word, node);					\
		}							\
		break
    for (node = _jit->head; node; node = node->next) {
	value = jit_classify(node->code);
	jit_regarg_set(node, value);
	switch (node->code) {
	    case jit_code_note:
		node->u.w = _jit->pc.w;
		break;
	    case jit_code_label:
		/* remember label is defined */
		node->flag |= jit_flag_patch;
		node->u.w = _jit->pc.w;
		break;
		case_rrr(add,);
		case_rrw(add,);
		case_rrr(addc,);
		case_rrw(addc,);
		case_rrr(addx,);
		case_rrw(addx,);
		case_rrr(sub,);
		case_rrw(sub,);
		case_rrr(subc,);
		case_rrw(subc,);
		case_rrr(subx,);
		case_rrw(subx,);
		case_rrr(mul,);
		case_rrw(mul,);
		case_rrr(div,);
		case_rrw(div,);
		case_rrr(div, _u);
		case_rrw(div, _u);
		case_rrr(rem,);
		case_rrw(rem,);
		case_rrr(rem, _u);
		case_rrw(rem, _u);
		case_rrr(lsh,);
		case_rrw(lsh,);
		case_rrr(rsh,);
		case_rrw(rsh,);
		case_rrr(rsh, _u);
		case_rrw(rsh, _u);
		case_rr(neg,);
		case_rr(com,);
		case_rrr(and,);
		case_rrw(and,);
		case_rrr(or,);
		case_rrw(or,);
		case_rrr(xor,);
		case_rrw(xor,);
		case_vv(trunc, _f_i);
		case_vv(trunc, _d_i);
		case_rr(ld, _c);
		case_rw(ld, _c);
		case_rr(ld, _uc);
		case_rw(ld, _uc);
		case_rr(ld, _s);
		case_rw(ld, _s);
		case_rr(ld, _us);
		case_rw(ld, _us);
		case_rr(ld, _i);
		case_rw(ld, _i);
		case_rrr(ldx, _c);
		case_rrw(ldx, _c);
		case_rrr(ldx, _uc);
		case_rrw(ldx, _uc);
		case_rrr(ldx, _s);
		case_rrw(ldx, _s);
		case_rrr(ldx, _us);
		case_rrw(ldx, _us);
		case_rrr(ldx, _i);
		case_rrw(ldx, _i);
		case_rr(st, _c);
		case_wr(st, _c);
		case_rr(st, _s);
		case_wr(st, _s);
		case_rr(st, _i);
		case_wr(st, _i);
		case_rrr(stx, _c);
		case_wrr(stx, _c);
		case_rrr(stx, _s);
		case_wrr(stx, _s);
		case_rrr(stx, _i);
		case_wrr(stx, _i);
		case_rr(hton,);
		case_rr(ext, _c);
		case_rr(ext, _uc);
		case_rr(ext, _s);
		case_rr(ext, _us);
		case_rr(mov,);
	    case jit_code_movi:
		if (node->flag & jit_flag_node) {
		    temp = node->v.n;
		    if (temp->code == jit_code_data ||
			(temp->code == jit_code_label &&
			 (temp->flag & jit_flag_patch)))
			movi(rn(node->u.w), temp->u.w);
		    else {
			assert(temp->code == jit_code_label ||
			       temp->code == jit_code_epilog);
			word = movi_p(rn(node->u.w), temp->u.w);
			patch(word, node);
		    }
		}
		else
		    movi(rn(node->u.w), node->v.w);
		break;
		case_rrr(lt,);
		case_rrw(lt,);
		case_rrr(lt, _u);
		case_rrw(lt, _u);
		case_rrr(le,);
		case_rrw(le,);
		case_rrr(le, _u);
		case_rrw(le, _u);
		case_rrr(eq,);
		case_rrw(eq,);
		case_rrr(ge,);
		case_rrw(ge,);
		case_rrr(ge, _u);
		case_rrw(ge, _u);
		case_rrr(gt,);
		case_rrw(gt,);
		case_rrr(gt, _u);
		case_rrw(gt, _u);
		case_rrr(ne,);
		case_rrw(ne,);
		case_brr(blt,);
		case_brw(blt,);
		case_brr(blt, _u);
		case_brw(blt, _u);
		case_brr(ble,);
		case_brw(ble,);
		case_brr(ble, _u);
		case_brw(ble, _u);
		case_brr(beq,);
		case_brw(beq,);
		case_brr(bge,);
		case_brw(bge,);
		case_brr(bge, _u);
		case_brw(bge, _u);
		case_brr(bgt,);
		case_brw(bgt,);
		case_brr(bgt, _u);
		case_brw(bgt, _u);
		case_brr(bne,);
		case_brw(bne,);
		case_brr(boadd,);
		case_brw(boadd,);
		case_brr(boadd, _u);
		case_brw(boadd, _u);
		case_brr(bxadd,);
		case_brw(bxadd,);
		case_brr(bxadd, _u);
		case_brw(bxadd, _u);
		case_brr(bosub,);
		case_brw(bosub,);
		case_brr(bosub, _u);
		case_brw(bosub, _u);
		case_brr(bxsub,);
		case_brw(bxsub,);
		case_brr(bxsub, _u);
		case_brw(bxsub, _u);
		case_brr(bms,);
		case_brw(bms,);
		case_brr(bmc,);
		case_brw(bmc,);
		case_vvv(add, _f);
		case_vvf(add);
		case_vvv(sub, _f);
		case_vvf(sub);
		case_vvv(mul, _f);
		case_vvf(mul);
		case_vvv(div, _f);
		case_vvf(div);
		case_vv(abs, _f);
		case_vv(neg, _f);
		case_vv(sqrt, _f);
		case_vv(ext, _f);
		case_vv(ld, _f);
		case_vw(ld, _f);
		case_vvv(ldx, _f);
		case_vvw(ldx, _f);
		case_vv(st, _f);
		case_wv(st, _f);
		case_vvv(stx, _f);
		case_wvv(stx, _f);
		case_vv(mov, _f);
	    case jit_code_movi_f:
		assert_data(node);
		if (jit_swf_p())
		    swf_movi_f(rn(node->u.w), node->v.f);
		else
		    vfp_movi_f(rn(node->u.w), node->v.f);
		break;
		case_vv(ext, _d_f);
		case_vvv(lt, _f);
		case_vvf(lt);
		case_vvv(le, _f);
		case_vvf(le);
		case_vvv(eq, _f);
		case_vvf(eq);
		case_vvv(ge, _f);
		case_vvf(ge);
		case_vvv(gt, _f);
		case_vvf(gt);
		case_vvv(ne, _f);
		case_vvf(ne);
		case_vvv(unlt, _f);
		case_vvf(unlt);
		case_vvv(unle, _f);
		case_vvf(unle);
		case_vvv(uneq, _f);
		case_vvf(uneq);
		case_vvv(unge, _f);
		case_vvf(unge);
		case_vvv(ungt, _f);
		case_vvf(ungt);
		case_vvv(ltgt, _f);
		case_vvf(ltgt);
		case_vvv(ord, _f);
		case_vvf(ord);
		case_vvv(unord, _f);
		case_vvf(unord);
		case_bvv(blt, _f);
		case_bvf(blt);
		case_bvv(ble, _f);
		case_bvf(ble);
		case_bvv(beq, _f);
		case_bvf(beq);
		case_bvv(bge, _f);
		case_bvf(bge);
		case_bvv(bgt, _f);
		case_bvf(bgt);
		case_bvv(bne, _f);
		case_bvf(bne);
		case_bvv(bunlt, _f);
		case_bvf(bunlt);
		case_bvv(bunle, _f);
		case_bvf(bunle);
		case_bvv(buneq, _f);
		case_bvf(buneq);
		case_bvv(bunge, _f);
		case_bvf(bunge);
		case_bvv(bungt, _f);
		case_bvf(bungt);
		case_bvv(bltgt, _f);
		case_bvf(bltgt);
		case_bvv(bord, _f);
		case_bvf(bord);
		case_bvv(bunord, _f);
		case_bvf(bunord);
		case_vvv(add, _d);
		case_vvd(add);
		case_vvv(sub, _d);
		case_vvd(sub);
		case_vvv(mul, _d);
		case_vvd(mul);
		case_vvv(div, _d);
		case_vvd(div);
		case_vv(abs, _d);
		case_vv(neg, _d);
		case_vv(sqrt, _d);
		case_vv(ext, _d);
		case_vv(ld, _d);
		case_vw(ld, _d);
		case_vvv(ldx, _d);
		case_vvw(ldx, _d);
		case_vv(st, _d);
		case_wv(st, _d);
		case_vvv(stx, _d);
		case_wvv(stx, _d);
		case_vv(mov, _d);
	    case jit_code_movi_d:
		assert_data(node);
		if (jit_swf_p())
		    swf_movi_d(rn(node->u.w), node->v.d);
		else
		    vfp_movi_d(rn(node->u.w), node->v.d);
		break;
		case_vv(ext, _f_d);
		case_vvv(lt, _d);
		case_vvd(lt);
		case_vvv(le, _d);
		case_vvd(le);
		case_vvv(eq, _d);
		case_vvd(eq);
		case_vvv(ge, _d);
		case_vvd(ge);
		case_vvv(gt, _d);
		case_vvd(gt);
		case_vvv(ne, _d);
		case_vvd(ne);
		case_vvv(unlt, _d);
		case_vvd(unlt);
		case_vvv(unle, _d);
		case_vvd(unle);
		case_vvv(uneq, _d);
		case_vvd(uneq);
		case_vvv(unge, _d);
		case_vvd(unge);
		case_vvv(ungt, _d);
		case_vvd(ungt);
		case_vvv(ltgt, _d);
		case_vvd(ltgt);
		case_vvv(ord, _d);
		case_vvd(ord);
		case_vvv(unord, _d);
		case_vvd(unord);
		case_bvv(blt, _d);
		case_bvd(blt);
		case_bvv(ble, _d);
		case_bvd(ble);
		case_bvv(beq, _d);
		case_bvd(beq);
		case_bvv(bge, _d);
		case_bvd(bge);
		case_bvv(bgt, _d);
		case_bvd(bgt);
		case_bvv(bne, _d);
		case_bvd(bne);
		case_bvv(bunlt, _d);
		case_bvd(bunlt);
		case_bvv(bunle, _d);
		case_bvd(bunle);
		case_bvv(buneq, _d);
		case_bvd(buneq);
		case_bvv(bunge, _d);
		case_bvd(bunge);
		case_bvv(bungt, _d);
		case_bvd(bungt);
		case_bvv(bltgt, _d);
		case_bvd(bltgt);
		case_bvv(bord, _d);
		case_bvd(bord);
		case_bvv(bunord, _d);
		case_bvd(bunord);
	    case jit_code_jmpr:
		jmpr(rn(node->u.w));
		flush_consts();
		break;
	    case jit_code_jmpi:
		temp = node->u.n;
		assert(temp->code == jit_code_label ||
		       temp->code == jit_code_epilog);
		if (temp->flag & jit_flag_patch)
		    jmpi(temp->u.w);
		else {
		    word = jmpi_p(_jit->pc.w);
		    patch(word, node);
		}
		flush_consts();
		break;
	    case jit_code_callr:
		callr(rn(node->u.w));
		break;
	    case jit_code_calli:
		if (node->flag & jit_flag_node) {
		    temp = node->u.n;
		    assert(temp->code == jit_code_label ||
			   temp->code == jit_code_epilog);
		    if (temp->flag & jit_flag_patch)
			calli(temp->u.w);
		    else {
			word = calli_p(_jit->pc.w);
			patch(word, node);
		    }
		}
		else
		    calli(node->u.w);
		break;
	    case jit_code_prolog:
		_jit->function = _jit->functions.ptr + node->w.w;
		undo.node = node;
		undo.word = _jit->pc.w;
		undo.data = _jit->consts.data;
		undo.thumb = _jit->thumb;
		undo.const_offset = _jit->consts.offset;
		undo.patch_offset = _jit->patches.offset;
		if (_jit->data_info.ptr)
		    undo.info_offset = _jit->data_info.offset;
	    restart_function:
		_jit->again = 0;
		prolog(node);
		break;
	    case jit_code_epilog:
		assert(_jit->function == _jit->functions.ptr + node->w.w);
		if (_jit->again) {
		    for (temp = undo.node->next;
			 temp != node; temp = temp->next) {
			if (temp->code == jit_code_label ||
			    temp->code == jit_code_epilog)
			    temp->flag &= ~jit_flag_patch;
		    }
		    node = undo.node;
		    _jit->pc.w = undo.word;
		    invalidate_consts();
		    _jit->consts.data = undo.data;
		    _jit->thumb = undo.thumb;
		    _jit->consts.offset = undo.const_offset;
		    _jit->patches.offset = undo.patch_offset;
		    if (_jit->data_info.ptr)
			_jit->data_info.offset = undo.info_offset;
		    goto restart_function;
		}
		/* remember label is defined */
		node->flag |= jit_flag_patch;
		node->u.w = _jit->pc.w;
		epilog(node);
		_jit->function = NULL;
		flush_consts();
		break;
	    default:
		abort();
	}
	jit_regarg_clr(node, value);
	/* update register live state */
	jit_reglive(node);

	if (_jit->consts.length && _jit->pc.uc - _jit->consts.data >= 3968) {
	    /* longest sequence should be 64 bytes, but preventively
	     * do not let it go past 128 remaining bytes before a flush */
	    if (node->next &&
		node->next->code != jit_code_jmpi &&
		node->next->code != jit_code_jmpr &&
		node->next->code != jit_code_epilog) {
		/* insert a jump, flush constants and continue */
		word = _jit->pc.w;
		assert(!jit_thumb_p());
		B(0);
		flush_consts();
		patch_at(arm_patch_jump, word, _jit->pc.w);
	    }
	}
    }
#undef case_bvd
#undef case_bvf
#undef case_brw
#undef case_bvv
#undef case_brr
#undef case_wvv
#undef case_wrr
#undef case_vvd
#undef case_vvf
#undef case_vvw
#undef case_rrw
#undef case_vvv
#undef case_rrr
#undef case_wv
#undef case_wr
#undef case_vw
#undef case_vv
#undef case_rw
#undef case_rr

    flush_consts();
    for (offset = 0; offset < _jit->patches.offset; offset++) {
	assert(_jit->patches.ptr[offset].kind & arm_patch_node);
	node = _jit->patches.ptr[offset].node;
	word = _jit->patches.ptr[offset].inst;
	if (node->code == jit_code_movi) {
	    if (jit_thumb_p())
		value = node->v.n->u.w;
	    else {
		/* calculate where to patch word */
		value = *(jit_int32_t *)word;
		assert((value & 0x0f700000) == ARM_LDRI);
		/* offset may become negative (-4) if last instruction
		 * before unconditional branch and data following
		 * FIXME can this cause issues in the preprocessor prefetch
		 * or something else? should not, as the constants are after
		 * an unconditional jump */
		if (value & ARM_P)	value =   value & 0x00000fff;
		else			value = -(value & 0x00000fff);
		word = word + 8 + value;
		value = node->v.n->u.w;
	    }
	}
	else
	    value = node->u.n->u.w;
	patch_at(_jit->patches.ptr[offset].kind & ~arm_patch_node, word, value);
    }

    __clear_cache(_jit->code.ptr, _jit->pc.uc);

    return (_jit->code.ptr);
}

#define CODE				1
#  include "jit_arm-cpu.c"
#  include "jit_arm-swf.c"
#  include "jit_arm-vfp.c"
#undef CODE

void
_emit_ldxi(jit_state_t *_jit, jit_int32_t r0, jit_int32_t r1, jit_word_t i0)
{
    ldxi_i(rn(r0), rn(r1), i0);
}

void
_emit_stxi(jit_state_t *_jit, jit_word_t i0, jit_int32_t r0, jit_int32_t r1)
{
    stxi_i(i0, rn(r0), rn(r1));
}

void
_emit_ldxi_d(jit_state_t *_jit, jit_int32_t r0, jit_int32_t r1, jit_word_t i0)
{
    if (jit_swf_p())
	swf_ldxi_d(rn(r0), rn(r1), i0);
    else
	vfp_ldxi_d(rn(r0), rn(r1), i0);
}

void
_emit_stxi_d(jit_state_t *_jit, jit_word_t i0, jit_int32_t r0, jit_int32_t r1)
{
    if (jit_swf_p())
	swf_stxi_d(i0, rn(r0), rn(r1));
    else
	vfp_stxi_d(i0, rn(r0), rn(r1));
}

static jit_int32_t
_jit_get_reg_pair(jit_state_t *_jit)
{
    /*   bypass jit_get_reg() with argument or'ed with jit_class_chk
     * and try to find an consecutive, even free register pair, or
     * return JIT_NOREG if fail, as the cost of spills is greater
     * than splitting a double load/store in two operations. */
    if (jit_reg_free_p(_R0) && jit_reg_free_p(_R1)) {
	jit_regset_setbit(_jit->regarg, _R0);
	jit_regset_setbit(_jit->regarg, _R1);
	return (_R0);
    }
    if (jit_reg_free_p(_R2) && jit_reg_free_p(_R3)) {
	jit_regset_setbit(_jit->regarg, _R2);
	jit_regset_setbit(_jit->regarg, _R3);
	return (_R2);
    }
    if (jit_reg_free_p(_R4) && jit_reg_free_p(_R5)) {
	jit_regset_setbit(_jit->regarg, _R4);
	jit_regset_setbit(_jit->regarg, _R5);
	return (_R4);
    }
    if (jit_reg_free_p(_R6) && jit_reg_free_p(_R7)) {
	jit_regset_setbit(_jit->regarg, _R6);
	jit_regset_setbit(_jit->regarg, _R7);
	return (_R6);
    }
    if (jit_reg_free_p(_R8) && jit_reg_free_p(_R9)) {
	jit_regset_setbit(_jit->regarg, _R8);
	jit_regset_setbit(_jit->regarg, _R9);
	return (_R8);
    }
    return (JIT_NOREG);
}

static void
_jit_unget_reg_pair(jit_state_t *_jit, jit_int32_t reg)
{
    jit_unget_reg(reg);
    switch (reg) {
	case _R0:	jit_unget_reg(_R1);	break;
	case _R2:	jit_unget_reg(_R3);	break;
	case _R4:	jit_unget_reg(_R5);	break;
	case _R6:	jit_unget_reg(_R7);	break;
	case _R8:	jit_unget_reg(_R9);	break;
	default:	abort();
    }
}

static void
_load_const(jit_state_t *_jit, jit_bool_t uniq, jit_int32_t r0, jit_word_t i0)
{
    jit_word_t		 w;
    jit_word_t		 d;
    jit_word_t		 base;
    jit_int32_t		*data;
    jit_int32_t		 size;
    jit_int32_t		 offset;

    assert(!jit_thumb_p());
    if (!uniq) {
	/* use zero, a valid directly encoded immediate, to avoid the
	 * need of a bitmask to know what offsets will be patched, so
	 * that comparison will always fail for constants that cannot
	 * be encoded */
	assert(i0 != 0);

	/* Actually, code is (currently at least) not self modifying,
	 * so, any value reachable backwards is valid as a constant. */

	/* FIXME a quickly updateable/mutable hash table could be
	 * better here, but most times only a few comparisons
	 * should be done
	 */

	/* search in previous constant pool */
	if ((data = (jit_int32_t *)_jit->consts.data)) {
	    w = (jit_word_t)data;
	    /* maximum backwards offset */
	    base = (_jit->pc.w + 8) - 4092;
	    if (base <= w)
		/* can scan all possible available backward constants */
		base = 0;
	    else
		base = (base - w) >> 2;
	    size = _jit->consts.size >> 2;
	    for (offset = size - 1; offset >= base; offset--) {
		if (data[offset] == i0) {
		    w = (jit_word_t)(data + offset);
		    d = (_jit->pc.w + 8) - w;
		    LDRIN(r0, _R15_REGNO, d);
		    return;
		}
	    }
	}
    }
    else
	assert(i0 == 0);

    _jit->consts.patches[_jit->consts.offset++] = _jit->pc.w;
    /* (probably) positive forward offset */
    LDRI(r0, _R15_REGNO, 0);

    if (!uniq) {
	/* search already requested values */
	for (offset = 0; offset < _jit->consts.length; offset++) {
	    if (_jit->consts.values[offset] == i0) {
		_jit->consts.patches[_jit->consts.offset++] = offset;
		return;
	    }
	}
    }

#if DEBUG
    /* cannot run out of space because of limited range
     * but assert anyway to catch logic errors */
    assert(_jit->consts.length < 1024);
    assert(_jit->consts.offset < 2048);
#endif
    _jit->consts.patches[_jit->consts.offset++] = _jit->consts.length;
    _jit->consts.values[_jit->consts.length++] = i0;
}

static void
_flush_consts(jit_state_t *_jit)
{
    jit_word_t		 word;
    jit_int32_t		 offset;

    /* if no forward constants */
    if (!_jit->consts.length)
	return;
    assert(!jit_thumb_p());
    word = _jit->pc.w;
    _jit->consts.data = _jit->pc.uc;
    _jit->consts.size = _jit->consts.length << 2;
    /* FIXME check will not overrun, otherwise, need to reallocate
     * code buffer and start over */
    memcpy(_jit->consts.data, _jit->consts.values, _jit->consts.size);
    _jit->pc.w += _jit->consts.size;

    if (_jit->data_info.ptr) {
	if (_jit->data_info.offset >= _jit->data_info.length) {
	    _jit->data_info.ptr = realloc(_jit->data_info.ptr,
					  (_jit->data_info.length + 1024) *
					  sizeof(jit_data_info_t));
	    memset(_jit->data_info.ptr + _jit->data_info.length, 0,
		   1024 * sizeof(jit_data_info_t));
	    _jit->data_info.length += 1024;
	}
	_jit->data_info.ptr[_jit->data_info.offset].code = word;
	_jit->data_info.ptr[_jit->data_info.offset].length = _jit->consts.size;
	++_jit->data_info.offset;
    }

    for (offset = 0; offset < _jit->consts.offset; offset += 2)
	patch_at(arm_patch_load, _jit->consts.patches[offset],
		 word + (_jit->consts.patches[offset + 1] << 2));
    _jit->consts.length = _jit->consts.offset = 0;
}

/* to be called if needing to start over a function */
static void
_invalidate_consts(jit_state_t *_jit)
{
    /* if no forward constants */
    if (_jit->consts.length)
	_jit->consts.length = _jit->consts.offset = 0;
}

static void
_patch(jit_state_t *_jit, jit_word_t instr, jit_node_t *node)
{
    jit_int32_t		 flag;
    jit_int32_t		 kind;

    assert(node->flag & jit_flag_node);
    if (node->code == jit_code_movi) {
	flag = node->v.n->flag;
	kind = arm_patch_word;
    }
    else {
	flag = node->u.n->flag;
#if 1
	/* should work if #if 0'ed, but better to avoid the goto fallback */
	if (node->code == jit_code_calli && jit_thumb_p())
	    kind = arm_patch_word;
	else
#endif
	    kind = arm_patch_jump;
    }
    assert(!(flag & jit_flag_patch));
    kind |= arm_patch_node;
    if (_jit->patches.offset >= _jit->patches.length) {
	_jit->patches.ptr = realloc(_jit->patches.ptr,
				    (_jit->patches.length + 1024) *
				    sizeof(jit_patch_t));
	memset(_jit->patches.ptr + _jit->patches.length, 0,
	       1024 * sizeof(jit_patch_t));
	_jit->patches.length += 1024;
    }
    _jit->patches.ptr[_jit->patches.offset].kind = kind;
    _jit->patches.ptr[_jit->patches.offset].inst = instr;
    _jit->patches.ptr[_jit->patches.offset].node = node;
    ++_jit->patches.offset;
}