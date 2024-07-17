#pragma once
#include"Stack.h"
#include"Queue.h"
using namespace std;
void appendChar(string& str, char ch);
void makeEqual(string& a, int x);
void HoanVi(char& a, char& b);
string changeToString(char a);
string fix(string s);
void addChar(string& s, char ch, int pos);
//void shiftLeft(string& s, char a, int pos);
void shiftLeft(string& s, int pos);
void addZeroByDefault(string& s);
int doUuTien(char a);
//void removeChar(string str, int pos);
string subWithSign(string& a, string& b);
void reverse(string& str);
void AddZero(string& str, int x);