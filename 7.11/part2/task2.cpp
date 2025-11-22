#include <iostream>
using namespace std;

int main()
{
  float sum;
  cout << "Введите сумму для перевода в доллары и центы: ";
  cin >> sum;
  int dollars = (int)sum;
  float cent = (sum - dollars) * 100;
  cout << dollars << " Долларов" <<  "\n" << cent << " Центов" << endl;
  
  return 0;
}