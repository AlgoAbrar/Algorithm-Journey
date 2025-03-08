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

// Function to find the leader (root) of the set using path compression (O(logN))
int find(int node)   
{
    if(par[node] == -1) 
        return node;  // If the node is the leader, return it.
    
    int leader = find(par[node]); // Recursively find the leader (root) of the set
    par[node] = leader;           // Path compression: Directly link the node to its leader to speed up future queries
    return leader;                // Return the leader
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
    cout << find(4) << endl;

    // Output the parent array showing the leader for each node
    for(int i = 0; i < 6; i++)
        cout << i << " -> " << par[i] << endl;

    return 0;
}

/*
Algorithm:
1. The function `find(int node)` recursively finds the leader (root) of the set containing the given node.
2. Path compression is used: after finding the leader of the set, the node is directly linked to the leader to optimize future queries.
3. If the parent of a node is -1, it is its own leader (root of its set).
4. The `main()` function initializes the `par[]` array, simulating the disjoint sets with union-find relations.
5. The program calls the `find()` function for node 4 and outputs the leader. Then, it prints the `par[]` array.

Time Complexity:
- The time complexity of the `find()` function is **O(logN)** due to the path compression. Path compression helps flatten the tree structure, making future queries faster.

Space Complexity:
- The space complexity is **O(N)**, where `N` is the number of nodes. This is because we store the parent of each node in the `par[]` array.

Note:
- This is a basic implementation of the Union-Find (Disjoint Set) data structure with path compression, which is often used in problems involving connected components, network connectivity, or dynamic connectivity.
*/
