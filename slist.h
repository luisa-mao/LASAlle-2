#include <stdio.h>
#include <string.h>
struct Node {
	  char   code[5];
    double   longitude;
    double   latitude;
	  Node* next;
  };
  
class slist{
  public:
  Node *head;
	int length;
	
	// Constructor
  slist();
  // Destructor
  ~slist();
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

 void add(char c[], double lon, double lat);				//Adds a new value to the end of this list.

 void clear();					//Removes all elements from this list.

 bool equals(struct Node * list);				//Returns true if the two lists contain the same elements in the same order.

 Node * get(int index);				//Returns the element at the specified index in this list.
 
 void addInOrder(char c[], double lon, double lat); //add in order

 void insert(int index, char c[], double lon, double lat);		//Inserts the element into this list before the specified index.

void exchg(int index1, int index2);		//Switches the payload data of specified indexex.

//swap(index1,index2)		//Swaps node located at index1 with node at index2

 bool isEmpty();				//Returns true if this list contains no elements.

// mapAll(fn)				//Calls the specified function on each element of the linkedlist in ascending index order.

 void remove(int index);			//Removes the element at the specified index from this list.

 void set(int index, char c[], double lon, double lat);		//Replaces the element at the specified index in this list with a new value.

 int size();					//Returns the number of elements in this list.
 
 

// subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

 std::string toString( int a);				//Converts the list to a printable string representation.
};