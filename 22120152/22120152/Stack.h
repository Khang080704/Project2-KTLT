#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;
struct Stack {
	string* list;
	int max;
	int size;

};

bool init(Stack& s, int n);
bool empty(Stack s);
bool full(Stack s);
bool push(Stack& s, string value);
bool pop(Stack& s);
string top(Stack s);