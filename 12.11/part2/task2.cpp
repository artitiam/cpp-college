#include <iostream>
using namespace std;

float calculate_salary(float sales)
{
  float percent = 0;

  if (sales < 500)
  {
    percent = 0.03;
  }
  else if (sales < 1000)
  {
    percent = 0.05;
  }
  else
  {
    percent = 0.08;
  }

  return 200 + sales * percent;
}

int main()
{
  float sales[3];
  float salary[3];

  cout << "\nВведите уровень продаж для 3 менеджеров:\n";
  for (int i = 0; i < 3; i++)
  {
    cout << "Менеджер " << i + 1 << ": ";
    cin >> sales[i];
    salary[i] = calculate_salary(sales[i]);
  }

  int best_index = 0;
  for (int i = 1; i < 3; i++)
  {
    if (sales[i] > sales[best_index])
    {
      best_index = i;
    }
  }

  salary[best_index] += 200;

  cout << "-----------------------";

  cout << "\nРезультаты:\n";
  for (int i = 0; i < 3; i++)
  {
    cout << "Менеджер " << i + 1 << ": Продажи = " << sales[i] << "$, Зарплата = " << salary[i] << "$";
    if (i == best_index)
    {
      cout << " (+премия)";
    }
    cout << endl;
  }

  cout << "\nЛучший менеджер: №" << best_index + 1 << endl;

  return 0;
}
