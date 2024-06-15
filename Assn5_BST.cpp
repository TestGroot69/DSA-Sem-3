#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *right;
    struct node *left;
};

class BST{
    node *root=NULL;
    public:
    node *get_Root(){
        return root;
    }
    node *insertion(node *newnode){
        node *t=root;
        if(root==nullptr){
            root=newnode;
            return newnode;
        }
        node *pre;
        while(t!=nullptr){
            pre=t;
            if(newnode->data>t->data){
                t=t->right;
            }
            else{
                t=t->left;
            }
        }
        if(newnode->data>pre->data){
            pre->right=newnode;
        }
        else{
            pre->left=newnode;
        }
        return newnode;
    }
    node *deletion(node *root,int x){
        if(root==nullptr){
            cout<<"Not Present\n";
            return root;
        }
        if(x<root->data){
            root->left=deletion(root->left,x);
            return root;
        }
        if(x>root->data){
            root->right=deletion(root->right,x);
            return root;
        }
        if(x==root->data){
            if(root->right==nullptr && root->left==nullptr){
                node *temp=root;
                delete(temp);
                return NULL;
            }
            if(root->left==NULL){
                node *temp=root;
                root=root->right;
                delete(temp);
                return root;
            }
            if(root->right==NULL){
                node *temp=root;
                root=root->left;
                delete(temp);
                return root;
            }
            else{
                int m = min_element(root->right);
                root->data= m;
                root->right = deletion(root->right, m);
            }
        }
        return root;
    }
    
    void pre_order_R(node *root){
        if(root!=nullptr){
            cout<<root->data<<" ";
            pre_order_R(root->left);
            pre_order_R(root->right);
        }
        else return;
    }
    void in_order_R(node *root){
        if(root!=nullptr){
            in_order_R(root->left);
            cout<<root->data<<" ";    
            in_order_R(root->right);
        }
        else return;
    }
    void post_order_R(node *root){
        if(root!=nullptr){
            post_order_R(root->left);
            post_order_R(root->right);
            cout<<root->data<<" ";
        }
        else return;
    }
    void pre_order_NR(node *root){
        stack <node*> s;
        while(root!=nullptr){
            cout<<root->data<<" ";
            s.push(root);
            root=root->left;
        }
        while(!s.empty()){
            root=s.top();
            s.pop();
            root=root->right;
            while(root!=nullptr){
                cout<<root->data<<" ";
                s.push(root);
                root=root->left;
            }
        }
    }
    void in_order_NR(node *root){
        stack <node*> s;
        while(root!=nullptr){
            s.push(root);
            root=root->left;
        }
        while(!s.empty()){
            root=s.top();
            cout<<root->data<<" ";
            s.pop();
            root=root->right;
            while(root!=nullptr){
                s.push(root);
                root=root->left;
            }
        }
    }
    void post_order_NR(node *root){
        stack <pair<node*,int>> s;
        while(root!=nullptr){
            s.push(make_pair(root,0));
            root = root->left;
        }
        while(!s.empty()){
            root = s.top().first;
            if(s.top().second==0){
                s.pop();
                s.push(make_pair(root,1));
                root = root->right;
                while(root!=nullptr){
                    s.push(make_pair(root,0));
                    root = root->left;
                }
            }
            else{
                cout<<s.top().first->data<<" ";
                s.pop();
            }
        }
    }
	void copy(node* one,node* &two){
		if(one==NULL){
			two=NULL;
		}
		else{
			two=new node;
			two->data=one->data;
			copy(one->left,two->left);
			copy(one->right,two->right);
		}
	}
    void mirror_image(node* root){
		if(root!=NULL){
			mirror_image(root->left);
			mirror_image(root->right);
			swap(root->left,root->right);
		}
	}
    void leaf_node(node *root){
        stack <node*> s;
        while(root!=nullptr){
            s.push(root);
            root=root->left;
        }
        while(!s.empty()){
            root=s.top();
            s.pop();
            if(root->left==nullptr && root->right==nullptr){
                cout<<root->data<<" ";
            }
            else{
                root=root->right;
                while(root!=nullptr){
                    s.push(root);
                    root=root->left;
                }
            }
        }
    }
    int height(node* root){
		if(root==NULL){
			return 0;
		}
		node* P=root;
		queue<node*> q;
		q.push(P);
		q.push(NULL);
		int Height=0;
		while(!q.empty()){
			P=q.front();q.pop();
			if(P==NULL)	Height++;
			if(P!=NULL){
				if(P->left!=NULL)	q.push(P->left);
				if(P->right!=NULL)	q.push(P->right);
			}
			else if(!q.empty()){
				q.push(NULL);
			}		
		}
		return Height;
	}
    int min_element(node *root){
        while(root->left!=NULL){
            root=root->left;
        }
        cout<<"Min element is: "<<root->data;
        return(root->data);
    }
    int max_element(node *root){
        while(root->right!=NULL){
            root=root->right;
        }
        cout<<"Min element is: "<<root->data;
        return(root->data);
    }
    bool search(node *root,int x){
        while(root!=nullptr){
            if(x>root->data){
                root=root->right;
            }
            else if(x<root->data){
                root=root->left;
            }
            else if(x==root->data){
                return true;
            }
        }
        return false;
    }
};

node *create(int x){
    node *p;
    p=new node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
int main(){
    BST T;
    int choice=99;
    int x,n;
    while (choice!=0){
        cout<<"\nChoose from the following:\n"
            <<"1->Insertion\n"
            <<"2->Deletion\n"
            <<"3->Display\n"
            <<"4->Mirror Image\n"
            <<"5->Copy\n"
            <<"6->Leaf Node\n"
            <<"7->Height of BST\n"
            <<"8->Min Element\n"
            <<"9->Max Element\n"
            <<"10->Search\n"
            <<"0->Exit\n"
            <<"Choice: ";
        cin>>choice;
        node *t=T.get_Root();
        switch (choice){
        case 1:
            cout<<"Enter the number to insert: "; 
            cin>>x;
            if(T.search(t,x)){
                cout<<"Element can't be inserted\n";
            }
            else{
                node *newnode;
                newnode=new node;
                newnode=create(x);
                T.insertion(newnode);
            }
            break;
        
        case 2:
            cout<<"Enter the number to delete: ";
            cin>>x;
            T.deletion(t,x);
            break;
        
        case 3:
            cout<<"\nChoose from the following:\n"
                <<"1->Preorder R Display\n"
                <<"2->Inorder R Display\n"
                <<"3->Postorder R Display\n"
                <<"4->Preorder NR display\n"
                <<"5->Inorder NR display\n"
                <<"6->Postorder NR display\n"
                <<"Enter your choice: ";
                cin>>choice;
                switch (choice){
                    case 1 :
                        T.pre_order_R(t);
                        cout<<endl;
                        break;

                    case 2 :
                        T.in_order_R(t);
                        cout<<endl;
                        break;

                    case 3:
                        T.post_order_R(t);
                        cout<<endl;
                        break;

                    case 4:
                        T.pre_order_NR(t);
                        cout<<endl;
                        break;

                    case 5:
                        T.in_order_NR(t);
                        cout<<endl;
                        break;

                    case 6:
                        T.post_order_NR(t);
                        cout<<endl;
                        break;

                    default:
                        break;
                    }
            break;
        
        case 4:
            T.mirror_image(t);  
            break;
        
        case 5:
            node *copy;
            T.copy(t,copy);
            T.in_order_NR(copy);
            break;
        
        case 6:
            T.leaf_node(t);
            cout<<endl;
            break;
        
        case 7:
            cout<<T.height(t)<<endl;
            break;
        
        case 8:
            T.min_element(t);
            cout<<endl;
            break;
        
        case 9:
            T.max_element(t);
            cout<<endl;
            break;
        
        case 10:
            cout<<"Enter the number to search: ";
            cin>>x;
            if(T.search(t,x)){
                cout<<"Number is present\n";
            }
            else{
                cout<<"Number is not present\n";
            }
            break;
        
        default:
            break;
        }
    }
    return 0;
}
