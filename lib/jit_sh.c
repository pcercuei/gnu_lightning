/*
 * Copyright (C) 2022  Free Software Foundation, Inc.
 *
 * This file is part of GNU lightning.
 *
 * GNU lightning is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU lightning is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * Authors:
 *	Paul Cercueil
 */

#  define NUM_WORD_ARGS			4
#  define STACK_SLOT			4
#  define STACK_SHIFT			2
#  define WORD_ADJUST			0

#define jit_arg_reg_p(i)		((i) >= 0 && (i) < NUM_WORD_ARGS)

#define fpr_args_inverted()		(__BYTE_ORDER == __LITTLE_ENDIAN && !SH_SINGLE_ONLY)

#if __BYTE_ORDER == __LITTLE_ENDIAN
#  define C_DISP			0
#  define S_DISP			0
#  define I_DISP			0
#else
#  define C_DISP			STACK_SLOT - sizeof(jit_int8_t)
#  define S_DISP			STACK_SLOT - sizeof(jit_int16_t)
#  define I_DISP			STACK_SLOT - sizeof(jit_int32_t)
#endif

#define jit_make_arg(node,code)		_jit_make_arg(_jit,node,code)
static jit_node_t *_jit_make_arg(jit_state_t*,jit_node_t*,jit_code_t);
#define jit_make_arg_f(node)		_jit_make_arg_f(_jit,node)
static jit_node_t *_jit_make_arg_f(jit_state_t*,jit_node_t*);
#define jit_make_arg_d(node)		_jit_make_arg_d(_jit,node)
static jit_node_t *_jit_make_arg_d(jit_state_t*,jit_node_t*);
#define load_const(uniq,r0,i0)		_load_const(_jit,uniq,r0,i0)
static void _load_const(jit_state_t*,jit_bool_t,jit_int32_t,jit_word_t);
#define load_const_f(uniq,r0,i0)	_load_const_f(_jit,uniq,r0,i0)
static void _load_const_f(jit_state_t*,jit_bool_t,jit_int32_t,jit_float32_t);
#define flush_consts(force)		_flush_consts(_jit,force)
static void _flush_consts(jit_state_t*,jit_bool_t);
#define invalidate_consts()		_invalidate_consts(_jit)
static void _invalidate_consts(jit_state_t*);
#define patch(instr, node)		_patch(_jit, instr, node)
static void _patch(jit_state_t*,jit_word_t,jit_node_t*);

#define PROTO 1
#  include "jit_rewind.c"
#  include "jit_sh-cpu.c"
#  include "jit_sh-fpu.c"
#  include "jit_fallback.c"
#undef PROTO

jit_register_t _rvs[] = {
    { 0x0,				"r0" },
    { rc(gpr) | 0x1,			"r1" },
    { rc(gpr) | 0x2,			"r2" },
    { rc(gpr) | 0x3,			"r3" },
    { rc(arg) | rc(gpr) | 0x4,		"r4" },
    { rc(arg) | rc(gpr) | 0x5,		"r5" },
    { rc(arg) | rc(gpr) | 0x6,		"r6" },
    { rc(arg) | rc(gpr) | 0x7,		"r7" },
    { rc(sav) | rc(gpr) | 0x8,		"r8" },
    { rc(sav) | rc(gpr) | 0x9,		"r9" },
    { rc(sav) | rc(gpr) | 0xa,		"r10" },
    { rc(sav) | rc(gpr) | 0xb,		"r11" },
    { rc(sav) | rc(gpr) | 0xc,		"r12" },
    { rc(sav) | rc(gpr) | 0xd,		"r13" },
    { rc(sav) | 0xe,			"r14" },
    { rc(sav) | 0xf,			"r15" },
    { 0x10,				"gbr" },

    /* Only use half of the floating-point registers.
     * This makes it much easier to switch between
     * float and double processing. */
    { rc(fpr) | 0x0,			"$f0" },
    { 0x1,				"$f1" },
    { rc(fpr) | 0x2,			"$f2" },
    { 0x3,				"$f3" },
    { rc(arg) | rc(fpr) | 0x4,		"$f4" },
    { 0x5,				"$f5" },
    { rc(arg) | rc(fpr) | 0x6,		"$f6" },
    { 0x7,				"$f7" },
    { rc(arg) | rc(fpr) | 0x8,		"$f8" },
    { 0x9,				"$f9" },
    { rc(arg) | rc(fpr) | 0xa,		"$f10" },
    { 0xb,				"$f11" },
    { rc(sav) | rc(fpr) | 0xc,		"$f12" },
    { rc(sav) | 0xd,			"$f13" },
    { rc(sav) | rc(fpr) | 0xe,		"$f14" },
    { rc(sav) | 0xf,			"$f15" },

    { _XF0,				"$xf0" },
    { _XF1,				"$xf1" },
    { _XF2,				"$xf2" },
    { _XF3,				"$xf3" },
    { _XF4,				"$xf4" },
    { _XF5,				"$xf5" },
    { _XF6,				"$xf6" },
    { _XF7,				"$xf7" },
    { _XF8,				"$xf8" },
    { _XF9,				"$xf9" },
    { _XF10,				"$xf10" },
    { _XF11,				"$xf11" },
    { rc(sav) | _XF12,			"$xf12" },
    { rc(sav) | _XF13,			"$xf13" },
    { rc(sav) | _XF14,			"$xf14" },
    { rc(sav) | _XF15,			"$xf15" },
};

void
jit_get_cpu(void)
{
}

void
_jit_init(jit_state_t *_jit)
{
	_jitc->reglen = jit_size(_rvs) - 1;
}

void
_jit_prolog(jit_state_t *_jit)
{
    jit_int32_t		 offset;

    if (_jitc->function)
	jit_epilog();

    assert(jit_regset_cmp_ui(&_jitc->regarg, 0) == 0);

    jit_regset_set_ui(&_jitc->regsav, 0);
    offset = _jitc->functions.offset;

    if (offset >= _jitc->functions.length) {
	jit_realloc((jit_pointer_t *)&_jitc->functions.ptr,
		    _jitc->functions.length * sizeof(jit_function_t),
		    (_jitc->functions.length + 16) * sizeof(jit_function_t));
	_jitc->functions.length += 16;
    }

    _jitc->function = _jitc->functions.ptr + _jitc->functions.offset++;
    _jitc->function->self.size = stack_framesize;
    _jitc->function->self.argi = _jitc->function->self.argf =
	_jitc->function->self.aoff = _jitc->function->self.alen = 0;
    _jitc->function->self.call = jit_call_default;

    jit_alloc((jit_pointer_t *)&_jitc->function->regoff,
	      _jitc->reglen * sizeof(jit_int32_t));

    /* _no_link here does not mean the jit_link() call can be removed
     * by rewriting as:
     * _jitc->function->prolog = jit_new_node(jit_code_prolog);
     */
    _jitc->function->prolog = jit_new_node_no_link(jit_code_prolog);
    jit_link(_jitc->function->prolog);

    _jitc->function->prolog->w.w = offset;
    _jitc->function->epilog = jit_new_node_no_link(jit_code_epilog);
    /*	u:	label value
     *	v:	offset in blocks vector
     *	w:	offset in functions vector
     */
    _jitc->function->epilog->w.w = offset;

    jit_regset_new(&_jitc->function->regset);
}

jit_int32_t
_jit_allocai(jit_state_t *_jit, jit_int32_t length)
{
    assert(_jitc->function);
    switch (length) {
	case 0:	case 1:						break;
	case 2:		_jitc->function->self.aoff &= -2;	break;
	case 3:	case 4:	_jitc->function->self.aoff &= -4;	break;
	default:	_jitc->function->self.aoff &= -8;	break;
    }
    _jitc->function->self.aoff -= length;
    if (!_jitc->realize) {
	jit_inc_synth_ww(allocai, _jitc->function->self.aoff, length);
	jit_dec_synth();
    }
    return (_jitc->function->self.aoff);
}

void
_jit_allocar(jit_state_t *_jit, jit_int32_t u, jit_int32_t v)
{
    jit_int32_t		 reg;
    assert(_jitc->function);
    jit_inc_synth_ww(allocar, u, v);
    if (!_jitc->function->allocar) {
	_jitc->function->aoffoff = jit_allocai(sizeof(jit_int32_t));
	_jitc->function->allocar = 1;
    }
    reg = jit_get_reg(jit_class_gpr);
    jit_negr(reg, v);
    jit_andi(reg, reg, -8);
    jit_ldxi_i(u, JIT_FP, _jitc->function->aoffoff);
    jit_addr(u, u, reg);
    jit_addr(JIT_SP, JIT_SP, reg);
    jit_stxi_i(_jitc->function->aoffoff, JIT_FP, u);
    jit_unget_reg(reg);
    jit_dec_synth();
}

void
_jit_ret(jit_state_t *_jit)
{
    jit_node_t		*instr;
    assert(_jitc->function);
    jit_inc_synth(ret);
    /* jump to epilog */
    instr = jit_jmpi();
    jit_patch_at(instr, _jitc->function->epilog);
    jit_dec_synth();
}

void
_jit_retr(jit_state_t *_jit, jit_int32_t u, jit_code_t code)
{
    jit_code_inc_synth_w(code, u);
    jit_movr(JIT_RET, u);
    jit_live(JIT_RET);
    jit_ret();
    jit_dec_synth();
}

void
_jit_reti(jit_state_t *_jit, jit_word_t u, jit_code_t code)
{
    jit_code_inc_synth_w(code, u);
    jit_movi(JIT_RET, u);
    jit_ret();
    jit_dec_synth();
}

void
_jit_epilog(jit_state_t *_jit)
{
    assert(_jitc->function);
    assert(_jitc->function->epilog->next == NULL);
    jit_link(_jitc->function->epilog);
    _jitc->function = NULL;
}

void
_jit_putargr(jit_state_t *_jit, jit_int32_t u, jit_node_t *v, jit_code_t code)
{
    assert_putarg_type(code, v->code);
    jit_code_inc_synth_wp(code, u, v);
    if (jit_arg_reg_p(v->u.w))
	jit_movr(JIT_RA0 + v->u.w, u);
    else
	jit_stxi(v->u.w, JIT_FP, u);
    jit_dec_synth();
}

void
_jit_putargi(jit_state_t *_jit, jit_word_t u, jit_node_t *v, jit_code_t code)
{
    jit_int32_t		regno;
    assert_putarg_type(code, v->code);
    jit_code_inc_synth_wp(code, u, v);
    if (jit_arg_reg_p(v->u.w))
        jit_movi(JIT_RA0 + v->u.w, u);
    else {
        regno = jit_get_reg(jit_class_gpr);
        jit_movi(regno, u);
        jit_stxi(v->u.w, JIT_FP, regno);
        jit_unget_reg(regno);
    }
    jit_dec_synth();
}

jit_bool_t
_jit_regarg_p(jit_state_t *_jit, jit_node_t *node, jit_int32_t regno)
{
    jit_int32_t		spec;

    spec = jit_class(_rvs[regno].spec);
    if (spec & jit_class_arg) {
	if (spec & jit_class_gpr) {
	    regno = JIT_RA0 + regno;
	    if (regno >= 0 && regno < node->v.w)
		return (1);
	}
	else if (spec & jit_class_fpr) {
	    regno = JIT_FA0 + regno;
	    if (regno >= 0 && regno < node->w.w)
		return (1);
	}
    }

    return (0);
}

jit_pointer_t
_emit_code(jit_state_t *_jit)
{
    jit_node_t		*node;
    jit_node_t		*temp;
    jit_word_t		 word;
    jit_word_t		 value;
    jit_int32_t		 offset;
    struct {
	jit_node_t	*node;
	jit_uint8_t	*data;
	jit_word_t	 word;
#if DEVEL_DISASSEMBLER
	jit_word_t	 prevw;
#endif
#if DISASSEMBLER
	jit_int32_t	 info_offset;
#endif
	jit_int32_t	 const_offset;
	jit_int32_t	 patch_offset;
    } undo;
#if DEVEL_DISASSEMBLER
    jit_word_t		 prevw;
#endif

    _jitc->function = NULL;
    _jitc->no_flag = 0;
    _jitc->mode_d = SH_DEFAULT_FPU_MODE;

    jit_reglive_setup();

    _jitc->consts.data = NULL;
    _jitc->consts.offset = _jitc->consts.length = 0;

    undo.word = 0;
    undo.node = NULL;
    undo.data = NULL;
#if DISASSEMBLER
    undo.info_offset =
#endif
    undo.const_offset = undo.patch_offset = 0;
#define case_rr(name, type)						\
	    case jit_code_##name##r##type:				\
		name##r##type(rn(node->u.w), rn(node->v.w));		\
		break
#define case_rw(name, type)						\
	    case jit_code_##name##i##type:				\
		name##i##type(rn(node->u.w), node->v.w);		\
		break
#define case_wr(name, type)						\
	    case jit_code_##name##i##type:				\
		name##i##type(node->u.w, rn(node->v.w));		\
		break
#define case_rrr(name, type)						\
	    case jit_code_##name##r##type:				\
		name##r##type(rn(node->u.w),				\
			      rn(node->v.w), rn(node->w.w));		\
		break
#define case_rrrr(name, type)						\
	    case jit_code_##name##r##type:				\
		name##r##type(rn(node->u.q.l), rn(node->u.q.h),		\
			      rn(node->v.w), rn(node->w.w));		\
		break
#define case_rrw(name, type)						\
	    case jit_code_##name##i##type:				\
		name##i##type(rn(node->u.w), rn(node->v.w), node->w.w);	\
		break
#define case_rrx(name, type)						\
	    case jit_code_##name##i##type:				\
		name##i##type(rn(node->u.w),				\
			      rn(node->v.w), node->w.w);		\
	       break
#define case_rrX(name, type)						\
	    case jit_code_##name##r##type:				\
		generic_##name##r##type(rn(node->u.w),			\
					rn(node->v.w), rn(node->w.w));	\
		break
#define case_xrr(name, type)						\
	    case jit_code_##name##i##type:				\
		name##i##type(node->u.w, rn(node->v.w),			\
			      rn(node->w.w));				\
		break
#define case_Xrr(name, type)						\
	    case jit_code_##name##r##type:				\
		generic_##name##r##type(rn(node->u.w), rn(node->v.w),	\
					rn(node->w.w));			\
		break
#define case_rrrw(name, type)						\
	    case jit_code_##name##i##type:				\
		name##i##type(rn(node->u.q.l), rn(node->u.q.h),		\
			      rn(node->v.w), node->w.w);		\
		break
#define case_rqr(name, type)						\
	    case jit_code_##name##r##type:				\
		name##r##type(rn(node->u.w), rn(node->v.q.l),		\
			      rn(node->v.q.h), rn(node->w.w));		\
	    case jit_code_##name##i##type:				\
		break;
#define case_rrf(name)							\
	    case jit_code_##name##i_f:					\
		name##i_f(rn(node->u.w), rn(node->v.w), node->w.f);	\
		break
#define case_rrd(name)							\
	    case jit_code_##name##i_d:					\
		name##i_d(rn(node->u.w), rn(node->v.w), node->w.d);	\
		break
#define case_wrr(name, type)						\
	    case jit_code_##name##i##type:				\
		name##i##type(node->u.w, rn(node->v.w), rn(node->w.w));	\
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
		    word = _jit->code.length				\
			- (_jit->pc.uc - _jit->code.ptr);		\
		    if (word < 4094) {					\
			word = name##r##type(0, rn(node->v.w),		\
					     rn(node->w.w));		\
		    } else {						\
			word = name##r##type##_p(_jit->pc.w,		\
						 rn(node->v.w),		\
						 rn(node->w.w), 1);	\
		    }							\
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
		    word = _jit->code.length				\
			- (_jit->pc.uc - _jit->code.ptr);		\
		    if (word < 4094) {					\
			word = name##i##type(0, rn(node->v.w),		\
					     node->w.w);		\
		    } else {						\
			word = name##i##type##_p(_jit->pc.w,		\
						 rn(node->v.w),		\
						 node->w.w, 1);		\
		    }							\
		    patch(word, node);					\
		}							\
		break;
#define case_brf(name)							\
	    case jit_code_##name##i_f:					\
		temp = node->u.n;					\
		assert(temp->code == jit_code_label ||			\
		       temp->code == jit_code_epilog);			\
		if (temp->flag & jit_flag_patch)			\
		    name##i_f(temp->u.w, rn(node->v.w), node->w.f);	\
		else {							\
		    word = name##i_f_p(_jit->pc.w, rn(node->v.w),	\
				       node->w.f, 1);			\
		    patch(word, node);					\
		}							\
		break
#define case_brd(name)							\
	    case jit_code_##name##i_d:					\
		temp = node->u.n;					\
		assert(temp->code == jit_code_label ||			\
		       temp->code == jit_code_epilog);			\
		if (temp->flag & jit_flag_patch)			\
		    name##i_d(temp->u.w, rn(node->v.w), node->w.d);	\
		else {							\
		    word = name##i_d_p(_jit->pc.w, rn(node->v.w),	\
				       node->w.d, 1);			\
		    patch(word, node);					\
		}							\
		break
#if DEVEL_DISASSEMBLER
    prevw = _jit->pc.w;
#endif
    for (node = _jitc->head; node; node = node->next) {
	if (_jit->pc.uc >= _jitc->code.end)
	    return (NULL);

#if DEVEL_DISASSEMBLER
	node->offset = (jit_uword_t)_jit->pc.w - (jit_uword_t)prevw;
	prevw = _jit->pc.w;
#endif
	value = jit_classify(node->code);
	jit_regarg_set(node, value);
	switch (node->code) {
	    case jit_code_align:
		/* Must align to a power of two */
		assert(!(node->u.w & (node->u.w - 1)));
		if ((word = _jit->pc.w & (node->u.w - 1)))
		    nop(node->u.w - word);
		break;
	    case jit_code_skip:
		nop((node->u.w + 3) & ~3);
		break;
	    case jit_code_note:		case jit_code_name:
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
		case_rrw(rsb,);
		case_rrr(mul,);
		case_rrw(mul,);
		case_rrr(hmul,);
		case_rrw(hmul,);
		case_rrr(hmul, _u);
		case_rrw(hmul, _u);
		case_rrrr(qmul,);
		case_rrrw(qmul,);
		case_rrrr(qmul, _u);
		case_rrrw(qmul, _u);
		case_rrr(div,);
		case_rrw(div,);
		case_rrr(div, _u);
		case_rrw(div, _u);
		case_rrrr(qdiv,);
		case_rrrw(qdiv,);
		case_rrrr(qdiv, _u);
		case_rrrw(qdiv, _u);
		case_rrr(rem,);
		case_rrw(rem,);
		case_rrr(rem, _u);
		case_rrw(rem, _u);
		case_rrr(lsh,);
		case_rrw(lsh,);
		case_rrrr(qlsh,);
		case_rrrw(qlsh,);
		case_rrrr(qlsh, _u);
		case_rrrw(qlsh, _u);
		case_rrr(rsh,);
		case_rrw(rsh,);
		case_rrr(rsh, _u);
		case_rrw(rsh, _u);
		case_rrrr(qrsh,);
		case_rrrw(qrsh,);
		case_rrrr(qrsh, _u);
		case_rrrw(qrsh, _u);
		case_rr(neg,);
		case_rr(com,);
		case_rr(clo,);
		case_rr(clz,);
		case_rr(cto,);
		case_rr(ctz,);
		case_rr(rbit,);
		case_rr(popcnt,);
		case_rrr(lrot,);
		case_rrw(lrot,);
		case_rrr(rrot,);
		case_rrw(rrot,);
		case_rrr(and,);
		case_rrw(and,);
		case_rrr(or,);
		case_rrw(or,);
		case_rrr(xor,);
		case_rrw(xor,);
		case_rr(trunc, _f_i);
		case_rr(trunc, _d_i);
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
	    case jit_code_unldr:
		unldr(rn(node->u.w), rn(node->v.w), node->w.w);
		break;
	    case jit_code_unldi:
		unldi(rn(node->u.w), node->v.w, node->w.w);
		break;
	    case jit_code_unldr_u:
		unldr_u(rn(node->u.w), rn(node->v.w), node->w.w);
		break;
	    case jit_code_unldi_u:
		unldi_u(rn(node->u.w), node->v.w, node->w.w);
		break;
		case_rrx(ldxb, _c);	case_rrX(ldxb, _c);
		case_rrx(ldxa, _c);	case_rrX(ldxa, _c);
		case_rrx(ldxb, _uc);	case_rrX(ldxb, _uc);
		case_rrx(ldxa, _uc);	case_rrX(ldxa, _uc);
		case_rrx(ldxb, _s);	case_rrX(ldxb, _s);
		case_rrx(ldxa, _s);	case_rrX(ldxa, _s);
		case_rrx(ldxb, _us);	case_rrX(ldxb, _us);
		case_rrx(ldxa, _us);	case_rrX(ldxa, _us);
		case_rrx(ldxb, _i);	case_rrX(ldxb, _i);
		case_rrx(ldxa, _i);	case_rrX(ldxa, _i);
		case_rrx(ldxb, _f);	case_rrX(ldxb, _f);
		case_rrx(ldxa, _f);	case_rrX(ldxa, _f);
		case_rrx(ldxb, _d);	case_rrX(ldxb, _d);
		case_rrx(ldxa, _d);	case_rrX(ldxa, _d);
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
	    case jit_code_unstr:
		unstr(rn(node->u.w), rn(node->v.w), node->w.w);
		break;
	    case jit_code_unsti:
		unsti(node->u.w, rn(node->v.w), node->w.w);
		break;
		case_xrr(stxb, _c);	case_Xrr(stxb, _c);
		case_xrr(stxa, _c);	case_Xrr(stxa, _c);
		case_xrr(stxb, _s);	case_Xrr(stxb, _s);
		case_xrr(stxa, _s);	case_Xrr(stxa, _s);
		case_xrr(stxb, _i);	case_Xrr(stxb, _i);
		case_xrr(stxa, _i);	case_Xrr(stxa, _i);
		case_xrr(stxb, _f);	case_rrX(stxb, _f);
		case_xrr(stxa, _f);	case_rrX(stxa, _f);
		case_xrr(stxb, _d);	case_rrX(stxb, _d);
		case_xrr(stxa, _d);	case_rrX(stxa, _d);
		case_rr(hton, _us);
		case_rr(hton, _ui);
		case_rr(bswap, _us);
		case_rr(bswap, _ui);
	    case jit_code_extr:
		extr(rn(node->u.w), rn(node->v.w), node->w.q.l, node->w.q.h);
		break;
	    case jit_code_extr_u:
		extr_u(rn(node->u.w), rn(node->v.w), node->w.q.l, node->w.q.h);
		break;
	    case jit_code_depr:
		depr(rn(node->u.w), rn(node->v.w), node->w.q.l, node->w.q.h);
		break;
	    case jit_code_depi:
		depi(rn(node->u.w), node->v.w, node->w.q.l, node->w.q.h);
		break;
		case_rr(ext, _c);
		case_rr(ext, _uc);
		case_rr(ext, _s);
		case_rr(ext, _us);
		case_rrr(movn,);
		case_rrr(movz,);
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
		case_rrr(add, _f);
		case_rrf(add);
		case_rrr(sub, _f);
		case_rrf(sub);
		case_rrf(rsb);
		case_rrr(mul, _f);
		case_rrf(mul);
		case_rrr(div, _f);
		case_rrf(div);
		case_rr(abs, _f);
		case_rr(neg, _f);
		case_rr(sqrt, _f);
		case_rqr(fma, _f);
		case_rqr(fms, _f);
		case_rqr(fnma, _f);
		case_rqr(fnms, _f);
		case_rr(ext, _f);
		case_rr(ld, _f);
		case_rw(ld, _f);
		case_rrr(ldx, _f);
		case_rrw(ldx, _f);
	    case jit_code_unldr_x:
		unldr_x(rn(node->u.w), rn(node->v.w), node->w.w);
		break;
	    case jit_code_unldi_x:
		unldi_x(rn(node->u.w), node->v.w, node->w.w);
		break;
		case_rr(st, _f);
		case_wr(st, _f);
		case_rrr(stx, _f);
		case_wrr(stx, _f);
	    case jit_code_unstr_x:
		unstr_x(rn(node->u.w), rn(node->v.w), node->w.w);
		break;
	    case jit_code_unsti_x:
		unsti_x(node->u.w, rn(node->v.w), node->w.w);
		break;
		case_rr(mov, _f);
	    case jit_code_movi_f:
		movi_f(rn(node->u.w), node->v.f);
		break;
		case_rr(ext, _d_f);
		case_rrr(lt, _f);
		case_rrf(lt);
		case_rrr(le, _f);
		case_rrf(le);
		case_rrr(eq, _f);
		case_rrf(eq);
		case_rrr(ge, _f);
		case_rrf(ge);
		case_rrr(gt, _f);
		case_rrf(gt);
		case_rrr(ne, _f);
		case_rrf(ne);
		case_rrr(unlt, _f);
		case_rrf(unlt);
		case_rrr(unle, _f);
		case_rrf(unle);
		case_rrr(uneq, _f);
		case_rrf(uneq);
		case_rrr(unge, _f);
		case_rrf(unge);
		case_rrr(ungt, _f);
		case_rrf(ungt);
		case_rrr(ltgt, _f);
		case_rrf(ltgt);
		case_rrr(ord, _f);
		case_rrf(ord);
		case_rrr(unord, _f);
		case_rrf(unord);
		case_brr(blt, _f);
		case_brf(blt);
		case_brr(ble, _f);
		case_brf(ble);
		case_brr(beq, _f);
		case_brf(beq);
		case_brr(bge, _f);
		case_brf(bge);
		case_brr(bgt, _f);
		case_brf(bgt);
		case_brr(bne, _f);
		case_brf(bne);
		case_brr(bunlt, _f);
		case_brf(bunlt);
		case_brr(bunle, _f);
		case_brf(bunle);
		case_brr(buneq, _f);
		case_brf(buneq);
		case_brr(bunge, _f);
		case_brf(bunge);
		case_brr(bungt, _f);
		case_brf(bungt);
		case_brr(bltgt, _f);
		case_brf(bltgt);
		case_brr(bord, _f);
		case_brf(bord);
		case_brr(bunord, _f);
		case_brf(bunord);
		case_rrr(add, _d);
		case_rrd(add);
		case_rrr(sub, _d);
		case_rrd(sub);
		case_rrd(rsb);
		case_rrr(mul, _d);
		case_rrd(mul);
		case_rrr(div, _d);
		case_rrd(div);
		case_rr(abs, _d);
		case_rr(neg, _d);
		case_rr(sqrt, _d);
		case_rqr(fma, _d);
		case_rqr(fms, _d);
		case_rqr(fnma, _d);
		case_rqr(fnms, _d);
		case_rr(ext, _d);
		case_rr(ld, _d);
		case_rw(ld, _d);
		case_rrr(ldx, _d);
		case_rrw(ldx, _d);
		case_rr(st, _d);
		case_wr(st, _d);
		case_rrr(stx, _d);
		case_wrr(stx, _d);
		case_rr(mov, _d);
	    case jit_code_movi_d:
		movi_d(rn(node->u.w), node->v.d);
		break;
		case_rr(ext, _f_d);
		case_rrr(lt, _d);
		case_rrd(lt);
		case_rrr(le, _d);
		case_rrd(le);
		case_rrr(eq, _d);
		case_rrd(eq);
		case_rrr(ge, _d);
		case_rrd(ge);
		case_rrr(gt, _d);
		case_rrd(gt);
		case_rrr(ne, _d);
		case_rrd(ne);
		case_rrr(unlt, _d);
		case_rrd(unlt);
		case_rrr(unle, _d);
		case_rrd(unle);
		case_rrr(uneq, _d);
		case_rrd(uneq);
		case_rrr(unge, _d);
		case_rrd(unge);
		case_rrr(ungt, _d);
		case_rrd(ungt);
		case_rrr(ltgt, _d);
		case_rrd(ltgt);
		case_rrr(ord, _d);
		case_rrd(ord);
		case_rrr(unord, _d);
		case_rrd(unord);
		case_brr(blt, _d);
		case_brd(blt);
		case_brr(ble, _d);
		case_brd(ble);
		case_brr(beq, _d);
		case_brd(beq);
		case_brr(bge, _d);
		case_brd(bge);
		case_brr(bgt, _d);
		case_brd(bgt);
		case_brr(bne, _d);
		case_brd(bne);
		case_brr(bunlt, _d);
		case_brd(bunlt);
		case_brr(bunle, _d);
		case_brd(bunle);
		case_brr(buneq, _d);
		case_brd(buneq);
		case_brr(bunge, _d);
		case_brd(bunge);
		case_brr(bungt, _d);
		case_brd(bungt);
		case_brr(bltgt, _d);
		case_brd(bltgt);
		case_brr(bord, _d);
		case_brd(bord);
		case_brr(bunord, _d);
		case_brd(bunord);
	    case jit_code_jmpr:
		jmpr(rn(node->u.w));
		flush_consts(0);
		break;
	    case jit_code_jmpi:
		if (node->flag & jit_flag_node) {
		    temp = node->u.n;
		    assert(temp->code == jit_code_label ||
			   temp->code == jit_code_epilog);
		    if (temp->flag & jit_flag_patch)
			jmpi(temp->u.w);
		    else {
			word = jmpi_p(_jit->pc.w);
			patch(word, node);
		    }
		}
		else
		    jmpi(node->u.w);
		flush_consts(0);
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
		_jitc->function = _jitc->functions.ptr + node->w.w;
		undo.node = node;
		undo.word = _jit->pc.w;
#if DEVEL_DISASSEMBLER
		undo.prevw = prevw;
#endif
		undo.data = _jitc->consts.data;
		undo.const_offset = _jitc->consts.offset;
		undo.patch_offset = _jitc->patches.offset;
#if DISASSEMBLER
		if (_jitc->data_info.ptr)
		    undo.info_offset = _jitc->data_info.offset;
#endif
	    restart_function:
		_jitc->again = 0;
		prolog(node);
		break;
	    case jit_code_epilog:
		assert(_jitc->function == _jitc->functions.ptr + node->w.w);
		if (_jitc->again) {
		    for (temp = undo.node->next;
			 temp != node; temp = temp->next) {
			if (temp->code == jit_code_label ||
			    temp->code == jit_code_epilog)
			    temp->flag &= ~jit_flag_patch;
		    }
		    temp->flag &= ~jit_flag_patch;
		    node = undo.node;
		    _jit->pc.w = undo.word;
#if DEVEL_DISASSEMBLER
		    prevw = undo.prevw;
#endif
		    invalidate_consts();
		    _jitc->consts.data = undo.data;
		    _jitc->consts.offset = undo.const_offset;
		    _jitc->patches.offset = undo.patch_offset;
#if DISASSEMBLER
		    if (_jitc->data_info.ptr)
			_jitc->data_info.offset = undo.info_offset;
#endif
		    goto restart_function;
		}
		/* remember label is defined */
		node->flag |= jit_flag_patch;
		node->u.w = _jit->pc.w;
		epilog(node);
		_jitc->function = NULL;
		flush_consts(0);
		break;
	    case jit_code_movr_w_f:
		movr_w_f(rn(node->u.w), rn(node->v.w));
		break;
	    case jit_code_movr_f_w:
		movr_f_w(rn(node->u.w), rn(node->v.w));
		break;
	    case jit_code_movi_f_w:
		movi_f_w(rn(node->u.w), node->v.f);
		break;
	    case jit_code_movi_w_f:
		movi_w_f(rn(node->u.w), node->v.w);
		break;
	    case jit_code_movr_ww_d:
		movr_ww_d(rn(node->u.w), rn(node->v.w), rn(node->w.w));
		break;
	    case jit_code_movr_d_ww:
		movr_d_ww(rn(node->u.w), rn(node->v.w), rn(node->w.w));
		break;
	    case jit_code_movi_d_ww:
		movi_d_ww(rn(node->u.w), rn(node->v.w), node->w.d);
		break;
	    case jit_code_movi_ww_d:
		movi_ww_d(rn(node->u.w), node->v.w, node->w.w);
		break;
#if 0
	    case jit_code_va_start:
		vastart(rn(node->u.w));
		break;
	    case jit_code_va_arg:
		vaarg(rn(node->u.w), rn(node->v.w));
		break;
	    case jit_code_va_arg_d:
		vaarg_d(rn(node->u.w), rn(node->v.w));
		break;
#endif
	    case jit_code_live:			case jit_code_ellipsis:
	    case jit_code_va_push:
	    case jit_code_allocai:		case jit_code_allocar:
	    case jit_code_arg_c:		case jit_code_arg_s:
	    case jit_code_arg_i:
	    case jit_code_arg_f:		case jit_code_arg_d:
	    case jit_code_va_end:
	    case jit_code_ret:
	    case jit_code_retr_c:		case jit_code_reti_c:
	    case jit_code_retr_uc:		case jit_code_reti_uc:
	    case jit_code_retr_s:		case jit_code_reti_s:
	    case jit_code_retr_us:		case jit_code_reti_us:
	    case jit_code_retr_i:		case jit_code_reti_i:
	    case jit_code_retr_f:		case jit_code_reti_f:
	    case jit_code_retr_d:		case jit_code_reti_d:
	    case jit_code_getarg_c:		case jit_code_getarg_uc:
	    case jit_code_getarg_s:		case jit_code_getarg_us:
	    case jit_code_getarg_i:		case jit_code_getarg_ui:
	    case jit_code_getarg_l:
	    case jit_code_getarg_f:		case jit_code_getarg_d:
	    case jit_code_putargr_c:		case jit_code_putargi_c:
	    case jit_code_putargr_uc:		case jit_code_putargi_uc:
	    case jit_code_putargr_s:		case jit_code_putargi_s:
	    case jit_code_putargr_us:		case jit_code_putargi_us:
	    case jit_code_putargr_i:		case jit_code_putargi_i:
	    case jit_code_putargr_f:		case jit_code_putargi_f:
	    case jit_code_putargr_d:		case jit_code_putargi_d:
	    case jit_code_pushargr_c:		case jit_code_pushargi_c:
	    case jit_code_pushargr_uc:		case jit_code_pushargi_uc:
	    case jit_code_pushargr_s:		case jit_code_pushargi_s:
	    case jit_code_pushargr_us:		case jit_code_pushargi_us:
	    case jit_code_pushargr_i:		case jit_code_pushargi_i:
	    case jit_code_pushargr_f:		case jit_code_pushargi_f:
	    case jit_code_pushargr_d:		case jit_code_pushargi_d:
	    case jit_code_retval_c:		case jit_code_retval_uc:
	    case jit_code_retval_s:		case jit_code_retval_us:
	    case jit_code_retval_i:
	    case jit_code_retval_f:		case jit_code_retval_d:
	    case jit_code_prepare:
	    case jit_code_finishr:		case jit_code_finishi:
		break;
	    case jit_code_casr:
		casr(rn(node->u.w), rn(node->v.w),
		     rn(node->w.q.l), rn(node->w.q.h));
		break;
	    case jit_code_casi:
		casi(rn(node->u.w), node->v.w,
		     rn(node->w.q.l), rn(node->w.q.h));
		break;
	    case jit_code_negi_f:		case jit_code_absi_f:
	    case jit_code_sqrti_f:		case jit_code_negi_d:
	    case jit_code_absi_d:		case jit_code_sqrti_d:
		break;
	    case jit_code_negi:
		negi(rn(node->u.w), node->v.w);
		break;
	    case jit_code_comi:
		comi(rn(node->u.w), node->v.w);
		break;
	    case jit_code_exti_c:
		exti_c(rn(node->u.w), node->v.w);
		break;
	    case jit_code_exti_uc:
		exti_uc(rn(node->u.w), node->v.w);
		break;
	    case jit_code_exti_s:
		exti_s(rn(node->u.w), node->v.w);
		break;
	    case jit_code_exti_us:
		exti_us(rn(node->u.w), node->v.w);
		break;
	    case jit_code_bswapi_us:
		bswapi_us(rn(node->u.w), node->v.w);
		break;
	    case jit_code_bswapi_ui:
		bswapi_ui(rn(node->u.w), node->v.w);
		break;
	    case jit_code_htoni_us:
		htoni_us(rn(node->u.w), node->v.w);
		break;
	    case jit_code_htoni_ui:
		htoni_ui(rn(node->u.w), node->v.w);
		break;
	    case jit_code_cloi:
		cloi(rn(node->u.w), node->v.w);
		break;
	    case jit_code_clzi:
		clzi(rn(node->u.w), node->v.w);
		break;
	    case jit_code_ctoi:
		ctoi(rn(node->u.w), node->v.w);
		break;
	    case jit_code_ctzi:
		ctzi(rn(node->u.w), node->v.w);
		break;
	    case jit_code_rbiti:
		rbiti(rn(node->u.w), node->v.w);
		break;
	    case jit_code_popcnti:
		popcnti(rn(node->u.w), node->v.w);
		break;
	    case jit_code_exti:
		exti(rn(node->u.w), node->v.w, node->w.q.l, node->w.q.h);
		break;
	    case jit_code_exti_u:
		exti_u(rn(node->u.w), node->v.w, node->w.q.l, node->w.q.h);
		break;
	    default:
		printf("ABORT MISSION (%i)\n", node->code);
		abort();
	}
	jit_regarg_clr(node, value);
	assert(_jitc->regarg == 0);
	assert(_jitc->synth == 0);
	/* update register live state */
	jit_reglive(node);

        _jitc->no_flag = !(node->flag & jit_flag_patch);

	if (!_jitc->no_flag) {
		/* We have a patch flag - reset FPU mode */
		set_fmode_no_r0(_jit, SH_DEFAULT_FPU_MODE);
	}

	if (_jitc->consts.length &&
	    (_jit->pc.uc - _jitc->consts.data >= 450 ||
	     (jit_uword_t)_jit->pc.uc -
	     (jit_uword_t)_jitc->consts.patches[0] >= 450)) {
	    /* longest sequence should be 64 bytes, but preventively
	     * do not let it go past 128 remaining bytes before a flush */
	    if (node->next &&
		node->next->code != jit_code_jmpi &&
		node->next->code != jit_code_jmpr &&
		node->next->code != jit_code_epilog) {
		/* insert a jump, flush constants and continue */
		word = _jit->pc.w;
		BRA(0);
		NOP();
		flush_consts(1);
		patch_at(word, _jit->pc.w);
	    }
	}
    }
#undef case_brw
#undef case_brr
#undef case_wrr
#undef case_rrw
#undef case_rrr
#undef case_wr
#undef case_rw
#undef case_rr

    flush_consts(1);

    for (offset = 0; offset < _jitc->patches.offset; offset++) {
	node = _jitc->patches.ptr[offset].node;
	word = _jitc->patches.ptr[offset].inst;
	value = node->code == jit_code_movi ? node->v.n->u.w : node->u.n->u.w;
	patch_at(word, value);
    }

    jit_flush(_jit->code.ptr, _jit->pc.uc);

    return (_jit->code.ptr);
}

#define CODE 1
#  include "jit_rewind.c"
#  include "jit_sh-cpu.c"
#  include "jit_sh-fpu.c"
#  include "jit_fallback.c"
#undef CODE

void
jit_flush(void *fptr, void *tptr)
{
#if defined(__GNUC__)
    jit_uword_t		i, f, t, s;

    s = sysconf(_SC_PAGE_SIZE);
    f = (jit_uword_t)fptr & -s;
    t = (((jit_uword_t)tptr) + s - 1) & -s;
    for (i = f; i < t; i += s)
	__clear_cache((void *)i, (void *)(i + s));
#endif
}

void
_emit_ldxi(jit_state_t *_jit, jit_int32_t r0, jit_int32_t r1, jit_word_t i0)
{
    ldxi(rn(r0), rn(r1), i0);
}

void
_emit_stxi(jit_state_t *_jit, jit_word_t i0, jit_int32_t r0, jit_int32_t r1)
{
    stxi(i0, rn(r0), rn(r1));
}

void
_emit_ldxi_d(jit_state_t *_jit, jit_int32_t r0, jit_int32_t r1, jit_word_t i0)
{
	/* No FPU support */
}

void
_emit_stxi_d(jit_state_t *_jit, jit_word_t i0, jit_int32_t r0, jit_int32_t r1)
{
	/* No FPU support */
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

    _jitc->consts.patches[_jitc->consts.offset++] = _jit->pc.w;
    /* positive forward offset */
    LDPL(r0, 0);

    if (!uniq) {
	/* search already requested values */
	for (offset = 0; offset < _jitc->consts.length; offset++) {
	    if (_jitc->consts.values[offset] == i0) {
		_jitc->consts.patches[_jitc->consts.offset++] = offset;
		return;
	    }
	}
    }

#if DEBUG
    /* cannot run out of space because of limited range
     * but assert anyway to catch logic errors */
    assert(_jitc->consts.length < 1024);
    assert(_jitc->consts.offset < 2048);
#endif
    _jitc->consts.patches[_jitc->consts.offset++] = _jitc->consts.length;
    _jitc->consts.values[_jitc->consts.length++] = i0;
}

static void
_load_const_f(jit_state_t *_jit, jit_bool_t uniq, jit_int32_t r0, jit_float32_t f0)
{
    jit_word_t		 w;
    jit_word_t		 d;
    jit_word_t		 base;
    jit_int32_t		*data;
    jit_int32_t		 size;
    jit_int32_t		 offset;
    union fl32 {
	    jit_int32_t i;
	    jit_float32_t f;
    };
    jit_uint32_t i0 = ((union fl32)f0).i;

    _jitc->consts.patches[_jitc->consts.offset++] = _jit->pc.w;
    /* positive forward offset */
    MOVA(0);
    LDF(r0, _R0);

    if (!uniq) {
	/* search already requested values */
	for (offset = 0; offset < _jitc->consts.length; offset++) {
	    if (_jitc->consts.values[offset] == i0) {
		_jitc->consts.patches[_jitc->consts.offset++] = offset;
		return;
	    }
	}
    }

#if DEBUG
    /* cannot run out of space because of limited range
     * but assert anyway to catch logic errors */
    assert(_jitc->consts.length < 1024);
    assert(_jitc->consts.offset < 2048);
#endif
    _jitc->consts.patches[_jitc->consts.offset++] = _jitc->consts.length;
    _jitc->consts.values[_jitc->consts.length++] = i0;
}

static void
_flush_consts(jit_state_t *_jit, jit_bool_t force)
{
    jit_word_t		 word;
    jit_int32_t		 offset;

    /* if no forward constants */
    if (!_jitc->consts.length)
	return;

    word = _jit->code.length - (_jit->pc.uc - _jit->code.ptr)
	    - (_jitc->consts.length << 1);
    if (!force && word < 1024)
	return;

    /* Align to 32 bits */
    if (_jit->pc.w & 0x3)
	    NOP();

    word = _jit->pc.w;
    _jitc->consts.data = _jit->pc.uc;
    _jitc->consts.size = _jitc->consts.length << 2;
    /* FIXME check will not overrun, otherwise, need to reallocate
     * code buffer and start over */
    jit_memcpy(_jitc->consts.data, _jitc->consts.values, _jitc->consts.size);
    _jit->pc.w += _jitc->consts.size;

#if DISASSEMBLER
    if (_jitc->data_info.ptr) {
	if (_jitc->data_info.offset >= _jitc->data_info.length) {
	    jit_realloc((jit_pointer_t *)&_jitc->data_info.ptr,
			_jitc->data_info.length * sizeof(jit_data_info_t),
			(_jitc->data_info.length + 1024) *
			sizeof(jit_data_info_t));
	    _jitc->data_info.length += 1024;
	}
	_jitc->data_info.ptr[_jitc->data_info.offset].code = word;
	_jitc->data_info.ptr[_jitc->data_info.offset].length = _jitc->consts.size;
	++_jitc->data_info.offset;
    }
#endif

    for (offset = 0; offset < _jitc->consts.offset; offset += 2)
	patch_at(_jitc->consts.patches[offset],
		 word + (_jitc->consts.patches[offset + 1] << 2));
    _jitc->consts.length = _jitc->consts.offset = 0;
}

/* to be called if needing to start over a function */
static void
_invalidate_consts(jit_state_t *_jit)
{
    /* if no forward constants */
    if (_jitc->consts.length)
	_jitc->consts.length = _jitc->consts.offset = 0;
}

static void
_patch(jit_state_t *_jit, jit_word_t instr, jit_node_t *node)
{
    jit_int32_t		 flag;

    assert(node->flag & jit_flag_node);
    if (node->code == jit_code_movi)
	flag = node->v.n->flag;
    else
	flag = node->u.n->flag;
    assert(!(flag & jit_flag_patch));
    if (_jitc->patches.offset >= _jitc->patches.length) {
	jit_realloc((jit_pointer_t *)&_jitc->patches.ptr,
		    _jitc->patches.length * sizeof(jit_patch_t),
		    (_jitc->patches.length + 1024) * sizeof(jit_patch_t));
	_jitc->patches.length += 1024;
    }
    _jitc->patches.ptr[_jitc->patches.offset].inst = instr;
    _jitc->patches.ptr[_jitc->patches.offset].node = node;
    ++_jitc->patches.offset;
}

static jit_node_t *
_jit_make_arg(jit_state_t *_jit, jit_node_t *node, jit_code_t code)
{
    jit_int32_t		 offset;

    if (jit_arg_reg_p(_jitc->function->self.argi))
	offset = _jitc->function->self.argi++;
    else {
	offset = _jitc->function->self.size;
	_jitc->function->self.size += STACK_SLOT;
    }

    if (node == (jit_node_t *)0)
	node = jit_new_node(code);
    else
	link_node(node);

    node->u.w = offset;
    node->v.w = ++_jitc->function->self.argn;
    jit_link_prolog();

    return (node);
}

static jit_node_t *
_jit_make_arg_f(jit_state_t *_jit, jit_node_t *node)
{
    jit_int32_t		 offset;

    if (jit_arg_reg_p(_jitc->function->self.argf)) {
	offset = _jitc->function->self.argf++;
	if (_jitc->function->self.call & jit_call_varargs)
	    offset += 8;
    }
    else {
	offset = _jitc->function->self.size;
	_jitc->function->self.size += STACK_SLOT;
    }
    if (node == (jit_node_t *)0)
	node = jit_new_node(jit_code_arg_f);
    else
	link_node(node);
    node->u.w = offset;
    node->v.w = ++_jitc->function->self.argn;
    jit_link_prolog();
    return (node);
}

static jit_node_t *
_jit_make_arg_d(jit_state_t *_jit, jit_node_t *node)
{
    jit_int32_t		 offset;
    if (jit_arg_reg_p(_jitc->function->self.argf)) {
	offset = (_jitc->function->self.argf + 1) & ~1;
	_jitc->function->self.argf = offset + 2;
	if (_jitc->function->self.call & jit_call_varargs)
	    offset += 8;
    }
    else {
	offset = _jitc->function->self.size;
	_jitc->function->self.size += STACK_SLOT;
    }
    if (node == (jit_node_t *)0)
	node = jit_new_node(jit_code_arg_d);
    else
	link_node(node);
    node->u.w = offset;
    node->v.w = ++_jitc->function->self.argn;
    jit_link_prolog();
    return (node);
}

jit_node_t *
_jit_arg(jit_state_t *_jit, jit_code_t code)
{
    assert(_jitc->function);
    assert(!(_jitc->function->self.call & jit_call_varargs));
    return (jit_make_arg((jit_node_t*)0, code));
}

void
_jit_getarg_c(jit_state_t *_jit, jit_int32_t u, jit_node_t *v)
{
    assert_arg_type(v->code, jit_code_arg_c);
    jit_inc_synth_wp(getarg_c, u, v);
    if (jit_arg_reg_p(v->u.w))
	jit_extr_c(u, JIT_RA0 + v->u.w);
    else
	jit_ldxi_c(u, JIT_FP, v->u.w + C_DISP);
    jit_dec_synth();
}

void
_jit_getarg_uc(jit_state_t *_jit, jit_int32_t u, jit_node_t *v)
{
    assert_arg_type(v->code, jit_code_arg_c);
    jit_inc_synth_wp(getarg_uc, u, v);
    if (jit_arg_reg_p(v->u.w))
	jit_extr_uc(u, JIT_RA0 + v->u.w);
    else
	jit_ldxi_uc(u, JIT_FP, v->u.w + C_DISP);
    jit_dec_synth();
}

void
_jit_getarg_s(jit_state_t *_jit, jit_int32_t u, jit_node_t *v)
{
    assert_arg_type(v->code, jit_code_arg_s);
    jit_inc_synth_wp(getarg_s, u, v);
    if (jit_arg_reg_p(v->u.w))
	jit_extr_s(u, JIT_RA0 + v->u.w);
    else
	jit_ldxi_s(u, JIT_FP, v->u.w + S_DISP);
    jit_dec_synth();
}

void
_jit_getarg_us(jit_state_t *_jit, jit_int32_t u, jit_node_t *v)
{
    assert_arg_type(v->code, jit_code_arg_s);
    jit_inc_synth_wp(getarg_us, u, v);
    if (jit_arg_reg_p(v->u.w))
	jit_extr_us(u, JIT_RA0 + v->u.w);
    else
	jit_ldxi_us(u, JIT_FP, v->u.w + S_DISP);
    jit_dec_synth();
}

void
_jit_getarg_i(jit_state_t *_jit, jit_int32_t u, jit_node_t *v)
{
    assert_arg_type(v->code, jit_code_arg_i);
    jit_inc_synth_wp(getarg_i, u, v);
    if (jit_arg_reg_p(v->u.w)) {
	jit_movr(u, JIT_RA0 + v->u.w);
    }
    else
	jit_ldxi_i(u, JIT_FP, v->u.w + I_DISP);
    jit_dec_synth();
}

void
_jit_pushargr(jit_state_t *_jit, jit_int32_t u, jit_code_t code)
{
    jit_code_inc_synth_w(code, u);
    jit_link_prepare();
    assert(_jitc->function);
    if (jit_arg_reg_p(_jitc->function->call.argi)) {
	jit_movr(JIT_RA0 + _jitc->function->call.argi, u);
	++_jitc->function->call.argi;
    }
    else {
	jit_stxi(_jitc->function->call.size + WORD_ADJUST, JIT_SP, u);
	_jitc->function->call.size += STACK_SLOT;
    }
    jit_dec_synth();
}

void
_jit_pushargi(jit_state_t *_jit, jit_word_t u, jit_code_t code)
{
    jit_int32_t		regno;
    assert(_jitc->function);
    jit_code_inc_synth_w(code, u);
    jit_link_prepare();
    if (jit_arg_reg_p(_jitc->function->call.argi)) {
	jit_movi(JIT_RA0 + _jitc->function->call.argi, u);
	++_jitc->function->call.argi;
    }
    else {
	regno = jit_get_reg(jit_class_gpr);
	jit_movi(regno, u);
	jit_stxi(_jitc->function->call.size + WORD_ADJUST, JIT_SP, regno);
	_jitc->function->call.size += STACK_SLOT;
	jit_unget_reg(regno);
    }
    jit_dec_synth();
}

void
_jit_finishr(jit_state_t *_jit, jit_int32_t r0)
{
    jit_node_t		*call;
    assert(_jitc->function);
    jit_inc_synth_w(finishr, r0);
    if (_jitc->function->self.alen < _jitc->function->call.size)
	_jitc->function->self.alen = _jitc->function->call.size;
    call = jit_callr(r0);
    call->v.w = _jitc->function->self.argi;
#if NEW_ABI
    call->w.w = call->v.w;
#else
    call->w.w = _jitc->function->self.argf;
#endif
    _jitc->function->call.argi = _jitc->function->call.argf =
	_jitc->function->call.size = 0;
    _jitc->prepare = 0;
    jit_dec_synth();
}

jit_node_t *
_jit_finishi(jit_state_t *_jit, jit_pointer_t i0)
{
    jit_node_t		*call;
    assert(_jitc->function);
    jit_inc_synth_w(finishi, (jit_word_t)i0);
    if (_jitc->function->self.alen < _jitc->function->call.size)
	_jitc->function->self.alen = _jitc->function->call.size;
    call = jit_calli(i0);
    call->v.w = _jitc->function->call.argi;
#if NEW_ABI
    call->w.w = call->v.w;
#else
    call->w.w = _jitc->function->call.argf;
#endif
    _jitc->function->call.argi = _jitc->function->call.argf =
	_jitc->function->call.size = 0;
    _jitc->prepare = 0;
    jit_dec_synth();
    return (call);
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
	jit_movr(r0, JIT_RET);
}

void
_jit_ellipsis(jit_state_t *_jit)
{
    jit_inc_synth(ellipsis);
    if (_jitc->prepare) {
	jit_link_prepare();
	assert(!(_jitc->function->call.call & jit_call_varargs));
	_jitc->function->call.call |= jit_call_varargs;
    }
    else {
	jit_link_prolog();
	assert(!(_jitc->function->self.call & jit_call_varargs));
	_jitc->function->self.call |= jit_call_varargs;
	_jitc->function->vagp = _jitc->function->self.argi;
    }
    jit_dec_synth();
}

void
_jit_va_push(jit_state_t *_jit, jit_int32_t u)
{
    jit_inc_synth_w(va_push, u);
    jit_pushargr(u);
    jit_dec_synth();
}

jit_bool_t
_jit_arg_register_p(jit_state_t *_jit, jit_node_t *u)
{
    if (u->code >= jit_code_arg_c && u->code <= jit_code_arg)
	return (jit_arg_reg_p(u->u.w));

    assert(u->code == jit_code_arg_f || u->code == jit_code_arg_d);
    return (jit_arg_reg_p(u->u.w));
}

jit_node_t *
_jit_arg_f(jit_state_t *_jit)
{
    assert(_jitc->function);
    return (jit_make_arg_f((jit_node_t*)0));
}

jit_node_t *
_jit_arg_d(jit_state_t *_jit)
{
    assert(_jitc->function);
    return (jit_make_arg_d((jit_node_t*)0));
}

void
_jit_retval_f(jit_state_t *_jit, jit_int32_t r0)
{
	jit_movr_f(r0, JIT_FRET);
}

void
_jit_retval_d(jit_state_t *_jit, jit_int32_t r0)
{
	jit_movr_d(r0, JIT_FRET);
}

void
_jit_retr_f(jit_state_t *_jit, jit_int32_t u)
{
	jit_inc_synth_w(retr_f, u);
	jit_movr_f(JIT_FRET, u);
	jit_live(JIT_FRET);
	jit_ret();
	jit_dec_synth();
}

void
_jit_reti_f(jit_state_t *_jit, jit_float32_t u)
{
	jit_inc_synth_w(reti_f, u);
	jit_movi_f(JIT_FRET, u);
	jit_live(JIT_FRET);
	jit_ret();
	jit_dec_synth();
}

void
_jit_retr_d(jit_state_t *_jit, jit_int32_t u)
{
	jit_inc_synth_w(retr_d, u);
	jit_movr_d(JIT_FRET, u);
	jit_live(JIT_FRET);
	jit_ret();
	jit_dec_synth();
}

void
_jit_reti_d(jit_state_t *_jit, jit_float64_t u)
{
	jit_inc_synth_w(reti_d, u);
	jit_movi_d(JIT_FRET, u);
	jit_live(JIT_FRET);
	jit_ret();
	jit_dec_synth();
}

void
_jit_pushargr_f(jit_state_t *_jit, jit_int32_t u)
{
	jit_int32_t regno;

	jit_inc_synth_w(pushargr_f, u);
	jit_link_prepare();
	assert(_jitc->function);
	if (jit_arg_reg_p(_jitc->function->call.argf)) {
		jit_movr_f(JIT_FA0 + (_jitc->function->call.argf ^ fpr_args_inverted()), u);
		++_jitc->function->call.argf;
	}
	else {
		jit_stxi_f(_jitc->function->call.size + WORD_ADJUST, JIT_SP, u);
		_jitc->function->call.size += STACK_SLOT;
	}
	jit_dec_synth();
}

void
_jit_pushargi_f(jit_state_t *_jit, jit_float32_t u)
{
	jit_int32_t regno;

	jit_inc_synth_w(pushargi_f, u);
	jit_link_prepare();
	assert(_jitc->function);
	if (jit_arg_reg_p(_jitc->function->call.argf)) {
		jit_movi_f(JIT_FA0 + (_jitc->function->call.argf ^ fpr_args_inverted()), u);
		++_jitc->function->call.argf;
	}
	else {
		regno = jit_get_reg(jit_class_fpr);
		jit_movi_f(regno, u);
		jit_stxi_f(_jitc->function->call.size + WORD_ADJUST, JIT_SP, regno);
		_jitc->function->call.size += STACK_SLOT;
		jit_unget_reg(regno);
	}
	jit_dec_synth();
}

void
_jit_pushargr_d(jit_state_t *_jit, jit_int32_t u)
{
	jit_int32_t regno;
	jit_inc_synth_w(pushargr_d, u);
	jit_link_prepare();
	assert(_jitc->function);

	regno = (_jitc->function->call.argf + 1) & ~1;
	if (jit_arg_reg_p(regno)) {
		jit_movr_d(JIT_FA0 + regno, u);
		_jitc->function->call.argf = regno + 2;
	}
	else {
		jit_stxi_d(_jitc->function->call.size + WORD_ADJUST, JIT_SP, u);
		_jitc->function->call.size += STACK_SLOT;
	}
	jit_dec_synth();
}

void
_jit_pushargi_d(jit_state_t *_jit, jit_float64_t u)
{
	jit_int32_t regno;

	jit_inc_synth_w(pushargi_d, u);
	jit_link_prepare();
	assert(_jitc->function);

	regno = (_jitc->function->call.argf + 1) & ~1;
	if (jit_arg_reg_p(regno)) {
		jit_movi_d(JIT_FA0 + regno, u);
		_jitc->function->call.argf = regno + 2;
	}
	else {
		regno = jit_get_reg(jit_class_fpr);
		jit_movi_d(regno, u);
		jit_stxi_d(_jitc->function->call.size + WORD_ADJUST, JIT_SP, regno);
		_jitc->function->call.size += STACK_SLOT;
		jit_unget_reg(regno);
	}
	jit_dec_synth();
}

void
_jit_putargr_f(jit_state_t *_jit, jit_int32_t u, jit_node_t *v)
{
	assert(v->code == jit_code_arg_f);
	jit_inc_synth_wp(putargr, u, v);
	if (jit_arg_reg_p(v->u.w))
		jit_movr_f(JIT_FA0 + (v->u.w ^ fpr_args_inverted()), u);
	else
		jit_stxi_f(v->u.w, JIT_FP, u);
	jit_dec_synth();
}

void
_jit_putargi_f(jit_state_t *_jit, jit_float32_t u, jit_node_t *v)
{
	jit_int32_t regno;

	assert(v->code == jit_code_arg_f);
	jit_inc_synth_wp(putargi, u, v);
	if (jit_arg_reg_p(v->u.w)) {
		jit_movi_f(JIT_FA0 + (v->u.w ^ fpr_args_inverted()), u);
	} else {
		regno = jit_get_reg(jit_class_fpr);

		jit_movi_f(regno, u);
		jit_stxi_f(v->u.w, JIT_FP, regno);

		jit_unget_reg(regno);
	}
	jit_dec_synth();
}

void
_jit_putargr_d(jit_state_t *_jit, jit_int32_t u, jit_node_t *v)
{
	assert(v->code == jit_code_arg_d);
	jit_inc_synth_wp(putargr, u, v);
	if (jit_arg_reg_p(v->u.w))
		jit_movr_d(JIT_FA0 + v->u.w, u);
	else
		jit_stxi_d(v->u.w, JIT_FP, u);
	jit_dec_synth();
}

void
_jit_putargi_d(jit_state_t *_jit, jit_float64_t u, jit_node_t *v)
{
	jit_int32_t regno;

	assert(v->code == jit_code_arg_d);
	jit_inc_synth_wp(putargi, u, v);
	if (jit_arg_reg_p(v->u.w)) {
		jit_movi_d(JIT_FA0 + v->u.w, u);
	} else {
		regno = jit_get_reg(jit_class_fpr);

		jit_movi_d(regno, u);
		jit_stxi_d(v->u.w, JIT_FP, regno);

		jit_unget_reg(regno);
	}
	jit_dec_synth();
}

void
_jit_getarg_d(jit_state_t *_jit, jit_int32_t u, jit_node_t *v)
{
    assert(v->code == jit_code_arg_d);
    jit_inc_synth_wp(getarg_d, u, v);

    if (jit_arg_reg_p(v->u.w))
	jit_movr_d(u, JIT_FA0 + v->u.w);
    else
	jit_ldxi_d(u, JIT_FP, v->u.w);

    jit_dec_synth();
}

void
_jit_getarg_f(jit_state_t *_jit, jit_int32_t u, jit_node_t *v)
{
    assert(v->code == jit_code_arg_f);
    jit_inc_synth_wp(getarg_f, u, v);

    if (jit_arg_reg_p(v->u.w))
	jit_movr_f(u, JIT_FA0 + (v->u.w ^ fpr_args_inverted()));
    else
	jit_ldxi_f(u, JIT_FP, v->u.w);

    jit_dec_synth();
}
