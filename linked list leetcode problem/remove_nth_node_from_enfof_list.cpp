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
   if(root==NULL)
   {
      root = new node();
      root->data = data;
      root->next = NULL;
   }
   else{
      node *current_node = root;
      while(current_node->next!=NULL)
      {
         current_node = current_node->next;
      }

      node *new_node = new node();
      new_node->data = data;
      new_node->next = NULL;
      current_node->next = new_node;
   }

}

void delete_pos_from_end(int pos)
{
   node *first  = root;
   node *last = root;

   for(int i = 1;i<pos;i++)
   {
      first = first->next;
   }

   ///cout<<first->data<<endl;

   node *prev = NULL;
   node *next_node = NULL;
   while(first->next!=NULL)
   {
      prev = last;
      last = last->next;
      next_node = last->next;
      first = first->next;
   }

   ///cout<<prev->data<<" "<<last->data<<" "<<next_node->data<<" "<<first->data<<endl;
    /// cout<<last->data<<endl;
    if(last==root)
    {
      node *temp = root;
      root = root->next;
      delete(temp);

    }
    else{
       prev->next = next_node;
       delete(last);
    }

}

void print()
{
   node *current_node = root;
   int k;
   while(current_node->next!=NULL)
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
      if(s[i]!='-')
        str += s[i];
      else if(s[i]=='-'){
        int k = stoi(str); append(k); i++;str="";
      }

   }
   int k = stoi(str);append(k);

   int pos;
   cin>>pos;
   delete_pos_from_end(pos);

   print();

   return 0;
}
