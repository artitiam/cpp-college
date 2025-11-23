#include <iostream>
#include <cctype> 
using namespace std;

int main()
{
  char ch;

  cout << "Введите символ: ";
  cin >> ch;

  if (isalpha(ch))
  {
    cout << "Это буква." << endl;
  }
  else if (isdigit(ch))
  {
    cout << "Это цифра." << endl;
  }
  else if (ispunct(ch))
  {
    cout << "Это знак препинания." << endl;
  }
  else
  {
    cout << "Это другой символ." << endl;
  }

  return 0;
}
