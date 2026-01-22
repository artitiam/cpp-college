#include <iostream>
#include <fstream>
#include <vector>

int main()
{
  std::ifstream fin("input.txt");
  std::vector<int> pos, neg;
  int x;
  while (fin >> x)
  {
    if (x >= 0)
    {
      pos.push_back(x);
    }
    else
    {
      neg.push_back(x);
    }
  }
  fin.close();

  int n = pos.size();
  std::vector<int> result;
  int i = 0, j = 0;
  int k = 1;

  while (i < n && j < n)
  {
    int take_pos = std::min(k, n - i);
    for (int t = 0; t < take_pos; t++)
    {
      result.push_back(pos[i + t]);
    }
    i += take_pos;

    int takeNeg = std::min(k, n - j);
    for (int t = 0; t < takeNeg; t++)
    {
      result.push_back(neg[j + t]);
    }
    j += takeNeg;

    k++;
  }

  std::ofstream fout("output.txt");
  for (int idx = 0; idx < result.size(); idx++)
  {
    if (idx > 0)
    {
      fout << " ";
    }
    fout << result[idx];
  }
  fout.close();

  std::cout << "Результат записан в output.txt";
  return 0;
}