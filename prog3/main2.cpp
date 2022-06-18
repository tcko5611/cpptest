#include <iostream>
#include <string>
#include <functional>
#include <vector>
using namespace std;

struct HashNode {
  HashNode(const string &s) :next(nullptr), prev(nullptr), val(s) {}
  HashNode *next;
  HashNode *prev;
  string val;
};

class HashSet {
  const int TABLE_SIZE = 100;
public:
  HashSet() : nodes(TABLE_SIZE, nullptr) {
  }
  ~HashSet() {}
  void add(const string& s) {
    int id = hash(s);
    HashNode *node = nodes[hash(s)];
    if (node == nullptr) {
      node = new HashNode(s);
      nodes[id] = node;
    }
    else {
      HashNode *prevNode = 0;
      while (node) {
        prevNode = node;
        if (node->val == s) return;
        node = node ->next;
      }
      HashNode *node = new HashNode(s);
      prevNode->next = node;
      node->prev = prevNode;
    }
  }
    
  void del(const string& s){
    int id = hash(s);
    HashNode *node = nodes[id];
    if (!node) return; 
    if (node->val == s) {
      HashNode *nextNode = node->next;
      if (nextNode) {
        nextNode->prev = nullptr;
        nodes[id] = nextNode;
        delete node;
      }
    }
    node = node->next;
    while (node) {
      if (node->val == s) {
        HashNode *prevNode = node->prev;
        HashNode *nextNode = node->next;
        prevNode->next = nextNode;
        if (nextNode) nextNode->prev= prevNode;
        delete node;
        return;
      }
    }
  }
  bool find(const string &s){
    int id = hash(s);
    HashNode *node = nodes[id];
    while (node) {
      if (node->val == s) {
        return true;
      }
      node = node->next;
    }
    return false;
  }
  void printAll()
  {
    for(int i = 0; i < nodes.size(); ++i) {
      HashNode *node = nodes[i];
      if (node == nullptr) continue;
      while(node) {
        cout << node->val << endl;
        node = node->next;
      }
    }
  }
private:
  int hash(const string &s) {
    int sum = 0;
    for (const char c: s) {
      sum += c-'\0';
    }
    return sum % TABLE_SIZE;
  }
  vector<HashNode *> nodes; 
};

int main(int argc, char *argv[])
{
  HashSet h;
  
  string value;
  h.add("abc");
  h.add("cba");
  h.add("ccc");
  cout << h.find("abc") << endl;
  cout << h.find("cba") << endl;
  h.del("cba");
  cout << h.find("cba") << endl;
  h.printAll();
  return 0;
}
