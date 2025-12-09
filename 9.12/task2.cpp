#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  vector<int> v;
  cout << "Введите числа (Ctrl+D/Ctrl+Z для завершения): ";
  int x;
  while (cin >> x)
  {
    v.push_back(x);
  }
  cout << "Массив: ";
  for (int num : v)
  {
    cout << num << " ";
  }
  cout << "\n";
  map<int, int> copy;
  for (int num : v)
  {
    copy[num]++;
  }

  for (const auto &pair : copy)
  {
    cout << pair.first << " -> " << pair.second << "\n";
  }
  cout << endl;

  return 0;
}