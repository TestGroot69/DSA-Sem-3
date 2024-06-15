#include <bits/stdc++.h>
using namespace std;

void heapify_maxheap(int arr[], int n, int i){
	int largest = i; 
	int l =2*i+1; 
	int r =2*i+2; 
	if (l < n && arr[l] > arr[largest]){
        largest = l;
    }
	if (r < n && arr[r] > arr[largest]){
        largest = r;
    }
	if (largest != i){
		swap(arr[i], arr[largest]);
		heapify_maxheap(arr, n, largest);
	}
}

void heapify_minheap(int arr[], int n, int i){
	int smallest = i; 
	int l =2*i+1; 
	int r=2*i+2; 
	if (l < n && arr[l] < arr[smallest]){
        smallest = l;
    }
	
	if (r < n && arr[r] < arr[smallest]){
        smallest = r;
    }

	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		heapify_minheap(arr, n, smallest);
	}
}
void heapSort(){
	int n;
	cout<<"enter size of array"<<"\n";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
        cin>>a[i];
    }
	int ch;
	cout<<"---MENU---\n";
	cout<<"1.max-heap\n";
	cout<<"2.min-heap\n";
	cout<<"enter your choice"<<"\n";
	cin>>ch;
	if(ch==1){
        for(int i = n/2 - 1; i >= 0; i--){
            heapify_maxheap(a, n, i);
        }
	    for(int i = n - 1; i > 0; i--) {
		    swap(a[0], a[i]);
		    heapify_maxheap(a, i, 0);
	    }
	}
	else if(ch==2){
		for(int i = n / 2 - 1; i >= 0; i--){
            heapify_minheap(a, n, i);
		    //delete elements in heap printing in ascending order
        }
	    for(int i = n - 1; i > 0; i--){
		    swap(a[0], a[i]);
		    heapify_minheap(a, i, 0);
	    }	
	}
	cout << "Sorted array is \n";
	for (int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
	cout << "\n";
}

int main(){
	heapSort();
}
