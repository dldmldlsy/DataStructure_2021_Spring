//#include <iostream>
//using namespace std;
//class arrq { //�迭�� ������ ����ťŬ����
//private:
//	int* q; //������������ ����ų ������ ť 
//	int rear; //������ 
//	int front;// �Ǿ� 
//	int capacity;//ť�� ũ�� 
//
//public:
//	arrq(int capacity) { //������ (
//		this->capacity = capacity + 1; //����ť�̹Ƿ�, ���� �ϳ� �� �ʿ�  (�� ����ť�ϱ� �ϳ��� �� �ʿ��Ѱ�!!) 
//		q = new int[this->capacity];  // ������ ���Ҽ� +1 ��ŭ �����Ҵ� 
//		front = rear = 0; //ó���� �ε��� 0������ �Ѵ� ����.
//
//		for (int i = 0; i < capacity; i++) {
//			q[i] = 0; //�� 0���� �ʱ�ȭ 
//		}
//	}
//	void enqueue(int value) { // rear�� ����! 
//		if (isfull()) { //�迭�� ��á�ٸ�
//			cout << "Full" << endl; //full���
//		}
//		else {
//			rear = (rear + 1) % capacity;  //rear�� ���������� �̵�
//			q[rear] = value; //rear�� �� �Է�
//		}
//	}
//
//	void dequeue() {
//		if (isempty()) // �迭�� ����ִٸ� 
//			cout << "empty" << endl; //empty���
//		else {
//			cout << q[front+1] << endl;
//			front = (front + 1) % capacity;//front�� ���������� �̵�
//			q[front] = 0; //
//		}
//	}
//	void _front() {
//		if (isempty())cout << "empty" << endl;
//		else cout << q[(front + 1) % capacity] << endl; //front �����ʰ� ���
//	}
//	void _rear() {
//		if (isempty())cout << "empty" << endl;
//		else cout << q[rear] << endl;
//	}
//	int size() { //������� ����� ���� ����
//		return (rear - front + capacity) % capacity; //�� rear-front�� �ƴ��� (ex. 1-5=-4(x) 1-5+7=3(0)
//	}
//
//	bool isfull() {
//		return front == (rear + 1) % capacity;
//	}
//	bool isempty() {
//		return front == rear;
//	}
//};
//int main() {
//	int n, t;
//	cin >> n >> t;
//	arrq aq(n);
//	string s;
//	int a;
//	for (int i = 0; i < t; i++) {
//		cin >>s ;
//		if (s == "isEmpty") {
//			cout<<boolalpha<<aq.isempty()<<endl; //true�� ��µǴµ� �������â�� True ! =>�����.
//		}
//		else if (s == "size") {
//			cout<<aq.size()<<endl;
//		}
//		else if (s == "dequeue") {
//			aq.dequeue();
//		}
//		else if (s == "enqueue") {
//			cin >> a;
//			aq.enqueue(a);
//		}
//		else if (s == "front") {
//			aq._front();
//		}
//		else if (s == "rear") {
//			aq._rear();
//		}
//		else
//			cout << "�ٽ� �Է����ּ���." << endl;
//
//
//	}
//}