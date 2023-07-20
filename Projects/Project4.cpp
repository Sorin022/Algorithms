#include <iostream>
#include <fstream>
using namespace std;

//rows and then columns

//binary search tree
//breath-first search
//read in the file for vertex and edges

void undirectedMartix(int vetrexNum, int edge1, int edge2) {
    int undirectedMatrix2DArray[vetrexNum][vetrexNum];

    for(int i = 0; i<vetrexNum; i++){
        for(int j = 0; j<vetrexNum; j++){
            undirectedMatrix2DArray[i][j] = 0;
        }
    }

    undirectedMatrix2DArray[edge1-1][edge2-1] = 1;
}

void undirectedAdjencyList(int vetrexNum, int edge1, int edge2){
   int undirectedAdjencyList2DArray[vetrexNum][vetrexNum];

   for(int i = 0; i<vetrexNum; i++){
        for(int j = 0; j<vetrexNum; j++){
            undirectedAdjencyList2DArray[i][j] = 0;
        }
    }

    undirectedAdjencyList2DArray[edge1-1][edge2-1] = edge2;
}

class LinkedObjects {
    public:
        int id;
        bool processed;
        LinkedObjects** neighbors;

    LinkedObjects(int vertexID, bool notProcessed, int HowManyVertex){
        id = vertexID;
        processed = notProcessed;
        neighbors = new LinkedObjects*[HowManyVertex];

        for (int i = 0; i < HowManyVertex; i++){
            neighbors[i] = 0;
        }

    }

    ~LinkedObjects() {
        delete[] neighbors;
    }

    void addEdge(LinkedObjects* vertex, int vertexAmount){
        for (int i = 0; i < vertexAmount; i++) {
            if (neighbors[i] == vertex) { // Check for the pointer equality.
                break;
            } else if (neighbors[i] == nullptr) {
                neighbors[i] = vertex;
                break;
            }
        }
    }

};

int* DepthFirstSearch(int vertexAmount, LinkedObjects* vertexID) {
    if (vertexID->processed == true) {
        return nullptr;
    }

    vertexID->processed = true;

    int* dfsResult = new int[vertexAmount];
    int dfsIndex = 0;

    for (int i = 0; i < vertexAmount; i++) {
        LinkedObjects* neighbor = vertexID->neighbors[i];

        if (neighbor != nullptr) {
            int* neighborResult = DepthFirstSearch(vertexAmount, neighbor);
            
            if (neighborResult != nullptr) {
                for (int j = 0; j < vertexAmount; j++) {
                    dfsResult[dfsIndex++] = neighborResult[j];
                }
                delete[] neighborResult;
            }
        }
    }

    dfsResult[dfsIndex] = vertexID->id;

    return dfsResult;
}



int main() {
    string FileString;
    ifstream File;
    File.open("C:\\Users\\sorin\\OneDrive\\Documents\\GitHub\\Algorithms\\Projects\\graph.txt");

    if (!File){
        cerr << "Unable to open the file!";
        exit(1);
    }



    while(File >> FileString) {
        
    }
  

}