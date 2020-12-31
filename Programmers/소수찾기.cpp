
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    
    int answer = 0;
    
    bool *arr = new bool[n+1];
    for(int i = 2; i < n+1; i++){
        arr[i] = true;
    }

    for(int i = 2; i * i <= n; i++){
        if(arr[i]){
            for(int j = i * i; j <= n; j += i)
                arr[j] = false;
        }
    }
    
    for(int i = 2; i < n+1; i++)
        if(arr[i])
            answer++;
    
    return answer;
}
