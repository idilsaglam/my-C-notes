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
    return *(t->ptr+index);
}

void array_set(array* t, unsigned int index, int valeur){
    assert(taille > index+1);
    t->ptr[index] = valeur;
    // *(t+index) = valeur;
}
void array_append(array* t, int val){
    assert(taille < t->capacite);
    *(t->ptr + taille) = val:
    t->taille++;
}
void array_print(array* t){
    for(int i = 0; i<t->taille; i++){
        printf(" %d",t->ptr[i]);
        //*((t->ptr)+i)
        i++;
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


void array_swap(array *t, int i , int j) {
    assert(t->taille > i && t->taille > j);
    int tmp = t->ptr[i];
    t->ptr[i] = t->ptr[j];
    t->ptr[j] = tmp;
}

//TODO
array* array_init_from(int* mem, unsigned int len, unsigned int cap){
    array* res = array_init(cap);
    for (int i = 0; i< len; i++) {
        array_append(t, mem[i]);
    }
    return res;
}

//TODO
void array_remove(array *t, unsigned int index){
    assert(index < t->taille);
    for (int i = index ; i < (t->taille-1); i++) {
        array_swap(t, i, i+1);
    }
    t->taille--;
}


//TODO
void array_insert(array *t, unsigned int index, int valeur){
    assert(index < t->taille);
    t->taille++;
    for (int i = t->taille-1; i > index; i--) {
        array_swap(t->ptr[i],t->ptr[i-1]);
    }
    t->ptr[index] = val;
}

int main(){
    return 1;
}