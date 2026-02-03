//second largest element in array
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution{
    public:
    int bruteforce(vector<int> &arr){//extream naive solution
        int n = arr.size();
        int slargest;
        //sort(arr.begin(),arr.end());//O(NlogN)
        int largest = arr[0];//get the largest element
        for (int i = 1; i < n - 1; i++){
            if (arr[i] > largest){
                largest = arr[i];
            }
        }
        for (int i = n - 2; i >= 0; i--){//start from the back
            if (arr[i] != largest){
                slargest = arr[i];
                break;//done come out
            }
        }
        return slargest; 
    }
    int better(vector<int> &arr){
        int n = arr.size();
        int largest = arr[0];//get the largest element
        for (int i = 1; i < n - 1; i++){
            if (arr[i] > largest){
                largest = arr[i];
            }
        }
        int slargest = INT_MIN;
        for (int i = 0; i < n - 1; i++){
            if (arr[i] > slargest && arr[i] != largest){
                slargest = arr[i];
            }
        }
        return slargest;
    }
    //int maxi = max_element(arr.begin(),arr.end()) - arr.begin();
    int getslargest(vector<int> & arr){
        int n = arr.size();
        int largest = arr[0];
        int slargest = INT_MIN;
        for (int i = 1; i < n ; i++){
            if (arr[i] > largest){
                slargest = largest;
                largest = arr[i];
            }
            else if (arr[i] < largest && arr[i] > slargest){
                slargest = arr[i];
            }
        }
        return (slargest == INT_MIN)? -1: slargest;
    }
};
int main(){
    vector<int> arr = {12,35, 1, 10, 34, 1};
    Solution s;
    cout<<s.getslargest(arr);
    return 0;
}//15/12/24