#include <iostream>
#include "Linked_List.h"

class Hash_Table
{
	Linked_List * array;
	int length;

public:

	Hash_Table();

	Hash_Table(int array_length);

	~Hash_Table();


/*****************************************************************************
  * Calculates array index and inserts a new node in the indexed list
 *****************************************************************************/
	bool insert_node(node * NewNode);


/*****************************************************************************
  * Removes node from the right list
 *****************************************************************************/	
	bool remove_node(std::string key);


/*****************************************************************************
  * Prints out the contents of the node corresponding to the specified key
 *****************************************************************************/
	bool get_node(std::string key);


/*****************************************************************************
  * Prints out the contents of the complete table
 *****************************************************************************/
	void print_table();
};