//
// Created by Idil Saglam on 2/16/22.
//
#include <stdio.h>
#include <stdlib.h>

//TODO! calisiyor anlamaya calis
void swap(int *p, int *q){
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

int occ (int nbr, int t[], int v){
    for(int i = 0; i<nbr; i++){
        if(t[i] == v){
            return i;
        }
    }
    return -1;
}

//TODO: dogru mu yaptim anlamadim
int *occ_ptr (int nbr, int t[], int v){
    int *p = t;
    for(int i = 0; i<nbr; i++){
        if(t[i] == v){
            return p;
        }
        *p = *p +1;
    }
    return NULL;
}

int nbr_occ (int nbr, int t[], int v){
    int res = 0;
    for(int i = 0; i<nbr; i++){
        if(t[i] == v){
            res++;
        }
    }
    return res;
}

void nbr_occ_op (int nbr, int t[], int v, int *pnv){
    // *pnv =  Déréférencement
    *pnv = nbr_occ(nbr,t,v);
}

void min_max_op(int nbr, int t[], int *pmin, int *pmax){
    *pmin = *t;
    printf("pmin = %d\n",*pmin);
    *pmax = *t;
    printf("pmax = %d\n",*pmax);

    for(int i =1; i<nbr; i++){
        if(t[i]<*pmin){
            *pmin = *(t+i);
            printf("pmin = %d\n",*pmin);

        }
        if(t[i] > *pmax){
            *pmax = *(t+i);
            printf("pmax = %d\n",*pmax);
        }
    }
    printf("pmin = %d\n",*pmin);
    printf("pmax = %d\n",*pmax);
}


void print_tab (int t[], int start, int end){
    int* p = NULL;
    for(int i = start; i<end; i++){
        p = t+i;
        printf("%p : %d\n", p, *p);
    }
}

void print_tab2 (int *pstart, int *pend){
    for(int* i = pstart; i<=pend; i++){
        printf("%p : %d", i, *i);
    }
    return;
}
int main(){

    int t[] = {2,3,4,5};

    //TODO
    swap(t,t+3);
    print_tab(t,0,4);
    int min;
    int max;
    min_max_op(4,t,&min, &max);
    printf("max : %d min : %d\n",max,min);


    printf("test 1 %d\n", occ(4,t,4));
    printf("test 2 %d\n", occ(4,t,7));


    printf("test 3 %d\n", *occ_ptr(4,t,4));
    printf("test 4 %d\n", *occ_ptr(4,t,7));

   int t2[] = {2,3,4,5,5,4,5,5};
   printf("test 5 %d\n", nbr_occ(8,t2,5));

   int x,y;
   x=5; y=6;
   printf("(avant) x: %d,y : %d\n",x,y);

   swap(&x,&y);
   printf("(apres) x : %d , y : %d\n",x,y);

  int tab[] = {1,2,3};
  swap(tab+2,tab);
  printf("tab[2]= %d, tab[0] = %d\n",tab[2],tab[0]);

    return  0;
}
