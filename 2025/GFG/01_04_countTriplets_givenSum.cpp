/*count all triplets with given sum in sorted array
Constraints
3 <= arr.size() <= 10^4 && -10^5 <= arr[i], target <= 10^5
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int countTriplets(vector<int> & arr, int target){
        int n = arr.size();
        int count = 0;
        for (int i = 0; i < n-2; i++){
            int left = i+1, right = n-1; 
            while(left < right){
                int sum = arr[i] + arr[left] + arr[right];
                if(sum == target){
                    if(arr[left] == arr[right]){
                        int length = right - left + 1;
                        count = (length * (length + 1))/2;
                        break;
                    }
                    int leftcount = 1;//count left duplicates
                    while (left+1 < right && arr[left] == arr[left+1]){
                        left++;
                        leftcount++;
                    }
                    int rightcount = 1;//count right duplicates
                    while (right - 1 > left && arr[right] == arr[right - 1]){
                        right--;
                        rightcount--;
                    }
                    count += leftcount * rightcount;
                    left++;
                    right--;
                }
                else if(sum < target) 
                    left++;
                else
                    right++;
            }
        }
        
    }
};
int main(){
    
    Solution s;
    return 0;
}
//04/01/25