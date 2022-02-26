//
// Created by Idil Saglam on 2/22/22.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct array {
    int *ptr;
    unsigned int capacite;
    unsigned int taille;
};
typedef struct array array;

array* array_init(unsigned int cap){
    array* a = malloc(sizeof(array));
    if(a == NULL){
        return NULL;
    }
    a->taille = cap;
    //(*a).taille = cap;
    a->ptr = malloc(sizeof(int) * (a->capacite));
    if(a->ptr == NULL){
        return NULL;
    }
    return a;
}

void array_destroy(array *t){
    free(t->ptr);
    free(t);
}

int array_get(array* t,unsigned int index){
    assert(index < t->taille);
    return *(t+index);
}

void array_set(array* t, unsigned int index, int valeur){
    assert(taille > index+1);
    t[index] = valeur;
    // *(t+index) = valeur;
}
void array_append(array* t, int val){
    assert(taille<t->capacite);
    *(t+taille) = val:
}
void array_print(array* t){
    for(int i = 0; i<t->taille; i++){
        printf(" %d",t->ptr[i]);
        //*((t->ptr)+i)
        t++;
    }
}

int array_search(array *t, int val){
    for(int i = 0; i<t->taille; i++){
        if(t->ptr[i] == val){
            return i;
        }
    }
    return -1;
}



int main(){
    return 1;
}