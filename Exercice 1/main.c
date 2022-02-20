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
    char *nomfichier = strdup(argv[2]);
    Biblio* b =charger_n_entrees(nomfichier,num);
    char buffer[1];
    int rep=10000;
    do {
        fgets(buffer,1,stdin);
        menu();
        buffer[1]='\0';
        rep = atoi(buffer);
        switch (rep) {
            case 1:
                printf("Affichage : \n");
                afficheBiblio(b);
                break;
            case 2:
                printf("");
                char titre[256];
                char auteur[256];
                printf("Veuillez écrire le numéro\n" );
                char numl[1];
                fgets(numl, 1, stdin);
                printf("Veuillez écrire le tire\n");
                break;




        }


    }while(rep!=0);
    return 1;
}