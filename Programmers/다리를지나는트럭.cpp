#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; //time
    
    queue<int> bridge;
    answer++; // answer = 1
    for(int i = 0; i < bridge_length - 1; i++)
        bridge.push(0);
    bridge.push(truck_weights[0]);
    
    int currentIndex = 1;
    int currentWeight = truck_weights[0];
    int poppedTrucks = 0;
    
    while(true){
        if(poppedTrucks == truck_weights.size())
            break;
        
        answer++;
        
        if(bridge.front() != 0){
            poppedTrucks++;
            currentWeight -= bridge.front();
        }
        bridge.pop();
        
        // if there's left to push, push
        if(currentIndex < truck_weights.size()){ // 틀리면 여기 부터 고치기
            if(currentWeight + truck_weights[currentIndex] <= weight){
                // if it's okay to add
                bridge.push(truck_weights[currentIndex]);
                currentWeight += truck_weights[currentIndex];
                currentIndex++;
            }
            else{
                bridge.push(0);
            }
        }
    }
    return answer;
}
