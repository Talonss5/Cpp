#include<iostream>
using namespace std;

class Stack {

private:

	int size, top, * S;

public:

	Stack(int size) {
		this->size = size;
		S =new int[size];
		top = -1;
	}

	friend ostream& operator<<(ostream &a, Stack &b) {
		for (int i = b.top; i >= 0; i--) {
			cout << b.S[i]<<endl;
			if (i != 0) {
				cout << "---" << endl;
			}
		}
		return a;
	}

	void push(int x) {
		if (top == size - 1) {
			cout << "Stack Overflow";
		}
		else {
			top++;
			S[top] = x;
		}
	}

	int pop() {
		int x = -1;
		if (top == -1) {
			cout << "Empty Stack";
		}
		else {
			top--;
			x = S[top];
		}
		return x;
	}

	int peek(int index) {
		if (top - index + 1 < 0) {
			cout << "Invalid index";
		}
		else {
			return S[top - index + 1];
		}
	}

	bool isEmpty() {
		if (top == -1) {
			return true;
		}
		return false;
	}

	bool isFull() {
		if (top == size - 1) {
			return true;
		}
		return false;
	}
};

int main() {
	Stack st = Stack(12);
	st.push(9);
	st.push(10);
	st.push(16);
	st.push(25);
	cout << st;
	return 0;
}