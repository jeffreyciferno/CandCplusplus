//************************************************************************
// ASU CSE310 Assignment #6
// ASU ID:1217664240
// Name: Jeffrey Ciferno
// Description: this is the main program that reads input from keyboard,
// it then build the adjacency list and performs the depth first search
// on the graph.
//**************************************************************************

#include "Graph.h"

using namespace std;

void getCityInfo(string oneLine, string& depCityName, LinkedList* arrCityList);
void getArrCityInfo(string oneArrCityInfo, string& arrCityName, double& price);

int main()
{
   int count;       //a variable for number of nodes
   string oneLine;
   cin >> count;
   cin.ignore(20, '\n');

   //For each line of the input file, you will need to create a LinkedList
   //for a specific departure city, it represents all its reachable arrival
   //cities info. Use an array of LinkedList to store them
   LinkedList** arrCityListArray = new LinkedList*[count];

   //For each individual LinkedList, you need to initialize it before using it
    for(int i = 0; i < count; i++)
   {
   arrCityListArray[i] = new LinkedList();
   }

   //A string array used to store all the departure city names
   string depCityArray[count];

   //Create a CityList object
   CityList* newCityList = new CityList();

   //Use a loop to get input line by line, then create a node
   //and add it inside above CityList object
   for(int i = 0; i < count; i++)
   {
      getline(cin, oneLine);
      
      LinkedList* arrTemp = new LinkedList();      

      //parse oneLine by calling getCityInfo()
      getCityInfo(oneLine, depCityArray[i], arrTemp);

      //add the node inside CityList object
      newCityList->CityListInsert(depCityArray[i], arrTemp);

    }

   //create a Graph object by using its constructor
   Graph* G = new Graph(count, newCityList);

   //print the graph's adjacent list
   cout <<"Adjacency List\n" << endl;
   
   G->printGraph();

   //Do depth first search on above graph
   
   G->DFS();

   //print the depth first search result
   cout << "\nDepth First Search Result\n" << endl;
   
   G->printDFSResult();
}

//****************************************************************
//This function from one line, extracts the departure city info.,
//it also extracts each arrival cities info., it them updates the
//parameterized arrCityList accordingly
void getCityInfo(string oneLine, string& depCityName, LinkedList* arrCityList)
{
   string delimiter = ",";
   int pos= 0;
   pos = oneLine.find(delimiter);
   string token = oneLine.substr(0,pos);
   depCityName = token;
   oneLine.erase(0, pos+delimiter.length());

   string oneArrCityInfo, cityName;
   double price;

   //continue run as long as not reach
   //to the end of the line
   while(oneLine.find(delimiter) != -1)
   {
   if (oneLine != ",")
   {
   pos = oneLine.find(delimiter);
   oneArrCityInfo = oneLine.substr(0,pos);
   getArrCityInfo(oneArrCityInfo, cityName, price);
   arrCityList->addArrCity(cityName, price);
   oneLine.erase(0, pos+delimiter.length());
   }
   else
   {
    return;
   }
   }
}

//****************************************************************
//By giving a string, for example 'Dallas(456.5)', this function
//extract the arrival city name 'Dallas' and air ticket price '456.5'
//Note: the delimeter is left or right parenthesis
void getArrCityInfo(string oneArrCityInfo, string& arrCityName, double& price)
{
   string delimiter1 = "(", delimiter2 = ")";
   int pos = 0;
   
   pos = oneArrCityInfo.find(delimiter1);
   arrCityName = oneArrCityInfo.substr(0, pos);
   oneArrCityInfo.erase(0, pos+delimiter1.length());

   pos = oneArrCityInfo.find(delimiter2);
   string token2 = oneArrCityInfo.substr(0, pos);
   price = stod(token2);
}

