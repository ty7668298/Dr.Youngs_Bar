#include"exam.h"
#include"person.h"
using namespace std;

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
