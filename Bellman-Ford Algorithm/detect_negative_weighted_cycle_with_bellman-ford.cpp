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

// Class to represent an edge in the graph
class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

// Global variables
int dis[1005]; // Stores shortest distance from the source
vector<Edge> edge_list; // Edge list representation of the graph
int n, e; // Number of nodes and edges

// Bellman-Ford Algorithm to find the shortest path
void bellman_ford()
{
    // Step 1: Relax all edges (n-1) times
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a, b = ed.b, c = ed.c;
            
            // Relaxation step
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

    // Step 2: Check for negative weight cycle
    bool cycle = false;    
    for (auto ed : edge_list)
    {
        int a = ed.a, b = ed.b, c = ed.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }

    // Step 3: Print the result
    if (cycle)
        cout << "Negative weighted cycle detected\n";
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << " -> " << dis[i] << endl;
    }
}

int main()
{
    // Input number of nodes and edges
    cin >> n >> e;

    // Input edge list
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b,a,c)); // Uncomment for an undirected graph
    }

    // Initialize distances to infinity
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;
    dis[0] = 0; // Assume source is node 0

    // Run Bellman-Ford algorithm
    bellman_ford();

    return 0;
}

/*
Algorithm:
1. Read the number of nodes (n) and edges (e).
2. Initialize a distance array with `INT_MAX`, setting the source node to `0`.
3. Store all edges in an edge list representation.
4. Relax all edges (n-1) times:
   - For each edge (a, b, c), update `dis[b]` if a shorter path is found from `a` to `b` via `c`.
5. Perform an additional iteration to check for **negative weight cycles**.
   - If another relaxation is possible, it means a **negative cycle exists**.
6. If a negative cycle is detected, print a message.
7. Otherwise, print the shortest distances from the source.

Time Complexity Analysis:
- Initializing distances: **O(n)**
- Relaxing edges (n-1) times:
  - Iterating over e edges per relaxation step: **O(n * e)**
- Checking for negative cycle: **O(e)**
- Printing results: **O(n)**
Overall, the time complexity is **O(n * e)**.

Space Complexity Analysis:
- Distance array: **O(n)**
- Edge list: **O(e)**
Overall, the space complexity is **O(n + e)**.

⚠️ Notes:
- Bellman-Ford **works for graphs with negative weights**.
- This implementation **detects negative weight cycles**.
- If a **negative cycle exists, the shortest path result is invalid**.
- This implementation assumes the **source node is `0`**. Modify `dis[0]` to `dis[src]` for a general case.
*/
