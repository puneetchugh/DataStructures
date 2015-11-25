#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main(){

	//string myName = "12345";
	std::stringstream myName("1234");
	string sub;
	istringstream iss("100 name is Puneet Chugh");
	iss>>sub;
	std::stringstream individualMember(sub);
	int newInteger;
	int sum = 0;
	char * character = (char *)&sub;
	for(unsigned int i = 0; i< sub.size(); i++){
		
		//cout<<"The ascii value of character is " <<character;
		//character++;
		sum +=sub[i];
	}
	
	cout<<"The sum of all ascii characters of the string is "<<sum<<endl;
	individualMember >> newInteger;
	cout<<"The value of individual Member is "<< newInteger;
	int myNameInteger;
	myName >> myNameInteger;
	cout << "The value of integer is "<< myNameInteger;
}
