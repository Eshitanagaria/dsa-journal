---
id: 875
title: Koko Eating Bananas
difficulty: Medium
topic: Binary Search on Answer
---

## Approach 1: Brute Force (Linear Search)

### What I tried:
- Found the maximum pile size in the array (`maxPile`) since Koko never needs to eat faster than the largest pile per hour.
- Iterated sequentially through all possible eating speeds $k$ from `1` to `maxPile`.
- For each speed $k$, simulated the total hours needed by iterating through all piles and calculating $\lceil \text{pile} / k \rceil$.
- Returned the first (minimum) speed $k$ that allowed Koko to finish all bananas within $h$ hours.

### Why it didn't work / was slow:
- While logically correct, scanning linearly through a large range of speeds takes **O(maxPile * n)** time. 
- When `maxPile` is large (up to $10^9$), this approach results in a Time Limit Exceeded (TLE) error.

---

## Approach 2: Binary Search on Answer (Optimal)

### What I tried:
- Realized that the search space for the eating speed $k$ is monotonic (sorted sequentially from `1` to `maxPile`).
- Set the binary search boundaries to `l = 1` and `r = maxPile`.
- In each step, calculated the middle speed `m = l + (r - l) / 2`.
- Used a helper function `canFinish()` to check if Koko can eat all bananas at speed `m` within $h$ hours:
  - Calculated required hours using integer arithmetic: `hours += pile / k; if (pile % k != 0) hours++;` (equivalent to `ceil((double)pile / k)`).
  - Early-exited the helper function if `hours > h` to optimize execution time and prevent integer overflow.
- If `canFinish` returned true, recorded `m` as a potential answer (`ans = m`) and narrowed the search space to the left half (`r = m - 1`) to see if a smaller valid speed existed.
- If `canFinish` returned false, it meant speed `m` was too slow, so shifted the search space to the right half (`l = m + 1`).

### Why this is better:
- Instead of checking every possible speed sequentially, Binary Search cuts the range of possible speeds in half at each step.
- This optimizes the speed check from linear to logarithmic efficiency.

---

# Optimal (Final)

### Key insight:
If Koko can finish all bananas at an eating speed $k$, she can definitely finish them at any speed greater than $k$. Conversely, if she cannot finish them at speed $k$, she won't be able to finish them at any speed less than $k$. 

This predictable **True/False monotone property** enables us to apply Binary Search directly on the *value range of the answer* rather than index positions.

---

### Why this is better:
- Drastically reduces the time complexity to **O(n * log(maxPile))**, which easily runs within time limits even if `maxPile` reaches $10^9$.
- Explicitly tracking accumulated hours with `long long` inside the helper prevents integer overflows when summing up total hours across multiple large piles.

---

## Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force (Linear Search) | **O(n * maxPile)** | **O(1)** |
| Binary Search on Answer | **O(n * log(maxPile))** | **O(1)** |

---

## Learnings

- **Binary Search on Answer**: Binary Search is highly effective on non-array ranges if the problem requires finding a minimum or maximum threshold value, and the validity condition transitions monotonically (e.g., `[False, False, True, True, True]`).
- **Ceil Division via Integer Math**: Avoid slow floating-point operations like `ceil(double(a)/b)`. Instead, use integer math:
  ```cpp
  int hours = a / b;
  if (a % b != 0) hours++;
  // Alternatively: (a + b - 1) / b