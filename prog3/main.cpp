#include <iostream>
#include <string>
#include <functional>
using namespace std;
const int TABLE_SIZE = 23;

template <typename K, typename V>
class HashNode {
public:
  HashNode(const K &key, const V &value) :
  key_(key), value_(value), next_(0)
  {
  }
  K key() const {return key_;}
  V value() const { return value_; }
  void setValue(V value) { value_ = value; }
  HashNode *next() const { return next_; }
  void setNext(HashNode *next) { next_ = next; }
private:
  K key_;
  V value_;
  HashNode *next_;
};
template <typename K> struct HashFunc {
  std::size_t operator()(const K &k) const
  {
    return std::hash<K>{}(k) % TABLE_SIZE;
  }
};

template <typename K, typename V, typename F = HashFunc<K> >
class HashTable {
public:
  HashTable()  { table_ = new HashNode<K, V> *[TABLE_SIZE](); }
  ~HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
      HashNode<K,V> *entry = table_[i];
      while (entry) {
        HashNode<K, V> *prev = entry;
        entry = entry->next();
        delete prev;
      }
      table_[i] = 0;
    }
    delete [] table_;
  }
  bool get(const K &key, V &value) {
    std::size_t hashValue = hashFunc_(key);
    HashNode<K, V> *entry = table_[hashValue];
    while (entry) {
      if (entry->key() == key) {
        value = entry->value();
        return true;
      }
      entry = entry->next();
    }
    return false;
  }
  void put(const K &key, const V &value) {
    std::size_t hashValue = hashFunc_(key);
    HashNode<K, V> *prev = 0;
    HashNode<K, V> *entry = table_[hashValue];
    while (entry != 0 && entry->key() != key) {
      prev = entry;
      entry = entry->next();
    }
    if (entry == 0) {
      entry = new HashNode<K, V>(key, value);
      if (prev == 0) {
        table_[hashValue] = entry;
      }
      else {
        prev->setNext(entry);
      }
    }
    else {
      entry->setValue(value);
    }
  }
  void remove(const K &key) {
    std::size_t hashValue = hashFunc_(key);
    HashNode<K, V> *prev = 0;
    HashNode<K, V> *entry = table_[hashValue];
    while (entry != 0 && entry->key() != key) {
      prev = entry;
      entry = entry->next();
    }
    if (entry == 0) {
      return;
    }
    else {
      if (prev == 0) {
        table_[hashValue] = entry->next();
      }
      else {
        prev->setNext(entry->next());
      }
      delete entry;
    }
      
  }
private:
  HashNode<K, V> **table_;
  F hashFunc_;
};

int main(int argc, char *argv[])
{
  HashTable<string, string> hTable;
  
  string value;
  hTable.put("a", "val1");
  hTable.put("bb", "val2");
  hTable.put("ccc", "val3");
  hTable.get("bb", value);
  cout << value << endl;
  hTable.remove("bb");
  bool b= hTable.get("bb", value);
  cout << "get bb:" << b << endl;
  return 0;
}
