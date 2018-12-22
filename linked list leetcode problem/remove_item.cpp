#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *next;
};

node *root = NULL;

void print()
{
   node *current_node = root;
   int l;
   while(current_node->next!=NULL)
   {
      cout<<current_node->val<<"->";
      current_node = current_node->next;
      l = current_node->val;
   }

    cout<<l<<endl;

}
void append(int val)
{

   if(root==NULL)
   {
      root = new node();
      root->val = val;
      root->next = NULL;
   }
   else{
       node *current_node = root;

       while(current_node->next!=NULL)
       {
           current_node = current_node->next;
       }

       node *temp = new node();
       temp->val = val;
       temp->next = NULL;
       current_node->next = temp;

   }

}

void remove_item(int val)
{
    node *current_node = root;
    node *prev_node = NULL;
    node *found_node = NULL;

    if(root->val==val)
    {
        node *temp=root;
		root=root->next;
		delete(temp);
    }
    else{

        while(current_node->next!=NULL)
         {
            if(current_node->next->val==val)
            {
                prev_node=current_node;
                found_node = current_node->next;
                ///cout<<"found"<<endl;
            }
            current_node = current_node->next;

         }
         ///cout<<prev_node->val<<endl;
         ///cout<<found_node->val<<endl;
         ///cout<<found_node->next->val<<endl;
         prev_node->next = found_node->next;
         delete(found_node);

    }


}

int main()
{
   string s,str;
   cin>>s;

   for(int i = 0;i<s.size();i++)
   {
       if(s[i]!='-')
          str+=s[i];
       if(s[i]=='-')
       {
          int k =stoi(str);
          str="";
          i++;
          append(k);
       }
   }
   int k = stoi(str);
   append(k);

   ///print();

   int p;
   cin>>p;

   remove_item(p);
   print();

   return 0;

}
