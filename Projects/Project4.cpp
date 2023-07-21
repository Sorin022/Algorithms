#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

//rows and then columns

struct Node
{
  //add the left and right see doc
  string data;
  Node* link;
};

typedef Node* ptr;

//build
struct Node* BinaryTreeInsert() {

}

//build
struct Node* BinaryTreeSearch() {

}



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

//breath-frist Search



int main() {
    string FileString;
    ifstream File;
    int vertex;
    int edge1;
    int edge2;

    File.open("C:\\Users\\sorin\\OneDrive\\Documents\\GitHub\\Algorithms\\Projects\\graph.txt");

    if (!File){
        cerr << "Unable to open the file!";
        exit(1);
    }



    while(File >> FileString) {
       getline(File, FileString); 
       int amount = 0;
       int total  = 0;
       int placeV = 0;
       int placeE1 = 0;
       int placeE2 = 0;
       int check = 0;


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
        }else{
            if (total == 670){
              vertex = int(FileString[i+2]);
              placeV++; 
              cout << vertex << '\n'; 
            }else if (total == 405){
              edge1 = int(FileString[i+2]);
              cout << edge1 << '\n';
            }else if (amount == 126){
                check = 1;
            }else if (total == 405 && check == 1){
                edge2 = int(FileString[i+2]);
                cout << edge2 << '\n';
            }
        }


       }
       
    }
  

}