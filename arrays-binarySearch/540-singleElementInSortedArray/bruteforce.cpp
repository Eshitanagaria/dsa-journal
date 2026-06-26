#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();

        // If array has only one element
        if (n == 1) return arr[0];

        for (int i = 0; i < n; i++) {
            // Check if it's the first element and not equal to the next
            if (i == 0) {
                if (arr[i] != arr[i + 1])
                    return arr[i];
            }
            // Check if it's the last element and not equal to the previous
            else if (i == n - 1) {
                if (arr[i] != arr[i - 1])
                    return arr[i];
            }
            // middle
            else {
                if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                    return arr[i];
            }
        }

        return -1;
    }
};