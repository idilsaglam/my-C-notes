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
    return(f.num*g.den == g.num*f.den);
}

int is_int(fraction f){
    return(f.den == 1);
}

fraction sum(fraction f, fraction g){
    fraction res;
    if(f.den == g.den){
        res.den = f.den;
        res.num = f.num + g.num;
        return res;
    }
    int c = f.den * g.den;
    res.den = c;
    res.num = c*(f.num+g.num);
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
    res.num = c*(f.num- g.num);
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
//TODO ISARETTTTTTTTTTTT
fraction* reduce(fraction* f){
    long cal = pgcd(f->den,f->num);
    f->den /= cal;
    f->num /= cal;
    return f;
}
//TODO ISARETTTTTTTTTTTT
fraction sqrt_frac(fraction f){
    f.num= sqrt(f.num);
    f.den = sqrt(f.den);
    return f;
}
double calculate(fraction g){
    return g.num/g.den;
}


typedef struct point {
    fraction x;
    fraction y;
}point;


int eq_point(point p1, point p2){
    return(eq_fraction(p1.x,p2.x) && eq_fraction(p1.y,p2.y));
}

double dist(point p1, point p2){
   //return (double) sqrt(abs((p1.x-p2.x) * (p1.x-p2.x))+ abs((p2.y-p1.y) * (p2.y-p1.y)));
    fraction sx = sub(p1.x,p2.x),sy = sub(p1.y,p2.y);
    fraction mx = mul(sx,sx),my = mul(sy,sy);
    fraction s = sum(mx,my);
    return calculate(sqrt_frac(s));

}

void affiche(char c[]){
    for(int i =0; i<sizeof(c)/sizeof(c[0]); i++){
        printf(c[i]);
    }
}
void affichePoly(int* tab, int array_length){
    for(int i = 0; i< array_length; i++){
        if(tab[i] == 0){
            continue;
        }
        if(i == 0){
            printf("%d",tab[i]);
            continue;
        }
        printf("+ %dX^%d ",tab[i],i);
   }
    printf("\n");
}

void additionPoly(int* tab1, int l1, int* tab2, int l2){

    int max = max(l1,l2);
    int* res = calloc(max,sizeof(int));
    for(int i = 0; i < max; i++){
        res[i] = 0;
        if (i < l1) {
            res[i] += tab1[i];
        }
        if (i < l2) {
            res[i] += tab2[i];
        }
    }
    affichePoly(res,max);
}

void multiplicationPoly(int *tab1, int*tab2, int l1, int l2){
    int len = l1+l2-1;
    int* res = calloc(len,sizeof(int));

    for (int i = 0; i<len; i++) {
        res[i] = 0;
    }

    for (int i = 0; i<l1; i++) {
        for (int j = 0; j < l2; j++) {
            res[i+j] += tab1[i] * tab2[j];
        }
    }
    free(res);
    affichePoly(res);
}

void eval(int *tab1, int len,int n){
    int res = 0;
    for(int i = 0; i<len; i++){
        res += tab[i] * n ^ i;
    }
    return res;
}




int main(){
    com_alea(NBC);

    int t[] = {1,0,3,0};

    affichePoly(t, sizeof(t) / sizeof(int));

    return  0;
}

