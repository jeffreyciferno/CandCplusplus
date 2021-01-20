//*******************************************************************
// ASU CSE310 Assignment #6
// ASU ID:1217664240
// Name:Jeffrey Ciferno
// Description: this is a linked list of LinkedList used to represent
// the adjacency list of a graph.
//*****************************************************************

#include "LinkedList.h"

using namespace std;

//Node represents a departure city info. this includes
//the departure city name, its arrival city list and
//other DFS info.
struct Node
{
   string depCity;
   string color, pi;   //pi is the parent
   int dTime, fTime;   //discover & finish time

   LinkedList* arrCityList;
   struct Node* next;
};

class CityList
{
   private:
   struct Node* head;

   public:
   CityList();
   void destructor();
   Node* getHead();
   bool CityListInsert(string deptCityName, LinkedList* arrCityList);
   bool CityListDelete(string deptCityName);
   Node* CityListSearch(string deptCityName);
   void CityListDisplay();
};

//constructor
CityList::CityList()
{
   head = NULL;
}

//Destructor
void CityList::destructor()
{
   int cityCount = 0; //counts deleted nodes
   Node *node = NULL; //initalizes node as null

   	while(node != NULL) //as long as head != null it will  iterate through the array
   	{
	node = head; //sets node = head
  	head = head->next; //moves head to the next node
	delete(node->arrCityList);
  	delete(node); //deletes node which contained the previous heads data
	cityCount++;	//counts the deleted node before rerunning the loop
   	}

	head = NULL; //if head equals NULL and it skips the loop, resets the head to NULL again to ensure data deletetion
   cout<< "The number of deleted departure cities is: " << cityCount <<"\n";
}

//This function is accessor for head
Node* CityList::getHead()
{
   return head;
}

//Given a departure city name, this function searches
//the adjacency list and return a pointer that points
//to it, otherwise it return NULL
Node* CityList::CityListSearch(string deptCityName)
{
   struct Node *start = head; //sets starting variable to start and it is equal to head
	while(start != NULL) //as long as start isnt null
    	{
		if(start->depCity == deptCityName) //compares starts depCity to the inputed deptCityName
		{
			break; //breaks to end
		}
      else
			start = start->next; //Iterates start to the next node. Starts the reloop all over again
	}
	return start; //returns the boolean found
}

//This function inserts a departure city with its arrival city list into
//the cityList. It returns true if the data is inserted successfully
//and false otherwise. Note: departure cities are inserted in alphabetical
//order
bool CityList::CityListInsert(string deptCityName, LinkedList* arrCityList )
{

  struct Node *newCityList = new Node(); //Creates instance of product
  newCityList->depCity = deptCityName;
  newCityList->arrCityList = arrCityList;
  newCityList->next = NULL; //Sets the next node(tail) to null so it can be filled later

        if (head==NULL) //determines head's state
        {
        head = newCityList; //sets heads info to newCityList's information
        return true; //outputs a true boolean
        }
        else
        {
                if(newCityList->depCity.compare(head->depCity) < 0) //rearrange function
                {
                newCityList->next = head; //Sets newCityList next equal to head
                head = newCityList; //Sets head to newCityList
                return true; //Returns boolean true
                }
                else
                {
                Node* current = head; //Creates Node instance current and sets it equal to head
                Node* preCurrent = NULL; //Creates Node instance preCurrent and sets it equal to NULL

                        while(current != NULL) //Iterates through the array as long as current is not equal to null
                        {

                                if(newCityList->depCity.compare(current->depCity) < 0) //rearrange function
                                {
                                newCityList->next = current; //Sets newCityList next is equal to current
                                preCurrent->next = newCityList; //Sets preCurrent next is set to newCityList
                                return true; //Returns boolean true
                                }

                        preCurrent = current; //Iterates preCurrent to current
                        current = current->next; //Iterates current to current next
                        }

                preCurrent->next = newCityList;
                return true;
                }

        return false;
        }

}


//Given a departure city name, this function deletes it from the CityList.
//it returns true if it is deleted successfully and false otherwise
bool CityList::CityListDelete(string deptCityName)
{
   	if(head==NULL) //Checks head's state
	{
	return false; //If NULL returns false
	}
	else
	{
		if(head->depCity == deptCityName) //Compares the head's depCity to the inputed variable's deptCityName
		{
		Node *node = head; //sets instance of node equal to head
		head = head->next; //sets head equal to the next node
		delete(node); //deletes node from the list
		return true; //returns boolean true
		}

		else
		{
		Node *current = head; //Creates an instance of Node called current and set it equal to head
		Node *preCurrent = NULL; //Creates an instance of Node called preCurrent and set it equal to null

			while(current != NULL) //Iterates current while it is not equal to null
			{
				if(current->depCity == deptCityName) // Compares current depCity to deptCityName
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


//This function print the CityList on screen. It will
//print departure cities in alphabetical order, and for
//each departure city's reachable arrival city, it will
//also display them in alphabetical order
void CityList::CityListDisplay()
{
   struct Node* temp = head;
   while(temp != NULL)
   {
   cout << left;
   cout << setw(15) << temp->depCity;
   temp->arrCityList->printArrCityList();
   temp = temp->next;
   }
}
