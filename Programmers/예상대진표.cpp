#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;    
    // say A is always smaller than B
    if(a > b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    // get the round A and B will meet
    while(true){
        // terminating condition : Even number A & A - 1
        if(b % 2 == 0 && b - 1 == a){
            break;
        }
        answer++; // proceeds to the next round
        
        if(a % 2 != 0){
            a = a / 2 + 1;
        } else{
            a = a / 2;
        }
        
        if(b % 2 != 0){
            b = b / 2 + 1;
        } else{
            b = b / 2;
        }
        
    }
    return answer;
}
