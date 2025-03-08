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

int par[1005];           // Array to store parent of each node
int group_size[1005];    // Array to store the size of each group (set)

// Find function with path compression to find the representative (leader) of a node
int find(int node)   // O(logN)
{
    if(par[node] == -1) 
        return node;
    int leader = find(par[node]);   // Recursively find the leader
    par[node] = leader;             // Path compression, make the node point directly to the leader
    return leader;
}

// Union function to combine two disjoint sets
void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);   // Find the leader of the first node
    int leader2 = find(node2);   // Find the leader of the second node

    // Union by size: attach the smaller group to the larger group
    if(group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;  // Make leader1 the parent of leader2
        group_size[leader1] += group_size[leader2];  // Update the group size
    }
    else
    {
        par[leader1] = leader2;  // Make leader2 the parent of leader1
        group_size[leader2] += group_size[leader1];  // Update the group size
    }
}

int main()
{
    // Initialize parent array to -1 (each node is its own parent initially)
    memset(par,-1,sizeof(par));

    // Initialize group_size array to 1 (each group initially has 1 node)
    memset(group_size,1,sizeof(group_size));

    int n, e;
    cin >> n >> e;  // Input the number of nodes and edges
    bool cycle = false;  // Flag to detect cycles

    while(e--)  // Process each edge
    {
        int a, b;
        cin >> a >> b;  // Input the two nodes of the edge
        
        int leaderA = find(a);  // Find the leader (root) of the first node
        int leaderB = find(b);  // Find the leader (root) of the second node

        if(leaderA == leaderB)  // If both nodes have the same leader, a cycle is detected
            cycle = true;
        else
            dsu_union(a, b);  // If no cycle, union the two sets
    }

    // Output whether a cycle is detected or not
    if(cycle)
        cout << "Cycle Detected.\n";
    else
        cout << "No cycle.\n";

    return 0;
}

/*
Algorithm:
1. Initialize each node to be its own parent and its group size to 1.
2. For each edge (a, b):
   - Find the leaders (representatives) of both nodes using path compression.
   - If the two nodes belong to the same set (i.e., they have the same leader), a cycle is detected.
   - Otherwise, merge the two sets using union by size, attaching the smaller group to the larger group.
3. If a cycle is detected during the edge processing, print "Cycle Detected." Otherwise, print "No cycle."

Time Complexity:
- The `find()` operation, with path compression, runs in nearly constant time, i.e., **O(α(n))**, where α(n) is the inverse Ackermann function (very slow-growing).
- The `dsu_union()` operation takes **O(α(n))** as well, due to the union by size optimization.
Hence, for `e` edges, the overall time complexity is **O(e * α(n))**, which is very efficient.

Space Complexity:
- The space complexity is **O(n)**, where `n` is the number of nodes, as we store the parent and group size arrays of size `n`.

Note:
- This algorithm efficiently detects cycles in a graph using Disjoint Set Union (DSU) with path compression and union by size.
*/
