
//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include <stdio.h>
#include <string.h>
#include "slist.h"

using namespace std;


class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    
};



void simpleSortTotal(slist a, int c);


int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    Airport* airportArr[13500];			// Replace array with Linked List
    slist airportList = slist();
    int   airportCount;
    //Airport* a[13500];
    
    char code[3];
    double lon;
    double lat;
    
    infile.open ("./USAirportCodes.csv", ifstream::in);
    //infile.open ("./file4.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
            /*airportArr[c] = new Airport();
            infile.getline(airportArr[c]->code, 256, ',');
            infile.getline(cNum, 256, ',');
            airportArr[c]->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airportArr[c]->latitude = atof(cNum);*/
            
            infile.getline(code, 256, ',');
            infile.getline(cNum, 256, ',');
            lat = atof(cNum);
            infile.getline(cNum, 256, '\n');
            lon = atof(cNum);
            
            //airportList
            airportList.addInOrder(code,lon,lat);
            

           
            /*
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
            }
            */

            
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();
        int count = 0;
         //simpleSortTotal(airportList, airportCount);
         cout<<"airports within 100 miles of AUS:"<<endl;
         for (int c=0; c < airportCount; c++){
            if (airportList.distanceEarth(airportList.get(c)->latitude, airportList.get(c)->longitude, 30.1944,97.6700)/1.609<100/*!(c % 1000)*/)
            {
        
                cout << airportList.toString(c)/*airportList.get(c)->code<<"   "<<distanceEarth(airportList.get(c)->latitude, airportList.get(c)->longitude, 30.1944,97.6700)/1.609<<" miles " <<distanceEarth(airportList.get(c)->latitude, airportList.get(c)->longitude, 30.1944,97.6700)<<" kilometers"*/ << endl;
                count++;
            }

         }
         cout<< "there are "<<count<<" airports within 100 miles of AUS"<<endl;
         cout<<"the farthest airport is "<<airportList.get(airportCount-1)->code<<endl;
         

    }
    else
    {
        cout << "Error opening file";
    }
 


    
}



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


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
 
double slist::distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
	Provide sort routine on linked list
*/

void simpleSortTotal(slist a, int c)
{
    cout<<"start"<<endl;
    Node *cur = a.head;
	  for (int i=0; i < c; i++){
		  for (int j=i; j < c; j++){
		    //cout<<"outside"<<endl;
		    if (distanceEarth(a.get(i)->latitude, a.get(i)->longitude,30.1944, 97.6700) > distanceEarth(a.get(j)->latitude, a.get(j)->longitude,30.1944, 97.6700)){
		      //cout<<"inside"<<endl;
			//swap pointer to record i with pointer to record j;
			    //a.exchg(i,j);
		    }
		  }
	  }
	  cout<<"end"<<endl;
}

