default:
	gcc rm.c -o rm.o
	gcc mkdir.c -o mkdir.o
	gcc cat.c -o cat.o
	gcc date.c -o date.o
	gcc date_I.c -o date_I.o
	gcc date_R.c -o date_R.o
	gcc ls.c -o ls.o
	gcc ls_a.c -o ls_a.o
	gcc ls_1.c -o ls_1.o
	gcc q2_mod.c
	./a.out