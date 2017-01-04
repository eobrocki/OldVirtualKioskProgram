#include <string>
#include "event.h"

using namespace std;

//	Set functions
void event::setName(string eventName)
{
	title = eventName;
};

void event::setDescription(string description)
{
	descript = description;
};

void event::setEventPrice(float eventPrice)
{
	price = eventPrice;
};

void event::setEventTime(string eventTime)
{
	time = eventTime;
};

void event::setEventDur(int eventDuration)
{
	duration = eventDuration;
};

void event::setOpenSeats(int openSeats)
{
	seats = openSeats;
};

//	Get Functions
string event::getName()
{
	return title;
};

string event::getDescript()
{
	return descript;
};

float event::getPrice()
{
	return price;
};

string event::getTime()
{
	return time;
}

int event::getDuration()
{
	return duration;
};

int event::getSeats()
{
	return seats;
};

void event::printName()
{
    cout << title;
}