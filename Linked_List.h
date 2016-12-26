#include <iostream>


/*****************************************************************************
  * Structure of the nodes that are to be inserted in the list
 *****************************************************************************/
struct node
{
	std::string key;
	node * next_item;
};

class Linked_List
{
	private:
		int ListLength; //Length of the list
		node * root; //First (root) node in the list
		node * desired_location; //Node at the desired location (Desired location : Where new node is to be inserted)
		node * before_desired_location; // Node before the desired location
		node * node_to_display; //Node whose data is to be printed out


	public:
		node * current_node; //Position of the node at the end of the list

/*****************************************************************************
  * Constructor
 *****************************************************************************/
		Linked_List();


/*****************************************************************************
  * Destructor
 *****************************************************************************/
		~Linked_List();


/*****************************************************************************
  * Function inserts a new node in the list at the requested location
 *****************************************************************************/
		bool insert_node(node * NewNode, int position);


/*****************************************************************************
  * Function prints out the contents of the specified node
 *****************************************************************************/		
		bool printout(std::string key);


/*****************************************************************************
  * Function removes the specified node from the linked list
 *****************************************************************************/		
		bool remove_node(std::string key);


/*****************************************************************************
  * Function returns length of the list
 *****************************************************************************/		
		int get_length();
};