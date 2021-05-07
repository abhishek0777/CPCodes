#include <bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define MOD 1000000007
/*
   notes
   null->next gives segmentation fault in c++,and null pointer exception in java
*/
struct node {
  node* next;
  int data;
  node(int x)
  {
    data = x;
    next = NULL;
  }
};


node* createList()
{
  int n, num; cin >> n;
  node *head = NULL, *prv = NULL;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (!head) {
      head = new node(num);
      prv = head;
    }
    else
    {
      prv->next = new node(num);
      prv = prv->next;
    }
  }
  return head;
}

void print(node* head)
{
  if (head) {
    cout << head->data << " ";
    print(head->next);
  }
}

int itsearch(node* head, int key)
{
  int idx = 0;
  while (head) {
    if (head->data == key)return idx;
    head = head->next;
    idx++;
  }
  return -1;
}

int recsearch(node* head, int key, int idx)
{
  if (!head)return -1;
  if (head->data == key)return idx;
  return recsearch(head->next, key, idx + 1);
}

node* insertAtBeg(node* head, int key)
{
  node* temp = new node(key);
  temp->next = head;
  return temp;
}

node* insertAtEnd(node* head, int key)
{
  node* curr = head;
  //handle explicitly when LL is empty
  if (!curr)return new node(key);

  while (curr->next) {
    curr = curr-> next;
  }
  curr->next = new node(key);
  return head;
}

node* deletefirst(node* head)
{
  if (!head)return head;
  node* temp = head->next;
  delete head;
  return temp;
}
node* deletelast(node* head)
{
  //when length of LL is 0 or 1
  if (!head || !head->next)return NULL;

  node* curr = head;
  while (curr->next->next)
    curr = curr->next;
  delete curr->next;
  curr->next = NULL;
  return head;

}

node* insertAtPos(node* head, int pos, int key)
{
  node* temp = new node(key);
  if (pos == 1) {
    temp->next = head;
    return temp;
  }
  node* curr = head;
  for (int i = 1; i <= pos - 2 && curr; i++)
    curr = curr->next;
  if (!curr)return head;
  temp->next = curr->next;
  curr->next = temp;
  return head;
}

node* insertInSorted(node* head, int key)
{
  node* temp = new node(key);
  if (!head)return temp;
  if (key < head->data) {
    temp->next = head;
    return temp;
  }
  node* curr = head;
  while (curr->next && curr->next->data < key)
    curr = curr->next;
  temp->next = curr->next;
  curr->next = temp;
  return head;
}

node* middleOfList(node* head)
{
  if (!head)return head;
  node* slow = head;
  node* fast = head;
  while (fast && fast->next)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

void nthFromEnd(node* head, int n)
{
  if (!head || n <= 0) {
    cout << "-1";
    return;
  }
  // using two pointer approach
  //move first pointer n nodes ahead
  node* first = head;
  int i;
  for ( i = 1; i <= n && first; i++)first = first->next;
  if (i != n + 1) {
    cout << "-1";
    return;
  }
  node* second = head;
  while (first) {
    first = first->next;
    second = second->next;
  }
  cout << second->data;
}

node* iterReverseLL(node* head)
{
  if (!head)return head;
  node *prv = NULL, *nxt = NULL, *curr = head;
  while (curr)
  {
    nxt = curr->next;
    curr->next = prv;
    prv = curr;
    curr = nxt;
  }
  return head = prv;
}

node* rec1ReverseLL(node* head)
{
  if (!head)return head;
  if (!head->next)return head;

  node* res_head = rec1ReverseLL(head->next);
  node* res_tail = head->next;
  res_tail->next = head;
  head->next = NULL;
  return res_head;
}

//similar to iterative reverse method
node* rec2ReverseLL(node* curr, node* prv)
{
  if (!curr)return prv;
  node* nxt = curr->next;
  curr->next = prv;
  return rec2ReverseLL(nxt, curr);
}

//remove duplicates from sorted linked list
node* removeDuplicates(node* head)
{
  node* curr = head;
  while (curr && curr->next)
  {
    if (curr->next->data == curr->data)
    {
      node* temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
    }
    else curr = curr->next;
  }
  return head;
}
//-----------------------Advance problems of Linked list

//reverse patch of nodes of window size k
node* recReverseByGrpOfK(node* head, int k)
{

  node *curr = head, *prv = NULL;
  int rem = k;
  while (curr && rem--)
  {
    node* nxt = curr->next;
    curr->next = prv;
    prv = curr;
    curr = nxt;
  }
  if (curr) {
    node* res_head = recReverseByGrpOfK(curr, k);
    head->next = res_head;
  }
  return prv;
}

node* iterReverseByGrpOfK(node* head, int k)
{
  bool isFirstPass = true;
  node *curr = head, *prevFirst = NULL;
  while (curr)
  {
    node *first = curr, *prv = NULL;
    int rem = k;
    while (curr && rem--)
    {
      node* nxt = curr->next;
      curr->next = prv;
      prv = curr;
      curr = nxt;
    }
    if (isFirstPass) {
      head = prv;
      isFirstPass = false;
    }
    else {prevFirst->next = prv;}
    prevFirst = first;
  }
  return head;
}


/*
Method-1:
append one more property to node structure,i.e visited,initially false
Algorithm:
Traverse the LL,if at any node,if we find node is already visited then loop is present
other wise take it ,and then mark it visited

bool detectLoopInLL(node* head)
{
  node* curr = head;
  while (curr)
  {
    if (curr->visited)return true;
    curr->visited = true;
    curr = curr->next;
  }
  return false;
}

This method is O(n) but it modify the structure of LL.

Method-2: Hashing
TC=O(n),Aux Space=theta(n)

bool detectLoopInLL(node* head)
{
  unordered_set<node*> mpp;
  node* curr = head;
  while (curr)
  {
    if (mpp.find(curr) != mpp.end())return true;
    mpp.insert(curr);
    curr = curr->next;
  }
  return false;
}


Method-3:
Using dummy node,set next of each visited node to temp
bool detectLoopInLL(node* head)
{
  node* dummy;
  node* curr = head;
  while (curr)
  {
    if (curr->next == dummy)return true;
    node* curr_next = curr->next;
    curr->next = dummy;
  }
  return false;
}

Method-4:
Floyd cycle detection
Algorithm:
1. Initialize slow_p and fast_p = head
2.Move slow_p by 1 and fast_p by two,if these pointer meet ,then there is a loop

bool detectLoopInLL(node* head)
{
  node *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)return true;
  }
  return false;
}

Why this algorithm works,
Lets say fast pointer is ahead by k when slow pointer enters the loop(k>=0)
, Now on each iteration distance b/w them increases by 1,so when updated k = length of cycle,we return

IMP*** if fast pointer is 3 or 4 times faster ,then in some case it gives wrong ans

*/

//floyd's cycle detection
bool detectLoopInLL(node* head)
{
  node *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)return true;
  }
  return false;
}

/*
 Remove LOOP:
 Its mathematical proof is so beautiful
 <--m-><---k--->
 *-*-*-*-*-*-*-*  <--- this is the meeting point
       |       |
       *-*-*-*-*
  distance travelled by fast is 2*slow
  so ,before meeting at meeting point
  2*(m+k+x*n)=(m+k+y*n) where n is length of cycle
  (m+k)=n(y-2x)
  So we get,(m+k) is multiple of 'n'
  So if we travel (m+k) from meeting point ,we again come to the same position because (m+k) is multiple of n,so
  if we travel m,we will be k distance away from where it is(i.e start of loop),
  and if we travel slow by m too,then it moves to start of loop if we start from head again.
  Hence second meeting point is start of loop,so changing  next of prev of fast to NULL remove loop

*/

void removeLoopInLL(node* head)
{
  node *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)break;
  }
  //if there is no loop
  if (slow != fast)return;

  slow = head;
  while (slow->next != fast->next)
  {
    slow = slow->next;
    slow = fast->next;
  }
  fast->next = NULL;
  return;
}

/*
Trickier interview question:
Given an address of node(and no head pointer is given),we have to delete that node,given that node is not the last node of LL

Solution:
Copy the data of next node of given node,and then delete the next node of given node.
For ex:
LL : 1-->2-->3-->4-->5
    We have to delete node 3,
    So first copy content of next node i.e 4
    1-->2-->4-->4-->5
    Delete next of given node
    1-->2-->4------>5
    Hence we got our resultant LL

    CODE:
    givenNode->data=givenNode->next->data;
    node* temp=givenNode->next;
    givenNode->next=givenNode->next->next;
    delete temp
*/

/*
Problem: Given LL,separate LL with even sequence nodes comes first before odd nodes seq without changing order of occurences
Ex: 1 2 3 4 5 6
o/p: 2 4 6 1 2 3
Create two list for odd and even separate and keep track of start and end of both lists
and at the end,join odd list at the end of even list
*/
node* segregateEvenOdd(node* head)
{
  node *odd = NULL, *even = NULL, *curr = head, *stOdd = NULL, *stEven = NULL;
  while (curr)
  {
    if (curr->data % 2)
    {
      if (!odd)odd = curr, stOdd = odd;
      else odd->next = curr, odd = odd->next;
    }
    else
    {
      if (!even)even = curr, stEven = even;
      else even->next = curr, even = even->next;
    }
    curr = curr->next;
  }
  if (even) {
    even->next = stOdd;
    odd->next = NULL;
    return stEven;
  }
  else
  {
    odd->next = NULL;
    return stOdd;
  }

}

/*
Method-1:
Hashing
traverse any list first and store all nodes in set,then traverse second list,
the first node we get which is present in hashset already that will be the intersection point.

Method-2:
Find length of both the lists.(m and n)
traverse longer list by abs(m-n);
then travel both the list simulataneously by one.
Whenever both pointers meet,that will be the intersection point

<----------m------------>
*-*-*-*-*-*-*-*-*-*-*-*-*
          |
          *
          |  <-----n---->
          *

*/
node* intersectionPoint(node* head, node* head2)
{
  //first find le
  int m = 0, n = 0;
  node* curr = head;
  while (curr)m++, curr = curr->next;
  curr = head2;
  while (curr)n++, curr = curr->next;
  if (m > n)
  {
    ll ab = abs(m - n);
    while (ab--) {
      head = head->next;
    }
  }
  else if (m < n) {
    ll ab = abs(n - m);
    while (ab--) {
      head2 = head2->next;
    }
  }
  while (head && head2)
  {
    if (head == head2)return head;
    head = head->next;
    head2 = head2->next;
  }
  return head;
}

/*
just for checking working of algorithm
It makes 1st node of head as intersection

I/P:
6
1 2 3 4 5 6
5
6 5 4 3 2

*/
void createIntersection(node* head, node* head2)
{

  node* curr = head2;
  while (curr->next) {
    curr = curr->next;
  }
  curr->next = head;
  return;
}

/*
Pairwise swap nodes of a linked list
*/
node* pairwiseSwap(node* head)
{
  if (!head || !head->next)return head;
  node* curr = head->next->next;
  node* prv = head;
  head = head->next;
  head->next = prv;
  while (curr && curr->next)
  {
    node* nxt = curr->next->next;
    prv->next = curr->next;
    prv = curr;
    curr->next->next = prv;
    curr = nxt;
  } 5
  prv->next = curr;
  return head;
}

/*
merge two sorted LL  to make one sorted LL
*/
node* mergeSortedLL(node* head1, node* head2)
{
  if (!head1)return head2;
  if (!head2)return head1;

  node *tail = NULL, *head = NULL;
  if (head1->data <= head2->data) {
    head = tail = head1;
    head1 = head1->next;
  }
  else
  {
    head = tail = head2;
    head2 = head2->next;
  }
  while (head1 && head2)
  {
    if (head1->data <= head2->data)
    {
      tail->next = head1;
      tail = tail->next;
      head1 = head1->next;
    }
    else
    {
      tail->next = head2;
      tail = tail->next;
      head2 = head2->next;
    }
  }
  if (!head1)tail->next = head2;
  else tail->next = head1;
  return head;
}



int main() {
  FAST

  node* head = createList();

  //creat cycle
  // prv->next = head;

  //create another LL for intersection algorithm
  /*
  node* head2 = createList();
  createIntersection(head, head2);
  cout << intersectionPoint(head, head2)->data << endl;
  */

  node* head2 = createList();
  node* head3 = mergeSortedLL(head, head2);
  print(head3);


  return 0;
}