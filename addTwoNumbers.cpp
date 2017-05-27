#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode * Lsum, * psum, * pri;
        //initiallize the pointer;
        Lsum = new ListNode(0);
        pri = Lsum;
        psum = Lsum;
        int temp = 0;
        int AddCount = 0;
        while(l1 != NULL && l2 != NULL)
        {
            temp = l1->val + l2->val + AddCount;
            if(temp < 10)
            {
                pri = psum;
                psum->val = temp;
                psum->next = new ListNode(0);
                psum = psum->next;
                AddCount = 0;
            }
            else
            {
                pri = psum;
                psum->val = temp % 10;
                psum->next = new ListNode(0);
                psum = psum->next;
                AddCount = temp / 10;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 == NULL && l2 != NULL)//l2 longer
            while(l2 != NULL)
            {
                temp = l2->val + AddCount;
                if(temp < 10)
                {
                    pri = psum;
                    psum->val = temp;
                    psum->next = new ListNode(0);
                    psum = psum->next;
                    AddCount = 0;
                }
                else
                {
                    pri = psum;
                    psum->val = temp % 10;
                    psum->next = new ListNode(0);
                    psum = psum->next;
                    AddCount = temp / 10;
                }
                l2 = l2->next;
            }

        if(l1 != NULL && l2 == NULL)//l1 longer
            while(l1 != NULL)
            {
                temp = l1->val + AddCount;
                if(temp < 10)
                {
                    pri = psum;
                    psum->val = temp;
                    psum->next = new ListNode(0);
                    psum = psum->next;
                    AddCount = 0;
                }
                else
                {
                    pri = psum;
                    psum->val = temp % 10;
                    psum->next = new ListNode(0);
                    psum = psum->next;
                    AddCount = temp / 10;
                }
                l1 = l1->next;
            }
        if(l1 == NULL && l2 == NULL && AddCount > 0)
        {
            pri = psum;
            psum->val = AddCount;
            psum->next = new ListNode(0);
            psum = psum->next;
            AddCount = 0;
        }
        ListNode * ps = psum;
        psum = pri;
        delete ps;
        psum->next = NULL;
        return Lsum;
    }
};

int main()
{
    Solution s;
    ListNode * l1, * l2, * result;
    l1 = new ListNode(0);
    l1->val = 5;
    l1->next = NULL;
    l2 = new ListNode(0);
    l2->val = 5;
    l2->next = NULL;

    result = s.addTwoNumbers(l1,l2);
    while(result != NULL)
    {
        cout<<result->val<<endl;
        result = result->next;
    }

    return 0;
}
