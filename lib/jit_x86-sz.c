
#if __X32
#define JIT_INSTR_MAX 42
    0,	/* data */
    0,	/* live */
    11,	/* align */
    0,	/* save */
    0,	/* load */
    4,	/* skip */
    0,	/* #name */
    0,	/* #note */
    3,	/* label */
    34,	/* prolog */
    0,	/* ellipsis */
    0,	/* va_push */
    0,	/* allocai */
    0,	/* allocar */
    0,	/* arg */
    0,	/* getarg_c */
    0,	/* getarg_uc */
    0,	/* getarg_s */
    0,	/* getarg_us */
    0,	/* getarg_i */
    0,	/* getarg_ui */
    0,	/* getarg_l */
    0,	/* putargr */
    0,	/* putargi */
    3,	/* va_start */
    5,	/* va_arg */
    7,	/* va_arg_d */
    0,	/* va_end */
    3,	/* addr */
    6,	/* addi */
    4,	/* addcr */
    6,	/* addci */
    4,	/* addxr */
    5,	/* addxi */
    4,	/* subr */
    6,	/* subi */
    12,	/* subcr */
    6,	/* subci */
    12,	/* subxr */
    5,	/* subxi */
    8,	/* rsbi */
    5,	/* mulr */
    7,	/* muli */
    20,	/* qmulr */
    25,	/* qmuli */
    20,	/* qmulr_u */
    25,	/* qmuli_u */
    21,	/* divr */
    24,	/* divi */
    22,	/* divr_u */
    25,	/* divi_u */
    23,	/* qdivr */
    28,	/* qdivi */
    24,	/* qdivr_u */
    29,	/* qdivi_u */
    21,	/* remr */
    24,	/* remi */
    22,	/* remr_u */
    25,	/* remi_u */
    4,	/* andr */
    7,	/* andi */
    4,	/* orr */
    8,	/* ori */
    4,	/* xorr */
    8,	/* xori */
    16,	/* lshr */
    7,	/* lshi */
    16,	/* rshr */
    5,	/* rshi */
    16,	/* rshr_u */
    5,	/* rshi_u */
    4,	/* negr */
    4,	/* comr */
    15,	/* ltr */
    16,	/* lti */
    15,	/* ltr_u */
    16,	/* lti_u */
    15,	/* ler */
    16,	/* lei */
    15,	/* ler_u */
    16,	/* lei_u */
    15,	/* eqr */
    16,	/* eqi */
    15,	/* ger */
    16,	/* gei */
    15,	/* ger_u */
    16,	/* gei_u */
    15,	/* gtr */
    16,	/* gti */
    15,	/* gtr_u */
    16,	/* gti_u */
    15,	/* ner */
    16,	/* nei */
    2,	/* movr */
    5,	/* movi */
    5,	/* movnr */
    5,	/* movzr */
    11,	/* extr_c */
    11,	/* extr_uc */
    3,	/* extr_s */
    3,	/* extr_us */
    0,	/* extr_i */
    0,	/* extr_ui */
    7,	/* htonr_us */
    4,	/* htonr_ui */
    0,	/* htonr_ul */
    3,	/* ldr_c */
    7,	/* ldi_c */
    3,	/* ldr_uc */
    7,	/* ldi_uc */
    3,	/* ldr_s */
    7,	/* ldi_s */
    3,	/* ldr_us */
    7,	/* ldi_us */
    2,	/* ldr_i */
    6,	/* ldi_i */
    0,	/* ldr_ui */
    0,	/* ldi_ui */
    0,	/* ldr_l */
    0,	/* ldi_l */
    4,	/* ldxr_c */
    7,	/* ldxi_c */
    4,	/* ldxr_uc */
    7,	/* ldxi_uc */
    4,	/* ldxr_s */
    7,	/* ldxi_s */
    4,	/* ldxr_us */
    7,	/* ldxi_us */
    3,	/* ldxr_i */
    6,	/* ldxi_i */
    0,	/* ldxr_ui */
    0,	/* ldxi_ui */
    0,	/* ldxr_l */
    0,	/* ldxi_l */
    10,	/* str_c */
    14,	/* sti_c */
    3,	/* str_s */
    7,	/* sti_s */
    2,	/* str_i */
    6,	/* sti_i */
    0,	/* str_l */
    0,	/* sti_l */
    11,	/* stxr_c */
    11,	/* stxi_c */
    4,	/* stxr_s */
    7,	/* stxi_s */
    3,	/* stxr_i */
    6,	/* stxi_i */
    0,	/* stxr_l */
    0,	/* stxi_l */
    8,	/* bltr */
    9,	/* blti */
    8,	/* bltr_u */
    9,	/* blti_u */
    8,	/* bler */
    12,	/* blei */
    8,	/* bler_u */
    9,	/* blei_u */
    8,	/* beqr */
    12,	/* beqi */
    8,	/* bger */
    9,	/* bgei */
    8,	/* bger_u */
    9,	/* bgei_u */
    8,	/* bgtr */
    9,	/* bgti */
    8,	/* bgtr_u */
    9,	/* bgti_u */
    8,	/* bner */
    12,	/* bnei */
    8,	/* bmsr */
    12,	/* bmsi */
    8,	/* bmcr */
    12,	/* bmci */
    8,	/* boaddr */
    9,	/* boaddi */
    8,	/* boaddr_u */
    9,	/* boaddi_u */
    8,	/* bxaddr */
    9,	/* bxaddi */
    8,	/* bxaddr_u */
    9,	/* bxaddi_u */
    8,	/* bosubr */
    9,	/* bosubi */
    8,	/* bosubr_u */
    9,	/* bosubi_u */
    8,	/* bxsubr */
    9,	/* bxsubi */
    8,	/* bxsubr_u */
    9,	/* bxsubi_u */
    2,	/* jmpr */
    5,	/* jmpi */
    2,	/* callr */
    5,	/* calli */
    0,	/* prepare */
    0,	/* pushargr */
    0,	/* pushargi */
    0,	/* finishr */
    0,	/* finishi */
    0,	/* ret */
    0,	/* retr */
    0,	/* reti */
    0,	/* retval_c */
    0,	/* retval_uc */
    0,	/* retval_s */
    0,	/* retval_us */
    0,	/* retval_i */
    0,	/* retval_ui */
    0,	/* retval_l */
    23,	/* epilog */
    0,	/* arg_f */
    0,	/* getarg_f */
    0,	/* putargr_f */
    0,	/* putargi_f */
    8,	/* addr_f */
    17,	/* addi_f */
    12,	/* subr_f */
    17,	/* subi_f */
    21,	/* rsbi_f */
    8,	/* mulr_f */
    17,	/* muli_f */
    12,	/* divr_f */
    17,	/* divi_f */
    12,	/* negr_f */
    12,	/* absr_f */
    4,	/* sqrtr_f */
    12,	/* ltr_f */
    27,	/* lti_f */
    12,	/* ler_f */
    27,	/* lei_f */
    14,	/* eqr_f */
    29,	/* eqi_f */
    12,	/* ger_f */
    27,	/* gei_f */
    12,	/* gtr_f */
    27,	/* gti_f */
    17,	/* ner_f */
    32,	/* nei_f */
    12,	/* unltr_f */
    27,	/* unlti_f */
    12,	/* unler_f */
    27,	/* unlei_f */
    12,	/* uneqr_f */
    27,	/* uneqi_f */
    12,	/* unger_f */
    27,	/* ungei_f */
    12,	/* ungtr_f */
    27,	/* ungti_f */
    12,	/* ltgtr_f */
    27,	/* ltgti_f */
    12,	/* ordr_f */
    27,	/* ordi_f */
    12,	/* unordr_f */
    27,	/* unordi_f */
    4,	/* truncr_f_i */
    0,	/* truncr_f_l */
    4,	/* extr_f */
    4,	/* extr_d_f */
    10,	/* movr_f */
    15,	/* movi_f */
    4,	/* ldr_f */
    8,	/* ldi_f */
    5,	/* ldxr_f */
    8,	/* ldxi_f */
    4,	/* str_f */
    8,	/* sti_f */
    5,	/* stxr_f */
    8,	/* stxi_f */
    9,	/* bltr_f */
    18,	/* blti_f */
    9,	/* bler_f */
    18,	/* blei_f */
    11,	/* beqr_f */
    20,	/* beqi_f */
    9,	/* bger_f */
    18,	/* bgei_f */
    9,	/* bgtr_f */
    18,	/* bgti_f */
    12,	/* bner_f */
    21,	/* bnei_f */
    9,	/* bunltr_f */
    18,	/* bunlti_f */
    9,	/* bunler_f */
    18,	/* bunlei_f */
    9,	/* buneqr_f */
    18,	/* buneqi_f */
    9,	/* bunger_f */
    18,	/* bungei_f */
    9,	/* bungtr_f */
    18,	/* bungti_f */
    9,	/* bltgtr_f */
    18,	/* bltgti_f */
    9,	/* bordr_f */
    18,	/* bordi_f */
    9,	/* bunordr_f */
    18,	/* bunordi_f */
    0,	/* pushargr_f */
    0,	/* pushargi_f */
    0,	/* retr_f */
    0,	/* reti_f */
    10,	/* retval_f */
    0,	/* arg_d */
    0,	/* getarg_d */
    0,	/* putargr_d */
    0,	/* putargi_d */
    8,	/* addr_d */
    26,	/* addi_d */
    12,	/* subr_d */
    26,	/* subi_d */
    30,	/* rsbi_d */
    8,	/* mulr_d */
    26,	/* muli_d */
    12,	/* divr_d */
    26,	/* divi_d */
    18,	/* negr_d */
    13,	/* absr_d */
    4,	/* sqrtr_d */
    13,	/* ltr_d */
    37,	/* lti_d */
    13,	/* ler_d */
    37,	/* lei_d */
    15,	/* eqr_d */
    39,	/* eqi_d */
    13,	/* ger_d */
    37,	/* gei_d */
    13,	/* gtr_d */
    37,	/* gti_d */
    18,	/* ner_d */
    42,	/* nei_d */
    13,	/* unltr_d */
    37,	/* unlti_d */
    13,	/* unler_d */
    37,	/* unlei_d */
    13,	/* uneqr_d */
    37,	/* uneqi_d */
    13,	/* unger_d */
    37,	/* ungei_d */
    13,	/* ungtr_d */
    37,	/* ungti_d */
    13,	/* ltgtr_d */
    37,	/* ltgti_d */
    13,	/* ordr_d */
    37,	/* ordi_d */
    13,	/* unordr_d */
    37,	/* unordi_d */
    4,	/* truncr_d_i */
    0,	/* truncr_d_l */
    4,	/* extr_d */
    4,	/* extr_f_d */
    10,	/* movr_d */
    30,	/* movi_d */
    4,	/* ldr_d */
    8,	/* ldi_d */
    5,	/* ldxr_d */
    8,	/* ldxi_d */
    4,	/* str_d */
    8,	/* sti_d */
    5,	/* stxr_d */
    8,	/* stxi_d */
    10,	/* bltr_d */
    28,	/* blti_d */
    10,	/* bler_d */
    28,	/* blei_d */
    12,	/* beqr_d */
    30,	/* beqi_d */
    10,	/* bger_d */
    28,	/* bgei_d */
    10,	/* bgtr_d */
    28,	/* bgti_d */
    13,	/* bner_d */
    31,	/* bnei_d */
    10,	/* bunltr_d */
    28,	/* bunlti_d */
    10,	/* bunler_d */
    28,	/* bunlei_d */
    10,	/* buneqr_d */
    28,	/* buneqi_d */
    10,	/* bunger_d */
    28,	/* bungei_d */
    10,	/* bungtr_d */
    28,	/* bungti_d */
    10,	/* bltgtr_d */
    28,	/* bltgti_d */
    10,	/* bordr_d */
    28,	/* bordi_d */
    10,	/* bunordr_d */
    28,	/* bunordi_d */
    0,	/* pushargr_d */
    0,	/* pushargi_d */
    0,	/* retr_d */
    0,	/* reti_d */
    10,	/* retval_d */
    0,	/* movr_w_f */
    0,	/* movr_ww_d */
    0,	/* movr_w_d */
    0,	/* movr_f_w */
    0,	/* movi_f_w */
    0,	/* movr_d_ww */
    0,	/* movi_d_ww */
    0,	/* movr_d_w */
    0,	/* movi_d_w */
    7,	/* bswapr_us */
    4,	/* bswapr_ui */
    0,	/* bswapr_ul */
    9,	/* casr */
    13,	/* casi */
#endif

#if __X64
#if __CYGWIN__ || _WIN32
#define JIT_INSTR_MAX 130
    0,	/* data */
    0,	/* live */
    27,	/* align */
    0,	/* save */
    0,	/* load */
    4,	/* skip */
    0,	/* #name */
    0,	/* #note */
    7,	/* label */
    130,	/* prolog */
    0,	/* ellipsis */
    0,	/* va_push */
    0,	/* allocai */
    0,	/* allocar */
    0,	/* arg */
    0,	/* getarg_c */
    0,	/* getarg_uc */
    0,	/* getarg_s */
    0,	/* getarg_us */
    0,	/* getarg_i */
    0,	/* getarg_ui */
    0,	/* getarg_l */
    0,	/* putargr */
    0,	/* putargi */
    7,	/* va_start */
    7,	/* va_arg */
    9,	/* va_arg_d */
    0,	/* va_end */
    4,	/* addr */
    13,	/* addi */
    6,	/* addcr */
    13,	/* addci */
    6,	/* addxr */
    7,	/* addxi */
    6,	/* subr */
    13,	/* subi */
    9,	/* subcr */
    13,	/* subci */
    9,	/* subxr */
    7,	/* subxi */
    16,	/* rsbi */
    7,	/* mulr */
    14,	/* muli */
    20,	/* qmulr */
    30,	/* qmuli */
    20,	/* qmulr_u */
    30,	/* qmuli_u */
    22,	/* divr */
    29,	/* divi */
    23,	/* divr_u */
    30,	/* divi_u */
    25,	/* qdivr */
    32,	/* qdivi */
    26,	/* qdivr_u */
    33,	/* qdivi_u */
    22,	/* remr */
    29,	/* remi */
    23,	/* remr_u */
    30,	/* remi_u */
    6,	/* andr */
    13,	/* andi */
    6,	/* orr */
    13,	/* ori */
    6,	/* xorr */
    13,	/* xori */
    9,	/* lshr */
    8,	/* lshi */
    9,	/* rshr */
    7,	/* rshi */
    9,	/* rshr_u */
    7,	/* rshi_u */
    6,	/* negr */
    6,	/* comr */
    13,	/* ltr */
    14,	/* lti */
    13,	/* ltr_u */
    14,	/* lti_u */
    13,	/* ler */
    14,	/* lei */
    13,	/* ler_u */
    14,	/* lei_u */
    13,	/* eqr */
    14,	/* eqi */
    13,	/* ger */
    14,	/* gei */
    13,	/* ger_u */
    14,	/* gei_u */
    13,	/* gtr */
    14,	/* gti */
    13,	/* gtr_u */
    14,	/* gti_u */
    13,	/* ner */
    14,	/* nei */
    3,	/* movr */
    10,	/* movi */
    7,	/* movnr */
    7,	/* movzr */
    7,	/* extr_c */
    7,	/* extr_uc */
    4,	/* extr_s */
    4,	/* extr_us */
    3,	/* extr_i */
    3,	/* extr_ui */
    9,	/* htonr_us */
    6,	/* htonr_ui */
    6,	/* htonr_ul */
    4,	/* ldr_c */
    14,	/* ldi_c */
    4,	/* ldr_uc */
    14,	/* ldi_uc */
    4,	/* ldr_s */
    14,	/* ldi_s */
    4,	/* ldr_us */
    14,	/* ldi_us */
    3,	/* ldr_i */
    13,	/* ldi_i */
    3,	/* ldr_ui */
    13,	/* ldi_ui */
    3,	/* ldr_l */
    13,	/* ldi_l */
    5,	/* ldxr_c */
    8,	/* ldxi_c */
    5,	/* ldxr_uc */
    8,	/* ldxi_uc */
    5,	/* ldxr_s */
    8,	/* ldxi_s */
    5,	/* ldxr_us */
    8,	/* ldxi_us */
    4,	/* ldxr_i */
    7,	/* ldxi_i */
    4,	/* ldxr_ui */
    6,	/* ldxi_ui */
    4,	/* ldxr_l */
    7,	/* ldxi_l */
    6,	/* str_c */
    16,	/* sti_c */
    4,	/* str_s */
    14,	/* sti_s */
    3,	/* str_i */
    13,	/* sti_i */
    3,	/* str_l */
    13,	/* sti_l */
    7,	/* stxr_c */
    7,	/* stxi_c */
    5,	/* stxr_s */
    7,	/* stxi_s */
    4,	/* stxr_i */
    6,	/* stxi_i */
    4,	/* stxr_l */
    8,	/* stxi_l */
    9,	/* bltr */
    10,	/* blti */
    9,	/* bltr_u */
    10,	/* blti_u */
    9,	/* bler */
    13,	/* blei */
    9,	/* bler_u */
    10,	/* blei_u */
    9,	/* beqr */
    19,	/* beqi */
    9,	/* bger */
    10,	/* bgei */
    9,	/* bger_u */
    10,	/* bgei_u */
    9,	/* bgtr */
    10,	/* bgti */
    9,	/* bgtr_u */
    10,	/* bgti_u */
    9,	/* bner */
    19,	/* bnei */
    9,	/* bmsr */
    13,	/* bmsi */
    9,	/* bmcr */
    13,	/* bmci */
    9,	/* boaddr */
    10,	/* boaddi */
    9,	/* boaddr_u */
    10,	/* boaddi_u */
    9,	/* bxaddr */
    10,	/* bxaddi */
    9,	/* bxaddr_u */
    10,	/* bxaddi_u */
    9,	/* bosubr */
    10,	/* bosubi */
    9,	/* bosubr_u */
    10,	/* bosubi_u */
    9,	/* bxsubr */
    10,	/* bxsubi */
    9,	/* bxsubr_u */
    10,	/* bxsubi_u */
    2,	/* jmpr */
    5,	/* jmpi */
    2,	/* callr */
    20,	/* calli */
    0,	/* prepare */
    0,	/* pushargr */
    0,	/* pushargi */
    0,	/* finishr */
    0,	/* finishi */
    0,	/* ret */
    0,	/* retr */
    0,	/* reti */
    0,	/* retval_c */
    0,	/* retval_uc */
    0,	/* retval_s */
    0,	/* retval_us */
    0,	/* retval_i */
    0,	/* retval_ui */
    0,	/* retval_l */
    124,	/* epilog */
    0,	/* arg_f */
    0,	/* getarg_f */
    0,	/* putargr_f */
    0,	/* putargi_f */
    10,	/* addr_f */
    19,	/* addi_f */
    15,	/* subr_f */
    19,	/* subi_f */
    26,	/* rsbi_f */
    10,	/* mulr_f */
    19,	/* muli_f */
    15,	/* divr_f */
    19,	/* divi_f */
    14,	/* negr_f */
    15,	/* absr_f */
    5,	/* sqrtr_f */
    16,	/* ltr_f */
    30,	/* lti_f */
    16,	/* ler_f */
    30,	/* lei_f */
    18,	/* eqr_f */
    32,	/* eqi_f */
    16,	/* ger_f */
    30,	/* gei_f */
    16,	/* gtr_f */
    30,	/* gti_f */
    20,	/* ner_f */
    34,	/* nei_f */
    16,	/* unltr_f */
    30,	/* unlti_f */
    16,	/* unler_f */
    30,	/* unlei_f */
    16,	/* uneqr_f */
    30,	/* uneqi_f */
    16,	/* unger_f */
    30,	/* ungei_f */
    16,	/* ungtr_f */
    30,	/* ungti_f */
    16,	/* ltgtr_f */
    30,	/* ltgti_f */
    16,	/* ordr_f */
    30,	/* ordi_f */
    16,	/* unordr_f */
    30,	/* unordi_f */
    5,	/* truncr_f_i */
    5,	/* truncr_f_l */
    5,	/* extr_f */
    5,	/* extr_d_f */
    5,	/* movr_f */
    18,	/* movi_f */
    5,	/* ldr_f */
    15,	/* ldi_f */
    6,	/* ldxr_f */
    8,	/* ldxi_f */
    5,	/* str_f */
    15,	/* sti_f */
    6,	/* stxr_f */
    9,	/* stxi_f */
    10,	/* bltr_f */
    19,	/* blti_f */
    10,	/* bler_f */
    23,	/* blei_f */
    12,	/* beqr_f */
    27,	/* beqi_f */
    10,	/* bger_f */
    24,	/* bgei_f */
    10,	/* bgtr_f */
    24,	/* bgti_f */
    13,	/* bner_f */
    27,	/* bnei_f */
    10,	/* bunltr_f */
    24,	/* bunlti_f */
    10,	/* bunler_f */
    24,	/* bunlei_f */
    10,	/* buneqr_f */
    24,	/* buneqi_f */
    10,	/* bunger_f */
    24,	/* bungei_f */
    10,	/* bungtr_f */
    24,	/* bungti_f */
    10,	/* bltgtr_f */
    24,	/* bltgti_f */
    10,	/* bordr_f */
    24,	/* bordi_f */
    10,	/* bunordr_f */
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
    10,	/* addr_d */
    25,	/* addi_d */
    15,	/* subr_d */
    25,	/* subi_d */
    27,	/* rsbi_d */
    10,	/* mulr_d */
    25,	/* muli_d */
    15,	/* divr_d */
    25,	/* divi_d */
    21,	/* negr_d */
    16,	/* absr_d */
    5,	/* sqrtr_d */
    17,	/* ltr_d */
    32,	/* lti_d */
    17,	/* ler_d */
    32,	/* lei_d */
    19,	/* eqr_d */
    34,	/* eqi_d */
    17,	/* ger_d */
    32,	/* gei_d */
    17,	/* gtr_d */
    32,	/* gti_d */
    21,	/* ner_d */
    36,	/* nei_d */
    17,	/* unltr_d */
    32,	/* unlti_d */
    17,	/* unler_d */
    32,	/* unlei_d */
    17,	/* uneqr_d */
    32,	/* uneqi_d */
    17,	/* unger_d */
    32,	/* ungei_d */
    17,	/* ungtr_d */
    32,	/* ungti_d */
    17,	/* ltgtr_d */
    32,	/* ltgti_d */
    17,	/* ordr_d */
    32,	/* ordi_d */
    17,	/* unordr_d */
    32,	/* unordi_d */
    5,	/* truncr_d_i */
    5,	/* truncr_d_l */
    5,	/* extr_d */
    5,	/* extr_f_d */
    5,	/* movr_d */
    29,	/* movi_d */
    5,	/* ldr_d */
    15,	/* ldi_d */
    6,	/* ldxr_d */
    8,	/* ldxi_d */
    5,	/* str_d */
    15,	/* sti_d */
    6,	/* stxr_d */
    9,	/* stxi_d */
    11,	/* bltr_d */
    26,	/* blti_d */
    11,	/* bler_d */
    26,	/* blei_d */
    13,	/* beqr_d */
    28,	/* beqi_d */
    11,	/* bger_d */
    26,	/* bgei_d */
    11,	/* bgtr_d */
    26,	/* bgti_d */
    14,	/* bner_d */
    29,	/* bnei_d */
    11,	/* bunltr_d */
    26,	/* bunlti_d */
    11,	/* bunler_d */
    26,	/* bunlei_d */
    11,	/* buneqr_d */
    26,	/* buneqi_d */
    11,	/* bunger_d */
    26,	/* bungei_d */
    11,	/* bungtr_d */
    26,	/* bungti_d */
    11,	/* bltgtr_d */
    26,	/* bltgti_d */
    11,	/* bordr_d */
    26,	/* bordi_d */
    11,	/* bunordr_d */
    26,	/* bunordi_d */
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
    9,	/* bswapr_us */
    6,	/* bswapr_ui */
    6,	/* bswapr_ul */
    11,	/* casr */
    21,	/* casi */
#else

#  if __X64_32
#define JIT_INSTR_MAX 108
    0,	/* data */
    0,	/* live */
    7,	/* align */
    0,	/* save */
    0,	/* load */
    4,	/* skip */
    0,	/* #name */
    0,	/* #note */
    3,	/* label */
    108,	/* prolog */
    0,	/* ellipsis */
    0,	/* va_push */
    0,	/* allocai */
    0,	/* allocar */
    0,	/* arg */
    0,	/* getarg_c */
    0,	/* getarg_uc */
    0,	/* getarg_s */
    0,	/* getarg_us */
    0,	/* getarg_i */
    0,	/* getarg_ui */
    0,	/* getarg_l */
    0,	/* putargr */
    0,	/* putargi */
    33,	/* va_start */
    43,	/* va_arg */
    45,	/* va_arg_d */
    0,	/* va_end */
    5,	/* addr */
    7,	/* addi */
    6,	/* addcr */
    7,	/* addci */
    6,	/* addxr */
    7,	/* addxi */
    6,	/* subr */
    7,	/* subi */
    9,	/* subcr */
    7,	/* subci */
    9,	/* subxr */
    7,	/* subxi */
    10,	/* rsbi */
    7,	/* mulr */
    8,	/* muli */
    18,	/* qmulr */
    24,	/* qmuli */
    18,	/* qmulr_u */
    24,	/* qmuli_u */
    19,	/* divr */
    22,	/* divi */
    20,	/* divr_u */
    23,	/* divi_u */
    22,	/* qdivr */
    25,	/* qdivi */
    23,	/* qdivr_u */
    26,	/* qdivi_u */
    19,	/* remr */
    22,	/* remi */
    20,	/* remr_u */
    23,	/* remi_u */
    6,	/* andr */
    9,	/* andi */
    6,	/* orr */
    10,	/* ori */
    6,	/* xorr */
    10,	/* xori */
    9,	/* lshr */
    8,	/* lshi */
    9,	/* rshr */
    7,	/* rshi */
    9,	/* rshr_u */
    7,	/* rshi_u */
    6,	/* negr */
    6,	/* comr */
    13,	/* ltr */
    14,	/* lti */
    13,	/* ltr_u */
    14,	/* lti_u */
    13,	/* ler */
    14,	/* lei */
    13,	/* ler_u */
    14,	/* lei_u */
    13,	/* eqr */
    14,	/* eqi */
    13,	/* ger */
    14,	/* gei */
    13,	/* ger_u */
    14,	/* gei_u */
    13,	/* gtr */
    14,	/* gti */
    13,	/* gtr_u */
    14,	/* gti_u */
    13,	/* ner */
    14,	/* nei */
    3,	/* movr */
    6,	/* movi */
    7,	/* movnr */
    7,	/* movzr */
    7,	/* extr_c */
    7,	/* extr_uc */
    4,	/* extr_s */
    4,	/* extr_us */
    0,	/* extr_i */
    0,	/* extr_ui */
    9,	/* htonr_us */
    6,	/* htonr_ui */
    0,	/* htonr_ul */
    5,	/* ldr_c */
    9,	/* ldi_c */
    5,	/* ldr_uc */
    9,	/* ldi_uc */
    5,	/* ldr_s */
    9,	/* ldi_s */
    5,	/* ldr_us */
    9,	/* ldi_us */
    4,	/* ldr_i */
    8,	/* ldi_i */
    0,	/* ldr_ui */
    0,	/* ldi_ui */
    0,	/* ldr_l */
    0,	/* ldi_l */
    9,	/* ldxr_c */
    7,	/* ldxi_c */
    9,	/* ldxr_uc */
    7,	/* ldxi_uc */
    9,	/* ldxr_s */
    7,	/* ldxi_s */
    9,	/* ldxr_us */
    7,	/* ldxi_us */
    8,	/* ldxr_i */
    7,	/* ldxi_i */
    0,	/* ldxr_ui */
    0,	/* ldxi_ui */
    0,	/* ldxr_l */
    0,	/* ldxi_l */
    7,	/* str_c */
    11,	/* sti_c */
    5,	/* str_s */
    9,	/* sti_s */
    4,	/* str_i */
    8,	/* sti_i */
    0,	/* str_l */
    0,	/* sti_l */
    11,	/* stxr_c */
    7,	/* stxi_c */
    9,	/* stxr_s */
    7,	/* stxi_s */
    8,	/* stxr_i */
    6,	/* stxi_i */
    0,	/* stxr_l */
    0,	/* stxi_l */
    9,	/* bltr */
    10,	/* blti */
    9,	/* bltr_u */
    10,	/* blti_u */
    9,	/* bler */
    12,	/* blei */
    9,	/* bler_u */
    10,	/* blei_u */
    9,	/* beqr */
    13,	/* beqi */
    9,	/* bger */
    10,	/* bgei */
    9,	/* bger_u */
    10,	/* bgei_u */
    9,	/* bgtr */
    10,	/* bgti */
    9,	/* bgtr_u */
    10,	/* bgti_u */
    9,	/* bner */
    13,	/* bnei */
    9,	/* bmsr */
    13,	/* bmsi */
    9,	/* bmcr */
    13,	/* bmci */
    9,	/* boaddr */
    10,	/* boaddi */
    9,	/* boaddr_u */
    10,	/* boaddi_u */
    9,	/* bxaddr */
    10,	/* bxaddi */
    9,	/* bxaddr_u */
    10,	/* bxaddi_u */
    9,	/* bosubr */
    10,	/* bosubi */
    9,	/* bosubr_u */
    10,	/* bosubi_u */
    9,	/* bxsubr */
    10,	/* bxsubi */
    9,	/* bxsubr_u */
    10,	/* bxsubi_u */
    2,	/* jmpr */
    5,	/* jmpi */
    2,	/* callr */
    9,	/* calli */
    0,	/* prepare */
    0,	/* pushargr */
    0,	/* pushargi */
    0,	/* finishr */
    0,	/* finishi */
    0,	/* ret */
    0,	/* retr */
    0,	/* reti */
    0,	/* retval_c */
    0,	/* retval_uc */
    0,	/* retval_s */
    0,	/* retval_us */
    0,	/* retval_i */
    0,	/* retval_ui */
    0,	/* retval_l */
    34,	/* epilog */
    0,	/* arg_f */
    0,	/* getarg_f */
    0,	/* putargr_f */
    0,	/* putargi_f */
    10,	/* addr_f */
    20,	/* addi_f */
    15,	/* subr_f */
    20,	/* subi_f */
    25,	/* rsbi_f */
    10,	/* mulr_f */
    20,	/* muli_f */
    15,	/* divr_f */
    20,	/* divi_f */
    15,	/* negr_f */
    15,	/* absr_f */
    5,	/* sqrtr_f */
    15,	/* ltr_f */
    26,	/* lti_f */
    15,	/* ler_f */
    26,	/* lei_f */
    17,	/* eqr_f */
    28,	/* eqi_f */
    15,	/* ger_f */
    26,	/* gei_f */
    15,	/* gtr_f */
    26,	/* gti_f */
    20,	/* ner_f */
    31,	/* nei_f */
    15,	/* unltr_f */
    26,	/* unlti_f */
    15,	/* unler_f */
    26,	/* unlei_f */
    15,	/* uneqr_f */
    26,	/* uneqi_f */
    15,	/* unger_f */
    26,	/* ungei_f */
    15,	/* ungtr_f */
    26,	/* ungti_f */
    15,	/* ltgtr_f */
    26,	/* ltgti_f */
    15,	/* ordr_f */
    26,	/* ordi_f */
    15,	/* unordr_f */
    26,	/* unordi_f */
    5,	/* truncr_f_i */
    0,	/* truncr_f_l */
    5,	/* extr_f */
    5,	/* extr_d_f */
    5,	/* movr_f */
    11,	/* movi_f */
    6,	/* ldr_f */
    10,	/* ldi_f */
    10,	/* ldxr_f */
    9,	/* ldxi_f */
    6,	/* str_f */
    10,	/* sti_f */
    10,	/* stxr_f */
    9,	/* stxi_f */
    10,	/* bltr_f */
    20,	/* blti_f */
    10,	/* bler_f */
    20,	/* blei_f */
    12,	/* beqr_f */
    23,	/* beqi_f */
    10,	/* bger_f */
    20,	/* bgei_f */
    10,	/* bgtr_f */
    20,	/* bgti_f */
    13,	/* bner_f */
    23,	/* bnei_f */
    10,	/* bunltr_f */
    20,	/* bunlti_f */
    10,	/* bunler_f */
    20,	/* bunlei_f */
    10,	/* buneqr_f */
    20,	/* buneqi_f */
    10,	/* bunger_f */
    20,	/* bungei_f */
    10,	/* bungtr_f */
    20,	/* bungti_f */
    10,	/* bltgtr_f */
    20,	/* bltgti_f */
    10,	/* bordr_f */
    20,	/* bordi_f */
    10,	/* bunordr_f */
    20,	/* bunordi_f */
    0,	/* pushargr_f */
    0,	/* pushargi_f */
    0,	/* retr_f */
    0,	/* reti_f */
    0,	/* retval_f */
    0,	/* arg_d */
    0,	/* getarg_d */
    0,	/* putargr_d */
    0,	/* putargi_d */
    10,	/* addr_d */
    29,	/* addi_d */
    15,	/* subr_d */
    29,	/* subi_d */
    34,	/* rsbi_d */
    10,	/* mulr_d */
    29,	/* muli_d */
    15,	/* divr_d */
    29,	/* divi_d */
    22,	/* negr_d */
    16,	/* absr_d */
    5,	/* sqrtr_d */
    16,	/* ltr_d */
    39,	/* lti_d */
    16,	/* ler_d */
    39,	/* lei_d */
    18,	/* eqr_d */
    41,	/* eqi_d */
    16,	/* ger_d */
    39,	/* gei_d */
    16,	/* gtr_d */
    39,	/* gti_d */
    21,	/* ner_d */
    44,	/* nei_d */
    16,	/* unltr_d */
    39,	/* unlti_d */
    16,	/* unler_d */
    39,	/* unlei_d */
    16,	/* uneqr_d */
    39,	/* uneqi_d */
    16,	/* unger_d */
    39,	/* ungei_d */
    16,	/* ungtr_d */
    39,	/* ungti_d */
    16,	/* ltgtr_d */
    39,	/* ltgti_d */
    16,	/* ordr_d */
    39,	/* ordi_d */
    16,	/* unordr_d */
    39,	/* unordi_d */
    5,	/* truncr_d_i */
    0,	/* truncr_d_l */
    5,	/* extr_d */
    5,	/* extr_f_d */
    5,	/* movr_d */
    23,	/* movi_d */
    6,	/* ldr_d */
    10,	/* ldi_d */
    10,	/* ldxr_d */
    9,	/* ldxi_d */
    6,	/* str_d */
    10,	/* sti_d */
    10,	/* stxr_d */
    9,	/* stxi_d */
    11,	/* bltr_d */
    30,	/* blti_d */
    11,	/* bler_d */
    30,	/* blei_d */
    13,	/* beqr_d */
    36,	/* beqi_d */
    11,	/* bger_d */
    30,	/* bgei_d */
    11,	/* bgtr_d */
    30,	/* bgti_d */
    14,	/* bner_d */
    33,	/* bnei_d */
    11,	/* bunltr_d */
    30,	/* bunlti_d */
    11,	/* bunler_d */
    30,	/* bunlei_d */
    11,	/* buneqr_d */
    30,	/* buneqi_d */
    11,	/* bunger_d */
    30,	/* bungei_d */
    11,	/* bungtr_d */
    30,	/* bungti_d */
    11,	/* bltgtr_d */
    30,	/* bltgti_d */
    11,	/* bordr_d */
    30,	/* bordi_d */
    11,	/* bunordr_d */
    30,	/* bunordi_d */
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
    9,	/* bswapr_us */
    6,	/* bswapr_ui */
    0,	/* bswapr_ul */
    11,	/* casr */
    16,	/* casi */
#  else

#define JIT_INSTR_MAX 115
    0,	/* data */
    0,	/* live */
    27,	/* align */
    0,	/* save */
    0,	/* load */
    4,	/* skip */
    0,	/* #name */
    0,	/* #note */
    7,	/* label */
    115,	/* prolog */
    0,	/* ellipsis */
    0,	/* va_push */
    0,	/* allocai */
    0,	/* allocar */
    0,	/* arg */
    0,	/* getarg_c */
    0,	/* getarg_uc */
    0,	/* getarg_s */
    0,	/* getarg_us */
    0,	/* getarg_i */
    0,	/* getarg_ui */
    0,	/* getarg_l */
    0,	/* putargr */
    0,	/* putargi */
    38,	/* va_start */
    41,	/* va_arg */
    48,	/* va_arg_d */
    0,	/* va_end */
    5,	/* addr */
    13,	/* addi */
    6,	/* addcr */
    13,	/* addci */
    6,	/* addxr */
    7,	/* addxi */
    6,	/* subr */
    13,	/* subi */
    9,	/* subcr */
    13,	/* subci */
    9,	/* subxr */
    7,	/* subxi */
    16,	/* rsbi */
    7,	/* mulr */
    14,	/* muli */
    20,	/* qmulr */
    30,	/* qmuli */
    20,	/* qmulr_u */
    30,	/* qmuli_u */
    22,	/* divr */
    29,	/* divi */
    23,	/* divr_u */
    30,	/* divi_u */
    25,	/* qdivr */
    32,	/* qdivi */
    26,	/* qdivr_u */
    33,	/* qdivi_u */
    22,	/* remr */
    29,	/* remi */
    23,	/* remr_u */
    30,	/* remi_u */
    6,	/* andr */
    13,	/* andi */
    6,	/* orr */
    13,	/* ori */
    6,	/* xorr */
    13,	/* xori */
    9,	/* lshr */
    8,	/* lshi */
    9,	/* rshr */
    7,	/* rshi */
    9,	/* rshr_u */
    7,	/* rshi_u */
    6,	/* negr */
    6,	/* comr */
    13,	/* ltr */
    14,	/* lti */
    13,	/* ltr_u */
    14,	/* lti_u */
    13,	/* ler */
    14,	/* lei */
    13,	/* ler_u */
    14,	/* lei_u */
    13,	/* eqr */
    14,	/* eqi */
    13,	/* ger */
    14,	/* gei */
    13,	/* ger_u */
    14,	/* gei_u */
    13,	/* gtr */
    14,	/* gti */
    13,	/* gtr_u */
    14,	/* gti_u */
    13,	/* ner */
    14,	/* nei */
    3,	/* movr */
    10,	/* movi */
    7,	/* movnr */
    7,	/* movzr */
    4,	/* extr_c */
    4,	/* extr_uc */
    4,	/* extr_s */
    4,	/* extr_us */
    3,	/* extr_i */
    3,	/* extr_ui */
    9,	/* htonr_us */
    6,	/* htonr_ui */
    6,	/* htonr_ul */
    5,	/* ldr_c */
    9,	/* ldi_c */
    5,	/* ldr_uc */
    9,	/* ldi_uc */
    5,	/* ldr_s */
    9,	/* ldi_s */
    5,	/* ldr_us */
    9,	/* ldi_us */
    4,	/* ldr_i */
    8,	/* ldi_i */
    4,	/* ldr_ui */
    8,	/* ldi_ui */
    4,	/* ldr_l */
    8,	/* ldi_l */
    6,	/* ldxr_c */
    8,	/* ldxi_c */
    6,	/* ldxr_uc */
    8,	/* ldxi_uc */
    6,	/* ldxr_s */
    8,	/* ldxi_s */
    6,	/* ldxr_us */
    8,	/* ldxi_us */
    5,	/* ldxr_i */
    7,	/* ldxi_i */
    5,	/* ldxr_ui */
    6,	/* ldxi_ui */
    5,	/* ldxr_l */
    7,	/* ldxi_l */
    4,	/* str_c */
    8,	/* sti_c */
    5,	/* str_s */
    9,	/* sti_s */
    4,	/* str_i */
    8,	/* sti_i */
    4,	/* str_l */
    8,	/* sti_l */
    5,	/* stxr_c */
    6,	/* stxi_c */
    6,	/* stxr_s */
    7,	/* stxi_s */
    5,	/* stxr_i */
    6,	/* stxi_i */
    5,	/* stxr_l */
    7,	/* stxi_l */
    9,	/* bltr */
    10,	/* blti */
    9,	/* bltr_u */
    10,	/* blti_u */
    9,	/* bler */
    13,	/* blei */
    9,	/* bler_u */
    10,	/* blei_u */
    9,	/* beqr */
    19,	/* beqi */
    9,	/* bger */
    10,	/* bgei */
    9,	/* bger_u */
    10,	/* bgei_u */
    9,	/* bgtr */
    10,	/* bgti */
    9,	/* bgtr_u */
    10,	/* bgti_u */
    9,	/* bner */
    19,	/* bnei */
    9,	/* bmsr */
    13,	/* bmsi */
    9,	/* bmcr */
    13,	/* bmci */
    9,	/* boaddr */
    10,	/* boaddi */
    9,	/* boaddr_u */
    10,	/* boaddi_u */
    9,	/* bxaddr */
    10,	/* bxaddi */
    9,	/* bxaddr_u */
    10,	/* bxaddi_u */
    9,	/* bosubr */
    10,	/* bosubi */
    9,	/* bosubr_u */
    10,	/* bosubi_u */
    9,	/* bxsubr */
    10,	/* bxsubi */
    9,	/* bxsubr_u */
    10,	/* bxsubi_u */
    2,	/* jmpr */
    5,	/* jmpi */
    2,	/* callr */
    13,	/* calli */
    0,	/* prepare */
    0,	/* pushargr */
    0,	/* pushargi */
    0,	/* finishr */
    0,	/* finishi */
    0,	/* ret */
    0,	/* retr */
    0,	/* reti */
    0,	/* retval_c */
    0,	/* retval_uc */
    0,	/* retval_s */
    0,	/* retval_us */
    0,	/* retval_i */
    0,	/* retval_ui */
    0,	/* retval_l */
    37,	/* epilog */
    0,	/* arg_f */
    0,	/* getarg_f */
    0,	/* putargr_f */
    0,	/* putargi_f */
    10,	/* addr_f */
    20,	/* addi_f */
    15,	/* subr_f */
    20,	/* subi_f */
    30,	/* rsbi_f */
    10,	/* mulr_f */
    20,	/* muli_f */
    15,	/* divr_f */
    20,	/* divi_f */
    15,	/* negr_f */
    15,	/* absr_f */
    5,	/* sqrtr_f */
    11,	/* ltr_f */
    26,	/* lti_f */
    11,	/* ler_f */
    26,	/* lei_f */
    13,	/* eqr_f */
    28,	/* eqi_f */
    11,	/* ger_f */
    26,	/* gei_f */
    11,	/* gtr_f */
    26,	/* gti_f */
    16,	/* ner_f */
    31,	/* nei_f */
    11,	/* unltr_f */
    26,	/* unlti_f */
    11,	/* unler_f */
    26,	/* unlei_f */
    11,	/* uneqr_f */
    26,	/* uneqi_f */
    11,	/* unger_f */
    26,	/* ungei_f */
    11,	/* ungtr_f */
    26,	/* ungti_f */
    11,	/* ltgtr_f */
    26,	/* ltgti_f */
    11,	/* ordr_f */
    26,	/* ordi_f */
    11,	/* unordr_f */
    26,	/* unordi_f */
    5,	/* truncr_f_i */
    5,	/* truncr_f_l */
    5,	/* extr_f */
    5,	/* extr_d_f */
    5,	/* movr_f */
    15,	/* movi_f */
    6,	/* ldr_f */
    10,	/* ldi_f */
    7,	/* ldxr_f */
    9,	/* ldxi_f */
    6,	/* str_f */
    10,	/* sti_f */
    7,	/* stxr_f */
    9,	/* stxi_f */
    10,	/* bltr_f */
    20,	/* blti_f */
    10,	/* bler_f */
    25,	/* blei_f */
    12,	/* beqr_f */
    27,	/* beqi_f */
    10,	/* bger_f */
    25,	/* bgei_f */
    10,	/* bgtr_f */
    25,	/* bgti_f */
    13,	/* bner_f */
    28,	/* bnei_f */
    10,	/* bunltr_f */
    25,	/* bunlti_f */
    10,	/* bunler_f */
    25,	/* bunlei_f */
    10,	/* buneqr_f */
    25,	/* buneqi_f */
    10,	/* bunger_f */
    25,	/* bungei_f */
    10,	/* bungtr_f */
    25,	/* bungti_f */
    10,	/* bltgtr_f */
    25,	/* bltgti_f */
    10,	/* bordr_f */
    25,	/* bordi_f */
    10,	/* bunordr_f */
    25,	/* bunordi_f */
    0,	/* pushargr_f */
    0,	/* pushargi_f */
    0,	/* retr_f */
    0,	/* reti_f */
    0,	/* retval_f */
    0,	/* arg_d */
    0,	/* getarg_d */
    0,	/* putargr_d */
    0,	/* putargi_d */
    10,	/* addr_d */
    25,	/* addi_d */
    15,	/* subr_d */
    25,	/* subi_d */
    30,	/* rsbi_d */
    10,	/* mulr_d */
    25,	/* muli_d */
    15,	/* divr_d */
    25,	/* divi_d */
    22,	/* negr_d */
    16,	/* absr_d */
    5,	/* sqrtr_d */
    12,	/* ltr_d */
    27,	/* lti_d */
    12,	/* ler_d */
    27,	/* lei_d */
    14,	/* eqr_d */
    29,	/* eqi_d */
    12,	/* ger_d */
    27,	/* gei_d */
    12,	/* gtr_d */
    27,	/* gti_d */
    17,	/* ner_d */
    32,	/* nei_d */
    12,	/* unltr_d */
    27,	/* unlti_d */
    12,	/* unler_d */
    27,	/* unlei_d */
    12,	/* uneqr_d */
    27,	/* uneqi_d */
    12,	/* unger_d */
    27,	/* ungei_d */
    12,	/* ungtr_d */
    27,	/* ungti_d */
    12,	/* ltgtr_d */
    27,	/* ltgti_d */
    12,	/* ordr_d */
    27,	/* ordi_d */
    12,	/* unordr_d */
    27,	/* unordi_d */
    5,	/* truncr_d_i */
    5,	/* truncr_d_l */
    5,	/* extr_d */
    5,	/* extr_f_d */
    5,	/* movr_d */
    15,	/* movi_d */
    6,	/* ldr_d */
    10,	/* ldi_d */
    7,	/* ldxr_d */
    9,	/* ldxi_d */
    6,	/* str_d */
    10,	/* sti_d */
    7,	/* stxr_d */
    9,	/* stxi_d */
    11,	/* bltr_d */
    26,	/* blti_d */
    11,	/* bler_d */
    26,	/* blei_d */
    13,	/* beqr_d */
    28,	/* beqi_d */
    11,	/* bger_d */
    26,	/* bgei_d */
    11,	/* bgtr_d */
    26,	/* bgti_d */
    14,	/* bner_d */
    29,	/* bnei_d */
    11,	/* bunltr_d */
    26,	/* bunlti_d */
    11,	/* bunler_d */
    26,	/* bunlei_d */
    11,	/* buneqr_d */
    26,	/* buneqi_d */
    11,	/* bunger_d */
    26,	/* bungei_d */
    11,	/* bungtr_d */
    26,	/* bungti_d */
    11,	/* bltgtr_d */
    26,	/* bltgti_d */
    11,	/* bordr_d */
    26,	/* bordi_d */
    11,	/* bunordr_d */
    26,	/* bunordi_d */
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
    9,	/* bswapr_us */
    6,	/* bswapr_ui */
    6,	/* bswapr_ul */
    11,	/* casr */
    16,	/* casi */
#endif /* __CYGWIN__ || _WIN32 */
#  endif /* __X64_32 */
#endif /* __X64 */
