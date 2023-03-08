
#if __WORDSIZE == 32
#define JIT_INSTR_MAX 116
    0,	/* data */
    0,	/* live */
    20,	/* align */
    0,	/* save */
    0,	/* load */
    4,	/* skip */
    0,	/* #name */
    0,	/* #note */
    0,	/* label */
    116,	/* prolog */
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
    12,	/* addcr */
    20,	/* addci */
    28,	/* addxr */
    28,	/* addxi */
    4,	/* subr */
    12,	/* subi */
    12,	/* subcr */
    20,	/* subci */
    28,	/* subxr */
    28,	/* subxi */
    16,	/* rsbi */
    4,	/* mulr */
    12,	/* muli */
    12,	/* qmulr */
    20,	/* qmuli */
    12,	/* qmulr_u */
    20,	/* qmuli_u */
    8,	/* divr */
    16,	/* divi */
    8,	/* divr_u */
    16,	/* divi_u */
    12,	/* qdivr */
    16,	/* qdivi */
    12,	/* qdivr_u */
    16,	/* qdivi_u */
    8,	/* remr */
    16,	/* remi */
    8,	/* remr_u */
    16,	/* remi_u */
    4,	/* andr */
    8,	/* andi */
    4,	/* orr */
    12,	/* ori */
    4,	/* xorr */
    12,	/* xori */
    4,	/* lshr */
    4,	/* lshi */
    4,	/* rshr */
    4,	/* rshi */
    4,	/* rshr_u */
    4,	/* rshi_u */
    4,	/* negr */
    8,	/* comr */
    4,	/* ltr */
    4,	/* lti */
    4,	/* ltr_u */
    4,	/* lti_u */
    8,	/* ler */
    4,	/* lei */
    8,	/* ler_u */
    4,	/* lei_u */
    8,	/* eqr */
    8,	/* eqi */
    8,	/* ger */
    8,	/* gei */
    8,	/* ger_u */
    8,	/* gei_u */
    4,	/* gtr */
    8,	/* gti */
    4,	/* gtr_u */
    8,	/* gti_u */
    8,	/* ner */
    8,	/* nei */
    4,	/* movr */
    8,	/* movi */
    4,	/* movnr */
    4,	/* movzr */
    36,	/* casr */
    44,	/* casi */
    4,	/* extr_c */
    4,	/* extr_uc */
    4,	/* extr_s */
    4,	/* extr_us */
    0,	/* extr_i */
    0,	/* extr_ui */
    8,	/* bswapr_us */
    8,	/* bswapr_ui */
    0,	/* bswapr_ul */
    4,	/* htonr_us */
    4,	/* htonr_ui */
    0,	/* htonr_ul */
    4,	/* ldr_c */
    12,	/* ldi_c */
    4,	/* ldr_uc */
    12,	/* ldi_uc */
    4,	/* ldr_s */
    12,	/* ldi_s */
    4,	/* ldr_us */
    12,	/* ldi_us */
    4,	/* ldr_i */
    12,	/* ldi_i */
    0,	/* ldr_ui */
    0,	/* ldi_ui */
    0,	/* ldr_l */
    0,	/* ldi_l */
    8,	/* ldxr_c */
    16,	/* ldxi_c */
    8,	/* ldxr_uc */
    16,	/* ldxi_uc */
    8,	/* ldxr_s */
    16,	/* ldxi_s */
    8,	/* ldxr_us */
    16,	/* ldxi_us */
    8,	/* ldxr_i */
    16,	/* ldxi_i */
    0,	/* ldxr_ui */
    0,	/* ldxi_ui */
    0,	/* ldxr_l */
    0,	/* ldxi_l */
    4,	/* str_c */
    12,	/* sti_c */
    4,	/* str_s */
    12,	/* sti_s */
    4,	/* str_i */
    12,	/* sti_i */
    0,	/* str_l */
    0,	/* sti_l */
    8,	/* stxr_c */
    16,	/* stxi_c */
    8,	/* stxr_s */
    16,	/* stxi_s */
    8,	/* stxr_i */
    16,	/* stxi_i */
    0,	/* stxr_l */
    0,	/* stxi_l */
    12,	/* bltr */
    12,	/* blti */
    12,	/* bltr_u */
    12,	/* blti_u */
    12,	/* bler */
    16,	/* blei */
    12,	/* bler_u */
    16,	/* blei_u */
    8,	/* beqr */
    16,	/* beqi */
    12,	/* bger */
    12,	/* bgei */
    12,	/* bger_u */
    12,	/* bgei_u */
    12,	/* bgtr */
    16,	/* bgti */
    12,	/* bgtr_u */
    16,	/* bgti_u */
    8,	/* bner */
    16,	/* bnei */
    12,	/* bmsr */
    12,	/* bmsi */
    12,	/* bmcr */
    12,	/* bmci */
    28,	/* boaddr */
    28,	/* boaddi */
    16,	/* boaddr_u */
    20,	/* boaddi_u */
    28,	/* bxaddr */
    28,	/* bxaddi */
    16,	/* bxaddr_u */
    20,	/* bxaddi_u */
    28,	/* bosubr */
    28,	/* bosubi */
    16,	/* bosubr_u */
    20,	/* bosubi_u */
    28,	/* bxsubr */
    28,	/* bxsubi */
    16,	/* bxsubr_u */
    20,	/* bxsubi_u */
    8,	/* jmpr */
    8,	/* jmpi */
    8,	/* callr */
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
    116,	/* epilog */
    0,	/* arg_f */
    0,	/* getarg_f */
    0,	/* putargr_f */
    0,	/* putargi_f */
    4,	/* addr_f */
    16,	/* addi_f */
    4,	/* subr_f */
    16,	/* subi_f */
    16,	/* rsbi_f */
    4,	/* mulr_f */
    16,	/* muli_f */
    4,	/* divr_f */
    16,	/* divi_f */
    4,	/* negr_f */
    4,	/* absr_f */
    4,	/* sqrtr_f */
    16,	/* ltr_f */
    28,	/* lti_f */
    16,	/* ler_f */
    28,	/* lei_f */
    16,	/* eqr_f */
    28,	/* eqi_f */
    16,	/* ger_f */
    28,	/* gei_f */
    16,	/* gtr_f */
    28,	/* gti_f */
    16,	/* ner_f */
    28,	/* nei_f */
    16,	/* unltr_f */
    28,	/* unlti_f */
    16,	/* unler_f */
    28,	/* unlei_f */
    16,	/* uneqr_f */
    28,	/* uneqi_f */
    16,	/* unger_f */
    28,	/* ungei_f */
    16,	/* ungtr_f */
    28,	/* ungti_f */
    16,	/* ltgtr_f */
    28,	/* ltgti_f */
    16,	/* ordr_f */
    28,	/* ordi_f */
    16,	/* unordr_f */
    28,	/* unordi_f */
    8,	/* truncr_f_i */
    0,	/* truncr_f_l */
    8,	/* extr_f */
    4,	/* extr_d_f */
    4,	/* movr_f */
    12,	/* movi_f */
    4,	/* ldr_f */
    12,	/* ldi_f */
    8,	/* ldxr_f */
    16,	/* ldxi_f */
    4,	/* str_f */
    12,	/* sti_f */
    8,	/* stxr_f */
    16,	/* stxi_f */
    12,	/* bltr_f */
    24,	/* blti_f */
    12,	/* bler_f */
    24,	/* blei_f */
    12,	/* beqr_f */
    24,	/* beqi_f */
    12,	/* bger_f */
    24,	/* bgei_f */
    12,	/* bgtr_f */
    24,	/* bgti_f */
    12,	/* bner_f */
    24,	/* bnei_f */
    12,	/* bunltr_f */
    24,	/* bunlti_f */
    12,	/* bunler_f */
    24,	/* bunlei_f */
    12,	/* buneqr_f */
    24,	/* buneqi_f */
    12,	/* bunger_f */
    24,	/* bungei_f */
    12,	/* bungtr_f */
    24,	/* bungti_f */
    12,	/* bltgtr_f */
    24,	/* bltgti_f */
    12,	/* bordr_f */
    24,	/* bordi_f */
    12,	/* bunordr_f */
    24,	/* bunordi_f */
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
    20,	/* addi_d */
    4,	/* subr_d */
    20,	/* subi_d */
    20,	/* rsbi_d */
    4,	/* mulr_d */
    20,	/* muli_d */
    4,	/* divr_d */
    20,	/* divi_d */
    4,	/* negr_d */
    4,	/* absr_d */
    4,	/* sqrtr_d */
    16,	/* ltr_d */
    40,	/* lti_d */
    16,	/* ler_d */
    40,	/* lei_d */
    16,	/* eqr_d */
    40,	/* eqi_d */
    16,	/* ger_d */
    40,	/* gei_d */
    16,	/* gtr_d */
    40,	/* gti_d */
    16,	/* ner_d */
    40,	/* nei_d */
    16,	/* unltr_d */
    40,	/* unlti_d */
    16,	/* unler_d */
    40,	/* unlei_d */
    16,	/* uneqr_d */
    40,	/* uneqi_d */
    16,	/* unger_d */
    40,	/* ungei_d */
    16,	/* ungtr_d */
    40,	/* ungti_d */
    16,	/* ltgtr_d */
    40,	/* ltgti_d */
    16,	/* ordr_d */
    40,	/* ordi_d */
    16,	/* unordr_d */
    40,	/* unordi_d */
    8,	/* truncr_d_i */
    0,	/* truncr_d_l */
    8,	/* extr_d */
    4,	/* extr_f_d */
    4,	/* movr_d */
    24,	/* movi_d */
    8,	/* ldr_d */
    16,	/* ldi_d */
    12,	/* ldxr_d */
    20,	/* ldxi_d */
    8,	/* str_d */
    16,	/* sti_d */
    12,	/* stxr_d */
    20,	/* stxi_d */
    12,	/* bltr_d */
    28,	/* blti_d */
    12,	/* bler_d */
    28,	/* blei_d */
    12,	/* beqr_d */
    28,	/* beqi_d */
    12,	/* bger_d */
    28,	/* bgei_d */
    12,	/* bgtr_d */
    28,	/* bgti_d */
    12,	/* bner_d */
    36,	/* bnei_d */
    12,	/* bunltr_d */
    36,	/* bunlti_d */
    12,	/* bunler_d */
    36,	/* bunlei_d */
    12,	/* buneqr_d */
    36,	/* buneqi_d */
    12,	/* bunger_d */
    36,	/* bungei_d */
    12,	/* bungtr_d */
    36,	/* bungti_d */
    12,	/* bltgtr_d */
    28,	/* bltgti_d */
    12,	/* bordr_d */
    28,	/* bordi_d */
    12,	/* bunordr_d */
    36,	/* bunordi_d */
    0,	/* pushargr_d */
    0,	/* pushargi_d */
    0,	/* retr_d */
    0,	/* reti_d */
    0,	/* retval_d */
    4,	/* movr_w_f */
    8,	/* movr_ww_d */
    0,	/* movr_w_d */
    4,	/* movr_f_w */
    4,	/* movi_f_w */
    8,	/* movr_d_ww */
    8,	/* movi_d_ww */
    0,	/* movr_d_w */
    0,	/* movi_d_w */
    8,	/* clor */
    8,	/* clzr */
    28,	/* ctor */
    20,	/* ctzr */
    68,	/* rbitr */
    64,	/* popcntr */
    12,	/* lrotr */
    4,	/* lroti */
    4,	/* rrotr */
    4,	/* rroti */
#endif /* __WORDSIZE */

#if __WORDSIZE == 64
#define JIT_INSTR_MAX 76
    0,	/* data */
    0,	/* live */
    24,	/* align */
    0,	/* save */
    0,	/* load */
    4,	/* skip */
    0,	/* #name */
    0,	/* #note */
    0,	/* label */
    76,	/* prolog */
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
    8,	/* va_arg_d */
    0,	/* va_end */
    4,	/* addr */
    28,	/* addi */
    12,	/* addcr */
    36,	/* addci */
    28,	/* addxr */
    28,	/* addxi */
    4,	/* subr */
    28,	/* subi */
    12,	/* subcr */
    36,	/* subci */
    28,	/* subxr */
    28,	/* subxi */
    36,	/* rsbi */
    8,	/* mulr */
    32,	/* muli */
    12,	/* qmulr */
    32,	/* qmuli */
    12,	/* qmulr_u */
    32,	/* qmuli_u */
    8,	/* divr */
    32,	/* divi */
    8,	/* divr_u */
    32,	/* divi_u */
    12,	/* qdivr */
    16,	/* qdivi */
    12,	/* qdivr_u */
    16,	/* qdivi_u */
    8,	/* remr */
    32,	/* remi */
    8,	/* remr_u */
    32,	/* remi_u */
    4,	/* andr */
    8,	/* andi */
    4,	/* orr */
    28,	/* ori */
    4,	/* xorr */
    28,	/* xori */
    4,	/* lshr */
    4,	/* lshi */
    4,	/* rshr */
    4,	/* rshi */
    4,	/* rshr_u */
    4,	/* rshi_u */
    4,	/* negr */
    8,	/* comr */
    4,	/* ltr */
    4,	/* lti */
    4,	/* ltr_u */
    4,	/* lti_u */
    8,	/* ler */
    4,	/* lei */
    8,	/* ler_u */
    4,	/* lei_u */
    8,	/* eqr */
    8,	/* eqi */
    8,	/* ger */
    8,	/* gei */
    8,	/* ger_u */
    8,	/* gei_u */
    4,	/* gtr */
    8,	/* gti */
    4,	/* gtr_u */
    8,	/* gti_u */
    8,	/* ner */
    8,	/* nei */
    4,	/* movr */
    28,	/* movi */
    4,	/* movnr */
    4,	/* movzr */
    36,	/* casr */
    56,	/* casi */
    4,	/* extr_c */
    4,	/* extr_uc */
    4,	/* extr_s */
    4,	/* extr_us */
    4,	/* extr_i */
    4,	/* extr_ui */
    8,	/* bswapr_us */
    16,	/* bswapr_ui */
    44,	/* bswapr_ul */
    4,	/* htonr_us */
    4,	/* htonr_ui */
    4,	/* htonr_ul */
    4,	/* ldr_c */
    24,	/* ldi_c */
    4,	/* ldr_uc */
    24,	/* ldi_uc */
    4,	/* ldr_s */
    24,	/* ldi_s */
    4,	/* ldr_us */
    24,	/* ldi_us */
    4,	/* ldr_i */
    24,	/* ldi_i */
    4,	/* ldr_ui */
    24,	/* ldi_ui */
    4,	/* ldr_l */
    24,	/* ldi_l */
    8,	/* ldxr_c */
    16,	/* ldxi_c */
    8,	/* ldxr_uc */
    16,	/* ldxi_uc */
    8,	/* ldxr_s */
    16,	/* ldxi_s */
    8,	/* ldxr_us */
    16,	/* ldxi_us */
    8,	/* ldxr_i */
    16,	/* ldxi_i */
    8,	/* ldxr_ui */
    16,	/* ldxi_ui */
    8,	/* ldxr_l */
    16,	/* ldxi_l */
    4,	/* str_c */
    24,	/* sti_c */
    4,	/* str_s */
    24,	/* sti_s */
    4,	/* str_i */
    24,	/* sti_i */
    4,	/* str_l */
    24,	/* sti_l */
    8,	/* stxr_c */
    16,	/* stxi_c */
    8,	/* stxr_s */
    16,	/* stxi_s */
    8,	/* stxr_i */
    16,	/* stxi_i */
    8,	/* stxr_l */
    16,	/* stxi_l */
    12,	/* bltr */
    12,	/* blti */
    12,	/* bltr_u */
    12,	/* blti_u */
    12,	/* bler */
    16,	/* blei */
    12,	/* bler_u */
    16,	/* blei_u */
    8,	/* beqr */
    36,	/* beqi */
    12,	/* bger */
    12,	/* bgei */
    12,	/* bger_u */
    12,	/* bgei_u */
    12,	/* bgtr */
    16,	/* bgti */
    12,	/* bgtr_u */
    16,	/* bgti_u */
    8,	/* bner */
    28,	/* bnei */
    12,	/* bmsr */
    12,	/* bmsi */
    12,	/* bmcr */
    12,	/* bmci */
    28,	/* boaddr */
    28,	/* boaddi */
    16,	/* boaddr_u */
    20,	/* boaddi_u */
    28,	/* bxaddr */
    28,	/* bxaddi */
    16,	/* bxaddr_u */
    20,	/* bxaddi_u */
    28,	/* bosubr */
    28,	/* bosubi */
    16,	/* bosubr_u */
    20,	/* bosubi_u */
    28,	/* bxsubr */
    28,	/* bxsubi */
    16,	/* bxsubr_u */
    20,	/* bxsubi_u */
    8,	/* jmpr */
    8,	/* jmpi */
    8,	/* callr */
    32,	/* calli */
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
    76,	/* epilog */
    0,	/* arg_f */
    0,	/* getarg_f */
    0,	/* putargr_f */
    0,	/* putargi_f */
    4,	/* addr_f */
    28,	/* addi_f */
    4,	/* subr_f */
    28,	/* subi_f */
    28,	/* rsbi_f */
    4,	/* mulr_f */
    28,	/* muli_f */
    4,	/* divr_f */
    28,	/* divi_f */
    4,	/* negr_f */
    4,	/* absr_f */
    4,	/* sqrtr_f */
    16,	/* ltr_f */
    40,	/* lti_f */
    16,	/* ler_f */
    40,	/* lei_f */
    16,	/* eqr_f */
    40,	/* eqi_f */
    16,	/* ger_f */
    40,	/* gei_f */
    16,	/* gtr_f */
    40,	/* gti_f */
    16,	/* ner_f */
    40,	/* nei_f */
    16,	/* unltr_f */
    40,	/* unlti_f */
    16,	/* unler_f */
    40,	/* unlei_f */
    16,	/* uneqr_f */
    40,	/* uneqi_f */
    16,	/* unger_f */
    40,	/* ungei_f */
    16,	/* ungtr_f */
    40,	/* ungti_f */
    16,	/* ltgtr_f */
    40,	/* ltgti_f */
    16,	/* ordr_f */
    40,	/* ordi_f */
    16,	/* unordr_f */
    40,	/* unordi_f */
    8,	/* truncr_f_i */
    8,	/* truncr_f_l */
    8,	/* extr_f */
    4,	/* extr_d_f */
    4,	/* movr_f */
    24,	/* movi_f */
    4,	/* ldr_f */
    24,	/* ldi_f */
    8,	/* ldxr_f */
    16,	/* ldxi_f */
    4,	/* str_f */
    24,	/* sti_f */
    8,	/* stxr_f */
    16,	/* stxi_f */
    12,	/* bltr_f */
    36,	/* blti_f */
    12,	/* bler_f */
    36,	/* blei_f */
    12,	/* beqr_f */
    36,	/* beqi_f */
    12,	/* bger_f */
    36,	/* bgei_f */
    12,	/* bgtr_f */
    36,	/* bgti_f */
    12,	/* bner_f */
    36,	/* bnei_f */
    12,	/* bunltr_f */
    36,	/* bunlti_f */
    12,	/* bunler_f */
    36,	/* bunlei_f */
    12,	/* buneqr_f */
    36,	/* buneqi_f */
    12,	/* bunger_f */
    36,	/* bungei_f */
    12,	/* bungtr_f */
    36,	/* bungti_f */
    12,	/* bltgtr_f */
    36,	/* bltgti_f */
    12,	/* bordr_f */
    36,	/* bordi_f */
    12,	/* bunordr_f */
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
    28,	/* addi_d */
    4,	/* subr_d */
    28,	/* subi_d */
    28,	/* rsbi_d */
    4,	/* mulr_d */
    28,	/* muli_d */
    4,	/* divr_d */
    28,	/* divi_d */
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
    8,	/* truncr_d_i */
    8,	/* truncr_d_l */
    8,	/* extr_d */
    4,	/* extr_f_d */
    4,	/* movr_d */
    28,	/* movi_d */
    4,	/* ldr_d */
    24,	/* ldi_d */
    8,	/* ldxr_d */
    16,	/* ldxi_d */
    4,	/* str_d */
    24,	/* sti_d */
    8,	/* stxr_d */
    16,	/* stxi_d */
    12,	/* bltr_d */
    36,	/* blti_d */
    12,	/* bler_d */
    36,	/* blei_d */
    12,	/* beqr_d */
    36,	/* beqi_d */
    12,	/* bger_d */
    36,	/* bgei_d */
    12,	/* bgtr_d */
    36,	/* bgti_d */
    12,	/* bner_d */
    40,	/* bnei_d */
    12,	/* bunltr_d */
    40,	/* bunlti_d */
    12,	/* bunler_d */
    40,	/* bunlei_d */
    12,	/* buneqr_d */
    40,	/* buneqi_d */
    12,	/* bunger_d */
    40,	/* bungei_d */
    12,	/* bungtr_d */
    40,	/* bungti_d */
    12,	/* bltgtr_d */
    36,	/* bltgti_d */
    12,	/* bordr_d */
    36,	/* bordi_d */
    12,	/* bunordr_d */
    40,	/* bunordi_d */
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
    4,	/* movr_d_w */
    24,	/* movi_d_w */
    4,	/* clor */
    4,	/* clzr */
    28,	/* ctor */
    20,	/* ctzr */
    76,	/* popcntr */
    12,	/* lrotr */
    4,	/* lroti */
    4,	/* rrotr */
    4,	/* rroti */
#endif /* __WORDSIZE */
