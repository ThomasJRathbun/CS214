/*
	Def's for Linked list 
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct _node
{
	int data;
	_node* next;

}node;

_node create(int, _node*);
_node insert(_node , int);

#endif
