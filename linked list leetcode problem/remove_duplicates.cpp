#include<bits/stdc++.h>
using namespace std;


struct node
{
    int roll;
    node *next;
};

node *root = NULL;

void append(int roll)
{
  if(root==NULL)
  {
     root=new node();
     root->roll = roll;
     root->next=NULL;
  }
  else{
    node *current_node=root;
    while(current_node->next!=NULL)
    {
       current_node = current_node->next;
    }

     node *new_node = new node();
     new_node->roll = roll;
     new_node->next = NULL;
     current_node->next = new_node;

  }

}

void print()
{
   node *current_node = root;
   int l;
   while(current_node->next!=NULL)
   {
      cout<<current_node->roll<<"->";
      current_node=current_node->next;
      l = current_node->roll;
   }
   cout<<l<<endl;
}

void delete_duplicate()
{
    node *current_node = root;
    while(current_node->next!=NULL)
    {
        node *selected_node = current_node->next;
        if(current_node->roll == selected_node->roll)
        {

            ///cout<<"found "<<selected_node->roll<<endl;
            current_node->next = selected_node->next;
            ///cout<<current_node->next->next->roll<<endl;

            delete(selected_node);

        }
        else
        current_node = current_node->next;
    }
}

/// 1->1->2->2->3->3

int main()
{

  string s,str="";
  cin>>s;
  for(int i = 0;i<s.size();i++)
  {
     if(s[i]!='-'){
         str+=s[i];

     }
      if(s[i]=='-'){  int k = stoi(str);append(k); i++; str="";}


  }
  int k = stoi(str);

  append(k);
  ///print();

  delete_duplicate();
  print();
  return 0;
}
