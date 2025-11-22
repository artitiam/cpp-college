#include <iostream>
using namespace std;

int main()
{
  float dist_ab, dist_bc, fuel_ab, fuel_bc, fuel_after_ab, additional_fuel;
  int weight, fuelRate;

  cout << "Введите расстояние A-B, расстояние B-C и вес груза: ";
  cin >> dist_ab >> dist_bc >> weight;

  if (weight > 2000)
  {
    cout << "Полет невозможен: самолет не поднимает такой груз." << endl;

    return 1;
  }

  if (weight <= 500)
    fuelRate = 1;
  else if (weight <= 1000)
    fuelRate = 4;
  else if (weight <= 1500)
    fuelRate = 7;
  else if (weight <= 2000)
    fuelRate = 9;

  fuel_ab = dist_ab * fuelRate;
  fuel_bc = dist_bc * fuelRate;

  if (fuel_ab > 300 || fuel_bc > 300)
  {
    cout << "Полет невозможен: недостаточно топлива для преодоления участка." << endl;
    return 0;
  }

  fuel_after_ab = 300 - fuel_ab;

  additional_fuel = fuel_bc - fuel_after_ab;

  if (additional_fuel < 0)
    additional_fuel = 0; 

  cout << "Минимальная дозаправка в пункте B: " << additional_fuel << " литров." << endl;

  return 0;
}
