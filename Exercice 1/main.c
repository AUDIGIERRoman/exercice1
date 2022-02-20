#include <stdlib.h>
#include<stdio.h>
#include"biblioLC.h"
#include"entreeSortieLC.h"

void menu(){
    printf("0-sortie du programme\n1-Affichage\n2-Insertion d'ouvrage\n");
}

int main(int argc,char** argv){
    menu();
    Biblio* b = charger_n_entrees("GdeBiblio.txt",50);
    /*afficheLivre(b->L);
    printf("\n");*/
    afficheBiblio(b);
    Livre *livre = recherchelivreparnum(b,27);
    afficheLivre(livre);
    livre = recherchelivrepartitre(b,"KMLNOZJKPQPXR");
    afficheLivre(livre);
    Biblio *b2 = memeauteur(b,"tg");
    afficheBiblio(b2);
    supprimerouvragebiblio(b2,2,"tg","JYBLD");
    afficheBiblio(b2);
    printf("\nok\n");
    fusionbiblio(b,b2);
    liberer_biblio(b);
    liberer_biblio(b2);

    return 1;
}