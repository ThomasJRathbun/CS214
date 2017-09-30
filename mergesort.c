#include "mergesort.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
typedef enum _bool{FALSE, TRUE}bool;

typedef struct _node
{
  char ** data;
  struct * _node next;
}node;
*/
//Read in data and insert nodes into Linked List
void readData( node * head, int _numHeaders )
{
  printf("[readData]:Entered\n");
  char* line;
  node * newNode = head;
  printf("[readData]:Initialized\n");
  while ( scanf("%ms", &line ) != EOF )
  {
    printf("[readData]:Scanned\n");
    if ( newNode->next == NULL && newNode->data == NULL )
      {
	newNode->data = (char**)malloc(sizeof(char*) * _numHeaders);
	newNode->next = NULL;
      }
    else 
      {
	while ( newNode->next != NULL )
	  {
	    node * prev = newNode;
	    newNode = newNode->next;
	    prev->next = newNode;
	  }
	newNode->next = (node*)malloc(sizeof(node));
	node * prev = newNode;
	newNode = newNode->next;
	prev->next = newNode;
      }
    
    newNode->data = (char**)malloc(sizeof(char*) * _numHeaders);
    int i = 0;
    printf(" NUMBER OF HEADERS: %d", _numHeaders);
    for (i; i<_numHeaders; i++)
      {
	printf(" NUMBER OF HEADERS: %d\n", _numHeaders);
	if( i ==0)
	  line = strtok( line, ",");
	else
	  line = strtok( NULL, ",");
	printf("line : %s\n",line);
	newNode->data[i] = (char*)malloc(sizeof(char) * strlen(line)+1);
	newNode->data[i] = line;
	printf("[readData]:data at node[%d]= %s\n",i,newNode->data[i]);
      }
  }
}


void printData( node * head )
{
  node * curr = head;
  int i = 0;
  while( curr != NULL)
    {
      for (i ; i< 4; i++)
	{
	  printf("%s\n",curr->data[i]);
	}
      curr = curr->next;
    }
}
/*
void merge( node * head, int left, int mid, int right ){


  int nodesInLeft  = mid - left + 1;
  int nodesInRight = right - mid;

  
  node * lList = head;
  node * rList = head;

  while ( rList->next != NULL && nodesInRight <)
    {
      
      
    }

  
  //while
  /*
    comp(
   

}

void mergesort( node * head, int left, int right, int (*comp)(void *, void *))
{

  if ( left < right )
    {
      int mid = ( (left + right)/2);

      mergesort( head, low, mid, comp);
      mergesort( head, mid+1, right, comp);

      //      merge();
    }
  else
    return;
}
*/
