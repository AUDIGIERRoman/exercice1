#include <stdio.h>
#include <stdlib.h>
#include "entreeSortieLC.h"
#include "biblioLC.h"


Biblio* charger_n_entrees(char* nomfic,int n){
    Biblio* b=creer_biblio();//on creer une bibliotheque pour pouvoir stocker nos livres 
    FILE* f= fopen(nomfic,"r");
    char buffer[256];
    int i=0;
    //On lis n ligne du fichier
    char auteur[50];
    char titre[50];
    while(i<n){
        fgets(buffer,256,f);// on recupere une ligne du fichier qu'on convertie en char dans le buffer
        int num=0;
        sscanf(buffer,"%d %s %s \n",&num,titre,auteur);//on recupere le num titre et l'auteur dans la chaine de caractere buffer
        inserer_en_tete(b,num,titre,auteur);
        i++;
    }

    fclose(f);
    return b;
}


void enregistrer_biblio(Biblio* b,char* nomfic){
    FILE* f=fopen(nomfic,"a");
    while(b->L){
        printf("%d %s %s ",b->L->num,b->L->titre,b->L->auteur);
        fputc('\n',f);
        b->L=b->L->suiv;
    }
    liberer_biblio(b);
    fclose(f);

}