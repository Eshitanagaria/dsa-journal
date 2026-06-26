---
id: 540
title: Single Element in a Sorted Array
difficulty: Medium
topic: Binary Search
---

## Approach 1: Brute Force (Method 1)

- **What I tried:**
  - Traversed the array element by element.
  - Since every element appears exactly twice except one, checked whether the current element was different from its adjacent elements.
  - Handled the first and last elements separately to avoid out-of-bounds access.
  - Returned the element that had no matching neighbor.

- **Why it didn't work / was slow:**
  - Required scanning the array sequentially until the unique element was found.
  - Did not utilize the fact that the array was sorted.
  - Time complexity was **O(n)**, whereas the problem requires an **O(log n)** solution.

---

## Approach 2: Optimal (Final)

*To be added.*

---

## Complexity

**Time:** `O(n)`  
**Space:** `O(1)`

---

## Learnings

- Since every element except one appears exactly twice, the unique element is the one that doesn't match either of its neighbors.
- Boundary elements (first and last) need to be handled separately to prevent invalid index access.
- Although this approach is simple and correct, it ignores the sorted property of the array.
- The follow-up asks for an **O(log n)** solution, indicating that Binary Search can be used by leveraging the pairing pattern in the sorted array.