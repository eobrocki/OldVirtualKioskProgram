#include <iostream>

#ifndef __CONCESSIONS_H_INCLUDED__
#define __CONCESSIONS_H_INCLUDED__

using namespace std;

class concessions
{
	public:
		//Set functions 
		void setSnackName(string snackName);
		void setSnackDescript(string snackDescript);
		void setSnackSize(int snackSize);

        //sets stock for particular size of object
		void setSnackStockS(int snackStockS);
        void setSnackStockM(int snackStockM);
        void setSnackStockL(int snackStockL);

        //sets price for particular size of object
        void setSnackPriceS(float snackPriceS);
        void setSnackPriceM(float snackPriceM);
        void setSnackPriceL(float snackPriceL);

        void setConcesType(int type);

        void setListPosition(int position);

		//Get functions
		string getName();
		string getDescript();
		float getPrice();

        int getSnackStockS();
        int getSnackStockM();
        int getSnackStockL();

        float getSnackPriceS();
        float getSnackPriceM();
        float getSnackPriceL();

        int getConcesType();

        int getListPosition();

        int getSnackSize();

        void printName();

    private:
		string title;
		string descript;
        int size;

		int stockS = 0;
        int stockM = 0;
        int stockL = 0;

        float priceS;
        float priceM;
        float priceL;

        //For labeling whether an object is a food item or drink, 0 indicates a food, 1 indicates a drink
        int concesType;
        int listPosition;
};
#endif