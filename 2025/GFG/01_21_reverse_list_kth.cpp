//linked list group reverse
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution{
    public:
    Node *reversekGroup(Node *head, int k){
        if (!head)
            return nullptr;
        Node* prev = nullptr;
        Node* curr = head;
        int cnt = 0;
        Node* nextnode = nullptr;
        while (curr != nullptr && cnt<k)
        {
            nextnode = curr->next; //store next node
            curr->next = prev;
            prev = curr;
            curr = nextnode;
            cnt++;
        }
        if(nextnode) {
            head->next = reversekGroup(nextnode, k);
        }
    }
};
int main(){
    
    Solution s;
    return 0;
}