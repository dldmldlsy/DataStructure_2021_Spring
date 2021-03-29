#include <iostream>
#include <string>
using namespace std;

// ��� Ŭ����(Stack Ŭ������ friend �Լ��� ����)
class Node {
private:
	int data;
	Node* next;
	friend class Stack;
};

<<<<<<< HEAD
// Stack Ŭ����
=======
//StackŬ����
>>>>>>> 748c32bee8e8b305ea82cd789c39ffd4de711be7
class Stack {
private:
	Node* head; // �� ���� ����Ű�� ������
	int Size; // ������ ũ��
	int max_size; // Array Stackó�� �۵��ϱ� ���� �ִ� ũ��
public:
	Stack(int t) :head(NULL), Size(0), max_size(t) {}; // head�� NULL�� Size�� 0���� max_size�� �Է°� t�� �ʱ�ȭ

<<<<<<< HEAD
	// size �Լ� 
=======
	//size �Լ� 
>>>>>>> 748c32bee8e8b305ea82cd789c39ffd4de711be7
	int size() {
		return Size;
	}

<<<<<<< HEAD
	// empty �Լ�
=======
	//empty �Լ�
>>>>>>> 748c32bee8e8b305ea82cd789c39ffd4de711be7
	bool empty() {
		return Size == 0;
	}

	// top �Լ�
	int top() {
		if (empty()) {
			return -1;
		}
		return head->data; // ���� �������� ����
	}

	// push �Լ�
	void push(int value) {
		Node* node = new Node; // �� ��带 ����
		node->data = value; // ��忡 �Ҵ�
		node->next = NULL;

		if (empty()) { // Stack�� ����ִ°��
			head = node;
			Size++;
		}
		else if (Size == max_size) { // Array Stackó�� �۵��ϱ� ���� �ִ� ����� �ִٰ� �����ϰ� ����� �ִ� ������� ���������� FULL�� ���
			cout << "FULL" << endl;
		}
		else { // Stack�� ������� ���� ���
			node->next = head;
			head = node;
			Size++;
		}
	}

	// pop �Լ�
	int pop() {
		if (empty()) {
			return -1;
		}
		Node* cur = head; // �޸� ������ �����Ϳ� ���� �޸��� �ּҸ� �Ҵ�
		int temp; // �� ����� int ����

		head = head->next; // head�� ��ĭ �Ʒ��� �Ű��ֱ�
		temp = cur->data; // ���� �޸��� ���� int������ �־��ֱ�

		Size--;
		delete cur; // �޸� ����
		return temp; // ����� �� ��ȯ
	}

	// print �Լ� (�� �־�� �ϴ°� �ƴ�)
	void print() {
		if (empty()) {
			cout << "Empty Error" << endl;
		}
		Node* cur = head; // ó������ ����
		while (cur != NULL) { // NULL ������ -> ������ ������
			cout << cur->data << endl; // ���� �����Ͱ� ����Ű���ִ� ����� ������ ���
			cur = cur->next; // ���� �����͸� ���� ���� �ٲٱ�
		}
	}
};

int main() {
	int t, N, data;
	string command;
<<<<<<< HEAD

	cin >> t >> N;
	Stack stack(t);

=======
	Stack stack(t);

	cin >> t >> N;
	
>>>>>>> 748c32bee8e8b305ea82cd789c39ffd4de711be7
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "size") {
			cout << stack.size() << endl;
		}
		else if (command == "empty") {
			cout << stack.empty() << endl;
		}
		else if (command == "top") {
			cout << stack.top() << endl;
		}
		else if (command == "push") {
			cin >> data;
			stack.push(data);
		}
		else if (command == "pop") {
			cout << stack.pop() << endl;
		}
		else if (command == "print") {
			stack.print();
		}
	}
}