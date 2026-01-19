#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Введите делимое и делитель: ";
    cin >> a >> b;

    if (b == 0)
    {
        cout << "Деление на ноль невозможно!";
        return 0;
    }

    int quotient = 0;
    int remainder = a;

    while (remainder >= b)
    {
        remainder -= b;
        quotient++;
    }

    cout << "Частное: " << quotient << endl;
    cout << "Остаток: " << remainder << endl;

    return 0;
}
