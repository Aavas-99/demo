#include<bits/stdc++.h>
using namespace std;

#define INF 1e18

void dijsktra(vector<vector<pair<int,int>>>&adj,vector<int>&dis,int s,vector<int>&par)
{
    dis[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(d!=dis[node])continue;

        for(auto it:adj[node])
        {
            int v=it.first;
            int w=it.second;

            if(dis[v]>d+w)
            {
                dis[v]=d+w;
                par[v]=node;
                pq.push({dis[v],v});
            }
        }

    }
}

void solve()
{
    int n,m,u,v,w;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>dis(n+1,INF);
    vector<int>par(n+1,-1);
    int s=1;
    dijsktra(adj,dis,s,par);
    if(dis[n]==INF)
    {
        cout<<-1;
        return;
    }
    int cur=n;
    vector<int>path;
    while(cur!=-1)
    {
        path.push_back(u);
        cur=par[cur];
    }
    reverse(path.begin(),path.end());
    for(auto x:path)
    {
        cout<<x<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
