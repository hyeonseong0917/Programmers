#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

int solution(int coin, vector<int> cards) {
    map<int,int> m;
    int n=cards.size();
    int ans=0;
    vector<int> d;
    vector<int> d_check(1000+1,0);
    for(int i=0;i<n/3;++i){
        // m[cards[i]]=1;
        d.push_back(cards[i]);
        d_check[i]=1;
    }
    int idx=n/3;
    vector<int> tmp;
    vector<int> tmp_check(1000+1,0);
    while(idx<n){
        ++ans;
        int fst_num=cards[idx];
        int sed_num=cards[idx+1];
        // 현재 라운드에서 건질 숫자가 있는가?
        int ds=d.size();
        bool fst_flag=0;
        bool fst_eq_flag=0;
        bool sed_eq_flag=0;
        // cout<<ans<<" "<<coin<<endl;
        for(int i=0;i<ds;++i){
            if(!d_check[i]) continue;
            if(d[i]+fst_num==n+1 && coin){
                --coin;
                fst_eq_flag=1;
                if(!sed_eq_flag){
                    d_check[i]=0;
                }else{
                    d.push_back(fst_num);
                    d_check[ds]=1;
                }
            }
            if(d[i]+sed_num==n+1 && coin){
                --coin;
                sed_eq_flag=1;
                if(!fst_eq_flag){
                    d_check[i]=0;
                }else{
                    d.push_back(sed_num);
                    d_check[ds]=1;
                }
            }
            
        }
        if(!fst_eq_flag){
            tmp.push_back(fst_num);
            int ts=tmp.size();
            tmp_check[ts-1]=1;
        }
        if(!sed_eq_flag){
            tmp.push_back(sed_num);
            int ts=tmp.size();
            tmp_check[ts-1]=1;
        }
        if(fst_eq_flag || sed_eq_flag){
            fst_flag=1;
        }
        if(fst_flag){
            idx+=2;
            continue;
        }
        // 첫 번째 라운드에서 건질만한 것들이 없었다
        
        // 원래 d에서 지불해야함
        bool sed_flag=0;
        ds=d.size();
        for(int i=0;i<ds;++i){
            if(sed_flag) break;
            if(!d_check[i]) continue;
            for(int j=i+1;j<ds;++j){
                if(!d_check[j]) continue;
                if(d[i]+d[j]==n+1){
                    sed_flag=1;
                    d_check[i]=0;
                    d_check[j]=0;
                    break;
                }
            }
        }
        if(sed_flag){
            idx+=2;
            continue;
        }
        // tmp에서 2개 꺼내기
        bool trd_flag=0;
        int ts=tmp.size();
        // cout<<ts<<endl;
        for(int i=0;i<ts;++i){
            if(trd_flag) break;
            if(!tmp_check[i]) continue;
            for(int j=i+1;j<ts;++j){
                if(!tmp_check[j]) continue;
                if(tmp[i]+tmp[j]==n+1 && coin>=2){
                    coin-=2;
                    tmp_check[i]=0;
                    tmp_check[i]=0;
                    trd_flag=1;
                    break;
                }
            }
        }
        if(trd_flag){
            idx+=2;
            continue;
        }
        break;
        
    }
    if(idx==n){
        ++ans;
    }
    return ans;
}