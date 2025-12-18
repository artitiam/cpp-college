#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task1()
{
  int m, n;
  cout << "Введите размер массива A: ";
  cin >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++)
    cin >> a[i];

  cout << "Введите размер массива B: ";
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<int> c;
  for (int i = 0; i < m; i++)
  {
    bool foundInB = false;
    for (int j = 0; j < n; j++)
    {
      if (a[i] == b[j])
      {
        foundInB = true;
        break;
      }
    }

    if (!foundInB)
    {
      bool alreadyInC = false;
      for (int k = 0; k < c.size(); k++)
      {
        if (a[i] == c[k])
        {
          alreadyInC = true;
          break;
        }
      }
      if (!alreadyInC)
      {
        c.push_back(a[i]);
      }
    }
  }

  cout << "Результат задания 1: ";
  for (int x : c)
    cout << x << " ";
  cout << endl;
}

void task2()
{
  int m, n;
  cout << "Введите размер массива A: ";
  cin >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++)
    cin >> a[i];

  cout << "Введите размер массива B: ";
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<int> c;

  auto addUniqueDiff = [&](const vector<int> &source, const vector<int> &compare)
  {
    for (int i = 0; i < source.size(); i++)
    {
      bool found = false;
      for (int j = 0; j < compare.size(); j++)
      {
        if (source[i] == compare[j])
        {
          found = true;
          break;
        }
      }
      if (!found)
      {
        bool exists = false;
        for (int k = 0; k < c.size(); k++)
        {
          if (source[i] == c[k])
          {
            exists = true;
            break;
          }
        }
        if (!exists)
          c.push_back(source[i]);
      }
    }
  };

  addUniqueDiff(a, b);
  addUniqueDiff(b, a);

  cout << "Результат задания 2: ";
  for (int x : c)
    cout << x << " ";
  cout << endl;
}

int main()
{
  setlocale(LC_ALL, "Russian");
  int choice;
  cout << "Выберите задание (1 или 2): ";
  cin >> choice;

  if (choice == 1)
    task1();
  else if (choice == 2)
    task2();

  return 0;
}