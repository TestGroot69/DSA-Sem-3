#include<bits/stdc++.h>
using namespace std;

int find_parent(int x,vector<int> &parent){
	if(parent[x]==-1){
		return x;
	}
	return parent[x]=find_parent(parent[x],parent);
}
void union_(int x,int y,vector<int> &parent){
	int px=find_parent(x,parent);
	int py=find_parent(y,parent);
	
	if(px!=py){
		parent[px]=py;
	}
}
int main(){
    int v,n;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>n;
    vector<pair<int,pair<int,int>>> s;
    int g[v+1][v+1]={{0}};
    int visited[v+1]={0};
    int distance[v+1];
    int from[v+1];
    for(int i=0;i<=v;i++){
        distance[i]=1e9;
    }
    for(int i=0;i<=v;i++){
        from[i]=1;
    }
    int k=0;
    while(k<n){
        int r,c,w;
        cin>>r>>c>>w;
        g[r][c]=w;
        g[c][r]=w;
        s.push_back(make_pair(w,make_pair(r,c)));
        k++;
    }

    // Prim's Algorithm
    int source =1;
    distance[source]=0;
    int visited_counter=0;
    while(visited_counter!=v){
        visited[source]=1;
        for(int i=1;i<=v;i++){
            if(visited[i]!=1 && g[source][i]!=0 && distance[i]>g[source][i]){
                distance[i]=g[source][i];
                from[i]=source;
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
    int mstP[v+1][v+1]={{0}};
    for(int i=1;i<=v;i++){
        mstP[i][from[i]] =g[i][from[i]];
        mstP[from[i]][i] =g[from[i]][i];
    }
    cout<<"\nParent Array: \n";
    for(int j=1;j<=v;j++){
        cout<<from[j]<<" ";
    }
    cout<<endl;
    cout<<"MST using Prim's Algorithm\n";
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(mstP[i][j]!=0)
            cout<<mstP[i][j]<<" ";
            else
            cout<<"- ";
        }
        cout<<endl;
    }
    cout<<endl;

    // Kruskal's Algorithm
    int mstK[v+1][v+1]={{0}};
    vector<int> parent(v+1,-1);
    sort(s.begin(),s.end());
    int h=0;
    while(h<n){
        int w=s[h].first;
        int u=s[h].second.first;
        int v=s[h].second.second;
        if(find_parent(u,parent)!=find_parent(v,parent)){
            mstK[u][v]=w;
			mstK[v][u]=w;
			union_(u,v,parent);
		}
        h++;
    }
    cout<<"MST using Kruskal's Algorithm\n";
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(mstK[i][j]!=0)
            cout<<mstK[i][j]<<" ";
            else
            cout<<"- ";
        }
        cout<<endl;
    }
    return 0;
}
