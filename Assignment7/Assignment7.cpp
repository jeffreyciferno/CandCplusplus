//************************************************************************
// ASU CSE310 Assignment #7
// ASU ID:
// Name:
// Description: this is the main program that reads input from keyboard,
// it then use disjoint set data structure to perform Kruskal MST algorithm
// on the graph.
// //---- is where you need to add your own codes
//**************************************************************************

#include "Graph.h"

using namespace std;

void getArrCityInfo(string oneArrCityInfo, string& arrCityName, double& price);
City* searchCity(City* oneCityArray[],int size, string oneCityName);

int main()
{
    int V, E;        //number of vertices and edges

    cin >> V >> E;
    cin.ignore(20, '\n');

    //a City array used to store all vertices (Cities) of the graph
    City* cityArray[V];

    //an array used to store all edges of the graph
    Edge* edgeArray[E];

    //----
    //----

    int i =0, j=0; //index for cityArray and edgeArray

    //local variables
    City* city1;
    City* city2;
    Edge* aNewEdge;

    string oneLine;
    getline(cin, oneLine);
    while(oneLine.compare("End") != 0)
    {
      //get one line of the input, extract the first token
      //create a City if it doesn't exist in cityArray,
      //insert it inside the cityArray; otherwise get a pointer
      //point to the City. This City will be the first point for
      //aNewEdge
      //----
      //----

   if (i <= V || j <= E)
   {
   string delimiter = ",";
   int pos= 0;
   pos = oneLine.find(delimiter);
   string token = oneLine.substr(0,pos);
   city1->cityName = token;
   oneLine.erase(0, pos+delimiter.length());
   cityArray[i] = city1;
   i++;	
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
   city2->cityName = cityName;
   oneLine.erase(0, pos+delimiter.length());

   city1 = aNewEdge->getCity1();
   city2 = aNewEdge->getCity2();
   price = aNewEdge->getPrice();
   edgeArray[j] = aNewEdge;
   j++;
   }
   }


      //extract the arrival city info. check whether it exists in
      //cityArray or not, if not, create a new City, add it inside.
      //This city will be the second point for aNewEdge
      //----
      //----

      //by using the two cities we got above, create a new edge, add
      //it inside edgeArray
      //----
      //----

      //get next line
      getline(cin, oneLine);
    } //repeat until the 'End'

    //Create a Graph object by using cityArray and edgeArray
    Graph* graph = new Graph(V, E, cityArray[V], edgeArray[E]);
    
    //Run Kruskal MST algorithm on above graph
    //----
 }
}

//****************************************************************
//By giving a string, for example 'Dallas(456.5)', this function
//extract the arrival city name 'Dallas' and air ticket price '456.5'
//Note: the delimeter is left or right parenthesis
//****************************************************************
void getArrCityInfo(string oneArrCityInfo, string& arrCityName, double& price)
{
   string delimiter1 = "(", delimiter2 = ")";
   int pos=oneArrCityInfo.find(delimiter1);
   string token = oneArrCityInfo.substr(0,pos);
   arrCityName = token;

   oneArrCityInfo.erase(0, pos+delimiter1.length());

   pos = oneArrCityInfo.find(delimiter2);
   token = oneArrCityInfo.substr(0,pos);
   price = stod(token);
   oneArrCityInfo.erase(0, pos+delimiter2.length());
}

//*********************************************************************
//Given a city name, this function searches cityArray and it return a
//pointer points to the City if it already exists, otherwise it returns NULL
//****************************************************************
City* searchCity(City* oneCityArray[], int arraySize, string oneCityName)
{
   for(int i = 0; i < arraySize; i++)
   {
   	if (oneCityArray[i]->cityName == oneCityName)
	{
	return oneCityArray[i];
	}   
   }
}
