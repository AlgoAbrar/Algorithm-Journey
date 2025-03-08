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

// Recursive function to calculate the factorial of a number
int fact(int n)
{
    if(n == 1)  // Base case: factorial of 1 is 1
        return 1;
    return n * fact(n - 1);  // Recursive case: factorial of n is n * factorial of (n-1)
}

int main()
{
    // Output the factorial of 5
    cout << fact(5);  // Expected output: 120
    return 0;
}

/*
Algorithm:
1. The `fact()` function uses recursion to calculate the factorial of a number.
2. The base case is when `n` equals 1, in which case the factorial is 1.
3. The recursive case multiplies the current number `n` by the factorial of `n-1`.
4. This process repeats until the base case is reached.

Time Complexity:
- The time complexity of this recursive function is **O(n)**, where `n` is the number for which the factorial is being calculated. Each recursive call reduces `n` by 1 until it reaches 1.

Space Complexity:
- The space complexity is also **O(n)** due to the depth of the recursion stack, as there are `n` recursive calls on the call stack before reaching the base case.

Note:
- This code assumes that the input number `n` is a positive integer. In practical scenarios, an additional base case could be added to handle invalid inputs like `n <= 0`.
*/
