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
    char*buffer= malloc(256);
    do {
        menu();
        fgets(buffer,2,stdin);
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
                printf("Veuillez écrire le numéro , le titre et l'auteur \n" );
                fgets(buffer, 100, stdin);
                sscanf(buffer,"%d %s %s",&num,titre,auteur);
                Livre* nouv = creer_livre(num,titre,auteur);
                printf("Livre crée :\n ");
                afficheLivre(nouv);
                liberer_livre(nouv);
                inserer_en_tete(b,num,titre,auteur);
                break;

            case 3:
                pr





        }


    }while(rep!=0);
    return 1;
}