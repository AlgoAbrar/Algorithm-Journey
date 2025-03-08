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

    // Using an edge list to store graph edges
    vector<pair<int, int>> edge_list;

    // Taking input for edges and storing them in the edge list
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        edge_list.push_back({a, b});
    }

    // Printing the edge list representation
    for (auto p : edge_list)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

/*
Algorithm:
1. Read the number of nodes (n) and edges (e).
2. Initialize an **edge list** using a vector of pairs.
3. Read 'e' edges:
   - Take input for two nodes (a, b).
   - Store them as a pair (a, b) in the edge list.
4. Print the edge list.

Time Complexity Analysis:
- Reading edges and inserting into the edge list: **O(e)**
- Printing the edge list: **O(e)**
Overall, the time complexity is **O(e)**.

Space Complexity Analysis:
- The edge list stores **O(e)** pairs.
- Other variables require **O(1)** space.
Overall, the space complexity is **O(e)**.

⚠️ Notes:
- This implementation is for a **directed graph** (edges are stored as **(a → b)**).
- If the graph is **undirected**, store both directions: `edge_list.push_back({b, a});`.
- **Edge list representation is memory-efficient for sparse graphs** compared to adjacency matrices.
- It is mainly useful in **graph algorithms like Kruskal’s MST** where edges need to be sorted.
*/
