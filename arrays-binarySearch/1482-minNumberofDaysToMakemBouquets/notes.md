---
id: 1482
title: Minimum Number of Days to Make m Bouquets
difficulty: Medium
topic: Binary Search on Answer
---

## Approach 1: Brute Force (Linear Search)

### What I tried:
- Identified the minimum possible day (`1`) and the maximum possible day (the maximum element in the `bloomDay` array).
- Iterated sequentially day-by-day from the minimum day to the maximum day.
- For each day, ran a simulation to check if it was possible to form `m` bouquets of `k` consecutive flowers.
- Returned the first day that satisfied the condition.

### Why it didn't work / was slow:
- The maximum value in `bloomDay` can be up to $10^9$. 
- Sequential scanning requires an **O(max(bloomDay) * n)** time complexity, which inevitably results in a Time Limit Exceeded (TLE) error for large inputs.

---

## Approach 2: Binary Search on Answer (Optimal)

### What I tried:
- Added an initial base check: if the total flowers required ($m \times k$) exceeds the total number of available flowers ($n$), it is physically impossible to form the bouquets, so immediately returned `-1`.
- Defined the search range for the answer from `l = 1` to `r = max_element(bloomDay)`.
- Implemented a helper function `isValid()` to determine if `m` bouquets can be formed by day `mid`:
  - Maintained a running count of consecutive blooming flowers (`count`).
  - Iterated through `bloomDay`. If an element was $\le$ `mid`, it had bloomed, so incremented `count`.
  - Once `count == k`, formed a bouquet, incremented `bouquets`, and reset `count` to `0`.
  - If a flower had not bloomed ($>\text{mid}$), broke the consecutive streak by resetting `count` to `0`.
- If `isValid()` returned true, stored `mid` as a potential answer (`ans = mid`) and searched the left half (`r = mid - 1`) to find a smaller valid day.
- If it returned false, searched the right half (`l = mid + 1`).

### Why this is better:
- The search space of days is monotonically ordered ($1, 2, 3, \dots, \text{maxDay}$). 
- Using Binary Search cuts the range of possible days in half at each step, checking only a logarithmic number of days rather than evaluating all of them linearly.

---

# Optimal (Final)

### Key insight:
The problem displays a clear **monotonic feasibility profile**: if it's possible to make the bouquets on day $D$, it will always be possible on any day $> D$. If it's impossible on day $D$, it will remain impossible on any day $< D$. 

This predictable transition point (`False, False, ..., True, True`) makes the problem a textbook candidate for **Binary Search on Answer**.

---

### Why this is better:
- Dramatically cuts down time complexity to **O(n * log(maxDay))**, allowing it to safely pass within the execution limit.
- Using a primitive boundary check ($m \times k > n$) instantly discards impossible test cases without triggering the search loop.

---

## Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force (Linear Search) | **O(n * max(bloomDay))** | **O(1)** |
| Binary Search on Answer | **O(n * log(max(bloomDay)))** | **O(1)** |

---

## Learnings

- **Integer Overflow Risk**: Always be cautious when multiplying two parameters like `m` and `k`. If both are $10^5$, their product ($10^{10}$) will overflow a standard 32-bit signed integer. Cast the product to a larger type or evaluate it defensively:
  ```cpp
  if ((long long)m * k > n) return -1;