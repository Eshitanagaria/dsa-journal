---
id: 153
title: Find Minimum in Rotated Sorted Array
difficulty: Medium
topic: Binary Search
---

## Approach 1: Brute Force

- **What I tried:**
  - Traversed the entire array.
  - Kept track of the minimum element seen so far.
  - Returned the smallest element after checking all values.

- **Why it didn't work / was slow:**
  - Ignored the fact that the array was originally sorted and only rotated.
  - Required visiting every element even though the answer could be found without scanning the entire array.
  - Time complexity was **O(n)**, whereas the problem specifically asks for an **O(log n)** solution.

---

## Approach 2: Optimal (Final)

*To be added.*

---

## Complexity

**Time:** `O(n)`  
**Space:** `O(1)`

---

## Learnings

- A simple linear scan correctly finds the minimum element.
- However, since the array is **sorted and rotated**, there is additional structure that can be exploited.
- The follow-up requires an **O(log n)** solution, indicating that **Binary Search** should be used instead of Linear Search.
- Before optimizing, it's often helpful to write the brute-force solution first to understand the problem and establish correctness.