---
id: 81
title: Search in Rotated Sorted Array II
difficulty: Medium
topic:  Binary Search
---

## Approach 1: Brute Force

- **What I tried:**
  - Traversed the array linearly.
  - Compared each element with the target.
  - Returned `true` if the target was found; otherwise returned `false`.

- **Why it didn't work / was slow:**
  - Ignored the sorted nature of the array.
  - Required checking every element in the worst case.
  - Time complexity was **O(n)**.

---

## Complexity

**Average Time:** `O(n)`  
**Space:** `O(1)`

---