#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    char data;
    node* next;
};

class Stck{
    node* top;
    public:
      Stck(){
        top=NULL;
      }  
    void push(char x){
        node* ptr;
        ptr=new node;
        ptr->data=x;
        ptr->next=NULL;
        if(top==NULL){
            top=ptr;
        }
        else{
            ptr->next=top;
            top=ptr;
        }

    }

    void pop(){
        if(top==NULL){
            cout<<"Empty"<<endl;
        } 
        else{
            node* temp=top;
            top=temp->next;
            delete temp;
        }
    }

    char popp(){
        if(top==NULL){
            cout<<"Empty"<<endl;
        } 
        else{
            node* temp=top;
            top=temp->next;
            return temp->data;
        }
    }

    void display(){
        node* temp=top;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }

    char stackTop(){
        return top->data;
    }

    bool stackEmpty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        } 
    }

    int precedence(char c){
        if(c=='^'){
            return 3;
        } 
        else if(c=='/'||c=='*'){
            return 2;
        }
        else if(c=='+'|| c=='-'){
            return 1;
        }
        else{
            return -1;
        } 
    }

    string infixToPosfix(string s){
        Stck p;
        string postfix;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9')){
                postfix=postfix+c;
            }
            else if(c=='('){
             p.push('(');
            }
            else if(c==')'){
                while(p.stackTop()!='('){
                    postfix=postfix+p.stackTop();
                    p.pop();
                }
                p.pop();
            }
            else{
                while(!p.stackEmpty() && precedence(c)<=precedence(p.stackTop())){
                    postfix=postfix+p.stackTop();
                    p.pop();
                }
                p.push(c);
            }
        }
        while(!p.stackEmpty()){
            postfix=postfix+p.stackTop();
            p.pop();
        }
        return postfix;
    }

    string infixToPrefix(string s1){

       reverse(s1.begin(),s1.end());
       for(int i=0;i<s1.size();i++){
          if(s1[i]=='('){
            s1[i]=')';
          } 
          else if(s1[i]==')'){
            s1[i]='(';
          }       
        }
        string prefix;
        prefix=infixToPosfix(s1);
        reverse(prefix.begin(),prefix.end());
        return prefix;
    }

    int evaluate(char token, int op1, int op2){
        if(token=='+'){
            return op1+op2;
        }
        else if(token=='*'){
            return op1*op2;
        }
        else if(token=='-'){
            return op1-op2;
        }
        else if(token=='/'){
            return op1/op2;
        }
    }

    int evalOfPostfix(char postfix[],int a){
        Stck q;
        int op1,op2,val;
        for(int i=0;i<a;i++){
            char token=postfix[i];
            if(isalnum(token)){
                q.push(token);
            }
            else{
                op2=q.popp()-'0';
                op1=q.popp()-'0';
                if(op1==0 && token=='/'){
                    cout<<"Cannot Divide By Zero"<<endl;
                    return -1;
                }
                val=evaluate(token, op1, op2);
                q.push(val+'0');
            }
        }
        val=q.popp()-'0';
        return val;
    }

    int evalOfPrefix(char prefix[], int a){
        Stck q;
        int op1,op2,val;
        char revprefix[a];
        for(int i=0;i<a;i++){
            revprefix[i]=prefix[a-i-1];
        }
        for(int i=0;i<a;i++){
            char token=revprefix[i];
            if(isalnum(token)){
                q.push(token);
            }
            else{
                op1=q.popp()-'0';
                op2=q.popp()-'0';
                if(op2==0 && token=='/'){
                    cout<<"Cannot Divide By Zero"<<endl;
                    return -1;
                }
                val=evaluate(token, op1, op2);
                q.push(val+'0');
            }
        }
        val=q.popp()-'0';
        return val;
    }
};

int main(){
    Stck obj;
    while(true){
        cout<<"Choose the Operation that you want to perform :\n1. Infix to Postfix\n2. Infix to Prefix\n3. Evalution of Postfix\n4. Evalution of Prefix\n5. Exit"<<endl;
        int choice;cin>>choice;
        switch(choice){
            case 1:{
                cout<<endl;
                cout<<"Enter infix string :";
                string str1;cin>>str1;
                cout<<" Postfix : "<<obj.infixToPosfix(str1)<<endl;
                break;
            }
            case 2:{
                cout<<endl;
                cout<<"Enter infix string :";
                string str2;cin>>str2;
                cout<<"Prefix : "<<obj.infixToPrefix(str2)<<endl;
                break;
            }
            case 3:{
                cout<<endl;
                cout<<"Enter Size of Postfix String : ";
                int a;
                cin>>a;
                cout<<"Enter Postfix String : ";
                char postfix[a];
                for(int i=0;i<a;i++){
                    cin>>postfix[i];
                }
                cout<<"Result of Evaluation : "<<obj.evalOfPostfix(postfix, a)<<endl;
                break;
            }
            case 4:{
                cout<<endl;
                cout<<"Enter Size of Prefix String : ";
                int a;
                cin>>a;
                cout<<"Enter Prefix String : ";
                char prefix[a];
                for(int i=0;i<a;i++){
                    cin>>prefix[i];
                }
                cout<<"Result of Evaluation : "<<obj.evalOfPrefix(prefix, a)<<endl;
                break;
            }
            default :{
                cout<<"Invalid choice!!!!"<<endl;
            }
        }
        cout<<endl;
        cout<<"Press 1 to Continue \nPress 2 to Exit \n"<<endl;
        int z;cin>>z;
        if(z==2) {
            cout<<"THANK YOU FOR USING THIS PROGRAM!!!!"<<endl;
            break;
        }
    }
}