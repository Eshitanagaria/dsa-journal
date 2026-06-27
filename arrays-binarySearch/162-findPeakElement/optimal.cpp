#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        if(n == 1)return 0;
        if(a[0] > a[1]) return 0;
        if(a[n-1] > a[n-2]) return n-1;

        //now binary search

        int l = 1, r = n-2;
        while(l <= r){
            int m = l + (r-l)/2;

            if(a[m] > a[m-1] && a[m] > a[m+1]) return m;

            //m on rising peak
            else if(a[m] > a[m-1] && a[m] < a[m+1]) l = m+1; //delete left portion
            
            //m on falling peak
            else if(a[m] > a[m+1] && a[m] < a[m-1]) r = m-1; //delete right portion

            else l = m+1; //move in whatever way you wanna move, coz u in a valley
        }
        return -1;

    }
};