//#include <iostream>
//#include <string>
//using namespace std;
//
//class node {
//public:
//	int data;
//	node* next;
//	node(int data) {
//		this->data = data;
//		this->next = NULL;
//	}
//};
//class linkedlist {
//public:
//	node* front;
//	node* rear;
//
//	linkedlist() { //������ 
//		//front rear NULL�� �ʱ�ȭ
//		this->front = NULL;
//		this->rear = NULL;
//	}
//	void addend(int data) { //����Ʈ �ڿ� �߰��ϴ� �Լ�
//		node* newnode = new node(data); //�� ��� ����
//		if (front == NULL) //front�� null�̸� ��尡 ����ִٴ� ��
//			front = rear = newnode; //�� ��尡 front���� rear�� ��
//		else { //�� ����Ʈ�� �ƴҰ��
//			rear->next = newnode; //�ǵڳ�� rear�� ��ũ�ʵ尡 �� ��带 ����Ű�� �ϱ�( �ǵڿ� �Ŵ޾���!) 
//			rear = newnode; //rear(�� ������ ��带 ����Ű�� ������)�� �� ���� ����! 
//		} 
//	}
//	void removefront() { //�� �� ��带 �����ϴ� �Լ�
//		if (front != NULL) { //����Ʈ�� �������������  (����ִ� ���� �Ʒ� dequeue�Լ����� empty����ϵ��� �ص� )
//			node* tmp = front; //�� ����ϳ� ���� �� ��忡 ���� front�� �����ص� (tmp���� ���� �� �ճ���� ���� ����) 
//			front = front->next; //�� �� ��带 ����Ű�� front��尡 ���� �ι�° ��带 ����Ű�� ��
//			                     //(���� �ι�° ��尡 �Ǿճ�尡 �Ǵ� ��->�ڵ����� ���� �Ǿճ��� ����Ʈ���� ������) 
//			delete tmp; //tmp �޸� ���� 
//		} 
//	}
//};
//
//class linkedqueue {
//public:
//	linkedlist* q; //���Ḯ��Ʈ�� ����Ű�� ������ q
//	int n; //ť ���Ұ���
//
//	linkedqueue() { //���Ḯ��Ʈť ������
//		this->q = new linkedlist(); // ���Ḯ��Ʈ ��ü ����
//		this->n = 0; //���Ҽ� 0���� �ʱ�ȭ
//	}
//	int size() { //���� ��(����Ʈũ��) ���ϴ� �Լ�
//		return n;
//	}
//	bool isempty() { //������� 
//		return n == 0; //n�� 0�̸� ���Ұ� �����ϱ� ����ٴ� ��=> true��ȯ
//	}
//	void front() { //front 
//		if (isempty()) //ť�� ��������� 
//			cout << "empty" << endl; //empty���
//		else
//			cout<<(q->front->data)<<endl; 
//		//q�� front �� ������ ���
//	}
//	void rear() { //rear
//		if (isempty())cout << "empty" << endl; //������� empty���
//		else cout << q->rear->data << endl; //rear�� data��� 
//	}
//	void enqueue(int e) { //����(�ǵڿ� ����) 
//		q->addend(e); //�ڿ� �����߰��ϴ� addend (������q�� ����Ű�� ��ü�� ����Լ�)ȣ��
//		n++;
//	}
//	void dequeue() { //���� (�Ǿ� �� ����) 
//		if (isempty()) cout << "empty" << endl; //������� empty ��� (������ �� ����) 
//		else {
//			q->removefront(); //�տ��� ���� removefront�Լ� ȣ�� 
//			n--; //���Ұ��� �ϳ� ���̱� 
//		}
//	}
//};
//int main() {
//	int t;
//	cin >> t; //�׽�Ʈ ���̽� �Է�
//	
//	for (int i = 0; i < t; i++) { //�׽�Ʈ���̽���ŭ �ݺ�
//		int n; // ī�尳�� (�������� ���⼭�ϴ� �� �³�????->�´�!) 
//		cin >> n;  //ī�尳�� �Է¹���
//		linkedqueue aQ; //P1 ī��� (�����Ͱ�=ĳ����ü��) 
//		linkedqueue bQ; //P2 ī��� 
//		
//		for (int j = 0; j < n; j++) { //ī�� ���� ��ŭ �ݺ�
//			int x; 
//			cin >> x; //ü���� �Է¹޾Ƽ� 
//			aQ.enqueue(x); //ť�� ����. 
//		} //P1�� ü���� �־���
//		for (int m = 0; m < n; m++) { //ī�� ���� n��ŭ �ݺ�
//			int y; 
//			cin >> y; //ü���� �Է¹޾Ƽ� 
//			bQ.enqueue(y); //ť�� ����
//		} //P2�� ü���� �� �־���. 
//
//		int asum = 0, bsum = 0; //P1�� ����, P2�� ����
//		int  r, afd, bfd; //r: ü����, �ܷ� p1�� ü��, �ܷ� p2�� ü��
//		for (int k = 0; k < n; k++) {
//			afd = aQ.q->front->data; //front�� ������=�º��� ü��
//			bfd = bQ.q->front->data;
//			r = abs(afd - bfd); //�� ü���� ����ũ�� (����)
//			if (afd > bfd) { //P1�� ü���� �� ū ���
//				asum++; //P1�� ����+1
//				bQ.q->front->next->data += r; 
//				//�� ü���� ���� �ºο��� �� P2�� �ι�°�����Ͱ�(������ �ܷ� ��)�� ������
//			}
//			else if (afd < bfd) { //P2�� �̱� ���!
//				bsum++;
//				aQ.q->front->next->data += r;
//			}
//
//			//�º��� ü���� �����ش�
//			aQ.dequeue();
//			bQ.dequeue();
//		}
//
//		if (asum > bsum) { cout << asum << endl; } //P1�� ������ �� ū ��� P1�� ���� ���
//		else { cout << bsum << endl; } //P2�� �� ũ�ų� ����� ��� P2�� �������)
//	}
//	return 0;
//}