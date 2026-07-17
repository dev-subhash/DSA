/*
DFS Algorithm
DFS(node)

Mark node as visited

Print node

For every neighbor
    If neighbor is not visited
         DFS(neighbor)


*/



#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int V;                          // Number of vertices
    vector<vector<int>> adj;        // Adjacency list

public:
    // Constructor
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V + 1);          // Using 1-based indexing
    }

    // Function to add an edge (Undirected Graph)
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS Helper Function
    void dfsHelper(int node, vector<bool> &visited)
    {
        // Mark current node as visited
        visited[node] = true;

        // Print current node
        cout << node << " ";

        // Visit all adjacent nodes
        for (int neighbor : adj[node])
        {
            // Visit only if not visited
            if (!visited[neighbor])
            {
                dfsHelper(neighbor, visited);
            }
        }
    }

    // DFS Traversal Function
    void DFS(int start)
    {
        vector<bool> visited(V + 1, false);

        dfsHelper(start, visited);
    }
};

int main()
{
    int n, m;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    Graph g(n);

    cout << "Enter edges:\n";

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    int start;

    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";

    g.DFS(start);

    return 0;
}