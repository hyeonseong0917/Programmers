#include <string>
#include <vector>

using namespace std;
const int MAX=1000+1;
int board[MAX][MAX];
// 1
// 2 15
// 3 16 14
// 4 17 21 13
// 5 18 19 20 12
// 6 7  8  9  10 11

int cnt=0;
vector<int> solution(int n) {
    vector<int> answer;
    for(int i=1;i<=n;++i){
        cnt+=i;
    }
    
    for(int i=0;i<MAX;++i){
        for(int j=0;j<MAX;++j){
            board[i][j]=0;
        }
    }
    int turn=0;
    int cur_num=1;
    int cur_step=n-1;
    int y=0, x=0;
    while(1){
        if(cur_num>cnt){
            break;
        }
        for(int i=y;i<=y+cur_step;++i){
            board[i][x]=cur_num;
            if(i!=y+cur_step) ++cur_num;
        }
        y+=cur_step;
        for(int i=x;i<=x+cur_step;++i){
            board[y][i]=cur_num;
            if(i!=x+cur_step) ++cur_num;
        }
        x+=cur_step;
        for(int i=0;i<=cur_step-1;++i){
            board[y-i][x-i]=cur_num;                
            if(i!=cur_step-1) ++cur_num;
        }
        if(cur_num==cnt){
            break;
        }
        y-=(cur_step-1);
        x-=(cur_step-1);
        y+=1;
        ++cur_num;
        board[y][x]=cur_num;
        cur_step-=3;
        // break;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            answer.push_back(board[i][j]);
        }
    }
    return answer;
}