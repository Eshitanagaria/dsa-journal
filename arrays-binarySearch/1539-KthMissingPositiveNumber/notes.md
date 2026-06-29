---
id: 1539
title: Kth Missing Positive Number
difficulty: Easy
topic: Binary Search
---

## Approach 1: First Attempt

- **What I tried:**
  - Traverse the array from left to right.
  - For every element `arr[i]` that is less than or equal to `k`, increment `k`.
  - As soon as an element greater than `k` is encountered, stop and return `k`.

- **Key intuition:**
  - Every number present in the array before or equal to the current value of `k` occupies a position that would otherwise count as a missing number. Therefore, each such element shifts the kth missing number one step ahead.

- **Why this works:**
  - Instead of explicitly counting missing numbers, we keep adjusting `k` whenever we encounter an existing number that falls within its range. After processing all relevant elements, `k` itself becomes the answer.

## Approach 2: Optimal (Binary Search)

- **Key insight:**
  - If no numbers were missing, the element at index `i` would be `i + 1`.
  - Therefore, the number of missing positive integers before `arr[i]` is:

  ```text
  missing = arr[i] - (i + 1)
  ```

- **How Binary Search works:**
  - Compute the middle index and calculate the number of missing elements before it.
  - If `missing < k`, the kth missing number lies on the right, so move `low = mid + 1`.
  - Otherwise, search on the left by moving `high = mid - 1`.
  - Continue until the search space is exhausted.

- **Why this works:**
  - The value of `missing` increases monotonically with the index, making binary search applicable.
  - After the search ends, `high` points to the last index where fewer than `k` numbers are missing.
  - The final answer is:

  ```text
  answer = high + 1 + k
  ```

## Complexity

Time:
- Approach 1: **O(n)**
- Approach 2: **O(log n)**

Space:
- Approach 1: **O(1)**
- Approach 2: **O(1)**

## Learnings

- The observation

  ```text
  missing = arr[i] - (i + 1)
  ```

  is the key to solving this problem efficiently.

- Binary search isn't always performed on the answer itself—it can also be applied to a monotonic property, such as the number of missing elements.

- After binary search, `high` stores the last position where the missing count is still less than `k`, which directly leads to the formula:

  ```text
  answer = high + 1 + k
  ```