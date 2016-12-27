#include "Linked_List.h"


/****************************************************************************
* Function: Linked_List()
*****************************************************************************
*
* Initializes the root node
* 
*
****************************************************************************/
Linked_List::Linked_List() : ListLength(0)
{
	root = new node;
	root -> key = "root";
	root -> next_item = nullptr;
	current_node = root;
}


/****************************************************************************
* Function: insert_node(node * NewNode, int position)
*****************************************************************************
*
* Inserts a new node in the list
* 
*
****************************************************************************/
bool Linked_List::insert_node(node * NewNode, int position)
{
	if(position <= 0 || position > ListLength+1)
	{
		std::cout << "Error: Exceeds length of the list!!!" << std::endl;
		return(false);
	}
/*****************************************************************************
  * If the new node is inserted at the end of the list
 *****************************************************************************/
	if(position == ListLength+1)
	{
		current_node -> next_item = NewNode;
		current_node = NewNode;
		current_node -> next_item = nullptr;
		++ListLength;
	}
/*****************************************************************************
  * If the new node is inserted in the middle of the list
 *****************************************************************************/	
	else if(position != ListLength+1)
	{
		int count = 1;
		desired_location = root->next_item;
		before_desired_location = root;
		while(true)
		{
			if(count == position)
			{
				NewNode -> next_item = desired_location;
				before_desired_location -> next_item = NewNode;
				++ListLength;
				break;
			}
			else
			{
				before_desired_location = desired_location;
				desired_location = desired_location -> next_item;
				++count;
			}
		}

	}

	return(true);
}


/****************************************************************************
* Function: printout(std::string key)
*****************************************************************************
*
* Print out the contents of the selected node
* 
*
****************************************************************************/
bool Linked_List::printout(std::string key)
{
	node_to_display = root -> next_item;
	int count = 1;
	while(count <= ListLength)
	{
		if(node_to_display -> key == key)
		{
			std::cout << node_to_display -> key << std::endl;
			return (true);
		}
		else
		{
			node_to_display = node_to_display -> next_item;
			++count;
		}
	}
	return (false);
}


/****************************************************************************
* Function: remove_node(std::string key)
*****************************************************************************
*
* Removes the specified node from the linked list
* 
*
****************************************************************************/
bool Linked_List::remove_node(std::string key)
{
	int count = 1;
	node * node_to_remove = root -> next_item;
	node * before_node_to_remove = root;
	
	while(count <= ListLength)
	{
		if(node_to_remove -> key == key)
		{
			before_node_to_remove -> next_item = node_to_remove -> next_item;
			delete node_to_remove;
			if (count == ListLength)
			{
				current_node = before_node_to_remove;
			}
			--ListLength;
			return(true); 
		}
		else
		{
			before_node_to_remove = node_to_remove;
			node_to_remove = node_to_remove -> next_item;
			++count;
		}
	}
	return(false);
}


/****************************************************************************
* Function: get_length()
*****************************************************************************
*
* Function returns length of the list
* 
*
****************************************************************************/
int Linked_List::get_length()
{
	return (ListLength);
}


/****************************************************************************
* Function: first_node()
*****************************************************************************
*
* Function returns pointer to the first node in the list
* 
*
****************************************************************************/
node * Linked_List::first_node()
{
	return(root -> next_item);
}


Linked_List::~Linked_List()
{
	node * next = root -> next_item;
	node * current = root;
	for (int i = 0; i < ListLength; ++i)
	{
		delete current;
		current = next;
		next = next -> next_item;
	}
	delete current;
}
