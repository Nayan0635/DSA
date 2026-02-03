//count occurance
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int countFreq(vector<int> & arr, int target){
        int cnt = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++){
            if (arr[i] == target){
                cnt++;
            } 
        }
        return cnt;
    }
};
int main(){
    
    Solution s;
    return 0;
}//18/12