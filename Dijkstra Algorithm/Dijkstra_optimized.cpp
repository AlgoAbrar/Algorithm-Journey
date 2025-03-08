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

// Adjacency list to represent the graph
vector<pair<int,int>> adj_list[105];

// Array to store the shortest distance from the source to each node
int dis[105];

// Dijkstra's algorithm to find the shortest path from the source node
void dijkstra(int src)
{
    // Min-heap priority queue to process nodes in order of shortest distance
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});  // Push the source node with distance 0
    dis[src] = 0;  // Set the distance of the source node to 0

    // While the queue is not empty, process nodes
    while (!pq.empty())
    {
        // Extract the node with the smallest distance from the priority queue
        pair<int, int> par = pq.top();
        pq.pop();
        int par_node = par.second;
        int par_dis = par.first;

        // Traverse through all adjacent nodes
        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            // Relax the edge if a shorter path is found
            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});  // Push the updated node into the priority queue
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    // Input the edges and build the adjacency list
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});  // For undirected graph
    }

    // Initialize the distance array to infinity for all nodes
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    // Run Dijkstra starting from node 0
    dijkstra(0);

    // Output the shortest distance from node 0 to each node
    for (int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}

/*
Algorithm:
1. Read the number of nodes (n) and edges (e).
2. Build the adjacency list to represent the graph.
3. Initialize the distance array `dis[]` with infinity for all nodes except the source node.
4. Apply Dijkstra's algorithm using a priority queue (min-heap) to process nodes in the order of their current shortest distance.
   - For each node, traverse through its adjacent nodes and relax the edge if a shorter path is found.
   - Push the updated node with the new distance into the priority queue.
5. After processing, print the shortest distance from the source node (node 0) to each node in the graph.

Time Complexity:
- Building the adjacency list: **O(e)**
- Initializing the distance array: **O(n)**
- Processing each node: **O(n log n)** (each node is pushed to and popped from the priority queue once)
- Processing each edge: **O(e log n)** (since each edge results in a priority queue update)
Overall time complexity: **O((n + e) log n)**, which is logarithmic in terms of nodes and edges due to the priority queue operations.

Space Complexity:
- Adjacency list: **O(e)** (since each edge is stored twice in an undirected graph)
- Distance array `dis[]`: **O(n)**
- Priority queue for processing: **O(n)**
Overall space complexity: **O(n + e)**.

⚠️ Notes:
- The priority queue ensures that the node with the smallest distance is processed first, leading to an optimal solution for finding the shortest path in graphs with non-negative edge weights.
- If a node is not reachable from the source, its distance will remain infinity (`INT_MAX`).
*/
