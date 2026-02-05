#include<stdio.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
int search(int *arr, int n, int key)
 {
    for(int i=0; i<n; i++)
    {
        if(arr[i] == key)return 1;
    }
    return 0;
 }
struct ListNode* modifiedList(int* arr, int n, struct ListNode* head) 
{
    struct ListNode *pre = NULL, *curr = head;
    while(curr)
    {
        if(search(arr, n, curr->val))
        {
            if(!pre)
            {
                head = curr->next;
            }
            else 
            {
                pre->next = curr->next;
            }
            curr = curr->next;
        }
        else
        {
            pre = curr;
            curr = curr->next;
        }
    }
    return head;

    
}
