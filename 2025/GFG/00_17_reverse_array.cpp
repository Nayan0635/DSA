//reverse an array
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void reverseArray(vector<int> &arr){
        int n = arr.size();
        int low = 0, high = n - 1;//keep two pointers
        while (low < high){
            swap(arr[low], arr[high]);//swap the elements
            low++, high--;
        }
    }
};

int main(){
    vector<int> vec = {1, 2, 3, 4, 5};
    Solution s;
    s.reverseArray(vec);
    for (int i : vec)
        cout<<i<<" ";
    return 0;
}//17/12/24