#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    // create a stack
    vector<char> stk;
    stk.push_back(s[0]);
    for(int i = 1; i < s.length(); i++){
        if(s[i] == stk.back()){
            stk.pop_back();
        } else{
            stk.push_back(s[i]);
        }
    }
    if(stk.empty())
        answer = 1;
    return answer;
}
