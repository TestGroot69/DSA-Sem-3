#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    int lbit;
    int rbit;
    struct node *left;
    struct node *right; 
};
class TBST{
public:
    node *head=new node;
    node *root;
    TBST(){
        head->rbit=1;   
        head->right=head;
        head->data=696969;
        head->lbit=0;
        head->left=NULL;
        root=NULL;
    }
    void insert(node *root,node *temp){
        if(temp->data<root->data){
            if(root->lbit==0){
                temp->left=root->left;
                temp->lbit=0;
                root->left=temp;
                root->lbit=1;
                temp->right=root;
                temp->rbit=0;
            }
            else{
                insert(root->left,temp);
            }
        }
        else if(temp->data>root->data){
            if(root->rbit==0){
                temp->right=root->right;
                temp->rbit=0;
                root->right=temp;
                root->rbit=1;
                temp->left=root;
                temp->lbit=0;
            }
            else{
                insert(root->right,temp);
            }
        }
        else{
            cout<<"Duplicate element can't be inserted!!!\n";
        }
    }
    void create(int x){
        node *temp;
        temp=new node;
        temp->left=NULL;
        temp->right=NULL;
        temp->lbit=0;
        temp->rbit=0;
        temp->data=x;
        if(root==NULL){
            root=temp;
            head->lbit=1;
            head->left=root;
            temp->left=head;
            temp->lbit=0;
            temp->right=head;
            temp->rbit=0;
        }
        else{
            insert(root,temp);
        }
    }
    void pre_order(){
        node *t=head->left;
        do{
            while(t->lbit!=0){
                cout<<t->data<<" ";
                t=t->left;
            }
            cout<<t->data<<" ";
            while(t->rbit==0){
                t=t->right;
            }
            t=t->right;
        }while(t!=head);
    }
    void in_order(){
        node *t=head->left;
        do{
            while(t->lbit!=0){
                t=t->left;
            }
            cout<<t->data<<" ";
            while(t->rbit==0){
                t=t->right;
                if(t!=head){
                    cout<<t->data<<" ";
                }
            }
            t=t->right;
        }while(t!=head);
    }
};

int main(){
    TBST T;
    int choice=11,x,n;
    while(choice!=0){
        cout<<"\nChoose from the following:\n"
            <<"1->Insertion\n"
            <<"2->Pre Order Display\n"
            <<"3->In Order Display\n"
            <<"0->Exit\n"
            <<"Choice: ";
        cin>>choice;
        switch (choice){
        case 1:
            cout<<"Enter the number to insert: ";
                cin>>x;
                T.create(x);
            break;

        case 2:
            T.pre_order();
            break;
        case 3:
            T.in_order();
            break;

        default:
            break;
        }
    }

return 0;
}