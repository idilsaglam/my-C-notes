//
// Created by Idil Saglam on 2/14/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define NBC 10
int g(int n, int (*f)()){
    if(n==1){
        return 1;
    }
    return 3* f(n/2);
}
int f(int n){
    if(n == 2){
        return 1;
    }
    return 2*g(n-1, f);
}

enum etat {VALIDEE, ENCOURS, EXPEDIEE};
typedef enum etat etat;
struct commande {
    int num_com;
    int prix_exp;
    int prix_prod;
    etat etat_com;};
typedef struct commande commande;

commande com_alea(int num){
    commande  commande1;

    commande1.num_com = num;

    srand(time(NULL));

    commande1.prix_prod = rand() % 2000;

    commande1.prix_exp = rand() % 21;

    int c = rand()%3;
    switch (c) {
        case 0:
            commande1.etat_com = VALIDEE;
            break;
        case 1:
            commande1.etat_com = ENCOURS;
            break;
        case 2:
            commande1.etat_com = EXPEDIEE;
            break;
    }
    // printf("%d\n",commande1.prix_exp);
    return commande1;
}

void affiche_com(commande c){
    char* etatP;
    switch (c.etat_com) {
        case VALIDEE:
            etatP = (char *) &("Validee");
            break;
        case ENCOURS:
            etatP = (char *)&("Encours");
            break;
        case EXPEDIEE:
            etatP = (char *)&("Expediee");
            break;
    }

    printf("Command number = %d, Prix d'exp = %d , Prix Produit = %d, Etat commande = %s ",c.num_com,c.prix_exp,c.prix_prod,etatP);

}
void affiche_exp(commande t[], int taille){
    for(int i = 0; i< taille; i++){
        if(t[i].etat_com == EXPEDIEE){
            affiche_com(t[i]);
        }
    }
}

int nbr_en_cours(commande t[], int taille){
    int c = 0;
    for(int i=0; i<taille; i++){
        if(t[i].etat_com == VALIDEE){
            c++;
        }
    }
    return c;
}

int cout_validees(commande t[],int taille){
    int c = 0;
    for(int i=0; i<taille; i++){
        if(t[i].etat_com == VALIDEE){
            c += t[i].prix_prod;
        }
    }
    return c;
}
typedef struct fraction{
    int num;
    long int den;
} fraction;

typedef int my_super_integer;

/*
 struct fraction {
    int num;
    long int den;
 }
 typedef struct fraction fraction;
 */

int length(commande* t) {
    return sizeof(*t)/sizeof(commande);
}


fraction build(long int n, long int d) {
    fraction fraction1;
    fraction1.num = n;
    fraction1.den = d;
    return fraction1;
}
int eq_fraction(fraction f, fraction g){
    if(f.num*g.den == g.num*f.den){
        return 0;
    }
    return 1;
}

int is_int(fraction f){
    if(f.den == 1){
        return 1;
    }
    return 0;
}

fraction sum(fraction f, fraction g){
    fraction res;
    if(f.den == g.den){
        res.den = f.den;
        res.num = f.num + g.den;
        return res;
    }
    int c = f.den * g.den;
    res.den = c;
    res.num = c*(f.num)+ c*(g.num);
    return res;
}


fraction sub(fraction f, fraction g){
    fraction res;
    if(f.den == g.den){
        res.den = g.den;
        res.num = f.num-g.num;
        return res;
    }
    int c = f.den * g.den;
    res.den = c;
    res.num = c*(f.num)- c*(g.num);
    return res;

}

fraction mul(fraction f, fraction g){
    fraction res;
    res.den = f.den * g.den;
    res.num = f.num * g.num;
    return res;
}
//TODO
long pgcd(long a, long b){
    int x = a;
    int y = b;
    int r;
    while (y!=0){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

fraction reduce(fraction f){
    long cal = pgcd(f.den,f.num);
    f.den /= cal;
    f.num /= cal;
    return f;
}


typedef struct point {
    fraction x;
    fraction y;
}point;


int eq_point(point p1, point p2){
    return(eq_fraction(p1.x,p2.x) && eq_fraction(p1.y,p2.y));
}

double dist(point p1, point p2){
    return (double) sqrt(abs(p1.x-p2.x * p1.x-p2.x)+ abs((p2.y-p1.y * p2.y-p1.y)));
}

void affiche(char c[]){
    for(int i =0; i<sizeof(c)/sizeof(c[0]); i++){
        printf(c[i]);
    }
}
void affichePoly(int tab[]){
    printf("%d ",tab[0]);
    char x[] = "X";
    for(int i = 1; i<sizeof(tab)/sizeof(tab[0]); i++){
        printf("%d ",tab[i]);
        affiche(x);
        x+= "X";
    }
}

int main(){
    com_alea(NBC);
    return  0;
}

