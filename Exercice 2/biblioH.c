#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioH.h"

int fonctionClef(char* auteur){
    int resultat=0; // on stockera ici la somme des valeurs ASCII de chaque lettre du nom de son auteur

    for (int i=0;i<TAILLEAUTEUR;i++){
        resultat+=(int)auteur[i];
    }
    
    return resultat;

}

LivreH* creer_livre(int num,char* titre,char* auteur){
    LivreH* Livre=(LivreH*)malloc(sizeof(LivreH));
    if(Livre==NULL){
        printf("erreur d affectation");
    }
    Livre->clef=fonctionClef(auteur);
    Livre->num=num;
    Livre->titre=strdup(titre);
    Livre->auteur=strdup(auteur);
    Livre->suivant=NULL;
    return Livre;
}

void liberer_livre(LivreH* l){
    free(l->titre);
    free(l->auteur);
    free(l->suivant);
    free(l);

}

BiblioH* creer_biblio(int m){

    BiblioH* Biblio=(BiblioH*)malloc(sizeof(BiblioH));
     if(Biblio==NULL){
        printf("erreur d affectation");
    }

    Biblio->nE=?; /*nombre d’elements contenus dans la table de hachage */
    Biblio->m=m; /*taille de la table de hachage */
    Biblio->T=NULL ; /*table de hachage avec resolution des collisions par chainage */

    return Biblio;
}

void liberer_biblio(BiblioH* b){
    
    LivreH **tmp = b->T;
    LivreH **tmp2 = NULL;

    While(tmp2){

        tmp2=tmp->suiv;
        free(tmp->auteur);
        free(tmp->titre);
        free(tmp->suivant);
        
    }
    free(b);
}



