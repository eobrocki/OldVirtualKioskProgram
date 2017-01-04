#include <string>
#include "concessions.h"

using namespace std;


//    Set Functions
void concessions::setSnackName(string snackName)
{
	title = snackName;
};

void concessions::setSnackDescript(string snackDescript)
{
	descript = snackDescript;
};

void concessions::setSnackSize(int snackSize)
{
    size = snackSize;
}

void concessions::setSnackStockS(int snackStockS)
{
	stockS = snackStockS;
};

void concessions::setSnackStockM(int snackStockM)
{
    stockM = snackStockM;
};

void concessions::setSnackStockL(int snackStockL)
{
    stockL = snackStockL;
};


void concessions::setSnackPriceS(float snackPriceS)
{
    priceS = snackPriceS;
}

void concessions::setSnackPriceM(float snackPriceM)
{
    priceM = snackPriceM;
}

void concessions::setSnackPriceL(float snackPriceL)
{
    priceL = snackPriceL;
}

void concessions::setConcesType(int type)
{
    concesType = type;
}

void concessions::setListPosition(int position)
{
    listPosition = position;
}



//Get Functions
string concessions::getName()
{
	return title;
};

string concessions::getDescript()
{
	return descript;
};

int concessions::getSnackSize()
{
    return size;
}

int concessions::getSnackStockS()
{
	return stockS;
};

int concessions::getSnackStockM()
{
    return stockM;
};

int concessions::getSnackStockL()
{
    return stockL;
};

float concessions::getSnackPriceS()
{
    return priceS;
};

float concessions::getSnackPriceM()
{
    return priceM;
};

float concessions::getSnackPriceL()
{
    return priceL;
};

int concessions::getConcesType()
{
    return concesType;
}

int concessions::getListPosition()
{
    return listPosition;
}

void concessions::printName()
{
    cout << title;
}

