#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;
};

class Stack {

	Node* head = nullptr;

public:
	void push(int val) {
		if (!isFull()) {
			Node* temp = new Node();
			temp->value = val;
			temp->next = head;
			head = temp;
		}
	}
int pop() {
	if (!isEmpty()) {
		Node* temp = head;
		head = head->next;
		int val = temp->value;
		delete(temp);
		return val;
	}
}

void display() {
	Node* temp = head;
	while (temp) {
		cout << temp->value << " ";
		temp = temp->next;
	}
}

bool isEmpty() {
	return head == nullptr;
}
bool isFull() {
	return false;
}
void clear() {
	Node* temp = head;
	Node* prev ;
	while (temp) {
		prev = temp->next;
		delete(temp);
		temp = prev;
	}
}

};

int main() {
	Stack s;
	for (int i = 0; i <= 10; i++) {
		s.push(i);
	}
	s.display();
	s.clear(); 
	return 0;
}
