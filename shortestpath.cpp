#include<bits/stdc++.h>
using namespace std;
void bfs(int n,vector<int>&vis,vector<vector<int>>&adj,vector<int>&ans,vector<int>&dis,vector<int>&par)
{
    queue<int>q;
    q.push(n);
    par[n]=-1;
    dis[n]=0;
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
                par[x]=f;
                if(dis[x]==-1 || dis[x]>dis[f]+1)
                {
                    dis[x]=dis[f]+1;
                }
                q.push(x);
                vis[x]=1;
            }
        }
    }
}

void path(int des,vector<int>&dis,vector<int>&par)
{
    vector<int>ans;
    if(dis[des]==-1)
    {
        cout<<"NO\n";
        return;
    }
    while(des!=-1)
    {
        ans.push_back(des);
        des=par[des];
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)cout<<x<<" ";
}
int main()
{
    long long n,k,u,v;
    cin>>n>>k;
    vector<int>vis(n+1,0);
    vector<int>par(n+1,-1);
    vector<int>dis(n+1,-1);
    vector<int>ans;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<k;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,vis,adj,ans,dis,par);
    path(n,dis,par);
    //for(auto it:dis)cout<<it<<" ";
}


