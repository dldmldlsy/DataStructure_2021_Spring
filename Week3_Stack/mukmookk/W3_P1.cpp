#include <iostream>
using namespace std;
 
class Stack{
private:
    int size;
    int _top;
    int* S;
public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    void display();
    int top();
};
 
Stack::Stack(int size)
{
    this->size = size;          // array를 통한 구현 -> 사이즈가 정해짐
    _top = -1;                  // top을 invalid하도록 초기화
    S = new int[size];          // 받은 사이즈 만큼 할당
}
 
Stack::~Stack()
{
    delete[] S;                 // 오브젝트 파괴
}
 
void Stack::push(int x)
{
    if (isFull())               // 더 이상 공간이 없다면
    {                           // stack Overflow 에러 발생
        cout << "FULL" << endl;
    }
    else
    {
        _top++;                 // 아니라면 top index를 증가시키고
        S[_top] = x;            // 배열에 대입
    }
}
 
int Stack::pop()
{
    int x = 1;                  // 제거할 값
    if (_top == -1)             // 값이 없다면
    {                           // stack underflow
        cout << "-1" << endl;
    }
    else
    {
        x = S[_top];            // 제거할 값 할당
        cout << x << endl;
        _top--;                 // 단순히 인덱스를 줄이는 것만으로 충분
    }
    return x;
}
 
//int Stack::peek(int index)
//{
//    int x = -1;
//    if (_top-index+1 < 0 || _top-index+1 == size)
//    {
//        cout << "Index error" << endl;
//    }
//    else
//    {
//        x = S[_top-index+1];
//    }
//    return x;
//}
 
int Stack::isFull()
{
    if (_top == size-1) // _top의 값이 허용하는 인덱스 끝에 있다면
    {
        return 1;       // return true
    }
    return 0;
}
 
int Stack::isEmpty()
{
    if (_top == -1)             // top이 초기 상태라면
    {
        cout << "1" << endl;    // return true
        return 1;
    }
    cout << "0" << endl;
    return 0;
}
 
void Stack::display()
{
    for (int i = _top; i >= 0; i--) // 순회하며 출력 (top -> bottom)
    {
        cout << S[i] << " ";
    }
    cout << endl;
}
 
int Stack::top()
{
    if (_top == -1)                 // top이 빈 경우 출력할 내용이 없으므로 에러
    {
        cout << "-1" << endl;
        return -1;
    }
    cout << S[_top] << endl;        // 아닌 경우 클래스의 멤버를 활용하여 출력
    return S[_top];
}

void interface(Stack st, int cases)
{
    string m;
    int value;
    while (cases > 0)
    {
        cin >> m;
        if (m == "empty")
            st.isEmpty();
        else if (m == "top")
            st.top();
        else if (m == "push")
        {
            cin >> value;
            st.push(value);
        }
        else if (m == "pop")
            st.pop();
        cin.ignore(INT_MAX, '\n');
        cases--;
    }
}
 
 
int main()
{
 
    int cases = 0;
    int st_size = 0;
    cin >> st_size >> cases;
 
    Stack stk(st_size);
 
    interface(st_size, cases);
    
 
    return 0;
}
