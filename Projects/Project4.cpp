#include <iostream>
#include <fstream>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;

int vertexArray[100];
int k = 0;
LinkedObjects graph;

struct Node
{
  string data;
  struct Node *left, *right;
};

typedef Node* ptr;

struct Node* BSTnode(string data){
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* BinaryTreeInsert(struct Node* Node, string data) {
    if (Node == NULL)
        return BSTnode(data);

    if (data < Node->data){
        Node->left = BinaryTreeInsert(Node->left, data);
        cout << "L" << '\n';
    }
    else if (data > Node->data){
        Node->right = BinaryTreeInsert(Node->right, data);
        cout << "R" << '\n';
    }
 
    return Node;

}


struct Node* BinaryTreeSearch(struct Node* root, string key) {
    if(root == NULL || root->data == key){
        return root;
    }

    if(root->data < key){
        return BinaryTreeSearch(root->right, key);
    }

    return BinaryTreeSearch(root->left, key);
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
    
    LinkedObjects(){

    }

    LinkedObjects(int vertexID, bool notProcessed){
        int HowManyVertex = vertexArray[k];
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
            if (neighbors[i] == vertex) {
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

void BreathFirstSearch(int vertex){
    list<int> BFSqueue;

    graph.processed = true;

    BFSqueue.push_back(vertex);

    while(!BFSqueue.empty()){
        vertex = BFSqueue.front();
        BFSqueue.pop_front();

        for(auto neighbors : graph.neighbors[vertex]){
            if(!graph.processed){
                graph.processes = true;
                BFSqueue.push_back(neighbors);
            }
        }
    }
}






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

    LinkedObjects* vertices[100];
    for (int i = 0; i < vertexArray[k]; i++) {
        vertices[i] = new LinkedObjects(i + 1, false);
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

       for(int o = 0; o<vertexArray[k]; o++){
        vertices[o] = new LinkedObjects(o + 1, false);
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
                    vertices[edge1 - 1]->addEdge(vertices[edge2 - 1], vertexArray[k]);
                }
            }else if(total == 530){
                k++;
            }
        }


       }

    //file of magic stuff
    ifstream BSTFile;
    BSTFile.open("C:\\Users\\sorin\\OneDrive\\Documents\\GitHub\\Algorithms\\Projects\\lol.txt");
    string BSTString;

    getline(BSTFile, BSTString); 
    struct Node* start = NULL;
    start = BinaryTreeInsert(start, BSTString);

    while(BSTFile >> BSTString){
        getline(BSTFile, BSTString); 
        BinaryTreeInsert(start, BSTString);
    }

    //file of search stuff that he wants
    ifstream BSTSearch;
    BSTSearch.open("C:\\Users\\sorin\\OneDrive\\Documents\\GitHub\\Algorithms\\Projects\\lol.txt");
    string BSTSearchString;

    while (BSTSearch >> BSTSearchString){
        getline(BSTSearch, BSTSearchString);
        BinaryTreeSearch(start, BSTSearchString);
    }
    

       
}

