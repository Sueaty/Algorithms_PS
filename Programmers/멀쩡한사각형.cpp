#include <cmath>
#include <iostream>

using namespace std;

using namespace std;

long long solution(int w, int h) {
    long long answer = 0;

    // func : y = h/w x
    for(int i = 1; i <= w; i++){
        double pos = ceil((long long)h * i / (double)w);
        int block = h - pos;
        
        answer += block;
    }
    
    answer = answer * 2;
    return answer;
}
