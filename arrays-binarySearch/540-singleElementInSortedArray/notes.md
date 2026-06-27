Markdown
---
id: 540
title: Single Element in a Sorted Array
difficulty: Medium
topic: Binary Search
---

## Approach 1: Brute Force (Linear Scan)

### What I tried:
- Handled the single-element edge case immediately (if the array size is 1).
- Traversed the array from left to right using a `for` loop to check neighbor elements and isolate the unique element.
- Handled boundary conditions explicitly:
  - For the first element (`i == 0`), checked if it is not equal to the next element (`arr[i] != arr[i + 1]`).
  - For the last element (`i == n - 1`), checked if it is not equal to the previous element (`arr[i] != arr[i - 1]`).
  - For all middle elements, checked if the element is different from both its left and right neighbors (`arr[i] != arr[i - 1] && arr[i] != arr[i + 1]`).

### Why it worked:
- Since the array is sorted, identical elements are always grouped adjacent to one another.
- If an element does not match its immediate neighbors, it is guaranteed to be the single unique element.

---

## Approach 2: Binary Search (Optimal)

### What I tried:
- Handled the edge cases explicitly up front to clean up the main loop logic:
  - Check if `n == 1` (single element array).
  - Check if the first element is unique (`nums[0] != nums[1]`).
  - Check if the last element is unique (`nums[n-1] != nums[n-2]`).
- Initialized binary search pointers safely within the internal boundaries: `l = 1` and `r = n - 2`. This completely avoids out-of-bounds errors when checking neighbors.
- Inside the `while(l <= r)` loop:
  - Calculated the middle index safely as `int m = l + (r - l) / 2;`.
  - Immediately checked if `nums[m]` is the single element by checking both its neighbors: `if(nums[m-1] != nums[m] && nums[m] != nums[m+1]) return nums[m];`.
  - Used index parity (even/odd configuration) to determine which half of the array contains the single element:
    - If `m` is **even** and matches its **right** neighbor (`nums[m] == nums[m+1]`), or if `m` is **odd** and matches its **left** neighbor (`nums[m] == nums[m-1]`), it means the pairs up to this point are completely aligned and intact. The single element must reside on the **right side** $\rightarrow$ `l = m + 1`.
    - Otherwise, the structural pair pattern has been disrupted, meaning the single element must reside on the **left side** $\rightarrow$ `r = m - 1`.

### Why this is better:
- It avoids scanning every single element sequentially.
- By leveraging both the sorted order and the structural indexing properties of the duplicate pairs, it eliminates half of the remaining search space with each comparison.

---

# Optimal (Final)

### Key insight:
In a completely paired sorted array, duplicate elements always start at an **even index** and end at an **odd index** (index pairs look like: `(0,1), (2,3), (4,5)`). 

Once the unique single element appears, it disrupts this alignment. Every duplicate pair appearing *after* the unique element shifts positions, starting instead at an **odd index** and ending at an **even index** (index pairs look like: `(odd, even)`). Binary Search can target this specific structural shift to determine whether to look left or right.

---

### Why this is better:
- Reduces the time complexity drastically from **O(n)** to **O(log n)**.
- Operates efficiently on massive arrays where a linear scan would result in a Time Limit Exceeded (TLE) error.
- Setting the search space bounds to `1` and `n-2` keeps the core binary search loop completely free of index-out-of-bounds corner checks.

---

## Complexity

| Approach | Time | Space |
|----------|------|-------|
| Brute Force (Linear Scan) | **O(n)** | **O(1)** |
| Binary Search (Optimal) | **O(log n)** | **O(1)** |

---

## Learnings

- **Even-Odd Index Pattern**: In problems involving pairs within sorted arrays, look for index parity traits. Before the unique element, duplicate pairs follow an `(even, odd)` index pattern. After it, they shift to an `(odd, even)` pattern.
- **Shrinking Search Space for Clean Logic**: When evaluating an index against its neighbors (`m-1` and `m+1`), pre-processing the boundaries (`0` and `n-1`) as independent edge cases allows you to safely compress the search range to `[1, n-2]`. This removes messy condition check clutter inside the main binary search block.
- **Binary Search Beyond Target Finding**: Binary search is not exclusive to finding a e