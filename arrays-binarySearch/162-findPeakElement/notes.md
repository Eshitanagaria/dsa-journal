---
id: 162
title: Find Peak Element
difficulty: Medium
topic: Binary Search
---

## Approach 1: Brute Force (Linear Scan)

### What I tried:
- Checked corner edge cases first: if the array has one element, or if the first or last elements are peaks.
- Iterated sequentially from index `1` to `n-2`.
- Checked if the current element was strictly greater than both its left neighbor (`nums[i-1]`) and right neighbor (`nums[i+1]`).

### Why it worked:
- A peak element is defined as an element that is strictly greater than its neighbors. 
- Scanning linearly ensures that the first element meeting this local maxima condition is immediately found and returned.

---

## Approach 2: Binary Search (Optimal)

### What I tried:
- Handled the boundary/edge cases explicitly before starting the loop (`n == 1`, `a[0] > a[1]`, and `a[n-1] > a[n-2]`). This safely narrowed the internal search window to `l = 1` and `r = n - 2`.
- Inside the binary search loop, calculated the middle index `m` and checked if it was a peak: `if(a[m] > a[m-1] && a[m] > a[m+1]) return m;`.
- If `m` was not a peak, used the slope properties to shift search boundaries:
  - **Rising Slope** (`a[m] > a[m-1] && a[m] < a[m+1]`): The numbers are increasing towards the right, guaranteeing a peak exists on the right side $\rightarrow$ `l = m + 1`.
  - **Falling Slope** (`a[m] > a[m+1] && a[m] < a[m-1]`): The numbers are decreasing towards the right, meaning a peak must exist on the left side $\rightarrow$ `r = m - 1`.
  - **Valley** (else condition): `m` is smaller than both neighbors. It doesn't matter which half is discarded because a peak is guaranteed to exist in either direction due to the $-\infty$ boundary conditions $\rightarrow$ defaulted to `l = m + 1`.

### Why this is better:
- Instead of scanning sequentially, it uses local slope behaviors to determine which half of the array can be safely discarded, cutting the search space in half at each step.

---

# Optimal (Final)

### Key insight:
An array can be visualized as a sequence of rising and falling slopes. Since the problem explicitly states that $nums[-1] = nums[n] = -\infty$, any upward slope is guaranteed to eventually drop or hit the boundary, creating a peak. 

By analyzing the local slope at index `m` (comparing it with its neighbors), we can confidently move towards the increasing direction because a peak is guaranteed to exist there.

---

### Why this is better:
- Drops the time complexity from **O(n)** down to a highly efficient **O(log n)**.
- Bounding the initial search range to `[1, n-2]` prevents pesky `IndexOutOfBoundsExceptions` inside the loop, eliminating the need for bulky condition checks.

---

## Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force (Linear Scan) | **O(n)** | **O(1)** |
| Binary Search (Optimal) | **O(log n)** | **O(1)** |

---

## Learnings

- **Binary Search on Unsorted Arrays**: Binary Search does not always require a completely sorted array. It is fully viable as long as there is a clear, logical structural condition (like slopes or trends) that allows discarding half of the search space at each iteration.
- **Isolating Boundaries for Loop Cleanliness**: Separating the first and last elements as standalone edge case checks lets you restrict your search space to `[1, n-2]`. This keeps your inner neighbor-comparison checks (`m-1` and `m+1`) completely safe from going out of bounds.
- **Trusting the Slope Direction**: When tracking local maxima, always move in the direction of the increasing element. If $a[m] < a[m+1]$, moving right ensures you are climbing a slope that must eventually peak out.