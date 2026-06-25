---
id: 33
title: Search in Rotated Sorted Array
difficulty: Medium
topic: Arrays, Binary Search
---

## Approach 1: Brute Force

- **What I tried:**
  - Traversed the array linearly.
  - Compared every element with the target.
  - Returned the index if found; otherwise returned `-1`.

- **Why it didn't work / was slow:**
  - Ignored the fact that the array was originally sorted.
  - Required checking every element in the worst case.
  - Time complexity was **O(n)**.

---

## Approach 2: Optimal (Final)

- **Key insight:**
  - Although the array is rotated, **at least one half is always sorted**.
  - Find the middle element using Binary Search.
  - Determine whether the **left half** or the **right half** is sorted.
  - Check whether the target lies within the sorted half:
    - If yes, search that half.
    - Otherwise, search the other half.
  - Repeat until the target is found or the search space becomes empty.

- **Why this is better:**
  - Eliminates half of the search space in every iteration.
  - Efficiently handles the rotation without finding the pivot explicitly.
  - Achieves logarithmic time complexity.

  ---

## Complexity

**Time:** `O(log n)`  
**Space:** `O(1)`

---

## Learnings

- In a rotated sorted array, **at least one half is always sorted**.
- First determine which half is sorted:
  - `nums[l] <= nums[mid]` → Left half is sorted.
  - Otherwise, the right half is sorted.
- Once the sorted half is identified, check whether the target lies within its range.
- There's **no need to explicitly find the pivot**; Binary Search handles the rotation naturally.
- Always calculate:
  ```cpp
  mid = l + (r - l) / 2;
  ```
  instead of:
  ```cpp
  mid = (l + r) / 2;
  ```
  to prevent integer overflow and safely handle edge cases.
- This technique is the foundation for solving many rotated-array Binary Search problems.