// inclusion guards
#ifndef SEARCH_LIB_H
#define SEARCH_LIB_H

// header files
#include <stdio.h>
#include <stdlib.h> // for malloc
#include <ctype.h> // for tolower
#include <stdbool.h> // for bool data type
#include <time.h>

// global constants
#define LENGTH 10
#define NOT_FOUND -1
#define SPECIFIER "%ld"
#define RANGE_MAX 3
#define RANGE_MIN 1
#define EMPTY_VALUE 0

// data type definition
typedef long int dtype;

//declaring treenode
typedef struct TreeNode
{
  // position to store the element
  dtype data;
  // index
  int index;
  // a pointer to the left struct node
  struct TreeNode* left;
  // a pointer to the right struct node
  struct TreeNode* right;  

} Treenode;

//declaring  node
typedef struct node
{
  // position to store the element
  dtype data;
  // a pointer to the next struct node
  struct node* next;
}Node;

//declaring stack
typedef struct stack
{

    int top;
    Node* head;
} Stack;

/**
* @brief Creates an empty Tree
*
* This function initializes and returns an empty Tree.
* time time complexity os O(1)
*param NA


*/
 Treenode* createTree();
 /**
* @brief printing the heap tree
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer root to the treenode
**/
 
 void printTree(Treenode* root);
 /**
* @brief adding the node to tree
*

* The time complexity of this algorithm is <O(1)>
*
* @param  pointer root to the treenode
* @param element
*@param  index
* @... <add as many as needed>
**/

 Treenode* addNode(Treenode* root, dtype element, int index);
  /**
* @brief getting the data from the file
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the filename
**/

 Treenode* getData(const char* filename); 
  /**
* @brief saving the data to the file
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer root to the treenode
* @param pointer to the filename
**/

 void saveData(const char* filename,Treenode* root);
  /**
* @brief getting the first occurence of the element from the tree
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the root of the tree
* @param element
**/

 int getFirstOccurrence(dtype element,Treenode* root);
  /**
* @brief getting the last occurence of the element from the tree
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the  root of the tree
* @param element
**/
 
 
 int getLastOccurrence(dtype element,Treenode* root);
  /**
* @brief helper function for getting the last occurence of the element from the tree
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the root of the tree
* @param element
**/
int getLastOccurrenceHelper(dtype element, Treenode *root);
  /**
* @brief helper function for getting the all occurence of the element from the tree
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the root of the tree
* @param element
* @param poiinter to the occurence 
* @param pointer to number of occurences 

**/
void getAllhelper(dtype element, Treenode *root, dtype *occurrences, dtype *numOccurrences);
 /**
* @brief function for getting the all occurence of the element from the tree
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the root of the tree
* @param element
* @param poiinter to the occurence 
* @param pointer to number of occurences 

**/

void getAllOccurrences(dtype element, Treenode *root, dtype *occurrences, dtype *numOccurrences);
 /**
* @brief to validatre the tree
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the root of the tree



**/

 bool validateTree(Treenode* root);
  /**
* @brief  function to get the user input y or n
*

* The time complexity of this algorithm is <O(1)>
*
* @param NA

**/

 char getChoiceYN();
 
  /**
* @brief function for pushing the node to the stack
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the node of the tree
* @param ponter to the stack


**/
 
 
 void push(Stack* stack, Treenode* node);
 
  /**
* @brief function for popping the node from the stack
*

* The time complexity of this algorithm is <O(1)>
*
* @param pointer to the node of the tree
* @param ponter to the stack


**/

 Treenode* pop(Stack* stack);
// end SEARCH_LIB
#endif
