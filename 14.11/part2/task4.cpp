#include <iostream>
using namespace std;

int main()
{
  cout << "Введите число A: ";
  int a;
  cin >> a;
  for (int i = 1; i < a; i++)
  {
    if ((a % (i * i) == 0) && !(a % (i * i * i) == 0))
    {
      cout << "-" << i << "\n";
      cout << i << "\n";
    }
  }

  return 0;
}