//��ũ�� ����Ʈ�� �̿��� ���� 

#include <iostream>
using namespace std;
class Node { // ���Ŭ���� ���� 
public:
	int data; //�������ʵ� 
	Node* next; //��ũ�ʵ�

	Node(int e) { //���Ŭ���� ������ (��ü ������ �ڵ� ����) 
		this->data = e; // �μ����� �ش� Ŭ������ü�� �������ʵ忡 ����
		this->next = NULL; // ���� ��带 ����Ű�� ��ũ�ʵ尪�� null������ �α� 
	}
};
class linkedStack { //��ũ�帮��Ʈ�� �̿��� ���� Ŭ����
public:
	Node* head; //ù ��带 ����ų ���������
	Node* tail; //������ ��带 ����ų ���� ������
	int n; // ������ size�� ������ ����
	linkedStack() { // ����Ʈ������ 
      // ���� ������ null�� �ʱ�ȭ 
		this->head = NULL; 
		this->tail = NULL;
		this->n = 0; //����ũ�� 0���� �ʱ�ȭ
	}
	int size() { // ����ũ�� ��ȯ�ϴ� �޼���
		return n; // n��ȯ
	}
	bool empty() { // ��������Ȯ���ϴ� �޼���
		return n == 0; // ����ũ�⸦ ���ϴ� n�� 0�̸� true�� ��ȯ
	}
	int top() { // top (����� ����)�� �����͸� ��ȯ�ϴ� �޼���
		if (empty())return -1; // ������ ��������� -1 ��ȯ
		else return head->data; // ������������� top�� ù ����� �����Ͱ��� ��ȯ�Ѵ�. 
	}
	void push(int e) { //���ÿ� �����͸� �߰��ϴ� push �޼���, �� �����Ͱ�= e
		Node* newNode = new Node(e); // ���ο� ��带 ����. 
		if (empty()) { // ������ ����ִٸ� �� ��尡 ù��°���� ������ ����̹Ƿ� 
			head = tail = newNode; // ���� ���Ͽ� �� ��带 ����
			n++; // ���� ũ�� +1
		}
		else { //��������ʴٸ� �� ���� �Ǿտ��� �տ� �߰��ǹǷ� ��尡 �� ���� �ٲ�
			newNode->next = head; // �� ����� �������� ��带 �����ϴ� ��ũ�ʵ忡 ���� ��尡 ����� 
			head = newNode; // ���� ����带 ����Ŵ.
			n++; // ���� ũ�� +1
		}
	}
	int pop() { // ���� ���� �ִ� (���������� ��) ���Ҹ� ������ �޼���
		if (empty()) return -1; // ��������� -1 ��ȯ
		else { // �������������
			Node* temp = head; //��带 ����Ű�� ������ ���� temp�� �����ͺ��� head ����.  ������ ���� temp�� head�� ����Ű�� ������ ù��° ��带 ����Ű�� �ȴ�. 
                             // ù��°��带 ���ÿ��� ������ �ι�°���Ұ� head�� �� �ǵ� �Ŀ� �̸� ��ȯ�ؾ��ϱ⶧���� �� ��带 ����Ű�� �ٸ� �����ͺ����� �̸� ����� ��.
			head = head->next;  // �����ͺ��� head�� ��������� ���� ��带 ����Ŵ. 
			n--; // top�� pop�Ǿ����Ƿ�  ���� ũ�� -1
			return temp->data; // �Ǿտ� �ִ� ��带 ����Ű�� temp�� ���� �� �� ����� �����Ͱ��� ��ȯ�ϵ��� ��. 
		}
	}
};
int main() {
	int n; // �׽�Ʈ���̽��� ������ ����
	cin >> n; // �׽�Ʈ���̽� �Է�
	string s; // ��ɾ ��� ���� ����
	linkedStack aS; // ����Ŭ������ ��ü aS ���� ( �����ڰ� �����ؼ� head, tail�� null, ����size��0���� �ʱ�ȭ��) 

	for (int i = 0; i < n; i++) { //�׽�Ʈ���̽� �� ��ŭ �ݺ�
		cin >> s; // ��ɾ� �Է� 
		if (s == "empty") {  
			cout << aS.empty() << endl; //��ȯ���� �ִ� �Լ��⶧���� cout�� ���� ��ȯ���� ��½�Ŵ.
		}
		else if (s == "top") {  
			cout << aS.top() << endl;//��ȯ���� �ִ� �Լ��⶧���� cout�� ���� ��ȯ���� ��½�Ŵ.
		}
		else if (s == "push") {
			int p;
			cin >> p; //push �� �����Ͱ��Է� push�Լ��� ����
			aS.push(p);
		}
		else if (s == "pop") {
			cout << aS.pop() << endl; //��ȯ���� �ִ� �Լ��⶧���� cout�� ���� ��ȯ���� ��½�Ŵ.
		}
		else
			cout << "���Է¹ٶ�." << endl;
	}

}

//#include <iostream>
//using namespace std;
//class arrStack {
//public:
//	int* arr;
//	int capacity; //�迭�� ũ��
//	int t; // top 
//
//	arrStack(int capacity) { //���� ������ (���밡�� ũ�⸦ �μ��ιޱ�) 
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
//	arrStack aS(1000);
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		if (s == "empty") {
//			cout << aS.empty() << endl;
//		}
//		else if (s == "top") {
//			cout << aS.top() << endl;
//		}
//		else if (s == "push") {
//			int p;
//			cin >> p;
//			aS.push(p);
//		}
//		else if (s == "pop") {
//			cout<<aS.pop()<<endl;
//		}
//		else
//			cout << "���Է¹ٶ�." << endl;
//	}
//
//}



