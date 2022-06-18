#include <vector>
#include <string>
#include <iostream>

using namespace std;

void printRecurr(vector<int> &a, int r, int n)
{
  if (r == n) {
    for (auto & e: a) {
      cout << e;
    }
    cout << endl;
  }
  for (int i = r; i < n; ++i) {
    int tmp = a[r];
    a[r] = a[i];
    a[i] = tmp;
    printRecurr(a, r+1, n);
    tmp = a[r];
    a[r] = a[i];
    a[i] = tmp;
  }
}

int main(int argc, char *argv[])
{
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < a.size(); ++i) {
    a[i] = i+1;
  }
  printRecurr(a, 0, n);
  return 0;
}
