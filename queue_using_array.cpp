#include <iostream>
using namespace std; 
#define capacity 100

class Queue {

	int arr[capacity];
	int rear, front , size;
public:
	Queue() {
		rear  = front = -1;
		size = 0;
	}
	void Enqueue(int val) {
		if (!isFull()) {
			rear = (rear + 1) % capacity;
			arr[rear] = val;
			++size;
		}
	}
	int Dequeue() {
		if (!isEmpty()) {
			front = (front + 1) % capacity;
			--size;
			return arr[front];
		}
	}

	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size == capacity - 1;
	}
	void display() {
		int temp = front;
		while (front != rear) {
			front = (front + 1) % capacity;
			cout << arr[front]<<" ";
		}
		cout << endl;
	}
	void clear() {
		size = 0;
	}

};

int main() {
	Queue Q;
	for (int i = 0; i <= 10; i++) {
		Q.Enqueue(i);
	}
	Q.display();

}
