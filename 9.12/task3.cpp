#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  std::vector<int> arr = {1, 2, 3, 4, 5};
  cout << "Введите размер сдвига: ";
  int k;
  cin >> k;

  rotate(arr.rbegin(), arr.rbegin() + k, arr.rend());

  for (int x : arr)
  {
    std::cout << x << " "; 
  }

  cout << endl;
}