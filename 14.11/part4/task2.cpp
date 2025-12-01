#include <iostream>
using namespace std;

int main()
{
  cout << "Введите размер клетки на шахматной доске: ";
  int sizeSquare;
  cin >> sizeSquare;

  for (int line = 0; line < 6; line++)
  {
    for (int column = 0; column < 24; column++)
    {
      if ((line + column / sizeSquare) & 1)
      {
        cout << "*";
      }

      else
      {
        cout << "_";
      }
    }
    cout << "\n";
  }

  return 0;
}