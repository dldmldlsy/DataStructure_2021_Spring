#include <iostream>
#include <string>
using namespace std;

// 노드 클래스(Stack 클래스를 friend 함수로 가짐)
class Node {
private:
	int data;
	Node* next;
	friend class Stack;
};

<<<<<<< HEAD
// Stack 클래스
=======
//Stack클래스
>>>>>>> 748c32bee8e8b305ea82cd789c39ffd4de711be7
class Stack {
private:
	Node* head; // 맨 위를 가리키는 포인터
	int Size; // 스택의 크기
	int max_size; // Array Stack처럼 작동하기 위한 최대 크기
public:
	Stack(int t) :head(NULL), Size(0), max_size(t) {}; // head를 NULL로 Size를 0으로 max_size를 입력값 t로 초기화

<<<<<<< HEAD
	// size 함수 
=======
	//size 함수 
>>>>>>> 748c32bee8e8b305ea82cd789c39ffd4de711be7
	int size() {
		return Size;
	}

<<<<<<< HEAD
	// empty 함수
=======
	//empty 함수
>>>>>>> 748c32bee8e8b305ea82cd789c39ffd4de711be7
	bool empty() {
		return Size == 0;
	}

	// top 함수
	int top() {
		if (empty()) {
			return -1;
		}
		return head->data; // 제일 위에값을 리턴
	}

	// push 함수
	void push(int value) {
		Node* node = new Node; // 새 노드를 만듦
		node->data = value; // 노드에 할당
		node->next = NULL;

		if (empty()) { // Stack이 비어있는경우
			head = node;
			Size++;
		}
		else if (Size == max_size) { // Array Stack처럼 작동하기 위해 최대 사이즈가 있다고 가정하고 사이즈가 최대 사이즈와 같아졌으면 FULL을 출력
			cout << "FULL" << endl;
		}
		else { // Stack이 비어있지 않은 경우
			node->next = head;
			head = node;
			Size++;
		}
	}

	// pop 함수
	int pop() {
		if (empty()) {
			return -1;
		}
		Node* cur = head; // 메모리 해제용 포인터에 지울 메모리의 주소를 할당
		int temp; // 값 저장용 int 변수

		head = head->next; // head를 한칸 아래로 옮겨주기
		temp = cur->data; // 지울 메모리의 값을 int변수에 넣어주기

		Size--;
		delete cur; // 메모리 해제
		return temp; // 저장된 값 반환
	}

	// print 함수 (꼭 있어야 하는건 아님)
	void print() {
		if (empty()) {
			cout << "Empty Error" << endl;
		}
		Node* cur = head; // 처음부터 시작
		while (cur != NULL) { // NULL 전까지 -> 마지막 값까지
			cout << cur->data << endl; // 현재 포인터가 가리키고있는 노드의 데이터 출력
			cur = cur->next; // 현재 포인터를 다음 노드로 바꾸기
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