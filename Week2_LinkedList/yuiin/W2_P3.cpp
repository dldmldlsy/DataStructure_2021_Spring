#include <iostream>
using namespace std;
class Node { //��� 
	int elem; //�������ʵ�
	Node* next; //��ũ�ʵ� 

	friend class S_LinkedList; 
};

class S_LinkedList {
public:
	S_LinkedList();
	int List_size();
	bool Empty();
	void Print();
	void Append(int elem);
	int Delete(int idx);
	void Insert(int idx, int elem);
	void Min();


private:
	Node* head;
	Node* tail;
};
S_LinkedList::S_LinkedList() { // ������
	head = new Node; //��� ����
	tail = new Node; //���� ����

	head = NULL; //�ΰ����� �ʱ�ȭ 
	tail = NULL; //�ΰ����� �ʱ�ȭ 
}
bool S_LinkedList::Empty() { //�������Ȯ��
	return (head == NULL && tail == NULL); //�Ѵ� �ΰ��̸� true ���
}
int S_LinkedList::List_size() { //����Ʈ ũ�� ����Լ�
	int list_size = 0;
	if (Empty()) {
		return list_size;
	}

	else {
		Node* cur_node = head; //�����带 ����Ű�� cur_node ���� + ���� �ʱ�ȭ 
		while (cur_node->next != NULL) {  // �����Ʈ�� ��ũ�ʵ尡 null�϶����� �ݺ� (null�ϰ�� tail�ٷ� �� ���Ҷ�� ��) 
			list_size++;
			cur_node = cur_node->next;
		}
		list_size++; //tail 
		return list_size;
	}
}
void S_LinkedList::Print() { //����Ʈ ���� ����Լ� 
	if (Empty())
		cout << "empty" << endl;
	else { 
		Node* cur_node = head;
		while (cur_node->next != NULL) {
			cout << cur_node->elem << " "; 
			cur_node = cur_node->next;
		}
		cout << cur_node->elem << endl;
	}
}
void S_LinkedList::Append(int elem) { //�������� ���� �߰� 
	Node* new_node = new Node; 
	new_node->elem = elem;
	new_node->next = NULL;

	if (Empty()) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = tail->next;
	}
	Print();
}
int S_LinkedList::Delete(int idx) { //�ε������� �����ϰ� ���
	int removeNum = 0; //������ ���Ұ� �����ϴ� ����
	int cnt = 0;
	Node* cur_node;
	Node* pre_node;

	if (Empty() || List_size() <= idx) {
		return -1;
	}

	if (idx == 0) {
		if (List_size() == 1) {
			removeNum = head->elem; 
			tail = NULL;
			head = NULL;
		}
		else {
			cur_node = head;
			removeNum = cur_node->elem;
			head = cur_node->next;
		}
	}
	else {
		pre_node = cur_node = head;
		while (cnt != idx) {
			pre_node = cur_node;
			cur_node = cur_node->next;
			cnt++;
		}
		removeNum = cur_node->elem;
		pre_node->next = cur_node->next;

		if (cur_node == tail) {
			tail = pre_node;
		}
	}
	return removeNum;
}
void S_LinkedList::Insert(int idx, int elem) { 
	Node* new_node = new Node; //�� ��� ����
	new_node->elem = elem; //�� ��忡 �������ʵ尪 ����

	Node* pre_node; 
	Node* cur_node;
	int cur_idx = 0;
	if (idx == 0) { //�Ǿտ� �����߰���
		if (Empty()) { 
			head = new_node;
			tail = new_node;
		}
		else {
			new_node->next = head;
			head = new_node;
		}
		Print(); 
	}
	else if (idx>List_size()) {
		cout << "Index Error" << endl;
	}
	else if (idx == List_size()) {
		Append(elem);
	}
	else {
		pre_node = cur_node = head;
		while (cur_idx != idx) {
			pre_node = cur_node;
			cur_node = cur_node->next;
			cur_idx++;
		}
		pre_node->next = new_node;
		new_node->next = cur_node;
		Print();
	}
}
void S_LinkedList::Min() {
	if (Empty())
		cout << "empty" << endl;
	else
	{
		Node* cur_node = head->next;
		int min = head->elem;
		while (cur_node->next != NULL) {
			if (min > cur_node->elem)
				min = cur_node->elem;
			cur_node = cur_node->next;
		}
		if (tail->elem < min)
			min = tail->elem;

		cout << min << endl; 
	}
}

int main() {
	int m;
	cin >> m; //�׽�Ʈ���̽� �Է�
	string n; 
	S_LinkedList sl; //���Ͽ��Ḯ��ƮŬ���� ��ü ����
	for (int i = 0; i < m; i++) {  //�׽�Ʈ���̽���ŭ �ݺ�
		cin >> n; //��ɾ� �Է�
		if (n == "Print") {  
			sl.Print();
		}
		else if (n == "Min") {
			sl.Min();
		}
		else if (n == "Delete") {
			int a;
			cin >> a;
			cout << sl.Delete(a) << endl;
		}
		else if (n == "Append") {
			int a;
			cin >> a;
			sl.Append(a);
		}
		else if (n == "Insert") {
			int a, b;
			cin >> a >> b;
			sl.Insert(a, b);
		}
		else
			cout << "�ٽ� �Է��ϼ���." << endl;
	}

}
