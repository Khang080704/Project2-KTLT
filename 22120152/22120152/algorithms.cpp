#include"algorithms.h"
void removeChar(char* str, int pos) {
	int len = strlen(str);
	for (int i = pos; i < len; i++) {
		str[i] = str[i + 1];
	}

	str[len - 1] = '\0';
}
void appendChar(string& str, char ch) {
	str += ch;
}
string changeToString(char a) {
	string result = "";
	result += a;
	return result;
}
string fix(string s) {
	stringstream ss(s);
	string a;
	string b;
	while (ss >> a) {
		b += a;
	}

	return b;
}

void addChar(string& s, char ch, int pos) {
	s.insert(s.begin() + pos, ch);
}
//void shiftLeft(string& s, char a, int pos) {
//	for (int i = s.size() - 1; i >= pos; i--) {
//		s[i + 1] = s[i];
//
//	}
//	s.resize(s.size() + 1);
//	s[pos] = a;
//}
void addZeroByDefault(string& s) {
	if ((s[0] == '+' || s[0] == '-') && s[1] >= '0' && s[1] <= '9') {
		s.insert(s.begin() + 0, '0');
	}
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] == '+' || s[i] == '-') && s[i + 1] >= '0' && s[i + 1] <= '9'
			&& (s[i - 1] < '0' || s[i - 1] > '9')) {
			if (s[i - 1] != ')') {
				s.insert(s.begin() + i, '0');
			}
		}
	}
}

int doUuTien(char a) {
	if (a == ' ') {
		return INT_MIN;
	}
	if (a == '+' || a == '-') {
		return 1;
	}
	else {
		if (a == '(') {
			return 0;
		}
		else {
			if (a == '*' || a == '/') {
				return 2;
			}
			else {
				return 3;
			}
		}
	}
}

void shiftLeft(string& s, int pos) {
	for (int i = pos; i < s.size(); i++) {
		s[i] = s[i + 1];
	}
	s.resize(s.size() - 1);
}
void makeEqual(string& a, int x) {
	for (int i = 1; i <= x; i++) {
		addChar(a, '0', 0);
	}
}
void HoanVi(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}
void reverse(string& str) {
	int n = str.size();
	if (n == 1) {
		return;
	}
	for (int i = 0; i < n / 2; ++i) {
		HoanVi(str[i], str[n - i - 1]);
	}
}
void AddZero(string& str, int x) {
	int length = str.size();

	for (int i = 0; i < x; i++) {
		str += '0';
	}
}