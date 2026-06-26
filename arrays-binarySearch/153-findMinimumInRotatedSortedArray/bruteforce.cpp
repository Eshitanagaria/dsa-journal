#include <vector>
using namespace std;

//although the question asks logn TC solution, following is the bute force ignoring thatstatement
class Solution {
public:
    int findMin(vector<int>& nums) {
        int Min = 5001;
        for(int i : nums){
            Min = min(Min, i);
        }
        return Min;
    }
};


