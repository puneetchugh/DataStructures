#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int main(){

	int array[SIZE];
	int counter = 0;
	int inner_counter = 0;
	int temp = 0;
	for(counter = 0; counter < SIZE; counter++){
		
		printf("\nEnter the number %d\t", counter+1);
		scanf("%d", &array[counter]);
	}

	
	
	
	for(counter = 0; counter < (SIZE - 1); counter++){
		
		for(inner_counter = 0; inner_counter < (SIZE - 1 - counter); inner_counter++){

			if(array[inner_counter] > array[inner_counter + 1]){
				
				temp = array[inner_counter];
				array[inner_counter] =  array[inner_counter + 1];
				array[inner_counter + 1] = temp; 	
			}
		}
	}

	printf("\n The sorted array is \n");
	for(counter = 0; counter < SIZE; counter++){
		
		printf("%d\t", array[counter]);
	}
	
}
