#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

const int N = 6;
int board[N][N];
int moveX[] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y)
{
  return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0);
}

bool solveKT(int x, int y, int moveCount)
{
  if (moveCount == N * N)
    return true;

  for (int i = 0; i < 8; i++)
  {
    int nextX = x + moveX[i];
    int nextY = y + moveY[i];
    if (isValid(nextX, nextY))
    {
      board[nextX][nextY] = moveCount + 1;
      if (solveKT(nextX, nextY, moveCount + 1))
        return true;
      board[nextX][nextY] = 0;
    }
  }
  return false;
}

void knightTour()
{
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      board[i][j] = 0;

  int startX, startY;
  cout << "Введите начальные координаты коня (0-5) через пробел: ";
  cin >> startX >> startY;

  if (startX < 0 || startX >= N || startY < 0 || startY >= N)
  {
    cout << "Неверные координаты." << endl;
    return;
  }

  board[startX][startY] = 1;
  if (solveKT(startX, startY, 1))
  {
    cout << "\nПуть найден:\n";
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
        cout << setw(3) << board[i][j];
      cout << endl;
    }
  }
  else
  {
    cout << "Решения не существует." << endl;
  }
}

const int P_SIZE = 4;
int field[P_SIZE][P_SIZE];
int emptyR, emptyC;

void drawField()
{
  system("cls");
  cout << "--- Пятнашки ---\n";
  for (int i = 0; i < P_SIZE; i++)
  {
    for (int j = 0; j < P_SIZE; j++)
    {
      if (field[i][j] == 0)
        cout << "   ";
      else
        cout << setw(3) << field[i][j];
    }
    cout << endl;
  }
  cout << "\nУправление: w(вверх), s(вниз), a(влево), d(вправо). 0 - выход.\n";
}

void fifteenGame()
{
  srand(time(0));
  vector<int> nums;
  for (int i = 0; i < P_SIZE * P_SIZE; i++)
    nums.push_back(i);
  random_shuffle(nums.begin(), nums.end());

  int k = 0;
  for (int i = 0; i < P_SIZE; i++)
  {
    for (int j = 0; j < P_SIZE; j++)
    {
      field[i][j] = nums[k++];
      if (field[i][j] == 0)
      {
        emptyR = i;
        emptyC = j;
      }
    }
  }

  char move;
  while (true)
  {
    drawField();
    cin >> move;
    if (move == '0')
      break;

    int nextR = emptyR, nextC = emptyC;
    if (move == 'w' && emptyR < P_SIZE - 1)
      nextR++;
    else if (move == 's' && emptyR > 0)
      nextR--;
    else if (move == 'a' && emptyC < P_SIZE - 1)
      nextC++;
    else if (move == 'd' && emptyC > 0)
      nextC--;

    swap(field[emptyR][emptyC], field[nextR][nextC]);
    emptyR = nextR;
    emptyC = nextC;
  }
}

char grid[3][3];

void drawGrid()
{
  system("cls");
  cout << "Крестики-нолики \n";
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << " " << (grid[i][j] == ' ' ? '.' : grid[i][j]) << " ";
      if (j < 2)
        cout << "|";
    }
    if (i < 2)
      cout << "\n-----------\n";
  }
  cout << endl;
}

bool checkTicWin(char p)
{
  for (int i = 0; i < 3; i++)
  {
    if (grid[i][0] == p && grid[i][1] == p && grid[i][2] == p)
      return true;
    if (grid[0][i] == p && grid[1][i] == p && grid[2][i] == p)
      return true;
  }
  if (grid[0][0] == p && grid[1][1] == p && grid[2][2] == p)
    return true;
  if (grid[0][2] == p && grid[1][1] == p && grid[2][0] == p)
    return true;
  return false;
}

void ticTacToe()
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      grid[i][j] = ' ';

  char currentPlayer = 'X';
  int turns = 0;

  while (turns < 9)
  {
    drawGrid();
    int r, c;
    cout << "Игрок " << currentPlayer << ", введите строку и столбец (0-2): ";
    cin >> r >> c;

    if (r < 0 || r > 2 || c < 0 || c > 2 || grid[r][c] != ' ')
    {
      cout << "Неверный ход! Нажмите Enter и попробуйте снова.";
      cin.ignore();
      cin.get();
      continue;
    }

    grid[r][c] = currentPlayer;
    if (checkTicWin(currentPlayer))
    {
      drawGrid();
      cout << "Игрок " << currentPlayer << " победил!\n";
      return;
    }
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    turns++;
  }
  drawGrid();
  cout << "Ничья!\n";
}

int main()
{
  setlocale(LC_ALL, "Russian");
  int choice;

  do
  {
    cout << "\n=== ГЛАВНОЕ МЕНЮ ===\n";
    cout << "1. Задание 1: Обход доски конем (6x6)\n";
    cout << "2. Задание 2: Игра Пятнашки\n";
    cout << "3. Задание 3: Крестики-нолики\n";
    cout << "0. Выход\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      knightTour();
      break;
    case 2:
      fifteenGame();
      break;
    case 3:
      ticTacToe();
      break;
    case 0:
      cout << "Выход...\n";
      break;
    default:
      cout << "Ошибка выбора.\n";
    }
  } while (choice != 0);

  return 0;
}