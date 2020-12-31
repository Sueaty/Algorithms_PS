
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int strlen = s.length();
    int mid = strlen / 2;
    if(strlen % 2 == 0){
        // if length is even number
        answer += s[mid - 1];
        answer += s[mid];
        
    } else{
        // if length is odd number
        answer = s[mid];
    }
    
    return answer;
}
