#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//#include "Sorter.h"
#include <string.h>


// ./sort -c movie_title

int main(int argc, char *argv[])
 {
   char *inputStr = (char*) malloc(10000 * sizeof(char));
   char ** headers = NULL;
   int numHeaders = 1;

   scanf( "%s", inputStr);
   printf("%s \n",inputStr);

   char * test;
   test = strtok(inputStr,",");
   while (test != NULL)
     {
       printf("input:%s\n %d\n",test,numHeaders);
       test = strtok(NULL,",");
       numHeaders++;
     }
 
   headers = (char**)malloc(numHeaders *  sizeof(char*));
   int headerIndex = 0;
   for ( headerIndex; headerIndex < numHeaders; headerIndex++)
     {
       printf("headerIndex: %d\n",headerIndex);
       headers[headerIndex] = (char*)malloc(100 * sizeof(char));
       if ( headerIndex == 0 )
	 headers[headerIndex * 100] = strtok(inputStr,",");
       else
	 {
	   headers[headerIndex * 100] = strtok(NULL,",");

	 }
       
     }

   int i = 0;
   for( i; i < numHeaders; i++)
     {
       printf( "%d : %s\n",i,headers[i*(100)]);
     }

   return 0;
 }

   /*
   int i =0;
   printf("scanned\n");

   int end =i -1;
   i = 0;
   while( i < end )
     {
       printf("header[%i]: %s\n",i,headers[i]);
       i ++;
     }
   
   /*   
  node * dataHead = NULL;
  dataHead = (node*) malloc(sizeof(node));
  dataHead->data = malloc(
  fscanf(stdin, "%s", headers);

   */
  


