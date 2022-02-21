#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblioH.h"
#define A (sqrt(5)-1)/2

int fonctionClef(char* auteur){
    int resultat=0; // on stockera ici la somme des valeurs ASCII de chaque lettre du nom de son auteur

    for (int i=0;i<TAILLEAUTEUR;i++){
        resultat+=(int)auteur[i];
    }
    
    return resultat;

}

LivreH* creer_livreH(int num,char* titre,char* auteur){
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

void liberer_livreH(LivreH* l){
    LivreH* tmp = l;
    LivreH* tmpsuiv = NULL;
    while (tmp){
        tmpsuiv = tmp->suivant;
        free(tmp->auteur);
        free(tmp->titre);
        free(tmp);
        tmp = tmpsuiv ;
    }
    free(l);

}

BiblioH* creer_biblioH(int m){

    BiblioH* Biblio=(BiblioH*)malloc(sizeof(BiblioH));
     if(Biblio==NULL){
        printf("erreur d affectation");
    }

    Biblio->nE=0; /*nombre d’elements contenus dans la table de hachage */
    Biblio->m=m; /*taille de la table de hachage */
    Biblio->T=NULL ; /*table de hachage avec resolution des collisions par chainage */

    return Biblio;
}

void liberer_biblioH(BiblioH* b){
    for(int i=0;i<(b->m);i++){
        liberer_livre(*(b->T));
        
    }
    free(b);
}

int fonctionHachage(int cle, int m){
    return (int)(m*((cle*A)-(int)(cle*A)));
}

void inserer(BiblioH* b, int num,char*titre, char *auteur){
    LivreH *l =creer_livre(num,titre,auteur);
    int hashkey= fonctionHachage(l->clef,b->m);
    LivreH *tmp =(b->T)[hashkey];
    if(!tmp){
        (b->T)[hashkey]=l;
    }
    while (tmp->suivant){
        tmp = tmp->suivant;
    }
    tmp->suivant = l;



}

int main(){
    return 1;
}



