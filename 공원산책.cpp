#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
char dir[4]={'N','E','S','W'};
int N,M;
vector<string> board;
bool isRange(int y, int x){
    return (y>=0 && x>=0 && y<N && x<M);
}
pair<int,int> pos;
void Move(char c, int dist){
    int y=pos.first;
    int x=pos.second;
    int ny=y;
    int nx=x;
    bool flag=0;
    for(int i=0;i<4;++i){
        if(dir[i]==c){
            while(1){
                ny+=dy[i];
                nx+=dx[i];
                if(!isRange(ny,nx) || board[ny][nx]=='X'){
                    flag=1;
                    break;
                }
                --dist;
                if(dist==0){
                    break;
                }
            }
        }
    }
    if(flag==0){
        pos=make_pair(ny,nx);
    }
    
}
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    board=park;
    N=park.size();
    M=park[0].size();
    
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(park[i][j]=='S'){
                pos=make_pair(i,j);
            }
        }
    }
    for(int i=0;i<routes.size();++i){
        char c=routes[i][0];
        int dist=routes[i][2]-'0';
        Move(c,dist);
    }
    answer.push_back(pos.first);
    answer.push_back(pos.second);
    
    return answer;
}