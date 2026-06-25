---
id: 704
title: Binary Search
difficulty: Easy
topic:  Binary Search
---

## Approach 1: Iterative Method

### What I tried:
- Used two pointers, `low` and `high` to represent the current search space.
- Repeatedly calculated the middle index (`mid`) and compared it with the target.
- Narrowed the search range by updating either `low` or `high` until the element was found or the search space became empty.

### Why it worked:
- Since the array is sorted, half of the remaining elements can be discarded after every comparison.
- No recursion is involved, so it uses constant extra memory.

## Approach 2: Recursive Method

### What I tried:
- Applied the same Binary Search logic recursively.
- At each recursive call:
  - If `arr[mid] == target`, return the index.
  - If the target is smaller, recursively search the left half.
  - Otherwise, recursively search the right half.
- Base case: if `low > high`, the element is not present.

### Why it worked:
- The recursion naturally divides the problem into smaller subproblems.
- The implementation is shorter and closely follows the Divide & Conquer paradigm.

### Key insight:
Both iterative and recursive Binary Search follow the same principle:
- The array **must be sorted**.
- Compare the target with the middle element.
- Eliminate the half that cannot contain the target.
- Repeat until the target is found or the search space becomes empty.

The **iterative approach is generally preferred** because it avoids recursive function call overhead while achieving the same time complexity.

### Why this is better:
- Reduces the search space by **half** after every comparison.
- Requires significantly fewer comparisons than Linear Search.
- The iterative implementation uses **constant extra space**, making it more memory efficient.

---

## Complexity

| Method | Time | Space |
|--------|------|-------|
| Iterative Binary Search | **O(log n)** | **O(1)** |
| Recursive Binary Search | **O(log n)** | **O(log n)** (Recursion Stack) |

---
> **Note:** Prefer `mid = low + (high - low) / 2` over `(low + high) / 2`. It avoids potential integer overflow and is the standard implementation used in production code and technical interviews.

## Learnings

- Binary Search only works on **sorted arrays**.
- Always calculate the middle index as:
  ```cpp
  mid = low + (high - low) / 2;
  ```
  to avoid integer overflow.

- Loop condition for the iterative approach:
  ```cpp
  while (low <= high)
  ```

- Base case for the recursive approach:
  ```cpp
  if (low > high)
      return -1;
  ```

- Update the search range correctly:
  - Left half → `high = mid - 1`
  - Right half → `low = mid + 1`

- Both implementations have **O(log n)** time complexity.
- The iterative version is generally preferred in interviews due to its **O(1)** space complexity.
- Binary Search forms the foundation for many advanced topics, including:
  - Lower Bound
  - Upper Bound
  - First & Last Occurrence
  - Peak Element
  - Rotated Sorted Arrays
  - Binary Search on Answers