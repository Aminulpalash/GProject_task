#include<bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   node *next;
};
node *root = NULL;

void append(int data)
{
   if(root == NULL)
   {
      root = new node();
      root->data = data;
      root->next = NULL;
   }
   else{
      node *current_node = root;
      while(current_node->next != NULL)
      {
         current_node = current_node->next;
      }

      node *temp = new node();
      temp->data = data;
      temp->next = NULL;
      current_node->next = temp;
   }
}

void middle_node()
{
   node *mid_node = root;
   node *fast_node = root;

   while(fast_node->next != NULL )
   {
      mid_node = mid_node->next;
      if(fast_node->next->next == NULL)
         fast_node = fast_node->next;
      else
         fast_node = fast_node->next->next;
   }

   cout<<"mid = "<<mid_node->data<<endl;
}

void print()
{
    node *current_node = root;
    ///cout<<143435465768<<endl;
    int k;
    while(current_node->next != NULL)
    {
       cout<<current_node->data<<"->";
       current_node = current_node->next;
       k = current_node->data;
    }

   if(root->next != NULL)
      cout<<k<<endl;
   else
      cout<<root->data<<endl;
}


int main()
{
   string s,str;
   cin>>s;
   for(int i=0;i<s.size();i++)
   {
      if(s[i] != '-')
         str += s[i];
      if(s[i] == '-') { int k = stoi(str);append(k);
      i++;str = ""; }
   }
   int k = stoi(str);
   append(k);
   ///cout<<k<<endl;

   middle_node();

   ///print();

   return 0;
}
