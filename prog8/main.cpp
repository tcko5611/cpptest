#include <iostream>
using namespace std;

struct ListNode;
struct ListNode {
  ListNode(int v) {
    next = 0;
    val = v;
  }
  ListNode* next;
  int val;
};

struct List
{
public:
  List() {
    head = nullptr;
  }
  void addNode(int val){
    ListNode *l = new ListNode(val);
    if (!head) {
      head = l;
    }
    else {
      ListNode *ll = head, *lll = head->next;
      while (lll) {
        ll = lll;
        lll =  lll->next;
      }
      ll->next = l;
    }
  }

  void swap()
  {
    ListNode *l = nullptr;
    if (head && head->next) {
      l = head->next;
    }
    swapPairs(head);
    if (l) {
      head = l;
    }
  }

  ListNode * swapPairs(ListNode *a) {
    if (!a) return nullptr;
    ListNode* nxt = a->next;
    if (nxt) {
      a->next = nxt->next;
      nxt->next = a;
      a->next = swapPairs(a->next);
    }
    else {
      return a;
    }
    return nxt;
  }
  
  void printAll()
  {
    ListNode *l = head;
    while (l) {
      cout << l->val << ",";
      l = l->next;
    }
    cout << endl;
  }
private:
  ListNode *head;
};

int main(int argc, char *argv[])
{
  List l;
  l.addNode(1);
  l.addNode(2);
  l.addNode(3);
  l.addNode(4);
  l.printAll();
  l.swap();
  l.printAll();
  return 0;
}
