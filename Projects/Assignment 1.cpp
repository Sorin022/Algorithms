#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
  char data;
  Node* link;
};

typedef Node* ptr;

char pop(ptr& front){
  if (front){
    ptr temp = front;
    char data = front->data;
    front = front->link;
    delete temp;
    return data;
  }
  
  return '0';
  
};

void push(ptr* frontRef, char key){
  ptr newNode = new Node;
  newNode->data = key;
  newNode->link = *frontRef;
  *frontRef = newNode;

};

struct TheQueue{
  Node* front;
  Node* back;

  TheQueue(){
    front = NULL;
    back  = NULL;
  }

  

  void putInQueue(char info){
    ptr temp = new Node;
    temp->data = info;
    if (back == NULL){
      front = temp;
      back  = temp;
      return;
    }

    back->link = temp;
    back = temp;
  };

  char takeOutQueue(){
    if (front == NULL) {
      return '0';
    }

    ptr temp = front;
    front = front->link;
    char data = temp->data;
    delete temp;

    if (front == NULL) {
      back = NULL;
    }

    return data;
  }
    
};






int main() {
  string readInString;
  ifstream File;
  File.open("C:\\Users\\sorin\\OneDrive\\Desktop\\UnderGrad-Marist\\College Jr 1\\Algorithms\\C++\\lol.txt");


  if (!File){
    cerr << "Unable to open the file!";
    exit(1);
  }

  while (File >> readInString) {
    for (int i = 0; i < readInString.length(); i++){
        if (int(readInString.at(i)) >= 32 && int(readInString.at(i)) <= 47){
            readInString[i] = '_';
        }

        if (int(readInString.at(i)) >= 65 && int(readInString.at(i)) <= 90){
            readInString[i] = char(int(readInString.at(i) + 32));
        }
    }

    string insert = readInString;

    ptr head;
    head = new Node;

    TheQueue queue;

    for (int j = 0; j < insert.length(); j++){
      push(&head , insert[j]);
      queue.putInQueue(insert[j]);
    }

    bool all_chars_same = true;

    for (int k = 0; k < insert.length(); k++){
      char popChar = pop(*&head);
      char queueChar = queue.takeOutQueue();

      if (popChar != queueChar) {
        all_chars_same = false;
        break;
      }
    }

    if (all_chars_same == true) {
      cout << insert << endl;
    }
  }


  File.close();
}