#ifndef biblioLC_H
#define biblioLC_H

typedef struct livre {
 int num ;
 char * titre ;
 char * auteur ;
 struct livre * suiv ;
 } Livre ;

 typedef struct { /* Tete fictive */
 Livre * L ; /* Premier element */
} Biblio ;



Livre* creer_livre(int num,char* titre,char* auteur);
void liberer_livre(Livre* l);
Biblio* creer_biblio();
void liberer_biblio(Biblio* b);
void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);
void afficheLivre(Livre* l);
void afficheBiblio(Biblio* b);
Livre* recherchelivreparnum(Biblio* b,int n);
Livre* recherchelivrepartitre(Biblio* b,char* t);
Biblio* memeauteur(Biblio* b,char* au);
void supprimerouvragebiblio(Biblio* b, int n, char* au, char* ti);
void fusionbiblio(Biblio* b1,Biblio* b2);
Biblio* recherchedoublon(Biblio* b1);





#endif //biblioLC_H


