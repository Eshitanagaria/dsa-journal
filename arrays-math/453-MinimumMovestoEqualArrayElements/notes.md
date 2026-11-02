<h1> 453. Minimum Moves to Equal Array Elements</h1>

Intuition 
<!-- Describe your first thoughts on how to solve this problem. -->
We use differences instead of incrementing

# Approach
<!-- Describe your approach to solving the problem. -->
- In each operation, we increment n-1 elements by 1.
- This is equivalent to decrementing the remaining element by 1.
- To make all elements equal with minimum moves, we can consider reducing every element to the minimum element in the array.
- Therefore, the minimum number of moves is the sum of the differences between each element and the minimum element.

# Complexity
- Time complexity: O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int ans = 0;

        for(int i : nums){
            ans += (i - mini);
        }
        return ans;


    }
};
```
