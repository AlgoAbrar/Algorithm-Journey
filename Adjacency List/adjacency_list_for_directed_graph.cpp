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

    // Array of vectors to represent adjacency list
    vector<int> adj_list[n];

    // Taking input for edges
    while (e--)
    {
        int a, b;
        cin >> a >> b;

        // Adding directed edge from a to b
        adj_list[a].push_back(b);
    }

    // Printing the adjacency list
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int x : adj_list[i])
            cout << x << " ";
        cout << endl;
    }

    return 0;
}

/*
Algorithm:
1. Read the number of nodes (n) and edges (e).
2. Initialize an adjacency list using an array of vectors.
3. Read 'e' edges:
   - Take input for two nodes (a, b).
   - Add b to a's adjacency list (directed edge).
4. Print the adjacency list representation.

Time Complexity Analysis:
- Initializing the adjacency list: **O(n)**
- Reading edges and inserting into adjacency list: **O(e)**
- Printing the adjacency list: **O(n + e)**
Overall, the time complexity is **O(n + e)**.

Space Complexity Analysis:
- Adjacency list uses **O(n + e)** space.
- Other variables require **O(1)** space.
Overall, the space complexity is **O(n + e)**.

⚠️ Note:
- The adjacency list uses an **array of vectors**, which is more memory-efficient than an **adjacency matrix** for sparse graphs.
- The input assumes **0-based indexing** for nodes.
- The code currently supports **only directed graphs** (i.e., no reverse edge for undirected graphs).
*/
