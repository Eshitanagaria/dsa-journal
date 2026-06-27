#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(const vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int pile : piles) {
            hours += pile / k;
            if (pile % k != 0) hours++;
            if (hours > h) return false;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int ans = maxPile;

        int l = 1, r = maxPile;

        while(l <= r){
            int m = l + (r-l)/2;

            if(canFinish(piles, h, m)){ //try smaller val if possible
                ans = m;
                r = m - 1;
            } 
            else {
                l = m+1;
            }
        }

        return ans;
    }
};