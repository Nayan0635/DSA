//move all zeros to End
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void moveZerosToEnd(vector<int> &arr){//BruteForse
        vector<int> temp;
        int n = arr.size();
        //store the non zero elements into temp
        for (int i = 0; i < n; i++){
            if(arr[i] != 0)
                temp.push_back(arr[i]);
        }
        //put the non zero elements in front
        int nz = temp.size();
        for (int i = 0; i < nz; i++){
           arr[i] = temp[i];
        }
        //fill zeros 
        for (int i = nz; i < n; i++){
            arr[i] = 0;
        }
    }
    vector<int> pushZerosToEnd(vector<int> &arr){//optimal
        int n = arr.size();
        int j = -1;
        for (int i = 0; i < n; i++){//find the index of zeros
            if (arr[i] == 0){
                j = i;
                break;
            }
        }
        if(j = -1) return arr;
        for (int i = j + 1; i < n; i++){//find the non zero element
            if (arr[i] != 0){
                swap(arr[i], arr[j]);//swap them
                j++;
            }
        }
    }
};

int main(){
    vector<int> vec = {1, 2, 9, 3, 4, 9, 5};
    int n = vec.size();
    Solution s;
    s.pushZerosToEnd(vec);
    for (int i = 0; i < n; i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}//16/12