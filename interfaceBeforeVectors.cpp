#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "interface.h"
#include "cart.h"
#include "event.h"


using namespace std;
event allEventInfo[100];
concessions allConcesInfo[100];
int eventAmount = 0;
int concesAmount = 0;
vector <event> allEventInfo1;
vector <concessions> allConcesInfo1;
//ddfjsdfklj



//Presents the interface for the events, allows the user to add tickets for events to their cart 
//*********************************************************************************************************************

//each event placed into an array, then the info will be dsiplayed
void eventInterface(cart* userCart)
{
    
        /*
        event BangTrashLid;
        BangTrashLid.setName("Banging on Trash Lids for an Hour");
        BangTrashLid.setDescription("Watch as failed ballet preformers use everyday objects as instruments, and give you a massive headache");
        BangTrashLid.setEventPrice(150.00);
        BangTrashLid.setEventTime("10:45");
        BangTrashLid.setEventDur(60);
        BangTrashLid.setOpenSeats(200);
        allEventInfo[0] = BangTrashLid;
        eventAmount++;
       

        event MrKite;
        MrKite.setName("Mr. Kite's flying circus");
        MrKite.setDescription("A wonderful display of all sort of talent like, jumping through rings and swallowing swords, and.... stuff like that");
        MrKite.setEventPrice(50.00);
        MrKite.setEventTime("2:30");
        MrKite.setEventDur(180);
        MrKite.setOpenSeats(300);
        allEventInfo[1] = MrKite;
        eventAmount++;

        event Whatever;
        Whatever.setName("Whatever");
        Whatever.setDescription("Who cares?");
        Whatever.setEventPrice(0.0);
        Whatever.setEventTime("Sometime");
        Whatever.setEventDur(0);
        Whatever.setOpenSeats(100);
        allEventInfo[2] = Whatever;
        eventAmount++;
        */
    
	int eventChoice;
	do
	{      
		
            do
            {
                cout << "List of events" << endl;
                cout << "**************" << endl;
                cout << endl;
                
                //Prints the first event's details
                for (int g = 0; g < eventAmount; g++)
                {
                    cout << "Title: " << allEventInfo[g].getName() << endl << endl;
                    cout << "    Event's description: " << endl;
                    cout << "    " << allEventInfo[g].getDescript() << endl;
                    cout << "    Price of tickets: " << allEventInfo[g].getPrice() << endl;
                    cout << "    Event times: " << allEventInfo[g].getTime() << endl;
                    cout << "    Event duration: " << allEventInfo[g].getDuration() << endl;
                    cout << "    Number of seats available: " << allEventInfo[g].getSeats() << endl;
                    cout << endl;
                }
          
                cout << "Make a selection" << endl;
                cout << "1. Add ticket(s) to cart." << endl;
                cout << "2. Back to the Main Menu." << endl;
                cin >> eventChoice;
                cout << endl << endl;
                
                do
                {
                    switch (eventChoice)
                    { 
                        case 1:                                                                            
                        {
                            int numberTickets;
                            cout << "Which event would you like tickets for?" << endl;
                       
                            for (int g = 0; g < eventAmount; g++)
                            {
                                cout << g + 1 << ". " << allEventInfo[g].getName() << endl;
                            }
                            cout << eventAmount + 1 << ". " << "Cancel" << endl;
                            int x;
                            cin >> x;
                            cout << endl;

                            // passes event to be added to cart
                            for (int g = 0; g < eventAmount; g++)
                            {
                                if (x == g + 1)
                                {
                                    cout << "How many would you like to add to cart?" << endl;
                                    cin >> numberTickets;
                                    cout << endl;
                                    if (numberTickets == 0 || numberTickets < 0)
                                    {
                                        cout << "Please enter a value greater than zero." << endl;
                                    }
                                    else
                                    {
                                        userCart->addEventItem(&allEventInfo[g], numberTickets);
                                    }
                                }
                                else if (x == eventAmount + 1)
                                {
                                    eventChoice = 2;
                                }
                            }
                            
                       }
                        
                  }
                } while (eventChoice != 2);
                
            } while (eventChoice != 2);
        
		
	} while (eventChoice != 2);
}

//presents the concessions menu, and allows the user to take foof or drinks in different sizes and add them to the cart
void concesInterface(cart* userCart)
{
    if (concesAmount == 0)
    {
        concessions popcorn;
        popcorn.setSnackName("Popcorn");
        popcorn.setSnackDescript("An all time classic, who doesn't like butter covered puff balls, especially when it's stuck to the bottom of your shoe?");
        popcorn.setSnackStockS(200);
        popcorn.setSnackStockM(150);
        popcorn.setSnackStockL(100);
        popcorn.setSnackPriceS(1.25);
        popcorn.setSnackPriceM(1.75);
        popcorn.setSnackPriceL(2.25);
        popcorn.setConcesType(0);
        allConcesInfo[0] = popcorn;
        concesAmount++;

        concessions gooBars;
        gooBars.setSnackName("Goo Goo Bars");
        gooBars.setSnackDescript("Listed as number two on Dan Lingers list of top ten ways to get Diabetes. The most unhealthy snack on the street is back!");
        gooBars.setSnackStockS(300);
        gooBars.setSnackStockM(200);
        gooBars.setSnackStockL(150);
        gooBars.setSnackPriceS(1.50);
        gooBars.setSnackPriceM(2.00);
        gooBars.setSnackPriceL(2.25);
        gooBars.setConcesType(0);
        allConcesInfo[1] = gooBars;
        concesAmount++;

        concessions cinnamonRoll;
        cinnamonRoll.setSnackName("Cinnamon Roll");
        cinnamonRoll.setSnackDescript("A sweet roll, with cinnamon, and icing on top. Go for large if you're adventurous, and not concerned with your calorie intake.");
        cinnamonRoll.setSnackStockS(100);
        cinnamonRoll.setSnackStockM(70);
        cinnamonRoll.setSnackStockL(50);
        cinnamonRoll.setSnackPriceS(3.00);
        cinnamonRoll.setSnackPriceM(3.75);
        cinnamonRoll.setSnackPriceL(5.00);
        cinnamonRoll.setConcesType(0);
        allConcesInfo[3] = cinnamonRoll;
        concesAmount++;

        concessions cocaBola;
        cocaBola.setSnackName("Coca Bola");
        cocaBola.setSnackDescript("Not to be confused with the other cola brand, whose founder stole our recipe, but you know who cares?!");
        cocaBola.setSnackStockS(400);
        cocaBola.setSnackStockM(300);
        cocaBola.setSnackStockL(250);
        cocaBola.setSnackPriceS(1.50);
        cocaBola.setSnackPriceM(2.25);
        cocaBola.setSnackPriceL(2.50);
        cocaBola.setConcesType(1);
        allConcesInfo[2] = cocaBola;
        concesAmount++;

        concessions water;
        water.setSnackName("Water");
        water.setSnackDescript("It's water, what do you want from us?");
        water.setSnackStockS(300);
        water.setSnackStockM(200);
        water.setSnackStockL(150);
        water.setSnackPriceS(1.00);
        water.setSnackPriceM(1.50);
        water.setSnackPriceL(2.00);
        water.setConcesType(1);
        allConcesInfo[4] = water;
        concesAmount++;

        
    }
	int concesChoice;
	do
	{
		cout << "Welcome to the concession stand" << endl;
		cout << "*******************************" << endl;
		cout << endl;
		cout << "Type in a number to make your selection" << endl;
		cout << "1. View Foods" << endl;
		cout << "2. View Refreshments" << endl;
		cout << "3. Back to Main Menu" << endl;

		cin >> concesChoice;
        
        //From here, user determines which item they would like to view the description and prices for foods
        if (concesChoice == 1)
        {
            int j = 1;
            cout << "List of available foods" << endl << endl;
            for (int g = 0; g < concesAmount; g++)
            {
                if (allConcesInfo[g].getConcesType() == 0)
                {
                    cout << j << ". ";
                    allConcesInfo[g].printName();
                    cout << endl << endl;
                    allConcesInfo[g].setListPosition(j);
                    j++;
                }
            }

            cout << endl;
            cout << "Enter your selection." << endl;
            cout << "1. Show price/description of food item" << endl;
            cout << "2. Back to concession menu" << endl;

            cin >> concesChoice;
            switch (concesChoice)
            {
                case 1:
                {
                    int x;
                    cout << "Enter which item you would like to view." << endl;
                    cin >> x;
                    cout << endl << endl;

                    int amount;
                    int size;

                    for (int g = 0; g < concesAmount; g++)
                    {
                       
                        if (allConcesInfo[g].getConcesType() == 0)
                        {
                            if (x  == allConcesInfo[g].getListPosition() )
                            {
                                int concesChoice2;
                                cout << allConcesInfo[g].getName() << endl;
                                cout << allConcesInfo[g].getDescript() << endl;
                                cout << "   " << allConcesInfo[g].getSnackPriceS() << " for small" << endl;
                                cout << "   " << allConcesInfo[g].getSnackPriceM() << " for medium" << endl;
                                cout << "   " << allConcesInfo[g].getSnackPriceL() << " for large" << endl;
                                cout << "Make a selection" << endl;
                                cout << "1. Add to cart." << endl;
                                cout << "2. Return to food menu." << endl;
                                cin >> concesChoice2;
                                cout << endl;

                                if (concesChoice2 == 1)
                                {
                                    cout << "How many units do you want?" << endl;
                                    cin >> amount;
                                    cout << endl;
                                    cout << "What size would you like it in? (1 for small, 2 for medium, 3 for large)" << endl;
                                    cin >> size;

                                    userCart->addConcesItem(&allConcesInfo[g], amount, size);
                                }

                            }

                        }

                    }

                }

            }
        }

        else if (concesChoice == 2)
            {
                int j = 1;
                cout << "List of available drinks" << endl << endl;
                for (int g = 0; g < concesAmount; g++)
                {
                    if (allConcesInfo[g].getConcesType() == 1)
                    {
                        cout << j << ". ";
                        allConcesInfo[g].printName();
                        cout << endl << endl;
                        allConcesInfo[g].setListPosition(j);
                        j++;
                    }
                }

                cout << endl;
                cout << "Enter your selection." << endl;
                cout << "1. Show price/description of food item" << endl;
                cout << "2. Back to concession menu" << endl;

                cin >> concesChoice;
                switch (concesChoice)
                {
                    case 1:
                    {
                        int x;
                        cout << "Enter which item you would like to view." << endl;
                        cin >> x;
                        cout << endl << endl;

                        int amount;
                        int size;

                        for (int g = 0; g < concesAmount; g++)
                        {
                            if (allConcesInfo[g].getConcesType() == 1)
                            {
                                if (x == allConcesInfo[g].getListPosition())
                                {
                                    int concesChoice2;
                                    cout << allConcesInfo[g].getName() << endl;
                                    cout << allConcesInfo[g].getDescript() << endl;
                                    cout << "   " << allConcesInfo[g].getSnackPriceS() << " for small" << endl;
                                    cout << "   " << allConcesInfo[g].getSnackPriceM() << " for medium" << endl;
                                    cout << "   " << allConcesInfo[g].getSnackPriceL() << " for large" << endl;
                                    cout << "Make a selection" << endl;
                                    cout << "1. Add to cart." << endl;
                                    cout << "2. Return to food menu." << endl;
                                    cin >> concesChoice2;
                                    cout << endl;

                                    if (concesChoice2 == 1)
                                    {
                                        cout << "How many units do you want?" << endl;
                                        cin >> amount;
                                        cout << endl;
                                        cout << "What size would you like it in? (1 for small, 2 for medium, 3 for large)" << endl;
                                        cin >> size;

                                        userCart->addConcesItem(&allConcesInfo[g], amount, size);
                                    }

                                }
                            }
                        }
                    }
                }
            }
	} while (concesChoice != 3);
}

//Shows the cart interface, from there the user can remove items, or clear the entire list
void cartInterface(cart* userCart)
{
    userCart->listCart();
}

//Shows the checkout interface, user can checkout and purchase items from their cart 
void checkoutInterface(cart* userCart)
{
	int checkoutChoice;
	do
	{
		cout << "Are you sure you want to check out?" << endl;
		cout << "***********************************" << endl;
		cout << endl;
		cout << "Type in a number to make your selection" << endl;
		cout << "1. YES!" << endl;
        cout << "2. NO!" << endl;
		cin >> checkoutChoice;

	    if (checkoutChoice == 1)
		{
            userCart->checkOut();
            checkoutChoice = 2;
		}

	} while (checkoutChoice != 2);
}

 void mainInterface()
 { 
     /*
     if (eventAmount == 0)
         // read in events, possibly add in file input here
     {
         ifstream eventIn;

         eventIn.open("fileInput.txt");
         if (!eventIn.is_open()) {
             cout << "Could not open file fileInput.txt." << endl;
         }

         string type;
         while (eventIn >> type)
         {
             if (type == "event")
             {
                 break;
             }
             cout << type << endl;

         }
         eventIn.close();
     }
     */
     int count = 0;
     if (eventAmount == 0 && concesAmount == 0)
     {
         ifstream infile("fileInput.txt");

         while (infile)
         {
             
             string input;
             if (!getline(infile, input)) break;

             istringstream inputStream(input);
             
             

             while (inputStream)
             {
                 string s;
                 if (!getline(inputStream, s, ',')) break;
                 if (s == "event")
                 {
                     int price;
                     int duration;
                     int seats;

                     event newEvent;
                     
                     getline(inputStream, s, ',');
                     newEvent.setName(s);

                     getline(inputStream, s, ',');
                     newEvent.setDescription(s);

                     getline(inputStream, s, ',');
                     newEvent.setEventTime(s);

                     getline(inputStream, price, ',');
                     newEvent.setPrice(price);

                     getline(inputStream, s, ',');
                     newEvent.setDuration();




                     inputStream >> price >> duration >> seats;

                     cout << price << duration << seats << endl;
                     

                 }
                 
                 count++;
             }
             

         }
         
         if (!infile.eof())
         {
             cerr << "Failed to read input file!\n";
         }
     }


    //Main interface, where the program starts and leads to the other interfaces
	int userChoice;
	do
	{
		cout << "Welcome to the virtual Kiosk" << endl;
		cout << "****************************" << endl;
		cout << endl;
		cout << "Type in a number to make your selection" << endl;
		cout << "1. Events" << endl;
		cout << "2. Concessions" << endl;
		cout << "3. View Cart" << endl;
		cout << "4. Checkout" << endl;
		cout << "5. Quit" << endl;

		cart userCart;
        
		cin >> userChoice;
        cout << endl;
		
		switch (userChoice)
		{
			case 1: eventInterface(&userCart);
					break;
            case 2: concesInterface(&userCart);
				    break;
			case 3: cartInterface(&userCart);
					break;
			case 4: checkoutInterface(&userCart);
					break;
			case 5:
			{
				int decision;
				cout << "Are you sure you want to quit? (1 for YES / 2 for NO)" << endl;
				cin >> decision;
				cout << endl;

				if (decision == 2)
				{
					userChoice = 0;
				}
			}

			default: cout << "Please enter a valid input." << endl;
		}

	} while (userChoice != 5);
}