#ifndef MERGESORT_H
#define MERGESORT_H


typedef enum _bool{FALSE, TRUE}bool;

typedef struct _node
{
  char ** data;
  struct _node* next;
}node;


void mergeSort( node ** ,int, int (*)(void*,void*));
node * merge( node *, node*,int, int (*)(void*,void*));
void subdivide( node*, node**, node**);
void printData( node*, int);
void readData ( node*, int);
/*
void merge( node* head, int left, int mid , int right, int index, int (*)(void*, void*) );
void mergesort( node* head, int left, int right, int index,  int (*)(void*,void*));
*/


#endif
