#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        //checking for edge cases of the leftmost and right most nums in array, and single elemnt array too
        if (n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        
        int l = 1, r = n-2;

           

        while(l <= r){
            int m = l + (r-l)/2;

            if(nums[m-1] != nums[m] && nums[m] != nums[m+1]) return nums[m];
            
            //mid is even, chck right side . if mid is odd, check left
            if ((m % 2 == 0 && nums[m] == nums[m+1]) || (m % 2 != 0 && nums[m] == nums[m-1])) {
                l = m + 1; // Left side is normal, single element is on the right
            } else {
                r = m - 1; // Disruption found, single element is on the left
            }

        }

        return -1;

    }
};