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

#if PROTO
struct jit_instr_ni {
#if __BYTE_ORDER == __LITTLE_ENDIAN
	jit_uint16_t i :8;
	jit_uint16_t n :4;
	jit_uint16_t c :4;
#else
	jit_uint16_t c :4;
	jit_uint16_t n :4;
	jit_uint16_t i :8;
#endif
};

struct jit_instr_nmd {
#if __BYTE_ORDER == __LITTLE_ENDIAN
	jit_uint16_t d :4;
	jit_uint16_t m :4;
	jit_uint16_t n :4;
	jit_uint16_t c :4;
#else
	jit_uint16_t c :4;
	jit_uint16_t n :4;
	jit_uint16_t m :4;
	jit_uint16_t d :4;
#endif
};

struct jit_instr_md {
#if __BYTE_ORDER == __LITTLE_ENDIAN
	jit_uint16_t d :4;
	jit_uint16_t m :4;
	jit_uint16_t c :8;
#else
	jit_uint16_t c :8;
	jit_uint16_t m :4;
	jit_uint16_t d :4;
#endif
};

struct jit_instr_d {
#if __BYTE_ORDER == __LITTLE_ENDIAN
	jit_uint16_t d :12;
	jit_uint16_t c :4;
#else
	jit_uint16_t c :4;
	jit_uint16_t d :12;
#endif
};

typedef union {
    struct jit_instr_ni ni;
    struct jit_instr_nmd nmd;
    struct jit_instr_md md;
    struct jit_instr_d d;
    jit_uint16_t op;
} jit_instr_t;

static void _cni(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
static void
_cnmd(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t,jit_uint16_t);
static void _cmd(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
static void _cd(jit_state_t*,jit_uint16_t,jit_uint16_t);

#    define STRB(rn, rm)		_cnmd(_jit, 0x0, rn, rm, 0x4)
#    define STRW(rn, rm)		_cnmd(_jit, 0x0, rn, rm, 0x5)
#    define STRL(rn, rm)		_cnmd(_jit, 0x0, rn, rm, 0x6)
#    define MULL(rn, rm)		_cnmd(_jit, 0x0, rn, rm, 0x7)
#    define LDRB(rn, rm)		_cnmd(_jit, 0x0, rn, rm, 0xc)
#    define LDRW(rn, rm)		_cnmd(_jit, 0x0, rn, rm, 0xd)
#    define LDRL(rn, rm)		_cnmd(_jit, 0x0, rn, rm, 0xe)
#    define BSRF(rn)			_cni(_jit, 0x0, rn, 0x03)
#    define STSH(rn)			_cni(_jit, 0x0, rn, 0x0a)
#    define STSL(rn)			_cni(_jit, 0x0, rn, 0x1a)
#    define BRAF(rn)			_cni(_jit, 0x0, rn, 0x23)
#    define MOVT(rn)			_cni(_jit, 0x0, rn, 0x29)

#    define STSPR(rn)			_cni(_jit, 0x0, rn, 0x2a)
#    define STSUL(rn)			_cni(_jit, 0x0, rn, 0x5a)
#    define STSFP(rn)			_cni(_jit, 0x0, rn, 0x6a)

#    define STDL(rn, rm, imm)		_cnmd(_jit, 0x1, rn, rm, imm)

#    define STB(rn, rm)			_cnmd(_jit, 0x2, rn, rm, 0x0)
#    define STW(rn, rm)			_cnmd(_jit, 0x2, rn, rm, 0x1)
#    define STL(rn, rm)			_cnmd(_jit, 0x2, rn, rm, 0x2)
#    define DIV0S(rn, rm)		_cnmd(_jit, 0x2, rn, rm, 0x7)
#    define TST(rn, rm)			_cnmd(_jit, 0x2, rn, rm, 0x8)
#    define AND(rn, rm)			_cnmd(_jit, 0x2, rn, rm, 0x9)
#    define XOR(rn, rm)			_cnmd(_jit, 0x2, rn, rm, 0xa)
#    define OR(rn, rm)			_cnmd(_jit, 0x2, rn, rm, 0xb)

#    define CMPEQ(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0x0)
#    define CMPHS(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0x2)
#    define CMPGE(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0x3)
#    define DIV1(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0x4)
#    define DMULU(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0x5)
#    define CMPHI(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0x6)
#    define CMPGT(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0x7)
#    define SUB(rn, rm)			_cnmd(_jit, 0x3, rn, rm, 0x8)
#    define SUBC(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0xa)
#    define SUBV(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0xb)
#    define ADD(rn, rm)			_cnmd(_jit, 0x3, rn, rm, 0xc)
#    define ADDC(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0xe)
#    define ADDV(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0xf)
#    define DMULS(rn, rm)		_cnmd(_jit, 0x3, rn, rm, 0xd)

#    define SHLL(rn)			_cni(_jit, 0x4, rn, 0x00)
#    define SHLR(rn)			_cni(_jit, 0x4, rn, 0x01)
#    define ROTL(rn)			_cni(_jit, 0x4, rn, 0x04)
#    define ROTR(rn)			_cni(_jit, 0x4, rn, 0x05)
#    define SHLL2(rn)			_cni(_jit, 0x4, rn, 0x08)
#    define SHLR2(rn)			_cni(_jit, 0x4, rn, 0x09)
#    define JSR(rn)			_cni(_jit, 0x4, rn, 0x0b)
#    define DT(rn)			_cni(_jit, 0x4, rn, 0x10)
#    define CMPPZ(rn)			_cni(_jit, 0x4, rn, 0x11)
#    define CMPPL(rn)			_cni(_jit, 0x4, rn, 0x15)
#    define SHLL8(rn)			_cni(_jit, 0x4, rn, 0x18)
#    define SHLR8(rn)			_cni(_jit, 0x4, rn, 0x19)
#    define SHAL(rn)			_cni(_jit, 0x4, rn, 0x20)
#    define SHAR(rn)			_cni(_jit, 0x4, rn, 0x21)
#    define ROTCL(rn)			_cni(_jit, 0x4, rn, 0x24)
#    define ROTCR(rn)			_cni(_jit, 0x4, rn, 0x25)
#    define SHLL16(rn)			_cni(_jit, 0x4, rn, 0x28)
#    define SHLR16(rn)			_cni(_jit, 0x4, rn, 0x29)
#    define LDSPR(rn)			_cni(_jit, 0x4, rn, 0x2a)
#    define JMP(rn)			_cni(_jit, 0x4, rn, 0x2b)
#    define LDS(rn)			_cni(_jit, 0x4, rn, 0x5a)
#    define LDSFP(rn)			_cni(_jit, 0x4, rn, 0x6a)
#    define SHAD(rn, rm)		_cnmd(_jit, 0x4, rn, rm, 0xc)
#    define SHLD(rn, rm)		_cnmd(_jit, 0x4, rn, rm, 0xd)

#    define LDDL(rn, rm, imm)		_cnmd(_jit, 0x5, rn, rm, imm)

#    define LDB(rn, rm)			_cnmd(_jit, 0x6, rn, rm, 0x0)
#    define LDW(rn, rm)			_cnmd(_jit, 0x6, rn, rm, 0x1)
#    define LDL(rn, rm)			_cnmd(_jit, 0x6, rn, rm, 0x2)
#    define MOV(rn, rm)			_cnmd(_jit, 0x6, rn, rm, 0x3)
#    define LDIB(rn, rm)		_cnmd(_jit, 0x6, rn, rm, 0x4)
#    define LDIW(rn, rm)		_cnmd(_jit, 0x6, rn, rm, 0x5)
#    define LDIL(rn, rm)		_cnmd(_jit, 0x6, rn, rm, 0x6)
#    define NOT(rn, rm)			_cnmd(_jit, 0x6, rn, rm, 0x7)
#    define SWAPB(rn, rm)		_cnmd(_jit, 0x6, rn, rm, 0x8)
#    define SWAPW(rn, rm)		_cnmd(_jit, 0x6, rn, rm, 0x9)
#    define NEGC(rn, rm)		_cnmd(_jit, 0x6, rn, rm, 0xa)
#    define NEG(rn, rm)			_cnmd(_jit, 0x6, rn, rm, 0xb)
#    define EXTUB(rn, rm)		_cnmd(_jit, 0x6, rn, rm, 0xc)
#    define EXTUW(rn, rm)		_cnmd(_jit, 0x6, rn, rm, 0xd)
#    define EXTSB(rn, rm)		_cnmd(_jit, 0x6, rn, rm, 0xe)
#    define EXTSW(rn, rm)		_cnmd(_jit, 0x6, rn, rm, 0xf)

#    define ADDI(rn, imm)		_cni(_jit, 0x7, rn, imm)

#    define LDDB(rm, imm)		_cnmd(_jit, 0x8, 0x4, rm, imm)
#    define LDDW(rm, imm)		_cnmd(_jit, 0x8, 0x5, rm, imm)
#    define CMPEQI(imm)			_cni(_jit, 0x8, 0x8, imm)
#    define BT(imm)			_cni(_jit, 0x8, 0x9, imm)
#    define BF(imm)			_cni(_jit, 0x8, 0xb, imm)
#    define BTS(imm)			_cni(_jit, 0x8, 0xd, imm)
#    define BFS(imm)			_cni(_jit, 0x8, 0xf, imm)

#    define LDPW(rn, imm)		_cni(_jit, 0x9, rn, imm)

#    define BRA(imm)			_cd(_jit, 0xa, imm)

#    define BSR(imm)			_cd(_jit, 0xb, imm)

#    define GBRLDB(imm)			_cni(_jit, 0xc, 0x4, imm)
#    define GBRLDW(imm)			_cni(_jit, 0xc, 0x5, imm)
#    define GBRLDL(imm)			_cni(_jit, 0xc, 0x6, imm)
#    define MOVA(imm)			_cni(_jit, 0xc, 0x7, imm)
#    define TSTI(imm)			_cni(_jit, 0xc, 0x8, imm)
#    define ANDI(imm)			_cni(_jit, 0xc, 0x9, imm)
#    define XORI(imm)			_cni(_jit, 0xc, 0xa, imm)
#    define ORI(imm)			_cni(_jit, 0xc, 0xb, imm)

#    define LDPL(rn, imm)		_cni(_jit, 0xd, rn, imm)

#    define MOVI(rn, imm)		_cni(_jit, 0xe, rn, imm)

#    define FADD(rn, rm)		_cnmd(_jit, 0xf, rn, rm, 0x0)
#    define FSUB(rn, rm)		_cnmd(_jit, 0xf, rn, rm, 0x1)
#    define FMUL(rn, rm)		_cnmd(_jit, 0xf, rn, rm, 0x2)
#    define FDIV(rn, rm)		_cnmd(_jit, 0xf, rn, rm, 0x3)
#    define FCMPEQ(rn,rm)		_cnmd(_jit, 0xf, rn, rm, 0x4)
#    define FCMPGT(rn,rm)		_cnmd(_jit, 0xf, rn, rm, 0x5)
#    define LDXF(rn, rm)		_cnmd(_jit, 0xf, rn, rm, 0x6)
#    define STXF(rn, rm)		_cnmd(_jit, 0xf, rn, rm, 0x7)
#    define LDF(rn, rm)			_cnmd(_jit, 0xf, rn, rm, 0x8)
#    define LDFS(rn, rm)		_cnmd(_jit, 0xf, rn, rm, 0x9)
#    define STF(rn, rm)			_cnmd(_jit, 0xf, rn, rm, 0xa)
#    define STFS(rn, rm)		_cnmd(_jit, 0xf, rn, rm, 0xb)
#    define FMOV(rn, rm)		_cnmd(_jit, 0xf, rn, rm, 0xc)
#    define FSTS(rn)			_cni(_jit, 0xf, rn, 0x0d)
#    define FLDS(rn)			_cni(_jit, 0xf, rn, 0x1d)
#    define FLOAT(rn)			_cni(_jit, 0xf, rn, 0x2d)
#    define FTRC(rn)			_cni(_jit, 0xf, rn, 0x3d)
#    define FNEG(rn)			_cni(_jit, 0xf, rn, 0x4d)
#    define FABS(rn)			_cni(_jit, 0xf, rn, 0x5d)
#    define FSQRT(rn)			_cni(_jit, 0xf, rn, 0x6d)
#    define FLDI0(rn)			_cni(_jit, 0xf, rn, 0x8d)
#    define FLDI1(rn)			_cni(_jit, 0xf, rn, 0x9d)
#    define FCNVSD(rn)			_cni(_jit, 0xf, rn, 0xad)
#    define FCNVDS(rn)			_cni(_jit, 0xf, rn, 0xbd)

#    define CLRT()			ii(0x8)
#    define NOP()			ii(0x9)
#    define RTS()			ii(0xb)
#    define DIV0U()			ii(0x19)
#    define FSCHG()			ii(0xf3fd)
#    define FRCHG()			ii(0xfbfd)

#    define ii(i)			*_jit->pc.us++ = i

#    define stack_framesize		(256)

static void _nop(jit_state_t*,jit_word_t);
#    define nop(i0)			_nop(_jit,i0)
static void _movr(jit_state_t*,jit_uint16_t,jit_uint16_t);
#    define movr(r0,r1)			_movr(_jit,r0,r1)
static void _movi(jit_state_t*,jit_uint16_t,jit_word_t);
#    define movi(r0,i0)			_movi(_jit,r0,i0)
static void _movnr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t,jit_bool_t);
#    define movnr(r0,r1,r2)		_movnr(_jit,r0,r1,r2,1)
#    define movzr(r0,r1,r2)		_movnr(_jit,r0,r1,r2,0)
static void _addr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define addr(r0,r1,r2)		_addr(_jit,r0,r1,r2)
static void _addcr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define addcr(r0,r1,r2)		_addcr(_jit,r0,r1,r2)
static void _addxr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define addxr(r0,r1,r2)		_addxr(_jit,r0,r1,r2)
static void _addi(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define addi(r0,r1,i0)		_addi(_jit,r0,r1,i0)
static void _addci(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define addci(r0,r1,i0)		_addci(_jit,r0,r1,i0)
static void _addxi(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define addxi(r0,r1,i0)		_addxi(_jit,r0,r1,i0)
static void _subr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define subr(r0,r1,r2)		_subr(_jit,r0,r1,r2)
static void _subcr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define subcr(r0,r1,r2)		_subcr(_jit,r0,r1,r2)
static void _subxr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define subxr(r0,r1,r2)		_subxr(_jit,r0,r1,r2)
static void _subi(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define subi(r0,r1,i0)		_subi(_jit,r0,r1,i0)
static void _subci(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define subci(r0,r1,i0)		_subci(_jit,r0,r1,i0)
static void _subxi(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define subxi(r0,r1,i0)		_subxi(_jit,r0,r1,i0)
static void _rsbi(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define rsbi(r0,r1,i0)		_rsbi(_jit,r0,r1,i0)
static void _mulr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define mulr(r0,r1,r2)		_mulr(_jit,r0,r1,r2)
static void _qmulr(jit_state_t*,jit_uint16_t,jit_uint16_t,
		   jit_uint16_t,jit_uint16_t);
#    define qmulr(r0,r1,r2,r3)		_qmulr(_jit,r0,r1,r2,r3)
static void _qmulr_u(jit_state_t*,jit_uint16_t,jit_uint16_t,
		     jit_uint16_t,jit_uint16_t);
#    define qmulr_u(r0,r1,r2,r3)	_qmulr_u(_jit,r0,r1,r2,r3)
static void _muli(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define muli(r0,r1,i0)		_muli(_jit,r0,r1,i0)
static void _qmuli(jit_state_t*,jit_uint16_t,jit_uint16_t,
		   jit_uint16_t,jit_word_t);
#    define qmuli(r0,r1,r2,i0)		_qmuli(_jit,r0,r1,r2,i0)
static void _qmuli_u(jit_state_t*,jit_uint16_t,jit_uint16_t,
		     jit_uint16_t,jit_word_t);
#    define qmuli_u(r0,r1,r2,i0)	_qmuli_u(_jit,r0,r1,r2,i0)
static void _divr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define divr(r0,r1,r2)		_divr(_jit,r0,r1,r2)
static void _divr_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define divr_u(r0,r1,r2)		_divr_u(_jit,r0,r1,r2)
static void _qdivr(jit_state_t*,jit_uint16_t,jit_uint16_t,
		   jit_uint16_t,jit_uint16_t);
#    define qdivr(r0,r1,r2,r3)		_qdivr(_jit,r0,r1,r2,r3)
static void _qdivr_u(jit_state_t*,jit_uint16_t,jit_uint16_t,
		     jit_uint16_t,jit_uint16_t);
#    define qdivr_u(r0,r1,r2,r3)	_qdivr_u(_jit,r0,r1,r2,r3)
static void _divi(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define divi(r0,r1,i0)		_divi(_jit,r0,r1,i0)
static void _divi_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define divi_u(r0,r1,i0)		_divi_u(_jit,r0,r1,i0)
static void _qdivi(jit_state_t*,jit_uint16_t,jit_uint16_t,
		   jit_uint16_t,jit_word_t);
#    define qdivi(r0,r1,r2,i0)		_qdivi(_jit,r0,r1,r2,i0)
static void _qdivi_u(jit_state_t*,jit_uint16_t,jit_uint16_t,
		     jit_uint16_t,jit_word_t);
#    define qdivi_u(r0,r1,r2,i0)	_qdivi_u(_jit,r0,r1,r2,i0)
static void _remr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define remr(r0,r1,r2)		_remr(_jit,r0,r1,r2)
static void _remr_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define remr_u(r0,r1,r2)		_remr_u(_jit,r0,r1,r2)
static void _remi(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define remi(r0,r1,i0)		_remi(_jit,r0,r1,i0)
static void _remi_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define remi_u(r0,r1,i0)		_remi_u(_jit,r0,r1,i0)
#    define bswapr_us(r0,r1)		_bswapr_us(_jit,r0,r1)
static void _bswapr_us(jit_state_t*,jit_uint16_t,jit_uint16_t);
#    define bswapr_ui(r0,r1)		_bswapr_ui(_jit,r0,r1)
static void _bswapr_ui(jit_state_t*,jit_uint16_t,jit_uint16_t);
#    define extr_c(r0, r1)		EXTSB(r0,r1)
#    define extr_s(r0,r1)		EXTSW(r0,r1)
#    define extr_uc(r0,r1)		EXTUB(r0,r1)
#    define extr_us(r0,r1)		EXTUW(r0,r1)
static void _andr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define andr(r0,r1,r2)		_andr(_jit,r0,r1,r2)
static void _andi(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define andi(r0,r1,i0)		_andi(_jit,r0,r1,i0)
static void _orr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define orr(r0,r1,r2)		_orr(_jit,r0,r1,r2)
static void _ori(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define ori(r0,r1,i0)		_ori(_jit,r0,r1,i0)
static void _xorr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define xorr(r0,r1,r2)		_xorr(_jit,r0,r1,r2)
static void _xori(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define xori(r0,r1,i0)		_xori(_jit,r0,r1,i0)
#    define comr(r0,r1)			NOT(r0,r1)
#    define negr(r0,r1)			NEG(r0,r1)
static void _gtr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define gtr(r0,r1,r2)		_gtr(_jit,r0,r1,r2)
static void _ger(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define ger(r0,r1,r2)		_ger(_jit,r0,r1,r2)
static void _gtr_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define gtr_u(r0,r1,r2)		_gtr_u(_jit,r0,r1,r2)
static void _ger_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define ger_u(r0,r1,r2)		_ger_u(_jit,r0,r1,r2)
#    define ltr(r0,r1,r2)		gtr(r0,r2,r1)
#    define ltr_u(r0,r1,r2)		gtr_u(r0,r2,r1)
#    define ler(r0,r1,r2)		ger(r0,r2,r1)
#    define ler_u(r0,r1,r2)		ger_u(r0,r2,r1)
static void _eqr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define eqr(r0,r1,r2)		_eqr(_jit,r0,r1,r2)
static void _ner(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define ner(r0,r1,r2)		_ner(_jit,r0,r1,r2)
static void _eqi(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define eqi(r0,r1,i0)		_eqi(_jit,r0,r1,i0)
static void _nei(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define nei(r0,r1,i0)		_nei(_jit,r0,r1,i0)
static void _gti(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define gti(r0,r1,i0)		_gti(_jit,r0,r1,i0)
static void _gei(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define gei(r0,r1,i0)		_gei(_jit,r0,r1,i0)
static void _gti_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define gti_u(r0,r1,i0)		_gti_u(_jit,r0,r1,i0)
static void _gei_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define gei_u(r0,r1,i0)		_gei_u(_jit,r0,r1,i0)
static void _lti(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define lti(r0,r1,i0)		_lti(_jit,r0,r1,i0)
static void _lei(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define lei(r0,r1,i0)		_lei(_jit,r0,r1,i0)
static void _lti_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define lti_u(r0,r1,i0)		_lti_u(_jit,r0,r1,i0)
static void _lei_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define lei_u(r0,r1,i0)		_lei_u(_jit,r0,r1,i0)
static void _lshr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define lshr(r0,r1,r2)		_lshr(_jit,r0,r1,r2)
static void _rshr(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define rshr(r0,r1,r2)		_rshr(_jit,r0,r1,r2)
static void _rshr_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define rshr_u(r0,r1,r2)		_rshr_u(_jit,r0,r1,r2)
static void _lshi(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define lshi(r0,r1,i0)		_lshi(_jit,r0,r1,i0)
static void _rshi(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define rshi(r0,r1,i0)		_rshi(_jit,r0,r1,i0)
static void _rshi_u(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define rshi_u(r0,r1,i0)		_rshi_u(_jit,r0,r1,i0)
#    define ldr_c(r0,r1)		LDB(r0,r1)
#    define ldr_s(r0,r1)		LDW(r0,r1)
#    define ldr_i(r0,r1)		LDL(r0,r1)
static void _ldr_uc(jit_state_t*,jit_uint16_t,jit_uint16_t);
#    define ldr_uc(r0,r1)		_ldr_uc(_jit,r0,r1)
static void _ldr_us(jit_state_t*,jit_uint16_t,jit_uint16_t);
#    define ldr_us(r0,r1)		_ldr_us(_jit,r0,r1)
static void _ldi_c(jit_state_t*,jit_uint16_t,jit_word_t);
#    define ldi_c(r0,i0)		_ldi_c(_jit,r0,i0)
static void _ldi_s(jit_state_t*,jit_uint16_t,jit_word_t);
#    define ldi_s(r0,i0)		_ldi_s(_jit,r0,i0)
static void _ldi_i(jit_state_t*,jit_uint16_t,jit_word_t);
#    define ldi_i(r0,i0)		_ldi_i(_jit,r0,i0)
static void _ldi_uc(jit_state_t*,jit_uint16_t,jit_word_t);
#    define ldi_uc(r0,i0)		_ldi_uc(_jit,r0,i0)
static void _ldi_us(jit_state_t*,jit_uint16_t,jit_word_t);
#    define ldi_us(r0,i0)		_ldi_us(_jit,r0,i0)
static void _ldxr_c(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define ldxr_c(r0,r1,r2)		_ldxr_c(_jit,r0,r1,r2)
static void _ldxr_s(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define ldxr_s(r0,r1,r2)		_ldxr_s(_jit,r0,r1,r2)
static void _ldxr_i(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define ldxr_i(r0,r1,r2)		_ldxr_i(_jit,r0,r1,r2)
static void _ldxr_uc(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define ldxr_uc(r0,r1,r2)		_ldxr_uc(_jit,r0,r1,r2)
static void _ldxr_us(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define ldxr_us(r0,r1,r2)		_ldxr_us(_jit,r0,r1,r2)
static void _ldxi_c(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define ldxi_c(r0,r1,i0)		_ldxi_c(_jit,r0,r1,i0)
static void _ldxi_s(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define ldxi_s(r0,r1,i0)		_ldxi_s(_jit,r0,r1,i0)
static void _ldxi_i(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define ldxi_i(r0,r1,i0)		_ldxi_i(_jit,r0,r1,i0)
static void _ldxi_uc(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define ldxi_uc(r0,r1,i0)		_ldxi_uc(_jit,r0,r1,i0)
static void _ldxi_us(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#    define ldxi_us(r0,r1,i0)		_ldxi_us(_jit,r0,r1,i0)
#    define str_c(r0,r1)		STB(r0,r1)
#    define str_s(r0,r1)		STW(r0,r1)
#    define str_i(r0,r1)		STL(r0,r1)
static void _sti_c(jit_state_t*,jit_word_t,jit_uint16_t);
#    define sti_c(i0,r0)		_sti_c(_jit,i0,r0)
static void _sti_s(jit_state_t*,jit_word_t,jit_uint16_t);
#    define sti_s(i0,r0)		_sti_s(_jit,i0,r0)
static void _sti_i(jit_state_t*,jit_word_t,jit_uint16_t);
#    define sti_i(i0,r0)		_sti_i(_jit,i0,r0)
static void _stxr_c(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define stxr_c(r0,r1,r2)		_stxr_c(_jit,r0,r1,r2)
static void _stxr_s(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define stxr_s(r0,r1,r2)		_stxr_s(_jit,r0,r1,r2)
static void _stxr_i(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#    define stxr_i(r0,r1,r2)		_stxr_i(_jit,r0,r1,r2)
static void _stxi_c(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t);
#    define stxi_c(i0,r0,r1)		_stxi_c(_jit,i0,r0,r1)
static void _stxi_s(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t);
#    define stxi_s(i0,r0,r1)		_stxi_s(_jit,i0,r0,r1)
static void _stxi_i(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t);
#    define stxi_i(i0,r0,r1)		_stxi_i(_jit,i0,r0,r1)
static jit_word_t _bger(jit_state_t*,jit_word_t,jit_uint16_t,
			jit_uint16_t,jit_bool_t);
#    define bltr(i0,r0,r1)		_bger(_jit,i0,r0,r1,0)
#    define bler(i0,r0,r1)		_bger(_jit,i0,r1,r0,1)
#    define bgtr(i0,r0,r1)		_bger(_jit,i0,r1,r0,0)
#    define bger(i0,r0,r1)		_bger(_jit,i0,r0,r1,1)
static jit_word_t _bger_u(jit_state_t*,jit_word_t,jit_uint16_t,
			  jit_uint16_t,jit_bool_t);
#    define bltr_u(i0,r0,r1)		_bger_u(_jit,i0,r0,r1,0)
#    define bler_u(i0,r0,r1)		_bger_u(_jit,i0,r1,r0,1)
#    define bgtr_u(i0,r0,r1)		_bger_u(_jit,i0,r1,r0,0)
#    define bger_u(i0,r0,r1)		_bger_u(_jit,i0,r0,r1,1)
static jit_word_t _beqr(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t);
#    define beqr(i0,r0,r1)		_beqr(_jit,i0,r0,r1)
static jit_word_t _bner(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t);
#    define bner(i0,r0,r1)		_bner(_jit,i0,r0,r1)
static jit_word_t _bmsr(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t);
#    define bmsr(i0,r0,r1)		_bmsr(_jit,i0,r0,r1)
static jit_word_t _bmcr(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t);
#    define bmcr(i0,r0,r1)		_bmcr(_jit,i0,r0,r1)
static jit_word_t _boaddr(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t,jit_bool_t);
#    define boaddr(i0,r0,r1)		_boaddr(_jit,i0,r0,r1,1)
#    define bxaddr(i0,r0,r1)		_boaddr(_jit,i0,r0,r1,0)
static jit_word_t _boaddr_u(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t,jit_bool_t);
#    define boaddr_u(i0,r0,r1)		_boaddr_u(_jit,i0,r0,r1,1)
#    define bxaddr_u(i0,r0,r1)		_boaddr_u(_jit,i0,r0,r1,0)
static jit_word_t _bosubr(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t,jit_bool_t);
#    define bosubr(i0,r0,r1)		_bosubr(_jit,i0,r0,r1,1)
#    define bxsubr(i0,r0,r1)		_bosubr(_jit,i0,r0,r1,0)
static jit_word_t _bosubr_u(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t,jit_bool_t);
#    define bosubr_u(i0,r0,r1)		_bosubr_u(_jit,i0,r0,r1,1)
#    define bxsubr_u(i0,r0,r1)		_bosubr_u(_jit,i0,r0,r1,0)
static jit_word_t _bgti(jit_state_t*,jit_word_t,jit_uint16_t,jit_word_t,jit_bool_t);
#    define blei(i0,r0,i1)		_bgti(_jit,i0,r0,i1,0)
#    define bgti(i0,r0,i1)		_bgti(_jit,i0,r0,i1,1)
static jit_word_t _bgei(jit_state_t*,jit_word_t,jit_uint16_t,jit_word_t,jit_bool_t);
#    define blti(i0,r0,i1)		_bgei(_jit,i0,r0,i1,0)
#    define bgei(i0,r0,i1)		_bgei(_jit,i0,r0,i1,1)
static jit_word_t _bgti_u(jit_state_t*,jit_word_t,jit_uint16_t,jit_word_t,jit_bool_t);
#    define blei_u(i0,r0,i1)		_bgti_u(_jit,i0,r0,i1,0)
#    define bgti_u(i0,r0,i1)		_bgti_u(_jit,i0,r0,i1,1)
static jit_word_t _bgei_u(jit_state_t*,jit_word_t,jit_uint16_t,jit_word_t,jit_bool_t);
#    define blti_u(i0,r0,i1)		_bgei_u(_jit,i0,r0,i1,0)
#    define bgei_u(i0,r0,i1)		_bgei_u(_jit,i0,r0,i1,1)
static jit_word_t _beqi(jit_state_t*,jit_word_t,jit_uint16_t,jit_word_t,jit_bool_t);
#    define beqi(i0,r0,i1)		_beqi(_jit,i0,r0,i1,1)
#    define bnei(i0,r0,i1)		_beqi(_jit,i0,r0,i1,0)
static jit_word_t _bmsi(jit_state_t*,jit_word_t,jit_uint16_t,jit_word_t,jit_bool_t);
#    define bmsi(i0,r0,i1)		_bmsi(_jit,i0,r0,i1,0)
#    define bmci(i0,r0,i1)		_bmsi(_jit,i0,r0,i1,1)
static jit_word_t _boaddi(jit_state_t*,jit_word_t,jit_uint16_t,jit_word_t,jit_bool_t);
#    define boaddi(i0,r0,i1)		_boaddi(_jit,i0,r0,i1,1)
#    define bxaddi(i0,r0,i1)		_boaddi(_jit,i0,r0,i1,0)
static jit_word_t _boaddi_u(jit_state_t*,jit_word_t,jit_uint16_t,jit_word_t,jit_bool_t);
#    define boaddi_u(i0,r0,i1)		_boaddi_u(_jit,i0,r0,i1,1)
#    define bxaddi_u(i0,r0,i1)		_boaddi_u(_jit,i0,r0,i1,0)
static jit_word_t _bosubi(jit_state_t*,jit_word_t,jit_uint16_t,jit_word_t,jit_bool_t);
#    define bosubi(i0,r0,i1)		_bosubi(_jit,i0,r0,i1,1)
#    define bxsubi(i0,r0,i1)		_bosubi(_jit,i0,r0,i1,0)
static jit_word_t _bosubi_u(jit_state_t*,jit_word_t,jit_uint16_t,jit_word_t,jit_bool_t);
#    define bosubi_u(i0,r0,i1)		_bosubi_u(_jit,i0,r0,i1,1)
#    define bxsubi_u(i0,r0,i1)		_bosubi_u(_jit,i0,r0,i1,0)
static void _jmpr(jit_state_t*,jit_int16_t);
#  define jmpr(r0)			_jmpr(_jit,r0)
static jit_word_t _jmpi(jit_state_t*,jit_word_t);
#  define jmpi(i0)			_jmpi(_jit,i0)
static void _callr(jit_state_t*,jit_int16_t);
#  define callr(r0)			_callr(_jit,r0)
static void _calli(jit_state_t*,jit_word_t);
#  define calli(i0)			_calli(_jit,i0)

static jit_word_t _movi_p(jit_state_t*,jit_uint16_t,jit_word_t);
#    define movi_p(r0,i0)		_movi_p(_jit,r0,i0)
static jit_word_t _jmpi_p(jit_state_t*,jit_word_t);
#  define jmpi_p(i0)			_jmpi_p(_jit,i0)
static jit_word_t _calli_p(jit_state_t*,jit_word_t);
#  define calli_p(i0)			_calli_p(_jit,i0)
static void _patch_abs(jit_state_t*,jit_word_t,jit_word_t);
#    define patch_abs(instr,label)	_patch_abs(_jit,instr,label)
static void _patch_at(jit_state_t*,jit_word_t,jit_word_t);
#    define patch_at(jump,label)	_patch_at(_jit,jump,label)
static void _prolog(jit_state_t*,jit_node_t*);
#  define prolog(node)			_prolog(_jit,node)
static void _epilog(jit_state_t*,jit_node_t*);
#  define epilog(node)			_epilog(_jit,node)

#    define ldr(r0,r1)			ldr_i(r0,r1)
#    define ldi(r0,i0)			ldi_i(r0,i0)
#    define ldxr(r0,r1,r2)		ldxr_i(r0,r1,r2)
#    define ldxi(r0,r1,i0)		ldxi_i(r0,r1,i0)
#    define str(r0,r1)			str_i(r0,r1)
#    define sti(i0,r0)			sti_i(i0,r0)
#    define stxr(r0,r1,r2)		stxr_i(r0,r1,r2)
#    define stxi(i0,r0,r1)		stxi_i(i0,r0,r1)

#  define is_low_mask(im)		(((im) & 1) ? (__builtin_popcountl((im) + 1) <= 1) : 0)
#  define is_middle_mask(im)		((im) ? (__builtin_popcountl((im) + (1 << __builtin_ctzl(im))) <= 1) : 0)
#  define is_high_mask(im)		((im) ? (__builtin_popcountl((im) + (1 << __builtin_ctzl(im))) == 0) : 0)
#  define masked_bits_count(im)		__builtin_popcountl(im)
#  define unmasked_bits_count(im)	(__WORDSIZE - masked_bits_count(im))
#endif /* PROTO */

#if CODE
static void
_cni(jit_state_t *_jit, jit_uint16_t c, jit_uint16_t n, jit_uint16_t i)
{
	jit_instr_t op;

	op.ni = (struct jit_instr_ni){ .c = c, .n = n, .i = i };

	ii(op.op);
}

static void
_cnmd(jit_state_t *_jit, jit_uint16_t c, jit_uint16_t n,
      jit_uint16_t m, jit_uint16_t d)
{
	jit_instr_t op;

	op.nmd = (struct jit_instr_nmd){ .c = c, .n = n, .m = m, .d = d };

	ii(op.op);
}

static void
_cmd(jit_state_t *_jit, jit_uint16_t c, jit_uint16_t m, jit_uint16_t d)
{
	jit_instr_t op;

	op.md = (struct jit_instr_md){ .c = c, .m = m, .d = d };

	ii(op.op);
}

static void
_cd(jit_state_t *_jit, jit_uint16_t c, jit_uint16_t d)
{
	jit_instr_t op;

	op.d = (struct jit_instr_d){ .c = c, .d = d };

	ii(op.op);
}

static void
_nop(jit_state_t *_jit, jit_word_t i0)
{
	for (; i0 > 0; i0 -= 2)
		NOP();
	assert(i0 == 0);
}

static void
_movr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	if (r0 != r1)
		MOV(r0, r1);
}

static void
movi_loop(jit_state_t *_jit, jit_uint16_t r0, jit_word_t i0)
{
	jit_word_t tmp;

	if (i0 >= -128 && i0 < 128) {
		MOVI(r0, i0);
	} else {
		tmp = (i0 >> 8) + !!(i0 & 0x80);
		if (tmp & 0xff) {
			movi_loop(_jit, r0, tmp);
			if (tmp != 0)
				SHLL8(r0);
		} else {
			tmp = (i0 >> 16) + !!(i0 & 0x80);
			movi_loop(_jit, r0, tmp);
			if (tmp != 0)
				SHLL16(r0);
		}
		if (i0 & 0xff)
			ADDI(r0, i0 & 0xff);
	}
}

static void
_movi(jit_state_t *_jit, jit_uint16_t r0, jit_word_t i0)
{
	jit_word_t w = _jit->pc.w & ~3;

	if (i0 >= -128 && i0 < 128) {
		MOVI(r0, i0);
	} else if (i0 >= w && i0 <= w + 0x3ff && !((i0 - w) & 0x3)) {
		MOVA((i0 - w) >> 2);
		movr(r0, _R0);
	} else if (is_low_mask(i0)) {
		MOVI(r0, -1);
		rshi_u(r0, r0, unmasked_bits_count(i0));
	} else if (is_high_mask(i0)) {
		MOVI(r0, -1);
		lshi(r0, r0, unmasked_bits_count(i0));
	} else {
		movi_loop(_jit, r0, i0);
	}
}

static void
emit_branch_opcode(jit_state_t *_jit, jit_word_t i0, jit_word_t w, int t_set)
{
	jit_int32_t disp = (i0 - w >> 1) - 2;

	if (disp >= -2048 && disp <= 2046) {
#if defined(__SH3__) || defined(__SH4__)
		if (t_set)
			BT((i0 - w >> 1) - 2);
		else
			BF((i0 - w >> 1) - 2);
#else
		/* BT/BF are buggy on SH2 - revert to using BTS/BFS */
		if (t_set)
			BTS((i0 - w >> 1) - 2);
		else
			BFS((i0 - w >> 1) - 2);
		NOP();
#endif
	} else {
		movi_p(_R0, i0);
		if (t_set)
			BF(1);
		else
			BT(1);
		JMP(_R0);
		NOP();
	}
}

static void _movnr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
		   jit_uint16_t r2, jit_bool_t set)
{
	TST(r2, r2);
	emit_branch_opcode(_jit, 4, 0, set);
	movr(r0, r1);
}

static void
_addr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	if (r0 == r2) {
		ADD(r0, r1);
	} else {
		movr(r0, r1);
		ADD(r0, r2);
	}
}

static void
_addcr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	CLRT();
	addxr(r0, r1, r2);
}

static void
_addxr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	if (r0 == r2) {
		ADDC(r0, r1);
	} else {
		movr(r0, r1);
		ADDC(r0, r2);
	}
}

static void
_addi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	if (i0 >= -128 && i0 < 127) {
		movr(r0, r1);
		ADDI(r0, i0);
	} else if (r0 != r1) {
		movi(r0, i0);
		addr(r0, r1, r0);
	} else {
		assert(r1 != _R0);

		movi(_R0, i0);
		addr(r0, r1, _R0);
	}
}

static void
_addci(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	CLRT();
	addxi(r0, r1, i0);
}

static void
_addxi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r0 != _R0 && r1 != _R0);

	movi(_R0, i0);
	addxr(r0, r1, _R0);
}

static void
_subr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	if (r1 == r2) {
		movi(r0, 0);
	} else if (r0 == r2) {
		NEG(r0, r2);
		ADD(r0, r1);
	} else {
		movr(r0, r1);
		SUB(r0, r2);
	}
}

static void
_subcr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	CLRT();
	subxr(r0, r1, r2);
}

static void
_subxr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	jit_uint32_t reg;

	if (r0 != r2) {
		movr(r0, r1);
		SUBC(r0, r2);
	} else {
		reg = jit_get_reg(jit_class_gpr);

		movr(rn(reg), r0);
		movr(r0, r1);
		SUBC(r0, rn(reg));

		jit_unget_reg(reg);
	}
}

static void
_subi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	addi(r0, r1, -i0);
}

static void
_subci(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r0 != _R0 && r1 != _R0);

	movi(_R0, i0);
	subcr(r0, r1, _R0);
}

static void
_subxi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r0 != _R0 && r1 != _R0);

	movi(_R0, i0);
	subxr(r0, r1, _R0);
}

static void
_rsbi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	if (!(i0 & ~0xff)) {
		negr(r0, r1);
		ADDI(r0, i0);
	} else if (r0 != r1) {
		assert(r0 != _R0 && r1 != _R0);

		movi(r0, i0);
		subr(r0, r0, r1);
	} else {
		assert(r0 != _R0);

		movi(_R0, i0);
		subr(r0, _R0, r1);
	}
}

static void
_mulr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	MULL(r1, r2);
	STSL(r0);
}

static void
_qmulr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
       jit_uint16_t r2, jit_uint16_t r3)
{
	DMULS(r2, r3);
	STSL(r0);
	STSH(r1);
}

static void
_qmulr_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
	 jit_uint16_t r2, jit_uint16_t r3)
{
	DMULU(r2, r3);
	STSL(r0);
	STSH(r1);
}

static void
_muli(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	movi(_R0, i0);
	mulr(r0, r1, _R0);
}

static void
_qmuli(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
       jit_uint16_t r2, jit_word_t i0)
{
	assert(r2 != _R0);

	movi(_R0, i0);
	qmulr(r0, r1, r2, _R0);
}

static void
_qmuli_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
	 jit_uint16_t r2, jit_word_t i0)
{
	assert(r2 != _R0);

	movi(_R0, i0);
	qmulr_u(r0, r1, r2, _R0);
}

static void
_divr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	jit_uint32_t reg, reg2;
	jit_uint16_t divisor;

	assert(r1 != _R0 && r2 != _R0);

	if (r1 == r2) {
		MOVI(r0, 1);
	} else {
		reg = jit_get_reg(jit_class_gpr);

		if (r0 == r2) {
			reg2 = jit_get_reg(jit_class_gpr);
			movr(rn(reg2), r2);
			divisor = rn(reg2);
		} else {
			divisor = r2;
		}

		movr(r0, r1);
		MOVI(_R0, 0);

		CMPGT(_R0, r0);
		SUBC(rn(reg), rn(reg));
		SUBC(r0, _R0);

		MOVI(_R0, -2);
		DIV0S(rn(reg), divisor);

		ROTCL(r0);
		DIV1(rn(reg), divisor);
		ROTCL(_R0);
		XORI(1);
		BTS(-6);
		TSTI(1);

		ROTCL(r0);
		MOVI(_R0, 0);
		ADDC(r0, _R0);

		jit_unget_reg(reg);
		if (r0 == r2)
			jit_unget_reg(reg2);
	}
}

static void
_divr_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	jit_uint32_t reg, reg2;
	jit_uint16_t divisor;

	assert(r1 != _R0 && r2 != _R0);

	if (r1 == r2) {
		MOVI(r0, 1);
	} else {
		reg = jit_get_reg(jit_class_gpr);

		if (r0 == r2) {
			reg2 = jit_get_reg(jit_class_gpr);
			movr(rn(reg2), r2);
			divisor = rn(reg2);
		} else {
			divisor = r2;
		}

		movr(r0, r1);
		MOVI(rn(reg), 0);
		MOVI(_R0, -2);
		DIV0U();

		ROTCL(r0);
		DIV1(rn(reg), divisor);
		ROTCL(_R0);
		XORI(1);
		BTS(-6);
		TSTI(1);

		ROTCL(r0);

		jit_unget_reg(reg);
		if (r0 == r2)
			jit_unget_reg(reg2);
	}
}

static void
_qdivr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
       jit_uint16_t r2, jit_uint16_t r3)
{
	jit_uint32_t reg;

	assert(r2 != _R0 && r3 != _R0);

	if (r0 != r2 && r0 != r3) {
		divr(r0, r2, r3);
		mulr(_R0, r0, r3);
		subr(r1, r2, _R0);
	} else {
		reg = jit_get_reg(jit_class_gpr);

		divr(rn(reg), r2, r3);
		mulr(_R0, rn(reg), r3);
		subr(r1, r2, _R0);
		movr(r0, rn(reg));

		jit_unget_reg(reg);
	}
}

static void
_qdivr_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
	 jit_uint16_t r2, jit_uint16_t r3)
{
	jit_uint32_t reg;

	assert(r2 != _R0 && r3 != _R0);

	if (r0 != r2 && r0 != r3) {
		divr_u(r0, r2, r3);
		mulr(_R0, r0, r3);
		subr(r1, r2, _R0);
	} else {
		reg = jit_get_reg(jit_class_gpr);

		divr_u(rn(reg), r2, r3);
		mulr(_R0, rn(reg), r3);
		subr(r1, r2, _R0);
		movr(r0, rn(reg));

		jit_unget_reg(reg);
	}
}

static void
_divi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	jit_uint32_t reg = jit_get_reg(jit_class_gpr);

	movi(rn(reg), i0);
	divr(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_divi_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	jit_uint32_t reg = jit_get_reg(jit_class_gpr);

	movi(rn(reg), i0);
	divr_u(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_qdivi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
       jit_uint16_t r2, jit_word_t i0)
{
	jit_uint32_t reg = jit_get_reg(jit_class_gpr);

	movi(rn(reg), i0);
	qdivr(r0, r1, r2, rn(reg));

	jit_unget_reg(reg);
}

static void
_qdivi_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
	 jit_uint16_t r2, jit_word_t i0)
{
	jit_uint32_t reg = jit_get_reg(jit_class_gpr);

	movi(rn(reg), i0);
	qdivr_u(r0, r1, r2, rn(reg));

	jit_unget_reg(reg);
}

static void
_remr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	jit_uint32_t reg = jit_get_reg(jit_class_gpr);

	assert(r1 != _R0 && r2 != _R0);

	qdivr(rn(reg), r0, r1, r2);

	jit_unget_reg(reg);
}

static void
_remr_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	jit_uint32_t reg = jit_get_reg(jit_class_gpr);

	assert(r1 != _R0 && r2 != _R0);

	qdivr_u(rn(reg), r0, r1, r2);

	jit_unget_reg(reg);
}

static void
_remi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	jit_uint32_t reg = jit_get_reg(jit_class_gpr);

	movi(rn(reg), i0);
	remr(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_remi_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	jit_uint32_t reg = jit_get_reg(jit_class_gpr);

	movi(rn(reg), i0);
	remr_u(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_bswapr_us(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	EXTUW(r0, r1);
	SWAPB(r0, r0);
}

static void
_bswapr_ui(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	SWAPB(r0, r1);
	SWAPW(r0, r0);
	SWAPB(r0, r0);
}

static void
_andr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	if (r0 == r2) {
		AND(r0, r1);
	} else {
		movr(r0, r1);
		AND(r0, r2);
	}
}

static void
_andi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	if (i0 == 0xff) {
		extr_uc(r0, r1);
	} else if (i0 == 0xffff) {
		extr_us(r0, r1);
	} else {
		assert(r0 != _R0 && r1 != _R0);

		movi(_R0, i0);
		movr(r0, r1);
		AND(r0, _R0);
	}
}

static void
_orr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	if (r0 == r2) {
		OR(r0, r1);
	} else {
		movr(r0, r1);
		OR(r0, r2);
	}
}

static void
_ori(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r0 != _R0 && r1 != _R0);

	movi(_R0, i0);
	movr(r0, r1);
	OR(r0, _R0);
}

static void
_xorr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	if (r0 == r2) {
		XOR(r0, r1);
	} else {
		movr(r0, r1);
		XOR(r0, r2);
	}
}

static void
_xori(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r0 != _R0 && r1 != _R0);

	movi(_R0, i0);
	movr(r0, r1);
	XOR(r0, _R0);
}

static void
_gtr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	CMPGT(r1, r2);
	MOVT(r0);
}

static void
_gtr_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	CMPHI(r1, r2);
	MOVT(r0);
}

static void
_ger(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	CMPGE(r1, r2);
	MOVT(r0);
}

static void
_ger_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	CMPHS(r1, r2);
	MOVT(r0);
}

static void
_eqr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	CMPEQ(r1, r2);
	MOVT(r0);
}

static void
_ner(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	assert(r1 != _R0 && r2 != _R0);

	MOVI(_R0, -1);
	CMPEQ(r1, r2);
	NEGC(r0, _R0);
}

static void
_eqi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	if (i0 == 0) {
		TST(r1, r1);
	} else if (i0 >= -128 && i0 < 128) {
		assert(r1 != _R0);

		movr(_R0, r1);
		CMPEQI(i0);
	} else {
		assert(r1 != _R0);

		movi(_R0, i0);
		CMPEQ(r1, _R0);
	}
	MOVT(r0);
}

static void
_nei(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r0 != _R0 && r1 != _R0);

	if (i0 == 0) {
		TST(r1, r1);
	} else if (i0 >= -128 && i0 < 128) {
		movr(_R0, r1);
		CMPEQI(i0);
	} else {
		movi(_R0, i0);
		CMPEQ(r1, _R0);
	}

	MOVI(_R0, -1);
	NEGC(r0, _R0);
}

static void
_gti(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	if (i0 == 0) {
		CMPPL(r1);
	} else {
		assert(r1 != _R0);

		movi(_R0, i0);
		CMPGT(r1, _R0);
	}
	MOVT(r0);
}

static void
_gei(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	if (i0 == 0) {
		CMPPZ(r1);
	} else {
		assert(r1 != _R0);

		movi(_R0, i0);
		CMPGE(r1, _R0);
	}
	MOVT(r0);
}

static void
_gti_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	movi(_R0, i0);
	CMPHI(r1, _R0);
	MOVT(r0);
}

static void
_gei_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	movi(_R0, i0);
	CMPHS(r1, _R0);
	MOVT(r0);
}

static void
_lti(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	movi(_R0, i0);
	CMPGT(_R0, r1);
	MOVT(r0);
}

static void
_lei(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	movi(_R0, i0);
	CMPGE(_R0, r1);
	MOVT(r0);
}

static void
_lti_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	movi(_R0, i0);
	CMPHI(_R0, r1);
	MOVT(r0);
}

static void
_lei_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	movi(_R0, i0);
	CMPHS(_R0, r1);
	MOVT(r0);
}

static void
emit_shllr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
#if defined(__SH3__) || defined(__SH4__)
	SHLD(r0, r1);
#else
	movr(_R0, r1);
	DT(_R0);
	BFS(-3);
	SHLL(r0);
#endif
}

static void
_lshr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	if (r0 == r2) {
		assert(r1 != _R0);

		movr(_R0, r2);
		movr(r0, r1);
		emit_shllr(_jit, r0, _R0);
	} else {
		movr(r0, r1);
		emit_shllr(_jit, r0, r2);
	}
}

static void
_rshr(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	assert(r0 != _R0 && r1 != _R0);

#if defined(__SH3__) || defined(__SH4__)
	negr(_R0, r2);
	movr(r0, r1);
	SHAD(r0, _R0);
#else
	movr(_R0, r2);
	movr(r0, r1);
	DT(_R0);
	BFS(-3);
	SHAR(r0);
#endif
}

static void
_rshr_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	assert(r0 != _R0 && r1 != _R0);

#if defined(__SH3__) || defined(__SH4__)
	negr(_R0, r2);
	movr(r0, r1);
	SHLD(r0, _R0);
#else
	movr(_R0, r2);
	movr(r0, r1);
	DT(_R0);
	BFS(-3);
	SHLR(r0);
#endif
}

static void
_lshi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	jit_uint32_t reg;

	movr(r0, r1);

	if (i0 == 16) {
		SHLL16(r0);
	} else if (i0 == 8) {
		SHLL8(r0);
	} else if (i0 == 2) {
		SHLL2(r0);
	} else if (i0 == 1) {
		SHLL(r0);
	} else {
		reg = r0 != _R0 ? _R0 : jit_get_reg(jit_class_gpr);

		movi(rn(reg), i0);
		lshr(r0, r0, rn(reg));

		if (r0 == _R0)
			jit_unget_reg(reg);
	}
}

static void
_rshi(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	jit_uint32_t reg;

	reg = r0 != _R0 ? _R0 : jit_get_reg(jit_class_gpr);

	movr(r0, r1);
#if defined(__SH3__) || defined(__SH4__)
	movi(rn(reg), -i0);
	SHAD(r0, rn(reg));
#else
	movi(rn(reg), i0);
	DT(rn(reg));
	BFS(-3);
	SHAR(r0);
#endif

	if (r0 == _R0)
		jit_unget_reg(reg);
}

static void
_rshi_u(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	jit_uint32_t reg;

	movr(r0, r1);

	if (i0 == 16) {
		SHLR16(r0);
	} else if (i0 == 8) {
		SHLR8(r0);
	} else if (i0 == 2) {
		SHLR2(r0);
	} else if (i0 == 1) {
		SHLR(r0);
	} else {
		reg = r0 != _R0 ? _R0 : jit_get_reg(jit_class_gpr);

#if defined(__SH3__) || defined(__SH4__)
		movi(rn(reg), -i0);
		SHLD(r0, rn(reg));
#else
		movi(rn(reg), i0);
		DT(rn(reg));
		BFS(-3);
		SHLR(r0);
#endif

		if (r0 == _R0)
			jit_unget_reg(reg);
	}
}

static void _ldr_uc(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	ldr_c(r0, r1);
	extr_uc(r0, r0);
}

static void _ldr_us(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	ldr_s(r0, r1);
	extr_us(r0, r0);
}

static void _ldi_c(jit_state_t *_jit, jit_uint16_t r0, jit_word_t i0)
{
	movi(_R0, i0);
	ldr_c(r0, _R0);
}

static void _ldi_s(jit_state_t *_jit, jit_uint16_t r0, jit_word_t i0)
{
	movi(_R0, i0);
	ldr_s(r0, _R0);
}

static void _ldi_i(jit_state_t *_jit, jit_uint16_t r0, jit_word_t i0)
{
	movi(_R0, i0);
	ldr_i(r0, _R0);
}

static void _ldi_uc(jit_state_t *_jit, jit_uint16_t r0, jit_word_t i0)
{
	movi(_R0, i0);
	ldr_uc(r0, _R0);
}

static void _ldi_us(jit_state_t *_jit, jit_uint16_t r0, jit_word_t i0)
{
	movi(_R0, i0);
	ldr_us(r0, _R0);
}

static void
_ldxr_c(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	assert(r1 != _R0);

	movr(_R0, r2);
	LDRB(r0, r1);
}

static void
_ldxr_s(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	assert(r1 != _R0);

	movr(_R0, r2);
	LDRW(r0, r1);
}

static void
_ldxr_i(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	assert(r1 != _R0);

	movr(_R0, r2);
	LDRL(r0, r1);
}

static void
_ldxr_uc(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	ldxr_c(r0, r1, r2);
	extr_uc(r0, r0);
}

static void
_ldxr_us(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	ldxr_s(r0, r1, r2);
	extr_us(r0, r0);
}

static void
_ldxi_c(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	if (i0 >= 0 && i0 <= 0xf) {
		LDDB(r1, i0);
		movr(r0, _R0);
	} else {
		movi(_R0, i0);
		ldxr_c(r0, r1, _R0);
	}
}

static void
_ldxi_s(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	if (i0 >= 0 && i0 <= 0x1f && !(i0 & 0x1)) {
		LDDW(r1, i0 >> 1);
		movr(r0, _R0);
	} else {
		movi(_R0, i0);
		ldxr_s(r0, r1, _R0);
	}
}

static void
_ldxi_i(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	if (i0 >= 0 && i0 <= 0x3f && !(i0 & 3)) {
		LDDL(r0, r1, i0 >> 2);
	} else {
		movi(_R0, i0);
		ldxr_i(r0, r1, _R0);
	}
}

static void
_ldxi_uc(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	ldxi_c(_R0, r1, i0);
	extr_uc(r0, _R0);
}

static void
_ldxi_us(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_word_t i0)
{
	assert(r1 != _R0);

	ldxi_s(_R0, r1, i0);
	extr_us(r0, _R0);
}

static void _sti_c(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0)
{
	assert(r0 != _R0);

	movi(_R0, i0);
	str_c(_R0, r0);
}

static void _sti_s(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0)
{
	assert(r0 != _R0);

	movi(_R0, i0);
	str_s(_R0, r0);
}

static void _sti_i(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0)
{
	assert(r0 != _R0);

	movi(_R0, i0);
	str_i(_R0, r0);
}

static void
_stxr_c(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	assert(r1 != _R0 && r2 != _R0);

	movr(_R0, r0);
	STRB(r1, r2);
}

static void
_stxr_s(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	assert(r1 != _R0 && r2 != _R0);

	movr(_R0, r0);
	STRW(r1, r2);
}

static void
_stxr_i(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	assert(r1 != _R0 && r2 != _R0);

	movr(_R0, r0);
	STRL(r1, r2);
}

static void
_stxi_c(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0, jit_uint16_t r1)
{
	assert(r0 != _R0 && r1 != _R0);

	movi(_R0, i0);
	stxr_c(_R0, r0, r1);
}

static void
_stxi_s(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0, jit_uint16_t r1)
{
	assert(r0 != _R0 && r1 != _R0);

	movi(_R0, i0);
	stxr_s(_R0, r0, r1);
}

static void
_stxi_i(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0, jit_uint16_t r1)
{
	if (i0 >= 0 && i0 <= 0x3f && !(i0 & 3)) {
		STDL(r0, r1, i0 >> 2);
	} else {
		assert(r0 != _R0 && r1 != _R0);

		movi(_R0, i0);
		stxr_i(_R0, r0, r1);
	}
}

static jit_word_t
_bger(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
      jit_uint16_t r1, jit_bool_t t)
{
	jit_word_t w;

	CMPGE(r0, r1);
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, t);

	return (w);
}

static jit_word_t
_bler(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0, jit_uint16_t r1)
{
	jit_word_t w;

	CMPGT(r0, r1);
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, 0);

	return (w);
}

static jit_word_t
_bgtr(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0, jit_uint16_t r1)
{
	jit_word_t w;

	CMPGT(r0, r1);
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, 1);

	return (w);
}

static jit_word_t
_bger_u(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
	jit_uint16_t r1, jit_bool_t t)
{
	jit_word_t w;

	CMPHS(r0, r1);
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, t);

	return (w);
}

static jit_word_t
_beqr(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0, jit_uint16_t r1)
{
	jit_word_t w;

	if (r0 == r1) {
		w = jmpi(i0);
	} else {
		CMPEQ(r0, r1);
		w = _jit->pc.w;
		emit_branch_opcode(_jit, i0, w, 1);
	}

	return (w);
}

static jit_word_t
_bner(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0, jit_uint16_t r1)
{
	jit_word_t w;

	CMPEQ(r0, r1);
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, 0);

	return (w);
}

static jit_word_t
_bmsr(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0, jit_uint16_t r1)
{
	jit_word_t w;

	TST(r0, r1);
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, 0);

	return (w);
}

static jit_word_t
_bmcr(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0, jit_uint16_t r1)
{
	jit_word_t w;

	TST(r0, r1);
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, 1);

	return (w);
}

static jit_word_t
_bgti(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
      jit_word_t i1, jit_bool_t set)
{
	jit_word_t w;

	if (i1 == 0) {
		CMPPL(r0);
	} else {
		assert(r0 != _R0);

		movi(_R0, i1);
		CMPGT(r0, _R0);
	}
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t
_bgei(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
      jit_word_t i1, jit_bool_t set)
{
	jit_word_t w;

	if (i1 == 0) {
		CMPPZ(r0);
	} else {
		assert(r0 != _R0);

		movi(_R0, i1);
		CMPGE(r0, _R0);
	}
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t
_bgti_u(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
	jit_word_t i1, jit_bool_t set)
{
	jit_word_t w;

	if (i1 == 0) {
		TST(r0, r0);
	} else {
		assert(r0 != _R0);

		movi(_R0, i1);
		CMPHI(r0, _R0);
	}
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t
_bgei_u(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
	jit_word_t i1, jit_bool_t set)
{
	jit_word_t w;

	assert(r0 != _R0);

	movi(_R0, i1);
	CMPHS(r0, _R0);
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t _beqi(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			jit_word_t i1, jit_bool_t set)
{
	jit_word_t w;

	if (i1 == 0) {
		TST(r0, r0);
	} else if (i1 >= -128 && i1 < 128) {
		movr(_R0, r0);
		CMPEQI(i1);
	} else {
		assert(r0 != _R0);

		movi(_R0, i1);
		CMPEQ(_R0, r0);
	}
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t _bmsi(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			jit_word_t i1, jit_bool_t set)
{
	jit_word_t w;

	assert(r0 != _R0);

	movi(_R0, i1);
	TST(_R0, r0);
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t _boaddr(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			  jit_uint16_t r1, jit_bool_t set)
{
	jit_word_t w;

	ADDV(r0, r1);

	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t _boaddr_u(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			    jit_uint16_t r1, jit_bool_t set)
{
	jit_word_t w;

	ADDC(r0, r1);

	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t _boaddi(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			  jit_word_t i1, jit_bool_t set)
{
	jit_word_t w;

	assert(r0 != _R0);

	movi(_R0, i1);
	w = _boaddr(_jit, i0, r0, _R0, set);

	return (w);
}

static jit_word_t _boaddi_u(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			    jit_word_t i1, jit_bool_t set)
{
	jit_word_t w;

	assert(r0 != _R0);

	movi(_R0, i1);
	w = _boaddr_u(_jit, i0, r0, _R0, set);

	return (w);
}

static jit_word_t _bosubr(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			  jit_uint16_t r1, jit_bool_t set)
{
	jit_word_t w;

	assert(r0 != _R0);

	NEG(_R0, r1);
	ADDV(r0, _R0);

	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t _bosubr_u(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			    jit_uint16_t r1, jit_bool_t set)
{
	jit_word_t w;

	SUBC(r0, r1);

	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t _bosubi(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			  jit_word_t i1, jit_bool_t set)
{
	jit_word_t w;

	assert(r0 != _R0);

	movi(_R0, i1);
	w = _bosubr(_jit, i0, r0, _R0, set);

	return (w);
}

static jit_word_t _bosubi_u(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			    jit_word_t i1, jit_bool_t set)
{
	jit_word_t w;

	assert(r0 != _R0);

	movi(_R0, i1);
	w = _bosubr_u(_jit, i0, r0, _R0, set);

	return (w);
}

static void
_jmpr(jit_state_t *_jit, jit_int16_t r0)
{
	JMP(r0);
	NOP();
}

static jit_word_t
_jmpi(jit_state_t *_jit, jit_word_t i0)
{
	jit_word_t w = _jit->pc.w;
	jit_int32_t disp = (i0 - w >> 1) - 2;

	if (disp >= -2048 && disp <= 2046) {
		BRA(disp);
		NOP();
	} else if (0) {
		/* TODO: BRAF */
		movi_p(_R0, disp - 7);
		BRAF(_R0);
		NOP();
	} else {
		movi(_R0, i0);
		jmpr(_R0);
	}

	return (w);
}

static void
_callr(jit_state_t *_jit, jit_int16_t r0)
{
	JSR(r0);
	NOP();
}

static void
_calli(jit_state_t *_jit, jit_word_t i0)
{
	movi(_R0, i0);
	callr(_R0);
}

static jit_word_t
_movi_p(jit_state_t *_jit, jit_uint16_t r0, jit_word_t i0)
{
	jit_word_t w = _jit->pc.w;

	MOVI(_R0, (i0 >> 24) & 0xff);
	SHLL8(_R0);
	ORI((i0 >> 16) & 0xff);
	SHLL8(_R0);
	ORI((i0 >> 8) & 0xff);
	SHLL8(_R0);
	ORI(i0 & 0xff);
	movr(r0, _R0);

	return (w);
}

static jit_word_t
_jmpi_p(jit_state_t *_jit, jit_word_t i0)
{
    jit_word_t w;

    w = movi_p(_R0, i0);
    jmpr(_R0);

    return (w);
}

static jit_word_t
_calli_p(jit_state_t *_jit, jit_word_t i0)
{
    jit_word_t		w;

    w = movi_p(_R0, i0);
    callr(_R0);

    return (w);
}

static void
_patch_abs(jit_state_t *_jit, jit_word_t instr, jit_word_t label)
{
	jit_instr_t *ptr = (jit_instr_t *)instr;

	ptr[0].ni.i = (label >> 24) & 0xff;
	ptr[2].ni.i = (label >> 16) & 0xff;
	ptr[4].ni.i = (label >> 8) & 0xff;
	ptr[6].ni.i = (label >> 0) & 0xff;
}

static void
_patch_at(jit_state_t *_jit, jit_word_t instr, jit_word_t label)
{
	jit_instr_t *ptr = (jit_instr_t *)instr;

	switch (ptr->nmd.c) {
	case 0xe:
		patch_abs(instr, label);
		break;
	case 0xa:
		ptr->d.d = ((label - instr) >> 1) - 2;
		break;
	case 0x8:
		switch (ptr->ni.n) {
		case 0x9:
		case 0xb:
		case 0xd:
		case 0xf:
			ptr->ni.i = ((label - instr) >> 1) - 2;
			break;
		default:
			assert(!"unhandled branch opcode");
		}
		break;
	default:
		assert("unhandled branch opcode");
	}
}

static void
_prolog(jit_state_t *_jit, jit_node_t *node)
{
	unsigned int i;

	if (_jitc->function->define_frame || _jitc->function->assume_frame) {
		jit_int32_t	frame = -_jitc->function->frame;
		assert(_jitc->function->self.aoff >= frame);
		if (_jitc->function->assume_frame)
			return;
		_jitc->function->self.aoff = frame;
	}

	if (_jitc->function->allocar)
		_jitc->function->self.aoff &= -8;
	_jitc->function->stack = ((_jitc->function->self.alen -
				   /* align stack at 16 bytes */
				   _jitc->function->self.aoff) + 15) & -16;

	subi(JIT_SP, JIT_SP, stack_framesize);
	stxi(4, JIT_SP, JIT_FP);

	for (i = 0; i < JIT_V_NUM; i++)
		if (jit_regset_tstbit(&_jitc->function->regset, JIT_V(i)))
			stxi((i + 2) * 4, JIT_SP, JIT_V(i));

	STSPR(_R0);
	str(JIT_SP, _R0);

	movr(JIT_FP, JIT_SP);

	if (_jitc->function->stack)
		subi(JIT_SP, JIT_SP, _jitc->function->stack);

#ifdef __SH_FPU_DOUBLE__
	_jitc->mode_d = 1;
#else
	_jitc->mode_d = 0;
#endif
}

static void
_epilog(jit_state_t *_jit, jit_node_t *node)
{
	unsigned int i;

	if (_jitc->function->assume_frame)
		return;

	ldr(JIT_SP, JIT_FP);
	LDSPR(JIT_SP);

	for (i = 0; i < JIT_V_NUM; i++)
		if (jit_regset_tstbit(&_jitc->function->regset, JIT_V(i)))
			ldxi(JIT_V(i), JIT_FP, (i + 2) * 4);

	addi(JIT_SP, JIT_FP, stack_framesize);

	RTS();
	ldxi(JIT_FP, JIT_FP, 4);
}
#endif /* CODE */
