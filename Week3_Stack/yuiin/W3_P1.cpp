#include <iostream>
using namespace std;
class arrStack {
public:
	int* arr;
	int capacity; //�迭�� ũ��
	int t; // top 

	arrStack(int capacity) { //���� ����
		this->capacity = capacity;
		this->arr = new int[capacity];
		this->t = -1;//ó���� top�� -1, �ϳ� ������0�� �ε������� �� ���������� ���� ������ �ε���=top
	}
	int size() { //�迭�� �ִ� ���Ұ��� 
		return t + 1; //top+1
	}
	bool empty() { //������� Ȯ�� 
		return t == -1; //top�� -1�̸� true��ȯ
	}
	int top() {
		if (empty())return -1; //������� -1��ȯ
		else return arr[t]; // �ε����� t�̸� top ���� ���� �ִ� ����!
	}
	void push(int e) {  //e��� ���Ҹ� �ֱ�
		if (size() == capacity) //���� ���Ұ���=�迭ũ��
			cout << "FULL" << endl; //full���
		else arr[++t] = e; //�ƴϸ� t�ϳ� �÷��� �ű⿡ e����
	}
	int pop() { //�� �� ���� ���� 
		if (empty())return -1; //������� -1���
		return arr[t--]; //���� top����ϰ� t �ϳ� ���̱� ������ �� �������ϱ�! 
	}
};
int main() {
	int t, n;
	cin >>t>> n;
	string s;
	arrStack aS(t);
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "empty") {
			cout << aS.empty() << endl;
		}
		else if (s == "top") {
			cout << aS.top() << endl;
		}
		else if (s == "push") {
			int p;
			cin >> p;
			aS.push(p);
		}
		else if (s == "pop") {
			cout<<aS.pop()<<endl;
		}
		else
			cout << "���Է¹ٶ�." << endl;
	}

}
