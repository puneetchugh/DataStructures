#include<stdio.h>
#include<stdlib.h>

void function();
int main(){
	
	function();
	function();
	function();
}

void function(){
	
	static int number = 0;
	printf("\nThe value of the number is %d\n", number++);
}
