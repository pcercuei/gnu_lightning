
#if __WORDSIZE == 32
#define JIT_INSTR_MAX 196
    0,	/* data */
    0,	/* live */
    28,	/* align */
    0,	/* save */
    0,	/* load */
    0,  /* skip */
    0,	/* #name */
    0,	/* #note */
    0,	/* label */
    156,	/* prolog */
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
    20,	/* va_arg_d */
    0,	/* va_end */
    4,	/* addr */
    12,	/* addi */
    4,	/* addcr */
    12,	/* addci */
    4,	/* addxr */
    8,	/* addxi */
    4,	/* subr */
    12,	/* subi */
    4,	/* subcr */
    12,	/* subci */
    4,	/* subxr */
    8,	/* subxi */
    12,	/* rsbi */
    48,	/* mulr */
    56,	/* muli */
    40,	/* qmulr */
    44,	/* qmuli */
    52,	/* qmulr_u */
    60,	/* qmuli_u */
    36,	/* divr */
    40,	/* divi */
    36,	/* divr_u */
    40,	/* divi_u */
    40,	/* qdivr */
    40,	/* qdivi */
    40,	/* qdivr_u */
    40,	/* qdivi_u */
    36,	/* remr */
    40,	/* remi */
    36,	/* remr_u */
    40,	/* remi_u */
    4,	/* andr */
    12,	/* andi */
    4,	/* orr */
    12,	/* ori */
    4,	/* xorr */
    12,	/* xori */
    12,	/* lshr */
    4,	/* lshi */
    12,	/* rshr */
    4,	/* rshi */
    12,	/* rshr_u */
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
    12,	/* eqi */
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
    8,	/* movi */
    12,	/* movnr */
    12,	/* movzr */
    88,	/* casr */
    96,	/* casi */
    4,	/* extr_c */
    4,	/* extr_uc */
    4,	/* extr_s */
    4,	/* extr_us */
    0,	/* extr_i */
    0,	/* extr_ui */
    12,	/* bswapr_us */
    16,	/* bswapr_ui */
    0,	/* bswapr_ul */
    4,	/* htonr_us */
    4,	/* htonr_ui */
    0,	/* htonr_ul */
    8,	/* ldr_c */
    12,	/* ldi_c */
    4,	/* ldr_uc */
    8,	/* ldi_uc */
    8,	/* ldr_s */
    12,	/* ldi_s */
    4,	/* ldr_us */
    8,	/* ldi_us */
    4,	/* ldr_i */
    8,	/* ldi_i */
    0,	/* ldr_ui */
    0,	/* ldi_ui */
    0,	/* ldr_l */
    0,	/* ldi_l */
    8,	/* ldxr_c */
    12,	/* ldxi_c */
    4,	/* ldxr_uc */
    8,	/* ldxi_uc */
    8,	/* ldxr_s */
    12,	/* ldxi_s */
    4,	/* ldxr_us */
    8,	/* ldxi_us */
    4,	/* ldxr_i */
    8,	/* ldxi_i */
    0,	/* ldxr_ui */
    0,	/* ldxi_ui */
    0,	/* ldxr_l */
    0,	/* ldxi_l */
    4,	/* str_c */
    8,	/* sti_c */
    4,	/* str_s */
    8,	/* sti_s */
    4,	/* str_i */
    8,	/* sti_i */
    0,	/* str_l */
    0,	/* sti_l */
    8,	/* stxr_c */
    12,	/* stxi_c */
    8,	/* stxr_s */
    12,	/* stxi_s */
    8,	/* stxr_i */
    12,	/* stxi_i */
    0,	/* stxr_l */
    0,	/* stxi_l */
    8,	/* bltr */
    8,	/* blti */
    8,	/* bltr_u */
    8,	/* blti_u */
    8,	/* bler */
    12,	/* blei */
    8,	/* bler_u */
    8,	/* blei_u */
    8,	/* beqr */
    16,	/* beqi */
    8,	/* bger */
    8,	/* bgei */
    8,	/* bger_u */
    8,	/* bgei_u */
    8,	/* bgtr */
    8,	/* bgti */
    8,	/* bgtr_u */
    8,	/* bgti_u */
    8,	/* bner */
    16,	/* bnei */
    12,	/* bmsr */
    16,	/* bmsi */
    12,	/* bmcr */
    16,	/* bmci */
    8,	/* boaddr */
    8,	/* boaddi */
    8,	/* boaddr_u */
    8,	/* boaddi_u */
    8,	/* bxaddr */
    8,	/* bxaddi */
    8,	/* bxaddr_u */
    8,	/* bxaddi_u */
    12,	/* bosubr */
    16,	/* bosubi */
    16,	/* bosubr_u */
    20,	/* bosubi_u */
    12,	/* bxsubr */
    16,	/* bxsubi */
    16,	/* bxsubr_u */
    20,	/* bxsubi_u */
    4,	/* jmpr */
    12,	/* jmpi */
    40,	/* callr */
    44,	/* calli */
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
    196,	/* epilog */
    0,	/* arg_f */
    0,	/* getarg_f */
    0,	/* putargr_f */
    0,	/* putargi_f */
    4,	/* addr_f */
    24,	/* addi_f */
    4,	/* subr_f */
    24,	/* subi_f */
    24,	/* rsbi_f */
    4,	/* mulr_f */
    24,	/* muli_f */
    4,	/* divr_f */
    24,	/* divi_f */
    4,	/* negr_f */
    4,	/* absr_f */
    4,	/* sqrtr_f */
    16,	/* ltr_f */
    36,	/* lti_f */
    16,	/* ler_f */
    36,	/* lei_f */
    16,	/* eqr_f */
    36,	/* eqi_f */
    16,	/* ger_f */
    36,	/* gei_f */
    16,	/* gtr_f */
    36,	/* gti_f */
    16,	/* ner_f */
    36,	/* nei_f */
    16,	/* unltr_f */
    36,	/* unlti_f */
    16,	/* unler_f */
    36,	/* unlei_f */
    16,	/* uneqr_f */
    36,	/* uneqi_f */
    16,	/* unger_f */
    36,	/* ungei_f */
    16,	/* ungtr_f */
    36,	/* ungti_f */
    16,	/* ltgtr_f */
    36,	/* ltgti_f */
    16,	/* ordr_f */
    36,	/* ordi_f */
    16,	/* unordr_f */
    36,	/* unordi_f */
    16,	/* truncr_f_i */
    0,	/* truncr_f_l */
    20,	/* extr_f */
    4,	/* extr_d_f */
    4,	/* movr_f */
    20,	/* movi_f */
    4,	/* ldr_f */
    12,	/* ldi_f */
    8,	/* ldxr_f */
    12,	/* ldxi_f */
    4,	/* str_f */
    12,	/* sti_f */
    8,	/* stxr_f */
    12,	/* stxi_f */
    16,	/* bltr_f */
    36,	/* blti_f */
    16,	/* bler_f */
    36,	/* blei_f */
    16,	/* beqr_f */
    36,	/* beqi_f */
    16,	/* bger_f */
    36,	/* bgei_f */
    16,	/* bgtr_f */
    36,	/* bgti_f */
    16,	/* bner_f */
    36,	/* bnei_f */
    16,	/* bunltr_f */
    36,	/* bunlti_f */
    16,	/* bunler_f */
    36,	/* bunlei_f */
    16,	/* buneqr_f */
    36,	/* buneqi_f */
    16,	/* bunger_f */
    36,	/* bungei_f */
    16,	/* bungtr_f */
    36,	/* bungti_f */
    16,	/* bltgtr_f */
    36,	/* bltgti_f */
    16,	/* bordr_f */
    36,	/* bordi_f */
    16,	/* bunordr_f */
    36,	/* bunordi_f */
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
    32,	/* addi_d */
    4,	/* subr_d */
    32,	/* subi_d */
    32,	/* rsbi_d */
    4,	/* mulr_d */
    32,	/* muli_d */
    4,	/* divr_d */
    32,	/* divi_d */
    4,	/* negr_d */
    4,	/* absr_d */
    4,	/* sqrtr_d */
    16,	/* ltr_d */
    44,	/* lti_d */
    16,	/* ler_d */
    44,	/* lei_d */
    16,	/* eqr_d */
    44,	/* eqi_d */
    16,	/* ger_d */
    44,	/* gei_d */
    16,	/* gtr_d */
    44,	/* gti_d */
    16,	/* ner_d */
    44,	/* nei_d */
    16,	/* unltr_d */
    44,	/* unlti_d */
    16,	/* unler_d */
    44,	/* unlei_d */
    16,	/* uneqr_d */
    44,	/* uneqi_d */
    16,	/* unger_d */
    44,	/* ungei_d */
    16,	/* ungtr_d */
    44,	/* ungti_d */
    16,	/* ltgtr_d */
    44,	/* ltgti_d */
    16,	/* ordr_d */
    44,	/* ordi_d */
    16,	/* unordr_d */
    44,	/* unordi_d */
    16,	/* truncr_d_i */
    0,	/* truncr_d_l */
    20,	/* extr_d */
    4,	/* extr_f_d */
    4,	/* movr_d */
    28,	/* movi_d */
    4,	/* ldr_d */
    12,	/* ldi_d */
    8,	/* ldxr_d */
    12,	/* ldxi_d */
    4,	/* str_d */
    12,	/* sti_d */
    8,	/* stxr_d */
    12,	/* stxi_d */
    16,	/* bltr_d */
    44,	/* blti_d */
    16,	/* bler_d */
    44,	/* blei_d */
    16,	/* beqr_d */
    44,	/* beqi_d */
    16,	/* bger_d */
    44,	/* bgei_d */
    16,	/* bgtr_d */
    44,	/* bgti_d */
    16,	/* bner_d */
    44,	/* bnei_d */
    16,	/* bunltr_d */
    44,	/* bunlti_d */
    16,	/* bunler_d */
    44,	/* bunlei_d */
    16,	/* buneqr_d */
    44,	/* buneqi_d */
    16,	/* bunger_d */
    44,	/* bungei_d */
    16,	/* bungtr_d */
    44,	/* bungti_d */
    16,	/* bltgtr_d */
    44,	/* bltgti_d */
    16,	/* bordr_d */
    44,	/* bordi_d */
    16,	/* bunordr_d */
    44,	/* bunordi_d */
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
    80,	/* clor */
    60,	/* clzr */
    76,	/* ctor */
    56,	/* ctzr */
    68,	/* rbitr */
    64,	/* popcntr */
    32,	/* lrotr */
    8,	/* lroti */
    32,	/* rrotr */
    8,	/* rroti */
    4,	/* extr */
    4,	/* extr_u */
    4,	/* depr */
    8,	/* depi */
    4,	/* negi */
    4,	/* comi */
    4,	/* exti_c */
    4,	/* exti_uc */
    4,	/* exti_s */
    8,	/* exti_us */
    0,	/* exti_i */
    0,	/* exti_ui */
    8,	/* bswapi_us */
    8,	/* bswapi_ui */
    0,	/* bswapi_ul */
    8,	/* htoni_us */
    8,	/* htoni_ui */
    0,	/* htoni_ul */
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
    8,	/* rbiti */
    4,	/* popcnti */
    4,	/* exti */
    4,	/* exti_u */
    72, /* qlshr */
    8,	/* qlshi */
    72, /* qlshr_u */
    8,	/* qlshi_u */
    72, /* qrshr */
    8,	/* qrshi */
    72, /* qrshr_u */
    8,	/* qrshi_u */
#endif /* __WORDSIZE */
