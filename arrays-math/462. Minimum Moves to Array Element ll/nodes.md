# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The median minimizes the sum of absolute differences between all elements and a common target value.

# Approach
<!-- Describe your approach to solving the problem. -->

Step 1. Sort the array (as median is found in sorted array)
Step 2. Find Median using formula array[n/2] 
Step 3. Make variable sum and add absolute differences of elements in the array and the median


# Complexity
- Time complexity: O(N logN)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());
        int median = nums[n/2];

        int sum = 0;
        for(int i : nums){
            sum += abs(i - median);
        }
        return sum;
        
    }
};
```

ps: Use Quickselect to find the median in linear time, avoiding the sort overhead and achieve a TC of O(N).
