//peak element
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int peakElement(vector<int> &arr){
        int n = arr.size();
        if (n == 1) return 0;//that one element is my peak
        if (arr[0] > arr[1]) return 0;//first peak
        if (arr[n - 1] > arr[n - 2]) return n-1;//last peak
        int low = 1, high = n-2;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid-1]) return mid;
            if (arr[mid - 1] < arr[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }//why returning 4?
};
int main(){
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 5 ,1};
    Solution s;
    cout<<s.peakElement(vec);
    return 0;
}//15/12/24