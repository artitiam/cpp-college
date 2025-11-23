#include <iostream> 
using namespace std;

int main()
{
  int num1, num2, num3, num4, num5, num6, num7, max_num; // Объявляем 7 чисел и переменную для максимального

  cout << "Введите 7 целых чисел: ";                           // Сообщение пользователю
  cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7; // Ввод всех чисел подряд

  if (num1 < num2) // Сравниваем num1 и num2
  {
    max_num = num2; // Если num2 больше — записываем его в max_num
  }
  else
  {
    max_num = num1; // Иначе в max_num будет num1
  }

  if (max_num < num3) // Сравниваем текущий максимум с num3
  {
    max_num = num3; // Если num3 больше — обновляем максимум
  }

  if (max_num < num4) // Сравниваем с num4
  {
    max_num = num4;
  }

  if (max_num < num5) // Сравниваем с num5
  {
    max_num = num5;
  }

  if (max_num < num6) // Сравниваем с num6
  {
    max_num = num6;
  }

  if (max_num < num7) // Сравниваем с num7
  {
    max_num = num7;
  }

  cout << "Самое большое число: " << max_num << endl; // Выводим результат

  return 0; // Завершаем программу
}
