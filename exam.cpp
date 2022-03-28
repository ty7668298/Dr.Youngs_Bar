#include<iostream>
#include"exam.h"
using namespace std;

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
