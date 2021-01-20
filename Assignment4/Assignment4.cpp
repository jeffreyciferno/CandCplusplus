// ASU CSE310 Assignment #4
// Name of Author: Jeffrey Ciferno
// ASU ID:1217664240
// Description: this is the main program that reads input from a text file,
// it then call hash functions to execute hash commands given in the input.

/**************************************************************************
//(1)Describe here what is your hash function? How do you get an input
// oneLine's hash value.
//The function works by taking a mathematic conversion based on the inputed variables
//(2)What is the number of collisions you expected?
//I expect there to be moderat collisons on the bottom end but when more variables are added is when the hash wont work well
//(3)Did your hash function work well? Using the test cases, what's your hash
//   table's load factor?
//(4)If you had to change your hash function to reduce the number of collisions,
//   how will you change it?
//----
//----
***************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include "Hash.h"

using namespace std;

//This function extracts tokens from oneLine and get all info. of a Product
void getProductInfo(string oneLine, string& productID, string& name, string& supplierID,
                    string& categoryID, string& unit, double& price);

//This function extracts tokens from onLine and get a Product key which is
//the combination of productID, name, supplierID and categoryID
void getKey(string oneLine, string& productID, string& name,
            string& supplierID, string& categoryID);

int main()
{
    //a variable represents the number of hash table slots
    int count;

    //a variable represents the number of commands inside the input file
    int numOfCommand;

    //a variable represents the actual command name inside the input file
    string command;

   string productID, name, supplierID, categoryID, unit;
   double price;
	string delimiter = ",";

	//declare any other necessary variables here
	string oneLine;  

   //get the first line which is a number and store it inside count
	cin >> count;
   cin.ignore(20, '\n');
   //create the hash table with the relevant number of slots
	Hash * hash1 = new Hash(count);

 do {
		getline(cin, oneLine);
		if(oneLine.compare("InsertionEnd") == 0)
         break;
		
      //if command is not InsertionEnd
      //Get one line, call getProductInfo(), then
      //insert the new product inside the hash table
      //----
		else 
		{
		getProductInfo(oneLine, productID, name, supplierID, categoryID, unit, price);
		hash1->hashInsert(productID, name, supplierID, categoryID, unit, price);
		}

	} while(true);

	cin >> numOfCommand;
   cin.ignore(20, '\n');

	for(int i= 0; i < numOfCommand; i++)
   {
 		//get one line from the input file and extract the first token,
 		//if the token is hashDisplay, call the relevant function in Hash.h
		getline(cin, oneLine);
 		if (oneLine.compare("hashDisplay") == 0)
		{
		hash1->hashDisplay();	
		}
 		//if the token is hashSearch, call the relevant function in Hash.h
		getKey(oneLine, productID, name, supplierID, categoryID);
 		if (oneLine.compare("hashSearch") == 0)
                {
                hash1->hashSearch(productID, name, supplierID, categoryID);
                }
 		//if the token is hashDelete, call the relevant function in Hash.h
 		else if (oneLine.compare("hashDelete") == 0)
                {
                hash1->hashDelete(productID, name, supplierID, categoryID);
                }									
     		//for all other cases, show the following message
      		//cout << "Invalid command" << endl;
		else
		{
		cout << "Invalid command" << endl;
		}
   } //end for loop
//hash1->hashDisplay();
	return 0;
} //end main

//*******************************************************************
//This function extract the tokens from one line and
//get all product info.
//*******************************************************************
void getProductInfo(string oneLine, string& productID, string& name, string& supplierID,
                    string& categoryID, string& unit, double& price)
{  string arry[6];
   istringstream ss(oneLine);
   string token;
   int i = 0;
   	while (std::getline(ss, token,',' ))
	{
		arry[i] = arry[i] + token;
		i++;
   	}
	productID = arry[0];
	name = arry[1];
	supplierID = arry[2];
	categoryID = arry[3];
	unit = arry[4];
	price = std::stod(arry[5]); 
   //Note: you can use stod to convert a string into double
   //but you will need c++11 compiler to achieve this
   //for example: price = stod(token);
}

//********************************************************************
//This function extracts the productID, name, supplierID and categoryID
//from a given oneLine. These info. forms the key of a Product.
//********************************************************************
void getKey(string oneLine, string& productID, string& name,
            string& supplierID, string& categoryID)
{  string arry[6];
   istringstream ss(oneLine);
   string token, key;
   int i = 0;

        while (getline(ss, token,',' ))
        {
                arry[i] = arry[i] + token;
		i++;
        }

	oneLine = arry[0];
	productID = arry[1];
        name = arry[2];
        supplierID = arry[3];
        categoryID = arry[4];
}
