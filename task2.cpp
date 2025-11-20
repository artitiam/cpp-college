#include <iostream>
using namespace std;

int main()
{
  float h1, m1, s1, h2, m2, s2, result;
  cout << "Введите начало и конец времени аренды скутера в формате часы минуты секунды: ";
  cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
  m1 = h1 * 60 + m1 + s1 / 60;
  m2 = h2 * 60 + m2 + s2 / 60;
  result = (m2 - m1) * 2;
  cout << "Стоимость аренды " << result <<  " гривен" << endl;

  return 0;
}