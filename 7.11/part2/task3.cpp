#include <iostream>
using namespace std;

int main()
{
  int days, weeks, rem_days;
  cout << "Введите дни чтобы перевести их в полные недели и остаток дней: ";
  cin >> days;
  weeks = days / 7;
  rem_days = days % 7;
  cout << "Полные недели: " << weeks << "\n" << "Остаток дней: " << rem_days << endl;

  return 0;
}