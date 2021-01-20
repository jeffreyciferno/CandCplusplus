// ASU CSE310 Assignment #4
// Name of Author: Jeffrey Ciferno
// ASU ID:1217664240
// Description: this is where you need to design functions on Hash table,
// such as hashInsert, hashDelete, hashSearch and hashDisplay

#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedList.h"
#include <math.h>

using namespace std;

class Hash
{
private:
	LinkedList** table;
	int m;
public:
	Hash(int size);
	~Hash();
	bool hashInsert(string productID, string name, string supplierID, string categoryID, string unit, double price);
	bool hashDelete(string productID, string name, string supplierID, string categoryID);
	bool hashSearch(string productID, string name, string supplierID, string categoryID);
	void hashDisplay();
private:
	int h(string key);
	double myConversion(string key, int base);
	int getIndex(string productID, string name, string supplierID, string categoryID);
	string getKey(string productID, string name, string supplierID, string categoryID);
};


//constructor
Hash::Hash(int size)
{
	table = new LinkedList * [size];
	for (int i = 0; i < size; i++)
	{
	table[i] = new LinkedList();
	}
m = size;
}


//Destructor
Hash::~Hash()
{
	delete[] table;
	table = NULL;
}

//hashInsert inserts a Product with the relevant info. into the hash table.
//it returns true if the data is inserted successfully and false otherwise
bool Hash::hashInsert(string productID, string name, string supplierID,
	string categoryID, string unit, double price)
{
	int index = getIndex(productID, name, supplierID, categoryID);
	string key = getKey(productID, name, supplierID, categoryID);
	if (table[index] == NULL)
		table[index] = new LinkedList();
	return table[index]->insert(productID, name, supplierID, categoryID, unit, price);
}

//hashDelete deletes a Product with the relevant key from the hash table.
//it returns true if it is deleted successfully and false otherwise
//Note: key is the combination of productID, name, supplierID and categoryID
bool Hash::hashDelete(string productID, string name, string supplierID, string categoryID)
{
	bool deleted = false;
	int index = getIndex(productID, name, supplierID, categoryID);
	//	string key = getKey(productID, name, supplierID, categoryID);
	if (hashSearch(productID, name, supplierID, categoryID) == true
		&& table[index] != NULL)
	{
		deleted = table[index]->deleteProduct(productID);
		cout << setw(5) << productID
			<< setw(35) << name
			<< setw(15) << supplierID
			<< setw(15) << categoryID
			<< " is deleted from hash table." << endl;
	}
	else
	{
		cout << setw(5) << productID
			<< setw(35) << name
			<< setw(15) << supplierID
			<< setw(15) << categoryID
			<< " is NOT found and NOT deleted from hash table." << endl;
	}
	return deleted;
}

//This function searches for a key inside the hash table and
//return true if it is found and false otherwise
//Note: key is the combination of productID, name, supplierID and categoryID
bool Hash::hashSearch(string productID, string name, string supplierID, string categoryID)
{
	bool found = false;
	int index = getIndex(productID, name, supplierID, categoryID);
	//	string key = getKey(productID, name, supplierID, categoryID);

	if (table[index] != NULL)
		found = table[index]->search(productID);
	if (found == true)
		cout << left
		<< setw(5) << productID
		<< setw(35) << name
		<< setw(15) << supplierID
		<< setw(15) << categoryID
		<< " is found in hash table." << endl;
	if (found == false)
		cout << left
		<< setw(5) << productID
		<< setw(35) << name
		<< setw(15) << supplierID
		<< setw(15) << categoryID
		<< " is NOT found in hash table." << endl;
	return found;
}

//This function prints all the elements from the hash table.
void Hash::hashDisplay()
{
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		if (table[i] == NULL || table[i]->getSize() == 0)
		{
			cout << "index: " << i << ", linked list size: 0" << endl;
			cout << "The list is empty" << endl << endl;
		}
		else
		{
			cout << "index: " << i << ", linked list size: " << table[i]->getSize() << endl;
			table[i]->displayList();
			cout << endl;
		}
	}
}

//The key is a concatenated string of name, productID, categoryID and address
//This function return the key for a given Product info.
string Hash::getKey(string productID, string name, string supplierID, string categoryID)
{
	return productID.append(name).append(supplierID).append(categoryID);
}

//This function returns the index for a given key
int Hash::getIndex(string productID, string name, string supplierID, string categoryID)
{
	string key = getKey(productID, name, supplierID, categoryID);
	int index = h(key);
	return index;
}

//This is the hash function I used, home brewed.
int Hash::h(string key)
{
	long double convertedNumber = myConversion(key, 13);
	if (convertedNumber < 0)
		convertedNumber = convertedNumber * (-1);
	convertedNumber = convertedNumber * 0.6180339887;
	return fmod(convertedNumber, 1) * m;
}

//This function converts string key into an integer key
double Hash::myConversion(string key, int base)
{
	double convertedNumber = 0;
	int var = 5;

	for (int i = key.length() - 1; i >= 0; i--)
	{
		int num = (int)key.at(i);
		convertedNumber += num * var;
		var = base * 15 / var ;
	}
	return convertedNumber;
}
