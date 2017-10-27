#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mergesort.h"


int main(int argc, char *argv[])
 {
   int options;
   int cFlag =0;
   char * headerTitle = "deault_header";
   while( (options = getopt(argc, argv,"c:")) != -1 )
     {
       switch (options)
	 {
	 case 'c':
	   {
	     headerTitle = optarg;
	     cFlag = 1;
	     break;
	   }
	 }
     }

     if ( cFlag == 0 )
     {
       printf("No -c option: Please try again with a header selected to sort by\n");
       return -1;
     }


     node * head = (node*)malloc(sizeof(node));
     head->next =NULL;
     int chosenColumn=0;
     int numOfHeaders=0;
     chosenColumn = getHeader(head, headerTitle, &numOfHeaders);

     node * data = (node*)malloc(sizeof(node));
     readData( data, numOfHeaders);

     if(chosenColumn != -1)
       {
	 //	 printf("chosenColumn: %d\n",chosenColumn);
       }
     else
       {
	 printf("header: %s does not exist\n",headerTitle);
	 return -1;
       }
     mergeSort( &data, chosenColumn ,checkString);
     head->next = data;
     printData(head, numOfHeaders);
     return 0;
 }
