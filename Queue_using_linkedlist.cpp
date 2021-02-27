#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;
};
class Queue {

	Node* rear;
	Node* front;
	int size;

public:
	Queue() {
		rear  = nullptr;
		front = nullptr;
		size  = 0;
	}

	void Enqueue(int val) {
		Node* temp  = new Node();
		temp->value = val;
		if (isEmpty()) {
			front = temp;
		}
		else {
			rear->next = temp;
		}
			rear = temp;
			++size;
	}

	int Dequeue() {
		if (!isEmpty()) {
			Node* temp = front;
			front = front->next;
			int val = temp->value;
			delete(temp);
			--size;
			return val;
		}
		else
			cout << "Queue is Empty" << endl;
	}

	bool isEmpty() {
		return size == 0; 
	}

	void display() {
		Node* temp = front;
		while (temp) {
			cout << temp->value<<" ";
			temp = temp->next;
		}
		cout << endl;
	}
	void clear() {
		Node* temp = front;
		Node* prev;
		while (temp) {
			prev = temp->next;
			delete(temp);
			temp = prev;
		}
	}


};

int main() {
	Queue Q;
	for (int i = 0; i <= 10; i++) {
		Q.Enqueue(i);
	}
	Q.display();
	for (int i = 0; i <= 10; i++) {
		cout<<Q.Dequeue()<<" ";
	}
	Q.clear();

	return 0;
}
