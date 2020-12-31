
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    if(isdigit(s[0])){
        answer = stoi(s);
    } else if(s[0] == '+'){
        s = s.substr(1);
        answer = stoi(s);
    } else{
        s = s.substr(1);
        answer = -1 * stoi(s);
    }
    return answer;
}
