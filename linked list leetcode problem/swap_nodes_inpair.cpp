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
   else
   {
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

void print()
{
   node *current_node = root;
   int l;
   while(current_node->next != NULL)
   {
      cout<<current_node->data<<"->";
      current_node = current_node->next;
      l = current_node->data;
   }

   if(root->next != NULL)
       cout<<l<<endl;
   else
     cout<<root->data<<endl;

}

void swap_node()
{
   node *first = root;
   root = first->next;

   ///cout<<first->data<<" "<<second->data<<" "<<temp->data<<" "<<root->data<<endl;

   while(1)
   {
      node *second = first->next;
      node *temp = second->next;
      second->next = first;
      ///cout<<first->data<<" "<<second->data<<endl;

      if(temp == NULL || temp->next == NULL)
      {
         ///cout<<"ree"<<endl;
         first->next = temp;break;
      }

      first->next = temp->next;
      first = temp;
      ///cout<<first->data<<" "<<second->data<<" "<<first->next->data<<endl;
   }

}

///  1->2->3->4

int main()
{
    string s,str;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
       if(s[i]!='-')
         str += s[i];
       else{  int k = stoi(str);append(k);str="";i++;  }
    }
    int k = stoi(str);
    append(k);

   /// print();

    swap_node();

    print();

    return 0;
}
