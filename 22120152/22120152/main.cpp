#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
#include"Queue.h"
#include"algorithms.h"
using namespace std;


string Add(string& str1, string& str2) {
	if (str2[0] == '-') { // str1 + (-str2)
		str2.erase(str2.begin());
		return subWithSign(str1, str2);
	}
	if (str1[0] == '-' && str2[0] != '-') { // -a + b
		str1.erase(str1.begin());
		return subWithSign(str2, str1);
	}
	if (str1[0] == '-' && str2[0] == '-') { // -str1 + (-str2)
		str1.erase(str1.begin());
		str2.erase(str2.begin());
		string result = Add(str1, str2);
		addChar(result, '-', 0);
		return result;
	}
	string s1 = str1;
	string s2 = str2;

	reverse(s1);
	reverse(s2);
	int maxLength = max(s1.size(), s2.size());

	// so chu so 0 can them vao mang nho hon
	int x = max(s1.size(), s2.size()) - (min(s1.size(), s2.size()));

	if (min(s1.size(), s2.size()) == s1.size()) {
		AddZero(s1, x);
	}
	else {
		AddZero(s2, x);
	}

	// cout << s1 << " " << s2 << endl;

	 //char* result = new char[maxLength];
	int bienNho = 0;
	int n1 = s1.size();
	int n2 = s2.size();
	int* a = new int[n1];
	int* b = new int[n2];
	int* c = new int[maxLength + 1];
	int n = 0;

	for (int i = 0; i < n1; i++) {
		a[i] = s1[i] - '0';
	}

	for (int i = 0; i < n1; i++) {
		b[i] = s2[i] - '0';
	}

	for (int i = 0; i < maxLength; i++) {
		int temp = a[i] + b[i] + bienNho;
		c[n++] = temp % 10;
		bienNho = temp / 10;
	}

	if (bienNho) {
		c[n++] = bienNho;
	}

	string result = "";

	for (int i = n - 1; i >= 0; i--) {
		appendChar(result, c[i] + '0');
	}

	return result;
	

}

string Sub(string& str1, string& str2) {
	
	string s1 = str1;
	string s2 = str2;

	reverse(s1);
	reverse(s2);
	int maxLength = max(s1.size(), s2.size());

	// so chu so 0 can them vao mang nho hon
	int x = max(s1.size(), s2.size()) - (min(s1.size(), s2.size()));

	if (min(s1.size(), s2.size()) == s1.size()) {
		AddZero(s1, x);
	}
	else {
		AddZero(s2, x);
	}
	int bienNho = 0;
	int n1 = s1.size();
	int n2 = s2.size();
	int* a = new int[n1];
	int* b = new int[n2];
	int* c = new int[maxLength];
	int n = 0;

	for (int i = 0; i < n1; i++) {
		a[i] = s1[i] - '0';
	}

	for (int i = 0; i < n1; i++) {
		b[i] = s2[i] - '0';
	}


	for (int i = 0; i < maxLength; i++) {
		int temp = a[i] - b[i] - bienNho; // push vao nguoc
		if (temp < 0) {
			bienNho = 1;
			c[n++] = 10 + temp;
		}
		else {
			c[n++] = temp;
			bienNho = 0;
		}
	}
	// kiem tra neu bien nho conf thi luu vao

	int sub0 = 0;
	string result = "";




	for (int i = n - 1; i >= 0; i--) {
		if (sub0 == 0 && c[i]) {
			sub0 = 1;
		}
		if (sub0) {
			appendChar(result, c[i] + '0');

		}
	}


	if (sub0 == 0) /*cout <<"0"*/ {
		appendChar(result, '0');
	}

	return result;
}

string subWithSign(string& a, string& b) {
	if (b[0] == '-' && a[0] != '-') { //a - (-b)
		b.erase(b.begin());
		string result = Add(a, b);
		return result;
	}
	if (a[0] == '-' && b[0] != '-') { // -a - b
		a.erase(a.begin());
		string result = Add(a, b);
		addChar(result, '-', 0);
		return result;
	}
	if (a[0] == '-' && b[0] == '-') { //-a -(-b)
		a.erase(a.begin());
		b.erase(b.begin());
		return subWithSign(b, a);
	}
	string temp = "";
	int x = max(a.size(), b.size()) - (min(a.size(), b.size()));

	if (min(a.size(), b.size()) == a.size()) {
		makeEqual(a, x);
	}
	else {
		makeEqual(b, x);
	}
	if (a > b) {
		temp = Sub(a, b);
	}
	else {
		if (a < b) {
			temp = Sub(b, a);
			addChar(temp, '-', 0);
		}
		else {
			addChar(temp, '0', 0);
		}
	}
	return temp;
}
string Multiple(string& str1, string& str2) {
	if (str1 == "0" || str2 == "0") {
		return "0";
	}
	string s1 = str1;
	string s2 = str2;

	reverse(s1);
	reverse(s2);

	int lengthS1 = s1.size();
	int lengthS2 = s2.size();
	int maxLength = max(s1.size(), s2.size());
	string s3;
	for (int i = 0; i < lengthS1 + lengthS2; i++) {
		s3 += '0';
	}


	for (int i = 0; i < lengthS2; i++) {
		int nho = 0;
		int j;
		for (j = 0; j < lengthS1; j++) {
			int x = (s2[i] - '0') * (s1[j] - '0') + nho + (s3[i + j] - '0');
			s3[i + j] = x % 10 + '0';
			nho = x / 10;
		}
		if (nho > 0) {
			s3[i + j] = nho + '0';
		}
	}

	reverse(s3);

	for (int i = 0; i < s3.size(); i++) {
		if (s3[i] == '0') {
			s3.erase(s3.begin() + i);
		}
		else {
			break;
		}
	}
	return s3;
}

string MultipWithSign(string& s1, string& s2) {
	if (s1 == "0" || s2 == "0") {
		return "0";
	}
	if (s1[0] == '-' && s2[0] != '-') {
		s1.erase(s1.begin());
		string result = Multiple(s1, s2);
		addChar(result, '-', 0);
		return result;
	}
	if (s1[0] != '-' && s2[0] == '-') {
		s2.erase(s2.begin());
		string result = Multiple(s1, s2);
		addChar(result, '-', 0);
		return result;
	}
	if (s1[0] == '-' && s2[0] == '-') {
		s1.erase(s1.begin());
		s2.erase(s2.begin());
		return Multiple(s1, s2);
	}
	else {
		return Multiple(s1, s2);
	}
}

Queue solve(string s) {
	string input = fix(s);
	addZeroByDefault(input);
	Stack a;
	init(a, 500);
	Queue b;
	initQueue(b, 500);
	int index = 0;

	for (int i = 0; i < input.length(); i = i + index) {
		if (input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/'
			&& input[i] != '(' && input[i] != ')') {
			int j = 0;
			string temp = "";
			while (input[i + j] != '+' && input[i + j] != '-' && input[i + j] != '*' && input[i + j] != '/'
				&& input[i + j] != '(' && input[i + j] != ')' && input[i + j] != '\0') {
				temp += input[i + j];
				j++;
			}
			index = j;

			pushQueue(b, temp);
		}
		else {
			if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
				if (doUuTien(input[i]) > doUuTien(top(a)[0])) {
					push(a, changeToString(input[i]));
				}
				else {
					while (!empty(a) && top(a) != "(" && doUuTien(input[i]) <= doUuTien(top(a)[0])) {
						pushQueue(b, top(a));
						pop(a);
					}
					push(a, changeToString(input[i]));
				}
				index = 1;

			}
			else {
				if (input[i] == '(') {
					push(a, changeToString(input[i]));
				}
				else {
					while (top(a) != "(") {
						pushQueue(b, top(a));
						pop(a);
					}
					pop(a);
				}
				index = 1;
			}
		}
	}

	while (!empty(a)) {
		pushQueue(b, top(a));
		pop(a);
	}

	return b;
}

string calculate(string s) {
	Queue postfix = solve(s);
	Stack computer;
	init(computer, 500);
	string result = "";

	while (!emptyQueue(postfix)) {
		if (Front(postfix) != "+" && Front(postfix) != "-" && Front(postfix) != "*"
			&& Front(postfix) != "/") {
			push(computer, Front(postfix));
		}
		else {
			if (Front(postfix) == "+") {
				string x = top(computer);
				pop(computer);
				string y = top(computer);
				pop(computer);
				result = Add(x, y);
				push(computer, result);
			}
			else {
				if (Front(postfix) == "-") {
					string x = top(computer);
					pop(computer);
					string y = top(computer);
					pop(computer);
					result = subWithSign(y, x);
					push(computer, result);
				}
				else {
					if (Front(postfix) == "*") {
						string x = top(computer);
						pop(computer);
						string y = top(computer);
						pop(computer);
						result = MultipWithSign(y, x);
						push(computer, result);
					}
				}
			}
			
		}
		popQueue(postfix);
	}
	return result;
}

int main()
{

	ifstream reader("input.txt", ios::in);
	ofstream writter("output.txt", ios::out);

	while (!reader.eof()) {
		string buffer;
		getline(reader, buffer);
		string result = calculate(buffer);
		writter << result << endl;
	}

	reader.close();
	writter.close();

}
