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
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];

    // Initialize adjacency matrix with infinity for no direct paths and 0 for self-loops
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;
        }
    }

    // Input edges and their weights
    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
        // adj_mat[b][a] = c; // Uncomment for undirected graph
    }

    // Floyd-Warshall Algorithm: Calculate shortest paths between all pairs of vertices
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(adj_mat[i][k] != INT_MAX && adj_mat[k][j] != INT_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
    }

    // Output the shortest path matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(adj_mat[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
Algorithm:
1. The program implements the **Floyd-Warshall algorithm**, which computes the shortest paths between all pairs of vertices in a weighted graph.
2. Initially, the adjacency matrix `adj_mat[][]` is filled with `INT_MAX` (infinity) to indicate no direct edge between nodes, except for the diagonal, which is set to 0 (distance from a node to itself).
3. For each edge in the graph, the weight is updated in the adjacency matrix.
4. The **Floyd-Warshall** algorithm is applied:
   - The algorithm iterates over each intermediate vertex `k`, and for each pair of vertices `(i, j)`, it checks if the path from `i` to `j` through `k` is shorter than the current direct path. If so, the distance is updated.
5. After running the algorithm, the matrix `adj_mat[][]` contains the shortest distances between all pairs of vertices.
6. The shortest path matrix is printed where `INF` is used for unreachable pairs.

Time Complexity:
- The time complexity of the Floyd-Warshall algorithm is **O(N^3)**, where N is the number of vertices in the graph. This is because the algorithm uses three nested loops: one for each of the `k` intermediate nodes, and two for the pairs of nodes `(i, j)` to update the distances.

Space Complexity:
- The space complexity is **O(N^2)** due to the storage of the adjacency matrix, where N is the number of vertices. This matrix holds the shortest distances between each pair of nodes.

*/