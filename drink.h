#include <iostream>
using namespace std;

#ifndef DRINK_H
#define DRINK_H

class Drink {
public:
	void set(string name, int price, int intoxi, string output);
	string getName();
	int getPrice();
	int getIntoxi();
	void Outputt();
private:
	string Name; //Alcohol Category
	int Price; //Price of alcohol 
	int Intoxi; //Intoxication 
	string Output; //Sentences after every drink
};

#endif
