#include <iostream>
#include <fstream>
#include <list>
#include <cstring>
#include <ctype.h>
using namespace std;

int Bamount = 0;
int Btotal = 0;
float Bavg = 0;

struct Node
{
  string data;
  Node* link;
};

typedef Node* ptr;

string pop(ptr& front){
  if (front){
    ptr temp = front;
    string data = front->data;
    front = front->link;
    delete temp;
    return data;
  }
  
  return "0";
  
}

void push(ptr* frontRef, string key){
  ptr newNode = new Node;
  newNode->data = key;
  newNode->link = *frontRef;
  *frontRef = newNode;

}

void SelectSort(ptr head){
    ptr temp = head;
  
    while (temp) {
        ptr first = temp;
        ptr travers = temp->link;
  
        while (travers) {
            if (first->data > travers->data)
                first = travers;
  
            travers = travers->link;
        }
  
        string data = temp->data;
        temp->data = first->data;
        first->data = data;
        temp = temp->link;
    }
}

void shuffle(ptr* head){
  int count = 0;
  ptr current = *head;

  while(current){
    count++;
    current = current->link;
  }

  srand(time(0));

  current = *head;
  for(int i = count-1; i>0; i--){
    int j = rand()%(i+1);

    ptr nodei = current;
    for (int k =0; k<i; k++){
      nodei = nodei->link;
    }

    ptr nodej = current;
    for (int k =0; k<j; k++){
      nodej = nodej->link;
    }

    string temp = nodei->data;
    nodei->data = nodej->data;
    nodej->data = temp;
  }
}

int LinearSearch(ptr head, string key){
    ptr temp = head;
    int amount = 0;

    while (temp && temp->data != key) {
        amount++;
        temp = temp->link;
    }

    return amount;
}

struct Node* Middle(Node* start, Node* end)
{
    if (start == NULL)
        return NULL;

    struct Node* slow = start;
    struct Node* fast = start->link;

    while (fast != end) {
        fast = fast->link;
        if (fast != end) {
            slow = slow->link;
            fast = fast->link;
        }
    }

    return slow;
}


struct Node* BinarySearch(Node* head, string value)
{
    struct Node* start = head;
    struct Node* last = NULL;

    do {
        Node* mid = Middle(start, last);

        if (mid == NULL)
            return NULL;

        if (mid->data == value){
          Btotal = Bamount + Btotal;
          return mid;
        }else if (mid->data < value){
          Bamount++;
          start = mid->link;
        }else{
          Bamount++;
          last = mid;
        }

    } while (last == NULL || last != start);

    return NULL;
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
  auto beginning = begin(block);
  bool exists = false;

  for(int i=0; beginning != end(block); beginning++){
    if(beginning->first == key){
      exists = true;
      beginning->second = data;
      break;
    }
  }

  if(!exists){
    block.emplace_back(key, data);
  }
  
  return;

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

int main() {
  string readInString;
  ifstream File;
  string insert = "0";
  File.open("C:\\Users\\sorin\\OneDrive\\Documents\\GitHub\\Algorithms\\Projects\\lol.txt");


  if (!File){
    cerr << "Unable to open the file!";
    exit(1);
  }

  ptr head = NULL;
  /*Hashtable magic;*/
  int num = 0;

  while(File >> readInString){  
    string firstString = readInString;

    push(&head, firstString);

    /*magic.insert(num, firstString);*/
  }

  SelectSort(head);

  ptr head2 = NULL;

  for(int i = 0; i<42; i++){
    shuffle(&head);

    string insert = head->data;

    push(&head2, insert);
  }

  int amountL = 0;
  int totalL = 0;
  float avgL = 0;  

  for (int j=0; j<42; j++){
    string ans = pop(*&head2);

    amountL = LinearSearch(head, ans);
    totalL = amountL + totalL;

    BinarySearch(head, ans);
    
  }

  avgL = ("%.2f", totalL/42);
  Bavg = ("%.2f", Btotal/42);

  for (int k = 0; k<42; k++){
    string hashCheck = pop(*&head);

    /*magic.searchHash(hashCheck);*/

  }

  /*Hashtable test;

  test.insert(1, "Sorin");
  test.insert(2, "Joe");
  test.insert(3, "Bob");
  test.insert(4, "Kevin");
  test.insert(5, "Stacie");*/
  

}