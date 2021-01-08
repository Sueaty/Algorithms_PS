// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    // int arry that shows how long it takes to finish the work
    vector<int> leftDays;
    int numOfProg = progresses.size();
    
    for(int i = 0; i < numOfProg; i++){
        int leftProg = 100 - progresses[i];
        int leftDay = leftProg / speeds[i];
        if(leftProg % speeds[i] > 0){
            leftDay += 1;
        }
        leftDays.push_back(leftDay);
    }

    int pos = 0;
    while(pos < numOfProg){
        int distriCnt = 0;
        int jobDuration = leftDays[pos];
        do{
            pos += 1;
            distriCnt += 1;
        } while(leftDays[pos] <= jobDuration && pos < numOfProg);
        
        answer.push_back(distriCnt);
    }   
    return answer;
}
