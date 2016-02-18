#include<stdio.h>
#include<stdlib.h>


int main(){

	char matrix[3][3] = {{'1','2','3'},
						{'4','5','6'},
						{'7','8','9'}};
	

	int row = 0;
	int column = 0;
	int choice = 0;
	int counter = 0;
	char player;
	
	for(counter = 0; counter < 9; counter++){
		
		
		printf("Its Player %d turn . Please enter the position number where you want to place your number.\t",(counter%2)+1);
		scanf("%d", &choice);


		if(counter%2 == 0){
			player = '0';
		}
		else{
			player = 'X';
		}

		

		row = (--choice)/3;
		column = choice%3;
		
		
		if(matrix[row][column] == '0' || matrix[row][column] == 'X'){
			
			printf("\nThis position is already filled. Choose some other position.\n");
			counter--;
			continue;
		}
		matrix[row][column]=player;
		
		if(((matrix[0][0] == matrix[1][1]) && (matrix[0][0] == matrix [2][2])) || ((matrix[0][2] == matrix[1][1]) && (matrix[0][2]== matrix[2][0]))){

			printf("Player %d has won\n", (counter%2)+1);
			break;
		}	
		
		if(((matrix[row][0] == matrix[row][1]) && (matrix[row][0] == matrix[row][2])) || ((matrix[0][column] == matrix[1][column]) && (matrix[0][column] == matrix[2][column]))){
			printf("\nPlayer %d has won\n", (counter%2)+1);
			break;
		}
	}

	int inner_row = 0;
	counter = 0;
	for(row = 0; row <= 4; row++){
		for(column = 0; column <= 4; column++){
			
			if((row%2 == 0) && (column%2 == 0)){
				//inner_row = counter - 1;
				printf("%c", matrix[counter/3][counter%3]);
				counter++;	
			}
			
			else if(row%2 == 1){
				printf("-");
			}
			
			else if(column%2 == 1){
				printf("|");
			}
		}
		printf("\n");
	}	

	return 0;
}
