//************************************************************************
// ASU CSE310 Assignment #6
// ASU ID: 1217664240
// Name: Jeffrey Ciferno
// Description: This class defines a directed graph
//********************************************************************

#include "CityList.h"

using namespace std;

class Graph
{
   private:
   int numOfNode;   //number of nodes in the graph
   int time;   //a global timer used to find each node dTime,fTime
   CityList* adjacentList; //a linked list of LinkedList

   public:
   Graph(int numOfNode, CityList* adjacentList);
   void destructor();

   void printGraph();
   void DFS();
   void DFS_Visit(Node *node);
   void printDFSResult();
};

//***************************************************************
//Constructor
Graph::Graph(int numOfNode, CityList* adjacentList)
{
   this->adjacentList = adjacentList;
   this->numOfNode = numOfNode;
   this->time = 0;
}

//*******************************************************************
//Destructor. We explicitly defines it as a function, in order to be
//able to call it from other functions, to make sure memory is released.
void Graph::destructor()
{
   delete(this->adjacentList);
}

//*******************************************************************
//This function prints the graph. The graph is represented by adjacency
//list. It will print the adjacency list.
void Graph::printGraph()
{
   this->adjacentList->CityListDisplay();
}

//*******************************************************************
//This function performs the DFS on the graph. Note: the DFS starts
//from the first node in adjacency list
void Graph::DFS() //Book puesdocode
{
  struct Node* adjNode = this->adjacentList->getHead();

  while(adjNode != NULL)
  {
  adjNode->pi = "NULL";
  adjNode->color = "WHITE";
  adjNode = adjNode->next;
  }
  
  this->time = 0;
  adjNode = adjacentList->getHead(); //resets adjNode to the head of adjacentList
  while(adjNode != NULL)
  {

    if(adjNode->color == "WHITE")
    {
    DFS_Visit(adjNode);
    }

  adjNode = adjNode->next;
  }

}

//*******************************************************************
//This function performs the DFS-Visit from the parameterized node
void Graph::DFS_Visit(Node* node) //Book puesdocode
{
  this->time = time + 1;
  node->dTime = time;
  node->color = "GREY";

  struct Node* temp;
  struct ArrCity* adjNode;
  adjNode = node->arrCityList->getHead();

  while(adjNode != NULL)
  {
	   temp = adjacentList->CityListSearch(adjNode->arrCity);
	   if(temp->color == "WHITE")
	   {
	   temp->pi = node->depCity;
	   DFS_Visit(temp);
	   }	
  	   adjNode = adjNode->next;
  }
  node->color = "BLACK";
  time = time + 1;
  node->fTime = time;
}

//**************************************************************
//This function prints the parent, dTime & fTime info. of
//each node after DFS. Check our solution output.
void Graph::printDFSResult()
{ struct Node* temp = this->adjacentList->getHead(); //instance of node temp equals adjacentList
   cout << left;
   cout << setw(15) << "City Name" << setw(10) << "Parent"
   << setw(10) << "dTime" << setw(10) << "fTime" << endl;

   cout << setw(15) << "=========" << setw(10) << "======"
   << setw(10) <<"=====" <<setw(10) << "=====" << endl;
   while(temp != NULL)
   {
   cout << setw(15) << temp->depCity << setw(10); 
   if(temp->pi == "NULL")
   {
   cout << "none";
   }
   else
   {
   cout << temp->pi;
   }
   cout << setw(10) <<temp->dTime <<setw(10) << temp->fTime << endl;
   temp = temp->next;
   }
}
