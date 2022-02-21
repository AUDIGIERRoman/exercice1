#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include"biblioLC.h"
#include"entreeSortieLC.h"

void menu(){
    printf("\t0-sortie du programme\n\t1-Affichage\n\t2-Insertion d'ouvrage\n\t 3-Suppression d'ouvrage\n\t"
           "4-Recherche par numéro\n\t5-Recherche par auteur\n\t6-Recherche par titre\n\t");
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
        sscanf(buffer,"%d",&rep);
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
                int test = sscanf(buffer2, "%d %s %s", &num2, titre, auteur);
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
            case 3:{
                int num3;
                char titre3[256];
                char auteur3[256];
                printf("Veuillez rentrer le numero, le titre et l'auteur du livre à supprimer\n");
                fgets(buffer,100,stdin);
                if(sscanf(buffer,"%d %s %s",&num3,titre3,auteur3)==3){
                    supprimerouvragebiblio(b,num3,titre3,auteur3);
                    printf("ouvrage supprimé\n");

                }
                else{
                    printf("erreur de format\n")
                }
                break;
            }
            case 4: {
                printf("Veuillez entrer le numéro de l'oeuvre cherchée\n");
                fgets(buffer, 10, stdin);
                int num4;
                if (sscanf(buffer,"%d",&num4) ==1) {
                    afficheLivre(recherchelivreparnum(b, num4));
                }
                else{
                    printf("erreur de format\n");
                }
                break;
            }
            case 5:{
                printf("Veuillez entrer le nom de l'auteur\n");
                fgets(buffer, 50, stdin);
                char auteur5[256];
                if (sscanf(buffer,"%s", auteur5) ==1) {
                    Biblio* tmp = memeauteur(b,auteur5);
                    afficheBiblio(tmp);
                    liberer_biblio(tmp);
                }
                else{
                    printf("erreur de format\n");
                }
                break;
            }
            case 6:{
                printf("Veuillez entrer le titre\n");
                fgets(buffer, 50, stdin);
                char titre6[256];
                if(sscanf(buffer,"%s",titre6)==1) {
                    afficheLivre(recherchelivrepartitre(b, titre6));
                }
                else{
                    printf("erreur de format\n");

                }
                break;
            }


        }


    }while(rep!=0);

    return 1;
}