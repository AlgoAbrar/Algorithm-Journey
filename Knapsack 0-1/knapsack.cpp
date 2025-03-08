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

int val[1005], weight[1005];

int knapsack(int i, int mx_weight)
{
    if(i < 0 || mx_weight <= 0) // Base case: No items left or knapsack is full
        return 0;

    if(weight[i] <= mx_weight) // Check if the current item can be included in the knapsack
    {
        // Two options: Include the item or exclude it
        int op1 = knapsack(i-1, mx_weight - weight[i]) + val[i]; // Include the item
        int op2 = knapsack(i-1, mx_weight); // Exclude the item
        return max(op1, op2); // Return the maximum of the two options
    }
    else
    {
        // If the item cannot be included due to weight limit, exclude it
        return knapsack(i-1, mx_weight);
    }
}

int main()
{
    int n, mx_weight;
    cin >> n; // Input number of items

    // Input values and weights for each item
    for(int i = 0; i < n; i++)
        cin >> val[i];
    for(int i = 0; i < n; i++)
        cin >> weight[i];
    cin >> mx_weight; // Input maximum weight capacity of the knapsack

    // Output the result of the knapsack function, which is the maximum value that can be obtained
    cout << knapsack(n-1, mx_weight) << endl;

    return 0;
}
/*Algorithm:
This is the recursive implementation of the 0/1 Knapsack problem using a top-down approach. 
The idea is to recursively explore two options for each item:
1. Include the current item in the knapsack (if weight permits).
2. Exclude the current item from the knapsack.
For each item, the function checks the maximum value achievable either by including the item or excluding it.

Time Complexity:
The time complexity of this recursive approach is O(2^n), where n is the number of items. This is because, for each item, we have two choices: either include it in the knapsack or exclude it, leading to an exponential growth of recursive calls.

Space Complexity:
The space complexity is O(n) due to the recursion stack, where n is the number of items.

*/