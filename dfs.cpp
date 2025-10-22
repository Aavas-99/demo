#include<bits/stdc++.h>
using namespace std;
void dfs(int n,vector<int>&vis,vector<vector<int>>&adj,vector<int>&ans)
{
    vis[n]=1;
    ans.push_back(n);
    for(auto x:adj[n])
    {
        if(!vis[x])
        {
            dfs(x,vis,adj,ans);
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
    dfs(1,vis,adj,ans);
    for(auto it:ans)cout<<it<<" ";
}


