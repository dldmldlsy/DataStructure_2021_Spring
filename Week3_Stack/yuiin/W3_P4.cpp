////3���� 4������ 

//��ũ�� ����Ʈ�� �̿��� ���� 
#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};
class linkedStack {
public:
	Node* head;
	Node* tail;
	int n;
	linkedStack() {
		this->head = NULL;
		this->tail = NULL;
		this->n = 0;
	}
	int size() {
		return n;
	}
	bool empty() {
		return n == 0;
	}
	int top() {
		if (empty())return -1;
		else return head->data;
	}
	void push(int e) {
		Node* newNode = new Node(e);
		if (empty()) {
			head = tail = newNode;
			n++;
		}
		else {
			newNode->next = head;
			head = newNode;
			n++;
		}
	}
	int pop() {
		if (empty()) return -1;
		else {
			Node* temp = head;
			head = head->next;
			n--;
			return temp->data;
		}
	}
};
int main() {
	int n; // �׽�Ʈ���̽� ���� ����
	cin >> n; //�׽�Ʈ���̽� �� �Է¹���
	string s; //��ɾ� ���� ����
	for (int i = 0; i < n; i++) {
		cin >> s; // ��ɾ� �Է�
		int size = s.size(); // size()�Լ��� �̿��� ���ڿ� s�� ���̸� ���� size������ ����. 
		linkedStack aS; //���� Ŭ���� ��ü ����.
		for (int i = 0; i < size; i++) { //���ڿ����̸�ŭ �ݺ� 
			char si = s.at(i); // ���ڿ�s�� ���Ҹ� si�� ����  si=s[0], s[i], ... 
			if (si == '*') // ���������� ��� 
			{
				// �ΰ��� �ǿ����ڰ� �ʿ��ϹǷ� pop()�� �̿��� �ΰ��� �ǿ����ڸ� �����´�. 
				int b = aS.pop(); // pop�Լ��� �̿��� ���� ������ top�� ��ȯ�ؼ� a�� ���� 
				int a = aS.pop(); // �ι�°�� �ִ� ���� top�� �ǰ� �� top�� �� ��ȯ�ؼ� b�� ���� 
				int x =a * b; // �� ���� ����.
				aS.push(x);
			}
			else if (si == '+') // ��������
			{    
				int b = aS.pop(); 
				int a = aS.pop();
				int x = a + b; 
				aS.push(x);
			}
			else if (si == '-')
			{   // ab-=> a-b : ���ÿ� a-> b(top) ���� ����Ǿ������״� 
				int b = aS.pop(); 
				int a = aS.pop();
				int x = a - b; //���� pop�� �� ������ ������ �� ��ġ�Ѵ�. 
				aS.push(x);
			}
			else //�����ڰ� �ƴ� ���
			{
				int num = s[i] - '0';  // ���ڿ��� ����� ���ڸ� int������ �ٲ���. 
				aS.push(num); // ���ÿ� �ش� ���ڸ� ����. 
			}
		}
		cout << aS.pop() << endl; // ��ɾ �� ó���� �Ŀ� ����� ������ ���� pop�Ѵ�. 
	}
	return 0; 
}


////�迭�� �̿��� ����ǥ��� ���� ���� ���α׷�����
//#include <iostream>
//using namespace std;
//class arrStack {
//public:
//	int* arr;
//	int capacity; //�迭�� ũ��
//	int t; // top 
//
//	arrStack(int capacity) { //���� ����
//		this->capacity = capacity;
//		this->arr = new int[capacity];
//		this->t = -1;//ó���� top�� -1, �ϳ� ������0�� �ε������� �� ���������� ���� ������ �ε���=top
//	}
//	int size() { //�迭�� �ִ� ���Ұ��� 
//		return t + 1; //top+1
//	}
//	bool empty() { //������� Ȯ�� 
//		return t == -1; //top�� -1�̸� true��ȯ
//	}
//	int top() {
//		if (empty())return -1; //������� -1��ȯ
//		else return arr[t]; // �ε����� t�̸� top ���� ���� �ִ� ����!
//	}
//	void push(int e) {  //e��� ���Ҹ� �ֱ�
//		if (size() == capacity) //���� ���Ұ���=�迭ũ��
//			cout << "FULL" << endl; //full���
//		else arr[++t] = e; //�ƴϸ� t�ϳ� �÷��� �ű⿡ e����
//	}
//	int pop() { //�� �� ���� ���� 
//		if (empty())return -1; //������� -1���
//		return arr[t--]; //���� top����ϰ� t �ϳ� ���̱� ������ �� �������ϱ�! 
//	}
//};
//int main() {
//	int n;
//	cin >> n;
//	string s;
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		int size = s.size();
//		arrStack aS(size);
//		for (int i = 0; i < size; i++) {
//			char si = s.at(i);
//			if (si == '*')
//			{
//				int a = aS.pop();
//				int b = aS.pop();
//				int x = b * a;
//				aS.push(x);
//			}
//			else if (si == '+')
//			{
//				int a = aS.pop();
//				int b = aS.pop();
//				int x = b + a;
//				aS.push(x);
//			}
//			else if (si == '-')
//			{
//				int a = aS.pop();
//				int b = aS.pop();
//				int x = b - a;
//				aS.push(x);
//			}
//			else
//			{
//				int num = s[i] - '0';
//				aS.push(num);
//			}
//		}
//		cout << aS.pop() << endl;
//	}
//	return 0; 
//}