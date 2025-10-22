#include<bits/stdc++.h>
using namespace std;

bool bfs(int n,vector<vector<int>>&adj,vector<int>&vis,vector<int>&par)
{
    queue<int>q;
    q.push(n);
    par[n]=-1;
    while(!q.empty())
    {
        int f=q.front();
        vis[f]=1;
        q.pop();
        for(auto x:adj[f])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x]=1;
                par[x]=f;
            }
            else
            {
                if(vis[x])
                {
                    if(par[x]!=f)
                    {
                        return false;
                    }
                }
            }
        }

    }
    return true;
}

int main()
{
    int n,k,u,v;
    cin>>n>>k;
    vector<int>vis(n+1,0);
    vector<int>par(n+1,-1);
    vector<vector<int>>adj(n+1);
    for(int i=0;i<k;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans=bfs(1,adj,vis,par);
    if(ans)cout<<"NO CYCLE";
    else cout<<"CYCLE FOUND";
}
