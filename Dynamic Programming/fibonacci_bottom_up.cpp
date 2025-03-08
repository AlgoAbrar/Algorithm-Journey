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

int main()
{
    // Taking the input for n
    int n;
    cin >> n;

    // Array to store the Fibonacci numbers
    int fibo[n+1];

    // Base cases: Fibonacci of 0 is 0 and Fibonacci of 1 is 1
    fibo[0] = 0;
    fibo[1] = 1;

    // Loop to calculate the Fibonacci numbers from 2 to n
    for(int i = 2; i <= n; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];  // Fibonacci relation
    }

    // Output the nth Fibonacci number
    cout << fibo[n] << endl;

    return 0;
}

/*
Algorithm:
1. Initialize an array `fibo` where `fibo[i]` stores the ith Fibonacci number.
2. Set the base values:
   - `fibo[0] = 0`
   - `fibo[1] = 1`
3. Iterate from `i = 2` to `n` to compute each Fibonacci number as the sum of the previous two numbers: `fibo[i] = fibo[i-1] + fibo[i-2]`.
4. Finally, print the nth Fibonacci number.

Time Complexity:
- The time complexity of this approach is **O(n)**, as we only need to iterate once through the array from 2 to `n` to compute the Fibonacci numbers.

Space Complexity:
- The space complexity is **O(n)** due to the space required for the `fibo` array which stores Fibonacci numbers from `0` to `n`.

Note:
- This approach uses dynamic programming with an array to store the intermediate Fibonacci numbers, which avoids the recomputation of Fibonacci values for smaller indices.
*/
