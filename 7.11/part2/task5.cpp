#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
  float deposit, annual_rate, monthly_rate, interest;

  cout << "Введите сумму вклада в евро и процент годовых: ";
  cin >> deposit >> annual_rate;

  monthly_rate = annual_rate / 12 / 100.0;

  cout << fixed << setprecision(2); 

  for (int i = 1; i <= 12; i++)
  {
    interest = deposit * monthly_rate; 
    cout << "Месяц " << i << ": " << interest << "€" << endl;
  }

  return 0;
}
