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

// Function to find the leader (root) of the set using iterative method (O(N))
int find(int node)    
{
    // Iteratively traverse to find the root (leader) of the set
    while(par[node] != -1)
    {
        node = par[node];  // Move to the parent node
    }
    return node;  // Return the root (leader) of the set
}

int main()
{
    // Initializing the parent array
    memset(par, -1, sizeof(par));

    // Manually setting parent values to simulate a disjoint set (or union-find)
    par[0] = 1;
    par[1] = -1;  // Node 1 is the leader of its set
    par[2] = 1;   // Node 2 is in the set led by Node 1
    par[3] = 1;   // Node 3 is in the set led by Node 1
    par[4] = 5;   // Node 4 is in the set led by Node 5
    par[5] = 3;   // Node 5 is in the set led by Node 3

    // Find the leader (root) of the set containing node 4
    cout << find(4) << endl;  // Expected output: 3 (since Node 3 is the leader of Node 4)

    return 0;
}

/*
Algorithm:
1. The `find(int node)` function iteratively traverses up the tree of parents until it reaches the root (leader) of the set.
2. The loop continues until `par[node] == -1`, which signifies that the node is the root of its set.
3. The `main()` function initializes the `par[]` array, simulating the disjoint sets with union-find relations.
4. The program calls the `find()` function for node 4 and outputs the leader.

Time Complexity:
- The time complexity of the `find()` function is **O(N)** in the worst case, where `N` is the depth of the tree (the number of nodes that need to be traversed). In a flat tree, the complexity would be constant, but in a skewed tree, it can become linear.

Space Complexity:
- The space complexity is **O(N)**, as we are storing the parent for each node in the `par[]` array.

Note:
- This is a basic implementation of the Union-Find (Disjoint Set) data structure using an **iterative approach** for finding the leader. This implementation does not use path compression, which could help reduce the time complexity in future queries.
*/
