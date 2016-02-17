#include<stdio.h>
#define SIZE 10

int main(){
	
	int array[SIZE];
	int counter = 0;
	int inner_counter = 0;
	int temp = 0;
	int moving_counter = 0;
	
	for(counter = 0; counter < SIZE; counter++){
		
		printf("\nEnter the number %d\t", counter+1);
		scanf("%d", &array[counter]);
	}


	for(counter = 1; counter < SIZE; counter++){
		
		temp = array[counter];
		//moving_counter = 0;
		for(inner_counter = 0; inner_counter < counter; inner_counter++){
		
			if(temp < array[inner_counter]){
				
				moving_counter = 0;
				for(moving_counter = counter; moving_counter > inner_counter; moving_counter--){
							
					array[moving_counter] = array[moving_counter - 1];
				}
				
				array[moving_counter] = temp;	
			}
		}
	}
	
	printf("\n The sorted array is \n");
	for(counter = 0; counter < SIZE; counter++){
		
		printf("%d\t", array[counter]);
	}

}
