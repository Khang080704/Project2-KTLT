#include"Stack.h"
bool init(Stack& s, int n) {
	s.list = new string[n];
	if (s.list == NULL)
		return false;
	else {
		s.max = n;
		s.size = 0;
		return true;
	}
}

bool empty(Stack s) {
	if (s.size == 0) {
		return true;
	}
	return false;
}

bool full(Stack s) {
	if (s.size == s.max)
		return true;
	return false;
}

bool push(Stack& s, string value) {
	if (full(s))
		return false;
	s.list[s.size] = value;
	s.size++;
	return true;
}

bool pop(Stack& s) {
	if (empty(s))
		return false;
	s.size--;
	return true;
}

string top(Stack s) {
	if (empty(s)) {
		return " ";
	}
	else {	
		return s.list[s.size - 1];
	}
}