#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;   
    int N = board.size();
    
    // basket
    vector<int> basket;
    
    // reconstruct the game board
    vector<vector<int>> gameboard;
    int index = 0;
    while(index < N){
        vector<int> subvec;
        for(int i = N - 1; i > -1; i--){
            if(board[i][index] == 0){
                break;
            } else{
                subvec.push_back(board[i][index]);
            }
        }
        gameboard.push_back(subvec);
        index++;
    }
    
    // follow the moves
    int pos = 0; // index of vector <moves>
    while(pos < moves.size()){
        int col = moves[pos] - 1; // game board starts with 1
        if(!gameboard[col].empty()){
            int doll = gameboard[col].back();
            gameboard[col].pop_back();
            
            if(basket.empty()){
                // if basket is empty just push_back
                basket.push_back(doll);
            } else{
                // check if it's possible to pop dolls
                if(basket.back() == doll){
                    answer += 2;
                    basket.pop_back();
                } else{
                    basket.push_back(doll);
                }
            }
        }
        pos += 1;
    }
    
    return answer;
}
