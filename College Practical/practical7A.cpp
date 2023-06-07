#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// Function to perform Depth First Search (DFS) on a graph
void DFS(const unordered_map<char, vector<char>>& graph, char startNode) {
    unordered_map<char, bool> visited;
    stack<char> stack;

    stack.push(startNode);

    while (!stack.empty()) {
        char currentNode = stack.top();
        stack.pop();

        if (!visited[currentNode]) {
            cout << currentNode << " ";
            visited[currentNode] = true;

            for (char neighbor : graph.at(currentNode)) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
    }
}

int main() {
    // Define the graph using an adjacency list
    unordered_map<char, vector<char>> graph;
    int numEdges;

    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        char source, destination;
        cout << "Enter the source node of edge " << i + 1 << ": ";
        cin >> source;
        cout << "Enter the destination node of edge " << i + 1 << ": ";
        cin >> destination;
        graph[source].push_back(destination);
    }

    // Perform DFS starting from node 'A'
    char startNode;
    cout << "Enter the start node for DFS traversal: ";
    cin >> startNode;

    cout << "DFS traversal: ";
    DFS(graph, startNode);
    cout << endl;

    return 0;
}
