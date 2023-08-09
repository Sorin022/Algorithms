#include <iostream>
using namespace std;

const int vertexAmount = 1000;

void WDMatrix(int WDMatrixArray[][vertexAmount][vertexAmount], int side, int v1, int v2, int weight){
    WDMatrixArray[side][v1][v2] = weight;
}

struct Node2{
    int data, amount;
    Node2* next;
};

typedef Node2* ptr2;

struct Edge{
    int source, destintation, weight;
};

class TheGraph{
    ptr2 AdjacencyListNode(int data, int weight, ptr2 head){
        ptr2 newNode2 = new Node2;
        newNode2->data = data;
        newNode2->amount = weight;

        newNode2->next = head;

        return newNode2;
    }

    int nodeAmount;

    public:

    ptr2* head;

    TheGraph(Edge totalEdges[], int node, int nodeAmount){
        head = new ptr2[nodeAmount]();
        this->nodeAmount = nodeAmount;

        for(int i=0; i<nodeAmount; i++){
            head[i] = nullptr;  
        }

        for(unsigned i=0; i<node; i++){
            int source = totalEdges[i].source;
            int destintation = totalEdges[i].destintation;
            int weight = totalEdges[i].weight;

            ptr2 newNode2 = AdjacencyListNode(destintation, weight, head[source]);
            head[source] = newNode2;
        }
    }

};

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
        


    WDLinkedObjects(int vertexNum, bool processes, int numNeighbors, int neightborsArray[], int weightArray[]) :
        id(vertexNum), processed(processes) {
        
        for (int i = 0; i < numNeighbors; i++) {
            push(&neighbors, neightborsArray[i]);
        }

        for (int i = 0; i < numNeighbors; i++) {
            push(&weight, weightArray[i]);
        }
    }
    
};

struct spice{
    int value, weight;


    spice(int value, int weight){
        int price = value;
        int amount = weight;
    }
};

bool comparision(struct spice a, struct spice b){
    double spice1 = (double)a.value/a.weight;
    double spice2 = (double)b.value/a.weight;
}

double knapsack(struct spice array[], int number, int amount){
    int currentWeight = 0;

    double endAmount = 0.0;

    for(int i = 0; i<amount; i++){
        if(currentWeight + array[i].weight <= number){
            currentWeight += array[i].weight;
            endAmount += array[i].value;   
        }else{
            int leftover = number - currentWeight;
            endAmount  += array[i].value * ((double)leftover/array[i].weight);
            break;
        }
    }

    return endAmount;
}

int main(){
    int direction = 0;
    int v1Array = 0;
    int v2Array = 0;
    int amount = 0;

    int MartixArray[2][vertexAmount][vertexAmount];

    WDMatrix(MartixArray, direction, v1Array, v2Array, amount);



}