#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;


class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int n = nums.size();
        double mean =  accumulate(nums.begin(), nums.end(), 0) / n;

        if( floor(2 * mean) == (2 * floor(mean) + 1)) mean = ceil(mean);
        else mean = floor(mean);

        int sum = 0;
        for(int i : nums){
            sum += abs(i - mean);
        }
        return sum;
        
    }
};