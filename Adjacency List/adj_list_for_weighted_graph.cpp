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

    // Adjacency list representation of a weighted graph
    vector<pair<int, int>> adj_list[n];

    // Inputting the edges
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        // Adding bidirectional (undirected) edges with weights
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    // Printing the adjacency list
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto p : adj_list[i])
            cout << p.first << " " << p.second << ", ";
        cout << endl;
    }

    return 0;
}

/*
Algorithm:
1. Read the number of nodes (n) and edges (e).
2. Initialize an adjacency list with 'n' empty lists.
3. Read 'e' edges:
   - Take input for two nodes (a, b) and the edge weight (c).
   - Add (b, c) to a's adjacency list and (a, c) to b's adjacency list.
4. Print the adjacency list representation.

Time Complexity Analysis:
- Initializing the adjacency list: **O(n)**
- Reading edges and inserting into the adjacency list: **O(e)**
- Printing the adjacency list: **O(n + e)**
Overall, the time complexity is **O(n + e)**.

Space Complexity Analysis:
- Adjacency list uses **O(n + e)** space.
- Other variables require **O(1)** space.
Overall, the space complexity is **O(n + e)**.
*/
