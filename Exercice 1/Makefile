all : main

main : main.o entreeSortieLC.o biblioLC.o 
	gcc -ggdb -Wall -o main main.o entreeSortieLC.o biblioLC.o

main.o : main.c entreeSortieLC.h biblioLC.h 
	gcc -ggdb -Wall -c main.c

entreeSortieLC.o : entreeSortieLC.c biblioLC.h
	gcc -ggdb -Wall -c entreeSortieLC.c

biblioLc.o : biblioLC.c
	gcc -ggdb -Wall -c biblioLC.c

clean :
	rm -f *.o
	rm -f main