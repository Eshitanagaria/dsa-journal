#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:

    bool dayno(vector<int>& weights, int days, int capacity){
        int d = 1;
        int currweight = 0;

        for(int weight : weights){
            if(currweight + weight > capacity ){
                d++ ;
                currweight = weight;
            }else{
                currweight += weight;
            }
            
        }

        return d <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        

        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        int ans = r;
        
        while(l <= r){
            int mid = l + (r-l)/2;

            //ans is less than equal to days days
            if(dayno(weights,days, mid)){
                ans = mid;
                r = mid - 1;
            } else  {
                l = mid + 1;
            }
        }
        return ans;
        
    }
};