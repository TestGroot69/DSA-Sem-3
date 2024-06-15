#include<bits/stdc++.h>

using namespace std;
#define endl "\n"

struct node{
    public:
        char data;
        node* left;
        node *right;
};

class ExpressionTree{
    node *root;

    public:
        void ExpressionTreeFromPostfix(){
            root = nullptr;
            stack<node*>s;
            node *top;
            node *t1;
            node *t2;
            string postfix;
            cout<<"Enter the Postfix Expression : "<<endl;
            cin>>postfix;
            for(int i=0;i<postfix.size();i++){
                if(isalnum(postfix[i])){
                    top=new node;
                    top->left=NULL;
                    top->right=NULL;
                    top->data=postfix[i];
                    s.push(top);
                }
                else{
                    t1=s.top();
                    s.pop();
                    t2=s.top();
                    s.pop();
                    top=new node;
                    top->right=t1;
                    top->left=t2;
                    top->data=postfix[i];
                    root=top;
                    s.push(root);
                }
            }
        }

        void ExpressionTreeFromPrefix(){
            root = nullptr;
            stack<node*>s;
            node *top;
            node *t1;
            node *t2;
            string prefix;
            cout<<"Enter the Prefix Expression : "<<endl;
            cin>>prefix;
            for(int i=prefix.size()-1;i>=0;i--){
                if(isalnum(prefix[i])){
                    top=new node;
                    top->left=NULL;
                    top->right=NULL;
                    top->data=prefix[i];
                    s.push(top);
                }
                else{
                    t1=s.top();
                    s.pop();
                    t2=s.top();
                    s.pop();
                    top=new node;
                    top->left=t1;
                    top->right=t2;
                    top->data=prefix[i];
                    root=top;
                    s.push(root);
                }
            }
        }

        void RecursiveInorderTraversal(node* x){
            if(x==NULL){
                return;
            }
            else{
                RecursiveInorderTraversal(x->left);
                cout<<x->data;
                RecursiveInorderTraversal(x->right);
            }
        }

        void trav1(){
            RecursiveInorderTraversal(root);
            cout<<endl;
        }

        void NonRecursiveInorderTraversal(node* x){
            stack<node*>s;
            while(x!=NULL){
                s.push(x);
                x=x->left;
            }
            while(!s.empty()){
                x=s.top();
                s.pop();
                cout<<x->data;
                x=x->right;

                while(x!=NULL){
                    s.push(x);
                    x=x->left;
                }
            }
        }

        void trav2(){
            NonRecursiveInorderTraversal(root);
            cout<<endl;
        }

        void RecursivePreorderTraversal(node* x){
            if(x==NULL){
                return;
            }
            else{
                cout<<x->data;
                RecursivePreorderTraversal(x->left);
                RecursivePreorderTraversal(x->right);
            }
        }

        void trav3(){
            RecursivePreorderTraversal(root);
            cout<<endl;
        }

        void NonRecursivePreorderTraversal(node* x){
            stack<node*>s;
             while(x!=NULL){
                cout<<x->data;
                s.push(x);
                x=x->left;
            }
            while(!s.empty()){
                x=s.top();
                s.pop();
                x=x->right;

                while(x!=NULL){
                    cout<<x->data;
                    s.push(x);
                    x=x->left;
                }
            }
        }

        void trav4(){
            NonRecursivePreorderTraversal(root);
            cout<<endl;
        }

        void RecursivePostorderTraversal(node* x){
            if(x==NULL){
                return;
            }
            else{
                RecursivePostorderTraversal(x->left);
                RecursivePostorderTraversal(x->right);
                cout<<x->data;
            }
        }

        void trav5(){
            RecursivePostorderTraversal(root);
            cout<<endl;
        }

        node* pre;
        void NonRecursivePostorderTraversal(node* x){
            stack<node*>s;
            while(x!=NULL){
                s.push(x);
                x=x->left;
            }
            while(!s.empty()){
                x=s.top();
                bool flag = 0;
                if (x->right == NULL || x->right == pre){
                    cout<<x->data;
                    s.pop();
                    if(x->right == pre){
                        flag = 1;
                    }
                    pre=x;
                }
                x=x->right;

                while(x!=NULL and flag == 0){
                    s.push(x);
                    x=x->left;
                }
            }
        }

        void trav6(){
            NonRecursivePostorderTraversal(root);
            cout<<endl;
        }
};

int main(){
    int option = 1, trav_opt = 1;

    ExpressionTree t;
    
    while(option!=4){
        cout<<"Choose the operation you want to perform: "<<endl;
        cout<<"1. Postfix Expression Tree"<<endl;
        cout<<"2. Prefix Expression Tree"<<endl;
        cout<<"3. Traversal"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>option;

        switch(option){
            case 1:
                t.ExpressionTreeFromPostfix();
                break;
            case 2:
                t.ExpressionTreeFromPrefix();
                break;
            case 3:
                cout<<"Choose the desired traversal technique : "<<endl;
                cout<<"1. Recursive Inorder Traversal"<<endl;
                cout<<"2. Non-Recursive Inorder Traversal"<<endl;
                cout<<"3. Recursive Preorder Traversal"<<endl;
                cout<<"4. Non-Recursive Preorder Traversal"<<endl;
                cout<<"5. Recursive Postorder Traversal"<<endl;
                cout<<"6. Non-Recursive Postorder Traversal"<<endl;
                cin>>trav_opt;

                switch(trav_opt){
                    case 1:
                        t.trav1();
                        break;
                    case 2:
                        t.trav2();
                        break;
                    case 3:
                        t.trav3();
                        break;
                    case 4:
                        t.trav4();
                        break;
                    case 5:
                        t.trav5();
                        break;
                    case 6:
                        t.trav6();
                        break;
                }
                break;
            case 4:
                cout<<"THANK YOU FOR USING THIS PROGRAM!!!!"<<endl;
                break;
        }   
    }
}