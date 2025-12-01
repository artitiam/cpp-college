#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

void drawDice(int value)
{
  switch (value)
  {
  case 1:
    cout << "┌─────────┐" << "\n";
    cout << "│         │" << "\n";
    cout << "│    ●    │" << "\n";
    cout << "│         │" << "\n";
    cout << "└─────────┘" << "\n";
    break;
  case 2:
    cout << "┌─────────┐" << "\n";
    cout << "│ ●       │" << "\n";
    cout << "│         │" << "\n";
    cout << "│       ● │" << "\n";
    cout << "└─────────┘" << "\n";
    break;
  case 3:
    cout << "┌─────────┐" << "\n";
    cout << "│ ●       │" << "\n";
    cout << "│    ●    │" << "\n";
    cout << "│       ● │" << "\n";
    cout << "└─────────┘" << "\n";
    break;
  case 4:
    cout << "┌─────────┐" << "\n";
    cout << "│ ●     ● │" << "\n";
    cout << "│         │" << "\n";
    cout << "│ ●     ● │" << "\n";
    cout << "└─────────┘" << "\n";
    break;
  case 5:
    cout << "┌─────────┐" << "\n";
    cout << "│ ●     ● │" << "\n";
    cout << "│    ●    │" << "\n";
    cout << "│ ●     ● │" << "\n";
    cout << "└─────────┘" << "\n";
    break;
  case 6:
    cout << "┌─────────┐" << "\n";
    cout << "│ ●     ● │" << "\n";
    cout << "│ ●     ● │" << "\n";
    cout << "│ ●     ● │" << "\n";
    cout << "└─────────┘" << "\n";
    break;
  }
}

int rollDice()
{
  return rand() % 6 + 1;
}

void animatedRoll()
{
  cout << "Бросок кубиков: ";
  for (int i = 0; i < 5; i++)
  {
    cout << "⚄ " << flush;
    this_thread::sleep_for(chrono::milliseconds(100));
  }
  cout << "\n";
}

int main()
{
  srand(time(0)); 

  int playerTotal = 0;
  int computerTotal = 0;

  cout << "Правила: у каждого игрока по 3 броска." << "\n";
  cout << "Победит тот, у кого сумма очков больше всего" << "\n";

  cout << "Нажмите Enter чтобы начать...";
  cin.get();

  for (int round = 1; round <= 3; round++)
  {
    cout << "Раунд " << round << "\n";

    cout << "Ваш ход" << "\n";
    cout << "Нажмите Enter чтобы бросить кубики...";
    cin.get();

    animatedRoll();

    int dice1 = rollDice();
    int dice2 = rollDice();
    int roundSum = dice1 + dice2;
    playerTotal += roundSum;

    cout << "\n";
    cout << "Первый кубик: " << dice1 << "\n";
    drawDice(dice1);
    cout << "\n";
    cout << "Второй кубик: " << dice2 << "\n";
    drawDice(dice2);
    cout << "\n";
    cout << "Сумма за раунд: " << roundSum << "\n";
    cout << "Общая сумма: " << playerTotal << "\n";

    cout << "Нажмите Enter чтобы продолжить...";
    cin.get();

    cout << "Раунд " << round << "\n";

    cout << "Ход компьютера" << "\n";
    cout << "Компьютер бросает кубики..." << "\n";
    this_thread::sleep_for(chrono::seconds(2));

    animatedRoll();

    int compDice1 = rollDice();
    int compDice2 = rollDice();
    int compRoundSum = compDice1 + compDice2;
    computerTotal += compRoundSum;

    cout << "\n";
    cout << "Первый кубик: " << compDice1 << "\n";
    drawDice(compDice1);
    cout << "\n";
    cout << "Второй кубик: " << compDice2 << "\n";
    drawDice(compDice2);
    cout << "\n";
    cout << "Сумма за раунд: " << compRoundSum << "\n";
    cout << "Общая сумма: " << computerTotal << "\n";

    if (round < 3)
    {
      cout << "Нажмите Enter чтобы перейти к следующему раунду...";
      cin.get();
    }
  }

  cout << "Финальный результат" << "\n";
  cout << "╔══════════════════════════╗" << "\n";
  cout << "║       Сумма очков        ║" << "\n";
  cout << "╠══════════════════════════╣" << "\n";
  cout << "║  Игрок:    " << setw(10) << playerTotal << "    ║" << "\n";
  cout << "║  Компьютер:" << setw(10) << computerTotal << "    ║" << "\n";
  cout << "╚══════════════════════════╝" << "\n";

  if (playerTotal > computerTotal)
  {
    cout << "Вы выиграли" << "\n";
  }
  else if (computerTotal > playerTotal)
  {
    cout << "Компьютер выиграл" << "\n";
  }
  else
  {
    cout << "Ничья" << "\n";
    cout << "Равный счет" << "\n";
  }

  return 0;
}