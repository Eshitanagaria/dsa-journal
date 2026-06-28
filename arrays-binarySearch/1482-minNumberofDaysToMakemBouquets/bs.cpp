#include <vector>
#include <algorithm>
using namespace std;

class Solution {

public:

    bool bloom(vector<int>& bloomDay, int m, int k, int day){
        int cnt = 0;
        int bq = 0;
        for(int i : bloomDay){
            if ( i <= day) {
                cnt++ ; 
                if(cnt == k){
                    bq ++ ;
                    cnt = 0;
                }
            } else{
                cnt = 0;
            }
        }

        return bq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n)
            return -1; // not possible
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int days = -1;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(bloom(bloomDay, m, k, mid)){
                days = mid;
                //lets check possibility of smaller day
                r = mid -1;
            } else {
                //check in right area of mid
                l = mid + 1;
            }

        }


        return days;
    }
};