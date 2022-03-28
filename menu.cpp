#include<iostream>
#include"menu.h"
using namespace std;

void Menu::Menu1() {
	system("cls"); //clear screen
	cout << endl << endl << endl << endl << endl;
	cout << "1. Start Game" << endl;
	cout << "2. Instructions" << endl;
	cout << "3. Quit Game" << endl;
	cout << "Enter you choice: ";
}
void Menu::Menu2(int day) {
	system("cls"); //clear screen
	cout << endl << endl;
	cout << "Today is day " << day << "." << endl;
	cout << "Welcome to Dr.Young¡¯s Bar!" << endl;
	cout << "1. Whisky $70" << endl;
	cout << "2. Vodka $50" << endl;
	cout << "3. Gin $60" << endl;
	cout << "4. Rum $40" << endl;
	cout << "5. Tequila $50" << endl;
	cout << "6. Brandy $80" << endl;
	cout << "7. Wine" << endl;
	cout << "8. Beer" << endl;
	cout << "9. Leave the bar and end the day" << endl;
}
void Menu::Menu3() {
	system("cls"); //clear screen
	cout << endl << endl << endl;
	cout << "1. A.O.C $120" << endl;
	cout << "2. V.D.Q.S $90" << endl;
	cout << "3. I.G.P $60" << endl;
	cout << "4. V.D.F $40" << endl;
	cout << "5. Lucky customer $60" << endl;
	cout << "Enter you choice: ";
}
void Menu::Menu4() {
	system("cls"); //clear screen
	cout << endl << endl << endl;
	cout << "1. Yellow Beer $20" << endl;
	cout << "2. Amber Beer $20" << endl;
	cout << "3. Brown Beer $20" << endl;
	cout << "4. Black Beer $20" << endl;
	cout << "5. Wine Taster $20" << endl;
	cout << "Enter you choice: ";
}
