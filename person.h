#include"exam.h"
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person {
public:
	Person();
	int getBalance();
	int getIntoxi();
	int purchase(int cost);
	void resetIntoxi();
	void addIntoxi(int x);
	int getScore();
	void setExam(int day, Exam temp);
	Exam getExam(int idx);
private:
	int balance; 
	int intoxi; //Intoxication 
	Exam exam[5]; //Exam of 5 subjects
	int finalScore; //Final score of the whole game 
};

#endif
