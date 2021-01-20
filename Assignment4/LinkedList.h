// ASU CSE310 Assignment #4:
// Name of Author: Jeffrey Ciferno
// ASU ID: 1217664240
// Description: LinkedList implements a list of Product, we can
// insert, search, delete and display the product list

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Product
{
	string productID, name, supplierID, categoryID, unit;
	double price;
	struct Product *next = NULL;
};

class LinkedList
{
	private:
		struct Product *head;
		int size;
    public:
       	LinkedList();
       	~LinkedList();
       	bool insert(string productID, string name, string supplierID,
                     string categoryID, string unit, double price);
       	bool deleteProduct(string productID);
       	bool search(string productID);
       	void displayList();
         int getSize();

         //you can define your own auxiliary functions if necessary
         //----
};

//Constructor
LinkedList::LinkedList()
{
    head = NULL;
    size = 0;
}

//Destructor
LinkedList::~LinkedList()
{
   int productCount = 0; //Counts products
   Product *node = NULL; //initalizes node as null

   	while(head != NULL) //as long as head != null it will  iterate through the array
   	{
	node = head; //sets node = head
  	head = head->next; //moves head to the next node
  	delete(node); //deletes node which contained the previous heads data
	productCount++;	//counts the deleted node before rerunning the loop
   	}

	head = NULL;
}

//Return number of Products inside the Linked list
int LinkedList::getSize()
{
	return size;
}

//Insert the parameter Product at the head of the linked list.
//return true if it is inserted successfully and false otherwise
//Note: we will do this when a collision happens
bool LinkedList::insert(string productID, string name, string supplierID,
                        string categoryID, string unit, double price)
{
   struct Product *newProduct = new Product; //Creates instance of product
newProduct->name = name; 
newProduct->productID = productID;
newProduct->supplierID = supplierID;
newProduct->categoryID = categoryID;
newProduct->unit = unit;
newProduct->price = price;
newProduct->next = head;
head = newProduct; //Sets the next node(tail) to null so it can be filled later
size++;
}

//Delete the Product with the given productID from the linked list.
//Return true if it is deleted successfully and false otherwise
bool LinkedList::deleteProduct(string productID)
{
	if(head==NULL) //Checks head's state
	{
	return false; //If NULL returns false
	}
	else
	{
		if(head->productID == productID) //Compares the head's id to the inputed variable's product id
		{
		Product *node = head; //sets instance of node equal to head
		head = head->next; //sets head equal to the next node
		delete(node); //deletes node from the list
		return true; //returns boolean true
		}

	}
}

//This function searches the product list with the given productID
//returns true if it is found, otherwise return false.
bool LinkedList::search(string productID)
{
	Product *newProduct = head; //sets starting varaiable to start and it is equal to head
	 //default state
	while(newProduct != NULL) //as long as start isnt null
    {
		while(newProduct->productID != productID) //compares starts id to the inputed product idea
		{
		newProduct = newProduct->next;
			if(newProduct == NULL)
			{
			return false;	
			}
		}
	}
return true;
}

//This function displays the contents of the linked list.
void LinkedList::displayList()
{
   struct Product *temp = head;
	if(head == NULL)
   {
		return;
	}
	while(temp!= NULL)
    {
      cout << left;
		cout	<< setw(5) << temp->productID
            << setw(35) << temp->name
            << setw(15) << temp->supplierID
            << setw(15) << temp->categoryID
            << setw(25) << temp->unit
            << setw(5) << temp->price << endl;
		temp = temp->next;
	}
}
