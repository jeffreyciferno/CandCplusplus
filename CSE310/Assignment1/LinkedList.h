// Assignment: #1 (ASU Fall 2019)
// Name: Jeffrey Ciferno
// ASU ID: 1217664240
// ASU Email Address: jmcifern@asu.edu
// Description: Assignment1 header file, linked list.h with alphabetical sort upon adding information into the list

#include <iostream>
#include <iomanip> //to format the output
#include <string>

using namespace std;

//struct Product represents certain product information
struct Product
{
    string name;
    int id;
    double price;
    struct Product * next;
};

//class LinkedList will contains a linked list of Products
class LinkedList
{
    private:
        struct Product* head;

    public:
        LinkedList();
        ~LinkedList();
        bool isFound(int productId);
        bool addProduct(string productName, int productId, double productPrice);
        bool removeProduct(int productId);
        bool changeProductName(int productId, string newProductName);
        bool changeProductPrice(int productId, double newPrice);
        void printProductList();
};

//Constructor to initialize an empty linked list
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the existing linked list.
//It deletes all the nodes including the head and finally prints the number of nodes deleted by it.
//Return value: Prints the number of nodes deleted by it.
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

	head = NULL; //if head equals NULL and it skips the loop, resets the head to NULL again to ensure data deletetion

   cout<< "The number of deleted products is: " << productCount <<"\n";
}

//A function to identify if the parametered Product is inside the LinkedList or not.
//Return true if it exists and false otherwise.
bool LinkedList::isFound(int productId)
{
	struct Product *start = head; //sets starting varaiable to start and it is equal to head
	bool found = false; //default state
	while(start != NULL) //as long as start isnt null
    {
		if(start->id == productId) //compares starts id to the inputed product idea
		{
			found = true; //sets found to true
			break; //breaks to end
		}
      else
			start = start->next; //Iterates start to the next node. Starts the reloop all over again
	}
	return found; //returns the boolean found
}

//Creates a new node and inserts it into the list at the right place.
//It also maintains an alphabetical ordering of the Products by their names
//while inserting it into the list. Note: you cannot insert duplicated products
//Return value: true if it is successfully inserted and false in case of failures.
bool LinkedList::addProduct(string productName, int productId, double productPrice)
{
struct Product *newProduct = new Product(); //Creates instance of product
newProduct->name = productName; 
newProduct->id = productId;
newProduct->price = productPrice;
newProduct->next = NULL; //Sets the next node(tail) to null so it can be filled later

	if (head==NULL) //determines head's state
	{
	head = newProduct; //sets heads null info to newproduct's information
	return true; //outputs a true boolean if it worked properly
	}
	else
	{
		if(newProduct->name.compare(head->name) < 0) //rearrange function
		{
		newProduct->next = head; //Sets newProduct next equal to head
		head = newProduct; //Sets head to newProduct
		return true; //Returns boolean true
		}
		else
		{
		Product* current = head; //Creates product instance current and sets it equal to head
		Product* preCurrent = NULL; //Creates product instance preCurrent and sets it equal to NULL

			while(current != NULL) //Iterates through the array as long as current is not equal to null
			{

				if(newProduct->name.compare(current->name) < 0) //rearrange function
				{
				newProduct->next = current; //Sets newProduct next is equal to current
				preCurrent->next = newProduct; //Sets preCurrent next is set to new product
				return true; //Returns boolean true
				}

			preCurrent = current; //Iterates preCurrent to current
			current = current->next; //Iterates current to current next
			}

		preCurrent->next = newProduct;
		return true;
		}

	return false;
	}
}

//Removes the given Product from the list, releases the memory and updates pointers.
//Return true if it is successfully removed, false otherwise.
bool LinkedList::removeProduct(int productId)
{
	if(head==NULL) //Checks head's state
	{
	return false; //If NULL returns false
	}
	else
	{
		if(head->id == productId) //Compares the head's id to the inputed variable's product id
		{
		Product *node = head; //sets instance of node equal to head
		head = head->next; //sets head equal to the next node
		delete(node); //deletes node from the list
		return true; //returns boolean true
		}

		else
		{
		Product *current = head; //Creates an instance of product called current and set it equal to head
		Product *preCurrent = NULL; //Creates an instance of product called preCurrent and set it equal to null

			while(current != NULL) //Iterates current while it is not equal to null
			{
				if(current->id == productId) // Compares current id to product id
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

//Modifies the data of the given Product.
//Return true if it modifies successfully and false otherwise.
bool LinkedList::changeProductName(int productId, string newProductName)
{
	if(head == NULL) //Checks head's state
	{
	return false; //Returns false if head is NULL.
	}
	else
	{
	Product *current = head; //Instantiates a pointer current equal to head
	double currentPrice;
		while(current != NULL) // Does function while current != NULL
		{

			if(current->id == productId) //Compares the id of current to the inputed "id", if equal does the function
			{
			current->name = newProductName; //Sets current's name equal to inputed product's name
			currentPrice = current->price; //Sets currentPrice to current price
			removeProduct(productId); //Removes product to be readded by following line
			addProduct(newProductName, productId, currentPrice); //Adds product back into the list with and updated name as well as resorting it
			return true; //Returns boolean true
                        }
				
		current = current->next; //Iterates through the list
		}

	return false; //Returns the boolean false if it fails after running
	}
}

bool LinkedList::changeProductPrice(int productId, double newPrice)
{
	if(head == NULL) //Checks head's state
        {
        return false; //Returns false if head is equal to false
        }
        else
        {	
        Product *current = head; //Instantiation of variable current, set equal to head

                 while(current != NULL) //Checks if current is equal to NULL, if so runs the function
                 {
                         if(current->id == productId) //Compares current's id to the inputed variable's id
                         {
                         current->price = newPrice; //Sets current's price to the inputed price.
                         return true; //Returns boolean true
                         }

                  current=current->next; //Iterates to the next variable in the list
                 }

         return false; //Returns the boolean false if it fails after running
         }

}

//Prints all the elements in the linked list starting from the head node
void LinkedList::printProductList()
{
	if(head == NULL) //Checks head's state
	{
	cout<<"\n Error: NULL List"<< endl; //Writes error
	}
	else
	{
	Product *current = head; //Instantiates Current
		while(current != NULL)
		{
		cout << current->id << ", ";
		cout << current->name << ", $";
		cout << std::setprecision(2) << fixed << current->price << "\n";
		current = current->next; //Moves to next node
		}
	}
}
