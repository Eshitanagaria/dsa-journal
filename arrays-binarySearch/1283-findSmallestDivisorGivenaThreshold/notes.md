---
id: 1283
title: Find the Smallest Divisor Given a Threshold
difficulty: Medium
topic: Binary Search on Answer
---

## Approach 1: Binary Search with Floating-Point `ceil` (Initial Attempt)

### What I tried:
- Realized the search range for the divisor is bounded between `1` and the maximum element in the `nums` array (`max_element`).
- Used Binary Search to find the optimal divisor within this range.
- Inside the validation helper function `divi()`, simulated the division for each element using floating-point casting and the built-in library function: `sum += ceil((double) i / mid);`.
- Checked if the accumulated sum was less than or equal to the `threshold`. If true, saved the divisor as a candidate and looked left (`r = mid - 1`); otherwise, looked right (`l = mid + 1`).

### Why it was slow / suboptimal:
- Floating-point division (`(double) i / mid`) combined with library calls like `ceil()` introduces significant computational overhead. 
- While it passes within the time limits, performing floating-point conversions repeatedly inside a nested validation loop is slower and prone to precision edge-case errors on massive test cases.

---

## Approach 2: Binary Search with Integer Math Optimization (Optimal)

### What I tried:
- Maintained the exact same binary search framework over the value space of potential divisors `[1, max_element]`.
- Optimized the inner condition helper function `divi()` by completely eliminating floating-point conversions and standard `ceil()` functions.
- Substituted it with pure, high-performance integer math arithmetic to calculate the ceiling division:
  ```cpp
  sum += (i + mid - 1) / mid;


---
## Complexity
Time: O(n * log(max(nums)))
Space: O(1)
---
## Learnings
- **Integer Ceiling Identity**: You can accurately calculate $\lceil a / b \rceil$ for positive integers without using floats or `ceil()` by executing `(a + b - 1) / b`.
- **Performance Tax of Casting**: In tight nested loops that execute repeatedly within binary search bounds, avoid type-casting variables as it noticeably drags down performance.
- **Binary Search on Value Range**: If a validation state transitions predictably (e.g., matching a `[False, False, True, True]` monotone pattern), apply Binary Search directly to the target answer's logical range rather than array indices.
---