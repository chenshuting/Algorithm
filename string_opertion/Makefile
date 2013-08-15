run:string.o string_ops.o test.o
	cc -o run string.o string_ops.o test.o 
string.o:string.c test.h
	cc -c string.c
test.o:test.c test.h
	cc -c test.c
string_ops.o:string_ops.c string_ops.h
	cc -c string_ops.c
clean:
	rm -f *.o run
