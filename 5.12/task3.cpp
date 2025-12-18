#include <iostream>
#include <string>

using namespace std;

int add(int a, int b)
{
  return a + b;
}

double add(double a, double b)
{
  return a + b;
}

string add(string a, string b)
{
  return a + b;
}

int main()
{
  cout << add(5, 10) << endl;
  cout << add(5.0, 10.5) << endl;
  cout << add(string("abc"), string("def")) << endl;

  int x = 5;
  double y = 10.5;
  cout << add((double)x, y) << endl;

  return 0;
}