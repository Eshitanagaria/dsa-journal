#include <vector>
using namespace std;

class Solution {
public:

    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() -1 ;
        int ans = INT_MAX;

        while(l < r){
            int mid = l + (r-l)/2 ;

            if(nums[mid] > nums[r]){
                //elimate left side as answer lies in rhs
                l = mid+1;
            } else{
                //elimnate rhs as ans in lhs, mid could be ans too
                r=mid;
            }
            ans = min(ans, nums[l]);
        }
        return nums[l];
    }
};