#include<iostream>
//#include<stdio>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
//#include <boost/algorithm/string/predicate.hpp>
//#include <boost/algorithm/string.hpp>
//#include<boost>
#define FILE_NAME "HW4Data.txt"


using namespace std;
// Class Flight for storing the flight details
class Flight{

	public:
			int flightNumber;
		 	string flightOrigin;
			string flightDest;
			int flightJourneyTime;
			Flight *nextNode;
	
};

// This function fetchFileData fetches data from the file HW4Data.txt and forms a linkedlist
void fetchFileData(string fileName, Flight ** head){
	string line;
 	ifstream myfile ("HW4Data.txt");
	
	    if (myfile.is_open())
    {
    	while ( getline (myfile,line) )
    	{	
			int loopCounter = 0;
			istringstream iss(line);
			Flight *newNode = new Flight();
			//cout<<"The address of newNode is"<<newNode<<endl;

    		do
    		{
				
        		string sub;
        		iss >> sub;
				std::stringstream individualMember(sub);
				//cout << "Substring: " << sub << endl;

				if(loopCounter == 0){
					
					int flightNumber;
					individualMember >> flightNumber;
					newNode-> flightNumber = flightNumber;
					//cout<<"Substring: "<< newNode->flightNumber<<endl; 
				}
				
				else if(loopCounter == 1){
					
					newNode->flightOrigin = sub; 
					//cout<<"Substring: "<< newNode->flightOrigin<<endl;
				
				}
				else if(loopCounter == 2){
					
					newNode->flightDest = sub;
					//cout<<"Substring: "<< newNode->flightDest<<endl;
				}
					
				else if(loopCounter == 3){
					int flightJourneyTime;
					individualMember >> flightJourneyTime;
					newNode->flightJourneyTime = flightJourneyTime;
					//cout<<"Substring: "<< newNode->flightJourneyTime<<endl;
				}
        		loopCounter++;

    		} while (iss);

			if((*head) == NULL){
				//cout<<"The newNode address is "<<newNode<<endl;
				newNode->nextNode = NULL;
				(*head) = newNode;
				//cout<<"Head is initially NULL"<<endl;
				//cout<<"The value of head is" << *head<< endl;
				//cout<<"The new address of newNode is "<< *head<<endl;
			}
		
			else{
				newNode -> nextNode = *head;
				*head = newNode;
				//cout<<"Head is not NULL now"<<endl;
				//cout<<"The new address of head is " << *head<<endl ;
			}
      		//cout << line << '\n';
    	}
    	myfile.close();
	}
}

//This function storeInDatabasewrtFlightNumber stores the data in the map on the basis of flight number
void storeInDatabasewrtFlightNumber(Flight *head[], Flight *listHead){

	//cout<<"I am in storeInDatabasewrtFlightNumber"<<endl;
	int counter = 0;
	
	Flight * temp = listHead;
	for(;counter<20;counter++){
		head[counter] = NULL;
	}
	while(temp != NULL){
		Flight *newNode = new Flight();
		newNode->flightNumber = temp->flightNumber;
		newNode->flightOrigin = temp->flightOrigin;
		newNode->flightDest = temp->flightDest;
		newNode->flightJourneyTime = temp->flightJourneyTime;
		temp = temp->nextNode;
		int indexNumber = (newNode->flightNumber) % 20;
		if(head[indexNumber] == NULL){
			newNode->nextNode = NULL;
			head[indexNumber] = newNode;
		}
		else{
			newNode->nextNode = head[indexNumber];
			head[indexNumber] = newNode;
		}
		counter++;
	}
}

// This function storeInDatabasewrtOriginAirport stores the data in the map on the basis of Departing Airport. It first calculates the sum of the ASCII values of the Departing Airport's characters and then calculates the key using sum.
void storeInDatabasewrtOriginAirport(Flight *head[], Flight *listHead){

	//cout<<"I am in storeInDatabasewrtOriginAirport"<<endl;
	int counter = 0;
	
	Flight * temp = listHead;
	for(;counter<20;counter++){
		head[counter] = NULL;
	}
	while(temp != NULL){
		Flight *newNode = new Flight();
		newNode->flightNumber = temp->flightNumber;
		newNode->flightOrigin = temp->flightOrigin;
		newNode->flightDest = temp->flightDest;
		newNode->flightJourneyTime = temp->flightJourneyTime;
		temp = temp->nextNode;
		int sum = 0;
		for(unsigned int i = 0; i < (newNode->flightOrigin).size(); i++){
		
		sum += (newNode->flightOrigin)[i];
	}

		int indexNumber = (sum) % 20;
		if(head[indexNumber] == NULL){
			newNode->nextNode = NULL;
			head[indexNumber] = newNode;
		}
		else{
			newNode->nextNode = head[indexNumber];
			head[indexNumber] = newNode;
		}
		counter++;
	}

}

// This function storeInDatabasewrtDestAirport stores the data in the map on the basis of Arriving Airport. It first calculates the sum of the ASCII values of the Arriving Airport's characters and then calculates the key using the sum.

void storeInDatabasewrtDestAirport(Flight *head[], Flight *listHead){
	
	//cout<<"I am in storeInDatabasewrtDestAirport"<<endl;
	int counter = 0;
	
	Flight * temp = listHead;
	for(;counter<20;counter++){
		head[counter] = NULL;
	}
	while(temp != NULL){
		Flight *newNode = new Flight();
		newNode->flightNumber = temp->flightNumber;
		newNode->flightOrigin = temp->flightOrigin;
		newNode->flightDest = temp->flightDest;
		newNode->flightJourneyTime = temp->flightJourneyTime;
		temp = temp->nextNode;
		int sum = 0;
		for(unsigned int i = 0; i < (newNode->flightOrigin).size(); i++){
		
		sum += (newNode->flightDest)[i];
	}

		int indexNumber = (sum) % 20;
		if(head[indexNumber] == NULL){
			newNode->nextNode = NULL;
			head[indexNumber] = newNode;
		}
		else{
			newNode->nextNode = head[indexNumber];
			head[indexNumber] = newNode;
		}
		counter++;
	}


}
//node * nodeList[];


//This searches an entry by matching the flight number. Calculates key much the same way storeInDatabasewrtFlightNumber().
void searchWrtFlightNumber(Flight *head[], int flightNumber){

		
	int key = flightNumber % 20;

	if(head[key] == NULL){
		cout<<"There's no entry with this airport Number"<<endl;
	}

	else{
		int counter = 0;
		Flight * temp = head[key];
		while(temp != NULL){
		
			if(flightNumber == (temp->flightNumber)){
				
				cout<<"Flight Number = "<< temp->flightNumber<<"\tFlight Origin = "<<temp->flightOrigin<<"\tFlight Destination = "<<temp->flightDest<<"\t Flight Duration = "<<temp->flightJourneyTime<<endl;
				counter++;
			}
			temp = temp->nextNode;
		}
		if(counter == 0){
			cout<<"There's no entry with this flight Number"<<endl;
		}
	}
}

// This searches an entry by matching the Departing Airport. The key is calcuated in the same way as in storeInDatabasewrtOriginAirport().
void searchWrtOriginAirport(Flight *head[], string OriginAirport){

		
	transform(OriginAirport.begin(), OriginAirport.end(), OriginAirport.begin(), ::toupper);
	int sum = 0;
	for(unsigned int i = 0; i < OriginAirport.size(); i++){

		sum += OriginAirport[i];
	}
	
	int key = sum%20;
	if(head[key] == NULL){
		cout<<"There's no entry with this airport Number"<<endl;
	}

	else{
		int counter = 0;
		Flight * temp = head[key];
		while(temp != NULL){
		
			if (OriginAirport.size() == ((temp->flightOrigin).size())){
				
				int flag = 0;
				for(unsigned int loopCounter = 0; loopCounter< OriginAirport.size(); loopCounter++){
					if(OriginAirport[loopCounter] == (temp->flightOrigin)[loopCounter]){
						flag = 1;
					}
					else{
						flag = 0;
						break;
					}
				}
				if(flag == 1){
					cout<<"Flight Number = "<< temp->flightNumber<<"\tFlight Origin = "<<temp->flightOrigin<<"\tFlight Destination = "<<temp->flightDest<<"\t Flight Duration = "<<temp->flightJourneyTime<<endl;
					counter++;
				}
			}
			temp = temp->nextNode;
		}
		if(counter == 0){
			cout<<"There's no entry with this flight Number"<<endl;
		}
	}
}

// This searches an entry by matching the Arriving Airport. The key is calcuated in the same way as in storeInDatabasewrtDestAirport().

void searchWrtDestAirport(Flight *head[], string DestAirport){

		
	transform(DestAirport.begin(), DestAirport.end(), DestAirport.begin(), ::toupper);
	int sum = 0;
	for(unsigned int i = 0; i < DestAirport.size(); i++){

		sum += DestAirport[i];
	}
	
	int key = sum%20;
	if(head[key] == NULL){
		cout<<"There's no entry with this airport Number"<<endl;
	}

	else{
		int counter = 0;
		Flight * temp = head[key];
		while(temp != NULL){
		
			if (DestAirport.size() == ((temp->flightDest).size())){
				
				int flag = 0;
				for(unsigned int loopCounter = 0; loopCounter< DestAirport.size(); loopCounter++){
					if(DestAirport[loopCounter] == (temp->flightDest)[loopCounter]){
						flag = 1;
					}
					else{
						flag = 0;
						break;
					}
				}
				if(flag == 1){
					cout<<"Flight Number = "<< temp->flightNumber<<"\tFlight Origin = "<<temp->flightOrigin<<"\tFlight Destination = "<<temp->flightDest<<"\t Flight Duration = "<<temp->flightJourneyTime<<endl;
					counter++;
				}
			}
			temp = temp->nextNode;
		}
		if(counter == 0){
			cout<<"There's no entry with this flight Number"<<endl;
		}
	}
}


int main(){
	
	Flight *head = NULL;
	fetchFileData(FILE_NAME, &head);

	Flight *dataBasewrtFlightNumber[20];
	Flight *dataBasewrtOriginAirport[20];
	Flight *dataBasewrtDestAirport[20];

	/*
	
	if(head == NULL){
		cout<<"Head is NULL";
	}
	Flight *temporaryObject = head;	
	while(temporaryObject != NULL){
		
		cout<<temporaryObject->flightNumber<<endl;
		cout<<temporaryObject->flightOrigin<<endl;
		cout<<temporaryObject->flightDest<<endl;
		cout<<temporaryObject->flightJourneyTime<<endl;
		temporaryObject = temporaryObject->nextNode;

	}*/
		
	storeInDatabasewrtFlightNumber(dataBasewrtFlightNumber,head);
	storeInDatabasewrtOriginAirport(dataBasewrtOriginAirport,head);
	storeInDatabasewrtDestAirport(dataBasewrtDestAirport,head);

	int input;

	do{
		std::cin.clear();
		cout<<"Search your flight details"<<endl;
		cout<<"1. Enter 1 for searching by Flight Number"<<endl;
		cout<<"2. Enter 2 for searching by Departure Airport"<<endl;
		cout<<"3. Enter 3 for seraching by Arrival Airport"<<endl;
		cout<<"4. Exit"<<endl;

		cin>>input;
		
		switch(input){
	
			case 1:{ 
						int flightNumber;
						cout<<"Enter The flight Number"<<endl;
						cin>>flightNumber;		
						searchWrtFlightNumber(dataBasewrtFlightNumber, flightNumber);
						break;
					}
					
			case 2: {
						string flightDeparture;
						cout<<"Enter the flight Departure Airport"<<endl;
						cin>>flightDeparture;
						searchWrtOriginAirport(dataBasewrtOriginAirport, flightDeparture);
						break;
					}
					
			case 3: {
						string flightArrival;
						cout<<"Enter the flight Arrival Airport"<<endl;
						cin>>flightArrival;
						searchWrtDestAirport(dataBasewrtDestAirport, flightArrival);
						break;
					}
					
			case 4: {
						cout<<"Exiting..."<<endl;
						break;
					}
			default: cout<<"You entered a wrong choice."<<endl;

		}
		std::cin.clear();	

	}while(input != 4);

	
	/*
	int count = 0;
	while(count != 20){
		
		if(dataBasewrtFlightNumber[count] == NULL){
			cout<<"This entry is null"<<endl;
		}
		
		if(dataBasewrtFlightNumber[count] != NULL){
		Flight *temp = dataBasewrtFlightNumber[count];

			while(temp != NULL){
			
				cout<<"The count is : "<<count<<endl;
			
				//temp = dataBasewrtFlightNumber[count];
				cout<<temp->flightNumber<<endl;
				cout<<temp->flightOrigin<<endl;
				cout<<temp->flightDest<<endl;
				cout<<temp->flightJourneyTime<<endl;
				temp = temp->nextNode;

				
			
			}
	
			
		}
		
		count++;
	}*/
		
	//	searchWrtFlightNumber(dataBasewrtFlightNumber, 1401);
	//	searchWrtOriginAirport(dataBasewrtOriginAirport, "KJFK");
	//	searchWrtDestAirport(dataBasewrtDestAirport, "KJFK");	
		
}

/*
int createFlightObject(Flight * arrayList[]){
	
	static int counter = 0;
	node * newNode = (node*)malloc(sizeof(Flight));

	newNode->flightNumber = ;
	newNode->flightOrigin = ;
	newNode->flightDest = ;
	newNode->flightJourneyTime = ;

	arrayList[counter++] = newNode;
	
}*/
