typedef struct livreh {
2 int clef ;
3 /* int num; ... toutes les donnees permettant de representer un livre */
4 struct livreh * suivant ;
5 } LivreH ;

typedef struct table {
int nE ; /*nombre d’elements contenus dans la table de hachage */
int m ; /*taille de la table de hachage */
LivreH ** T ; /*table de hachage avec resolution des collisions par chainage */
} BiblioH ;