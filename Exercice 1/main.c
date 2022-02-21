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
    int rep;
    char buffer[256];
    do {
        menu();
        fgets(buffer,1,stdin);
        sscanf(buffer,"%d",&rep);
        switch (rep) {
            case 1:
                printf("Affichage : \n");
                afficheBiblio(b);
                break;
            case 2:
                printf("");
                int num;
                char titre[256];
                char auteur[256];
                printf("Veuillez écrire le numéro\n" );
                fgets(buffer, 100, stdin);

                break;




        }


    }while(rep!=0);
    return 1;
}