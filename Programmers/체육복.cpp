
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int *students = new int[n + 1];
    for(int i = 0; i < n + 1; i++)
        students[i] = 1;
    
    // add those who has extra
    for(int i = 0; i < reserve.size(); i++){
        int studentNum = reserve[i];
        students[studentNum]++;
    }
    
    // subtract those who lost their's
    for(int i = 0; i < lost.size(); i++){
        int studentNum = lost[i];
        students[studentNum]--;
    }
    
    // give one to others
    for(int i = 1; i < n + 1; i++){
        if(students[i] >= 1){
            answer++;
        } else{
            // check previous student
            if(students[i - 1] == 2){
                students[i - 1]--;
                students[i]++;
                answer++;
            } else if(students[i + 1] == 2){
                students[i + 1]--;
                students[i]++;
                answer++;
            }
        }
    }
    
    return answer;
}
