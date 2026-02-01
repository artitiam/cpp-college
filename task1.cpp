#include <iostream>

class Integer
{
private:
    int value;

public:
    Integer() : value(0)
    {
        std::cout << "Объект Integer создан.\n";
    }

    void setValue(int val)
    {
        value = val;
    }

    int getValue() 
    {
        return value;
    }

    void printValue() 
    {
        std::cout << "Значение: " << value << "\n";
    }
};

int main()
{
    Integer obj;

    obj.setValue(42);

    std::cout << "Получено значение: " << obj.getValue() << "\n";

    obj.printValue();

    return 0;
}