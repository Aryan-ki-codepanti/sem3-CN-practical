#include <bits/stdc++.h>
using namespace std;

// Graph -> adj matrix
/*
Sample input

6 0

0 1 4 0 0 0
1 0 4 2 7 0
4 4 0 3 5 0
0 2 3 0 4 6
0 7 5 4 0 7
0 0 0 6 7 0

*/

int select_min_node(vector<bool> processed, vector<int> distances)
{
    int min_dist = INT_MAX;
    int min_node;

    for (int i = 0; i < processed.size(); i++)
        if (!processed[i] && distances[i] < min_dist)
        {
            min_dist = distances[i];
            min_node = i;
        }
    return min_node;
}

void dijkstra(int **graph, int v, int src)
{

    int parent[v];
    vector<int> distances(v, INT_MAX);
    vector<bool> processed(v, false);

    parent[src] = -1;
    distances[src] = 0;

    int curr_node;
    for (int i = 0; i < v - 1; i++)
    {
        curr_node = select_min_node(processed, distances);
        processed[curr_node] = true;

        for (int neighbor = 0; neighbor < v; neighbor++)
        {
            if (graph[curr_node][neighbor] && !processed[neighbor] && (graph[curr_node][neighbor] + distances[curr_node] < distances[neighbor]))
            {
                distances[neighbor] = distances[curr_node] + graph[curr_node][neighbor];
                parent[neighbor] = curr_node;
            }
        }
    }

    cout << "\nSource : " << src << endl;
    // display shortest path graph && distances
    for (int i = 0; i < v; i++)
        if (i != src)
            cout << "Edge : " << parent[i] << " -> " << i << " cost = " << distances[i] << endl;
}

int main()
{
    int v, src;
    cout << "Enter number of vertices and source" << endl;
    cin >> v >> src;

    int **graph = new int *[v];
    for (int i = 0; i < v; i++)
        graph[i] = new int[v];

    cout << "Enter adjacency matrix" << endl;
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            cin >> graph[i][j];
    dijkstra(graph, v, src);

    return 0;
}