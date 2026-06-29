#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool present(string word, char x){
        for(char w : word){
            if(w == x) return true;
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector <int> ans;
        for(int i = 0; i < words.size();i++){
            if(present(words[i], x)) ans.push_back(i);
        }
        return ans;
    }
};