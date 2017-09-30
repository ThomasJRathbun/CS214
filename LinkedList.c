node* create(int data , Node* next){
	node* new_Node = malloc(sizeof(node));

	if(new_Node == NULL){
		printf("error on creating new node" );
	}

	new_Node->data = data;
	new_Node->next = next;

	return new_node;
}

node* insert(node* head, int storeData){

	/*
		inserts in order, will need to change 
	*/
	node* prev = head; 
	node* nxt = head->next;

	//insert at head 
	if(head == NULL){
		head = create(storeData, NULL);
		return head;
	}

	if(head->data < storeData && ptr == NULL){
		head->next = create(storeData , NULL);
	}

	//iterate to find insert location 
	prev = head; 
	while(ptr != NULL){

		if(ptr->data > storeData ){
			//between two nodes
			prev->next = create(storeData, ptr);
			return head;

		}else if( ptr->data <  storeData && ptr->next == NULL){
			//insert at tail 
			ptr->next = create( storeData , NULL); 
			return head; 
		}else{
			//update nodes 
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return head;

}