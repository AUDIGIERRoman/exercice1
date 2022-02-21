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
        fgets(buffer,3,stdin);
        sscanf(buffer,"%d\n",&rep);
        switch (rep) {
            case 1: {
                printf("Affichage : \n");
                afficheBiblio(b);
                break;
            }
            case 2: {
                printf("Insertion de livre\n");
                char buffer2[256];
                int num2;
                char titre[256];
                char auteur[256];
                printf("Veuillez écrire le numéro , le titre et l'auteur \n");
                fgets(buffer2, 100, stdin);
                int test = sscanf(buffer2, "%d %s %s\n", &num2, titre, auteur);
                if (test == 3) {
                    Livre *nouv = creer_livre(num2, titre, auteur);
                    printf("Livre créé et inséré :\n ");
                    afficheLivre(nouv);
                    liberer_livre(nouv);
                    inserer_en_tete(b, num2, titre, auteur);
                } else {
                    printf("erreur de format\n");
                }
                break;
            }
            case 3: {
                printf("Veuillez entrer le numéro de l'oeuvre cherchée\n");
                fgets(buffer, 10, stdin);
                int num3;
                sscanf(buffer,"%d",&num3);
                afficheLivre( recherchelivreparnum(b,num3));
                break;
            }
            case 4:{
                printf("Veuillez entrer le nom de l'auteur")
                break;
            }


        }


    }while(rep!=0);
    return 1;
}