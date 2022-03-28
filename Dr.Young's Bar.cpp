#include<iostream>
#include<string>
#include<map>
#include<Windows.h>
#include<time.h>
#include<fstream>
#include"drink.h"
#include"exam.h"
#include"menu.h"
#include"person.h"
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
	system("cls"); 
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
	system("cls"); 
	cout << endl << endl << endl;
	cout << "1. A.O.C $120" << endl;
	cout << "2. V.D.Q.S $90" << endl;
	cout << "3. I.G.P $60" << endl;
	cout << "4. V.D.F $40" << endl;
	cout << "5. Lucky customer $60" << endl;
	cout << "Enter you choice: ";
}
void Menu::Menu4() {
	system("cls"); 
	cout << endl << endl << endl;
	cout << "1. Yellow Beer $20" << endl;
	cout << "2. Amber Beer $20" << endl;
	cout << "3. Brown Beer $20" << endl;
	cout << "4. Black Beer $20" << endl;
	cout << "5. Wine Taster $20" << endl;
	cout << "Enter you choice: ";
}

Exam::Exam() {
	score = 70; //The initial score of each subject is 70
	Name = "";
}
int Exam::getScore() {
	if (score > 100) { 
		score = 100; //More than 100 points count as 100 points
	}
	return score;
}
void Exam::addScore(int s) {
	score += s; //Increase scores for drinking
}
void Exam::subScore(int s) {
	score -= s; //Excessive intake of alcohol reduces exam score
}
void Exam::setName(string name) {
	Name = name; //Define exam subjects
}
string Exam::getName() {
	return Name;
}

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

Person::Person() {
	balance = 1000; //The initial balance is 1000
	intoxi = 0;
	finalScore = 0;
}
int Person::getBalance() {
	return balance;
}
int Person::getIntoxi() {
	return intoxi;
}
int Person::purchase(int cost) {
	//Buy wine, if successful, return 1; otherwise return 0
	if (cost > balance) {
		return 0; //The money is not enough
	}
	balance -= cost; //Deduction
	return 1;
}
void Person::resetIntoxi() {
	intoxi = 0; //Reset intoxication
}
void Person::addIntoxi(int x) {
	intoxi += x; //Increase intoxication
}
int Person::getScore() {
	//Calculate the final score
	int score = 0;
	//First calculate the total score of the five exam
	for (int i = 0; i < 5; i++) {
		score += exam[i].getScore();
	}
	score += balance / 10; //Then add the balance divided by 10 as extra points
	return score;
}
void Person::setExam(int day, Exam temp) {
	exam[day - 1] = temp;
}
Exam Person::getExam(int idx) {
	return exam[idx]; //Get the exam subject of one day
}

Menu m; //Objects of class Menu
Person p; //Objects of class Person
Drink d; //Objects of class Drink

void init();
int input();
void Instructions();
void Game();
void StartGame(int day);
void Wine();
void Beer();

//The effect of each drink on the score increase of each subject
int matrix[14][9] = {
	{5,2,10,2,2,2,3,3,3},
	{10,5,2,5,5,5,3,3,3},
	{3,2,5,2,2,2,5,5,5},
	{2,5,2,5,5,5,5,5,5},
	{5,3,3,3,3,3,10,10,10},
	{5,10,5,10,10,10,2,2,2},
	{10,5,10,5,5,5,8,8,8},
	{8,5,8,5,5,5,5,5,5},
	{8,3,5,3,3,3,3,3,3},
	{5,5,2,5,5,5,3,3,3},
	{0,0,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,2,2,2},
	{2,0,0,0,0,0,0,0,0},
	{0,2,0,2,2,2,0,0,0},
};
map<string, int> dic1;
map<string, int> dic2;

void init() {
	//Match score and exam subjects one by one with the subscripts in the matrix above
	dic1["Whisky"] = 0;
	dic1["Vodka"] = 1;
	dic1["Gin"] = 2;
	dic1["Rum"] = 3;
	dic1["Tequila"] = 4;
	dic1["Brandy"] = 5;
	dic1["A.O.C"] = 6;
	dic1["V.D.Q.S"] = 7;
	dic1["I.G.P"] = 8;
	dic1["V.D.F"] = 9;
	dic1["Yellow Beer"] = 10;
	dic1["Amber Beer"] = 11;
	dic1["Brown Beer"] = 12;
	dic1["Black Beer"] = 13;
	dic2["Literature"] = 0;
	dic2["Mathematics"] = 1;
	dic2["Communication"] = 2;
	dic2["Physics"] = 3;
	dic2["Chemistry"] = 4;
	dic2["Biology"] = 5;
	dic2["Philosophy"] = 6;
	dic2["History"] = 7;
	dic2["Geography"] = 8;
}

int input() {
	//It is used for user input selection and returns the user's selection
	string input;
	while (true) {
		getline(cin, input); 
		if (input.length() == 1 && input[0] >= '1' && input[0] <= '9') {
			return input[0] - '0'; //If the input is a character between 1 and 9, the user's choice is returned
		}
		cout << "Your input is wrong, please input again: ";
	}
}

void Instructions() {
	//Read the contents of "instruction.txt"
	system("cls");
	cout << endl << endl << endl << endl << endl;
	ifstream f;
	f.open("instruction.txt"); 
	if (!f.is_open()) {
		cout << "Open file failure" << endl;
	}
	string temp;
	//Output file content
	while (getline(f, temp)) {
		cout << temp << endl;
	}
	f.close();
	cout << "Press any key to return to the main menu..." << endl;
	getchar();
	Game();
}

void Wine() {
	m.Menu3();
	int choice;
	while (true) {
		choice = input(); //User input option
		if (choice >= 1 && choice <= 5) {
			break;
		}
		cout << "Your input is wrong, please input again: ";
	}
	switch (choice)
	{
	case 1:
		d.set("A.O.C", 120, 20, "");
		break;
	case 2:
		d.set("V.D.Q.S", 90, 20, "");
		break;
	case 3:
		d.set("I.G.P", 60, 30, "");
		break;
	case 4:
		d.set("V.D.F", 40, 30, "");
		break;
	case 5: {
		int x = rand() % 100 + 1; //Get a number between 1 and 100
		if (x >= 1 && x <= 10) {
			d.set("A.O.C", 60, 20, "");
		}
		else if (x >= 11 && x <= 35) {
			d.set("V.D.Q.S", 60, 20, "");
		}
		else if (x >= 36 && x <= 75) {
			d.set("I.G.P", 60, 30, "");
		}
		else {
			d.set("V.D.F", 60, 30, "");
		}
		cout << "You get " << d.getName() << "!" << endl;
		cout << "Press any key to continue..." << endl;
		getchar();
		break;
	}
	default:
		break;
	}
}

void Beer() {
	m.Menu4();
	int choice;
	while (true) {
		choice = input(); //User input option
		if (choice >= 1 && choice <= 5) {
			break;
		}
		cout << "Your input is wrong, please input again: ";
	}
	switch (choice)
	{
	case 1:
		d.set("Yellow Beer", 20, 20, "");
		break;
	case 2:
		d.set("Amber Beer", 20, 20, "");
		break;
	case 3:
		d.set("Brown Beer", 20, 20, "");
		break;
	case 4:
		d.set("Black Beer", 20, 20, "");
		break;
	case 5: {
		int x = rand() % 4 + 1; //Get a number between 1 and 4
		if (x == 1) {
			d.set("Yellow Beer", 20, 20, "");
		}
		else if (x == 2) {
			d.set("Amber Beer", 20, 20, "");
		}
		else if (x == 3) {
			d.set("Brown Beer", 20, 20, "");
		}
		else {
			d.set("Black Beer", 20, 20, "");
		}
		cout << "You get " << d.getName() << "!" << endl;
		cout << "Press any key to continue..." << endl;
		getchar();
		break;
	}
	default:
		break;
	}
}

void StartGame(int day) {
	p.resetIntoxi(); //Reset intoxication
	Exam e; //Objects of class Exam 
	//Define what subject is today
	if (day == 1) {
		e.setName("Literature");
	}
	else if (day == 2) {
		e.setName("Mathematics");
	}
	else if (day == 3) {
		e.setName("Communication");
	}
	else if (day == 4) {
		int x = rand() % 3; //Generate a random number between 0 and 2
		if (x == 0) {
			e.setName("Physics");
		}
		else if (x == 1) {
			e.setName("Chemistry");
		}
		else {
			e.setName("Biology");
		}
	}
	else {
		int x = rand() % 3; //Generate a random number between 0 and 2
		if (x == 0) {
			e.setName("Philosophy");
		}
		else if (x == 1) {
			e.setName("History");
		}
		else {
			e.setName("Geography");
		}
	}

	while (true) {
		m.Menu2(day);
		cout << "Your exam subject tomorrow is: " << e.getName() << "." << endl;
		cout << "Your balance: " << p.getBalance() << endl;
		cout << "Enter you choice: ";
		int flag = 0;
		int choice = input();
		switch (choice)
		{
		case 1:
			d.set("Whisky", 70, 40, "On the rock!");
			break;
		case 2:
			d.set("Vodka", 50, 60, "Feel braver!");
			break;
		case 3:
			d.set("Gin", 60, 30, "Clean and cool!");
			break;
		case 4:
			d.set("Rum", 40, 50, "La Cunyaya! Oh, Ho!");
			break;
		case 5:
			d.set("Tequila", 50, 40, "A slice of lemon would be perfect!");
			break;
		case 6:
			d.set("Brandy", 80, 10, "The soul of grape!");
			break;
		case 7:
			Wine();
			break;
		case 8:
			Beer();
			break;
		case 9:
			flag = 1; //Get out of the loop
			break;
		default:
			break;
		}
		if (flag) {
			break;
		}
		if (!p.purchase(d.getPrice())) {
			//Purchase failed
			cout << "Your balance is not enough!" << endl;
			continue;
		}
		p.addIntoxi(d.getIntoxi()); //Increase intoxication
		e.addScore(matrix[dic1[d.getName()]][dic2[e.getName()]]); //Increase exam score
		d.Outputt();
		cout << "Drinking...Wait for 2 seconds..." << endl;
		Sleep(2000);
	}
	if (p.getIntoxi() > 100) {
		//Excessive intake of alcohol reduces exam score
		e.subScore((p.getIntoxi() - 100) / 5);
	}
	cout << "Your " << e.getName() << " exam grade is: " << e.getScore() << "." << endl;
	p.setExam(day, e);
	cout << "Press any key to continue..." << endl;
	getchar();
}

void Output() {
	//Output game results
	cout << "Your final grade is: " << p.getScore() << endl;
	ofstream outfile;
	outfile.open("record.txt");
	if (!outfile.is_open()) {
		cout << "Open file failure" << endl;
	}
	for (int i = 0; i < 5; i++) {
		Exam temp = p.getExam(i);
		outfile << "Day " << i + 1 << endl;
		outfile << "Exam: " << temp.getName() << endl;
		outfile << "Grade: " << temp.getScore() << endl;
		outfile << endl;
	}
	outfile << "Balance: " << p.getBalance() << endl;
	outfile << "Final grade: " << p.getScore() << endl;
}

void Game() {
	//The starting interface of the game
	m.Menu1(); //Show the first menu
	int choice;
	while (true) {
		choice = input(); 
		if (choice >= 1 && choice <= 3) {
			break;
		}
		cout << "Your input is wrong, please input again: ";
	}
	switch (choice)
	{
	case 1:
		for (int day = 1; day <= 5; day++) {
			//From Monday to Friday
			StartGame(day);
		}
		Output();
		break;
	case 2:
		Instructions();
		break;
	case 3:
		system("exit");
		break;
	default:
		break;
	}
}

int main() 
{
	srand(time(NULL)); //Set the seed of the random number
	init();
	Game();
	cout << "Game over. Press any key to quit." << endl;
	getchar();
	return 0;
}
