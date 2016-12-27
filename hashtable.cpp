#include "hashtable.h"

/****************************************************************************
* Overload Constructor
*****************************************************************************
*
* Overload Constructor
* 
*
****************************************************************************/
Hash_Table::Hash_Table()
{
	array = new Linked_List [10];
	length = 10;
}


Hash_Table::Hash_Table(int array_length)
{
	array = new Linked_List [array_length];
	length = array_length;
}


/****************************************************************************
* Function: insert_node(node * NewNode)
*****************************************************************************
*
* Calculates array index and inserts a new node in the indexed list
* 
*
****************************************************************************/
bool Hash_Table::insert_node(node * NewNode)
{
	std::string key = NewNode -> key;
	int hash = 0;
	for (unsigned int i =0; i < key.length(); ++i)
	{
		hash += key[i];
	}
	int index = hash % length;
	array[index].insert_node(NewNode, array[index].get_length()+1);
	std::cout << key << " added to Array[" << index <<"]" << std::endl;
	return(true);
}


/****************************************************************************
* Function: remove_node(std::string key)
*****************************************************************************
*
* Removes a node from the table
* 
*
****************************************************************************/
bool Hash_Table::remove_node(std::string key)
{
	int hash = 0;
	for (unsigned int i =0; i < key.length(); ++i)
	{
		hash += key[i];
	}
	int index = hash % length;
	if(array[index].remove_node(key))
	{
		return(true);
	}
	else
	{
		std::cout << "Node not found in the table!!!" << std::endl;
		return(false);
	}
}


/****************************************************************************
* Function: get_node(std::string key)
*****************************************************************************
*
* Prints out the contents of the node corresponding to the specified key
* 
*
****************************************************************************/
bool Hash_Table::get_node(std::string key)
{
	int hash = 0;
	for (unsigned int i =0; i < key.length(); ++i)
	{
		hash += key[i];
	}
	int index = hash % length;
	if(array[index].printout(key))
	{
		return(true);
	}
	else
	{
		std::cout << "Node not found in the table!!!" << std::endl;
		return(false);
	}
}


/****************************************************************************
* Function: print_table()
*****************************************************************************
*
* Prints out the contents of the complete table
* 
*
****************************************************************************/
void Hash_Table::print_table()
{
	node * current_node;
	for (int i = 0; i < length; ++i)
	{
		std::cout << "\nArray[" << i << "] : "; 
		if (array[i].get_length() > 0)
		{
			current_node = array[i].first_node();
			for (int j = 1; j <= array[i].get_length(); ++j)
			{
				std::cout << current_node -> key << "--";
				current_node = current_node -> next_item;
			}
		}
	}
	std::cout << "\n"; 
}


/****************************************************************************
* Destructor
*****************************************************************************
*
* Destructor
* 
*
****************************************************************************/
Hash_Table::~Hash_Table()
{
	delete [] array;
}