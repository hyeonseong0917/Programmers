#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    vector<int> d=deliveries;
    vector<int> p=pickups;
    int last_idx=n-1;
    while(1){
        bool flag=0;
        for(int i=0;i<n;++i){
            if(d[i]!=0 || p[i]!=0){
                flag=1;
                break;
            }
        }
        if(!flag){
            break;
        }
        int d_cnt=0;
        int idx=-1;
        int new_last_idx=-1;
        for(int i=last_idx;i>=0;--i){
            if(d_cnt==cap) break;
            if(d[i]!=0){
                new_last_idx=i;
                if(idx==-1){
                    idx=i;
                }
                if(d_cnt+d[i]>cap){
                    d[i]=max(0,d[i]-(cap-d_cnt));
                    break;
                }else{
                    d_cnt+=d[i];
                    d[i]=0;
                }
            }
        }
        int p_cnt=0;
        for(int i=last_idx;i>=0;--i){
            if(p_cnt==cap) break;
            if(p[i]!=0){
                new_last_idx=max(new_last_idx,i);
                idx=max(idx,i);
                if(p_cnt+p[i]>cap){
                    
                    p[i]=max(0,p[i]-(cap-p_cnt));
                    // p[i]-=cap-p_cnt;
                    break;
                }else{
                    p_cnt+=p[i];
                    p[i]=0;
                }
            }
        }
        answer+=(idx+1)*2;
        last_idx=new_last_idx;
    }
    return answer;
}
