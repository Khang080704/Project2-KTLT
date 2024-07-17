#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;
struct Queue {
	string* list;
	int max;
	int size;

};
bool initQueue(Queue& q, int n);
bool emptyQueue(Queue q);
bool fullQueue(Queue q);
bool pushQueue(Queue& q, string value);
bool popQueue(Queue& q);
string Front(Queue q);