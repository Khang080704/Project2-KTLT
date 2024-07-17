#include"Queue.h"

bool initQueue(Queue& q, int n) {
	q.list = new string[n];
	if (q.list == NULL) {
		return false;
	}
	q.max = n;
	q.size = 0;
	return true;
}

bool emptyQueue(Queue q) {
	if (q.size == 0)
		return true;
	return false;
}

bool fullQueue(Queue q) {
	if (q.size == q.max)
		return true;
	return false;
}

bool pushQueue(Queue& q, string value) {
	if (fullQueue(q)) {
		return false;
	}
	else {
		q.list[q.size] = value;
		q.size++;
		return true;
	}
}

bool popQueue(Queue& q) {
	if (emptyQueue(q)) {
		return false;
	}
	else {
		for (int i = 0; i < q.size - 1; i++) {
			q.list[i] = q.list[i + 1];
		}
		q.size--;
	}
}

string Front(Queue q) {
	if (emptyQueue(q)) {
		return " ";
	}
	else {
		return q.list[0];
	}
}
