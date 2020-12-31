
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    // get size of commands
    unsigned long int size = commands.size();
    int start, end, k;
    for(int i = 0; i < size; i++){
        start = commands[i][0];
        end = commands[i][1];
        k = commands[i][2];
        
        vector<int> usedArray(&array[start - 1], &array[end]);
        sort(usedArray.begin(), usedArray.end());
        answer.push_back(usedArray[k - 1]);
    }
    
    return answer;
}
