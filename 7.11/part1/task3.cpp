#include <iostream>
using namespace std;

int main()
{
  float distance, expend_hund, cost1, cost2, cost3, pet_con;
  cout << "Введите расстояние, расход бензина на 100км и стоимость трех видов бензина за литр: ";
  cin >> distance >> expend_hund >> cost1 >> cost2 >> cost3;
  pet_con = distance / 100 * expend_hund;  
  cost1 = cost1 * pet_con;
  cost2 = cost2 * pet_con;
  cost3 = cost3 * pet_con;
  cout << "Номер бензина" << "\t" << "Цена" << "\n";
  cout << "Бензин №1:" << "\t" << cost1 << "\n";
  cout << "Бензин №2:" << "\t" << cost2 << "\n";
  cout << "Бензин №3:" << "\t" << cost3 << "\n";

  return 0;
}