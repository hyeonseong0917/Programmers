#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> first_forgive, second_forgive, third_forgive;
void Init(){
    int cur_num=0;
    for(int i=0;i<10000;++i){
        ++cur_num;
        if(cur_num>5){
            cur_num=1;
        }
        first_forgive.push_back(cur_num);
    }
    cur_num=0;
    for(int i=0;i<10000;++i){
        if(i%2==0){
            second_forgive.push_back(2);
        }else{
            ++cur_num;
            if(cur_num==2){
                ++cur_num;
            }
            if(cur_num>5){
                cur_num=1;
            }
            second_forgive.push_back(cur_num);
        }
    }
    cur_num=3;
    for(int i=0;i<10000;++i){
        if(i%2==0 && i!=0){
            if(cur_num==3){
                cur_num=1;
            }else if(cur_num==1){
                cur_num=2;
            }else if(cur_num==2){
                cur_num=4;
            }else if(cur_num==4){
                cur_num=5;
            }else if(cur_num==5){
                cur_num=3;
            }
        }
        third_forgive.push_back(cur_num);
    }
    
}
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

vector<int> solution(vector<int> answers) {
    vector<int> ret;
    Init();
    vector<pair<int,int>> people; //{점수,idx}
    for(int i=0;i<3;++i){
        people.push_back({0,i});
    }
    
    for(int i=0;i<answers.size();++i){
        int cur_ans=answers[i];
        if(cur_ans==first_forgive[i]){
            ++people[0].first;
        }
        if(cur_ans==second_forgive[i]){
            ++people[1].first;
        }
        if(cur_ans==third_forgive[i]){
            ++people[2].first;
        }
    }
    sort(people.begin(),people.end(),comp);
    int maxNum=people[0].first;
    ret.push_back(people[0].second+1);
    for(int i=1;i<3;++i){
        if(maxNum==people[i].first){
            ret.push_back(people[i].second+1);
        }
    }
    return ret;
}