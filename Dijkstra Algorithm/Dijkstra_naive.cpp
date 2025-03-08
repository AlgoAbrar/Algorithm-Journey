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

// Modified Dijkstra's algorithm using a queue instead of a priority queue
void dijkstra(int src)
{
    // Queue to store the node and its current distance
    queue<pair<int,int>> q;
    q.push({src, 0});  // Initialize the queue with the source node and distance 0
    dis[src] = 0;  // Set the distance to the source node as 0

    while(!q.empty())
    {
        // Extract the node and distance from the front of the queue
        pair<int,int> par = q.front();
        q.pop();
        int par_node = par.first;
        int par_dis = par.second;

        // Traverse through all adjacent nodes
        for(auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            // Relax the edge if a shorter path is found
            if(par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                q.push({child_node, dis[child_node]});  // Push the child node and its updated distance into the queue
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    // Input the edges and build the adjacency list
    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});  // For undirected graph
    }

    // Initialize distances to infinity
    for(int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    // Run Dijkstra starting from node 0
    dijkstra(0);

    // Output the shortest distance from node 0 to each node
    for(int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}

/*
Algorithm:
1. Read the number of nodes (n) and edges (e).
2. Build the adjacency list to represent the graph.
3. Initialize the distance array `dis[]` with infinity for all nodes except the source node.
4. Apply Dijkstra's algorithm using a queue to process nodes.
   - For each node, traverse through its adjacent nodes and relax the edge if a shorter path is found.
   - Update the distance and push the adjacent node into the queue if a shorter path is found.
5. After processing, print the shortest distance from the source node (node 0) to each node in the graph.

Time Complexity:
- Building the adjacency list: **O(e)**
- Initializing the distance array: **O(n)**
- Processing each node: **O(n)** (since each node is pushed to the queue once)
- Processing each edge: **O(e)** (since each edge is relaxed once)
Overall time complexity: **O(n + e)**, which is linear in terms of nodes and edges.

Space Complexity:
- Adjacency list: **O(e)** (since each edge is stored twice in an undirected graph)
- Distance array `dis[]`: **O(n)**
- Queue for processing: **O(n)**
Overall space complexity: **O(n + e)**.

⚠️ Notes:
- This implementation uses a queue instead of a priority queue, which may not always provide optimal performance for Dijkstra's algorithm in all cases.
- The algorithm assumes that all edge weights are non-negative.
- If a node is not reachable from the source, its distance will remain infinity (`INT_MAX`).
*/
