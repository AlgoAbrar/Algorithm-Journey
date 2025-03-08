/*
Name: Saiyedul Abrar
ID: 0812320205101022
Dept. of Computer Science and Engineering,
Bangladesh Army University of Engineering & Technology,
Qadirabad Cantonment, Natore, Bangladesh
Contact: saiyedul.abrar1430@gmail.com, +8801533713957
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, q;
    cin >> n >> e >> q;
    long long int adj_mat[n+5][n+5];

    // Initialize adjacency matrix with infinity for no direct paths and 0 for self-loops
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LLONG_MAX;
        }
    }

    // Input edges and their weights
    while(e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
        adj_mat[b][a] = min(adj_mat[a][b], c);  // Undirected graph
    }

    // Floyd-Warshall Algorithm: Calculate shortest paths between all pairs of vertices
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
    }

    // Process the queries
    while(q--)
    {
        int s, d;
        cin >> s >> d;
        if(adj_mat[s][d] == LLONG_MAX)
            cout << -1 << endl;  // No path exists
        else
            cout << adj_mat[s][d] << endl;  // Shortest path distance
    }
    
    return 0;
}
/*
Algorithm:
1. The program implements the **Floyd-Warshall algorithm** for finding the shortest paths between all pairs of vertices in a weighted graph.
2. Initially, an adjacency matrix `adj_mat[][]` is created where each element is set to `LLONG_MAX` (infinity), indicating no direct edge exists between vertices. The diagonal is set to 0 as the distance from a node to itself is 0.
3. The edges of the graph are read, and the adjacency matrix is updated with the minimum edge weight for each pair of connected nodes. Since the graph is undirected, the matrix is updated symmetrically for both `a -> b` and `b -> a`.
4. The **Floyd-Warshall algorithm** is applied:
   - For each intermediate vertex `k`, and for each pair of vertices `(i, j)`, the algorithm checks if the path from `i` to `j` through `k` is shorter than the current known path. If so, the distance is updated.
5. After running the algorithm, the matrix `adj_mat[][]` contains the shortest distances between all pairs of vertices.
6. For each query, the program outputs the shortest distance from node `s` to node `d`. If no path exists, it outputs `-1`.

Time Complexity:
- The time complexity of the **Floyd-Warshall algorithm** is **O(N^3)**, where N is the number of vertices in the graph. This is because the algorithm uses three nested loops: one for each intermediate node `k` and two for each pair of nodes `(i, j)`.

Space Complexity:
- The space complexity is **O(N^2)** due to the storage of the adjacency matrix `adj_mat[][]`, where N is the number of vertices. This matrix holds the shortest distances between each pair of nodes.

*/