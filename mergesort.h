#ifndef MERGESORT_H
#define MERGESORT_H


typedef enum _bool{FALSE, TRUE}bool;

typedef struct _node
{
  char ** data;
  struct _node* next;
}node;

void mergesort( node* head, int left, int right, int, int index,  int (*)( void*, void*));
void merge( node* head, int left, int mid , int right, int index, int (*)(void*,void*) );

void printData( node*, int);
void readData ( node*, int);





#endif
