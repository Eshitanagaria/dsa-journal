#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    bool divi(vector<int>& nums, int threshold, int mid){
        int sum = 0;
        for(int i : nums){
            sum += (i + mid -1)/mid;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if( n == 1){
            if(nums[0] <= threshold) return nums[0];
            // else return -1;
        }
        int ans = -1;

        int l = 1;
        int r = *max_element(nums.begin(),nums.end());

        while(l <= r){
            int mid = l + (r-l)/2;

            if(divi(nums, threshold, mid)){
                ans = mid;
                //search for smaller possible answer
                r = mid - 1;
            }
            else{
                l = mid+ 1;
            }
        }

        return ans;



        
        
    }
};