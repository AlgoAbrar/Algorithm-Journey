/* codeforces problem.
Name: Saiyedul Abrar
ID: 0812320205101022
Dept. of Computer Science and Engineering,
Bangladesh Army University of Engineering & Technology,
Qadirabad Cantonment, Natore, Bangladesh
Contact: saiyedul.abrar1430@gmail.com, +8801533713957
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// Adjacency list to represent the graph
vector<pair<ll,ll>> adj_list[100005];

// Arrays to store the shortest distance and parent node for the shortest path tree
ll dis[100005];
ll parent[100005];

// Dijkstra's algorithm to find the shortest path from source node `src`
void dijkstra(ll src)
{
    // Priority queue to implement the min-heap (stores pairs of {distance, node})
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    
    // Initialize the source node distance to 0
    pq.push({0, src});
    dis[src] = 0;

    // Process the nodes
    while(!pq.empty())
    {
        // Extract the node with the smallest distance
        pair<ll,ll> par = pq.top();
        pq.pop();
        ll par_node = par.second;
        ll par_dis = par.first;

        // Traverse through all the adjacent nodes
        for(auto child : adj_list[par_node])
        {
            ll child_node = child.first;
            ll child_dis = child.second;

            // Relax the edge if a shorter path is found
            if(par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
                parent[child_node] = par_node;  // Store the parent node for path reconstruction
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;

    // Input edges and build the adjacency list
    while(e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c}); // For undirected graph
    }

    // Initialize distances and parents for all nodes
    for(ll i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;  // Set the initial distance to infinity
        parent[i] = -1;  // No parent initially
    }

    // Run Dijkstra starting from node 1
    dijkstra(1);

    // Output the shortest path from node 1 to node n
    if(dis[n] == LLONG_MAX)
        cout << -1 << endl;  // No path exists
    else
    {
        // Reconstruct the path from node n to node 1
        ll node = n;
        vector<ll> path;
        while(node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }

        // Reverse the path to get the correct order
        reverse(path.begin(), path.end());

        // Print the path
        for(auto x : path)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}

/*
Algorithm:
1. Read the number of nodes (n) and edges (e).
2. Build the adjacency list to represent the graph.
3. Initialize the distance array `dis[]` with infinity and `parent[]` with -1 for all nodes.
4. Apply Dijkstra's algorithm:
   - Use a priority queue to process nodes by the smallest distance.
   - For each node, update the distance to its adjacent nodes if a shorter path is found.
   - Store the parent node for each node to reconstruct the shortest path later.
5. After running Dijkstra's, check if the distance to node `n` is infinity (i.e., no path exists).
6. If a path exists, reconstruct it by following the parent nodes from node `n` back to node `1`.
7. Output the path or -1 if no path exists.

Time Complexity Analysis:
- Constructing the graph (adjacency list): **O(e)**
- Initializing distance and parent arrays: **O(n)**
- Dijkstra's algorithm:
  - Each node is inserted into the priority queue once: **O(n log n)**
  - Each edge is relaxed once: **O(e log n)**
Overall time complexity: **O((n + e) log n)**, which is efficient for graphs with sparse connections.

Space Complexity Analysis:
- Adjacency list: **O(e)** (since each edge is stored twice in an undirected graph)
- Distance array `dis[]`: **O(n)**
- Parent array `parent[]`: **O(n)**
- Priority queue: **O(n)**
Overall space complexity: **O(n + e)**.

⚠️ Notes:
- This implementation works for both directed and undirected graphs (undirected edges are added twice).
- Dijkstra's algorithm assumes non-negative edge weights.
- If there's no path from the source node to the destination, it outputs `-1`.
*/
