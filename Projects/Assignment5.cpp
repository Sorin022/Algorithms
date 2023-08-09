#include <iostream>
#include <fstream>
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

struct BellManGraph{
    int vertex, edge;

    struct Edge* theEdge;
};

struct BellManGraph* makeGraph(int vertex, int edge){
    struct BellManGraph* theGraph = new BellManGraph;
    theGraph->vertex = vertex;
    theGraph->edge = edge;
    theGraph->theEdge = new Edge[edge];
}

void BellManFrodAlgo(struct BellManGraph* theGraph, int source){
    int vertex = theGraph->vertex;
    int edge = theGraph->edge;
    int distance[vertex];

    for(int i = 0; i<vertex; i++){
        distance[i] = INT_MAX;
        distance[source] = 0;
    }

    for(int i = 1; i <= vertex-1; i++){
        for(int j = 0; j < edge; j++){
            int vSource = theGraph->theEdge[j].source;
            int vDestination = theGraph->theEdge[j].destintation;
            int weight = theGraph->theEdge[j].weight;
            
            if(distance[vSource] != INT_MAX && distance[vSource] + weight < distance[vDestination]){
                distance[vDestination] = distance[vSource] + weight;
            }
        }
    }

    for(int i = 0; i < edge; i++){
        int vSource = theGraph->theEdge[i].source;
        int vDestination = theGraph->theEdge[i].destintation;
        int weight = theGraph->theEdge[i].weight;

        if(distance[vSource] != INT_MAX && distance[vSource] + weight < distance[vDestination]){
            return;
        }



    }
}

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
    ifstream File;
    string FileString;
    int direction = 0;
    int v1Array = 0;
    int v2Array = 0;
    int vertexAmount = 0;

    int MartixArray[2][vertexAmount][vertexAmount];

    WDMatrix(MartixArray, direction, v1Array, v2Array, vertexAmount);

    File.open("C:\\Users\\sorin\\OneDrive\\Documents\\GitHub\\Algorithms\\Projects\\graph.txt");

    if (!File){
        cerr << "Unable to open the file!";
        exit(1);
    }

    getline(File, FileString);

    while(getline(File, FileString) && File >> FileString){
            int amount = 0;
            int total  = 0;


            for(int j=0; j<FileString.length(); j++){
                    char FileStringChar = FileString[j];
                    FileString[j] = tolower(FileStringChar);
            }

            for (int i=0; i<FileString.length(); i++){
                amount = int(FileString[i]);
                total = amount + total;

                if (amount == 32){
                    amount = 0;
                    total  = 0;
                }else if(total == 670){
                    vertexAmount++;
                }
            }
    }

    int vertex[vertexAmount];
    int v1[vertexAmount*2];
    int v2[vertexAmount*2];
    int PH1 = 0;
    int PH2 = 0;
    int directionArray[vertexAmount*vertexAmount];
    int whichDir = 0;

    for(int i=0; i<vertexAmount; i++){
        vertex[i] = i+1;
    }

    while(getline(File, FileString) && File >> FileString){
            int amount = 0;
            int total  = 0;


            for(int j=0; j<FileString.length(); j++){
                    char FileStringChar = FileString[j];
                    FileString[j] = tolower(FileStringChar);
            }

            for (int i=0; i<FileString.length(); i++){
                amount = int(FileString[i]);
                total = amount + total;

                if (amount == 32){
                    amount = 0;
                    total  = 0;
                    direction = 0;
                }else if(total == 405){
                    v1[PH1] = (int)FileString[i+2];
                    PH1++;
                }else if(amount == 45){
                    v2[PH2] = (int)FileString[i+2];
                    PH2++;
                    directionArray[whichDir] = (int)FileString[i+2];
                    whichDir++;
                }
            }
    }

}