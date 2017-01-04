#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "interface.h"
#include "cart.h"
#include "event.h"


using namespace std;
//event allEventInfo[100];
//concessions allConcesInfo[100];
int eventAmount = 0;
int concesAmount = 0;
vector <event> allEventInfo;
vector <concessions> allConcesInfo;



//Presents the interface for the events, allows the user to add tickets for events to their cart 

//each event placed into an array, then the info will be dsiplayed
void eventInterface(cart* userCart)
{
        //The old way of inputing objects, consider it a legacy feature
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
                    cout << "Title: " << allEventInfo.at(g).getName() << endl << endl;
                    cout << "    Event's description: " << endl;
                    cout << "    " << allEventInfo.at(g).getDescript() << endl;
                    cout << "    Price of tickets: " << allEventInfo.at(g).getPrice() << endl;
                    cout << "    Event times: " << allEventInfo.at(g).getTime() << endl;
                    cout << "    Event duration: " << allEventInfo.at(g).getDuration() << endl;
                    cout << "    Number of seats available: " << allEventInfo.at(g).getSeats() << endl;
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
                                cout << g + 1 << ". " << allEventInfo.at(g).getName() << endl;
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
                                        userCart->addEventItem(&allEventInfo.at(g), numberTickets);
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
        // Old way of inputing concessions object, consider it a legacy feature
        /*
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
        */
        
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
                if (allConcesInfo.at(g).getConcesType() == 0)
                {
                    cout << j << ". ";
                    allConcesInfo.at(g).printName();
                    cout << endl << endl;
                    allConcesInfo.at(g).setListPosition(j);
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
                       
                        if (allConcesInfo.at(g).getConcesType() == 0)
                        {
                            if (x == allConcesInfo.at(g).getListPosition())
                            {
                                int concesChoice2;
                                cout << allConcesInfo.at(g).getName() << endl;
                                cout << allConcesInfo.at(g).getDescript() << endl;
                                cout << "   " << allConcesInfo.at(g).getSnackPriceS() << " for small" << endl;
                                cout << "   " << allConcesInfo.at(g).getSnackPriceM() << " for medium" << endl;
                                cout << "   " << allConcesInfo.at(g).getSnackPriceL() << " for large" << endl;
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

                                    userCart->addConcesItem(&allConcesInfo.at(g), amount, size);
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
                    if (allConcesInfo.at(g).getConcesType() == 1)
                    {
                        cout << j << ". ";
                        allConcesInfo.at(g).printName();
                        cout << endl << endl;
                        allConcesInfo.at(g).setListPosition(j);
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
                            if (allConcesInfo.at(g).getConcesType() == 1)
                            {
                                if (x == allConcesInfo.at(g).getListPosition())
                                {
                                    int concesChoice2;
                                    cout << allConcesInfo.at(g).getName() << endl;
                                    cout << allConcesInfo.at(g).getDescript() << endl;
                                    cout << "   " << allConcesInfo.at(g).getSnackPriceS() << " for small" << endl;
                                    cout << "   " << allConcesInfo.at(g).getSnackPriceM() << " for medium" << endl;
                                    cout << "   " << allConcesInfo.at(g).getSnackPriceL() << " for large" << endl;
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

                                        userCart->addConcesItem(&allConcesInfo.at(g), amount, size);
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
    
    //File Input 
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
                     float price;
                     int duration;
                     int seats;

                     event newEvent;
                     //Input object name
                     getline(inputStream, s, ',');
                     newEvent.setName(s);
                     //Input object description
                     getline(inputStream, s, ',');
                     newEvent.setDescription(s);
                     //Input object time                     
                     getline(inputStream, s, ',');
                     newEvent.setEventTime(s);

                     //Converts strings to int
                     //price
                     getline(inputStream, s, ',');
                     stringstream convert(s);
                     if (!(convert >> price))
                     {
                         price = 0;
                     }
                     newEvent.setEventPrice(price);
                     //duration
                     getline(inputStream, s, ',');
                     stringstream convert2(s);
                     if (!(convert2 >> duration))
                     {
                         duration = 0;
                     }
                     newEvent.setEventDur(duration);
                     //seats
                     getline(inputStream, s, ',');
                     stringstream convert3(s);
                     if (!(convert3 >> seats))
                     {
                         seats = 0;
                     }
                     newEvent.setOpenSeats(seats);

                     allEventInfo.push_back(newEvent);

                     eventAmount++;
                 }
                 else if (s == "concessions")
                 {
                     int stock;
                     float price;
                     int type;

                     concessions newConces;
                     //Sets name
                     getline(inputStream, s, ',');
                     newConces.setSnackName(s);
                     //set description
                     getline(inputStream, s, ',');
                     newConces.setSnackDescript(s);
                     //Converts strings to ints 
                     //Stock Small
                     getline(inputStream, s, ',');
                     stringstream convert(s);
                     if (!(convert >> stock))
                     {
                         stock = 0;
                     }
                     newConces.setSnackStockS(stock);
                     //Stock Medium
                     getline(inputStream, s, ',');
                     stringstream convert1(s);
                     if (!(convert1 >> stock))
                     {
                         stock = 0;
                     }
                     newConces.setSnackStockM(stock);
                     //Stocke Large
                     getline(inputStream, s, ',');
                     stringstream convert2(s);
                     if (!(convert2 >> stock))
                     {
                         stock = 0;
                     }
                     newConces.setSnackStockL(stock);
                     //Price Small
                     getline(inputStream, s, ',');
                     stringstream convert3(s);
                     if (!(convert3 >> price))
                     {
                         price = 0;
                     }
                     newConces.setSnackPriceS(price);
                     //Price Medium
                     getline(inputStream, s, ',');
                     stringstream convert4(s);
                     if (!(convert4 >> price))
                     {
                         price = 0;
                     }
                     newConces.setSnackPriceM(price);
                     //Price Large
                     getline(inputStream, s, ',');
                     stringstream convert5(s);
                     if (!(convert5 >> price))
                     {
                         price = 0;
                     }
                     newConces.setSnackPriceL(price);
                     //Conces Type
                     getline(inputStream, s, ',');
                     stringstream convert6(s);
                     if (!(convert6 >> type))
                     {
                         type = 0;
                     }
                     newConces.setConcesType(type);

                     allConcesInfo.push_back(newConces);

                     concesAmount++;
                 }
                 else
                 {
                     cout << "File not formatted correctly" << endl;
                 }
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