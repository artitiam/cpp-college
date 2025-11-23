#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");

  const int pizza_count = 4;
  const int drink_count = 3;

  string pizza_names[pizza_count] = {"Маргарита", "Пепперони", "Гавайская", "Четыре сыра"};
  float pizza_prices[pizza_count] = {8.5, 9.5, 10.0, 11.0};

  string drink_names[drink_count] = {"Кола", "Сок", "Вода"};
  float drink_prices[drink_count] = {2.5, 3.0, 1.5};

  int pizza_order[pizza_count] = {0};
  int drink_order[drink_count] = {0};

  char cont;
  do
  {
    cout << "Меню пиццы \n";
    for (int i = 0; i < pizza_count; i++)
    {
      cout << (i + 1) << " - " << pizza_names[i] << " ($" << pizza_prices[i] << ")\n";
    }

    cout << "-----------------------\n";

    cout << "Меню напитков \n";
    for (int i = 0; i <= drink_count; i++)
    {
      cout << (i + 1 + pizza_count) << " - " << drink_names[i] << " ($" << drink_prices[i] << ")\n";
    }

    cout << "-----------------------\n";

    cout << "Введите код товара: ";
    int code;
    cin >> code;

    if (code >= 1 && code <= pizza_count + drink_count)
    {
      cout << "Введите количество: ";
      int quan;
      cin >> quan;

      if (code <= pizza_count)
        pizza_order[code - 1] += quan;
      else
        drink_order[code - pizza_count - 1] += quan;
    }
    else
    {
      cout << "Неверный код!\n";
    }

    cout << "Добавить ещё? (y/n): ";
    cin >> cont;
  } while (cont == 'y' || cont == 'Y');

  cout << "-----------------------\n";
  
  cout << "ЧЕК \n";
  float total = 0.0;
  float drinks_total = 0.0;
  int total_pizza_count = 0;

  for (int i = 0; i < pizza_count; i++)
  {
    if (pizza_order[i] > 0)
    {
      float cost = pizza_order[i] * pizza_prices[i];
      total += cost;
      total_pizza_count += pizza_order[i];
      cout << left << setw(20) << pizza_names[i] << setw(10) << pizza_order[i] << "$" << setw(8) << cost << endl;
    }
  }

  for (int i = 0; i < drink_count; i++)
  {
    if (drink_order[i] > 0)
    {
      float cost = drink_order[i] * drink_prices[i];
      total += cost;

      if (drink_prices[i] > 2.0)
        drinks_total += cost;

      cout << left << setw(15) << drink_names[i] << setw(10) << drink_order[i] << "$" << setw(8) << cost << endl;
    }
  }

  int free_pizzas = total_pizza_count / 5;
  float min_pizza_price = pizza_prices[0];
  for (int i = 1; i < pizza_count; i++)
    if (pizza_prices[i] < min_pizza_price)
      min_pizza_price = pizza_prices[i];

  float pizza_discount = free_pizzas * min_pizza_price;
  total -= pizza_discount;

  int expensive_drink_count = 0;
  for (int i = 0; i < drink_count; i++)
    if (drink_prices[i] > 2.0)
      expensive_drink_count += drink_order[i];

  if (expensive_drink_count > 3)
  {
    float drinks_discount = drinks_total * 0.15;
    total -= drinks_discount;
  }

  if (total > 50)
    total *= 0.8;

  cout << "Итого к оплате: $" << fixed << setprecision(2) << total << endl;

  return 0;
}
