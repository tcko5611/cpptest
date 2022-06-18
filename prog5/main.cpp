#include <list>
#include <iostream>

using namespace std;
class Queue {
public:
  Queue() {}
  ~Queue() {}
  void push(int i) { data_.push_back(i); }
  int front() { return data_.front(); }
  void pop() { data_.pop_front(); }
private:
  list<int> data_;
};

int main(int argc, char* argv[])
{
  Queue q;
  q.push(5);
  q.push(9);
  q.push(1);
  for (int i = 0; i < 3; ++i) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}
