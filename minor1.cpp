#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function declarations
ListNode* buildLinkedList(vector<int>& arr)
{
    ListNode *m=NULL;ListNode*ans=NULL;
    for(int i=0;i<arr.size();i++)
    {
        ListNode *newnode=new ListNode(arr[i]);
        if(i==0)
        {
            ans = newnode;
            m=newnode;
        }
        else
        {
            m->next=newnode;
            m=m->next;
        }
    }
    return ans;
}
vector<int> linkedListToVector(ListNode* head,vector<int>vec)
{
    
    while(head!=NULL)
    {
        vec.push_back(head->val);
        head=head->next;
    }
    return vec;
}
ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode*prev=NULL;ListNode*next=NULL;
    while(k!=0)
    {
        next=head->next;
        head->next=prev;
       
        prev=head;
        head=next;
        k--;
    }
    return prev;
}
vector<int> magicalConveyorBelt(int r, vector<int>& arr)
{
    int e=r;
    vector<int>vec;int k=1;
   ListNode*m=buildLinkedList(arr);
   
   int f;
   ListNode*n=m;
  while((r-k)>=0) 
  {
      f=k;
    while(k!=0)
   {
       n=n->next;
       k--;
   }
   m= reverseKGroup(m,f);
   vec= linkedListToVector(m,vec);
   k=f;
   m=n;
   r=r-k;
   k++;
   
  }
  k=abs((r-k));
  while(k!=0)
  {
    vec.push_back(arr[e-k]);
    k--;
  }

  return vec;
   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> result = magicalConveyorBelt(n, arr);

    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << "\n";

    return 0;
}