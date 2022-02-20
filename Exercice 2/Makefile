all :main

main : biblioH.o
	gcc -o main biblioH.o

biblioH.o : biblioH.c biblioH.h
	gcc -Wall -c biblioH.c biblioH.H

clean :
	rm -f *.o
	rm -f main
