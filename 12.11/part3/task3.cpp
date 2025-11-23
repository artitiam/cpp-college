#include <iostream>
using namespace std;

int main()
{
  int choice;
  float pay_per_100 = 50.0;
  float fine_every_3 = 20.0;

  cout << "Меню:\n";
  cout << "1. Расчет количества строк для желаемого дохода и опозданий\n";
  cout << "2. Расчет количества возможных опозданий\n";
  cout << "3. Расчет итоговой зарплаты\n";
  cout << "Выберите пункт меню: ";
  cin >> choice;

  switch (choice)
  {
  case 1:
  {
    float desired_income;
    int late_count;
    cout << "Введите желаемый доход ($): ";
    cin >> desired_income;
    cout << "Введите количество опозданий: ";
    cin >> late_count;

    int fines = (late_count / 3) * fine_every_3;
    float needed_income = desired_income + fines;

    float lines = (needed_income / pay_per_100) * 100.0;

    cout << "Васе нужно написать " << lines << " строк кода.\n";
    break;
  }
  case 2:
  {
    float lines;
    float desired_income;
    cout << "Введите количество строк кода: ";
    cin >> lines;
    cout << "Введите желаемую зарплату ($): ";
    cin >> desired_income;

    float base_income = (lines / 100.0) * pay_per_100;

    if (base_income < desired_income)
    {
      cout << "С таким количеством строк заработать нельзя.\n";
    }
    else
    {
      float desiavailable_for_finesred_income = base_income - desired_income;
      int possible_late = (desiavailable_for_finesred_income / fine_every_3) * 3;
      cout << "Вася может опоздать " << possible_late << " раз.\n";
    }

    break;
  }
  case 3:
  {
    float lines;
    int late_count;
    cout << "Введите количество строк кода: ";
    cin >> lines;
    cout << "Введите количество опозданий: ";
    cin >> late_count;

    float base_income = (lines / 100.0) * pay_per_100;
    float total_fines = (late_count / 3) * fine_every_3;
    float final_income = base_income - total_fines;

    if (final_income <= 0)
    {
      cout << "Васе ничего не заплатят.\n";
    }
    else
    {
      cout << "Васе заплатят " << final_income << " $.\n";
    }
    break;
  }
  default:
    cout << "Неверный пункт меню!\n";
  }

  return 0;
}
