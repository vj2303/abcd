#include <iostream>
#include <cstring>
using namespace std;

void createFlightGraph(string cities[], int numCities)
{
    int i, j;
    char choice;
    int graph[numCities][numCities];

    memset(graph, 0, sizeof(graph)); // Initialize the graph with 0

    for (i = 0; i < numCities; i++)
    {
        for (j = i + 1; j < numCities; j++)
        {
            if (graph[i][j] == 0)
            {
                cout << "Is there a flight from " << cities[i] << " to " << cities[j] << "? (Y/N): ";
                cin >> choice;

                if (choice == 'Y' || choice == 'y')
                {
                    cout << "Enter the flight duration from " << cities[i] << " to " << cities[j] << ": ";
                    cin >> graph[i][j];
                    graph[j][i] = graph[i][j];
                }
            }
        }
    }

    cout << "Adjacency matrix:\n";
    for (i = 0; i < numCities; i++)
    {
        cout << "  " << cities[i] << " ";
    }
    cout << endl;

    for (i = 0; i < numCities; i++)
    {
        cout << cities[i];
        for (j = 0; j < numCities; j++)
        {
            cout << "  " << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numCities, i;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    string cities[numCities];
    cout << "Enter the names of cities: \n";
    for (i = 0; i < numCities; i++)
        cin >> cities[i];

    createFlightGraph(cities, numCities);

    return 0;
}
