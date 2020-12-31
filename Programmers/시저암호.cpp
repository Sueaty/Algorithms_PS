
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0; i < s.length(); i++){
        if(isalpha(s[i])){
            if(97 <= s[i] && s[i] <= 122){
                // lower letter
                if(s[i] + n > 122){
                    answer += s[i] + n - 26;
                } else{
                    answer += s[i] + n;
                }
            } else {
                // upper letter
                if(s[i] + n > 90){
                    answer += s[i] + n - 26;
                } else{
                    answer += s[i] + n;
                }
            }
        } else{
            answer += " ";
        }
    }  
  
    return answer;
}
