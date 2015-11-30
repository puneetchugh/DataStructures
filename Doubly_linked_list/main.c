#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{

	struct node *left;
	struct node *right;
	char *name;
	char *phone_number;
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

	new_node->name = (char*) malloc(strlen(name)+1);
	strcpy(new_node->name, name);

	new_node->phone_number = (char *) malloc(strlen(phone_number) + 1);
	strcpy(new_node->phone_number, phone_number);

	new_node->left=new_node->right=NULL;
	
	return(new_node);
}

/***************************************************************
*Function name : add_to_front()								   *
*Parameters													   *
*      1) head : Its a double pointer value that receives the  *
*	   			 address of header 							   *
*	   2) node_to_be_added: It gets the pointer to the node to *
*							be added						   *
*Return value  : Nothing									   *
***************************************************************/
void add_to_front(node **head, node *node_to_be_added){

	if(*head == NULL){

		node_to_be_added->right=node_to_be_added->left = NULL;

		*head = node_to_be_added;
	}
	
	else{
		
		node * temp = *head;
		node_to_be_added->right = temp;
		node_to_be_added->left  = NULL;
		*head = node_to_be_added;
	}
}

/***************************************************************
*Function name : add_to_rear()								   *
*Parameters													   *
*      1) head : Its a double pointer value that receives the  *
*	   			 address of header 							   *
*	   2) node_to_be_added: It gets the pointer to the node to *
*							be added						   *
*Return value  : Nothing									   *
***************************************************************/


void add_to_rear(node **head, node *node_to_be_added){

	if(*head == NULL){
		
		add_to_front(head, node_to_be_added);
	}
	
	else{

		node *temp = *head;
		while(temp->right != NULL){
			temp = temp->right;
		}

		node_to_be_added->right = NULL;
		node_to_be_added->left = temp;
		temp->right = node_to_be_added;
	}
}


/***************************************************************
*Function name : add_after_a_node()							   *
*Parameters													   *
*      1) head : Its a double pointer value that receives the  *
*	   			 address of header 							   *
*	   2) node_to_be_added: It gets the pointer to the node to *
*							be added						   *
*	   3) name : It receives the node member name's value, 	   *
*				 after which we need to insert the node		   *
*Return value  : Nothing									   *
***************************************************************/

void add_after_a_node(node **head, node *node_to_be_added, char *name){

	if(*head == NULL){
		
		printf("\nThere's no node in the list. How can you delete one ??\n");
		return;
	}

	else{
			
		node * temp = *head;
		int flag = 0;
		while((temp != NULL) || (flag != 1)){
			
			if(strcmp(name, temp->name) == 0){
				
				flag = 1;
				break;
			}
			temp = temp->right;
			
		}

		node_to_be_added->right = temp->right;
		temp->right->left = node_to_be_added;
		//another way of doing previous step
		//node_to_be_added->right->left = node_to_be_added; 
		node_to_be_added->left  = temp;
		temp->right=node_to_be_added;
		printf("\nNode added successfully\n");
	}
}


/***************************************************************
*Function name : traverse_list()							   *
*Parameters													   *
*      1) head : Its a pointer that receives the header of     *
*				 the list        							   *		
*Return value  : Nothing									   *
***************************************************************/


void traverse_list(node * head){

	if(head == NULL){
	
		printf("\nThe list is empty\n");
	}

	else{
		
		printf("\nName \tPhone_number");
		node *temp = head;
		while(temp != NULL){
			
			printf("\n%s\t%s", temp->name, temp->phone_number);
			temp = temp->right;
			
		}

	}
	
	printf("\n");

}


/***************************************************************
*Function name : remove_front_node()						   *
*Parameters													   *
*      1) head : Its a double pointer that receives the        *
*				 address of the head        				   *		
*Return value  : Nothing									   *
***************************************************************/


void remove_front_node(node ** head){

	if(*head == NULL){
		
		printf("\nThere's no node to delete");
	}	

	else{

		node * temp = *head;
		
		temp = temp->right;
		temp->left = NULL;
		*head = temp;
	}
}



/***************************************************************
*Function name : remove_end_node()  						   *
*Parameters													   *
*      1) head : Its a double pointer that receives the        *
*				 address of the head        				   *		
*Return value  : Nothing									   *
***************************************************************/


void remove_end_node(node ** head){
	
	if(*head == NULL){
		
		printf("\nThere's no node to delete");
	}

	else{

		node * temp = *head;
		while(temp->right != NULL){

			temp = temp->right;
		}

		temp->left->right = NULL;

	}
}



/***************************************************************
*Function name : remove_node_from_between()  				   *
*Parameters													   *
*      1) head : Its a double pointer that receives the        *
*				 address of the head        				   *
*	   2) name : Its the name member of node that is to be 	   *
*				 deleted		   							   *		
*Return value  : Nothing									   *
***************************************************************/


void remove_node_from_between(node ** head, char * name){

	if(*head == NULL){

		printf("\nThere's no node to delete");
		return;

	}

	else{
		
		node * temp = *head;
		int flag = 0;
		if(strcmp(temp->name, name) == 0){
			
			if(temp->right != NULL){
				temp = temp->right;
				temp->left = NULL;
				*head = temp;
			}
	
			else{
				temp = NULL;
			}

		return;
		}

	
		while((temp->right != NULL) || (flag != 1)){
			
			temp = temp->right;

			if(strcmp(temp->name, name) == 0){

				flag = 1;
				break;
			}

		}
		
		if(flag == 1){
			
			if(temp->right == NULL){
				temp->left->right = NULL;
				return;
			}
			
			temp->left->right = temp->right;
			temp->right->left = temp->left;

		}
	}
}


int main(){

	node * head = NULL;

	//node *new_node = create_a_node("puneet", "2019937915");
	
	//printf("\nThe value of name member of node is %s ", new_node->name);
	//printf("\nThe value of phone_number member of the node is %s", new_node->phone_number);
	
	int choice;
	node * new_node = NULL;
		
	//add_to_front(&head, new_node);
	//traverse_list(head);
	
	
	do{

		printf("\nPerform some operation\n");
		printf("\n1.Add a node to the front");
		printf("\n2.Add a node to the end");
		printf("\n3.Add a node to somewhere in the middle");
		printf("\n4.Delete a node from the front");
		printf("\n5.Delete a node from the end");
		printf("\n6.Delete a node from somewhere in the middle");
		printf("\n7.Traverse the list");
		printf("\n8.Exit\n");

		while(getchar() != '\n');
		scanf("%d",&choice);
	
		switch(choice){

			case 1: {
						new_node = create_a_node("puneet", "2019937915");
						add_to_front(&head, new_node);
						break;
					}
			case 2: new_node = create_a_node("jyoti", "9968271270");
					add_to_rear(&head, new_node);
					break;
			case 3: new_node = create_a_node("om_chugh", "9810502403");
					add_after_a_node(&head, new_node, "puneet");
					break;
			case 4: remove_front_node(&head);
					break;
			
			case 5: remove_end_node(&head);
					break;
			
			case 6: remove_node_from_between(&head, "puneet");
					break;
	
			case 7: traverse_list(head);
					break;

			default: printf("\n You did not enter a valid input. Enter again\n");
		}
			
	}while(choice != 8);
	

	//add_to_front(&head, new_node);
	//traverse(head);
	
	return 1;

}
