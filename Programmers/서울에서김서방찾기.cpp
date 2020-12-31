
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    vector<string>::iterator it = find(seoul.begin(), seoul.end(), "Kim");
    int pos = distance(seoul.begin(), it);
    answer = "김서방은 " + to_string(pos) + "에 있다";
    
    return answer;
}
