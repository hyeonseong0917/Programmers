#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    for(int i=0;i<commands.size();++i){
        vector<int> cur_command=commands[i];
        int startIdx=cur_command[0]-1;
        int finIdx=cur_command[1]-1;
        int myIdx=cur_command[2]-1;
        tmp.clear();
        for(int j=startIdx;j<=finIdx;++j){
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[myIdx]);
    }
    return answer;
}