#include <iostream>
#include <list>
#include <string>

class HashTable {
private:
    static const int tableSize = 10; // Number of buckets
    std::list<std::pair<int, std::string>> table[tableSize];

public:
    int hashFunction(int key);
    void insert(int key, const std::string& data);
    std::string search(int key);
};

int HashTable::hashFunction(int key) {
    return key % tableSize; // Simple modulo hashing
}

void HashTable::insert(int key, const std::string& data) {
    int hashValue = hashFunction(key);
    table[hashValue].emplace_back(key, data);
}


std::string HashTable::search(int key) {
    int hashValue = hashFunction(key);
    auto& bucket = table[hashValue];

    for (const auto& item : bucket) {
        if (item.first == key) {
            return item.second;
        }
    }

    return "Key not found!";
}

int main() {
    HashTable hashTable;

    hashTable.insert(1, "John");
    hashTable.insert(2, "Alice");
    hashTable.insert(11, "Bob");
    hashTable.insert(21, "Charlie");

    std::cout << "Search results:" << std::endl;
    std::cout << "Key 1: " << hashTable.search(1) << std::endl;
    std::cout << "Key 2: " << hashTable.search(2) << std::endl;
    std::cout << "Key 11: " << hashTable.search(11) << std::endl;
    std::cout << "Key 21: " << hashTable.search(21) << std::endl;
    std::cout << "Key 3: " << hashTable.search(3) << std::endl;

    hashTable.remove(2);
    std::cout << "Key 2 after removal: " << hashTable.search(2) << std::endl;

    return 0;
}

/*class Hashtable{
  private:
    static const int hashsize = 250;
    list<pair<int, string>> magicTable[hashsize];

  public:
    bool isEmpty();
    int hashFunction(string magicString);
    void insert(int key, string data);
    int searchHash(string data);
};

bool Hashtable::isEmpty() {
  int total = 0;
  for (int i =0; i < hashsize; i++){
    int sum = sum + magicTable[i].size();
  }

  if(!total){
    return true;
  }else{
    return false;
  }
};

int Hashtable::hashFunction(string magicString){
 for(int j=0; j<magicString.length(); j++){
  magicString[j] = toupper(magicString[j]);
 }
  int length = magicString.length();
  int letterTotal = 0;

  for (int i = 0; i < length; i++) {
    char thisLetter = magicString[i];
    int thisValue = (int)thisLetter;
    letterTotal = letterTotal + thisValue;
  }

  return letterTotal;
}

void Hashtable::insert(int key, string data){
  int hashcode = hashFunction(data);
  auto& block = magicTable[hashcode];
  bool exists = false;

  for (auto it = block.begin(); it != block.end(); ++it) {
    if (it->first == key) {
      exists = true;
      it->second = data;
      break;
    }
  }

  if (!exists) {
    block.emplace_back(key, data);
  }

}

int Hashtable::searchHash(string data){
  int hashcode = hashFunction(data);
  auto& block = magicTable[hashcode];
  auto beginning = begin(block);
  int amountToCheck = 0;

  for (int j=0; beginning != end(block); beginning++){
    amountToCheck++;
    if(beginning->second == data){
      return amountToCheck;
    }
  }
  return 0;
}*/