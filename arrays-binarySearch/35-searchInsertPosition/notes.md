---
id: 35
title: Search Insert Position
difficulty: Easy
topic: Binary Search
---

## Approach 1: Brute Force (Linear Search)

### What I tried:
- Traversed the array from left to right.
- Checked the first index where `nums[i] >= target`.
- Returned that index immediately.
- If no such element existed, returned `nums.size()`, meaning the target should be inserted at the end.

### Why it worked:
- Since the array is sorted, the first element greater than or equal to the target is its correct position.
- If all elements are smaller than the target, the insertion position is after the last element.



---

## Approach 2: Manual Binary Search

### What I tried:
- Used Binary Search while maintaining an `ans` variable initialized to `nums.size()`.
- Whenever `nums[mid] >= target`, updated `ans = mid` and searched the left half.
- Otherwise, searched the right half.
- Returned `ans` as the insertion position.

### Why it worked:
- The insertion position is the first index where `nums[i] >= target`.
- Binary Search efficiently finds this position by repeatedly halving the search space.
- If the target exists, `ans` becomes its index.
- Otherwise, `ans` stores the correct insertion position.


---

## Approach 3: Using STL `lower_bound()` (Optimal)

### What I tried:
- Used C++ STL's `lower_bound()` function.
- It returns an iterator pointing to the first element that is **greater than or equal to** the target.
- Converted the iterator into an index by subtracting `nums.begin()`.

### Why this is better:
- Internally performs Binary Search.
- Much shorter and cleaner code.
- Less prone to implementation mistakes.
- Preferred whenever STL is allowed.

---

# Optimal (Final)

### Key insight:
The answer is simply the **first index where `nums[i] >= target`**.

- A linear scan finds it in **O(n)** time.
- Binary Search finds the same index in **O(log n)**.
- `lower_bound()` is the STL implementation of this Binary Search logic.

---

### Why this is better:
- Eliminates half of the remaining search space after every comparison.
- Much faster than Linear Search for large arrays.
- `lower_bound()` makes the implementation concise while maintaining the same efficiency.

---

## Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force (Linear Search) | **O(n)** | **O(1)** |
| Manual Binary Search | **O(log n)** | **O(1)** |
| STL `lower_bound()` | **O(log n)** | **O(1)** |

---

## Learnings

- Since the array is sorted, the insertion position is always the **first index where `nums[i] >= target`**.
- `lower_bound()` directly returns this position.
- Maintaining an `ans` variable during Binary Search helps keep track of the leftmost valid position.
- Always calculate the middle index as:
  ```cpp
  mid = low + (high - low) / 2;
  ```
  instead of:
  ```cpp
  mid = (low + high) / 2;
  ```
  This prevents **integer overflow** when `low` and `high` are very large values. Although overflow is uncommon in most coding problems, this is considered best practice as it safely handles edge cases and is the standard implementation used in interviews and production code.
- `lower_bound()` internally uses Binary Search, so it provides the same **O(log n)** time complexity with cleaner code.
```