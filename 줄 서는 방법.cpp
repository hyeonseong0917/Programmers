#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long factorial(long long num){
    if(num==0 || num==1) return 1;
    return num*factorial(num-1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    for(int i=1;i<=n;++i){
        v.push_back(i);
    }
    int cnt=0;
    while(1){
        if(answer.size()==n){
            break;
        }
        long long cur_num=factorial(v.size()-1);
        long long page=k/cur_num;
        k%=cur_num;
        if(k==0){
            long long c=page-1;
            if(c<0){
                c=v.size()-1;
            }
            answer.push_back(v[c]);
            v.erase(v.begin()+c);
        }else{
            answer.push_back(v[page]);
            v.erase(v.begin()+page);
            
        }
        // break;
    }
    
    return answer;
}