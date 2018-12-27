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

/// 1->1->2->4->5->3->1
/// 1->4->3->2->5->6->7->3->2->4

void partition_list(int val)
{
   node *current_node = root;
   node *selected1_node = NULL;
   while(current_node->data < val)
     {
        selected1_node = current_node;
        current_node = current_node->next;
     }

     node *post_selected1_node = current_node;
     ///cout<<selected1_node->data<<endl;
     ///current_node = selected1_node->next;

     node *pre_selected2_node = NULL;
     node *post_selected2_node = NULL;
     node *selected2_node = NULL;



     if(current_node->next != NULL) {
     while(current_node->data >= val)
     {
        pre_selected2_node = current_node;
        current_node = current_node->next;
        selected2_node = current_node;
        post_selected2_node = selected2_node->next;

     }
      cout<<selected2_node->data<<endl;
      if(pre_selected2_node == root)
      {
        cout<<"root"<<endl;
         if(selected2_node->next!=NULL) pre_selected2_node->next = post_selected2_node;
         else pre_selected2_node->next = NULL;
         selected2_node->next = pre_selected2_node;
         root = selected2_node;
      }else {
        selected1_node->next = selected2_node;
        selected2_node->next = post_selected1_node;
        pre_selected2_node->next = post_selected2_node;

      }


     }else{  cout<<"ert"<<endl;}
     ///cout<<pre_selected2_node->data<<" "<<selected2_node->data<<" "<<post_selected2_node->data<<endl;
     ///cout<<selected2_node->data<<endl;


}

void print()
{
   node *current_node = root;
   while(current_node->next != NULL)
   {
      cout<<current_node->data<<"->";
      current_node = current_node->next;
   }
   if(root->next != NULL)
     cout<<current_node->data<<endl;
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
        else if(s[i]== '-')
          { int k = stoi(str); append(k);i++;str=""; }
    }
    int k = stoi(str);
    append(k);
    int val;
    cin>>val;
    partition_list(val);
    print();


}
