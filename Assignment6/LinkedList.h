//************************************************************************
// ASU CSE310 Assignment #6
// ASU ID:1217664240
// Name:Jeffrey Ciferno
// Description: this is a linked list used to store arrival cities

#include <iostream>
#include <iomanip> //to format the output
#include <string>

using namespace std;

//struct ArrCity represents an arrival city information
struct ArrCity
{
   string arrCity;
   double price;
   struct ArrCity * next;
};

//class LinkedList will contains a linked list of arrival cities
class LinkedList
{
   private:
   struct ArrCity* head;

   public:
   LinkedList();
   ~LinkedList();
   ArrCity* getHead();
   bool isFound(string aCity);
   bool addArrCity(string aCity, double price);
   bool removeArrCity(string aCity);
   void printArrCityList();
};

//Constructor to initialize an empty linked list
LinkedList::LinkedList()
{
   head = NULL;
}

//Destructor
//Before termination, the destructor is called to free the associated memory.
//It deletes all the ArrCitys including the head and finally prints the number
//of ArrCitys deleted by it.
LinkedList::~LinkedList()
{
   int cityCount = 0; //Counts cities
   ArrCity *node = NULL; //initalizes node as null

   	while(head != NULL) //as long as head != null it will  iterate through the array
   	{
	node = head; //sets node = head
  	head = head->next; //moves head to the next node
  	delete(node); //deletes node which contained the previous heads data
	cityCount++;	//counts the deleted node before rerunning the loop
   	}

	head = NULL; //if head equals NULL and it skips the loop, resets the head to NULL again to ensure data deletetion

   head = NULL;
   cout<< "The number of deleted arrival cities are: " << cityCount <<"\n";
}

//Accessor to the header of the linked list
ArrCity* LinkedList::getHead()
{
   return head;
}

//A function to check if the parameterized arrival city is
//inside the LinkedList or not. Return true if it exists and
//false otherwise.
bool LinkedList::isFound(string aCity)
{
	struct ArrCity *start = head; //sets starting varaiable to start and it is equal to head
	bool found = false; //default state
	while(start != NULL) //as long as start isnt null
    	{
		if(start->arrCity == aCity) //compares starts arrCity to the inputed arrCity
		{
			found = true; //sets found to true
			break; //breaks to end
		}
      		else
			start = start->next; //Iterates start to the next node. Starts the reloop all over again
	}
	return found; //returns the boolean found
}

//Creates a new ArrCity and inserts it into the list at the right place.
//It also maintains an alphabetical ordering of the ArrCitys
//while inserting it into the list. Note: you cannot insert duplicated ArrCitys
//Return value: true if it is successfully inserted and false otherwise
bool LinkedList::addArrCity(string aCity, double price)
{

  struct ArrCity *newCity = new ArrCity(); //Creates instance of ArrCity
  newCity->arrCity = aCity; 
  newCity->price = price;
  newCity->next = NULL; //Sets the next node(tail) to null so it can be filled later

	if (head==NULL) //determines head's state
	{
	head = newCity; //sets heads info to newCity's information
	return true; //outputs a true boolean
	}
	else
	{
		if(newCity->arrCity.compare(head->arrCity) < 0) //rearrange function
		{
		newCity->next = head; //Sets newCity next equal to head
		head = newCity; //Sets head to newCity
		return true; //Returns boolean true
		}
		else
		{
		ArrCity* current = head; //Creates ArrCity instance current and sets it equal to head
		ArrCity* preCurrent = NULL; //Creates ArrCity instance preCurrent and sets it equal to NULL

			while(current != NULL) //Iterates through the array as long as current is not equal to null
			{

				if(newCity->arrCity.compare(current->arrCity) < 0) //rearrange function
				{
				newCity->next = current; //Sets newCity next is equal to current
				preCurrent->next = newCity; //Sets preCurrent next is set to newCity
				return true; //Returns boolean true
				}

			preCurrent = current; //Iterates preCurrent to current
			current = current->next; //Iterates current to current next
			}

		preCurrent->next = newCity;
		return true;
		}

	return false;
	}

}

//Removes the given ArrCity from the list, releases the memory and updates pointers.
//Return true if it is successfully removed, false otherwise.
bool LinkedList::removeArrCity(string aCity)
{
	if(head==NULL) //Checks head's state
	{
	return false; //If NULL returns false
	}
	else
	{
		if(head->arrCity == aCity) //Compares the head's arrCity to the inputed variable's arrCity
		{
		ArrCity *node = head; //sets instance of node equal to head
		head = head->next; //sets head equal to the next node
		delete(node); //deletes node from the list
		return true; //returns boolean true
		}

		else
		{
		ArrCity *current = head; //Creates an ArrCity called current and set it equal to head
		ArrCity *preCurrent = NULL; //Creates an instance of ArrCity called preCurrent and set it equal to null

			while(current != NULL) //Iterates current while it is not equal to null
			{
				if(current->arrCity == aCity) // Compares arrCity id to ArrCity aCity
				{
				preCurrent->next = current->next; //Changes position
				delete(current); //Delete current
				return true; //Returns boolean true
				}

			preCurrent = current; //sets preCurrent to current
			current = current->next; //sets current to current next
			}

		return false; //Returns boolean false
		}

	}
}

//Prints all the arrival cities info. in the linked list starting from the head.
void LinkedList::printArrCityList()
{
   struct ArrCity *temp = head;
   if(head == NULL)
   {
      cout << "The arrival city list is empty\n";
      return;
   }
   while(temp!= NULL)
   {
      cout << temp->arrCity << fixed << setprecision(2) << "(" << temp->price << "), ";
      temp = temp->next;
   }
   cout <<"\n";
}
