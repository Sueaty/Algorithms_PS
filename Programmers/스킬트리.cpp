#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    // skill order array
    int arr_skill[26];
    for(int i = 0; i < 26; i++){
        // default : initialize to -1
        arr_skill[i] = -1;
    }
    // if letter is in string 'skill' change value to skill's order
    for(int pos = 0; pos < skill.length(); pos++){
        int letter = skill[pos];
        arr_skill[letter - 65] = pos;
    }
    
    // check skill tree
    for(int i = 0; i < skill_trees.size(); i++){
        // check current skill
        string curr = skill_trees[i];
        // compare string 'curr' with array
        int skillOrder = 0;
        for(int j = 0; j < curr.length(); j++){
            int letter = curr[j];
            if(arr_skill[letter - 65] > -1){
                if(arr_skill[letter - 65] > skillOrder){
                    answer--;
                    break;
                } else{
                    skillOrder++;
                }
            }
        }          
    }
    
    return answer;
}
