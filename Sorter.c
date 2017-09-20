#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
//#include "Sorter.h"
#include <string.h>


int main(int argc, char *argv[])
 {
   char * inputStr;
   char ** headers = NULL;
   int numHeaders = 0;

   fscanf(stdin, "%s", inputStr);
   printf("%s \n",inputStr);

   char * test;
   test = strtok(inputStr,",");
   while (test != NULL)
     {
       printf("input:%s\n %d\n",test,numHeaders);
       test = strtok(NULL,",");
       numHeaders++;
     }
 
   headers = (char**)(numHeaders * sizeof(char *));


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
  


