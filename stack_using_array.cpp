#include <iostream>
#include <string>
using namespace std;
#define capacity 100

class Stack {
public:
	int arr[capacity];
	int top;
	Stack() {
		this->top = 0;
	}
	void push(int value) {
		if (IsFull())
			cout << "Stack overflow" << endl;
		else
			arr[top++] = value; // 
	}
	int pop() {
		if (IsEmpty()) {
			cout << "Stack is Empty" << endl;
		}
		else
			return arr[--top];
	}
	bool IsFull() {
		return top >= capacity;
	}
	bool IsEmpty() {
		return top <= 0;
	}
	int size() {
		return top;
	}
	void display() {
		for (int i = 0; i < top; i++) {
			cout << arr[i] << " " ;
		}
		cout << endl; 
	}
	int peek() {
		return arr[top - 1];
	}

	void clear() {
		top = 0; 
	}
};
void main() {
	Stack s;
	for (int i = 0; i < 10; i++) {
		s.push(i);
	}
	cout << "The elements in the stack = ";
	s.display();
	cout<<"The top element =  "<<s.peek()<<endl;
	cout << "The size of the stack = " << s.size();
}
