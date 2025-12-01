#include <iostream>
using namespace std;

int main()
{
  cout << "Введите число от 1 до 20: ";
  long num;
  cin >> num;

  for (int i = num; i <= 20; i++)
  {
    cout << i << " ";
    num *= i;
    cout << num << "\n";
  }
  cout << "Произведение чисел от " << num << " до 20" << endl;

  return 0;
}