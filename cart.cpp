#include <iostream>
#include "cart.h"


int cart::objectSizeE = 0;

int cart::objectSizeC = 0;

//Add event items to a specific point on an array
//*********************************************************************************************************************************************
void cart::addEventItem(event* ticket, int numTickets)
{
    if (ticket->getSeats() >= numTickets)
    {
        eventList[objectSizeE] = ticket;
        numItemsE[objectSizeE] = numTickets;
        ticket->setOpenSeats(ticket->getSeats() - numTickets);
        cout << "x" << numTickets << " tickets for ";
        ticket->printName();
        cout << " added to cart." << endl << endl;
        objectSizeE++;
    }

    else if (ticket->getSeats() == 0)
    {
        cout << "Unfortunately, all seats for that show are sold out. (sad face) :( " << endl << endl;
    }

    else if (ticket->getSeats() < numTickets)
    {
        int userChoice = 0;
        cout << "Unfortunately there are only " << ticket->getSeats() << " seats left, would you like to add this amount to your cart instead?" << endl;
        cout << "Options:" << endl;
        cout << "1. Yes." << endl;
        cout << "2. No." << endl;
        cin >> userChoice;
        cout << endl;
        if (userChoice == 1)
        {
            eventList[objectSizeE] = ticket;
            numItemsE[objectSizeE] = ticket->getSeats();
            numTickets = ticket->getSeats();
            ticket->setOpenSeats(0);
            cout << "x" << numTickets << " tickets for ";
            ticket->printName();
            cout << " added to cart." << endl << endl;
            objectSizeE++;
        }
    }

}
//removes items from list, properly removes the amount currently in the cart, but not for the stock of the event object that holds it
//*****************************************************************************************************************************************
void cart::removeEventItem(event* ticket, int numTickets, int x, int amountRemove)
{
    if (amountRemove > numTickets)
    {
        cout << "Amount to remove, is greater than the ammount in your cart, please enter a valid ammount." << endl;
    }
    //x - 1 representss the location proper in the array
    else if (amountRemove < numTickets)
    {
        numItemsE[x - 1] = numTickets - amountRemove;
        ticket->setOpenSeats(ticket->getSeats() + amountRemove);
    }
    else if (amountRemove == numTickets)
    {
        for (int g = x; g < objectSizeE; g++)
        {
            //replaces the object in the array with the one in front of it
            //Possibly can be deleted if I use a vector
            eventList[g - 1] = eventList[g];
            numItemsE[g - 1] = numItemsE[g];
            eventList[g] = eventList[g + 1];
            numItemsE[g] = numItemsE[g + 1];
        }
        ticket->setOpenSeats(ticket->getSeats() + amountRemove);
        objectSizeE--;
    }
   
}

// adds the concession item to an array, this one works properly as far as I know
void cart::addConcesItem(concessions* item, int numItems, int size)
{
    item->setSnackSize(size);

        //First determines the size of the concession item, then decreases the stock of that size 
        
            if (size == 1 && item->getSnackStockS() > 0 && item->getSnackStockS() >= numItems)
            {
                //Small

                concesList[objectSizeC] = item;
                numItemsC[objectSizeC] = numItems;
                concesSize[objectSizeC] = size;
                item->setSnackStockS(item->getSnackStockS() - numItems);
                cout << "x" << numItems << " units of Small";
                item->printName();
                cout << " added to cart." << endl << endl;

                objectSizeC++;
            }

            else if (size == 2 && item->getSnackStockM() > 0 && item->getSnackStockM() >= numItems)
            {
                //Medium

                concesList[objectSizeC] = item;
                numItemsC[objectSizeC] = numItems;
                concesSize[objectSizeC] = size;
                item->setSnackStockM(item->getSnackStockM() - numItems);
                cout << "x" << numItems << " units of Medium";
                item->printName();
                cout << " added to cart." << endl << endl;
                objectSizeC++;
            }

            else if (size == 3 && item->getSnackStockL() > 0 && item->getSnackStockL() >= numItems)
            {
                //large

                concesList[objectSizeC] = item;
                numItemsC[objectSizeC] = numItems;
                concesSize[objectSizeC] = size;
                item->setSnackStockL(item->getSnackStockL() - numItems);
                cout << "x" << numItems << " units of Large";
                item->printName();
                cout << " added to cart." << endl << endl;
                objectSizeC++;
            }
           
        //If the amount desired is greater than the stock for the particular size
            else if (size == 1 && item->getSnackStockS() > 0 && item->getSnackStockS() < numItems)
            {
                int choice;
                cout << "Unfortunately, there are only ";
                cout << item->getSnackStockS();
                cout << " left in stock." << endl;
                cout << "Would you like to add that amount to your cart instead?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    // small
                    concesList[objectSizeC] = item;
                    numItemsC[objectSizeC] = item->getSnackStockS();
                    concesSize[objectSizeC] = size;
                    cout << "x" << item->getSnackStockS() << " units of Small";
                    item->printName();
                    cout << " added to cart." << endl << endl;
                    item->setSnackStockS(0);
                    objectSizeC++;
                }
            }

            else if (size == 2 && item->getSnackStockM() > 0 && item->getSnackStockM() < numItems)
            {
                int choice;
                cout << "Unfortunately, there are only ";
                cout << item->getSnackStockM();
                cout << " left in stock." << endl;
                cout << "Would you like to add that amount to your cart instead?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    // medium
                    concesList[objectSizeC] = item;
                    numItemsC[objectSizeC] = item->getSnackStockM();
                    concesSize[objectSizeC] = size;
                    cout << "x" << item->getSnackStockM() << " units of Medium";
                    item->printName();
                    cout << " added to cart." << endl << endl;
                    item->setSnackStockM(0);
                    objectSizeC++;
                }
            }
            else if (size == 3 && item->getSnackStockL() > 0 && item->getSnackStockL() < numItems)
            {
                int choice;
                cout << "Unfortunately, there are only ";
                cout << item->getSnackStockL();
                cout << " left in stock." << endl;
                cout << "Would you like to add that amount to your cart instead?" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    // large
                    concesList[objectSizeC] = item;
                    numItemsC[objectSizeC] = item->getSnackStockL();
                    concesSize[objectSizeC] = size;
                    cout << "x" << item->getSnackStockL() << " units of Large";
                    item->printName();
                    cout << " added to cart." << endl << endl;
                    item->setSnackStockL(0);
                    objectSizeC++;
                }
            }
            //If the amount of stock is equal to zero
            else 
            {
                cout << "Unfortunately, that item of that size is out of stock" << endl << endl;
            }
}

//The same goes for this one, as far as know it properly removes item from the array, and cart
void cart::removeConcesItem(concessions* item, int numItems, int x, int amountRemove)
{
    if (amountRemove > numItems)
    {
        cout << "Amount to remove is greater than the amount in your cart, please enter a valid ammount." << endl;
    }
    //x - 1 reps the location proper in the array
    //if amount to remove is less than the items in the cart
    else if (amountRemove < numItems)
    {
        //sets stock appropriate to size
        if (item->getSnackSize() == 1)
        {
            //small
            numItemsC[x - 1] = numItems - amountRemove;
            item->setSnackStockS(item->getSnackStockS() + amountRemove);
        }
        else if (item->getSnackSize() == 2)
        {
            //medium
            numItemsC[x - 1] = numItems - amountRemove;
            item->setSnackStockM(item->getSnackStockM() + amountRemove);
        }
        else if (item->getSnackSize() == 3)
        {
            //large
            numItemsC[x - 1] = numItems - amountRemove;
            item->setSnackStockL(item->getSnackStockL() + amountRemove);
        }
    }
    //if items in cart is equal to the amount removed
    else if (amountRemove == numItems)
    {
        
        for (int g = x; g < objectSizeC; g++)
        {
           //replaces the object in the array with the one in front of it
           //Possibly can be deleted if I use a vector
            concesList[g - 1] = concesList[g];
            numItemsC[g - 1] = numItemsC[g];
            concesSize[g - 1] = concesSize[g];
            concesList[g] = concesList[g + 1];
            numItemsC[g] = numItemsC[g + 1];
            concesSize[g] = concesSize[g + 1];
        }
        if (item->getSnackSize() == 1)
        {
            //small
            item->setSnackStockS(item->getSnackStockS() + amountRemove);
        }
        else if (item->getSnackSize() == 2)
        {
            //medium
            item->setSnackStockM(item->getSnackStockM() + amountRemove);
        }
        else if (item->getSnackSize() == 3)
        {
            //large
            item->setSnackStockL(item->getSnackStockL() + amountRemove);
        }
        objectSizeC--;
    }
}

//displays the cart and the items in it, didn't implement a system to add two objects of the same size or name together
void cart::listCart()
{
    int choice = 0;
    do
    {
        //Lists the objects in the eventList array 
        int choice;
        if (objectSizeE > 0)
        {
            cout << "*******Events*******" << endl;

            for (int g = 0; g < objectSizeE; g++)
            {
                if (numItemsE[g] > 0)
                {
                    eventList[g]->printName();
                    cout << endl;
                    cout << "Price per unit:     $" << eventList[g]->getPrice() << endl;
                    cout << "Number of units:     x" << numItemsE[g] << endl;
                }
            }
        }
        //Lists the objects in the concesList array
        if (objectSizeC > 0)
        {
            cout << "*******Concession Items*******" << endl;

            for (int g = 0; g < objectSizeC; g++)
            {
                if (numItemsC[g] > 0)
                {
                    if (concesSize[g] == 1)
                    {
                        //small
                        cout << "Small"; 
                        concesList[g]->printName();
                        cout << endl;
                        cout << "Price per unit:     $" << concesList[g]->getSnackPriceS() << endl;
                        cout << "Number of units:     x" << numItemsC[g] << endl;
                    }
                    else if (concesSize[g] == 2)
                    {
                        //medium
                        cout << "Medium";
                        concesList[g]->printName();
                        cout << endl;
                        cout << "Price per unit:     $" << concesList[g]->getSnackPriceM() << endl;
                        cout << "Number of units:     x" << numItemsC[g] << endl;
                    }
                    else if (concesSize[g] == 3)
                    {
                        //large
                        cout << "Large";
                        concesList[g]->printName();
                        cout << endl;
                        cout << "Price per unit:     $" << concesList[g]->getSnackPriceL() << endl;
                        cout << "Number of units:     x" << numItemsC[g] << endl;
                    }
                }
            }
        }
        cout << "Welcome to your cart" << endl;
        cout << "********************" << endl << endl;
        
        if (objectSizeE > 0 || objectSizeC > 0)
        {
            cout << "Options:" << endl;
            cout << "1. Remove item(s) from cart" << endl;
            cout << "2. Clear cart." << endl;
            cout << "3. Return to menu" << endl;
            cin >> choice;
            cout << endl;
            if (choice == 1)
            {
                int removeChoice = 0;
                cout << "What type of item would you like to remove?" << endl;
                cout << "1. Event tickets" << endl;
                cout << "2. Concession item" << endl;
                cin >> removeChoice;

                if (removeChoice == 1)
                {
                    cout << "Which Event ticket would you like to remove?" << endl;

                    int j = 1;

                    for (int g = 0; g < objectSizeE; g++)
                    {
                        
                        if (numItemsE[g] > 0)
                        {
                            cout << j << ". ";
                            eventList[g]->printName();
                            cout << endl;
                            j++;
                        }
                    }

                    int x;
                    cin >> x;
                    cout << endl;
                    cout << "How many would you like to remove?" << endl;
                    int amountRemove;
                    cin >> amountRemove;
                    cout << endl;
                    removeEventItem(eventList[x - 1], numItemsE[x - 1], x, amountRemove);
                }
                else if (removeChoice == 2)
                {
                    cout << "Which concession item would you like to remove." << endl;

                    int j = 1;

                    for (int g = 0; g < objectSizeC; g++)
                    {

                        if (numItemsC[g] > 0)
                        {
                            cout << j << ". ";
                            concesList[g]->printName();
                            cout << endl;
                            j++;
                        }
                    }

                    int x;
                    cin >> x;
                    cout << endl;
                    cout << "How many would you like to remove?" << endl;
                    int amountRemove;
                    cin >> amountRemove;
                    cout << endl;
                    removeConcesItem(concesList[x - 1], numItemsC[x - 1], x, amountRemove);
                }
            }
            
            else if (choice == 2)
            {
                cleanCart();
            }
            else if (choice == 3)
            {
                break;
            }
        }
        else
        {
            cout << "There appears to be nothing here, you should fix that. Wink* Wink*" << endl;
            cout << "Options:" << endl;
            cout << "1. Return to Main Menu." << endl;
            cin >> choice;
            cout << endl;
            if (choice == 1)
            {
                choice = 2;
                break;
            }

        }
    } while (choice != 2);

}
// adds up and clears the cart
void cart::checkOut()
{
    float sum = 0;
    int choice;

    //Adds object prices together
    for (int g = 0; g < objectSizeE; g++)
    {
        sum += eventList[g]->getPrice() * numItemsE[g];
    }

    for (int g = 0; g < objectSizeC; g++)
    {
        if (concesSize[g] == 1)
        {
            sum += concesList[g]->getSnackPriceS() * numItemsC[g];
        }
        else if (concesSize[g] == 2)
        {
            sum += concesList[g]->getSnackPriceM() * numItemsC[g];
        }
        else if (concesSize[g] == 3)
        {
            sum += concesList[g]->getSnackPriceL() * numItemsC[g];
        }
    }

    cout << "Your total is $" << sum << " do you wish to accept?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choice;
    cout << endl;
    if (choice == 1)
    { 
        objectSizeE = 0;
        objectSizeC = 0;
        cout << endl;
        cout << "Thank you, and have a superfluous day!!!!!" << endl << endl;
    }
}
//sets the object array sizes to 0, so they can be overwritten later
void cart::cleanCart()
{
    for (int g = 0; g < objectSizeE; g++)
    {
        eventList[g]->setOpenSeats(eventList[g]->getSeats() + numItemsE[g]);
    }
    for (int g = 0; g < objectSizeC; g++)
    {
        int temp = 0;

        if (concesSize[g] == 1)
        {
            temp = concesList[g]->getSnackStockS() + numItemsC[g];
            concesList[g]->setSnackStockS(temp);
        }
        else if (concesSize[g] == 2)
        {
            temp = concesList[g]->getSnackStockM() + numItemsC[g];
            concesList[g]->setSnackStockM(temp);
        }
        else if (concesSize[g] == 3)
        {
            temp = concesList[g]->getSnackStockL() + numItemsC[g];
            concesList[g]->setSnackStockL(temp);
        }
    }
    objectSizeE = 0;
    objectSizeC = 0;
    cout << endl;
}



