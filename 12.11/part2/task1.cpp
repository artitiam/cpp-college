#include <iostream> 
#include <iomanip>  
using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian"); // Устанавливаем русскую локаль для корректного вывода текста

  const int pizza_count = 4; // Количество видов пиццы
  const int drink_count = 3; // Количество видов напитков

  string pizza_names[pizza_count] = {"Маргарита", "Пепперони", "Гавайская", "Четыре сыра"}; // Названия пицц
  float pizza_prices[pizza_count] = {8.5, 9.5, 10.0, 11.0};                                 // Цены на пиццу

  string drink_names[drink_count] = {"Кола", "Сок", "Вода"}; // Названия напитков
  float drink_prices[drink_count] = {2.5, 3.0, 1.5};         // Цены на напитки

  int pizza_order[pizza_count] = {0}; // Количество заказанной пиццы (по каждому виду)
  int drink_order[drink_count] = {0}; // Количество напитков (по каждому виду)

  char cont; // Переменная для продолжения заказа
  do
  {
    cout << "Меню пиццы \n"; // Заголовок меню пиццы
    for (int i = 0; i < pizza_count; i++)
    {
      cout << (i + 1) << " - " << pizza_names[i] << " ($" << pizza_prices[i] << ")\n"; // Вывод пиццы с кодом
    }

    cout << "-----------------------\n";

    cout << "Меню напитков \n";           // Заголовок меню напитков
    for (int i = 0; i < drink_count; i++) // Исправлено условие цикла — иначе был выход за массив
    {
      cout << (i + 1 + pizza_count) << " - " << drink_names[i] << " ($" << drink_prices[i] << ")\n"; // Вывод напитков с кодом
    }

    cout << "-----------------------\n";

    cout << "Введите код товара: "; // Просим выбрать товар
    int code;
    cin >> code;

    if (code >= 1 && code <= pizza_count + drink_count) // Проверка корректности кода
    {
      cout << "Введите количество: "; // Сколько штук
      int quan;
      cin >> quan;

      if (code <= pizza_count)         // Если выбран товар с первой части меню — пицца
        pizza_order[code - 1] += quan; // Запоминаем заказ пиццы
      else
        drink_order[code - pizza_count - 1] += quan; // Запоминаем заказ напитков
    }
    else
    {
      cout << "Неверный код!\n"; // Сообщение при неверном вводе
    }

    cout << "Добавить ещё? (y/n): "; // Продолжение заказа
    cin >> cont;
  } while (cont == 'y' || cont == 'Y');

  cout << "-----------------------\n";

  cout << "ЧЕК \n";          // Заголовок чека
  float total = 0.0;         // Общая сумма заказа
  float drinks_total = 0.0;  // Сумма напитков дороже 2$
  int total_pizza_count = 0; // Общее количество пицц

  for (int i = 0; i < pizza_count; i++) // Перебор всех пицц
  {
    if (pizza_order[i] > 0) // Если пицца заказывалась
    {
      float cost = pizza_order[i] * pizza_prices[i];                                                              // Стоимость этого вида
      total += cost;                                                                                              // Добавляем в итог
      total_pizza_count += pizza_order[i];                                                                        // Считаем количество всех пицц
      cout << left << setw(20) << pizza_names[i] << setw(10) << pizza_order[i] << "$" << setw(8) << cost << endl; // Вывод строки чека
    }
  }

  for (int i = 0; i < drink_count; i++) // Перебор напитков
  {
    if (drink_order[i] > 0)
    {
      float cost = drink_order[i] * drink_prices[i]; // Стоимость напитков этого вида
      total += cost;                                 // В общий итог

      if (drink_prices[i] > 2.0) // Если напиток дорогой (>2$)
        drinks_total += cost;    // Добавляем в отдельную сумму

      cout << left << setw(15) << drink_names[i] << setw(10) << drink_order[i] << "$" << setw(8) << cost << endl;
    }
  }

  int free_pizzas = total_pizza_count / 5; // Каждая 5-я пицца бесплатно
  float min_pizza_price = pizza_prices[0]; // Находим минимальную цену пиццы
  for (int i = 1; i < pizza_count; i++)
    if (pizza_prices[i] < min_pizza_price)
      min_pizza_price = pizza_prices[i];

  float pizza_discount = free_pizzas * min_pizza_price; // Скидка по акции
  total -= pizza_discount;                              // Вычитаем скидку

  int expensive_drink_count = 0; // Количество дорогих напитков
  for (int i = 0; i < drink_count; i++)
    if (drink_prices[i] > 2.0)
      expensive_drink_count += drink_order[i];

  if (expensive_drink_count > 3) // Если больше 3 дорогих напитков
  {
    float drinks_discount = drinks_total * 0.15; // Скидка 15%
    total -= drinks_discount;                    // Вычитаем скидку
  }

  if (total > 50) // Если итог больше $50
    total *= 0.8; // Дополнительная скидка 20%

  cout << "Итого к оплате: $" << fixed << setprecision(2) << total << endl; // Вывод окончательного результата

  return 0; // Завершение программы
}
