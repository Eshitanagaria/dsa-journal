---
id: 453
title: Minimum Moves to Equal Array Elements
difficulty: Medium
topic: Maths
---


## Approach 1: First attempt
- In each operation, we increment n-1 elements by 1.
- This is equivalent to decrementing the remaining element by 1.
- To make all elements equal with minimum moves, we can consider reducing every element to the minimum element in the array.
- Therefore, the minimum number of moves is the sum of the differences between each element and the minimum element.



## Complexity
Time: O(N)
Space: O(1)

## Learnings
- Work smart not hard