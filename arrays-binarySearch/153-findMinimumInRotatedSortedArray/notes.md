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

- **Key insight:**
  - Even though the array is rotated, one half is always sorted.
  - Compare the middle element with the rightmost element:
    - If the middle element is greater than the rightmost element, the minimum must lie in the right half.
    - Otherwise, the minimum lies in the left half, and the middle element could itself be the answer.
  - Continue narrowing the search space until only the minimum element remains.

- **Why this is better:**
  - Eliminates half of the search space in every iteration.
  - Does not require finding the rotation point explicitly.
  - Efficiently finds the minimum element in logarithmic time.

---

## Complexity

**Time:** `O(log n)`  
**Space:** `O(1)`

---

## Learnings

- In a rotated sorted array without duplicates, comparing the middle element with the rightmost element is enough to determine which half contains the minimum.
- If the middle element is greater than the rightmost element, the minimum lies in the right half.
- Otherwise, the minimum lies in the left half, and the middle element should not be discarded since it could be the minimum.
- The search continues until the search space shrinks to a single element, which is the minimum.
- Always calculate the middle index using `low + (high - low) / 2` instead of `(low + high) / 2` to avoid integer overflow and safely handle edge cases.