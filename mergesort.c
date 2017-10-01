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


node* merge(node * leftList, node* rightList,int index, int (*comp)(void*,void*))
{
  printf( "[merge]:ENTERING \n");
  printf("[merge]:Is left or right NULL\n");
  if ( leftList == NULL)
    {
      printf("[merge]:Left NULL return Right\n");
      return rightList;
    }
  if ( rightList == NULL)
    {
      printf("[merge]:Right NULL return Left\n");
      return leftList;
    }
  node * result = NULL;
  printf("[merge]:leftList:%s\n",leftList->data[index]);
  printf("[merge]:rightList:%s\n",rightList->data[index]);
  printf("[merge]:SWITCH. index:%d\n", index);
  if( (*comp)(strcat(leftList->data[index],"\0"),strcat(rightList->data[index],"\0")) <= 0)
      {
	printf( "[merge]:Less than 1 \n");
	result = leftList;
	printf( "[merge]:Less than 1 \n");
	result->next = merge(leftList->next,rightList,index,comp);
      }
      else
	{
	  printf( "[merge]:More than 1 \n");
	  result = rightList;
	  printf("[merge]:leftList:%s\n",leftList->data[index]);
	  result->next = merge(leftList,rightList->next,index,comp);
      	}
      
      return result;
}

void subDivide( node * head, node** left, node** right )
{
  printf("[subDivide]:ENtering\n");
  node * fast = head->next;
  node * slow = head;
  if ( head == NULL || head->next == NULL)
    {
      *left  = head;
      *right = NULL;
    }
  else
    {

      while( fast != NULL)
	{
	  fast = fast->next;
	  if ( fast != NULL )
	    {
	      fast = fast->next;
	      slow = slow->next;
	    }
	}
      *left  = head;
      *right = slow->next;
      slow->next = NULL;
      printf("[subDivide]: left:\n");
      printData(*left,4);
      printf("[subDivide]: right:\n");
      printData(*right,4);
    }
}

void mergeSort( node ** head, int index,  int (*comp)(void*,void*))
{
  printf("[mergeSort]:Initializing\n");
  node * left    = NULL;
  node * right   = NULL;
  node * result  = *head;
  if ( result == NULL || result->next == NULL)
    {
      printf("[mergeSort]:Result NULL?\n");
      return;
    }
  printf("[mergeSort]:Subdivide List\n");
    subDivide( result, &left, &right );
  printf("[mergeSort]:Recursive Left\n");
    mergeSort(&left, index, comp);
  printf("[mergeSort]:Recursive Right\n");
    mergeSort(&right, index, comp);

  printf("[mergeSort]:Merge\n");
  
  printf("[MERGESORT]: left:\n");
  printData(left,4);
  printf("[MERGESORT]: right:\n");
  printData(right,4);

  printf("[MERGESORT]:LEFTLIST:%s\n", left->data[index]);
  *head = merge(left,right,index, comp);
}


/*
void merge( node * head, int left, int mid, int right , int index , int (*comp)(void*, void* )){
=======

void merge( node * head, int left, int mid, int right , int index , int (*comp)(void*,void* )){
>>>>>>> 2dc39753c67234149bdf2a7a1314260f010a74bc
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
<<<<<<< HEAD
      printf( "***********\n");
      printData( rightList, 4);
      printData( leftList, 4);
      printf( "***********\n");      
      if( rightList == NULL )
	{
	  printf( "[merge]::leftList is NULL\n");
	  return;
	}
      printf( "[merge]::WHILE:checking data\n");
      printf( "[merge]::index %d\n",index+1);
      printf( "[merge]::left:%s|| right:%s \n",leftList->data[index],rightList->data[index]);
      switch ((*comp)(leftList->data[index],rightList->data[index]))
=======
      printf( "[merge]::WHILE:checking data\n");
      switch (comp(leftList->data[index],rightList->data[index]))
>>>>>>> 2dc39753c67234149bdf2a7a1314260f010a74bc
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
<<<<<<< HEAD
      head = leftList;
      node * curr = leftList;
      while ( curr->next != NULL )
	{
	  curr = curr->next;
	}
      curr->next = rightList;
      return;
=======
>>>>>>> 2dc39753c67234149bdf2a7a1314260f010a74bc
    }
}
void mergesort( node * head, int left, int right, int index, int ((*comp)(void * , void * )))
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
<<<<<<< HEAD
      printf( "[mergeSort]:NewHead:%s\n",head->data[index]);
=======
>>>>>>> 2dc39753c67234149bdf2a7a1314260f010a74bc
    }
  else
    return;
}

<<<<<<< HEAD
*/
