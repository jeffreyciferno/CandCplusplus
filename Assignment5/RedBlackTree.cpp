//************************************************************************
// ASU CSE310 Assignment #5
// Name of Author: Jeffrey ciferno
// ASU ID:1217664240
// Description: Red black tree implementation. See RedBlackTree.h
//              for the tree definition. You need to add your own
//              code at //---- position
//************************************************************************

#include "RedBlackTree.h"

using namespace std;

//*******************************************************************
//constructor
RedBlackTree::RedBlackTree()
{
	root = NULL;
}

//*******************************************************************
//destructor
RedBlackTree::~RedBlackTree()
{
	int nodeSize = deleteNode(root);
	cout << "The number of nodes deleted: " << nodeSize << endl;
}

//*******************************************************************
//delete the sub-tree rooted at 'node' and return number of nodes deleted
//This can be defined as a recursive function
int RedBlackTree::deleteNode(Node *node)
{int count = 0;	
    if(node == NULL)
    	return 0;
    if(node->leftChild != NULL)
	{
	deleteNode(node->leftChild);
	count++;
	}
    if(node->rightChild != NULL)
	{
	deleteNode(node->rightChild);
	count++;
	}
delete node;
count++;

return count;
}

//****************************************************************
//This is the general BST insertion operation.
//It does not care about the color of the newly added node.
void RedBlackTree::insertNode(Node *node)
{Node *temp = root;
 Node *current = NULL;
string key1 = node->productID + node->name + node->supplierID + node->categoryID;

	 while(temp != NULL)
                {
                        current = temp;
                if(compareNodes(temp,key1) > 0)
                {
                 temp= temp->leftChild;
                }
                else
                {
                 temp = temp->rightChild;
                }

		}
	if(current == NULL)
	{	root = node;
	}
	else
	{
		if(compareNodes(current,key1) > 0)
		{
		 current->leftChild = node;
			node->color= "RED";
		}
		else
		{
		 current->rightChild = node;
			node->color= "RED";
		}
		
	}




	//At the end, need to call fixup() in case the newly
	//added node's parent is also RED
	fixUp(node);
}

//*******************************************************************
//At beginning, each newly added node will always be red,
//this may violate the red-black tree property #4. fixUp()
//function will restore the property.
void RedBlackTree::fixUp(Node *z)
{/*
    if(z == root)
    {
		z->color = "BLACK";
		return;
	 }
     if(z->parent->color != "BLACK" && z != root)
	{
   	Node *uncle = NULL;
	
	if(z->parent->parent->rightChild)
	{
	uncle = z->parent->parent->leftChild;
	}
	else
	{
	uncle = z->parent->parent->rightChild;
	}
	
if (uncle->color == "RED")
{
z->parent->color = "BLACK";
uncle->color = "BLACK";
z->parent->parent->color = "RED";
//z= z->parent->parent;
}
}*/ 
	 //if z's color is 'RED' and its parent's color is also 'RED'
    while(z->color.compare("RED") == 0 &&
          z->parent != NULL &&
          z->parent->color.compare("RED") == 0)
    {
      z->parent->color = "BLACK"; 

    }//end while
    //make sure the root is always 'BLACK'
    this->root->color = "BLACK";
}

//*****************************************************
//This function print the pre-order traversal of the
//subtree rooted at 'node'.It's a recursive function
void RedBlackTree::preOrderTraversal(Node *node)
{
	if(node == NULL)
   {
		return;
	}
   if (node != NULL)
   {   
	print(node);
	preOrderTraversal(node->leftChild);
	preOrderTraversal(node->rightChild);

	}
}

//**************************************************
//This function print the in-order traversal of the
//subtree rooted at 'node'.It's a recursive function
void RedBlackTree::inorderTraversal(Node *node)
{
        if(node == NULL)
        {
		return;
	}
   else
   {	
        inorderTraversal(node->leftChild);
//	print(node->leftChild);
//      inorderTraversal(node);
	print(node);
        inorderTraversal(node->rightChild);
//	print(node->rightChild);

	}
}

//**************************************************
//This function print the post-order traversal of the
//subtree rooted at 'node'.It's a recursive function
void RedBlackTree::postOrderTraversal(Node *node)
{ 
   if(node == NULL)
   {
		return;
	}
	else
   {
        postOrderTraversal(node->leftChild);
//	print(node->leftChild);
        postOrderTraversal(node->rightChild);
//	print(node->rightChild);
	print(node);
	}
}

//**************************************************************
//This function returns a pointer points to the minimum node from
//the current sub-tree rooted at 'node'. It's a recursive function
Node* RedBlackTree::findMinimumNode(Node *node)
{	Node *current = node;
	if (node == NULL)
   {
		cout << "Tree is empty, no MINIMUM." << endl;
		return node;
	}
    else
    {
    	 while(current->leftChild != NULL)
        {
        current = current->leftChild;
        }
        return current;
	 }
}

//**************************************************************
//This function returns a pointer points to the maximum node from
//the current sub-tree rooted at 'node'. It's a recursive function
Node* RedBlackTree::findMaximumNode(Node *node)
{	
	Node *current = node;
	if (node == NULL)
   {
		cout << "Tree is empty, no MAXIMUM." << endl;
		return node;
	}
   else
   {
      	while(current->rightChild != NULL)
	{
	current = current->rightChild;
	}
	return current;
   }
}

//**************************************************************
//This function search the tree for a given key of a Product
//Note: key is the combination of productID, name, supplierID

//and categoryID. It returns a pointer points to the node if founded
//otherwise return NULL
Node* RedBlackTree::treeSearch(string productID, string name, string supplierID, string categoryID)
{
   string key1 = productID + name + supplierID + categoryID;
	Node *node = root;
	int i;
	while(node != NULL)
    {
		i = compareNodes(node,key1);
		//-----
		if(i >= 0)
		{
	         cout << left;
	         cout << setw(5) << productID
            << setw(35) << name
            << setw(15) << supplierID
            << setw(15) << categoryID
            << " is FOUND." << endl;
            return node;
		}
      else
      {
         cout << left;
         cout << setw(5) << productID
              << setw(35) << name
              << setw(15) << supplierID
              << setw(15) << categoryID
              << " is NOT FOUND." << endl;
         return NULL;
      }
    }
}

//****************************************************
//This function left-rotate the BST at 'node'
void RedBlackTree::leftRotate(Node *node)
{
	if(node == NULL)
		return;

}

//***************************************************
//This function right-rotate the BST at 'node'
void RedBlackTree::rightRotate(Node *node)
{
	if(node == NULL)
		return;
	//add your codes here
   //----
	//----
}


//**************************************************************
//This function finds the predecessor of the given 'node'
//it prints the relevant predecessor info. on screen.
Node* RedBlackTree::findPredecessorNode(Node *node)
{
   Node* predn;
if(node == NULL)
{
return NULL;
}
        if(node->leftChild != NULL)
        {
        predn = findMaximumNode(node->leftChild);
        return predn;
        }

      cout << left;
      cout << "Its Predeccessor is: " << endl;
                print(predn);
                return predn;


        while(node->parent != NULL && node->parent->leftChild == node) //parent of node with no right subtree
        {
         node = node->parent;
        return node->parent;
        }
      cout << left;
      cout << "Its Predeccessor does NOT EXIST"    << endl;
      return predn;
        }


//**************************************************************
//This function finds the successor of the given 'node'
//it prints the relevant successor info. on screen.
Node* RedBlackTree::findSuccessorNode(Node *node)
{
   Node* sn;
	if(node == NULL)
{
return NULL;
}
	if(node->rightChild != NULL)
	{
 	sn = findMinimumNode(node->rightChild);
	return sn;
	}
   
      cout << left;
      cout << "Its Successor is: " << endl;
		print(sn);
		return sn;
  
    
 	while(node->parent != NULL && node->parent->rightChild == node) //parent of node with no left subtree
	{
	 node = node->parent;
	return node->parent;
	}
      cout << left;
      cout << "Its Successor does NOT EXIST"	<< endl;
      return sn;
	}


//**************************************************************
//This function find the minimum node of the entire red-black tree
//It print out the minimum node info. on screen if tree is not empty
//or print 'Tree is empty' message on screen.
void RedBlackTree::treeMinimum()
{
	if (root == NULL)
   {
		cout << "Tree is empty. No Minimum." << endl;
		return;
	}

	return print(findMinimumNode(root));
	
}

//**************************************************************
//This function find the maximum node of the entire red-black tree
//It print out the maximum node info. on screen if tree is not empty
//or print 'Tree is empty' message on screen.
void RedBlackTree::treeMaximum()
{
	if (root == NULL)
    {
		cout << "Tree is empty. No Maximum." << endl;
		return;
	}

	return print(findMaximumNode(root));
	
}

//******************************************************************
//This function print out the pre-order traversal of the entire tree
void RedBlackTree::preorder()
{
	preOrderTraversal(root);
}

//******************************************************************
//This function print out the in-order traversal of the entire tree
void RedBlackTree::inorder()
{
	inorderTraversal(root);
}

//******************************************************************
//This function print out the post-order traversal of the entire tree
void RedBlackTree::postorder()
{
	postOrderTraversal(root);

}

//******************************************************************
//Given a product's key, this function first check whether the
//product is inside the tree or not, if it is inside, it will print
//its predecessor info. on screen, if not, it print an error message
void RedBlackTree::treePredecessor(string productID, string name,
                                   string supplierID,string categoryID)
{	Node* current;
	if (root == NULL)
		cout << "Tree is empty. No Predecessor." << endl;
	else
   	{ current = treeSearch(productID, name, supplierID,categoryID);
          print(findPredecessorNode(current));
	  
	}
}

//******************************************************************
//Given a product's key, this function first check whether the
//product is inside the tree or not, if it is inside, it will print
//its successor info. on screen, if not, it print an error message
void RedBlackTree::treeSucessor(string productID, string name,
                                string supplierID, string categoryID)
{	Node* current;
	if (root == NULL)
		cout << "Tree is empty. No Successor." << endl;
	else
   	{ current = treeSearch(productID, name, supplierID, categoryID);
	  print(findSuccessorNode(current));
	}
}

//**************************************************************
//This function create a node from the given info., then insert
//the node inside the red-black tree. Note: at beginning, the newly
//added node should always be 'RED'
void RedBlackTree::treeInsert(string productID, string name, string supplierID,
                              string categoryID, string unit, double price)
{
struct Node *newNode = new Node();
newNode->productID = productID;
newNode->name = name;
newNode->supplierID = supplierID;
newNode->categoryID = categoryID;
newNode->unit = unit;
newNode->price = price;
	insertNode(newNode);
}

//******************************************************************
//Given a 'node', this function prints all its information on screen
void RedBlackTree::print(Node *node)
{
      cout << left;
		cout	<< setw(5) << node->productID
            << setw(35) << node->name
            << setw(15) << node->supplierID
            << setw(15) << node->categoryID
            << setw(25) << node->unit
            << setw(7) << node->price
            << setw(7) << node->color << endl;
}

//**************************************************************
//Given a Node 'node1', this function compares it with another
//node's key.
//key is a string combination of productID + name + supplierID + categoryID

//It returns a negative number if in alphabetical order, key2 is
//in front of 'node1'; otherwise it returns a positive number
int RedBlackTree::compareNodes(Node *node1, string key2)
{
	string key1 = node1->productID + node1->name + node1->supplierID +node1->categoryID;
	 return key1.compare(key2);
}

//**************************************************************
//This function return the root of the red-black tree
Node* RedBlackTree::getRoot()
{
	return this->root;
}
