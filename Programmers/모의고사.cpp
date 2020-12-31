
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int nQuest = answers.size();
    // vector for person A, B, C
    vector<int> A({1, 2, 3, 4, 5});
    vector<int> B({2, 1, 2, 3, 2, 4, 2, 5});
    vector<int> C({3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
    
    vector<int> cnt(3, 0);
    for(int i = 0; i < nQuest; i++){
        if(answers[i] - A[i % 5] == 0)
            cnt[0] += 1;
        if(answers[i] - B[i % 8] == 0)
            cnt[1] += 1;
        if(answers[i] - C[i % 10] == 0)
            cnt[2] += 1;
    }
    int max = 0;
    for(int i = 0; i < 3; i++){
        if (cnt[i] > max)
            max = cnt[i];
    }
    for(int i = 0; i < 3; i++){
        if(cnt[i] == max)
            answer.push_back(i + 1);
    } 
    
    return answer;
}
