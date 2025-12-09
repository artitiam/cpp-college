#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main()
{
  mt19937 rng(random_device{}());
  uniform_int_distribution<int> dist(5, 10);

  int randomNumber = dist(rng);

  vector<int> v;
  cout << "Массив: ";
  for (int i = 0; i < randomNumber; i++)
  {
    v.push_back(i);
    cout << v[i] << " ";
  }
  cout << "\n";
  cout << "Выберите индекс элемента который хотите удалить: ";
  int userChoice;
  cin >> userChoice;
  v.erase(v.begin() + userChoice);
  cout << "Изменённый массив: ";
  for (int x : v)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}