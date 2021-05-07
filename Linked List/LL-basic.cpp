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


int main() {
  FAST
  int n, num; cin >> n;
  node* head = NULL;
  node* prv = NULL;
  for (int i = 0; i < n; i++)
  {
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
  print(head);
  head = removeDuplicates(head);
  cout << endl;
  print(head);
  return 0;
}