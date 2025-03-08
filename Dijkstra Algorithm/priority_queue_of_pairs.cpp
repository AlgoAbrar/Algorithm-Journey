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
    // Declare a priority queue with pairs of integers, ordered by the first value in ascending order.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // Push pairs (10, 1) and (5, 2) into the priority queue
    pq.push({10, 1});
    pq.push({5, 2});

    // Output the top element of the priority queue (smallest first value)
    cout << pq.top().first << " " << pq.top().second << endl;

    return 0;
}

/*
Algorithm:
1. A priority queue is created with pairs of integers, sorted by the first integer of the pair in ascending order.
2. Two pairs `(10, 1)` and `(5, 2)` are pushed into the priority queue.
3. The program then prints the first and second elements of the pair that is at the top of the priority queue. The top pair is the one with the smallest first value.
   
   Since the pairs are sorted in ascending order by their first element, the pair with the smallest first element will be at the top.

Time Complexity:
- Pushing an element into the priority queue takes **O(log n)**, where n is the number of elements in the queue.
- Accessing the top element takes **O(1)** time.
Hence, the time complexity for pushing two elements is **O(log 2) = O(1)**, and accessing the top element takes **O(1)**.

Space Complexity:
- The priority queue stores pairs of integers, so the space complexity is **O(n)**, where n is the number of elements in the queue. In this case, **n = 2**, so space complexity is **O(2) = O(1)**.

Note:
- In this example, the smallest element based on the first value (5, 2) will be printed because of the ordering in the priority queue.
*/
