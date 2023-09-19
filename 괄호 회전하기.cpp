#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

bool isRight(string s){
    stack<char> st;
    for(int i=0;i<s.size();++i){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }else{
            if(st.empty()){
                return 0;
            }
            char c=st.top();
            if((c=='(' && s[i]==')') 
               || (c=='{' && s[i]=='}')
               || (c=='[' && s[i]==']')){
                st.pop();
            }else{
                return 0;
            }
        }
    }
    return st.empty();
    
}

int solution(string s) {
    int answer = 0;
    int N=s.size();
    if(isRight(s)) ++answer;
    for(int i=1;i<N;++i){
        char first_char=s[0];
        s=s.substr(1,N-1);
        s+=first_char;
        // cout<<s<<endl;
        if(isRight(s)) ++answer;
    }
    return answer;
}