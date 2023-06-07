#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void createFlightGraph(vector<string>& cities, unordered_map<string, vector<pair<string, int>>>& graph) {
    int numCities = cities.size();
    char choice;

    for (int i = 0; i < numCities; i++) {
        for (int j = i + 1; j < numCities; j++) {
            cout << "Is there a flight from " << cities[i] << " to " << cities[j] << "? (Y/N): ";
            cin >> choice;

            if (choice == 'Y' || choice == 'y') {
                int cost;
                cout << "Enter the cost (time/fuel) for the flight: ";
                cin >> cost;
                graph[cities[i]].push_back({cities[j], cost});
                graph[cities[j]].push_back({cities[i], cost});
            }
        }
    }
}

int main() {
    int numCities;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    vector<string> cities(numCities);
    cout << "Enter the names of cities: \n";
    for (int i = 0; i < numCities; i++)
        cin >> cities[i];

    unordered_map<string, vector<pair<string, int>>> graph;
    createFlightGraph(cities, graph);

    cout << "Adjacency list:\n";
    for (const auto& pair : graph) {
        cout << pair.first << ": ";
        for (const auto& neighbor : pair.second) {
            cout << neighbor.first << " (Cost: " << neighbor.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
