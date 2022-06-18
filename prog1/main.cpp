#include <iostream>
#include <iomanip>

using namespace std;
void precisionCompute(int x, int y, int n) 
{ 
    // Base cases 
    if (y == 0) { 
        cout << "Infinite" << endl; 
        return; 
    } 
    if (x == 0) { 
        cout << 0 << endl; 
        return; 
    } 
    if (n <= 0) { 
        // Since n <= 0, don't compute after 
        // the decimal 
        cout << x / y << endl; 
        return; 
    } 
  
    // Handling negative numbers 
    if (((x > 0) && (y < 0)) || ((x < 0) && (y > 0))) { 
        cout << "-"; 
        x = x > 0 ? x : -x; 
        y = y > 0 ? y : -y; 
    } 
  
    // Integral division 
    int d = x / y; 
  
    // Now one by print digits after dot 
    // using school division method. 
    for (int i = 0; i <= n; i++) { 
        cout << d; 
        x = x - (y * d); 
        if (x == 0) 
            break; 
        x = x * 10; 
        d = x / y; 
        if (i == 0) 
            cout << "."; 
    }
    cout << endl;
} 
  
int main(int argc, char* argv[])
{
  int a, b ,c;
  while (1) {
    std::cin >> a >> b >> c;
    precisionCompute(a, b, c);
  }
  return 0;
}
