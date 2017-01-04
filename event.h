#include <iostream>

using namespace std;

#ifndef __EVENT_H_INCLUDED__
#define __EVENT_H_INCLUDED__

class event
{
	public: 
		//Set Functions
		void setName(string eventName);
		void setDescription(string description);
		void setEventPrice(float eventPrice);
		void setEventTime(string eventTime);
		void setEventDur(int eventDuration);
		void setOpenSeats(int openSeats);
    
		//Get Functions
		string getName();
		string getDescript();
		float getPrice();
		string getTime();
		int getDuration();
		int getSeats();

        void printName();
        
		
	private:
		string title;
		string descript;
		float price;
		string time;
		int duration;
		int seats;
};

#endif