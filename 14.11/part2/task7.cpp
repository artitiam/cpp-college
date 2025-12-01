#include <iostream>
using namespace std;

int main()
{
  cout << "Введите два целых числа: ";
  int a, b;
  cin >> a >> b;

  for (int i = 0; i < 2; i++)
  {
    for (int j = 1; j < a; j++)
    {
      if (a % j == 0)
      {
        cout << "-" << j << "\n";
        cout << j << "\n";
      }
    }
    a = b;
  }

  return 0;
}