#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N;
vector<int> picked;
bool visited[10+1];
vector<int> next_picked;
vector<vector<int>> cur_dice;
vector<int> a_sum,b_sum;
vector<int> a_tmp,b_tmp;
void sum_simul(int idx){
    if(idx==N/2){
        int cur_a_sum=0;
        int cur_b_sum=0;
        for(int i=0;i<N/2;++i){
            cur_a_sum+=a_tmp[i];
            cur_b_sum+=b_tmp[i];
        }
        a_sum.push_back(cur_a_sum);
        b_sum.push_back(cur_b_sum);
        return;
    }
    for(int i=0;i<6;++i){
        a_tmp.push_back(cur_dice[picked[idx]][i]);
        b_tmp.push_back(cur_dice[next_picked[idx]][i]);
        sum_simul(idx+1);
        a_tmp.pop_back();
        b_tmp.pop_back();
    }
}
int ret=-1;
int calc_num(){
    a_sum.clear();
    b_sum.clear();
    a_tmp.clear();
    b_tmp.clear();
    sum_simul(0);
    int cnt=0;
    sort(b_sum.begin(),b_sum.end());
    // cout<<a_sum.size()<<" "<<b_sum.size()<<"\n";
    // for(int i=0;i<a_sum.size();++i){
    //     cout<<a_sum[i]<<" ";
    // }cout<<"\n";
    // for(int i=0;i<b_sum.size();++i){
    //     cout<<b_sum[i]<<" ";
    // }cout<<"\n";
    for(int i=0;i<a_sum.size();++i){
        int L=0, R=b_sum.size()-1;
        int mid=(L+R)/2;
        int cur_num=a_sum[i];
        if(cur_num<=b_sum[0]) continue;
        bool flag=0;
        // cur_num보다 작은 최대의 수의 최대 idx
        while(L+1<R){
            mid=(L+R)/2;
            if(b_sum[mid]<cur_num){
                flag=1;
                L=mid;
            }else{
                R=mid;
            }
        }
        cnt+=L;
        // if(flag){
        //     cnt+=(L+1);    
        // }
        
        
    }
    // for(int i=0;i<picked.size();++i){
    //     cout<<picked[i]<<" ";
    // }cout<<"\n";
    // cout<<cnt<<"\n";
    return cnt;
}
vector<int> ans;
void dfs(int idx){
    if(picked.size()==N/2){
        next_picked.clear();
        bool check[10+1];
        for(int i=0;i<10+1;++i){
            check[i]=0;
        }
        for(int i=0;i<N/2;++i){
            check[picked[i]]=1;
        }
        for(int i=0;i<N;++i){
            if(!check[i]){
                next_picked.push_back(i);        
            }
        }
        int cur_calc_num=calc_num();
        if(ret<cur_calc_num){
            ret=cur_calc_num;   
            ans.clear();
            for(int i=0;i<picked.size();++i){
                ans.push_back(picked[i]+1);
            }
            sort(ans.begin(),ans.end());
        }
        
        return;
    }
    if(idx==N){
        return;
    }
    for(int i=idx;i<N;++i){
        if(!visited[i]){
            visited[i]=1;
            picked.push_back(i);
            dfs(i+1);
            picked.pop_back();
            visited[i]=0;
        }
    }
}
vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    cur_dice=dice;
    N=dice.size();
    dfs(0);
    return ans;
}