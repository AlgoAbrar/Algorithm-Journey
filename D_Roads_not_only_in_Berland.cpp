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

int par[1005];
int group_size[1005];

int find(int node)   // O(logN)
{
    if(par[node] == -1) 
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2) 
{
    int leader1 = find(node1); 
    int leader2 = find(node2);   
    if(leader1 == leader2)
        return;
    if(group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
    vector<pair<int, int>> rmv; // Store edges to remove to avoid cycle
    vector<pair<int, int>> create; // Store edges to add for connectivity

    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if(leaderA == leaderB) // Cycle detected, mark edge for removal
            rmv.push_back({a, b});
        else // No cycle, unite the sets
            dsu_union(a, b);
    }

    // Ensure the graph is fully connected
    for(int i = 2; i <= n; i++)
    {
        int leader1 = find(1);
        int leader2 = find(i);
        if(leader1 != leader2)
        {
            create.push_back({1, i}); // Add edge to ensure connectivity
            dsu_union(1, i);
        }
    }

    // Output the result
    cout << rmv.size() << endl;
    for(int i = 0; i < rmv.size(); i++)
        cout << rmv[i].first << " " << rmv[i].second << " " << create[i].first << " " << create[i].second << endl;

    return 0;
}
/*
Algorithm:
This code implements the Disjoint Set Union (DSU) or Union-Find data structure with path compression and union by size.
- The `find` function returns the leader (or root) of the set containing a node, applying path compression to speed up future queries.
- The `dsu_union` function merges two sets by linking the smaller set to the larger one, ensuring efficient merging.

The program reads a set of edges that form a tree, identifies any cycles in the tree, and outputs the list of edges that can be removed to break the cycle and reconnect them to form a spanning tree.

Time Complexity:
- The `find` function with path compression operates in nearly constant time, O(α(n)), where α is the inverse Ackermann function. This is extremely slow-growing and is practically constant for all reasonable input sizes.
- The `dsu_union` function operates in O(α(n)) as well.
- Overall, the complexity is O(n + m * α(n)), where n is the number of nodes, and m is the number of edges. For typical inputs, this is nearly linear in the number of nodes and edges.

Space Complexity:
- The space complexity is O(n) due to the `par[]` and `group_size[]` arrays storing information for each node.

*/