#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;
    int g[v+1][v+1]={{0}};
    int visited[v+1]={0};
    int distance[v+1];
    for(int i=0;i<=v;i++){
        distance[i]=999;
    }
    while(e!=0){
        int r,c,w;
        cin>>r>>c>>w;
        g[r][c]=w;
        g[c][r]=w;
        e--;
    }
    int source =1;
    distance[source]=0;
    int visited_counter=0;
    while(visited_counter!=v){
        visited[source]=1;
        for(int i=1;i<=v;i++){
            if(i!=source && g[source][i]!=0){
                distance[i]=min(distance[i],distance[source]+g[source][i]);
            }
        }
        int mn=INT_MAX;
        for(int i=1;i<=v;i++){
            if(mn>distance[i] && visited[i]==0){
                mn=distance[i];
                source=i;
            }
        }
        visited_counter++;
    }
    for(int i=1;i<=v;i++){
         cout<<distance[i]<<" ";
    }
    return 0;
}
//8
//14
// 1 2 2
// 1 4 3
// 1 6 1
// 2 4 2
// 2 5 4
// 2 3 2
// 3 5 5
// 3 8 1
// 4 6 3
// 4 5 4
// 5 6 3
// 5 7 7
// 5 8 6
// 6 7 5



// 6
// 10
// 1 2 6
// 1 3 1
// 1 4 5
// 2 3 5
// 2 5 3
// 3 5 6
// 3 4 5
// 3 6 4
// 4 6 2
// 5 6 6
