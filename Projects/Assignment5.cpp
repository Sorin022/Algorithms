#include <iostream>
using namespace std;

//3d array
void WDMatrix(int WDMatrixArray[], int side, int v1, int v2, int weight){
    WDMatrixArray[side][v1][v2] = weight;
}

void WDAdjancey(){
    
}

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

class WDLinkedObjects{
    public:
        int id;
        bool processed;
        ptr neighbors = NULL;
        ptr weight = NULL;
        


    WDLinkedObjects(int vertexNum, bool processes, int neightborsArray[], int weightArray[]){
        int id = vertexNum;
        processes = false;
        for (int i=0; i<sizeof(neightborsArray)/sizeof(int); i++){
            push(&neighbors, neightborsArray[i]);
        }

        for (int i=0; i<sizeof(weightArray)/sizeof(int); i++){
            push(&weight, weightArray[i]);
        }
    }
    
};

int main(){

}