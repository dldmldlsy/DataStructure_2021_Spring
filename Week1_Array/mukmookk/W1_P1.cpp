#include <iostream>
#include <string>

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
        std::cout << this->arr[index] << "\n";
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
        std::cout << value << "\n";
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
    
    int find_max() {
        int max = arr[0];
        for (int i = 1; i < size; i++) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        return max;
    }
};

void command_interface(Array arr, std::string command)
{
    int index;
    int value;
    
    index = -1;
    if (command == "find_min")
        arr.find_min();
    else if (command == "print")
        arr.print();
    else if (command == "add")
    {
        std::cin >> index;
        std::cin >> value;
        arr.add(index, value);
    }
    else if (command == "remove")
    {
        std::cin >> index;
        arr.remove(index);
    }
    else if (command == "at")
    {
        std::cin >> index;
        arr.at(index);
    }
    else if (command == "set")
    {
        std::cin >> index;
        std::cin >> value;
        arr.set(index, value);
    }
    else
        std::cout << "Wrong command" << "\n";
}

int main(int argc, const char * argv[]) {
    int N;
    int cases;
    std::string command;
    
    std::cin >> N;
    std::cin >> cases;
    Array arr{N};

    while (cases > 0)
    {
        std::cin >> command;
        command_interface(arr, command);
        std::cin.ignore(255, '\n');
        std::cin.clear();
		cases--;
    }
    return 0;
}

