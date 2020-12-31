
#include <string>
#include <algorithm>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    // make all letters lower cased
    for(int i = 0; i < s.length(); i++){
        if(s[i] < 97)
            s[i] += 32;
    }
    sort(s.begin(), s.end());
    
    int cntP = 0, cntY = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'p'){
            cntP++;
            continue;
        }
        if(s[i] == 'y'){
            cntY++;
            continue;
        }
    }

    if(cntP != cntY)
        answer = false;
    return answer;
}
