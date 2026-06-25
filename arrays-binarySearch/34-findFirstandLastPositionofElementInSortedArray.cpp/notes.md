---
id: 34
title: Find First and Last Position of Element in Sorted Array
difficulty: Medium
topic: Binary Search
---

## Approach 1: Brute Force

- **What I tried:**
  - Traversed the array linearly.
  - Stored the first occurrence when I encountered the target.
  - Kept updating the last occurrence whenever I found the target again.
  - Returned `{-1, -1}` if the target was not present.

- **Why it didn't work / was slow:**
  - Required scanning the entire array even if the target appeared early.
  - Time complexity was **O(n)**, which is inefficient for large sorted arrays.

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (first == -1)
                    first = i;
                last = i;
            }
        }

        return {first, last};
    }
};
```

---

## Approach 2: Optimal (Final)

- **Key insight:**
  - Instead of finding any occurrence of the target, perform **two Binary Searches**:
    - One to find the **first occurrence**.
    - Another to find the **last occurrence**.
  - Whenever the target is found:
    - For the first occurrence, continue searching the **left half**.
    - For the last occurrence, continue searching the **right half**.
  - A helper function avoids code duplication by using a boolean flag.

- **Why this is better:**
  - Each Binary Search reduces the search space by half.
  - Two Binary Searches still take only **O(log n)** time.
  - Cleaner implementation using a reusable helper function.

```cpp
class Solution {
public:
    int findPos(vector<int>& nums, int target, bool first) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                ans = mid;

                if (first)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {
            findPos(nums, target, true),
            findPos(nums, target, false)
        };
    }
};
```

---

## Complexity

**Time:** `O(log n)`  
**Space:** `O(1)`

---

## Learnings

- Finding the **first** and **last** occurrence are two separate Binary Search problems.
- After finding the target:
  - Move **left** (`r = mid - 1`) to find the first occurrence.
  - Move **right** (`l = mid + 1`) to find the last occurrence.
- Using a helper function with a boolean flag avoids duplicate code.
- Always calculate:
  ```cpp
  mid = l + (r - l) / 2;
  ```
  instead of
  ```cpp
  mid = (l + r) / 2;
  ```
  to prevent integer overflow and safely handle edge cases.
- Even though Binary Search is performed twice, the total time complexity remains **O(log n)** since constant factors are ignored.