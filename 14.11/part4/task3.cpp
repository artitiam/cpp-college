#include <iostream>
using namespace std;

int main()
{
  for (int i = 0; i <= 9; i++)
  {
    for (size_t k = 97; k < 104; k++)
    {
      cout << char(k) << i << " ";
    }
    cout << "\n";
  }

  return 0;
}