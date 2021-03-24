#include <iostream>

class Array
{
private:
    int *arr;
    int arrSize;
public:
    Array(int _size)
    {
        this->arrSize = _size;
        this->arr = new int [this->arrSize];
        for (int i{0}; i < this->arrSize; i++)
            arr[i] = 0;
    }
    
    int at(int index)
    {
        return this->arr[index];
    }
    
    void add(int index, int value)
    {
        for (int i {this->arrSize - 2}; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = value;
    }
    
    void set(int index, int value)
    {
        arr[index] = value;
    }
    
    void print()
    {
        for (int i{0}; i < arrSize; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    
    void remove(int index)
    {
        for (int i {index + 1}; i < arrSize; i++)
        {
            arr[i - 1] = arr[i];
        }
        arr[arrSize - 1] = 0;
    }
    
    void find_min()
    {
        int min;
        int index;
        
        index = 0;
        min = arr[0];
        while(index++ < arrSize)
        {
            if (arr[index] < min)
            {
                min = arr[index];
            }
        }
        std::cout << min << "\n";
    }
    
    void del()
    {
        delete[] arr;
    }
};


int main(int argc, const char * argv[]) {
    int cases;
    int arrSize;
    int shifts;
    int item;
    int index;
    
    index = 0;
    item = 0;
    std::cin >> cases;  //  3
    while (cases > 0)
    {
        std::cin >> arrSize;    // 10
        Array arr(arrSize);
        Array temp_arr(arrSize);
        std::cin >> shifts;     // 3
        shifts = shifts % arrSize;
        while (index < arrSize)
        {
            std::cin >> item;
            arr.set(index, item);
            index++;
        }

        for (int i = 0; i < arrSize; i++)
        {
            if (i < shifts)
                temp_arr.set(arrSize - shifts + i, arr.at(i));
            else
                temp_arr.set(i - shifts, arr.at(i));
        }
        temp_arr.print();
        std::cin.clear();
        std::cin.ignore(255, '\n');
        index = 0;
        arr.del();
        temp_arr.del();
        
        cases--;
    }
    return 0;
}

