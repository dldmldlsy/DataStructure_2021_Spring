#include <iostream>
using namespace std;
class Node {
	int data;
	Node* pre;
	Node* next;

	friend class D_LinkedList;
};
class D_LinkedList {
public:
	D_LinkedList();
	void Print();
	void Append(int x);
	int Delete(int idx);
	void Print_reverse();
	void Sum();

private:
	int listSize;
	Node* head;
	Node* tail;
};
D_LinkedList::D_LinkedList() {
	listSize = 0;

	//head = new Node;
	//tail = new Node;

	head = NULL;
	tail = NULL;
}
void D_LinkedList::Print() {
	if (listSize == 0) {
		cout << "empty" << endl;
		return;
	}

	Node* cur_node = head;
	while (cur_node->next != NULL) {
		cout << cur_node->data << " ";
		cur_node = cur_node->next;
	}
	cout << cur_node->data << endl;
}
void D_LinkedList::Append(int x) {
	Node* newNode = new Node();
	newNode->data = x;

	if (listSize == 0) {
		head = newNode;
		tail = newNode;
		listSize++;
		Print();
		return;
	}
	
	newNode->pre = tail;
	newNode->next = NULL;

	tail->next = newNode;
	tail = tail->next;
	listSize++;
	Print();
}
int D_LinkedList::Delete(int idx) {
	if (listSize == 0 || listSize <= idx) {
		return -1;
	}
	if (listSize == 1) {
		int num = head->data;
		head = NULL;
		tail = NULL;
		listSize--;
		return num;
	}
	Node* cur_node = head;
	//��� ������
	if (idx == 0) {
		int num = head->data;
		head = head->next;
		listSize--;
		return num;
	}

	//�Ϲ����ΰ��
	for (int i = 0; i < idx; i++) {
		cur_node = cur_node->next;
	}
	//���ϻ�����
	if (idx == (listSize - 1)) {
		int num = tail->data;
		cur_node->pre->next = NULL;
		tail = cur_node->pre;
		listSize--;
		return num;
	}

	cur_node->pre->next = cur_node->next;
	cur_node->next->pre = cur_node->pre;
	listSize--;
	return cur_node->data;
}
void D_LinkedList::Print_reverse() {
	if (listSize == 0) {
		cout << "empty" << endl;
		return;
	}

	Node* cur_node = tail;
	while (cur_node->pre != NULL) {
		cout << cur_node->data << " ";
		cur_node = cur_node->pre;
	}
	cout << cur_node->data <<endl;
}
void D_LinkedList::Sum() {
	int sum = 0;

	Node* cur_node = head;
	while (cur_node != NULL) {
		sum += cur_node->data;
		cur_node = cur_node->next;
	}
	cout << sum << endl;
}
int main() {
	int m;
	cin >> m; //�׽�Ʈ���̽� �Է�
	string n;
	D_LinkedList sl; //���Ͽ��Ḯ��ƮŬ���� ��ü ����
	for (int i = 0; i < m; i++) {  //�׽�Ʈ���̽���ŭ �ݺ�
		cin >> n; //��ɾ� �Է�
		if (n == "Print") {
			sl.Print();
		}
		else if (n == "Append") {
			int a;
			cin >> a;
			sl.Append(a);
		}
		else if (n == "Delete") {
			int a;
			cin >> a;
			cout << sl.Delete(a) << endl;
		}
		else if (n == "Print_reverse") {
			sl.Print_reverse();
		}
		else if (n == "Sum") {
			sl.Sum();
		}
		else
			cout << "�ٽ� �Է��ϼ���." << endl;
	}
	return 0;
}