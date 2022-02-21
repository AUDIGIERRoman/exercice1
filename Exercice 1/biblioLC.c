#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"

Livre* creer_livre(int num,char* titre,char* auteur){
    Livre* livre=(Livre*)malloc(sizeof(Livre));
    if(livre==NULL){
        printf("Erreur d'allocation");
    }
    livre->num=num;
    livre->titre= strdup(titre);
    livre->auteur= strdup(auteur);
    return livre;
}

void liberer_livre(Livre* l){
    free(l->titre);
    free(l->auteur);
    free(l);
}


Biblio* creer_biblio(){
    Biblio *bib=(Biblio*)malloc(sizeof(Biblio));
    if(bib==NULL){
        printf("Erreur d'allocation");
    }
    bib->L=NULL;
    return bib;

}

void liberer_biblio(Biblio* b){
    Livre *l = b->L;
    Livre *tmp = NULL;
    while(l){
        tmp = l->suiv;
        liberer_livre(l);
        l = tmp;
    }
    free(b);
}

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur){
    Livre* tmp1 = creer_livre(num,titre,auteur);
    Livre* tmp2 =b->L;
        tmp1->suiv=tmp2;
        b->L=tmp1;
    }


void afficheLivre(Livre* l){
    printf("Numero :%d Titre du livre :%s Nom de l'auteur: %s \n",l->num,l->titre,l->auteur);
}
void afficheBiblio(Biblio* b){
    Livre *tmp = b->L;
    while(tmp){
        afficheLivre(tmp);
        tmp=tmp->suiv;
    }
}
Livre* recherchelivreparnum(Biblio* b,int n){
    Livre* tmp =b->L;
    while(tmp){
        if(tmp->num==n){
            return tmp;
            }
      tmp=tmp->suiv;
        }
    return NULL;
    }

Livre* recherchelivrepartitre(Biblio* b,char* t){
    Livre* tmp = b->L;
    while(tmp){
        if(strcmp(tmp->titre,t)){
            return tmp;
            }
      tmp=tmp->suiv;
        }
    return NULL;

}

Biblio* memeauteur(Biblio* b,char* au){
    Biblio* b2= creer_biblio();
    Livre* tmp= b->L;
    while(tmp){
        if(! strcmp(tmp->auteur,au)){
        inserer_en_tete(b2,tmp->num,tmp->titre,tmp->auteur);
            }
      tmp=tmp->suiv;
        }
    return b2;
}

void supprimerouvragebiblio(Biblio* b, int n, char* au, char* ti){
    Livre* tmp = b->L;
    Livre* tmprec = b->L;
    int test = 1;
    while(tmp){
        if ((tmp->num==n) &&(strcmp(tmp->auteur,au)==0)&& (strcmp(tmp->titre,ti)==0)) {
            if (test) {
                b->L = tmp->suiv;
                liberer_livre(tmp);
            } else {
                tmprec->suiv = tmp->suiv;
                liberer_livre(tmp);
            }
        }
        test=0;
        tmprec=tmp;
        tmp=tmp->suiv;

    }
}
            



void fusionbiblio(Biblio* b1,Biblio* b2){
    Livre* tmp = b1->L;
    while(tmp->suiv){
        tmp=tmp->suiv;
    }
    tmp->suiv=b2->L;
    free(b2);
       
}
Biblio* recherchedoublon(Biblio* b1){
    Biblio* res = creer_biblio();
    Livre*  tmp=b1->L;
    Livre*  tmp2=NULL;
    int test=1;
    while(tmp){
        test=1;
        tmp2=tmp;
        tmp=tmp->suiv;
        while(tmp2){
            if((strcmp(tmp2->auteur,tmp->auteur)==0)&&(strcmp(tmp2->titre,tmp->titre)==0)) {
                if (test) {
                    //Livre* cpy = creer_livre(tmp->num,tmp->titre,tmp->auteur);
                    //Livre* cpy2 = creer_livre(tmp2->num,tmp2->titre,tmp2->auteur);
                    inserer_en_tete(res, tmp->num, tmp->titre, tmp->auteur);
                    inserer_en_tete(res, tmp2->num, tmp2->titre, tmp2->auteur);
                    test = 0;
                } else {
                    //Livre* cpy2 = creer_livre(tmp2->num,tmp2->titre,tmp2->auteur);
                    inserer_en_tete(res, tmp2->num, tmp2->titre, tmp2->auteur);
                }
            }
            tmp2=tmp2->suiv;
        }
    }

    return res;
}