#include "mergesort.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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


void printData( node * head, int _numHeaders)
{
  node * curr = head;
  int i = 0;
  while( curr != NULL)
    {
      for (i = 0 ; i< _numHeaders; i++)
	{
	  if ( (_numHeaders - i) == 1)
	    printf("%s\n",curr->data[i]);
	  else
	    printf("%s,",curr->data[i]);
	}
      curr = curr->next;
    }
  return;
}


void merge( node * head, int left, int mid, int right , int index , int (*comp)(void*,void*)){
  printf( "[merge]:Initializing\n");

  int nodesInLeft  = mid - left + 1;
  int nodesInRight = right - mid;
  int i =0, j = 0;
  node * leftList  = head;
  node * rightList = head;

  
  printf( "[merge]:Initialized\n");
  for ( i; i<nodesInLeft ; i++)
    {
      printf( "[merge]:Copying LeftList\n");
      leftList = leftList->next;
    }

  for ( i; i<nodesInRight ; i++)
    {
      printf( "[merge]:Copying righList\n");
      rightList = rightList->next;
    }

  i = 0;
  j = 0;
  node * curr = head;
  while ( i < nodesInLeft && j < nodesInRight )
    {
      printf( "[merge]::WHILE:checking data\n");
      switch (comp(leftList->data[index],rightList->data[index]))
	{
	case -1:
	  {
	    printf( "[merge]:Case -1 \n");
	    curr = leftList;
	    curr = curr->next;
	    leftList = leftList->next;
	    i++;
	    break;
	  }
	case 0:
	  {
	    printf( "[merge]:Case 0 \n");
	    curr = leftList;
	    curr = curr->next;
	    leftList = leftList->next;
	    i++;
	    break;
	  }
	case 1:
	  {
	    printf( "[merge]:Case 1 \n");
	    curr = rightList;
	    curr = curr->next;
	    leftList = rightList->next;
	    j++;
	    break;
	  }
	}
      printf( "[merge]:EXIT \n");
    }
}
void mergesort( node * head, int left, int right, int index, int (*comp)(void *, void *))
{
  printf( "[mergeSort]:Initialized \n");
  if ( left < right )
    {
      
      int mid = ( (left + right)/2);
      printf( "[mergeSort]:mid Set \n");
      mergesort( head, left, mid,index, comp);
      printf( "[mergeSort]:Sorted Left \n");
      mergesort( head, mid+1, right,index, comp);
      printf( "[mergeSort]:Sorted Right \n");
      merge( head, left, mid, right,index, comp);
      printf( "[mergeSort]:Merged\n");
    }
  else
    return;
}


