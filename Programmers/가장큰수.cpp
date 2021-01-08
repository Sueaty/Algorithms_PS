#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmpString(string num1, string num2){
    return num1 + num2 > num2 + num1;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    // convert int to string -> sort
    vector<string> numStrings;
    for(int i = 0; i < numbers.size(); i++){
        numStrings.push_back(to_string(numbers[i]));
    }
    sort(numStrings.begin(), numStrings.end(), cmpString);
    for(int i = 0; i < numStrings.size(); i++){
        if(i == 0 && numStrings[0][i] == '0')
            return "0";
        else answer += numStrings[i];
    }
    return answer;
}
