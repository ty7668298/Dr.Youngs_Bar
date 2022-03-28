#include<iostream>
using namespace std;

#ifndef EXAM_H
#define EXAM_H

class Exam {
public:
	Exam();
	int getScore();
	void addScore(int s);
	void subScore(int s);
	void setName(string name);
	string getName();
private:
	int score; //Exam score
	string Name; //Exam subject
};

#endif
