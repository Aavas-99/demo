#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w;
};

bool bellman(int n,vector<edge>&e,vector<int>&par,int src,vector<int>&dis)
{
    dis[src]=0;
    for(int i=0;i<n-1;i++)
    {
        bool upd=false;
        for(auto it:e)
        {
            if(dis[it.u]!=1e8 && dis[it.v]>dis[it.u]+it.w)
            {
                dis[it.v]=dis[it.u]+it.w;
                par[it.v]=it.u;
            }
        }
        if(!upd) break;
    }
    for(auto it:e)
    {
        if(dis[it.u]!=1e8 && dis[it.v]>dis[it.u]+it.w)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n,m,u,v,w,src,des;
    cin>>n>>m;
    vector<edge>e(n+1);
    vector<int>par(n+1,0);
    vector<int>dis(n+1,1e8);
    for(int i=0;i<m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    cin>>src>>des;
    bool x= bellman(n,e,par,src,dis);
    if(!x)
    {
        cout<<"Negative Cycle"<<endl;
    }
    else if(dis[des]==1e8)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        stack<int>st;
        while(n)
        {
            st.push(n);
            n=par[n];
        }
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
}
