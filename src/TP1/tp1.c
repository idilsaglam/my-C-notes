//
// Created by Idil Saglam on 2/13/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 27
#define SUP 10

void ex2_1(int n){
    int res = 0;
    for(int i=1; i<=n; i++){
        res += i*i*i;
        //res+= pow(i,3);
    }
    printf("%d\n", res);
}

void ex2_2(int n){
    int somme = 0;
    for(int i =0; i<n; i++){
        printf("%d\n",i);
        somme+= i;
    }
    printf("La somme est %d\n",somme);
    printf("Moyenne est %f\n",(double)somme/n);
}

int fact(int n){
    int res = 1;
    for(int i=2; i<=n; i++){
      res *= i;
    }
    return res;
}

void fact2(int n){
    for(int i=0; i<n; i++){
        printf("%d ! = %d\n",i, fact(i));
    }
}

void affichage(int t[]){
    printf("sizeof(t) = %lu\n",sizeof(t)); // 8
    printf("sizeof(t[0]) = %lu\n",sizeof(t[0])); // 4
    printf("sizeof(t)/sizeof(t[0]) = %lu\n",sizeof(t)/sizeof(t[0])); //2
}

//TODO
int suiteSyracuse(int n, int tmpDeVol){
    printf("Valeur de n %d\n", n);
    if(n == 1){
        printf("Le temps de vol est %d\n",tmpDeVol);
        return 0;
    }
    if(n % 2 == 0){
        n /= 2;
        tmpDeVol++;
    }else{
        n = 3*n+1;
    }
    return suiteSyracuse(n,tmpDeVol);
}

int* eratosthene(){
    // tab va cotenir uniquement des 0 (False) et 1 (True)
    int *tab = calloc(SUP, sizeof(int));
    for(int i = 2; i<SUP; i++) {
        for (int j = 2 * i; j < SUP; j = j+i) {
                tab[j] = 1;
        }
    }
    return tab;
}

void eros2(){
   /* // tab va contenir uniquement des 0 (False) et 1 (True)
    int *tab = calloc(SUP, sizeof(int));
    for(int i = 2; i<SUP; i++) {
        for (int j = 2 * i; j < SUP; j = j+i) {
            tab[j] = 1;
        }
    }
    */
   int *tab = eratosthene();
    for(int i = 2; i<SUP-2; i++){
        if(!tab[i] && !tab[i+2]){
            printf("( %d %d ) ",i,i+2);
        }
    }
    printf("\n");
    free(tab);
}

void eros3(){
    int *tab = eratosthene();
    for(int i = 2; i<SUP; i++){
        for(int j = 2; j<SUP; j++){
            if((!tab[i] && !tab[j]) && ((i+j) % 2 == 0)){
                printf("%d + %d = %d\n",i,j,i+j);
            }
        }
    }
    printf("\n");
    free(tab);
}

int main(){
    eros3();
    int g;
    scanf("%d",&g);
    ex2_1(g);
    int n = 42;
    int m = 2;
    double  x = 3.14;

    printf("%d\n",n+1);
    printf("%d + %d = %d\n",n,m,n+m);
    printf("%d / %lf = %lf\n",n,x,n/x);

    int tab[] = {42,17,11};
    printf("sizeof(tab) = %lu\n",sizeof(tab)); // 12
    printf("sizeof(tab[0]) = %lu\n",sizeof(tab[0])); // 4
    printf("sizeof(tab)/sizeof(tab[0]) = %lu\n",sizeof(tab)/sizeof(tab[0])); //3
    affichage(tab);

    int v;
    //TODO
    ex2_1(scanf("%d",&v));
    ex2_2(5);
    fact2(6);
    suiteSyracuse(N,0);
    return 0;
}
