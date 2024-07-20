#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> g;
vector<bool> visited;
int n=0;
int node_cnt;
int v_cnt;
vector<int> answer=vector<int>(4,0);
vector<int> check;
bool flag=0;
void dfs(int cur_node, int root_node){
    if(flag) return;
    if(check[cur_node]>=2 && g[cur_node].size()==2){
        flag=1;
        ++answer[3];
        return;
    }
    if(cur_node==root_node && visited[cur_node]){
        flag=1;
        ++answer[1];
        return;
    }
    if(g[cur_node].empty()){
        flag=1;
        ++answer[2];
        return;
    }
    for(int i=0;i<g[cur_node].size();++i){
        if(!visited[g[cur_node][i]]){
            visited[g[cur_node][i]]=1;
            dfs(g[cur_node][i],root_node);
        }
    }
    
}
vector<int> solution(vector<vector<int>> edges) {
    
    for(int i=0;i<edges.size();++i){
        n=max(n,max(edges[i][0],edges[i][1]));
    }
    
    visited=vector<bool>(n+1,0);
    for(int i=0;i<=n;++i){
        vector<int> tmp=vector<int>(0,0);
        g.push_back(tmp);
    }
    check=vector<int>(n+1,0);
    vector<int> out_check=vector<int>(n+1,0);
    for(int i=0;i<edges.size();++i){
        g[edges[i][0]].push_back(edges[i][1]);
        ++check[edges[i][1]];
        ++out_check[edges[i][0]];
    }
    int fst_node=-1;
    for(int i=1;i<=n;++i){
        if(!check[i] && out_check[i]>=2){
            fst_node=i;
            break;
        }
    }
    answer[0]=fst_node;
    for(int i=0;i<g[fst_node].size();++i){
        int cur_node=g[fst_node][i];
        flag=0;
        dfs(cur_node,cur_node);
        
    }
    return answer;
}