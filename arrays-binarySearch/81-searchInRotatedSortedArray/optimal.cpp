#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1;

        while(l <= r){
            int m = l + (r-l)/2;

            if(nums[m] == nums[l] && nums[m]==nums[r] && nums[m] != target){
                l = l+1;
                r = r-1;
                continue;
            }

            //mid isthe number
            if(nums[m] == target) return true;

              //if there is no rotaion checking
            if (nums[l] <= nums[m]) {
                //target in left part of rotation
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                } else { //target in right part of rotation
                    l = m + 1;
                }
            }
             //the right half must be normally sorted
            else {
                //target in right part of rotation
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else {//target in left part of rotation
                    r = m - 1;
                }
            }
        }

        return false;
    }
};