#include <iostream>
using namespace std;

int main()
{
  cout << "Введите целое число A: ";
  int a;
  cin >> a;

  for (int i = 1; i < a; i++)
  {
    if (a % i == 0)
    {
      cout << "-" << i << "\n";
      cout << i << "\n";
    }
  }

  return 0;
}