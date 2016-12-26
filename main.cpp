#include <iostream>
#include "hashtable.h"

using namespace std;

int main(int argc, char * argv[])
{
	Hash_Table myHT;

	node * Node_A = new node;
	Node_A -> key = "Thierry Henry";

	node * Node_B = new node;
	Node_B -> key = "Lionel Messi";

	node * Node_C = new node;
	Node_C -> key = "Cristiano Ronaldo";

	node * Node_D = new node;
	Node_D -> key = "Mesut Ozil";

	node * Node_E = new node;
	Node_E -> key = "Santi Cazorla";

    node * Node_F = new node;
	Node_F -> key = "Zlatan Ibrahimovic";

	node * Node_G = new node;
	Node_G -> key = "Thomas Muller";

    node * Node_H = new node;
	Node_H -> key = "Mario Goetze";


/*****************************************************************************
  * Add players to the hash table  
  * Print out the contents of the table
*****************************************************************************/
	myHT.insert_node(Node_A);
	myHT.insert_node(Node_B);
	myHT.insert_node(Node_C);
	myHT.insert_node(Node_D);
	myHT.insert_node(Node_E);
	myHT.insert_node(Node_F);
	myHT.insert_node(Node_G);
	myHT.insert_node(Node_H);


	std::cout << "\n\n<--------Contents of the hash table-------->" << std::endl;
	myHT.get_node("Thierry Henry");
	myHT.get_node("Lionel Messi");
	myHT.get_node("Cristiano Ronaldo");
	myHT.get_node("Mesut Ozil");
	myHT.get_node("Santi Cazorla");
	myHT.get_node("Zlatan Ibrahimovic");
	myHT.get_node("Thomas Muller");
	myHT.get_node("Mario Goetze");


/*****************************************************************************
  * Removes players from the hash table  
  * Print out the contents of the table
*****************************************************************************/
	myHT.remove_node("Thierry Henry"); //Removes this player
	myHT.remove_node("Zlatan Ibrahimovic"); //Removes this player


	std::cout << "\n\n\n\n<--------After removing-------->" << std::endl;
	myHT.get_node("Thierry Henry");
	myHT.get_node("Lionel Messi");
	myHT.get_node("Cristiano Ronaldo");
	myHT.get_node("Mesut Ozil");
	myHT.get_node("Santi Cazorla");
	myHT.get_node("Zlatan Ibrahimovic");
	myHT.get_node("Thomas Muller");
	myHT.get_node("Mario Goetze");


	return 0;
}