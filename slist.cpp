#include <iostream>
#include <fstream>
#include <cmath> 
#include <stdio.h>
#include <string.h>


using namespace std;
#include "slist.h"

/*
Class Library File
*/

	// Constructor
  slist::slist(){
	  head = NULL;
	  length = 0;
  } 
  // Destructor
  slist::~slist(){
  }
  /*
  #define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}
*/
  
  //Adds a new value to the end of this list.
   void slist::add(char c[], double lon, double lat){				
    length=length +1;
    Node *newNode = new Node;
    strcpy(newNode->code,c);
    newNode->longitude = lon;
    newNode->latitude = lat;
    newNode->next = NULL;
    
    Node *cur = head;
    
	  while(cur) {
		  if(cur->next == NULL) {
			  cur->next = newNode;
			  break;
		  }
		  cur = cur->next;
	  }
	  if (head == NULL) {
      head = newNode;
    }
  }
  
  
  //Removes all elements from this list.
  void slist::clear()  
  {  
    // deref head_ref to get the real head
    Node* current = head;  
    Node* next;  
  
    while (current != NULL)  
    {  
      next = current->next;  
      delete current;  
      current = next;  
    }  
      
    // deref head_ref to affect the real head back  
    //in the caller. 
    head = NULL; 
    length = 0;
  }
  
  //Returns true if the two lists contain the same elements in the same order.
  bool slist::equals( Node * list){  	
    Node* current = head;
    while (current->next != NULL && list->next != NULL) 
    { 
        if (current->code != list->code||current->longitude!=list->longitude||current->latitude!=list->latitude) 
            return false; 
  
        current = current->next; 
        list = list->next; 
    } 
  
    return (current == NULL && list == NULL);
  }
  //Returns the element at the specified index in this list.
  Node* slist::get(int index){	
    Node* current = head;
    for(int i = 0; i<index; i++){
      current = current->next;
    }
    return current;
  }
  //add in order
  void slist::addInOrder(char c[], double lon, double lat){				
    length=length +1;
    Node *newNode = new Node;
    strcpy(newNode->code,c);
    newNode->longitude = lon;
    newNode->latitude = lat;
    newNode->next = NULL;
    
    Node *cur = head;
    
	  while(cur) {
		  if(cur->next!=NULL&&distanceEarth((cur->next)->latitude,(cur->next)->longitude, 30.1944,97.6700 )>distanceEarth(lat,lon,30.1944,97.6700)) {
		    newNode->next = cur->next;
			  cur->next = newNode;
			  break;
		  }
		  else if((cur->next)==NULL){
		    cur->next = newNode;
		    break;
		  }
		  cur = cur->next;
	  }
	  if (head == NULL) {
      head= newNode;
    }
  }
  //Inserts the element into this list before the specified index.
  void slist::insert(int index, char c[], double lon, double lat){
    length = length + 1;
    Node myNode;
    strcpy(myNode.code,c);
    myNode.longitude = lon;
    myNode.latitude = lat;
    
    myNode.next = get(index);
    get(index-1)->next = &myNode;
    
  }
  //Switches the payload data of specified indexex.
  void slist::exchg(int index1, int index2){		
    Node * node1 = get(index1);
    Node * node2 = get(index2);
    char tempCode[5];
    strcpy(tempCode,node1->code);
    double tempLon = node1->longitude;
    double tempLat = node1->latitude;
    
    strcpy(node1->code, node2->code);
    node1->longitude = node2->longitude;
    node1->latitude = node2->latitude;
    
    strcpy(node2->code,tempCode);
    node2->longitude = tempLon;
    node2->latitude = tempLat;
  }
  //Returns true if this list contains no elements.
  bool slist::isEmpty(){	
    if (length == 0){
      return true;
    }
    return false;
 }
  //Removes the element at the specified index from this list.
  void slist::remove(int index){
    struct Node * temp = get(index);
    get(index-1)->next = get(index+1);
    delete temp;
  }
  //Replaces the element at the specified index in this list with a new value.
  void slist::set(int index, char c[], double lon, double lat){
    strcpy(get(index)->code,c);
    get(index)->longitude = lon;
    get(index)->latitude = lat;
  }
  //Returns the number of elements in this list.
  int slist::size(){
    return length;
  }
  
  std::string slist::toString( int a){
    return get(a)->code;
  }

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
 /*
double slist::distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}*/
