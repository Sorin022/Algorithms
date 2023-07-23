#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

//rows and then columns

int vertexArray[100];
int k = 0;

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



void undirectedMartix(int edge1, int edge2) {
    int vertexNum = vertexArray[k];
    int undirectedMatrix2DArray[vertexNum][vertexNum];

    for(int i = 0; i<vertexNum; i++){
        for(int j = 0; j<vertexNum; j++){
            undirectedMatrix2DArray[i][j] = 0;
        }
    }

    undirectedMatrix2DArray[edge1-1][edge2-1] = 1;
}

void undirectedAdjencyList(int edge1, int edge2){
    int vertexNum = vertexArray[k];
    int undirectedAdjencyList2DArray[vertexNum][vertexNum];

   for(int i = 0; i<vertexNum; i++){
        for(int j = 0; j<vertexNum; j++){
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
    int vertexArray[100];
    int vertexArrayPointer = 0;

    File.open("C:\\Users\\sorin\\OneDrive\\Documents\\GitHub\\Algorithms\\Projects\\graph.txt");

    if (!File){
        cerr << "Unable to open the file!";
        exit(1);
    }
    
    getline(File, FileString);

    while(getline(File, FileString)){ 
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
                    vertex++;
                }else if(total ==  530) {
                    vertexArray[vertexArrayPointer] = vertex;
                    vertexArrayPointer++;
                    vertex = 0;
                }
            }
        }



    while(File >> FileString) {
       getline(File, FileString); 
       int amount = 0;
       int total  = 0;
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
            if (total != 530){
                if (total == 405){
                edge1 = int(FileString[i+2]);
                edge1 = 0;
                }else if (amount == 126){
                    check = 1;
                }else if (total == 405 && check == 1){
                    edge2 = int(FileString[i+2]);
                    edge2 = 0;
                    undirectedMartix(edge1, edge2);
                    undirectedAdjencyList(edge1, edge2);
                }
            }else if(total == 530){
                k++;
            }
        }


       }
       
}

