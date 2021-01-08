#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    
    vector<vector<int>> redSize;
    vector<int> redCandidate;
    for(int i = 1; i < red + 1; i++){
        if(red % i == 0){
            if(i > red/i)
                break;
            redCandidate.push_back(red / i);
            redCandidate.push_back(i);
            redSize.push_back(redCandidate);
        }
        redCandidate.clear();
    }
    
    int cntCandidates = redSize.size();
    for(int i = 0; i < cntCandidates; i++){
        int x = redSize[i][0] + 2;
        int y = redSize[i][1] + 2;
        if(x * y == brown + red){
            answer.push_back(x);
            answer.push_back(y);
            break;
        }
    }
    return answer;
}
