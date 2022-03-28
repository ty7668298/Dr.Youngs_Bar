#include<iostream>
#include"drink.h"
using namespace std;

void Drink::set(string name, int price, int intoxi, string output) {
	Name = name;
	Price = price;
	Intoxi = intoxi;
	Output = output;
}
string Drink::getName() {
	return Name;
}
int Drink::getPrice() {
	return Price;
}
int Drink::getIntoxi() {
	return Intoxi;
}
void Drink::Outputt() {
	cout << Output << endl;
}