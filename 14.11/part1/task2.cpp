#include <iostream>
using namespace std;

int main()
{
  int y, x = 0;
  cout << "Введите x и y: ";
  cin >> x >> y;
  int a = x;
  for (int i = 1; i < y; i++)
  {
    x = x * a;
  }

  cout << x << endl;

  return 0;
}