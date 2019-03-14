#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node*left;
  Node*right;
 Node(int val) {
    data=val;
    left=NULL;
    right=NULL;
   }
};

class bist{
  public:
    Node*root;
  bist() {
   root=NULL;
   }

void insert(int val) {
   insertHelper(root,val);
    }
void insertHelper(Node*current,int val){
  if (current==NULL){
    if(root==NULL) {
   current=new Node(val);
      root=current;
      }
   }
   else if(val>current->data){
       if (current->right==NULL){
           current->right=new Node(val);
         }
         else {
           insertHelper(current->right,val);
           }
       }
      else {
        if (current->left==NULL){
         current->left=new Node(val);
         }
        else {
         insertHelper(current->left,val);
       }
     }
   }
 void display() {
    display2(root);
  }
  void display2(Node*current) {
   if (current->left!=NULL){
     	display2(current->left);
      }
    cout<<current->data<<",";
   if (current->right!=NULL){
       display2(current->right);
    }
  }


 Node*search(int v){
    return search2(root,v);
   }
 
 Node*search2 (Node*current,int v){
   if (current==NULL){
      cout<<endl;
     cout<<v<<" not present"<<endl;
     return NULL;
    }
   else {
      if (v==current->data){
    cout<<endl;
    cout<<v<<" found"<<endl;
    return current;
      }
     else if(v<current->data){
      return search2(current->left,v);
     }
     else {
       return search2(current->right,v);
      } 
    }
  }
 };

int main () {
  bist b1;
   
  b1.insert(8);
  b1.insert(2);
  b1.insert(30);
  b1.insert(5);
  b1.insert(25);
  b1.insert(6);
  b1.display();

   cout<<endl;
   int x;
  cout<<"what do you want to find?"<<endl;
  cin>>x;
  cout<<" The address of the given value "<<x<<b1.search(x)<<endl;
  return 0;
}
