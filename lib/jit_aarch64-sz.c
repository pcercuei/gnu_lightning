
#if __WORDSIZE == 64
#  if PACKED_STACK
#define JIT_INSTR_MAX 96
    0,	/* data */
    0,	/* live */
    4,	/* align */
    0,	/* save */
    0,	/* load */
    4,	/* skip */
    0,	/* #name */
    0,	/* #note */
    0,	/* label */
    96,	/* prolog */
    0,	/* ellipsis */
    0,	/* va_push */
    0,	/* allocai */
    0,	/* allocar */
    0,	/* arg_c */
    0,	/* arg_s */
    0,	/* arg_i */
    0,	/* arg_l */
    0,	/* getarg_c */
    0,	/* getarg_uc */
    0,	/* getarg_s */
    0,	/* getarg_us */
    0,	/* getarg_i */
    0,	/* getarg_ui */
    0,	/* getarg_l */
    0,	/* putargr_c */
    0,	/* putargi_c */
    0,	/* putargr_uc */
    0,	/* putargi_uc */
    0,	/* putargr_s */
    0,	/* putargi_s */
    0,	/* putargr_us */
    0,	/* putargi_us */
    0,	/* putargr_i */
    0,	/* putargi_i */
    0,	/* putargr_ui */
    0,	/* putargi_ui */
    0,	/* putargr_l */
    0,	/* putargi_l */
    4,	/* va_start */
    8,	/* va_arg */
    12,	/* va_arg_d */
    0,	/* va_end */
    4,	/* addr */
    20,	/* addi */
    4,	/* addcr */
    12,	/* addci */
    4,	/* addxr */
    8,	/* addxi */
    4,	/* subr */
    20,	/* subi */
    4,	/* subcr */
    12,	/* subci */
    4,	/* subxr */
    8,	/* subxi */
    24,	/* rsbi */
    4,	/* mulr */
    20,	/* muli */
    12,	/* qmulr */
    20,	/* qmuli */
    12,	/* qmulr_u */
    20,	/* qmuli_u */
    4,	/* divr */
    20,	/* divi */
    4,	/* divr_u */
    12,	/* divi_u */
    20,	/* qdivr */
    16,	/* qdivi */
    20,	/* qdivr_u */
    16,	/* qdivi_u */
    12,	/* remr */
    28,	/* remi */
    12,	/* remr_u */
    20,	/* remi_u */
    4,	/* andr */
    4,	/* andi */
    4,	/* orr */
    4,	/* ori */
    4,	/* xorr */
    4,	/* xori */
    4,	/* lshr */
    4,	/* lshi */
    4,	/* rshr */
    4,	/* rshi */
    4,	/* rshr_u */
    4,	/* rshi_u */
    4,	/* negr */
    4,	/* comr */
    8,	/* ltr */
    8,	/* lti */
    8,	/* ltr_u */
    8,	/* lti_u */
    8,	/* ler */
    8,	/* lei */
    8,	/* ler_u */
    8,	/* lei_u */
    8,	/* eqr */
    8,	/* eqi */
    8,	/* ger */
    8,	/* gei */
    8,	/* ger_u */
    8,	/* gei_u */
    8,	/* gtr */
    8,	/* gti */
    8,	/* gtr_u */
    8,	/* gti_u */
    8,	/* ner */
    8,	/* nei */
    4,	/* movr */
    16,	/* movi */
    8,	/* movnr */
    8,	/* movzr */
    28,	/* casr */
    40,	/* casi */
    4,	/* extr_c */
    4,	/* extr_uc */
    4,	/* extr_s */
    4,	/* extr_us */
    4,	/* extr_i */
    4,	/* extr_ui */
    8,	/* bswapr_us */
    8,	/* bswapr_ui */
    4,	/* bswapr_ul */
    8,	/* htonr_us */
    8,	/* htonr_ui */
    4,	/* htonr_ul */
    4,	/* ldr_c */
    16,	/* ldi_c */
    4,	/* ldr_uc */
    16,	/* ldi_uc */
    4,	/* ldr_s */
    16,	/* ldi_s */
    4,	/* ldr_us */
    16,	/* ldi_us */
    4,	/* ldr_i */
    16,	/* ldi_i */
    4,	/* ldr_ui */
    16,	/* ldi_ui */
    4,	/* ldr_l */
    16,	/* ldi_l */
    8,	/* ldxr_c */
    20,	/* ldxi_c */
    4,	/* ldxr_uc */
    20,	/* ldxi_uc */
    4,	/* ldxr_s */
    16,	/* ldxi_s */
    4,	/* ldxr_us */
    16,	/* ldxi_us */
    4,	/* ldxr_i */
    20,	/* ldxi_i */
    4,	/* ldxr_ui */
    16,	/* ldxi_ui */
    4,	/* ldxr_l */
    20,	/* ldxi_l */
    4,	/* str_c */
    16,	/* sti_c */
    4,	/* str_s */
    16,	/* sti_s */
    4,	/* str_i */
    16,	/* sti_i */
    4,	/* str_l */
    16,	/* sti_l */
    4,	/* stxr_c */
    20,	/* stxi_c */
    4,	/* stxr_s */
    20,	/* stxi_s */
    4,	/* stxr_i */
    20,	/* stxi_i */
    4,	/* stxr_l */
    20,	/* stxi_l */
    8,	/* bltr */
    8,	/* blti */
    8,	/* bltr_u */
    8,	/* blti_u */
    8,	/* bler */
    8,	/* blei */
    8,	/* bler_u */
    8,	/* blei_u */
    8,	/* beqr */
    24,	/* beqi */
    8,	/* bger */
    8,	/* bgei */
    8,	/* bger_u */
    8,	/* bgei_u */
    8,	/* bgtr */
    8,	/* bgti */
    8,	/* bgtr_u */
    8,	/* bgti_u */
    8,	/* bner */
    24,	/* bnei */
    8,	/* bmsr */
    8,	/* bmsi */
    8,	/* bmcr */
    8,	/* bmci */
    8,	/* boaddr */
    8,	/* boaddi */
    8,	/* boaddr_u */
    8,	/* boaddi_u */
    8,	/* bxaddr */
    8,	/* bxaddi */
    8,	/* bxaddr_u */
    8,	/* bxaddi_u */
    8,	/* bosubr */
    8,	/* bosubi */
    8,	/* bosubr_u */
    8,	/* bosubi_u */
    8,	/* bxsubr */
    8,	/* bxsubi */
    8,	/* bxsubr_u */
    8,	/* bxsubi_u */
    4,	/* jmpr */
    4,	/* jmpi */
    4,	/* callr */
    16,	/* calli */
    0,	/* prepare */
    0,	/* pushargr_c */
    0,	/* pushargi_c */
    0,	/* pushargr_uc */
    0,	/* pushargi_uc */
    0,	/* pushargr_s */
    0,	/* pushargi_s */
    0,	/* pushargr_us */
    0,	/* pushargi_us */
    0,	/* pushargr_i */
    0,	/* pushargi_i */
    0,	/* pushargr_ui */
    0,	/* pushargi_ui */
    0,	/* pushargr_l */
    0,	/* pushargi_l */
    0,	/* finishr */
    0,	/* finishi */
    0,	/* ret */
    0,	/* retr_c */
    0,	/* reti_c */
    0,	/* retr_uc */
    0,	/* reti_uc */
    0,	/* retr_s */
    0,	/* reti_s */
    0,	/* retr_us */
    0,	/* reti_us */
    0,	/* retr_i */
    0,	/* reti_i */
    0,	/* retr_ui */
    0,	/* reti_ui */
    0,	/* retr_l */
    0,	/* reti_l */
    0,	/* retval_c */
    0,	/* retval_uc */
    0,	/* retval_s */
    0,	/* retval_us */
    0,	/* retval_i */
    0,	/* retval_ui */
    0,	/* retval_l */
    96,	/* epilog */
    0,	/* arg_f */
    0,	/* getarg_f */
    0,	/* putargr_f */
    0,	/* putargi_f */
    4,	/* addr_f */
    12,	/* addi_f */
    4,	/* subr_f */
    12,	/* subi_f */
    12,	/* rsbi_f */
    4,	/* mulr_f */
    12,	/* muli_f */
    4,	/* divr_f */
    12,	/* divi_f */
    4,	/* negr_f */
    4,	/* absr_f */
    4,	/* sqrtr_f */
    8,	/* ltr_f */
    16,	/* lti_f */
    8,	/* ler_f */
    16,	/* lei_f */
    8,	/* eqr_f */
    16,	/* eqi_f */
    8,	/* ger_f */
    16,	/* gei_f */
    8,	/* gtr_f */
    16,	/* gti_f */
    8,	/* ner_f */
    16,	/* nei_f */
    8,	/* unltr_f */
    16,	/* unlti_f */
    8,	/* unler_f */
    16,	/* unlei_f */
    16,	/* uneqr_f */
    24,	/* uneqi_f */
    8,	/* unger_f */
    16,	/* ungei_f */
    8,	/* ungtr_f */
    16,	/* ungti_f */
    16,	/* ltgtr_f */
    24,	/* ltgti_f */
    8,	/* ordr_f */
    16,	/* ordi_f */
    8,	/* unordr_f */
    16,	/* unordi_f */
    8,	/* truncr_f_i */
    4,	/* truncr_f_l */
    4,	/* extr_f */
    4,	/* extr_d_f */
    4,	/* movr_f */
    8,	/* movi_f */
    8,	/* ldr_f */
    20,	/* ldi_f */
    8,	/* ldxr_f */
    24,	/* ldxi_f */
    8,	/* str_f */
    20,	/* sti_f */
    8,	/* stxr_f */
    24,	/* stxi_f */
    8,	/* bltr_f */
    16,	/* blti_f */
    8,	/* bler_f */
    16,	/* blei_f */
    8,	/* beqr_f */
    16,	/* beqi_f */
    8,	/* bger_f */
    16,	/* bgei_f */
    8,	/* bgtr_f */
    16,	/* bgti_f */
    8,	/* bner_f */
    16,	/* bnei_f */
    8,	/* bunltr_f */
    16,	/* bunlti_f */
    8,	/* bunler_f */
    16,	/* bunlei_f */
    16,	/* buneqr_f */
    24,	/* buneqi_f */
    8,	/* bunger_f */
    16,	/* bungei_f */
    8,	/* bungtr_f */
    16,	/* bungti_f */
    16,	/* bltgtr_f */
    24,	/* bltgti_f */
    8,	/* bordr_f */
    16,	/* bordi_f */
    8,	/* bunordr_f */
    16,	/* bunordi_f */
    0,	/* pushargr_f */
    0,	/* pushargi_f */
    0,	/* retr_f */
    0,	/* reti_f */
    0,	/* retval_f */
    0,	/* arg_d */
    0,	/* getarg_d */
    0,	/* putargr_d */
    0,	/* putargi_d */
    4,	/* addr_d */
    12,	/* addi_d */
    4,	/* subr_d */
    12,	/* subi_d */
    12,	/* rsbi_d */
    4,	/* mulr_d */
    12,	/* muli_d */
    4,	/* divr_d */
    12,	/* divi_d */
    4,	/* negr_d */
    4,	/* absr_d */
    4,	/* sqrtr_d */
    8,	/* ltr_d */
    16,	/* lti_d */
    8,	/* ler_d */
    16,	/* lei_d */
    8,	/* eqr_d */
    16,	/* eqi_d */
    8,	/* ger_d */
    16,	/* gei_d */
    8,	/* gtr_d */
    16,	/* gti_d */
    8,	/* ner_d */
    16,	/* nei_d */
    8,	/* unltr_d */
    16,	/* unlti_d */
    8,	/* unler_d */
    16,	/* unlei_d */
    16,	/* uneqr_d */
    24,	/* uneqi_d */
    8,	/* unger_d */
    16,	/* ungei_d */
    8,	/* ungtr_d */
    16,	/* ungti_d */
    16,	/* ltgtr_d */
    24,	/* ltgti_d */
    8,	/* ordr_d */
    16,	/* ordi_d */
    8,	/* unordr_d */
    16,	/* unordi_d */
    8,	/* truncr_d_i */
    4,	/* truncr_d_l */
    4,	/* extr_d */
    4,	/* extr_f_d */
    4,	/* movr_d */
    12,	/* movi_d */
    8,	/* ldr_d */
    20,	/* ldi_d */
    8,	/* ldxr_d */
    24,	/* ldxi_d */
    8,	/* str_d */
    20,	/* sti_d */
    8,	/* stxr_d */
    24,	/* stxi_d */
    8,	/* bltr_d */
    16,	/* blti_d */
    8,	/* bler_d */
    16,	/* blei_d */
    8,	/* beqr_d */
    20,	/* beqi_d */
    8,	/* bger_d */
    16,	/* bgei_d */
    8,	/* bgtr_d */
    16,	/* bgti_d */
    8,	/* bner_d */
    16,	/* bnei_d */
    8,	/* bunltr_d */
    16,	/* bunlti_d */
    8,	/* bunler_d */
    16,	/* bunlei_d */
    16,	/* buneqr_d */
    24,	/* buneqi_d */
    8,	/* bunger_d */
    16,	/* bungei_d */
    8,	/* bungtr_d */
    16,	/* bungti_d */
    16,	/* bltgtr_d */
    24,	/* bltgti_d */
    8,	/* bordr_d */
    16,	/* bordi_d */
    8,	/* bunordr_d */
    16,	/* bunordi_d */
    0,	/* pushargr_d */
    0,	/* pushargi_d */
    0,	/* retr_d */
    0,	/* reti_d */
    0,	/* retval_d */
    0,	/* movr_w_f */
    0,	/* movr_ww_d */
    0,	/* movr_w_d */
    0,	/* movr_f_w */
    0,	/* movi_f_w */
    0,	/* movr_d_ww */
    0,	/* movi_d_ww */
    0,	/* movr_d_w */
    0,	/* movi_d_w */
    8,	/* clor */
    4,	/* clzr */
    12,	/* ctor */
    8,	/* ctzr */
    4,	/* rbitr */
    16,	/* popcntr */
    12,	/* lrotr */
    4,	/* lroti */
    4,	/* rrotr */
    4,	/* rroti */
    4,	/* extr */
    4,	/* extr_u */
    4,	/* depr */
    8,	/* depi */
    4,	/* negi */
    4,	/* comi */
    4,	/* exti_c */
    4,	/* exti_uc */
    4,	/* exti_s */
    4,	/* exti_us */
    12, /* exti_i */
    4,	/* exti_ui */
    4,	/* bswapi_us */
    8,	/* bswapi_ui */
    16, /* bswapi_ul */
    4,	/* htoni_us */
    8,	/* htoni_ui */
    16, /* htoni_ul */
    0,	/* negi_f */
    0,	/* absi_f */
    0,	/* sqrti_f */
    0,	/* negi_d */
    0,	/* absi_d */
    0,	/* sqrti_d */
    4,	/* cloi */
    4,	/* clzi */
    4,	/* ctoi */
    4,	/* ctzi */
    16, /* rbiti */
    4,	/* popcnti */
    4,	/* exti */
    4,	/* exti_u */
    56, /* qlshr */
    8,	/* qlshi */
    52, /* qlshr_u */
    8,	/* qlshi_u */
    52, /* qrshr */
    8,	/* qrshi */
    52, /* qrshr_u */
    8,	/* qrshi_u */

#  else	/* PACKED_STACK */
#define JIT_INSTR_MAX 120
    0,	/* data */
    0,	/* live */
    12,	/* align */
    0,	/* save */
    0,	/* load */
    4,	/* skip */
    0,	/* #name */
    0,	/* #note */
    0,	/* label */
    120,	/* prolog */
    0,	/* ellipsis */
    0,	/* va_push */
    0,	/* allocai */
    0,	/* allocar */
    0,	/* arg_c */
    0,	/* arg_s */
    0,	/* arg_i */
    0,	/* arg_l */
    0,	/* getarg_c */
    0,	/* getarg_uc */
    0,	/* getarg_s */
    0,	/* getarg_us */
    0,	/* getarg_i */
    0,	/* getarg_ui */
    0,	/* getarg_l */
    0,	/* putargr_c */
    0,	/* putargi_c */
    0,	/* putargr_uc */
    0,	/* putargi_uc */
    0,	/* putargr_s */
    0,	/* putargi_s */
    0,	/* putargr_us */
    0,	/* putargi_us */
    0,	/* putargr_i */
    0,	/* putargi_i */
    0,	/* putargr_ui */
    0,	/* putargi_ui */
    0,	/* putargr_l */
    0,	/* putargi_l */
    44,	/* va_start */
    48,	/* va_arg */
    56,	/* va_arg_d */
    0,	/* va_end */
    4,	/* addr */
    20,	/* addi */
    4,	/* addcr */
    12,	/* addci */
    4,	/* addxr */
    8,	/* addxi */
    4,	/* subr */
    20,	/* subi */
    4,	/* subcr */
    12,	/* subci */
    4,	/* subxr */
    8,	/* subxi */
    24,	/* rsbi */
    4,	/* mulr */
    20,	/* muli */
    12,	/* qmulr */
    20,	/* qmuli */
    12,	/* qmulr_u */
    20,	/* qmuli_u */
    4,	/* divr */
    20,	/* divi */
    4,	/* divr_u */
    12,	/* divi_u */
    20,	/* qdivr */
    16,	/* qdivi */
    20,	/* qdivr_u */
    16,	/* qdivi_u */
    12,	/* remr */
    28,	/* remi */
    12,	/* remr_u */
    20,	/* remi_u */
    4,	/* andr */
    4,	/* andi */
    4,	/* orr */
    4,	/* ori */
    4,	/* xorr */
    4,	/* xori */
    4,	/* lshr */
    4,	/* lshi */
    4,	/* rshr */
    4,	/* rshi */
    4,	/* rshr_u */
    4,	/* rshi_u */
    4,	/* negr */
    4,	/* comr */
    8,	/* ltr */
    8,	/* lti */
    8,	/* ltr_u */
    8,	/* lti_u */
    8,	/* ler */
    8,	/* lei */
    8,	/* ler_u */
    8,	/* lei_u */
    8,	/* eqr */
    8,	/* eqi */
    8,	/* ger */
    8,	/* gei */
    8,	/* ger_u */
    8,	/* gei_u */
    8,	/* gtr */
    8,	/* gti */
    8,	/* gtr_u */
    8,	/* gti_u */
    8,	/* ner */
    8,	/* nei */
    4,	/* movr */
    16,	/* movi */
    8,	/* movnr */
    8,	/* movzr */
    28,	/* casr */
    36,	/* casi */
    4,	/* extr_c */
    4,	/* extr_uc */
    4,	/* extr_s */
    4,	/* extr_us */
    4,	/* extr_i */
    4,	/* extr_ui */
    8,	/* bswapr_us */
    8,	/* bswapr_ui */
    4,	/* bswapr_ul */
    8,	/* htonr_us */
    8,	/* htonr_ui */
    4,	/* htonr_ul */
    4,	/* ldr_c */
    12,	/* ldi_c */
    4,	/* ldr_uc */
    16,	/* ldi_uc */
    4,	/* ldr_s */
    16,	/* ldi_s */
    4,	/* ldr_us */
    16,	/* ldi_us */
    4,	/* ldr_i */
    16,	/* ldi_i */
    4,	/* ldr_ui */
    16,	/* ldi_ui */
    4,	/* ldr_l */
    16,	/* ldi_l */
    8,	/* ldxr_c */
    20,	/* ldxi_c */
    4,	/* ldxr_uc */
    20,	/* ldxi_uc */
    4,	/* ldxr_s */
    16,	/* ldxi_s */
    4,	/* ldxr_us */
    16,	/* ldxi_us */
    4,	/* ldxr_i */
    20,	/* ldxi_i */
    4,	/* ldxr_ui */
    16,	/* ldxi_ui */
    4,	/* ldxr_l */
    20,	/* ldxi_l */
    4,	/* str_c */
    16,	/* sti_c */
    4,	/* str_s */
    16,	/* sti_s */
    4,	/* str_i */
    16,	/* sti_i */
    4,	/* str_l */
    16,	/* sti_l */
    4,	/* stxr_c */
    20,	/* stxi_c */
    4,	/* stxr_s */
    20,	/* stxi_s */
    4,	/* stxr_i */
    20,	/* stxi_i */
    4,	/* stxr_l */
    20,	/* stxi_l */
    8,	/* bltr */
    8,	/* blti */
    8,	/* bltr_u */
    8,	/* blti_u */
    8,	/* bler */
    8,	/* blei */
    8,	/* bler_u */
    8,	/* blei_u */
    8,	/* beqr */
    24,	/* beqi */
    8,	/* bger */
    8,	/* bgei */
    8,	/* bger_u */
    8,	/* bgei_u */
    8,	/* bgtr */
    8,	/* bgti */
    8,	/* bgtr_u */
    8,	/* bgti_u */
    8,	/* bner */
    24,	/* bnei */
    8,	/* bmsr */
    8,	/* bmsi */
    8,	/* bmcr */
    8,	/* bmci */
    8,	/* boaddr */
    8,	/* boaddi */
    8,	/* boaddr_u */
    8,	/* boaddi_u */
    8,	/* bxaddr */
    8,	/* bxaddi */
    8,	/* bxaddr_u */
    8,	/* bxaddi_u */
    8,	/* bosubr */
    8,	/* bosubi */
    8,	/* bosubr_u */
    8,	/* bosubi_u */
    8,	/* bxsubr */
    8,	/* bxsubi */
    8,	/* bxsubr_u */
    8,	/* bxsubi_u */
    4,	/* jmpr */
    4,	/* jmpi */
    4,	/* callr */
    12,	/* calli */
    0,	/* prepare */
    0,	/* pushargr_c */
    0,	/* pushargi_c */
    0,	/* pushargr_uc */
    0,	/* pushargi_uc */
    0,	/* pushargr_s */
    0,	/* pushargi_s */
    0,	/* pushargr_us */
    0,	/* pushargi_us */
    0,	/* pushargr_i */
    0,	/* pushargi_i */
    0,	/* pushargr_ui */
    0,	/* pushargi_ui */
    0,	/* pushargr_l */
    0,	/* pushargi_l */
    0,	/* finishr */
    0,	/* finishi */
    0,	/* ret */
    0,	/* retr_c */
    0,	/* reti_c */
    0,	/* retr_uc */
    0,	/* reti_uc */
    0,	/* retr_s */
    0,	/* reti_s */
    0,	/* retr_us */
    0,	/* reti_us */
    0,	/* retr_i */
    0,	/* reti_i */
    0,	/* retr_ui */
    0,	/* reti_ui */
    0,	/* retr_l */
    0,	/* reti_l */
    0,	/* retval_c */
    0,	/* retval_uc */
    0,	/* retval_s */
    0,	/* retval_us */
    0,	/* retval_i */
    0,	/* retval_ui */
    0,	/* retval_l */
    96,	/* epilog */
    0,	/* arg_f */
    0,	/* getarg_f */
    0,	/* putargr_f */
    0,	/* putargi_f */
    4,	/* addr_f */
    12,	/* addi_f */
    4,	/* subr_f */
    12,	/* subi_f */
    12,	/* rsbi_f */
    4,	/* mulr_f */
    12,	/* muli_f */
    4,	/* divr_f */
    12,	/* divi_f */
    4,	/* negr_f */
    4,	/* absr_f */
    4,	/* sqrtr_f */
    8,	/* ltr_f */
    16,	/* lti_f */
    8,	/* ler_f */
    16,	/* lei_f */
    8,	/* eqr_f */
    16,	/* eqi_f */
    8,	/* ger_f */
    16,	/* gei_f */
    8,	/* gtr_f */
    16,	/* gti_f */
    8,	/* ner_f */
    16,	/* nei_f */
    8,	/* unltr_f */
    16,	/* unlti_f */
    8,	/* unler_f */
    16,	/* unlei_f */
    16,	/* uneqr_f */
    24,	/* uneqi_f */
    8,	/* unger_f */
    16,	/* ungei_f */
    8,	/* ungtr_f */
    16,	/* ungti_f */
    16,	/* ltgtr_f */
    24,	/* ltgti_f */
    8,	/* ordr_f */
    16,	/* ordi_f */
    8,	/* unordr_f */
    16,	/* unordi_f */
    8,	/* truncr_f_i */
    4,	/* truncr_f_l */
    4,	/* extr_f */
    4,	/* extr_d_f */
    4,	/* movr_f */
    8,	/* movi_f */
    8,	/* ldr_f */
    20,	/* ldi_f */
    8,	/* ldxr_f */
    24,	/* ldxi_f */
    8,	/* str_f */
    20,	/* sti_f */
    8,	/* stxr_f */
    24,	/* stxi_f */
    8,	/* bltr_f */
    16,	/* blti_f */
    8,	/* bler_f */
    16,	/* blei_f */
    8,	/* beqr_f */
    16,	/* beqi_f */
    8,	/* bger_f */
    16,	/* bgei_f */
    8,	/* bgtr_f */
    16,	/* bgti_f */
    8,	/* bner_f */
    16,	/* bnei_f */
    8,	/* bunltr_f */
    16,	/* bunlti_f */
    8,	/* bunler_f */
    16,	/* bunlei_f */
    16,	/* buneqr_f */
    24,	/* buneqi_f */
    8,	/* bunger_f */
    16,	/* bungei_f */
    8,	/* bungtr_f */
    16,	/* bungti_f */
    16,	/* bltgtr_f */
    24,	/* bltgti_f */
    8,	/* bordr_f */
    16,	/* bordi_f */
    8,	/* bunordr_f */
    16,	/* bunordi_f */
    0,	/* pushargr_f */
    0,	/* pushargi_f */
    0,	/* retr_f */
    0,	/* reti_f */
    0,	/* retval_f */
    0,	/* arg_d */
    0,	/* getarg_d */
    0,	/* putargr_d */
    0,	/* putargi_d */
    4,	/* addr_d */
    12,	/* addi_d */
    4,	/* subr_d */
    12,	/* subi_d */
    12,	/* rsbi_d */
    4,	/* mulr_d */
    12,	/* muli_d */
    4,	/* divr_d */
    12,	/* divi_d */
    4,	/* negr_d */
    4,	/* absr_d */
    4,	/* sqrtr_d */
    8,	/* ltr_d */
    16,	/* lti_d */
    8,	/* ler_d */
    16,	/* lei_d */
    8,	/* eqr_d */
    16,	/* eqi_d */
    8,	/* ger_d */
    16,	/* gei_d */
    8,	/* gtr_d */
    16,	/* gti_d */
    8,	/* ner_d */
    16,	/* nei_d */
    8,	/* unltr_d */
    16,	/* unlti_d */
    8,	/* unler_d */
    16,	/* unlei_d */
    16,	/* uneqr_d */
    24,	/* uneqi_d */
    8,	/* unger_d */
    16,	/* ungei_d */
    8,	/* ungtr_d */
    16,	/* ungti_d */
    16,	/* ltgtr_d */
    24,	/* ltgti_d */
    8,	/* ordr_d */
    16,	/* ordi_d */
    8,	/* unordr_d */
    16,	/* unordi_d */
    8,	/* truncr_d_i */
    4,	/* truncr_d_l */
    4,	/* extr_d */
    4,	/* extr_f_d */
    4,	/* movr_d */
    12,	/* movi_d */
    8,	/* ldr_d */
    20,	/* ldi_d */
    8,	/* ldxr_d */
    24,	/* ldxi_d */
    8,	/* str_d */
    20,	/* sti_d */
    8,	/* stxr_d */
    24,	/* stxi_d */
    8,	/* bltr_d */
    16,	/* blti_d */
    8,	/* bler_d */
    16,	/* blei_d */
    8,	/* beqr_d */
    20,	/* beqi_d */
    8,	/* bger_d */
    16,	/* bgei_d */
    8,	/* bgtr_d */
    16,	/* bgti_d */
    8,	/* bner_d */
    16,	/* bnei_d */
    8,	/* bunltr_d */
    16,	/* bunlti_d */
    8,	/* bunler_d */
    16,	/* bunlei_d */
    16,	/* buneqr_d */
    24,	/* buneqi_d */
    8,	/* bunger_d */
    16,	/* bungei_d */
    8,	/* bungtr_d */
    16,	/* bungti_d */
    16,	/* bltgtr_d */
    24,	/* bltgti_d */
    8,	/* bordr_d */
    16,	/* bordi_d */
    8,	/* bunordr_d */
    16,	/* bunordi_d */
    0,	/* pushargr_d */
    0,	/* pushargi_d */
    0,	/* retr_d */
    0,	/* reti_d */
    0,	/* retval_d */
    0,	/* movr_w_f */
    0,	/* movr_ww_d */
    0,	/* movr_w_d */
    0,	/* movr_f_w */
    0,	/* movi_f_w */
    0,	/* movr_d_ww */
    0,	/* movi_d_ww */
    0,	/* movr_d_w */
    0,	/* movi_d_w */
    8,	/* clor */
    4,	/* clzr */
    12,	/* ctor */
    8,	/* ctzr */
    4,	/* rbitr */
    16,	/* popcntr */
    12,	/* lrotr */
    4,	/* lroti */
    4,	/* rrotr */
    4,	/* rroti */
    4,	/* extr */
    4,	/* extr_u */
    4,	/* depr */
    8,	/* depi */
    4,	/* negi */
    4,	/* comi */
    4,	/* exti_c */
    4,	/* exti_uc */
    4,	/* exti_s */
    4,	/* exti_us */
    12, /* exti_i */
    4,	/* exti_ui */
    4,	/* bswapi_us */
    8,	/* bswapi_ui */
    16, /* bswapi_ul */
    4,	/* htoni_us */
    8,	/* htoni_ui */
    16, /* htoni_ul */
    0,	/* negi_f */
    0,	/* absi_f */
    0,	/* sqrti_f */
    0,	/* negi_d */
    0,	/* absi_d */
    0,	/* sqrti_d */
    4,	/* cloi */
    4,	/* clzi */
    4,	/* ctoi */
    4,	/* ctzi */
    16, /* rbiti */
    4,	/* popcnti */
    4,	/* exti */
    4,	/* exti_u */
    56, /* qlshr */
    8,	/* qlshi */
    52, /* qlshr_u */
    8,	/* qlshi_u */
    52, /* qrshr */
    8,	/* qrshi */
    52, /* qrshr_u */
    8,	/* qrshi_u */
#  endif
#endif /* __WORDSIZE */
