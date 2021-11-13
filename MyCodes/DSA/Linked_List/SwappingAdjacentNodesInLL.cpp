#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};

class AdjacentSwapping{
    ListNode *head = nullptr;
    public:
        ListNode* getNode(int val);
        void appendNode(int val);
        void swapPairs();
        ListNode* swapAdjacentPairRecursively(ListNode* odd);
        int lengthOfLL();
        void Display();
};

ListNode* AdjacentSwapping::getNode(int val){
    ListNode *newNode = new ListNode;
    newNode->val = val;
    newNode->next = nullptr;
    return newNode;
}

void AdjacentSwapping::appendNode(int val){
    ListNode *last, * newNode = getNode(val);
    if(head==nullptr){
        head = newNode;
        last = newNode;
    }
    else{
        last->next = newNode;
        last = newNode;
    }
}


void AdjacentSwapping::swapPairs(){
    /*
    ListNode *even, *odd = head, *last;
    int pos=1;
    even = odd->next;
    while(odd->next){
        if(pos==1){
            odd->next = even->next;
            even->next = odd;
            head = even;
        }else{
            even = odd;
            //even = even->next;
            if(odd->next){
                odd = odd->next;
                if(odd->next){
                    even->next = odd->next;
                    even = even->next;
                    even->next = odd;
                }
            }
        }
        pos++;
        
    }
    */
    if(head==nullptr){
        return;
    }else{
        head = swapAdjacentPairRecursively(head);
    }
}

ListNode* AdjacentSwapping::swapAdjacentPairRecursively(ListNode *odd){
    ListNode *even = odd->next;
    if(odd->next==nullptr){
        return odd;
    }
    if(even->next==nullptr){
        even->next = odd;
        odd->next = nullptr;
        return even;
    }
    if(odd->next->next){
        ListNode *lastNode = swapAdjacentPairRecursively(odd->next->next);
        even->next = odd;
        odd->next = lastNode;
        return even;
    }
    return even;
}
int AdjacentSwapping::lengthOfLL(){
    ListNode *temp = head;
    int cnt=1;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void AdjacentSwapping::Display(){
    ListNode* itr = head;
    cout<<"Start->";
    for(;itr!=nullptr; itr = itr->next){
        cout<<itr->val<<"->";
    }
    cout<<"NULL"<<endl;
}

int main(){
    
    AdjacentSwapping obj;
    obj.appendNode(1);
    obj.appendNode(2);
    obj.appendNode(3);
    obj.appendNode(4);
    obj.appendNode(5);
    obj.Display();
    obj.swapPairs();
    obj.Display();
    return 0;
}