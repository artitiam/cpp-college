#include <iostream> 
using namespace std;

int main()
{
  float dist_ab, dist_bc, fuel_ab, fuel_bc, fuel_after_ab, additional_fuel; // Переменные для расстояний и топлива
  int weight, fuelRate;                                                     // Переменные для веса груза и расхода топлива

  cout << "Введите расстояние A-B, расстояние B-C и вес груза: "; // Просим ввод данных
  cin >> dist_ab >> dist_bc >> weight;                            // Ввод

  if (weight > 2000) // Проверка максимальной грузоподъемности
  {
    cout << "Полет невозможен: самолет не поднимает такой груз." << endl; // Сообщение об ошибке
    return 1;                                                             // Завершение программы
  }

  if (weight <= 500) // Определяем расход топлива по весу
    fuelRate = 1;
  else if (weight <= 1000)
    fuelRate = 4;
  else if (weight <= 1500)
    fuelRate = 7;
  else if (weight <= 2000)
    fuelRate = 9;

  fuel_ab = dist_ab * fuelRate; // Количество топлива на участок A-B
  fuel_bc = dist_bc * fuelRate; // Количество топлива на участок B-C

  if (fuel_ab > 300 || fuel_bc > 300) // Проверка: хватает ли бака на каждый участок
  {
    cout << "Полет невозможен: недостаточно топлива для преодоления участка." << endl; // Если нет — вывод ошибки
    return 0;                                                                          // Прекращаем выполнение
  }

  fuel_after_ab = 300 - fuel_ab; // Топливо, оставшееся после перелета A-B

  additional_fuel = fuel_bc - fuel_after_ab; // Сколько топлива нужно дозаправить в B

  if (additional_fuel < 0) // Если топлива остаётся больше, чем нужно
    additional_fuel = 0;   // Дозаправка не требуется

  cout << "Минимальная дозаправка в пункте B: " << additional_fuel << " литров." << endl; // Вывод результата

  return 0; // Завершение программы
}
