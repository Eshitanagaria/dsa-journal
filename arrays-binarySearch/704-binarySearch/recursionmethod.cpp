#include <vector>
using namespace std; 

class Solution {
public:
    int Binarysearch(vector<int>& nums, int target, int low, int high){
        if (low > high) {
            return -1;
        }

        int mid = low + (high-low)/2; //better optimization

        if(nums[mid] == target) return mid;
        else if (nums[mid] < target) {
           return Binarysearch(nums, target, mid+1 , high );
        }
        else{
            return Binarysearch(nums, target, low, mid-1);
        }
    }
    int search(vector<int>& nums, int target) {
        return Binarysearch(nums, target, 0, nums.size()-1);                
    }
};