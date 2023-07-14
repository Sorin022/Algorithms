#include <iostream>
#include <fstream>
#include <list>
#include <cstring>
#include <ctype.h>
using namespace std;

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

float LinearSearch(ptr head, string key){
    ptr temp = head;
    int amount = 0;
    int total = 0;

    for (int i=0; i<42; i++){
        while (key != temp->data){
            amount++;
            temp = temp->link;
        }
    }

    return amount;
}

ptr Middle(Node* head) {
    Node* by2;
    Node* by1;
    by1 = head;
    by2 = head->link;

    while (by2 != NULL) {
        by2 = by2->link;
        if (by2 != NULL) {
            by1 = by1->link;
            by2 = by2->link;
        }
    }

    by1->link = NULL;
    return by1;
}

void Reverse(ptr head){
    ptr start = head;
    ptr previous = NULL;
    ptr link = NULL;

    while (start != NULL){
        link = start->link;
        start->link = previous;
        previous = start;
        start = link;
    }
    head = previous;
}

float BinarySearch(ptr head, string key){
    int amount = 0;
    int total = 0;

    ptr check = NULL;
    check = Middle(head);

    while(check->data != key){
        if (check->data < key){
            Reverse(head);
            amount++;
        }
        else{
            Middle(head);
            amount++;
        }
    }

    return amount;
}

class Hashtable{
  private:
    static const int hashsize = 250;
    list<pair<string, ptr>> magicTable[hashsize];

  public:
    bool isEmpty();
    int hashFunction(string magicString);
    void insert(string key, ptr data);
    ptr searchHash(string key);
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

void Hashtable::insert(string key, ptr data){
  int hashcode = hashFunction(key);
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

ptr Hashtable::searchHash(string key){
  int hashcode = hashFunction(key);
  auto& block = magicTable[hashcode];
  auto beginning = begin(block);

  for (int j=0; beginning != end(block); beginning++){
    if(beginning->first == key){
      return beginning->second;
    }
  }

  return nullptr;
}

int main() {
  string readInString;
  ifstream File;
  File.open("C:\\Users\\sorin\\OneDrive\\Documents\\GitHub\\Algorithms\\Projects\\lol.txt");


  if (!File){
    cerr << "Unable to open the file!";
    exit(1);
  }

  ptr head = NULL;

  while(File >> readInString){  
    string firstChar = readInString;

    push(&head, firstChar);
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

  int amountB = 0;
  int totalB = 0;
  float avgB = 0; 

  for (int j=0; j<42; j++){
    string ans = pop(*&head);

    amountL = LinearSearch(head, ans);
    totalL = amountL + totalL;

    amountB = BinarySearch(head, ans);
    totalB = amountB + totalB;
  }

  avgL = ("%.2f", totalL/42);
  avgB = ("%.2f", totalB/42);

  Hashtable magic;

  //jsut call the insert functions and you will insert in a new iteam.
  //you pass it the link its attached to and the data it is.
  //same thing for search.

}