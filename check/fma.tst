.data		32
ok:
.c		"ok"

.code
	prolog

	/* Simple encoding test for all different registers */
	movi_f %f0 0.0
	movi_f %f1 2.0
	movi_f %f2 3.0
	movi_f %f3 4.0
	fmar_f %f0 %f1 %f2 %f3
	beqi_f fa0 %f0 10.0
	calli @abort
fa0:
	movi_d %f0 0.0
	movi_d %f1 4.0
	movi_d %f2 5.0
	movi_d %f3 6.0
	fmar_d %f0 %f1 %f2 %f3
	beqi_d da0 %f0 26.0
	calli @abort
da0:
	movi_f %f0 0.0
	movi_f %f1 2.0
	movi_f %f2 3.0
	movi_f %f3 4.0
	fmsr_f %f0 %f1 %f2 %f3
	beqi_f fs0 %f0 2.0
	calli @abort
fs0:
	movi_d %f0 0.0
	movi_d %f1 4.0
	movi_d %f2 5.0
	movi_d %f3 6.0
	fmsr_d %f0 %f1 %f2 %f3
	beqi_d ds0 %f0 14.0
	calli @abort
ds0:

	/* Simple encoding test for result also first argument */
	movi_f %f1 2.0
	movi_f %f2 3.0
	movi_f %f3 4.0
	fmar_f %f1 %f1 %f2 %f3
	beqi_f fa1 %f1 10.0
	calli @abort
fa1:
	movi_d %f1 4.0
	movi_d %f2 5.0
	movi_d %f3 6.0
	fmar_d %f1 %f1 %f2 %f3
	beqi_d da1 %f1 26.0
	calli @abort
da1:
	movi_f %f1 2.0
	movi_f %f2 3.0
	movi_f %f3 4.0
	fmsr_f %f1 %f1 %f2 %f3
	beqi_f fs1 %f1 2.0
	calli @abort
fs1:
	movi_d %f1 4.0
	movi_d %f2 5.0
	movi_d %f3 6.0
	fmsr_d %f1 %f1 %f2 %f3
	beqi_d ds1 %f1 14.0
	calli @abort
ds1:

	/* Simple encoding test for result also second argument */
	movi_f %f1 2.0
	movi_f %f2 3.0
	movi_f %f3 4.0
	fmar_f %f2 %f1 %f2 %f3
	beqi_f fa2 %f2 10.0
	calli @abort
fa2:
	movi_d %f1 4.0
	movi_d %f2 5.0
	movi_d %f3 6.0
	fmar_d %f2 %f1 %f2 %f3
	beqi_d da2 %f2 26.0
	calli @abort
da2:
	movi_f %f1 2.0
	movi_f %f2 3.0
	movi_f %f3 4.0
	fmsr_f %f2 %f1 %f2 %f3
	beqi_f fs2 %f2 2.0
	calli @abort
fs2:
	movi_d %f1 4.0
	movi_d %f2 5.0
	movi_d %f3 6.0
	fmsr_d %f2 %f1 %f2 %f3
	beqi_d ds2 %f2 14.0
	calli @abort
ds2:

	/* Simple encoding test for result also third argument */
	movi_f %f1 2.0
	movi_f %f2 3.0
	movi_f %f3 4.0
	fmar_f %f3 %f1 %f2 %f3
	beqi_f fa3 %f3 10.0
	calli @abort
fa3:
	movi_d %f1 4.0
	movi_d %f2 5.0
	movi_d %f3 6.0
	fmar_d %f3 %f1 %f2 %f3
	beqi_d da3 %f3 26.0
	calli @abort
da3:
	movi_f %f1 2.0
	movi_f %f2 3.0
	movi_f %f3 4.0
	fmsr_f %f3 %f1 %f2 %f3
	beqi_f fs3 %f3 2.0
	calli @abort
fs3:
	movi_d %f1 4.0
	movi_d %f2 5.0
	movi_d %f3 6.0
	fmsr_d %f3 %f1 %f2 %f3
	beqi_d ds3 %f3 14.0
	calli @abort
ds3:

	/* Simple encoding test for all different registers */
	movi_f %f0 0.0
	movi_f %f1 2.0
	movi_f %f2 3.0
	fmai_f %f0 %f1 %f2 4.0
	beqi_f fai0 %f0 10.0
	calli @abort
fai0:
	movi_d %f0 0.0
	movi_d %f1 4.0
	movi_d %f2 5.0
	fmai_d %f0 %f1 %f2 6.0
	beqi_d dai0 %f0 26.0
	calli @abort
dai0:
	movi_f %f0 0.0
	movi_f %f1 2.0
	movi_f %f2 3.0
	fmsi_f %f0 %f1 %f2 4.0
	beqi_f fsi0 %f0 2.0
	calli @abort
fsi0:
	movi_d %f0 0.0
	movi_d %f1 4.0
	movi_d %f2 5.0
	fmsi_d %f0 %f1 %f2 6.0
	beqi_d dsi0 %f0 14.0
	calli @abort
dsi0:

	/* Simple encoding test for result also first argument */
	movi_f %f1 2.0
	movi_f %f2 3.0
	fmai_f %f1 %f1 %f2 4.0
	beqi_f fai1 %f1 10.0
	calli @abort
fai1:
	movi_d %f1 4.0
	movi_d %f2 5.0
	fmai_d %f1 %f1 %f2 6.0
	beqi_d dai1 %f1 26.0
	calli @abort
dai1:
	movi_f %f1 2.0
	movi_f %f2 3.0
	fmsi_f %f1 %f1 %f2 4.0
	beqi_f fsi1 %f1 2.0
	calli @abort
fsi1:
	movi_d %f1 4.0
	movi_d %f2 5.0
	fmsi_d %f1 %f1 %f2 6.0
	beqi_d dsi1 %f1 14.0
	calli @abort
dsi1:

	/* Simple encoding test for result also second argument */
	movi_f %f1 2.0
	movi_f %f2 3.0
	fmai_f %f2 %f1 %f2 4.0
	beqi_f fai2 %f2 10.0
	calli @abort
fai2:
	movi_d %f1 4.0
	movi_d %f2 5.0
	fmai_d %f2 %f1 %f2 6.0
	beqi_d dai2 %f2 26.0
	calli @abort
dai2:
	movi_f %f1 2.0
	movi_f %f2 3.0
	fmsi_f %f2 %f1 %f2 4.0
	beqi_f fsi2 %f2 2.0
	calli @abort
fsi2:
	movi_d %f1 4.0
	movi_d %f2 5.0
	fmsi_d %f2 %f1 %f2 6.0
	beqi_d dsi2 %f2 14.0
	calli @abort
dsi2:

	prepare
		pushargi ok
	finishi @puts

	ret
	epilog
