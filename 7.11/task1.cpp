#include <iostream>
using namespace std;

int main() {
  float a, b, c;
  cout << "Введите расстояние в километрах до аэропорта и время за которое нужно доехать в минутах: ";
  cin >> a >> b;
  c = a / b * 60;
  cout << "км/ч: " << c << endl;

  return 0;
}