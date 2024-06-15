#include<bits/stdc++.h>
using namespace std;

void enqueue(int value,int queue[], int size,int &f,int &r){
    if(f==-1 && r==-1){
        f=0;
        r=0;
        queue[r]=value;
    }
    else if((r+1)%size==f){
        cout<<"Queue is Full!!!!"<<endl;
    }
    else{
        r=(r+1)%size;
        queue[r]=value;
    }
}

void dequeue(int queue[],int size,int &f,int &r){
    if(f==-1 && r==-1){
        cout<<"Queue is Empty"<<endl;
    }
    else if(f==r){
        cout<<"Deleted Element is :"<<queue[f]<<endl;
        f=-1;
        r=-1;
    }
    else{
        cout<<"Deleted Element is :"<<queue[f]<<endl;
        f=(f+1)%size;
    }

}

void display(int queue[],int size,int &f,int &r){
    if(f==-1 && r==-1){
        cout<<"Queue is Empty!!!!"<<endl;
    }
    else if(f==r){
        cout<<"Queue contains Single Element : "<<queue[f]<<endl;
    }
    else if(f<r){
        cout<<"QUEUE :"<<endl;
        for(int i=f;i<=r;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
    else if(f>r){
        cout<<"QUEUE :"<<endl;
        for(int i=f;i<size;i++){
            cout<<queue[i]<<" ";
        }
        for(int i=0;i<=r;i++){
            cout<<queue[i]<<" ";
        }
    }
}

int main(){
    int size;
    cout<<"Enter the Size of Circular Queue :"<<endl;
    cin>>size;
    int value;
    int f=-1,r=-1;
    int queue[size];
    bool flag=1;
    while(flag){
        cout<<"ENTER YOUR CHOICE :\n1. Insertion(Enqueue) \n2. Deletion(Dequeue) \n3. Display the Queue \n4. Exit \n"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the value you want to Insert :"<<endl;
                cin>>value;
                enqueue(value,queue,size,f,r);
                break;
            
            case 2:
                dequeue(queue,size,f,r);
                break;
            
            case 3:
                display(queue,size,f,r);
                break;
            
            case 4:
                break;
            
            default:
                cout<<"Invalid Choice!!!!"<<endl;
        }
        cout<<endl;
        cout<<"Press 1 to Continue \nPress 0 to Exit \n"<<endl;
        cin>>flag;
        if(flag==0){
            cout<<"THANK YOU FOR USING THIS PROGRAM!!!!"<<endl;
            break;
        }
    }
}