#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{

	struct node *left;
	struct node *right;
	char *name;
}node;


/*****************************************************
*Function name : create_a_node()					 *
*Parameters											 *
*    1) name - It accepts the name for struct node   *
*			   member name							 *
*    2) phone_number - It accepts the phone  number  *
*			   for struct node member phone_number	 *
*Return value : It returns the pointer to the newly  *
*				created node    					 *
*****************************************************/

node* create_a_node(char * name, char *phone_number){

	node *new_node = (node *) malloc(sizeof(node));
	if(new_node == NULL){
		printf("\nThere's not enough memory to create a node");
		return NULL;
	}

	new_node->name = (char*) malloc(strlen(name)+1);
	if(new_node == NULL){
		printf("\nThere's not enough memory to create a node");
		return NULL;
	}

	strcpy(new_node->name, name);

	new_node->phone_number = (char *) malloc(strlen(phone_number) + 1);
	if(new_node == NULL){
		printf("\nThere's not enough memory to create a node");
		return NULL;
	}

	strcpy(new_node->phone_number, phone_number);

	new_node->left = new_node->right = NULL;
	
	return(new_node);
}

/********************************************************
*Function name : position_of_node()						*
*Parameters												*
*	1) head - Its a double pointer carrying the address *
*			  of the header.							*
*	2) node_to_be_added - Its a pointer to the node to  *
*			  be added									*
*														*
* Return value - Returns the last node after which the 	*
*				 new node needs to be inserted			*
********************************************************/
node* position_of_node(node ** head, node * node_to_be_added){

	if(*head == NULL){
		
		*head = node_to_be_added;
		return NULL;
	}

	else{

		temp = *head;
		
		while(1){

			if(strcmp((node_to_be_added->name), temp->name) > 0){
				
				if((temp->right) != NULL){
					temp = temp->right;
				}
				
				else{

					//temp->right = node_to_be_added;
					break;
				}

			}
			
			else if(strcmp((node_to_be_added->name), (temp->name)) < 0){

				if((temp->left) != NULL){

					temp = temp->left;
				}

				else{

					//temp->left = node_to_be_added;
					break;
				}
			}

			else if(strcmp(node_to_be_added->name, temp->name) == 0){
				
				printf("\n");
				break;
			}
			
		}
		return temp;
	}
	
}


/********************************************************************************
*Function Name : delete_a_node()												*
*Parameters:																	*
*	1) head - Its a double pointer having the address of the header				*
*	2) name - node's member name which is to be deleted							*
*																				*
*Return value - Nothing															*
********************************************************************************/
void delete_a_node(node ** head, char * name){

	node *node_to_be_deleted = position_of_node(head);
	
	if(node_to_be_deleted == NULL){
		printf("\nSuch a node does not exists\n");
	}
	
	else{
		
		if
	}
	
}


int main(){

	
	return 1;
}
