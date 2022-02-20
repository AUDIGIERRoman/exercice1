#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include"biblioLC.h"
#include"entreeSortieLC.h"

void menu(){
    printf("0-sortie du programme\n1-Affichage\n2-Insertion d'ouvrage\n");
}

int main(int argc,char** argv) {
    int num = atoi(argv[1]);
    char *nomfichier;
    strcpy(nomfichier, argv[3]);
    int rep;
    char buffer[1];
    do {
        menu();
        fgets(buffer,1,stdin);
        buffer[1]='\0';
        rep = atoi(buffer);
        switch (rep) {


        }


    }while(rep!=0);
    return 1;
}