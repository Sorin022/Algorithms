#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function to add an edge to the graph's adjacency list
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // If the graph is undirected, add this line; otherwise, omit it for a directed graph.
}

int main() {
    ifstream inputFile("C:\\Users\\sorin\\OneDrive\\Documents\\GitHub\\Algorithms\\Projects\\graph.txt"); // Replace 'graph_data.txt' with your actual file name.

    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;

    vector<vector<int>> adjList(numVertices); // Assuming vertex numbering starts from 1.

    int u, v;
    for (int i = 0; i < numEdges; ++i) {
        inputFile >> u >> v;
        addEdge(adjList, u, v);
    }

    // Print the adjacency list (optional, just for verification)
    for (int i = 1; i <= numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        for (int v : adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    inputFile.close();
    return 0;
}