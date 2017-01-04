#include "event.h"
#include "concessions.h"

#ifndef __CART_H_INCLUDED__
#define __CART_H_INCLUDED__

using namespace std;

class cart
{
public:
	void addEventItem(event* ticket, int numTickets);
	void removeEventItem(event* ticket, int numTickets, int x, int amountRemove);
	void addConcesItem(concessions* item, int numItems, int size);
	void removeConcesItem(concessions* item, int numTickets, int x, int amountRemove);
    void listCart();
    void cleanCart();
	void checkOut();

    //Arrays for objects
    event* eventList[100];
    concessions* concesList[100];

    //Array for how many items 
    int numItemsE[100]; 
    int numItemsC[100];

    //array for size of concessions
    int concesSize[100];

private:
    //Is the length of the object arrays for events and concessions
    static int objectSizeE;
    static int objectSizeC;
    
};
#endif