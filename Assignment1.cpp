#include<bits/stdc++.h>
using namespace std;

class SEIT{
    string name;
    int roll;
    float sgpa;
    public:
    int index;
    void getdata(int i){
        string a;
        int b;
        float c;
        cout<<"Enter Name ("<<i+1<<") : ";
        cin>>a;
        cout<<"Enter Roll No. : ";
        cin>>b;
        cout<<"Enter SGPA : ";
        cin>>c;
        name=a;
        roll=b;
        sgpa=c;
        index=i;
    }
    void putdata(){
        cout<<"Name : "<<name<<endl;
        cout<<"Roll No. : "<<roll<<endl;
        cout<<"SGPA : "<<sgpa<<endl;
    }
    void linearsearch(SEIT s[],int n,float key){
        bool flag=1;
        for(int i=0;i<n;i++){
            if(s[i].sgpa==key){
                cout<<"Object is present at "<<s[i].index<<" index."<<endl;
                s[i].putdata();
                flag=0;
            }

        }
        if (flag){
            cout<<"No record found"<<endl;
        }
    }
    void bsort(SEIT s[],int n){
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {

                if(s[j].name>s[j+1].name)
                {

                    swap(s[j],s[j+1]);
                }
            }
        }

    }
     void brsort(SEIT s[],int n){
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {

                if(s[j].roll>s[j+1].roll)
                {

                    swap(s[j],s[j+1]);
                }
            }
        }

    }
    void binarysearch(SEIT s[],int n,string nm){

        int low=0;
        int high=n-1;
        int mid=(low+high)/2;
        bool flag=1;
        while(low<=high){
            if(s[mid].name==nm){
                s[mid].putdata();
                flag=0;
                break;
            }
            else if(s[mid].name<nm){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            mid=(low+high)/2;
        }
        if(flag){
            cout<<"No record found."<<endl;
        }
    }
    void isort(SEIT s[],int n){
        for(int i=0;i<n-1;i++){
    	    int j=i;
    	    while(j>=0 and s[j].name>s[j+1].name ){
    		    swap(s[j],s[j+1]);
    		    j--;
    	    }
        }
    }
    int partition(SEIT s[], int start, int end){
        int i = start+1, j = end;
        float pivot=s[start].sgpa;
        while (i < j) {
        
            while (s[i].sgpa < pivot && i<=j) {
                i++;
            }
    
            while (s[j].sgpa > pivot && i<=j) {
                j--;
            }
            if(i<j){
                swap(s[i],s[j]);
            }
        }
        swap(s[start],s[j]);
        return j;
    }
 
    void quickSort(SEIT s[], int start, int end){
        if (start < end){
            int p = partition(s, start, end);
    
            quickSort(s, start, p - 1);
    
            quickSort(s, p + 1, end);

        }
        
    }
};
int menu()
{
    int a;
    cout<<" 1. Linear search"<<endl;
    cout<<" 2. Binary search"<<endl;
    cout<<" 3. Bubble Sort on Roll No. and display details of all students"<<endl;
    cout<<" 4. Insertion Sort on Name and Print Details"<<endl;
    cout<<" 5. Quick Sort on SGPA and Print Details"<<endl;
    cout<<" 6. Exit"<<endl;
    cout<<"enter your choice = ";
    cin>>a;
    cout<<endl;
    return a;
}
int main(){
    menu();
    cout<<"Enter No. of students : ";
    int n;
    cin>>n;
    SEIT s[n];
    for(int i=0;i<n;i++){
        s[i].putdata();    
    }
    for(int i=0;i<n;i++){
        s[i].getdata(i);
    }
    int choice;
    choice=menu();
    while(true){
        SEIT dummy;

        if(choice==6){
            break;
        }
        else if(choice==1)
        {
            float key;
            cout<<"Enter SGPA of the student : ";
            cin>>key;
            dummy.linearsearch(s,n,key);
        }
        else if(choice==2)
        {
            dummy.bsort(s,n);
            string nm;
            cout<<"Enter the name of the student : ";
            cin>>nm;
            dummy.binarysearch(s,n,nm);
        }
        else if(choice==3){
            dummy.brsort(s,n);
            for(int i=0;i<n;i++)
            {
                s[i].putdata();
            }
        }
        else if(choice==4){
            dummy.isort(s,n);
            for(int i=0;i<n;i++){
                s[i].putdata();
            }
        }
        else if(choice==5){
            dummy.quickSort(s,0,n-1);
            int top;
            cout<<"Enter how many top records to be displayed : ";
            cin>>top;
            for(int i=n-1;i>=n-top;i--){
                s[i].putdata();
            }
        }
        else
        {
            cout<<"invalid input pls enter another choice"<<endl;
        }


        choice=menu();

    }
    return 0;
}
