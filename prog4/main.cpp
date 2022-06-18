#include <vector>
#include <string>
#include <iostream>

using namespace std;

void printRecurr(vector<int> &a, vector<bool>& b, int n)
{
  if (n == 1) {
    for (int i = 0; i < b.size(); ++i) {
      if (!b[i]) continue;
      a[i] = n;
      for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
      }
      cout << endl;
      return;
    }
  }
  for (int i = 0; i < b.size(); ++i) {
    if (!b[i]) continue;
    a[i] = n;
    b[i] = false;
    printRecurr(a, b, n-1);
    b[i] = true;
  }
}

int main(int argc, char *argv[])
{
  int n;
  cin >> n;
  vector<int> a(n, 0);
  vector<bool> b(n, true);
  printRecurr(a, b, n);
  return 0;
}
