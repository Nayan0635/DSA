//Equilibrium Point
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution{
    public:
    int findEquilibrium(vector<int> &arr){
        int n = arr.size();
        int sum = 0;
        int total = accumulate(arr.begin(), arr.end(),0);
        for (int i = 0; i < n; i++){
            sum+= arr[i];
            if (sum = total - sum + arr[i])
                return i;           
        }
        return -1;
    }
};
int main(){
    vector<int> vec = {1, 2, 0, 3};
    Solution s;
    cout << s.findEquilibrium(vec) << endl;
    return 0;
}//14/01
            // if (sum == total - sum + arr[i])
            //     return i;