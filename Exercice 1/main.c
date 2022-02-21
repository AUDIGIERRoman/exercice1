#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include"biblioLC.h"
#include"entreeSortieLC.h"

void menu(){
    printf("\t0-sortie du programme\n\t1-Affichage\n\t2-Insertion d'ouvrage\n\t"
           "3-Recherche par numéro\n\t");
}

int main(int argc,char** argv) {
    int num = atoi(argv[1]);
    char *nomfichier = strdup(argv[2]);
    Biblio* b =charger_n_entrees(nomfichier,num);
    int rep;
    char buffer[256];
    do {
        menu();
        fgets(buffer,2,stdin);
        sscanf(buffer,"%d\n",&rep);
        switch (rep) {
            case 1:
                printf("Affichage : \n");
                afficheBiblio(b);
                break;
            case 2:
                printf("Insertion de livre\n");
                strcpy(buffer,"\0");
                int numero;
                char titre[256];
                char auteur[256];
                printf("Veuillez écrire le numéro , le titre et l'auteur \n\n" );
                fgets(buffer, 100, stdin);
                int test = sscanf(buffer,"%d %s %s\n",&numero,titre,auteur);
                if (test==3){
                    Livre *nouv = creer_livre(numero, titre, auteur);
                    printf("Livre créé :\n ");
                    afficheLivre(nouv);
                    liberer_livre(nouv);
                    inserer_en_tete(b, numero, titre, auteur);
                }
                else{
                    printf("erreur de format\n");
                }
                break;

            case 3:
                fgets(buffer,10,stdin);
                break;




        }


    }while(rep!=0);
    return 1;
}