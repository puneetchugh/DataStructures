#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int main(){

	int array[SIZE];

	int counter = 0;
	int inner_counter = 0;
	int temp = 0;
	int index = 0;

	for(counter = 0; counter < SIZE; counter++){
		
		printf("\nEnter the %d element", counter+1);
		scanf("%d", &array[counter]);
	}
	for (counter = 0; counter < (SIZE -1); counter++){

		temp = array[counter];
		
		for(inner_counter = (counter+1); inner_counter < (SIZE); inner_counter++ ){
				
			if(temp > array[inner_counter]){
			
				temp = array[inner_counter];
				index = inner_counter;
			}
		}

		if(index != counter){
			array[index] = array[counter];
			array[counter] = temp;
		}
	}

	printf("\nThe sorted array after selection sort is \n");
	for(counter = 0; counter < (SIZE); counter++){

		printf("%d\t", array[counter]);
	}
}
