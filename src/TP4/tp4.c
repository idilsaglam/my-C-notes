//
// Created by Idil Saglam on 2/22/22.
//
#include <stdlib.h>
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
int main(){
    return 1;
}