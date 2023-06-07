#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Function to perform Breadth First Search (BFS) on a graph
void BFS(const unordered_map<char, vector<char>>& graph, char startNode) {
    unordered_map<char, bool> visited;
    queue<char> queue;

    queue.push(startNode);

    while (!queue.empty()) {
        char currentNode = queue.front();
        queue.pop();

        if (!visited[currentNode]) {
            cout << currentNode << " ";
            visited[currentNode] = true;

            for (char neighbor : graph.at(currentNode)) {
                if (!visited[neighbor]) {
                    queue.push(neighbor);
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

    // Perform BFS starting from node 'A'
    char startNode;
    cout << "Enter the start node for BFS traversal: ";
    cin >> startNode;

    cout << "BFS traversal: ";
    BFS(graph, startNode);
    cout << endl;

    return 0;
}
