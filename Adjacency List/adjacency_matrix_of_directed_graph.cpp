/*
Name: Saiyedul Abrar
ID: 0812320205101022
Dept. of Computer Science and Engineering,
Bangladesh Army University of Engineering & Technology,
Qadirabad Cantonment, Natore, Bangladesh
Contact: saiyedul.abrar1430@gmail.com, +8801533713957
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Taking input for the number of nodes (n) and edges (e)
    int n, e;
    cin >> n >> e;

    // Initializing adjacency matrix with 0
    int adj_mat[n][n];
    memset(adj_mat, 0, sizeof(adj_mat));

    // Setting diagonal elements to 1 (self-loops)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i == j)
                adj_mat[i][j] = 1;
    }

    // Taking input for edges and updating adjacency matrix
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1; // Directed edge from a to b
    }

    // Printing the adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Algorithm:
1. Read the number of nodes (n) and edges (e).
2. Initialize an adjacency matrix of size n × n with all values set to 0.
3. Set self-loops (diagonal elements) to 1 (i.e., adj_mat[i][i] = 1).
4. Read 'e' edges:
   - Take input for two nodes (a, b).
   - Mark adj_mat[a][b] as 1 (directed edge from a to b).
5. Print the adjacency matrix.

Time Complexity Analysis:
- Initializing the adjacency matrix: **O(n²)**
- Setting diagonal elements: **O(n)**
- Reading edges and updating the matrix: **O(e)**
- Printing the adjacency matrix: **O(n²)**
Overall, the time complexity is **O(n²)** (dominant term).

Space Complexity Analysis:
- The adjacency matrix requires **O(n²)** space.
- Other variables require **O(1)** space.
Overall, the space complexity is **O(n²)**.

⚠️ Notes:
- This implementation is for a **directed graph**.
- If **undirected edges** are needed, also set `adj_mat[b][a] = 1`.
- **Adjacency matrix is inefficient for large graphs** since it takes **O(n²) space**, making it unsuitable for sparse graphs.
*/
