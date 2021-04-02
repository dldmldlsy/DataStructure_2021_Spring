//Problem W1_P1: DS21_Week1_P1_F 
//ù�������� 1���������� (1�������� W1_P3)
//ù���� ����� min�̾��� ���������� max�� �ٲ��ö��! 
// �Ʒ��� max�� Ǯ���� 
// - 3/6

// 3/10


#include <iostream>
using namespace std;

class Array {
private:
	int* arr;
	int arrSize;
public:
	Array(int sz) {
		this->arrSize = sz;
		this->arr = new int[arrSize];
		for (int i = 0; i < sz; i++)
			arr[i] = 0;
	}

	int at(int idx) {
		return arr[idx];
	}

	void add(int idx, int value) {
		for (int i = arrSize - 2; i >= idx; i--)
			arr[i + 1] = arr[i];
		arr[idx] = value;
	}

	void remove(int idx) {
		for (int i = idx + 1; i < arrSize; i++)
			arr[i - 1] = arr[i];
		arr[arrSize - 1] = 0;
	}

	void set(int idx, int value) {
		arr[idx] = value;
		cout << value << endl;
	}

	void print() {
		for (int i = 0; i < arrSize; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	void find_max() {
		int max = arr[0];
		for (int i = 1; i < arrSize; i++) {
			if (arr[i] > max)
				max = arr[i];
			else
				max = max;
		}
		cout << max;
	}

};

int main()
{
	int n, t;
	int a, b;
	string sr;
	cin >> n >> t;
	Array arr(n);
	arr.print();
	for (int i = 1; i <= t; i++) {
		cin >> sr;
		if (sr == "find_max")
			arr.find_max();
		else if (sr == "print")
			arr.print();
		else if (sr == "add")
		{
			cin >> a >> b;
			arr.add(a, b);
		}
		else if (sr == "remove")
		{
			cin >> a;
			arr.remove(a);
		}
		else if (sr == "at")
		{
			cin >> a;
			arr.at(a);
		}
		else if (sr == "set")
		{
			cin >> a>> b;
			arr.set(a, b);
		}
		else
			cout << "�ٽ� �Է����ֽñ� �ٶ��ϴ�.";
		cout << endl;
	}
	return 0;
}