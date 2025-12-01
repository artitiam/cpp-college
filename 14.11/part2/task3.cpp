#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int lastNum, newNum = 0;
  cout << "Введите любое целое число чтобы убрать из него 3 и 6: ";
  int num;
  cin >> num;
  for (int i = 0; 0 < num;)
  {
    lastNum = num % 10;
    if ((lastNum != 3) && (lastNum != 6))
    {
      newNum = newNum + lastNum * pow(10, i);
      i++;
    }

    num = num / 10;
  }

  cout << "Новое число: " << newNum << endl;

  return 0;
}