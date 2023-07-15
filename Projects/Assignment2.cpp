#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
  int data;
  Node* link;
};

typedef Node* ptr;

void push(ptr* headRef, int key){
  ptr newNode = new Node;
  newNode->data = key;
  newNode->link = *headRef;
  *headRef = newNode;

};

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
  
        int data = temp->data;
        temp->data = first->data;
        first->data = data;
        temp = temp->link;
    }
};


ptr InsertSort(ptr head, int data){
  int AmountOfCalls = 0;
  ptr temp;
  ptr pointer;

  int key = data;
  if(head->link != NULL){
    if (head->data == data || key < head->data){
    pointer->link = head;
    head = pointer;
      }
      else{
        temp = head;
        while(temp->link != NULL && temp->link->data < key){
          temp = temp->link;
          pointer->link = temp->link;
          temp->link = pointer;
          AmountOfCalls++;
        }

        cout << AmountOfCalls;
        return head;
      }
  }
  return head;
  
};

void Middle(Node* head, Node** front, Node** back) {
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

    *front = head;
    *back = by1->link;
    by1->link = NULL;
}

Node* Merge(Node* l1, Node* l2) {
    Node* result = NULL;

    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;

    if (l1->data <= l2->data) {
        result = l1;
        result->link = Merge(l1->link, l2);
    }
    else {
        result = l2;
        result->link = Merge(l1, l2->link);
    }

    return result;
}

void MergeSortAlgorithm(Node** headReference) {
    Node* head = *headReference;
    Node* l1;
    Node* l2;

    if (head == NULL || head->link == NULL) {
        return;
    }

    Middle(head, &l1, &l2);
    MergeSortAlgorithm(&l1);
    MergeSortAlgorithm(&l2);
    *headReference = Merge(l1, l2);
}


struct Node* Tail(struct Node* start)
{
    while (start != NULL && start->link != NULL)
        start = start->link;
    return start;
}
  
struct Node* Split(struct Node* head, struct Node* end,
                       struct Node** Head2,
                       struct Node** End2)
{
    struct Node* pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;
  
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*Head2) == NULL)
                (*Head2) = cur;
  
            prev = cur;
            cur = cur->link;
        }
        else
        {

            if (prev)
                prev->link = cur->link;
            struct Node* tmp = cur->link;
            cur->link = NULL;
            tail->link = cur;
            tail = cur;
            cur = tmp;
        }
    }
  

    if ((*Head2) == NULL)
        (*Head2) = pivot;
  
    (*End2) = tail;
  
    return pivot;
}
  

struct Node* QuickSortRecurcussion(struct Node* start, struct Node* end)
{
    if (!start || start == end)
        return start;
  
    Node *Head2 = NULL, *End2 = NULL;
  
    struct Node* pivot = Split(start, end, &Head2, &End2);
  
    if (Head2 != pivot) {
        struct Node* temp = Head2;
        while (temp->link != pivot)
            temp = temp->link;
        temp->link = NULL;
  

        Head2 = QuickSortRecurcussion(Head2, temp);
  

        temp = Tail(Head2);
        temp->link = pivot;
    }
  
    pivot->link = QuickSortRecurcussion(pivot->link, End2);
  
    return Head2;
}
  
void QuickSortAlgorithm(struct Node** head)
{
    (*head) = QuickSortRecurcussion(*head, Tail(*head));
    return;
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

    int temp = nodei->data;
    nodei->data = nodej->data;
    nodej->data = temp;
  }
};



int main() {
  ifstream File;
  File.open("C:\\Users\\sorin\\OneDrive\\Desktop\\UnderGrad-Marist\\College Jr 1\\Algorithms\\C++\\lol.txt");


  if (!File){
    cerr << "Unable to open the file!";
    exit(1);
  }

  string readInString;
  ptr head = NULL;

  while(File >> readInString){  
    int length = readInString.length();

    push(&head, length);

    InsertSort(head, length);
  }
  
  shuffle(&head);

  SelectSort(head);

  shuffle(&head);

  QuickSortAlgorithm(&head);

  shuffle(&head);

  MergeSortAlgorithm(&head);

  File.close();
}


