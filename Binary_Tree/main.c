#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/***************************************************************
************************Tree Node*******************************
***************************************************************/
typedef struct node {

	struct node *left;
	struct node *right;
	char *name;
} node;



/****************************************************************
*Function name : find_minimum(node * incoming_node)             *
*Purpose       : It finds the inorder successor of the node to  *
*				 be deleted in BsT    							*
*Parameters														*
*    1) incoming_node - Its the right node of the node whose    *
*						inorder successor     					*
*						needs to be found       	            *
*Return value : It returns the inorder successor   				*
****************************************************************/
node * find_minimum(node * incoming_node){

	if(incoming_node -> left == NULL){
		
		return NULL;
	}
	else if(incoming_node -> left -> left == NULL){
		
		return incoming_node;
	}
	find_minimum(incoming_node->left);
}

/****************************************************************
*Function name : create_a_node(char * name, char * phone_number)*
*Purpose       : It creates a node to be inserted in the BsT    *
*Parameters														*
*    1) name - It accepts the name for struct node member name  *
*Return value : It returns the pointer to the newly             *
*				created node    					            *
****************************************************************/

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

	/*
	new_node->phone_number = (char *) malloc(strlen(phone_number) + 1);
	if(new_node == NULL){
		printf("\nThere's not enough memory to create a node");
		return NULL;
	}

	strcpy(new_node->phone_number, phone_number);
	*/
	new_node->left = new_node->right = NULL;
	
	return(new_node);
}

/************************************************************
*Function name : position_of_node(node ** head, char * name)*
*Parameters												    *
*	1) head - Its a double pointer carrying the address     *
*			  of the header.								*
*	2) node_to_be_added - Its a pointer to the node to  	*
*			  be added										*
*															*
* Return value - Returns the last node after which the 		*
*				 new node needs to be inserted				*
************************************************************/
node* position_of_node(node ** head, char * name, int method){

	if(*head == NULL){
		
		//*head = node_to_be_added;
		return NULL;
	}

	else{

		node * temp = *head;
		node * parent_of_temp = *head;
		while(1){

			if(strcmp(name, temp->name) > 0){
				
				if((temp->right) != NULL){
					parent_of_temp = temp;
					temp = temp->right;
				}
				
				else{
					//return temp;
					//temp->right = node_to_be_added;
					break;
				}

			}
			
			else if(strcmp(name, temp->name) < 0){

				if((temp->left) != NULL){
					parent_of_temp = temp;
					temp = temp->left;
				}

				else{
					//return temp;
					//temp->left = node_to_be_added;
					break;
				}
			}

			else if(strcmp(name, temp->name) == 0){
				
				printf("\nDuplicate name cannot be added.\n");
				break;
			}
			
		}
		if(method == 1){
			
			return temp;
		}
		else if(method == 2){
			return parent_of_temp;
		}
	}
	
}


/********************************************************************************
*Function Name : add_a_node(node ** head, char * name)					    	*
*Parameters:																	*
*	1) head - Its a double pointer having the address of the header				*
*	2) name - node's member name which is to be deleted							*
*																				*
*Return value - Nothing															*
********************************************************************************/
void add_a_node(node ** head, char * name){
	
	node * node_to_be_added = create_a_node(name, "201-416-9342");
	if(node_to_be_added == NULL){
		printf("Not enough space for the node");
		return;
	}
	if(*head == NULL){
		*head = node_to_be_added;
	}
	else{
		node * node_insert_pos = position_of_node(head, name, 1);
		if(node_insert_pos == NULL){
			if(*head == NULL){
			
				*head = node_to_be_added;
				return;
			}
			printf("It's a duplicate name. It cannot be added.");
		}
		else{
			if(strcmp(name, node_insert_pos->name)<0)
			{
				node_insert_pos->left = node_to_be_added;
			}
			else{
				node_insert_pos->right = node_to_be_added;
			}
		}	
	}

}
/*******************************************************************************
*Function Name : delete_a_node(node ** head, char * name)					   *
*Parameters:																   *
*	1) head - Its a double pointer having the address of the header			   *
*	2) name - node's member name which is to be deleted						   *
*																			   *
*Return value - Nothing														   *
*******************************************************************************/
void delete_a_node(node ** head, char * name){

	node *node_to_be_deleted = position_of_node(head, name, 2);
	
	if(node_to_be_deleted == NULL){
		printf("\nSuch a node does not exists\n");
	}
	
	else{
		
		if((node_to_be_deleted->right != NULL && strcmp(name, node_to_be_deleted->right->name) == 0) ||
				node_to_be_deleted->left != NULL && strcmp(name, node_to_be_deleted->left->name) == 0){
		
		
		
			if(node_to_be_deleted->right != NULL){
				
				
			if(node_to_be_deleted->right->right != NULL && node_to_be_deleted->right->left != NULL && strcmp(name, node_to_be_deleted->right->name) == 0){
				
				node * inorder_successor = find_minimum(node_to_be_deleted->right->right);
				if(inorder_successor == NULL){
					
					strcpy(node_to_be_deleted->right->name, node_to_be_deleted->right->right->name);
					node * deleted = node_to_be_deleted->right->right;
					free(deleted);
					return;
				}
				strcpy(node_to_be_deleted->right->name, inorder_successor->left->name);
				//delete the inorder successor
				node * deleted = inorder_successor->left;
				free(deleted);
			}
							
			else if(((node_to_be_deleted->right->right != NULL) && strcmp(name, node_to_be_deleted->right->name)==0)){
				
				node * deleted = node_to_be_deleted->right;
				node_to_be_deleted->right = node_to_be_deleted->right->right;
				free(deleted);			

			}
			
			else if((node_to_be_deleted->right->left != NULL) && strcmp(name, node_to_be_deleted->right->name)==0){
				
				node * deleted = node_to_be_deleted->right;
				node_to_be_deleted->right = node_to_be_deleted->right->left;
				free(deleted);
			}

			else{
				
				node * deleted = node_to_be_deleted->right;
				node_to_be_deleted->right = NULL;
				free(deleted);
			}
			}

			else if(node_to_be_deleted->left != NULL){
				
					
			 if(node_to_be_deleted->left->left != NULL && node_to_be_deleted->left->right != NULL && strcmp(name, node_to_be_deleted->left->name) == 0){
				node * inorder_successor = find_minimum(node_to_be_deleted->left->right);
				strcpy(node_to_be_deleted->left->name, inorder_successor->left->name);
				
				if(inorder_successor == NULL){
					
					strcpy(node_to_be_deleted->left->name, node_to_be_deleted->left->right->name);
					node * deleted = node_to_be_deleted->left->right;
					free(deleted);
					return;
				}
				strcpy(node_to_be_deleted->left->name, inorder_successor->left->name);
				//delete the inorder successor
				node * deleted = inorder_successor->left;
				free(deleted);
			}
				
				
			else if((node_to_be_deleted->left->left != NULL)&& strcmp(name, node_to_be_deleted->left->name)==0){
			
				node * deleted = node_to_be_deleted->left;
				node_to_be_deleted->left = node_to_be_deleted->left->left;
				free(deleted);
			}		
			else if((node_to_be_deleted->left->right != NULL)&& strcmp(name, node_to_be_deleted->left->name)==0){
				
				node * deleted = node_to_be_deleted->left;
				node_to_be_deleted->left = node_to_be_deleted->left->right;
				free(deleted);
			}
			else{
				
				node * deleted = node_to_be_deleted->left;
				node_to_be_deleted->left = NULL;
				free(deleted);
			}
			}
		
			/*	
			if(node_to_be_deleted->right->right != NULL && node_to_be_deleted->right->left != NULL && strcmp(name, node_to_be_deleted->right->name) == 0){
				
				node * inorder_successor = find_minimum(node_to_be_deleted->right->right);
				if(inorder_successor == NULL){
					
					strcpy(node_to_be_deleted->right->name, node_to_be_deleted->right->right->name);
					node * deleted = node_to_be_deleted->right->right;
					free(deleted);
					return;
				}
				strcpy(node_to_be_deleted->right->name, inorder_successor->left->name);
				//delete the inorder successor
				node * deleted = inorder_successor->left;
				free(deleted);
			}

			else if(node_to_be_deleted->left->left != NULL && node_to_be_deleted->left->right != NULL && strcmp(name, node_to_be_deleted->left->name) == 0){
				node * inorder_successor = find_minimum(node_to_be_deleted->left->right);
				strcpy(node_to_be_deleted->left->name, inorder_successor->left->name);
				
				if(inorder_successor == NULL){
					
					strcpy(node_to_be_deleted->left->name, node_to_be_deleted->left->right->name);
					node * deleted = node_to_be_deleted->left->right;
					free(deleted);
					return;
				}
				strcpy(node_to_be_deleted->left->name, inorder_successor->left->name);
				//delete the inorder successor
				node * deleted = inorder_successor->left;
				free(deleted);
			}

			else if(((node_to_be_deleted->right->right != NULL) && strcmp(name, node_to_be_deleted->right->name)==0)){
				
				node * deleted = node_to_be_deleted->right;
				node_to_be_deleted->right = node_to_be_deleted->right->right;
				free(deleted);			

			}
 
			else if((node_to_be_deleted->right->left != NULL) && strcmp(name, node_to_be_deleted->right->name)==0){
				
				node * deleted = node_to_be_deleted->right;
				node_to_be_deleted->right = node_to_be_deleted->right->left;
				free(deleted);
			}

			else if((node_to_be_deleted->left->left != NULL)&& strcmp(name, node_to_be_deleted->left->name)==0){
			
				node * deleted = node_to_be_deleted->left;
				node_to_be_deleted->left = node_to_be_deleted->left->left;
				free(deleted);
			}		
			else if((node_to_be_deleted->left->right != NULL)&& strcmp(name, node_to_be_deleted->left->name)==0){
				
				node * deleted = node_to_be_deleted->left;
				node_to_be_deleted->left = node_to_be_deleted->left->right;
				free(deleted);
			}*/
		}
		else{
			
			//the node is a root node
			if(strcmp(node_to_be_deleted->name, (*head)->name) == 0){
				
				if(((*head)->left == NULL) && ((*head)->right == NULL)){
					
					*head = NULL;
				}
				else if(((*head)->left != NULL) && ((*head)->right != NULL)){
					
					node * inorder_successor = find_minimum((*head)->right);
					if(inorder_successor == NULL){
					
						strcpy((*head)->name, (*head)->right->name);
						node * deleted = node_to_be_deleted->right;
						(*head)->right = NULL;
						free(deleted);
						return;
					}
					
				}

				else if((*head)->left == NULL){
					
					
					node * inorder_successor = find_minimum((*head)->right);
					if(inorder_successor == NULL){
					
						strcpy((*head)->name, (*head)->right->name);
						node * deleted = node_to_be_deleted->right;
						free(deleted);
						return;
					}
				}
				
				else if((*head)->right == NULL){
					
					node * deleted = *head;
					*head = (*head)->left;
					free(deleted);
				}		
			}
		}
	}
	
}

void pre_order(node * temp){

	if(temp == NULL){
		//printf("\nCan't do pre-order. The BsT is already empty");
		return;
	}
	
	printf("%s\t\n",temp->name);
	pre_order(temp->left);
	pre_order(temp->right);

}

void post_order(node * temp){
	
	if(temp == NULL){
		//printf("\nCan't do post -order. The BsT is already empty");
		return;
	}

	post_order(temp->left);
	post_order(temp->right);
	printf("%s\t\n", temp->name);
}

void in_order(node * temp){
	
	if(temp == NULL){
		return;
	}

	in_order(temp->left);
	printf("%s\t\n", temp->name);
	in_order(temp->right);
}
int main(){

	node * head = NULL;	
	add_a_node(&head, "Puneet");
	add_a_node(&head, "Jyoti");
	add_a_node(&head, "Pawan");
	add_a_node(&head, "Kamran");
	add_a_node(&head, "Xiomi");
	post_order(head);
	
	//delete_a_node(&head, "Jyoti");
	delete_a_node(&head, "Puneet");
	//delete_a_node(&head, "Kamran");
	post_order(head);
	return 1;
}
