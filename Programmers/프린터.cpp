#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
struct Printer{
    int loc;
    int priority;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<int> pType(10); // priority type : 1 ~ 9, initialized to 0
    queue<Printer> jobs; // manage jobs in queue (FIFO)
    vector<Printer> order;
    
    // convert jobs to structure and push to queue
    for(int i = 0; i < priorities.size(); i++){
        Printer p;
        p.loc = i;
        p.priority = priorities[i];
        pType[priorities[i]]++;
        jobs.push(p);
    }
    
    for(int i = 9; i > 0; i--){
        int curr = i; // current priority to search for
        int numOfJob = pType[i]; // number of jobs with 'curr' priority
        if(numOfJob > 0){
            while(numOfJob > 0){
                if(jobs.front().priority == i){
                    // if it's the matching priority
                    order.push_back(jobs.front()); // add to vector 'order'
                    jobs.pop(); // erase it from queue 'jobs'
                    numOfJob--; // decrement numOfJobs (terminating condition of while statement)
                } else {
                    // if it's not the matching priority
                    jobs.push(jobs.front()); // push it to the back of the queue 'jobs'
                    jobs.pop(); // erase it from the front of the queue 'jobs'
                }
            }
        }
    }
    
    for(int i = 0; i < order.size(); i++){
        if(order[i].loc == location){
            answer = i + 1;
        }
    }

    return answer;
}
