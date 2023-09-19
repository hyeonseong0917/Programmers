#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 12345
// 22345
// 33345
// 44445
// 55555

//1을 제외한 i번째 행에는 i가 i개 있고 나머지는 1개씩
#define ll long long
vector<int> solution(int n, long long left, long long right) {
    vector<int> ans;
    for(ll i=left;i<=right;++i){
        ll y=i%n +1;
        ll x=i/n +1;
        ans.push_back(max(x,y));
    }
    return ans;
}