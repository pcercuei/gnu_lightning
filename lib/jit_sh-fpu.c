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
static void _extr_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_bool_t);
#  define extr_f(r0, r1)		_extr_f(_jit, r0, r1,0)
#  define extr_d(r0, r1)		_extr_f(_jit, r0, r1,1)
static void _truncr_f_i(jit_state_t*,jit_int16_t,jit_int16_t,jit_bool_t);
#  define truncr_f_i(r0, r1)		_truncr_f_i(_jit, r0, r1, 0)
#  define truncr_d_i(r0, r1)		_truncr_f_i(_jit, r0, r1, 1)
static void _movr_f(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define movr_f(r0, r1)		_movr_f(_jit, r0, r1)
static void _movr_d(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define movr_d(r0, r1)		_movr_d(_jit, r0, r1)
static void _movi_f(jit_state_t*,jit_uint16_t,jit_float32_t);
#  define movi_f(r0, i0)		_movi_f(_jit, r0, i0)
static void _movi_d(jit_state_t*,jit_uint16_t,jit_float64_t);
#  define movi_d(r0, i0)		_movi_d(_jit, r0, i0)
static void _ltr_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t,jit_bool_t);
#  define ltr_f(r0, r1, r2)		_ltr_f(_jit,r0,r1,r2,0)
#  define ltr_d(r0, r1, r2)		_ltr_f(_jit,r0,r1,r2,1)
static void _lti_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define lti_f(r0, r1, i0)		_lti_f(_jit,r0,r1,i0)
static void _lti_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define lti_d(r0, r1, i0)		_lti_d(_jit,r0,r1,i0)
static void _ler_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t,jit_bool_t);
#  define ler_f(r0, r1, r2)		_ler_f(_jit,r0,r1,r2,0)
#  define ler_d(r0, r1, r2)		_ler_f(_jit,r0,r1,r2,1)
static void _lei_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define lei_f(r0, r1, i0)		_lei_f(_jit,r0,r1,i0)
static void _lei_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define lei_d(r0, r1, i0)		_lei_d(_jit,r0,r1,i0)
static void _eqr_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t,jit_bool_t);
#  define eqr_f(r0, r1, r2)		_eqr_f(_jit,r0,r1,r2,0)
#  define eqr_d(r0, r1, r2)		_eqr_f(_jit,r0,r1,r2,1)
static void _eqi_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define eqi_f(r0, r1, i0)		_eqi_f(_jit,r0,r1,i0)
static void _eqi_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define eqi_d(r0, r1, i0)		_eqi_d(_jit,r0,r1,i0)
#  define ger_f(r0, r1, r2)		ler_f(r0,r2,r1)
#  define ger_d(r0, r1, r2)		ler_d(r0,r2,r1)
static void _gei_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define gei_f(r0, r1, i0)		_gei_f(_jit,r0,r1,i0)
static void _gei_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define gei_d(r0, r1, i0)		_gei_f(_jit,r0,r1,i0)
static void _gtr_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define gtr_f(r0, r1, r2)		ltr_f(r0,r2,r1)
#  define gtr_d(r0, r1, r2)		ltr_d(r0,r2,r1)
static void _gti_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define gti_f(r0, r1, i0)		_gti_f(_jit,r0,r1,i0)
static void _gti_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define gti_d(r0, r1, i0)		_gti_d(_jit,r0,r1,i0)
static void _ner_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define ner_f(r0, r1, r2)		_ner_f(_jit,r0,r1,r2)
static void _ner_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define ner_d(r0, r1, r2)		_ner_d(_jit,r0,r1,r2)
static void _nei_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define nei_f(r0, r1, i0)		_nei_f(_jit,r0,r1,i0)
static void _nei_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define nei_d(r0, r1, i0)		_nei_d(_jit,r0,r1,i0)
static void _unltr_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define unltr_f(r0, r1, r2)		_unltr_f(_jit,r0,r1,r2)
static void _unltr_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define unltr_d(r0, r1, r2)		_unltr_d(_jit,r0,r1,r2)
static void _unlti_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define unlti_f(r0, r1, i0)		_unlti_f(_jit,r0,r1,i0)
static void _unlti_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define unlti_d(r0, r1, i0)		_unlti_d(_jit,r0,r1,i0)
static void _unler_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define unler_f(r0, r1, r2)		_unler_f(_jit,r0,r1,r2)
static void _unler_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define unler_d(r0, r1, r2)		_unler_d(_jit,r0,r1,r2)
static void _unlei_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define unlei_f(r0, r1, i0)		_unlei_f(_jit,r0,r1,i0)
static void _unlei_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define unlei_d(r0, r1, i0)		_unlei_d(_jit,r0,r1,i0)
static void _ungtr_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define ungtr_f(r0, r1, r2)		_ungtr_f(_jit,r0,r1,r2)
static void _ungtr_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define ungtr_d(r0, r1, r2)		_ungtr_d(_jit,r0,r1,r2)
static void _ungti_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define ungti_f(r0, r1, i0)		_ungti_f(_jit,r0,r1,i0)
static void _ungti_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define ungti_d(r0, r1, i0)		_ungti_d(_jit,r0,r1,i0)
static void _unger_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define unger_f(r0, r1, r2)		_unger_f(_jit,r0,r1,r2)
static void _unger_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define unger_d(r0, r1, r2)		_unger_d(_jit,r0,r1,r2)
static void _ungei_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define ungei_f(r0, r1, i0)		_ungei_f(_jit,r0,r1,i0)
static void _ungei_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define ungei_d(r0, r1, i0)		_ungei_d(_jit,r0,r1,i0)
static void _uneqr_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define uneqr_f(r0, r1, r2)		_uneqr_f(_jit,r0,r1,r2)
static void _uneqr_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define uneqr_d(r0, r1, r2)		_uneqr_d(_jit,r0,r1,r2)
static void _uneqi_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define uneqi_f(r0, r1, i0)		_uneqi_f(_jit,r0,r1,i0)
static void _uneqi_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define uneqi_d(r0, r1, i0)		_uneqi_d(_jit,r0,r1,i0)
static void _ltgtr_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define ltgtr_f(r0, r1, r2)		_ltgtr_f(_jit,r0,r1,r2)
static void _ltgtr_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define ltgtr_d(r0, r1, r2)		_ltgtr_d(_jit,r0,r1,r2)
static void _ltgti_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define ltgti_f(r0, r1, i0)		_ltgti_f(_jit,r0,r1,i0)
static void _ltgti_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define ltgti_d(r0, r1, i0)		_ltgti_d(_jit,r0,r1,i0)
static void _ordr_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define ordr_f(r0, r1, r2)		_ordr_f(_jit,r0,r1,r2)
static void _ordr_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define ordr_d(r0, r1, r2)		_ordr_d(_jit,r0,r1,r2)
static void _ordi_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define ordi_f(r0, r1, i0)		_ordi_f(_jit,r0,r1,i0)
static void _ordi_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define ordi_d(r0, r1, i0)		_ordi_d(_jit,r0,r1,i0)
static void _unordr_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define unordr_f(r0, r1, r2)		_unordr_f(_jit,r0,r1,r2)
static void _unordr_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_int16_t);
#  define unordr_d(r0, r1, r2)		_unordr_d(_jit,r0,r1,r2)
static void _unordi_f(jit_state_t*,jit_int16_t,jit_int16_t,jit_float32_t);
#  define unordi_f(r0, r1, i0)		_unordi_f(_jit,r0,r1,i0)
static void _unordi_d(jit_state_t*,jit_int16_t,jit_int16_t,jit_float64_t);
#  define unordi_d(r0, r1, i0)		_unordi_d(_jit,r0,r1,i0)
static void _addr_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t,jit_bool_t);
#  define addr_f(r0,r1,r2)		_addr_f(_jit,r0,r1,r2,0)
#  define addr_d(r0,r1,r2)		_addr_f(_jit,r0,r1,r2,1)
static void _addi_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_float32_t);
#  define addi_f(r0,r1,i0)		_addi_f(_jit,r0,r1,i0)
static void _addi_d(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_float64_t);
#  define addi_d(r0,r1,i0)		_addi_d(_jit,r0,r1,i0)
static void _subr_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#  define subr_f(r0,r1,r2)		_subr_f(_jit,r0,r1,r2)
static void _subr_d(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#  define subr_d(r0,r1,r2)		_subr_d(_jit,r0,r1,r2)
static void _subi_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_float32_t);
#  define subi_f(r0,r1,i0)		_subi_f(_jit,r0,r1,i0)
static void _subi_d(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_float64_t);
#  define subi_d(r0,r1,i0)		_subi_d(_jit,r0,r1,i0)
static void _negr_f(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define negr_f(r0,r1)			_negr_f(_jit,r0,r1)
static void _negr_d(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define negr_d(r0,r1)			_negr_d(_jit,r0,r1)
#  define rsbr_f(r0,r1,r2)		subr_f(r0,r2,r1)
static void _rsbi_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_float32_t);
#  define rsbi_f(r0,r1,i0)		_rsbi_f(_jit,r0,r1,i0)
#  define rsbr_d(r0,r1,r2)		subr_d(r0,r2,r1)
static void _rsbi_d(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_float64_t);
#  define rsbi_d(r0,r1,i0)		_rsbi_d(_jit,r0,r1,i0)
static void _mulr_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#  define mulr_f(r0,r1,r2)		_mulr_f(_jit,r0,r1,r2)
static void _muli_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_float32_t);
#  define muli_f(r0,r1,i0)		_muli_f(_jit,r0,r1,i0)
static void _mulr_d(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#  define mulr_d(r0,r1,r2)		_mulr_d(_jit,r0,r1,r2)
static void _muli_d(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_float64_t);
#  define muli_d(r0,r1,i0)		_muli_d(_jit,r0,r1,i0)
static void _divr_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#  define divr_f(r0,r1,r2)		_divr_f(_jit,r0,r1,r2)
static void _divi_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_float32_t);
#  define divi_f(r0,r1,i0)		_divi_f(_jit,r0,r1,i0)
static void _divr_d(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#  define divr_d(r0,r1,r2)		_divr_d(_jit,r0,r1,r2)
static void _divi_d(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_float64_t);
#  define divi_d(r0,r1,i0)		_divi_d(_jit,r0,r1,i0)
static void _absr_f(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define absr_f(r0,r1)			_absr_f(_jit,r0,r1)
static void _absr_d(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define absr_d(r0,r1)			_absr_d(_jit,r0,r1)
static void _sqrtr_f(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define sqrtr_f(r0,r1)		_sqrtr_f(_jit,r0,r1)
static void _sqrtr_d(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define sqrtr_d(r0,r1)		_sqrtr_d(_jit,r0,r1)
static void _extr_d_f(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define extr_d_f(r0,r1)		_extr_d_f(_jit,r0,r1)
static void _extr_f_d(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define extr_f_d(r0,r1)		_extr_f_d(_jit,r0,r1)
#  define ldr_f(r0,r1)			LDF(r0,r1)
static void _ldr_d(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define ldr_d(r0,r1)			_ldr_d(_jit,r0,r1)
static void _ldi_f(jit_state_t*,jit_uint16_t,jit_word_t);
#  define ldi_f(r0,i0)			_ldi_f(_jit,r0,i0)
static void _ldi_d(jit_state_t*,jit_uint16_t,jit_word_t);
#  define ldi_d(r0,i0)			_ldi_d(_jit,r0,i0)
static void _ldxr_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#  define ldxr_f(r0,r1,r2)		_ldxr_f(_jit,r0,r1,r2)
static void _ldxr_d(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#  define ldxr_d(r0,r1,r2)		_ldxr_d(_jit,r0,r1,r2)
static void _ldxi_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#  define ldxi_f(r0,r1,i0)		_ldxi_f(_jit,r0,r1,i0)
static void _ldxi_d(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_word_t);
#  define ldxi_d(r0,r1,i0)		_ldxi_d(_jit,r0,r1,i0)
#  define str_f(r0,r1)			STF(r0,r1)
static void _str_d(jit_state_t*,jit_uint16_t,jit_uint16_t);
#  define str_d(r0,r1)			_str_d(_jit,r0,r1)
static void _sti_f(jit_state_t*,jit_word_t,jit_uint16_t);
#  define sti_f(i0,r0)			_sti_f(_jit,i0,r0)
static void _sti_d(jit_state_t*,jit_word_t,jit_uint16_t);
#  define sti_d(i0,r0)			_sti_d(_jit,i0,r0)
static void _stxr_f(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#  define stxr_f(r0,r1,r2)		_stxr_f(_jit,r0,r1,r2)
static void _stxr_d(jit_state_t*,jit_uint16_t,jit_uint16_t,jit_uint16_t);
#  define stxr_d(r0,r1,r2)		_stxr_d(_jit,r0,r1,r2)
static void _stxi_f(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t);
#  define stxi_f(i0,r0,r1)		_stxi_f(_jit,i0,r0,r1)
static void _stxi_d(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t);
#  define stxi_d(i0,r0,r1)		_stxi_d(_jit,i0,r0,r1)
static jit_word_t _beqr_f(jit_state_t*,jit_word_t,jit_uint16_t,jit_uint16_t,jit_bool_t,jit_bool_t);
#  define beqr_f(i0,r0,r1)		_beqr_f(_jit,i0,r0,r1,0,1)
#  define beqr_d(i0,r0,r1)		_beqr_f(_jit,i0,r0,r1,1,1)
static jit_word_t _beqi_f(jit_state_t*,jit_word_t,jit_uint16_t,jit_float32_t,jit_bool_t);
#  define beqi_f(i0,r0,i1)		_beqi_f(_jit,i0,r0,i1,1)
static jit_word_t _beqi_d(jit_state_t*,jit_word_t,jit_uint16_t,jit_float64_t,jit_bool_t);
#  define beqi_d(i0,r0,i1)		_beqi_d(_jit,i0,r0,i1,1)
#  define bner_f(i0,r0,r1)		_beqr_f(_jit,i0,r0,r1,0,0)
#  define bner_d(i0,r0,r1)		_beqr_f(_jit,i0,r0,r1,1,0)
#  define bnei_f(i0,r0,i1)		_beqi_f(_jit,i0,r0,i1,0)
#  define bnei_d(i0,r0,i1)		_beqi_d(_jit,i0,r0,i1,0)
#  define bltr_f(i0, r0, r1)		bgtr_f(i0,r1,r0)
#  define bltr_d(i0, r0, r1)		bgtr_d(i0,r1,r0)
static jit_word_t
_blti_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define blti_f(i0, r0, i1)		_blti_f(_jit,i0,r0,i1)
static jit_word_t
_blti_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define blti_d(i0, r0, i1)		_blti_d(_jit,i0,r0,i1)
static jit_word_t _bgtr_f(jit_state_t*,jit_word_t,jit_int16_t,jit_int16_t,jit_bool_t,jit_bool_t);
#  define bgtr_f(i0, r0, r1)		_bgtr_f(_jit,i0,r0,r1,0,1)
#  define bgtr_d(i0, r0, r1)		_bgtr_f(_jit,i0,r0,r1,1,1)
static jit_word_t
_bgti_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define bgti_f(i0, r0, i1)		_bgti_f(_jit,i0,r0,i1)
static jit_word_t
_bgti_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define bgti_d(i0, r0, i1)		_bgti_d(_jit,i0,r0,i1)
static jit_word_t _bler_f(jit_state_t*,jit_word_t,jit_int16_t,jit_int16_t,jit_bool_t,jit_bool_t);
#  define bler_f(i0, r0, r1)		_bler_f(_jit,i0,r0,r1,0,0)
#  define bler_d(i0, r0, r1)		_bler_f(_jit,i0,r0,r1,1,0)
static jit_word_t
_blei_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define blei_f(i0, r0, i1)		_blei_f(_jit,i0,r0,i1)
static jit_word_t
_blei_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define blei_d(i0, r0, i1)		_blei_d(_jit,i0,r0,i1)
#  define bger_f(i0, r0, r1)		bler_f(i0,r1,r0)
#  define bger_d(i0, r0, r1)		bler_d(i0,r1,r0)
static jit_word_t
_bgei_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define bgei_f(i0, r0, i1)		_bgei_f(_jit,i0,r0,i1)
static jit_word_t
_bgei_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define bgei_d(i0, r0, i1)		_bgei_d(_jit,i0,r0,i1)
#  define bunltr_f(i0, r0, r1)		_bler_f(_jit,i0,r1,r0,0,1)
#  define bunltr_d(i0, r0, r1)		_bler_f(_jit,i0,r1,r0,1,1)
static jit_word_t
_bunlti_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define bunlti_f(i0, r0, i1)		_bunlti_f(_jit,i0,r0,i1)
static jit_word_t
_bunlti_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define bunlti_d(i0, r0, i1)		_bunlti_d(_jit,i0,r0,i1)
#  define bunler_f(i0, r0, r1)		_bgtr_f(_jit,i0,r0,r1,0,0)
#  define bunler_d(i0, r0, r1)		_bgtr_f(_jit,i0,r0,r1,1,0)
static jit_word_t
_bunlei_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define bunlei_f(i0, r0, i1)		_bunlei_f(_jit,i0,r0,i1)
static jit_word_t
_bunlei_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define bunlei_d(i0, r0, i1)		_bunlei_d(_jit,i0,r0,i1)
#  define bungtr_f(i0, r0, r1)		_bler_f(_jit,i0,r0,r1,0,1)
#  define bungtr_d(i0, r0, r1)		_bler_f(_jit,i0,r0,r1,1,1)
static jit_word_t
_bungti_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define bungti_f(i0, r0, i1)		_bungti_f(_jit,i0,r0,i1)
static jit_word_t
_bungti_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define bungti_d(i0, r0, i1)		_bungti_d(_jit,i0,r0,i1)
#  define bunger_f(i0, r0, r1)		_bgtr_f(_jit,i0,r1,r0,0,0)
#  define bunger_d(i0, r0, r1)		_bgtr_f(_jit,i0,r1,r0,1,0)
static jit_word_t
_bungei_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define bungei_f(i0, r0, i1)		_bungei_f(_jit,i0,r0,i1)
static jit_word_t
_bungei_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define bungei_d(i0, r0, i1)		_bungei_d(_jit,i0,r0,i1)
static jit_word_t _buneqr_f(jit_state_t*,jit_word_t,jit_int16_t,jit_int16_t,jit_bool_t);
#  define buneqr_f(i0, r0, r1)		_buneqr_f(_jit,i0,r1,r0,0)
#  define buneqr_d(i0, r0, r1)		_buneqr_f(_jit,i0,r1,r0,1)
static jit_word_t
_buneqi_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define buneqi_f(i0, r0, i1)		_buneqi_f(_jit,i0,r0,i1)
static jit_word_t
_buneqi_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define buneqi_d(i0, r0, i1)		_buneqi_d(_jit,i0,r0,i1)
static jit_word_t _bltgtr_f(jit_state_t*,jit_word_t,jit_int16_t,jit_int16_t,jit_bool_t);
#  define bltgtr_f(i0, r0, r1)		_bltgtr_f(_jit,i0,r1,r0,0)
#  define bltgtr_d(i0, r0, r1)		_bltgtr_f(_jit,i0,r1,r0,1)
static jit_word_t
_bltgti_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define bltgti_f(i0, r0, i1)		_bltgti_f(_jit,i0,r0,i1)
static jit_word_t
_bltgti_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define bltgti_d(i0, r0, i1)		_bltgti_d(_jit,i0,r0,i1)
static jit_word_t _bordr_f(jit_state_t*,jit_word_t,jit_int16_t,jit_int16_t,jit_bool_t,jit_bool_t);
#  define bordr_f(i0, r0, r1)		_bordr_f(_jit,i0,r0,r1,0,1)
#  define bordr_d(i0, r0, r1)		_bordr_f(_jit,i0,r0,r1,1,1)
static jit_word_t
_bordi_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define bordi_f(i0, r0, i1)		_bordi_f(_jit,i0,r0,i1)
static jit_word_t
_bordi_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define bordi_d(i0, r0, i1)		_bordi_d(_jit,i0,r0,i1)
#  define bunordr_f(i0, r0, r1)		_bordr_f(_jit,i0,r0,r1,0,0)
#  define bunordr_d(i0, r0, r1)		_bordr_f(_jit,i0,r0,r1,1,0)
static jit_word_t
_bunordi_f(jit_state_t*, jit_word_t, jit_int16_t, jit_float32_t);
#  define bunordi_f(i0, r0, i1)		_bunordi_f(_jit,i0,r0,i1)
static jit_word_t
_bunordi_d(jit_state_t*, jit_word_t, jit_int16_t, jit_float64_t);
#  define bunordi_d(i0, r0, i1)		_bunordi_d(_jit,i0,r0,i1)
#endif /* PROTO */

#define FLOAT_ONLY 1

#if CODE
static inline void set_fmode(jit_state_t *_jit, jit_bool_t is_double)
{
#if !FLOAT_ONLY
	jit_uint16_t reg;

	if (_jitc->mode_d ^ is_double) {
		reg = jit_get_reg(jit_class_gpr);

		_jitc->mode_d = is_double;

		movi(_R0, 0x1 << 19);
		STSFP(rn(reg));
		orr(rn(reg), rn(reg), _R0);
		if (!is_double)
			xorr(rn(reg), rn(reg), _R0);
		LDSFP(rn(reg));

		jit_unget_reg(reg);
	}
#endif
}

static void _extr_f(jit_state_t *_jit, jit_int16_t r0,
		    jit_int16_t r1, jit_bool_t is_double)
{
	set_fmode(_jit, is_double);

	LDS(r1);
	FLOAT(r0);
}

static void _truncr_f_i(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1,
			jit_bool_t is_double)
{
	set_fmode(_jit, is_double);

	FTRC(r1);
	STSUL(r0);
}

static void _movr_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	if (r0 != r1) {
		FMOV(r0, r1);
#ifdef __SH_FPU_DOUBLE__
		FMOV(r0 + 1, r1 + 1);
#endif
	}
}

static void _movr_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	if (r0 != r1) {
		FMOV(r0, r1);
#ifdef __SH_FPU_DOUBLE__
		FMOV(r0 + 1, r1 + 1);
#endif
	}
}

static void _movi_f(jit_state_t *_jit, jit_uint16_t r0, jit_float32_t i0)
{
#if defined(__SH_FPU_DOUBLE__)
	movi_d(r0, (jit_float64_t)i0);
#else
	union fl32 {
		jit_uint32_t i;
		jit_float32_t f;
	};

	set_fmode(_jit, 0);

	if (i0 == 0.0f) {
		FLDI0(r0);
	} else if (i0 == -0.0f) {
		FLDI0(r0);
		FNEG(r0);
	} else if (i0 == 1.0f) {
		FLDI1(r0);
	} else if (i0 == -1.0f) {
		FLDI1(r0);
		FNEG(r0);
	} else {
		movi(_R0, ((union fl32)i0).i);
		LDS(_R0);
		FSTS(r0);
	}
#endif
}

static void _movi_d(jit_state_t *_jit, jit_uint16_t r0, jit_float64_t i0)
{
#if !defined(__SH_FPU_DOUBLE__)
	movi_f(r0, (jit_float32_t)i0);
#else
	union fl64 {
		struct {
			jit_uint32_t hi;
			jit_uint32_t lo;
		};
		jit_float64_t f;
	};

	set_fmode(_jit, 1);

	movi(_R0, ((union fl64)i0).hi);
	LDS(_R0);
	FSTS(r0 + 1);
	movi(_R0, ((union fl64)i0).lo);
	LDS(_R0);
	FSTS(r0);
#endif
}

static void _ltr_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1,
		   jit_int16_t r2, jit_bool_t is_double)
{
	set_fmode(_jit, is_double);

	FCMPGT(r2, r1);
	MOVT(r0);
}

static void
_lti_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);
	movi_f(rn(reg), i0);

	ltr_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_lti_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	ltr_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void _ler_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1,
		   jit_int16_t r2, jit_bool_t is_double)
{
	set_fmode(_jit, is_double);

	FCMPGT(r2, r1);
	MOVT(r0);
	FCMPEQ(r1, r2);
	MOVT(_R0);
	orr(r0, _R0, r0);
}

static void
_lei_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);
	movi_f(rn(reg), i0);

	ler_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_lei_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	ler_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void _eqr_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1,
		   jit_int16_t r2, jit_bool_t is_double)
{
	set_fmode(_jit, is_double);

	FCMPEQ(r1, r2);
	MOVT(r0);
}

static void
_eqi_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i0);
	eqr_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_eqi_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	eqr_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_gei_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);
	movi_f(rn(reg), i0);

	ler_f(r0, rn(reg), r1);

	jit_unget_reg(reg);
}

static void
_gei_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	ler_d(r0, rn(reg), r1);

	jit_unget_reg(reg);
}

static void
_gti_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);
	movi_f(rn(reg), i0);

	ltr_f(r0, rn(reg), r1);

	jit_unget_reg(reg);
}

static void
_gti_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	ltr_d(r0, rn(reg), r1);

	jit_unget_reg(reg);
}

static void
_ner_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	eqr_f(_R0, r1, r2);
	XORI(1);
	movr(r0, _R0);
}

static void
_ner_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	eqr_d(_R0, r1, r2);
	XORI(1);
	movr(r0, _R0);
}

static void
_nei_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);
	movi_f(rn(reg), i0);

	ner_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_nei_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	ner_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_unltr_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	ltr_f(_R0, r1, r2);
	XORI(1);
	movr(r0, _R0);
}

static void
_unltr_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	ltr_d(_R0, r1, r2);
	XORI(1);
	movr(r0, _R0);
}

static void
_unlti_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i0);
	unltr_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_unlti_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	unltr_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_unler_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	ler_f(_R0, r1, r2);
	XORI(1);
	movr(r0, _R0);
}

static void
_unler_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	ler_d(_R0, r1, r2);
	XORI(1);
	movr(r0, _R0);
}

static void
_unlei_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);
	movi_f(rn(reg), i0);

	unler_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_unlei_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	unler_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_ungtr_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	gtr_f(_R0, r1, r2);
	XORI(1);
	movr(r0, _R0);
}

static void
_ungtr_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	gtr_d(_R0, r1, r2);
	XORI(1);
	movr(r0, _R0);
}

static void
_ungti_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i0);
	ungtr_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_ungti_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	ungtr_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_unger_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	ger_f(_R0, r1, r2);
	XORI(1);
	movr(r0, _R0);
}

static void
_unger_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	ger_d(_R0, r1, r2);
	XORI(1);
	movr(r0, _R0);
}

static void
_ungei_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i0);
	unger_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_ungei_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	unger_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_uneqr_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	unger_f(rn(reg), r1, r2);
	unler_f(r0, r1, r2);
	andr(r0, r0, rn(reg));

	jit_unget_reg(reg);
}

static void
_uneqr_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	unger_d(rn(reg), r1, r2);
	unler_d(r0, r1, r2);
	andr(r0, r0, rn(reg));

	jit_unget_reg(reg);
}

static void
_uneqi_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);
	movi_f(rn(reg), i0);

	uneqr_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_uneqi_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	uneqr_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_ltgtr_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	ungtr_f(rn(reg), r1, r2);
	unltr_f(r0, r1, r2);
	orr(r0, r0, rn(reg));

	jit_unget_reg(reg);
}

static void
_ltgtr_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	ungtr_d(rn(reg), r1, r2);
	unltr_d(r0, r1, r2);
	orr(r0, r0, rn(reg));

	jit_unget_reg(reg);
}

static void
_ltgti_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);
	movi_f(rn(reg), i0);

	ltgtr_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_ltgti_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	ltgtr_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_ordr_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	eqr_f(rn(reg), r1, r1);
	eqr_f(r0, r2, r2);
	andr(r0, r0, rn(reg));

	jit_unget_reg(reg);
}

static void
_ordr_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	eqr_d(rn(reg), r1, r1);
	eqr_d(r0, r2, r2);
	andr(r0, r0, rn(reg));

	jit_unget_reg(reg);
}

static void
_ordi_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);
	movi_f(rn(reg), i0);

	ordr_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_ordi_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	ordr_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_unordr_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	ner_f(rn(reg), r1, r1);
	ner_f(r0, r2, r2);
	orr(r0, r0, rn(reg));

	jit_unget_reg(reg);
}

static void
_unordr_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_int16_t r2)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	ner_d(rn(reg), r1, r1);
	ner_d(r0, r2, r2);
	orr(r0, r0, rn(reg));

	jit_unget_reg(reg);
}

static void
_unordi_f(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);
	movi_f(rn(reg), i0);

	unordr_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_unordi_d(jit_state_t *_jit, jit_int16_t r0, jit_int16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	unordr_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_addr_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
	jit_uint16_t r2, jit_bool_t is_double)
{
	set_fmode(_jit, is_double);

	if (r0 == r2) {
		FADD(r0, r1);
	} else {
		if (is_double)
			movr_d(r0, r1);
		else
			movr_f(r0, r1);
		FADD(r0, r2);
	}
}

static void
_addi_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	set_fmode(_jit, 0);

	if (r0 == r1) {
		reg = jit_get_reg(jit_class_fpr);

		movi_f(rn(reg), i0);
		FADD(r0, rn(reg));

		jit_unget_reg(reg);
	} else {
		movi_f(r0, i0);
		FADD(r0, r1);
	}
}

static void _addi_d(jit_state_t *_jit, jit_uint16_t r0,
		    jit_uint16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	set_fmode(_jit, 1);

	if (r0 == r1) {
		reg = jit_get_reg(jit_class_fpr);

		movi_d(rn(reg), i0);
		FADD(r0, rn(reg));

		jit_unget_reg(reg);
	} else {
		movi_d(r0, i0);
		FADD(r0, r1);
	}
}

static void
_subr_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	jit_uint16_t reg;

	set_fmode(_jit, 0);

	if (r1 == r2) {
		movi_f(r0, 0.0f);
	} else if (r0 == r2) {
		FNEG(r0);
		FADD(r0, r1);
	} else {
		movr_f(r0, r1);
		FSUB(r0, r2);
	}
}

static void
_subr_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	jit_uint16_t reg;

	set_fmode(_jit, 1);

	if (r1 == r2) {
		movi_d(r0, 0.0);
	} else if (r0 == r2) {
		FNEG(r0);
		FADD(r0, r1);
	} else {
		movr_d(r0, r1);
		FSUB(r0, r2);
	}
}

static void
_subi_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	set_fmode(_jit, 0);

	if (r0 == r1) {
		reg = jit_get_reg(jit_class_fpr);

		movi_f(rn(reg), i0);
		FSUB(r0, rn(reg));

		jit_unget_reg(reg);
	} else {
		movi_f(r0, -i0);
		FADD(r0, r1);
	}
}

static void
_subi_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	set_fmode(_jit, 1);

	if (r0 == r1) {
		reg = jit_get_reg(jit_class_fpr);

		movi_d(rn(reg), i0);
		FSUB(r0, rn(reg));

		jit_unget_reg(reg);
	} else {
		movi_d(r0, -i0);
		FADD(r0, r1);
	}
}

static void
_rsbi_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	set_fmode(_jit, 0);

	if (r0 == r1) {
		reg = jit_get_reg(jit_class_fpr);

		movi_f(rn(reg), i0);
		subr_f(r0, rn(reg), r0);

		jit_unget_reg(reg);
	} else {
		movi_f(r0, i0);
		FSUB(r0, r1);
	}
}

static void
_rsbi_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	set_fmode(_jit, 1);

	if (r0 == r1) {
		reg = jit_get_reg(jit_class_fpr);

		movi_d(rn(reg), i0);
		subr_d(r0, rn(reg), r0);

		jit_unget_reg(reg);
	} else {
		movi_d(r0, i0);
		FSUB(r0, r1);
	}
}

static void
_mulr_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	set_fmode(_jit, 0);

	if (r0 == r2) {
		FMUL(r0, r1);
	} else {
		movr_f(r0, r1);
		FMUL(r0, r2);
	}
}

static void
_muli_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	if (r0 == r1) {
		reg = jit_get_reg(jit_class_fpr);

		movi_f(rn(reg), i0);
		mulr_f(r0, r1, rn(reg));

		jit_unget_reg(reg);
	} else {
		movi_f(r0, i0);
		mulr_f(r0, r0, r1);
	}
}

static void
_mulr_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	set_fmode(_jit, 1);

	if (r0 == r2) {
		FMUL(r0, r1);
	} else {
		movr_d(r0, r1);
		FMUL(r0, r2);
	}
}

static void
_muli_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	if (r0 == r1) {
		reg = jit_get_reg(jit_class_fpr);

		movi_d(rn(reg), i0);
		mulr_d(r0, r1, rn(reg));

		jit_unget_reg(reg);
	} else {
		movi_d(r0, i0);
		mulr_d(r0, r0, r1);
	}
}

static void
_divr_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	jit_uint16_t reg;

	set_fmode(_jit, 0);

	if (r0 == r2) {
		reg = jit_get_reg(jit_class_fpr);

		movr_f(rn(reg), r2);
		movr_f(r0, r1);
		FDIV(r0, rn(reg));

		jit_unget_reg(reg);
	} else {
		movr_f(r0, r1);
		FDIV(r0, r2);
	}
}

static void
_divi_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_float32_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i0);
	divr_f(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void
_divr_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_uint16_t r2)
{
	jit_uint16_t reg;

	set_fmode(_jit, 1);

	if (r0 == r2) {
		reg = jit_get_reg(jit_class_fpr);

		movr_d(rn(reg), r2);
		movr_d(r0, r1);
		FDIV(r0, rn(reg));

		jit_unget_reg(reg);
	} else {
		movr_d(r0, r1);
		FDIV(r0, r2);
	}
}

static void
_divi_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1, jit_float64_t i0)
{
	jit_uint16_t reg;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i0);
	divr_d(r0, r1, rn(reg));

	jit_unget_reg(reg);
}

static void _absr_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	set_fmode(_jit, 0);

	movr_f(r0, r1);
	FABS(r0);
}

static void _absr_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	set_fmode(_jit, 1);

	movr_d(r0, r1);
	FABS(r0);
}

static void _sqrtr_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	set_fmode(_jit, 0);

	movr_f(r0, r1);
	FSQRT(r0);
}

static void _sqrtr_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	set_fmode(_jit, 1);

	movr_d(r0, r1);
	FSQRT(r0);
}

static void _negr_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	set_fmode(_jit, 0);

	movr_f(r0, r1);
	FNEG(r0);
}

static void _negr_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	set_fmode(_jit, 1);

	movr_d(r0, r1);
	FNEG(r0);
}

static void _extr_d_f(jit_state_t *_jit,jit_uint16_t r0, jit_uint16_t r1)
{
#if !defined(__SH_FPU_DOUBLE__)
	movr_f(r0, r1);
#else
	movr_d(r0, r1);
	/*
	set_fmode(_jit, 1);
	FCNVDS(r1);
	set_fmode(_jit, 0);
	FSTS(r0);
	*/
#endif
}

static void _extr_f_d(jit_state_t *_jit,jit_uint16_t r0, jit_uint16_t r1)
{
#if !defined(__SH_FPU_DOUBLE__)
	movr_f(r0, r1);
#else
	movr_d(r0, r1);
	/*
	set_fmode(_jit, 0);
	FLDS(r1);
	set_fmode(_jit, 1);
	FCNVSD(r0);
	*/
#endif
}

static void _ldr_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	movr(_R0, r1);
	LDFS(r0 + 1, _R0);
	LDF(r0, _R0);
}

static void _ldi_f(jit_state_t *_jit, jit_uint16_t r0, jit_word_t i0)
{
	movi(_R0, i0);
	ldr_f(r0, _R0);
}

static void _ldi_d(jit_state_t *_jit, jit_uint16_t r0, jit_word_t i0)
{
	movi(_R0, i0);
	ldr_d(r0, _R0);
}

static void _ldxr_f(jit_state_t *_jit, jit_uint16_t r0,
		    jit_uint16_t r1, jit_uint16_t r2)
{
	movr(_R0, r2);
	LDXF(r0, r1);
}

static void _ldxr_d(jit_state_t *_jit, jit_uint16_t r0,
		    jit_uint16_t r1, jit_uint16_t r2)
{
	addr(_R0, r1, r2);
	ldr_d(r0, _R0);
}

static void _ldxi_f(jit_state_t *_jit, jit_uint16_t r0,
		    jit_uint16_t r1, jit_word_t i0)
{
	movi(_R0, i0);
	ldxr_f(r0, r1, _R0);
}

static void _ldxi_d(jit_state_t *_jit, jit_uint16_t r0,
		    jit_uint16_t r1, jit_word_t i0)
{
	movi(_R0, i0);
	ldxr_d(r0, r1, _R0);
}

static void _str_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1)
{
	STF(r0, r1 + 1);
	movi(_R0, 4);
	STXF(r0, r1);
}

static void _sti_f(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0)
{
	movi(_R0, i0);
	STF(_R0, r0);
}

static void _sti_d(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0)
{
	movi(_R0, i0 + 8);
	STFS(_R0, r0);
	STFS(_R0, r0 + 1);
}

static void _stxr_f(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
		    jit_uint16_t r2)
{
	movr(_R0, r0);
	STXF(r1, r2);
}

static void _stxr_d(jit_state_t *_jit, jit_uint16_t r0, jit_uint16_t r1,
		    jit_uint16_t r2)
{
	movr(_R0, r0);
	STXF(r1, r2 + 1);
	addr(_R0, _R0, 4);
	STXF(r1, r2);
}

static void _stxi_f(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
		    jit_uint16_t r1)
{
	movr(_R0, i0);
	stxr_f(_R0, r0, r1);
}

static void _stxi_d(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
		    jit_uint16_t r1)
{
	movr(_R0, i0);
	stxr_d(_R0, r0, r1);
}

static jit_word_t _beqr_f(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			  jit_uint16_t r1, jit_bool_t is_double, jit_bool_t set)
{
	jit_word_t w;

	set_fmode(_jit, is_double);

	FCMPEQ(r0, r1);
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t _beqi_f(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			  jit_float32_t i1, jit_bool_t set)
{
	jit_word_t w;
	jit_uint16_t reg;

	set_fmode(_jit, 0);

	reg = jit_get_reg(jit_class_fpr);
	movi_f(rn(reg), i1);

	FCMPEQ(r0, rn(reg));
	jit_unget_reg(reg);

	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t _beqi_d(jit_state_t *_jit, jit_word_t i0, jit_uint16_t r0,
			  jit_float64_t i1, jit_bool_t set)
{
	jit_word_t w;
	jit_uint16_t reg;

	set_fmode(_jit, 1);

	reg = jit_get_reg(jit_class_fpr);
	movi_d(rn(reg), i1);

	FCMPEQ(r0, rn(reg));
	jit_unget_reg(reg);

	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t _bgtr_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0,
			  jit_int16_t r1, jit_bool_t is_double, jit_bool_t set)
{
	jit_word_t w;

	set_fmode(_jit, is_double);

	FCMPGT(r0, r1);
	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t
_blti_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = bltr_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_blti_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = bltr_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bgti_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = bgtr_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bgti_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = bgtr_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t _bler_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0,
			  jit_int16_t r1, jit_bool_t is_double, jit_bool_t set)
{
	jit_word_t w;

	set_fmode(_jit, is_double);

	FCMPGT(r1, r0);
	MOVT(_R0);
	FCMPEQ(r0, r1);
	ROTCL(_R0);
	TSTI(3);

	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t
_blei_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = bler_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_blei_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = bler_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bgei_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = bger_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bgei_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = bger_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t _buneqr_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0,
			    jit_int16_t r1, jit_bool_t is_double)
{
	jit_word_t w;

	set_fmode(_jit, is_double);

	FCMPGT(r0, r1);
	MOVT(_R0);
	FCMPGT(r1, r0);
	ROTCL(_R0);
	TSTI(3);

	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, 1);

	return (w);
}

static jit_word_t _bltgtr_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0,
			    jit_int16_t r1, jit_bool_t is_double)
{
	jit_word_t w;

	set_fmode(_jit, is_double);

	FCMPGT(r0, r1);
	MOVT(_R0);
	FCMPGT(r1, r0);
	ROTCL(_R0);
	XORI(3);
	TSTI(3);
	MOVT(_R0);
	FCMPEQ(r0, r1);
	ROTCL(_R0);
	TSTI(3);

	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, 0);

	return (w);
}

static jit_word_t _bordr_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0,
			   jit_int16_t r1, jit_bool_t is_double, jit_bool_t set)
{
	jit_word_t w;

	set_fmode(_jit, is_double);

	FCMPEQ(r0, r0);
	MOVT(_R0);
	FCMPEQ(r1, r1);
	ROTCL(_R0);
	XORI(3);
	TSTI(3);

	w = _jit->pc.w;
	emit_branch_opcode(_jit, i0, w, set);

	return (w);
}

static jit_word_t
_bunlti_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = bunltr_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bunlti_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = bunltr_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bunlei_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = bunler_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bunlei_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = bunler_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bungti_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = bungtr_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bungti_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = bungtr_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bungei_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = bunger_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bungei_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = bunger_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_buneqi_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = buneqr_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_buneqi_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = buneqr_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bltgti_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = bltgtr_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bltgti_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = bltgtr_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bordi_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = bordr_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bordi_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = bordr_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bunordi_f(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float32_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_f(rn(reg), i1);
	w = bunordr_f(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

static jit_word_t
_bunordi_d(jit_state_t *_jit, jit_word_t i0, jit_int16_t r0, jit_float64_t i1)
{
	jit_uint16_t reg;
	jit_word_t w;

	reg = jit_get_reg(jit_class_fpr);

	movi_d(rn(reg), i1);
	w = bunordr_d(i0, r0, rn(reg));

	jit_unget_reg(reg);

	return w;
}

#endif /* CODE */
