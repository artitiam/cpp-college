#include <iostream>
using namespace std;

float findMax(int *A, int *B, int n, int m)
{
  int maxVal = A[0];
  for (int i = 0; i < n; i++)
    if (A[i] > maxVal)
      maxVal = A[i];
  for (int i = 0; i < m; i++)
    if (B[i] > maxVal)
      maxVal = B[i];
  return maxVal;
}

float findMin(int *A, int *B, int n, int m)
{
  int minVal = A[0];
  for (int i = 0; i < n; i++)
    if (A[i] < minVal)
      minVal = A[i];
  for (int i = 0; i < m; i++)
    if (B[i] < minVal)
      minVal = B[i];
  return minVal;
}

float findAvg(int *A, int *B, int n, int m)
{
  float sum = 0;
  for (int i = 0; i < n; i++)
    sum += A[i];
  for (int i = 0; i < m; i++)
    sum += B[i];
  return sum / (n + m);
}

float Action(int *A, int *B, int n, int m, float (*func)(int *, int *, int, int))
{
  return func(A, B, n, m);
}

int main()
{
  int A[] = {3, 7, 1, 9};
  int B[] = {4, 2, 8};
  int n = 4, m = 3;

  cout << "1 - max\n2 - min\n3 - avg\n";
  int choice;
  cin >> choice;

  float result;
  if (choice == 1)
    result = Action(A, B, n, m, findMax);
  else if (choice == 2)
    result = Action(A, B, n, m, findMin);
  else
    result = Action(A, B, n, m, findAvg);

  cout << result << endl;
  return 0;
}
