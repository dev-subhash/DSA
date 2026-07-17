#include <iostream>
using namespace std;

int main()
{
    // n = number of vertices
    // m = number of edges
    int n, m;
    cin >> n >> m;

    // Create an adjacency matrix and initialize all values to 0.
    // adj[i][j] = 1 means there is an edge between i and j.
    // adj[i][j] = 0 means there is no edge.
    int adj[n + 1][n + 1] = {0};

    // Read all the edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // Mark the edge from u to v
        adj[u][v] = 1;

        // Since this is an undirected graph,
        // also mark the edge from v to u.
        // Remove this line for a directed graph.
        adj[v][u] = 1;
    }

    // Print the adjacency matrix (optional)
    cout << "Adjacency Matrix:\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



// ADJACENCY LIST REPRESENTATION



#include <iostream>
#include <vector>   // Required for vector

using namespace std;

int main()
{
    // n = Number of vertices (nodes)
    // m = Number of edges
    int n, m;
    cin >> n >> m;

    // Create an adjacency list.
    // adj[i] stores all the neighbours of vertex i.
    // Size is (n + 1) because vertices are numbered from 1 to n.
    vector<int> adj[n + 1];

    // Read all the edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // Add vertex v to the adjacency list of u
        adj[u].push_back(v);

        // Since the graph is undirected,
        // also add vertex u to the adjacency list of v.
        // Remove this line for a directed graph.
        adj[v].push_back(u);
    }

    // Print the adjacency list
    cout << "Adjacency List:\n";

    // Traverse every vertex
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";

        // Print all neighbours of vertex i
        for (int neighbour : adj[i])
        {
            cout << neighbour << " ";
        }

        cout << endl;
    }

    return 0;
}



//  IF THE GRAPH IS WEIGHTED 






#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // n = number of vertices
    // m = number of edges
    int n, m;
    cin >> n >> m;

    // Adjacency list
    // pair.first  -> neighbour
    // pair.second -> weight
    vector<pair<int, int>> adj[n + 1];

    // Read all edges
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        // Add edge u -> v with weight wt
        adj[u].push_back({v, wt});

        // Since graph is undirected,
        // also add edge v -> u
        adj[v].push_back({u, wt});
    }

    // Print adjacency list
    cout << "Weighted Adjacency List:\n";

    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";

        for (auto it : adj[i])
        {
            cout << "(" << it.first << ", " << it.second << ") ";
        }

        cout << endl;
    }

    return 0;
}