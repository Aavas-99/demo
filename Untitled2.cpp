#include<bits/stdc++.h>
using namespace std;
void bfs(int n,vector<int>&vis,vector<vector<int>>&adj,vector<int>&ans)
{
    queue<int>q;
    q.push(n);
    while(q.empty()==0)
    {
        int f=q.front();
        q.pop();
        vis[f]=1;
        ans.push_back(f);
        for(auto x:adj[f])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x]=1;
            }
        }
    }
}
int main()
{
    long long n,k,u,v;
    cin>>n>>k;
    vector<int>vis(n+1,0);
    vector<int>par(n+1,-1);
    vector<int>ans;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<k;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,vis,adj,ans);
    for(auto it:ans)cout<<it<<" ";
}

