//container with most water
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxWater(vector<int> &arr){
        int left = 0, right = arr.size()-1;
        int maxWater = 0;
        while(left < right){
            int width = (right - left);
            int height = min(arr[left], arr[right]);
            maxWater = max(maxWater, height*width);
            if(arr[left] < arr[right]){//look for the higher edge
                left++;
            } else{
                right--;
            }
        }
        return maxWater;
    }
};
int main(){
    vector<int> vec = {1, 5, 4, 3};
    Solution s;
    cout<<s.maxWater(vec)<<endl;
    return 0;
}//13/01/25