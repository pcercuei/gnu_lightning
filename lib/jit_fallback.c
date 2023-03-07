#if PROTO
#define USE_BIT_TABLES			1
#define USE_BITSWAP_UNROLLED		0
#define USE_BITSWAP_LOOP		0
#define fallback_save(r0)		_fallback_save(_jit, r0)
static void _fallback_save(jit_state_t*, jit_int32_t);
#define fallback_load(r0)		_fallback_load(_jit, r0)
static void _fallback_load(jit_state_t*, jit_int32_t);
#define fallback_save_regs(r0)		_fallback_save_regs(_jit, r0)
static void _fallback_save_regs(jit_state_t*, jit_int32_t);
#define fallback_load_regs(r0)		_fallback_load_regs(_jit, r0)
static void _fallback_load_regs(jit_state_t*, jit_int32_t);
#define fallback_calli(i0, i1)		_fallback_calli(_jit, i0, i1)
static void _fallback_calli(jit_state_t*, jit_word_t, jit_word_t);
#define fallback_casx(r0,r1,r2,r3,im)	_fallback_casx(_jit,r0,r1,r2,r3,im)
static void _fallback_casx(jit_state_t *, jit_int32_t, jit_int32_t,
			   jit_int32_t, jit_int32_t, jit_word_t);
#define fallback_clo(r0,r1)		_fallback_clo(_jit,r0,r1)
static void _fallback_clo(jit_state_t*, jit_int32_t, jit_int32_t);
#define fallback_clz(r0,r1)		_fallback_clz(_jit,r0,r1)
static void _fallback_clz(jit_state_t*, jit_int32_t, jit_int32_t);
#define fallback_cto(r0,r1)		_fallback_cto(_jit,r0,r1)
static void _fallback_cto(jit_state_t*, jit_int32_t, jit_int32_t);
#define fallback_ctz(r0,r1)		_fallback_ctz(_jit,r0,r1)
static void _fallback_ctz(jit_state_t*, jit_int32_t, jit_int32_t);
#define fallback_bitswap(r0,r1)		_fallback_bitswap(_jit, r0, r1)
static void _fallback_bitswap(jit_state_t*, jit_int32_t, jit_int32_t);
#define fallback_popcnt(r0,r1)		_fallback_popcnt(_jit, r0, r1)
static void _fallback_popcnt(jit_state_t*, jit_int32_t, jit_int32_t);
#define fallback_lrotr(r0, r1, r2)	_fallback_lrotr(_jit, r0, r1, r2)
static void _fallback_lrotr(jit_state_t*, jit_int32_t,jit_int32_t,jit_int32_t);
#define fallback_lroti(r0, r1, i0)	_fallback_lroti(_jit, r0, r1, i0)
static void _fallback_lroti(jit_state_t*, jit_int32_t,jit_int32_t,jit_word_t);
#define fallback_rrotr(r0, r1, r2)	_fallback_rrotr(_jit, r0, r1, r2)
static void _fallback_rrotr(jit_state_t*, jit_int32_t,jit_int32_t,jit_int32_t);
#define fallback_rroti(r0, r1, i0)	_fallback_rroti(_jit, r0, r1, i0)
static void _fallback_rroti(jit_state_t*, jit_int32_t,jit_int32_t,jit_word_t);
#  if defined(__s390__) || defined(__s390x__)
#    define fallback_jit_get_reg(flags)	jit_get_reg_but_zero(flags)
#  else
#    define fallback_jit_get_reg(flags)	jit_get_reg(flags)
#  endif
#  if defined(__ia64__)
#    define fallback_flush()		sync()
#  elif defined(__mips__)
#    define fallback_flush()		flush()
#  else
#    define fallback_flush()		/**/
#  endif
#  if defined(__mips__)
#    define fallback_jmpi(i0)		jmpi(i0, 1)
#  elif defined(__arm__)
#    define fallback_jmpi(i0)		jmpi_p(i0, 1)
#  elif defined(__s390__) || defined(__s390x__)
#    define fallback_jmpi(i0)		jmpi(i0, 1)
#  else
#    define fallback_jmpi(i0)		jmpi(i0)
#  endif
#  if defined(__s390__) || defined(__s390x__)
#    define fallback_bnei(i0,r0,i1)	bnei_p(i0,r0,i1)
#    define fallback_blei(i0,r0,i1)	blei_p(i0,r0,i1)
#    define fallback_bmsr(i0,r0,r1)	bmsr_p(i0,r0,r1)
#    define fallback_bmsi(i0,r0,i1)	bmsi_p(i0,r0,i1)
#  else
#    define fallback_bnei(i0,r0,r1)	bnei(i0,r0,r1)
#    define fallback_blei(i0,r0,r1)	blei(i0,r0,r1)
#    define fallback_bmsr(i0,r0,r1)	bmsr(i0,r0,r1)
#    define fallback_bmsi(i0,r0,i1)	bmsi(i0,r0,i1)
#  endif
#  if defined(__ia64__)
#    define fallback_patch_jmpi(inst, lbl)				\
	patch_at(jit_code_jmpi, inst, lbl)
#    define fallback_patch_bnei(inst, lbl)				\
	patch_at(jit_code_bnei, inst, lbl)
#    define fallback_patch_blei(inst, lbl)				\
	patch_at(jit_code_blei, inst, lbl)
#    define fallback_patch_bmsr(inst, lbl)				\
	patch_at(jit_code_bmsr, inst, lbl)
#    define fallback_patch_bmsi(inst, lbl)				\
	patch_at(jit_code_bmsi, inst, lbl)
#  elif defined(__arm__)
#    define fallback_patch_jmpi(inst, lbl)				\
	patch_at(arm_patch_jump,inst, lbl)
#    define fallback_patch_bnei(inst, lbl)				\
	patch_at(arm_patch_jump,inst, lbl)
#    define fallback_patch_blei(inst, lbl)				\
	patch_at(arm_patch_jump,inst, lbl)
#    define fallback_patch_bmsr(inst, lbl)				\
	patch_at(arm_patch_jump,inst, lbl)
#    define fallback_patch_bmsi(inst, lbl)				\
	patch_at(arm_patch_jump,inst, lbl)
 #  else
#    define fallback_patch_jmpi(inst, lbl)				\
	patch_at(inst, lbl)
#    define fallback_patch_bnei(inst, lbl)				\
	patch_at(inst, lbl)
#    define fallback_patch_blei(inst, lbl)				\
	patch_at(inst, lbl)
#    define fallback_patch_bmsr(inst, lbl)				\
	patch_at(inst, lbl)
#    define fallback_patch_bmsi(inst, lbl)				\
	patch_at(inst, lbl)
#  endif
#endif

#if CODE
static void
_fallback_save(jit_state_t *_jit, jit_int32_t r0)
{
    jit_int32_t		offset, regno, spec;
    for (offset = 0; offset < JIT_R_NUM; offset++) {
	spec =  _rvs[offset].spec;
	regno = jit_regno(spec);
	if (regno == r0) {
	    if (!(spec & jit_class_sav))
		stxi(_jitc->function->regoff[JIT_R(offset)], rn(JIT_FP), regno);
	    break;
	}
    }
}

static void
_fallback_load(jit_state_t *_jit, jit_int32_t r0)
{
    jit_int32_t		offset, regno, spec;
    for (offset = 0; offset < JIT_R_NUM; offset++) {
	spec =  _rvs[offset].spec;
	regno = jit_regno(spec);
	if (regno == r0) {
	    if (!(spec & jit_class_sav))
		ldxi(regno, rn(JIT_FP), _jitc->function->regoff[JIT_R(offset)]);
	    break;
	}
    }
}

static void
_fallback_save_regs(jit_state_t *_jit, jit_int32_t r0)
{
    jit_int32_t		regno, spec;
    for (regno = 0; regno < _jitc->reglen; regno++) {
	spec =  _rvs[regno].spec;
	if ((jit_regset_tstbit(&_jitc->regarg, regno) ||
	     jit_regset_tstbit(&_jitc->reglive, regno)) &&
	    !(spec & jit_class_sav)) {
	    if (!_jitc->function->regoff[regno]) {
		_jitc->function->regoff[regno] =
		    jit_allocai(spec & jit_class_gpr ?
				sizeof(jit_word_t) : sizeof(jit_float64_t));
		_jitc->again = 1;
	    }
	    if ((spec & jit_class_gpr) && rn(regno) == r0)
		continue;
	    jit_regset_setbit(&_jitc->regsav, regno);
	    if (spec & jit_class_gpr)
		emit_stxi(_jitc->function->regoff[regno], JIT_FP, regno);
	    else
		emit_stxi_d(_jitc->function->regoff[regno], JIT_FP, regno);
	}
    }
}

static void
_fallback_load_regs(jit_state_t *_jit, jit_int32_t r0)
{
    jit_int32_t		regno, spec;
    for (regno = 0; regno < _jitc->reglen; regno++) {
	spec =  _rvs[regno].spec;
	if ((jit_regset_tstbit(&_jitc->regarg, regno) ||
	     jit_regset_tstbit(&_jitc->reglive, regno)) &&
	    !(spec & jit_class_sav)) {
	    if ((spec & jit_class_gpr) && rn(regno) == r0)
		continue;
	    jit_regset_setbit(&_jitc->regsav, regno);
	    if (spec & jit_class_gpr)
		emit_ldxi(regno, JIT_FP, _jitc->function->regoff[regno]);
	    else
		emit_ldxi_d(regno, JIT_FP, _jitc->function->regoff[regno]);
	}
    }
}

static void
_fallback_calli(jit_state_t *_jit, jit_word_t i0, jit_word_t i1)
{
#  if defined(__arm__)
    movi(rn(_R0), i1);
#  elif defined(__hppa__)
    movi(_R26_REGNO, i1);
#  endif
#  if defined(__arm__)
    calli(i0, jit_exchange_p());
#  elif defined(__mips__)
    calli(i0, 0);
#  elif defined(__powerpc__) && _CALL_SYSV
    calli(i0, 0);
#  elif defined(__s390__) || defined(__s390x__)
    calli(i0, 0);
#  else
    calli(i0);
#  endif
}

#ifdef NEED_FALLBACK_CASX
static void
_fallback_casx(jit_state_t *_jit, jit_int32_t r0, jit_int32_t r1,
	       jit_int32_t r2, jit_int32_t r3, jit_word_t i0)
{
    jit_int32_t		r1_reg, iscasi;
    jit_word_t		jump, done;
    /* XXX only attempts to fallback cas for lightning jit code */
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    if ((iscasi = r1 == _NOREG)) {
	r1_reg = fallback_jit_get_reg(jit_class_gpr|jit_class_sav);
	r1 = rn(r1_reg);
	movi(r1, i0);
    }
    fallback_save_regs(r0);
    fallback_calli((jit_word_t)pthread_mutex_lock, (jit_word_t)&mutex);
    fallback_load(r1);
    ldr(r0, r1);
    fallback_load(r2);
    eqr(r0, r0, r2);
    fallback_save(r0);
    jump = fallback_bnei(_jit->pc.w, r0, 1);
    fallback_load(r3);
#  if __WORDSIZE == 32
    str_i(r1, r3);
#  else
    str_l(r1, r3);
#  endif
    /* done: */
    fallback_flush();
    done = _jit->pc.w;
    fallback_calli((jit_word_t)pthread_mutex_unlock, (jit_word_t)&mutex);
    fallback_load(r0);
    fallback_patch_bnei(jump, done);
    fallback_load_regs(r0);
    if (iscasi)
	jit_unget_reg(r1_reg);
}
#endif

static void
_fallback_clo(jit_state_t *_jit, jit_int32_t r0, jit_int32_t r1)
{
    jit_word_t		clz, done;
    comr(r0, r1);
    clz = fallback_bnei(_jit->pc.w, r0, 0);
    movi(r0, __WORDSIZE);
    fallback_flush();
    done = fallback_jmpi(_jit->pc.w);
    fallback_flush();
    fallback_patch_bnei(clz, _jit->pc.w);
    fallback_clz(r0, r0);
    fallback_flush();
    fallback_patch_jmpi(done, _jit->pc.w);
}

static void
_fallback_clz(jit_state_t *_jit, jit_int32_t r0, jit_int32_t r1)
{
#  if USE_BIT_TABLES
    /*		t0 = __WORDSIZE - 8;
     *	loop:
     *		t1 = r1 >> t0;
     *		if (t1)
     *			goto done;
     *		t0 -= 8;
     *		if (t0)
     *			goto loop;
     *		t1 = r1;
     *	done:
     *		r0 = __WORDSIZE - 8 - t0 + clz_tab[t1]
     */
     /* Table below is count of leading zeros of 8 bit values. */
    static const jit_uint8_t clz_tab[256] = {
	8,7,6,6,5,5,5,5,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };
    jit_int32_t		t0, t1;
    jit_word_t		loop, done;
    t0 = fallback_jit_get_reg(jit_class_gpr);
    t1 = fallback_jit_get_reg(jit_class_gpr);
    movi(rn(t0), __WORDSIZE - 8);
    fallback_flush();
    loop = _jit->pc.w;
    rshr_u(rn(t1), r1, rn(t0));
    done = fallback_bnei(_jit->pc.w, rn(t1), 0);
    subi(rn(t0), rn(t0), 8);
    fallback_bnei(loop, rn(t0), 0);
    movr(rn(t1), r1);
    fallback_flush();
    fallback_patch_bnei(done, _jit->pc.w);
    rsbi(r0, rn(t0), __WORDSIZE - 8);
    movi(rn(t0), (jit_word_t)clz_tab);
    ldxr_uc(rn(t1), rn(t0), rn(t1));
    addr(r0, r0, rn(t1));
    jit_unget_reg(t1);
    jit_unget_reg(t0);
#  else
    jit_int32_t		r1_reg, r2, r2_reg;
    jit_word_t		clz, l32, l16, l8, l4, l2, l1;
    l32 = fallback_bnei(_jit->pc.w, r1, 0);
    movi(r0, __WORDSIZE);
    clz = fallback_jmpi(_jit->pc.w);
    fallback_flush();
    fallback_patch_bnei(l32, _jit->pc.w);
    r2_reg = fallback_jit_get_reg(jit_class_gpr);
    r2 = rn(r2_reg);
    r1_reg = fallback_jit_get_reg(jit_class_gpr);
    movr(rn(r1_reg), r1);
    r1 = rn(r1_reg);
    movi(r0, 0);
#    if __WORDSIZE == 64
    movi(r2, 0xffffffff00000000UL);
    l32 = fallback_bmsr(_jit->pc.w, r1, r2);
    lshi(r1, r1, 32);
    addi(r0, r0, 32);
    fallback_flush();
    fallback_patch_bmsr(l32, _jit->pc.w);
    lshi(r2, r2, 16);
#    else
    movi(r2, 0xffff0000UL);
#    endif
    l16 = fallback_bmsr(_jit->pc.w, r1, r2);
    lshi(r1, r1, 16);
    addi(r0, r0, 16);
    fallback_flush();
    fallback_patch_bmsr(l16, _jit->pc.w);
    lshi(r2, r2, 8);
    l8 = fallback_bmsr(_jit->pc.w, r1, r2);
    lshi(r1, r1, 8);
    addi(r0, r0, 8);
    fallback_flush();
    fallback_patch_bmsr(l8, _jit->pc.w);
    lshi(r2, r2, 4);
    l4 = fallback_bmsr(_jit->pc.w, r1, r2);
    lshi(r1, r1, 4);
    addi(r0, r0, 4);
    fallback_flush();
    fallback_patch_bmsr(l4, _jit->pc.w);
    lshi(r2, r2, 2);
    l2 = fallback_bmsr(_jit->pc.w, r1, r2);
    lshi(r1, r1, 2);
    addi(r0, r0, 2);
    fallback_flush();
    fallback_patch_bmsr(l2, _jit->pc.w);
    lshi(r2, r2, 1);
    l1 = fallback_bmsr(_jit->pc.w, r1, r2);
    addi(r0, r0, 1);
    fallback_flush();
    fallback_patch_bmsr(l1, _jit->pc.w);
    fallback_patch_jmpi(clz, _jit->pc.w);
    jit_unget_reg(r2_reg);
    jit_unget_reg(r1_reg);
#  endif
}

static void
_fallback_cto(jit_state_t *_jit, jit_int32_t r0, jit_int32_t r1)
{
    jit_word_t		ctz, done;
    comr(r0, r1);
    ctz = fallback_bnei(_jit->pc.w, r0, 0);
    movi(r0, __WORDSIZE);
    done = fallback_jmpi(_jit->pc.w);
    fallback_flush();
    fallback_patch_bnei(ctz, _jit->pc.w);
    fallback_ctz(r0, r0);
    fallback_flush();
    fallback_patch_jmpi(done, _jit->pc.w);
}

static void
_fallback_ctz(jit_state_t *_jit, jit_int32_t r0, jit_int32_t r1)
{
#  if USE_BIT_TABLES
    /* Adapted from http://graphics.stanford.edu/~seander/bithacks.html#ZerosOnRightModLookup
     * Table for 64 bits was recomputed choosing 67 as next prime number.
     * The cost of the modulo might not compensate and could be better to
     * use the alternate version (or bitswap and use clz).
     */
    jit_int32_t		t0;
#    if __WORDSIZE == 32
    static const jit_uint8_t mod37[] = {
	32,  0,  1, 26,  2, 23, 27,  0,  3, 16, 24, 30, 28, 11,  0, 13,
	 4,  7, 17,  0, 25, 22, 31, 15, 29, 10, 12,  6,  0, 21, 14,  9,
	 5, 20, 8, 19, 18
    };
    /* return mod37[(-r1 & r1) % 37]; */
#    else
    static const jit_uint8_t mod67[] = {
	64,  0,  1, 39,  2, 15, 40, 23,  3, 12, 16, 59, 41, 19, 24, 54,
         4,  0, 13, 10, 17, 62, 60, 28, 42, 30, 20, 51, 25, 44, 55, 47,
         5, 32,  0, 38, 14, 22, 11, 58, 18, 53, 63,  9, 61, 27, 29, 50,
        43, 46, 31, 37, 21, 57, 52,  8, 26, 49, 45, 36, 56,  7, 48, 35,
         6, 34, 33
    };
    /* return mod67[(-r1 & r1) % 67]; */
#    endif
    t0 = fallback_jit_get_reg(jit_class_gpr);
    if (r0 == r1) {
	negr(rn(t0), r1);
	andr(r0, rn(t0), r1);
    }
    else {
	negr(r0, r1);
	andr(r0, r0, r1);
    }
#    if __WORDSIZE == 32
    remi_u(r0, r0, 37);
    movi(rn(t0), (jit_word_t)mod37);
#    else
    remi_u(r0, r0, 67);
    movi(rn(t0), (jit_word_t)mod67);
#    endif
    ldxr_uc(r0, rn(t0), r0);
    jit_unget_reg(t0);
#  else
    jit_int32_t		r1_reg, r2, r2_reg;
    jit_word_t		ctz, l32, l16, l8, l4, l2, l1;
    l32 = fallback_bnei(_jit->pc.w, r1, 0);
    movi(r0, __WORDSIZE);
    ctz = fallback_jmpi(_jit->pc.w);
    fallback_flush();
    fallback_patch_bnei(l32, _jit->pc.w);
    r2_reg = fallback_jit_get_reg(jit_class_gpr);
    r2 = rn(r2_reg);
    r1_reg = fallback_jit_get_reg(jit_class_gpr);
    movr(rn(r1_reg), r1);
    r1 = rn(r1_reg);
    movi(r0, 0);
#    if __WORDSIZE == 64
    movi(r2, 0xffffffffUL);
    l32 = fallback_bmsr(_jit->pc.w, r1, r2);
    rshi_u(r1, r1, 32);
    addi(r0, r0, 32);
    fallback_flush();
    fallback_patch_bmsr(l32, _jit->pc.w);
    rshi(r2, r2, 16);
#    else
    movi(r2, 0xffffUL);
#    endif
    l16 = fallback_bmsr(_jit->pc.w, r1, r2);
    rshi_u(r1, r1, 16);
    addi(r0, r0, 16);
    fallback_flush();
    fallback_patch_bmsr(l16, _jit->pc.w);
    rshi(r2, r2, 8);
    l8 = fallback_bmsr(_jit->pc.w, r1, r2);
    rshi_u(r1, r1, 8);
    addi(r0, r0, 8);
    fallback_flush();
    fallback_patch_bmsr(l8, _jit->pc.w);
    rshi(r2, r2, 4);
    l4 = fallback_bmsr(_jit->pc.w, r1, r2);
    rshi_u(r1, r1, 4);
    addi(r0, r0, 4);
    fallback_flush();
    fallback_patch_bmsr(l4, _jit->pc.w);
    rshi(r2, r2, 2);
    l2 = fallback_bmsr(_jit->pc.w, r1, r2);
    rshi_u(r1, r1, 2);
    addi(r0, r0, 2);
    fallback_flush();
    fallback_patch_bmsr(l2, _jit->pc.w);
    rshi(r2, r2, 1);
    l1 = fallback_bmsr(_jit->pc.w, r1, r2);
    addi(r0, r0, 1);
    fallback_flush();
    fallback_patch_bmsr(l1, _jit->pc.w);
    fallback_patch_jmpi(ctz, _jit->pc.w);
    jit_unget_reg(r2_reg);
    jit_unget_reg(r1_reg);
#  endif
}

static void
_fallback_bitswap(jit_state_t *_jit, jit_int32_t r0, jit_int32_t r1)
{
#  if USE_BIT_TABLES
    /*		t0 = r1;
     *		t1 = t0 & 0xff;
     *		t2 = swap_tab;
     *		r0 = t2[t1];
     *		t3 = 8;
     *	loop:
     *		t1 = t0 >> t3;
     *		t1 &= 0xff;
     *		r0 <<= 8;
     *		r0 |= t2[t1];
     *		t3 += 8;
     *		if (t3 < __WORDSIZE)
     *		    goto loop;
     */
    jit_word_t		loop;
    jit_int32_t		t0, r1_reg, t1, t2, t3;
    static const unsigned char swap_tab[256] = {
	 0, 128, 64, 192, 32, 160,  96, 224,
	16, 144, 80, 208, 48, 176, 112, 240,
	 8, 136, 72, 200, 40, 168, 104, 232,
	24, 152, 88, 216 ,56, 184, 120, 248,
	 4, 132, 68, 196, 36, 164, 100, 228,
	20, 148, 84, 212, 52, 180, 116, 244,
	12, 140, 76, 204, 44, 172, 108, 236,
	28, 156, 92, 220, 60, 188, 124, 252,
	 2, 130, 66, 194, 34, 162,  98, 226,
	18, 146, 82, 210, 50, 178, 114, 242,
	10, 138, 74, 202, 42, 170, 106, 234,
	26, 154, 90, 218, 58, 186, 122, 250,
	 6, 134, 70, 198, 38, 166, 102, 230,
	22, 150, 86, 214, 54, 182, 118, 246,
	14, 142, 78, 206, 46, 174, 110, 238,
	30, 158, 94, 222, 62, 190, 126, 254,
	 1, 129, 65, 193, 33, 161,  97, 225,
	17, 145, 81, 209, 49, 177, 113, 241,
	 9, 137, 73, 201, 41, 169, 105, 233,
	25, 153, 89, 217, 57, 185, 121, 249,
	 5, 133, 69, 197, 37, 165, 101, 229,
	21, 149, 85, 213, 53, 181, 117, 245,
	13, 141, 77, 205, 45, 173, 109, 237,
	29, 157, 93, 221, 61, 189, 125, 253,
	 3, 131, 67, 195, 35, 163,  99, 227,
	19, 147, 83, 211, 51, 179, 115, 243,
	11, 139, 75, 203, 43, 171, 107, 235,
	27, 155, 91, 219, 59, 187, 123, 251,
	 7, 135, 71, 199, 39, 167, 103, 231,
	23, 151, 87, 215, 55, 183, 119, 247,
	15, 143, 79, 207, 47, 175, 111, 239,
	31, 159, 95, 223, 63, 191, 127, 255
    };
    if (r0 == r1) {
	t0 = fallback_jit_get_reg(jit_class_gpr);
	r1_reg = rn(t0);
    }
    else {
	t0 = JIT_NOREG;
	r1_reg = r1;
    }
    t1 = fallback_jit_get_reg(jit_class_gpr);
    t2 = fallback_jit_get_reg(jit_class_gpr);
    t3 = fallback_jit_get_reg(jit_class_gpr);
    if (r0 == r1)
	movr(rn(t0), r1);
    extr_uc(rn(t1), r1_reg);
    movi(rn(t2), (jit_word_t)swap_tab);
    ldxr_uc(r0, rn(t2), rn(t1));
    movi(rn(t3), 8);
    fallback_flush();
    loop = _jit->pc.w;
    rshr(rn(t1), r1_reg, rn(t3));
    extr_uc(rn(t1), rn(t1));
    lshi(r0, r0, 8);
    ldxr_uc(rn(t1), rn(t2), rn(t1));
    orr(r0, r0, rn(t1));
    addi(rn(t3), rn(t3), 8);
    blti(loop, rn(t3), __WORDSIZE);
    jit_unget_reg(t3);
    jit_unget_reg(t2);
    jit_unget_reg(t1);
    if (t0 != JIT_NOREG)
	jit_unget_reg(t0);
#  elif USE_BITSWAP_UNROLLED
/* http://graphics.stanford.edu/~seander/bithacks.html#ReverseParallel */
/*
unsigned int v; // 32-bit word to reverse bit order

// swap odd and even bits
v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
// swap consecutive pairs
v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
// swap nibbles ...
v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
// swap bytes
v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
// swap 2-byte long pairs
v = ( v >> 16             ) | ( v               << 16);
 */
    jit_int32_t		t0, t1, t2, t3, t4;
    movr(r0, r1);
    t0 = fallback_jit_get_reg(jit_class_gpr);
    t1 = fallback_jit_get_reg(jit_class_gpr);
    t2 = fallback_jit_get_reg(jit_class_gpr);
    movi(rn(t0), __WORDSIZE == 32 ? 0x55555555L : 0x5555555555555555L);
    rshi_u(rn(t1), r0, 1);		/* t1 = v >> 1 */
    andr(rn(t1), rn(t1), rn(t0));	/* t1 &= t0 */
    andr(rn(t2), r0, rn(t0));		/* t2 = v & t0*/
    lshi(rn(t2), rn(t2), 1);		/* t2 <<= 1 */
    orr(r0, rn(t1), rn(t2));		/* v = t1 | t2 */
    movi(rn(t0), __WORDSIZE == 32 ? 0x33333333L : 0x3333333333333333L);
    rshi_u(rn(t1), r0, 2);		/* t1 = v >> 2 */
    andr(rn(t1), rn(t1), rn(t0));	/* t1 &= t0 */
    andr(rn(t2), r0, rn(t0));		/* t2 = v & t0*/
    lshi(rn(t2), rn(t2), 2);		/* t2 <<= 2 */
    orr(r0, rn(t1), rn(t2));		/* v = t1 | t2 */
    movi(rn(t0), __WORDSIZE == 32 ? 0x0f0f0f0fL : 0x0f0f0f0f0f0f0f0fL);
    rshi_u(rn(t1), r0, 4);		/* t1 = v >> 4 */
    andr(rn(t1), rn(t1), rn(t0));	/* t1 &= t0 */
    andr(rn(t2), r0, rn(t0));		/* t2 = v & t0*/
    lshi(rn(t2), rn(t2), 4);		/* t2 <<= 4 */
    orr(r0, rn(t1), rn(t2));		/* v = t1 | t2 */
    movi(rn(t0), __WORDSIZE == 32 ?  0x00ff00ffL : 0x00ff00ff00ff00ffL);
    rshi_u(rn(t1), r0, 8);		/* t1 = v >> 8 */
    andr(rn(t1), rn(t1), rn(t0));	/* t1 &= t0 */
    andr(rn(t2), r0, rn(t0));		/* t2 = v & t0*/
    lshi(rn(t2), rn(t2), 8);		/* t2 <<= 8 */
    orr(r0, rn(t1), rn(t2));		/* v = t1 | t2 */
#    if __WORDSIZE == 32
    rshi_u(rn(t1), r0, 16);		/* t1 = v >> 16 */
    lshi(rn(t2), r0, 16);		/* t2 = v << 16 */
    orr(r0, rn(t1), rn(t2));		/* v = t1 | t2 */
#    else
    movi(rn(t0), 0x0000ffff0000ffffL);
    rshi_u(rn(t1), r0, 16);		/* t1 = v >> 16 */
    andr(rn(t1), rn(t1), rn(t0));	/* t1 &= t0 */
    andr(rn(t2), r0, rn(t0));		/* t2 = v & t0*/
    lshi(rn(t2), rn(t2), 16);		/* t2 <<= 16 */
    orr(r0, rn(t1), rn(t2));		/* v = t1 | t2 */
    rshi_u(rn(t1), r0, 32);		/* t1 = v >> 32 */
    lshi(rn(t2), r0, 32);		/* t2 = v << 32 */
    orr(r0, rn(t1), rn(t2));		/* v = t1 | t2 */
#    endif
    jit_unget_reg(t2);
    jit_unget_reg(t1);
    jit_unget_reg(t0);
#  elif USE_BITSWAP_LOOP
/* http://graphics.stanford.edu/~seander/bithacks.html#ReverseParallel */
/*
unsigned int s = sizeof(v) * CHAR_BIT; // bit size; must be power of 2
unsigned int mask = ~0;
while ((s >>= 1) > 0)
{
  mask ^= (mask << s);
  v = ((v >> s) & mask) | ((v << s) & ~mask);
}
*/
    jit_int32_t		s, mask;
    jit_word_t		loop, done, t0, t1;
    movr(v, r1);
    s = fallback_jit_get_reg(jit_class_gpr);
    movi(rn(s), __WORDSIZE);			/* s = sizeof(v) * CHAR_BIT; */
    mask = fallback_jit_get_reg(jit_class_gpr);
    movi(rn(mask), ~0L);			/* mask = ~0; */
    flush();
    loop = _jit->pc.w;				/* while ((s >>= 1) > 0) */
    rshi(rn(s), rn(s), 1);			/*        (s >>= 1) */
    done = blei(_jit->pc.w, rn(s), 0);		/* no loop if s <= 0 */
    t0 = fallback_jit_get_reg(jit_class_gpr);
    lshr(rn(t0), rn(mask), rn(s));		/* t0 = (mask << s) */
    xorr(rn(mask), rn(mask), rn(t0));		/* mask ^= t0 */
    rshr(rn(t0), v, rn(s));			/* t0 = v >> s */
    andr(rn(t0), rn(t0), rn(mask));		/* t0 = t0 & mask */
    t1 = fallback_jit_get_reg(jit_class_gpr);
    lshr(rn(t1), v, rn(s));			/* t1 = v << s */
    comr(v, rn(mask));				/* v = ~mask */
    andr(rn(t1), v, rn(t1));			/* t1 = t1 & v */
    orr(v, rn(t0), rn(t1));			/* v = t0 | t1 */
    jmpi(loop);
    flush();
    patch_at(done, _jit->pc.w);
    jit_unget_reg(t1);
    jit_unget_reg(t0);
    jit_unget_reg(mask);
    jit_unget_reg(s);
#  endif
}

static void
_fallback_popcnt(jit_state_t *_jit, jit_int32_t r0, jit_int32_t r1)
{
    /* Same approach as rbitr */
    /*		t0 = r1;
     *		t1 = t0 & 0xff;
     *		t2 = pop_tab;
     *		r0 = t2[t1];
     *		t3 = 8;
     *	loop:
     *		t1 = t0 >> t3;
     *		t1 &= 0xff;
     *		r0 <<= 8;
     *		r0 |= t2[t1];
     *		t3 += 8;
     *		if (t3 < __WORDSIZE)
     *		    goto loop;
     */
    jit_word_t		loop;
    jit_int32_t		t0, r1_reg, t1, t2, t3;
    static const unsigned char pop_tab[256] = {
	0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
	3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8
    };
    if (r0 == r1) {
	t0 = fallback_jit_get_reg(jit_class_gpr);
	r1_reg = rn(t0);
    }
    else {
	t0 = JIT_NOREG;
	r1_reg = r1;
    }
    t1 = fallback_jit_get_reg(jit_class_gpr);
    t2 = fallback_jit_get_reg(jit_class_gpr);
    t3 = fallback_jit_get_reg(jit_class_gpr);
    if (r0 == r1)
	movr(rn(t0), r1);
    extr_uc(rn(t1), r1_reg);
    movi(rn(t2), (jit_word_t)pop_tab);
    ldxr_uc(r0, rn(t2), rn(t1));
    movi(rn(t3), 8);
    fallback_flush();
    loop = _jit->pc.w;
    rshr(rn(t1), r1_reg, rn(t3));
    extr_uc(rn(t1), rn(t1));
    ldxr_uc(rn(t1), rn(t2), rn(t1));
    addr(r0, r0, rn(t1));
    addi(rn(t3), rn(t3), 8);
    blti(loop, rn(t3), __WORDSIZE);
    jit_unget_reg(t3);
    jit_unget_reg(t2);
    jit_unget_reg(t1);
    if (t0 != JIT_NOREG)
	jit_unget_reg(t0);
}

static void
_fallback_lrotr(jit_state_t *_jit,
		jit_int32_t r0, jit_int32_t r1, jit_int32_t r2)
{
    /* r0 = (r1 << r2) | (r1 >> (__WORDSIZE - r2)) */
    jit_int32_t		t0, t1;
    t0 = fallback_jit_get_reg(jit_class_gpr);
    if (r0 == r1 || r0 == r2) {
	t1 = fallback_jit_get_reg(jit_class_gpr);
	lshr(rn(t0), r1, r2);
	rsbi(rn(t1), r2, __WORDSIZE);
	rshr_u(rn(t1), r1, rn(t1));
	orr(r0, rn(t0), rn(t1));
	jit_unget_reg(t1);
    }
    else {
	lshr(r0, r1, r2);
	rsbi(rn(t0), r2, __WORDSIZE);
	rshr_u(rn(t0), r1, rn(t0));
	orr(r0, r0, rn(t0));
    }
    jit_unget_reg(t0);
}

static void
_fallback_lroti(jit_state_t *_jit,
		jit_int32_t r0, jit_int32_t r1, jit_word_t i0)
{
    jit_int32_t		t0;
    t0 = fallback_jit_get_reg(jit_class_gpr);
    lshi(rn(t0), r1, i0);
    rshi_u(r0, r1, __WORDSIZE - i0);
    orr(r0, r0, rn(t0));
    jit_unget_reg(t0);
}

static void
_fallback_rrotr(jit_state_t *_jit,
		jit_int32_t r0, jit_int32_t r1, jit_int32_t r2)
{
    /* r0 = (r1 >> r2) | (r1 << (__WORDSIZE - r2)) */
    jit_int32_t		t0, t1;
    t0 = fallback_jit_get_reg(jit_class_gpr);
    if (r0 == r1 || r0 == r2) {
	t1 = fallback_jit_get_reg(jit_class_gpr);
	rshr_u(rn(t0), r1, r2);
	rsbi(rn(t1), r2, __WORDSIZE);
	lshr(rn(t1), r1, rn(t1));
	orr(r0, rn(t0), rn(t1));
	jit_unget_reg(t1);
    }
    else {
	rshr_u(r0, r1, r2);
	rsbi(rn(t0), r2, __WORDSIZE);
	lshr(rn(t0), r1, rn(t0));
	orr(r0, r0, rn(t0));
    }
    jit_unget_reg(t0);
}

static void
_fallback_rroti(jit_state_t *_jit,
		jit_int32_t r0, jit_int32_t r1, jit_word_t i0)
{
    jit_int32_t		t0;
    t0 = fallback_jit_get_reg(jit_class_gpr);
    rshi_u(rn(t0), r1, i0);
    lshi(r0, r1, __WORDSIZE - i0);
    orr(r0, r0, rn(t0));
    jit_unget_reg(t0);
}
#endif
