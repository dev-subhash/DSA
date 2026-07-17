/*

BFS ALGORITHM 


1. Put starting node into queue.

2. Mark it visited.

3. While queue is not empty

      Take front node.

      Print it.

      Visit every adjacent node.

      If not visited

            Mark visited.

            Push into queue.

*/



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS traversal
vector<int> bfsTraversal(int V, vector<int> adj[], int start)
{
    // Stores BFS traversal
    vector<int> bfs;

    // Visited array
    vector<bool> visited(V + 1, false);

    // Queue for BFS
    queue<int> q;

    // Start BFS from the starting node
    q.push(start);
    visited[start] = true;

    // Continue until queue becomes empty
    while (!q.empty())
    {
        // Get the front node
        int node = q.front();
        q.pop();

        // Store the node in answer
        bfs.push_back(node);

        // Traverse all adjacent nodes
        for (int neighbour : adj[node])
        {
            // If neighbour is not visited
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return bfs;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    // Adjacency List
    vector<int> adj[V + 1];

    cout << "Enter edges (u v):\n";

    // Undirected Graph
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;

    cout << "Enter starting node: ";
    cin >> start;

    // Perform BFS
    vector<int> ans = bfsTraversal(V, adj, start);

    cout << "\nBFS Traversal:\n";

    for (int node : ans)
    {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}