all :main

main : biblioH.o
	gcc -o main biblioH.o

biblioH.o : biblioH.c biblioH.h
	gcc -Wall -c biblioH.c biblioH.h

entreeSortie.o : entreeSortieh.c entreeSortieH.h
	gcc -Wall -c entreeSortie.c entreeSortie.h


clean :
	rm -f *.o
	rm -f main
