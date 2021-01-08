#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
    string c_type; // string that relates to the type (ex. headgear, eyewear...)
    vector<string> c_types; // vector that contains c_type
    for(int i = 0; i < clothes.size(); i++){
        c_type = clothes[i][1];
        c_types.push_back(c_type);
    } 
    
    // *===== remove duplicates ====* //
    sort(c_types.begin(), c_types.end()); // sort c_types to easily remove duplicates
    auto tmp_ = unique(c_types.begin(), c_types.end()); // c_type now contains {type, type... x x} where x is undetermined c_type
    c_types.erase(tmp_, c_types.end());  // erase undetermined 'x' in c_type
    
    
    int numTypes = c_types.size(); // total number of unique clothes type
    int *cntType = new int[numTypes]; // cntType = num of clothes for each type
    // initialize it to 1;
    for(int i = 0; i < numTypes; i++)
        cntType[i] = 1; // case where that c_type is not chosen
    
    // get which c_type has how many clothes
    int index;
    for(int i = 0; i < clothes.size(); i++){
        c_type = clothes[i][1];
        vector<string>::iterator it = find(c_types.begin(), c_types.end(), c_type);
        index = it - c_types.begin();
        cntType[index] += 1;
    }
    
    for (int i = 0; i < numTypes; i++)
        answer *= cntType[i];

    return answer - 1;
}
