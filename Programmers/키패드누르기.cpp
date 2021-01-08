#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

void add_edge(vector<int> ptr[], int v, int u){
    ptr[v].push_back(u);
    ptr[u].push_back(v);
}

bool bfs(vector<int> ptr[], int s, int d, int size, int predecessor[], int distance[]){
    list<int> queue;
    bool visited[size];
    for(int i = 0; i < size; i++){
        visited[i] = false;
        distance[i] = 1000; // max number
        predecessor[i] = -1;
    }
    
    visited[s] = true;
    distance[s] = 0;
    queue.push_back(s);
    
    //bfs
    while(!queue.empty()){
        int u = queue.front();
        queue.pop_front();
        for(int i = 0; i < ptr[u].size(); i++){
            if(visited[ptr[u][i]] == false){
                visited[ptr[u][i]] = true;
                distance[ptr[u][i]] = distance[u] + 1;
                predecessor[ptr[u][i]] = u;
                queue.push_back(ptr[u][i]);
                
                if(ptr[u][i] == d)
                    return true;
            }
        }
    }
    return false;
}

int getDistance(vector<int> ptr[], int s, int d, int size){
    int predecessor[size], distance[size];
    
    bfs(ptr, s, d, size, predecessor, distance);
    
    vector<int> path; // saves shortest path
    int crawl = d;
    path.push_back(crawl);
    while(predecessor[crawl] != -1){
        path.push_back(predecessor[crawl]);
        crawl = predecessor[crawl];
    }

    int pathLen = path.size();
    return pathLen;;// must return the length
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int size = numbers.size();
    
    // create cell phone graph
    vector<int> ptr[13];
    add_edge(ptr, 1, 2); add_edge(ptr, 1, 4);
    add_edge(ptr, 2, 3); add_edge(ptr, 2, 5);
    add_edge(ptr, 3, 6);
    add_edge(ptr, 4, 5); add_edge(ptr, 4, 7);
    add_edge(ptr, 5, 6); add_edge(ptr, 5, 8);
    add_edge(ptr, 6, 9);
    add_edge(ptr, 7, 8); add_edge(ptr, 7, 10);
    add_edge(ptr, 8, 9); add_edge(ptr, 8, 11);
    add_edge(ptr, 9, 12);
    add_edge(ptr, 10, 11);
    add_edge(ptr, 11, 12);
        
    int pressNum;
    int posL = 10, posR = 12;
    for(int order = 0; order < size; order++){
        pressNum = numbers[order];
        if(pressNum == 0) 
            pressNum = 11;
        
        if(pressNum == 1 || pressNum == 4 || pressNum == 7){
            posL = pressNum;
            answer += "L";
        }
        else if(pressNum == 3 || pressNum == 6 || pressNum == 9){
            posR = pressNum;
            answer += "R";
        }
        else{
            cout << "press : " << pressNum << endl;
            if(posL == pressNum){
                answer += "L";
            }
            else if(posR == pressNum){
                answer += "R";
            }
            else{ 
                // in need of using graph
                int pathForLeft, pathForRight;
                // case 1 : 
                pathForLeft = getDistance(ptr, pressNum, posL, 13);
                cout << pathForLeft << endl;
                // case 2:
                pathForRight = getDistance(ptr, pressNum, posR, 13);
                cout << pathForRight << endl;
                cout << endl;
                
                if(pathForLeft < pathForRight){
                    posL = pressNum;
                    answer += "L";
                }
                else if(pathForLeft > pathForRight){
                    posR = pressNum;
                    answer += "R";
                }
                else{ // if pathForLeft == pathForRight
                    if(hand.compare("left") == 0){
                        posL = pressNum;
                        answer += "L";
                    }
                    else{
                        posR = pressNum;
                        answer += "R";
                    }
                } 
            }
        }
    }
    return answer;
}
