#include <vector> 
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            //we get target at mid
            if (nums[mid] == target)
                return mid;

            //if there is no rotaion checking
            if (nums[l] <= nums[mid]) {
                //target in left part of rotation
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else { //target in right part of rotation
                    l = mid + 1;
                }
            }
             //the right half must be normally sorted
            else {
                //target in right part of rotation
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {//target in left part of rotation
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};