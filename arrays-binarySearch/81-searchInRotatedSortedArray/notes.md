---
id: 81
title: Search in Rotated Sorted Array II
difficulty: Medium
topic: Binary Search
---

## Approach 1: Brute Force

- **What I tried:**
  - Traversed the array linearly.
  - Compared each element with the target.
  - Returned `true` if the target was found; otherwise returned `false`.

- **Why it didn't work / was slow:**
  - Ignored the sorted property of the array.
  - Required checking every element in the worst case.
  - Time complexity was **O(n)**.

---

## Approach 2: Optimal (Final)

- **Key insight:**
  - Similar to LeetCode 33, one half of the rotated array is always sorted.
  - However, duplicate elements can make it impossible to determine which half is sorted.
  - Whenever the left, middle, and right elements are all equal (and the middle isn't the target), shrink the search space by moving both pointers inward.
  - Once the ambiguity is removed, identify the sorted half and check whether the target lies within it.
  - Continue Binary Search on the appropriate half until the target is found or the search space becomes empty.

- **Why this is better:**
  - Uses Binary Search whenever possible, reducing the search space by half.
  - Handles duplicate values by eliminating ambiguous boundary elements.
  - Significantly faster than Linear Search on average.

---

## Complexity

**Average Time:** `O(log n)`  
**Worst-case Time:** `O(n)`  
**Space:** `O(1)`

---

## Learnings

- This problem is an extension of **LeetCode 33**, with the addition of duplicate elements.
- Normally, one half of the rotated array is guaranteed to be sorted.
- Duplicates can make it impossible to determine which half is sorted, so the search space must first be reduced by moving both pointers inward.
- After removing the ambiguity, the remaining logic is identical to Binary Search on a rotated sorted array.
- In arrays containing many duplicates, the algorithm may shrink the search space one element at a time, leading to a **worst-case time complexity of O(n)**.
- Always calculate the middle index using `low + (high - low) / 2` instead of `(low + high) / 2` to avoid integer overflow and safely handle edge cases.