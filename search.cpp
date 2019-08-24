
#include <iostream>
#include <algorithm>

using namespace std;

void sequential_search(int*, int); // (num_list, key);
void binary_search(int*, int); // (num_list, key);
void interpolation_search(int*, int); // (num_list, key);
int main(void){
    // num_list of no duplicates
    int num_list[100] = {458,254,923,279,259,166,16,135,600,141,873,937,821,469,856,137,332,566,26,745,350,775,194,738,922,446,436,146,378,265,155,880,956,872,190,751,604,596,287,156,424,54,972,171,529,440,864,258,610,7,901,562,284,282,586,320,516,548,964,46,264,414,830,868,820,970,904,270,883,835,397,687,694,819,762,489,889,392,243,292,192,690,6,326,423,427,410,98,161,979,665,616,899,944,325,421,301,564,881,950};
    
    sequential_search(num_list, 192);
    binary_search(num_list, 192);
    interpolation_search(num_list, 192);
}

void sequential_search(int* num_list, int key){
    bool found = false;
    int pos = 0;
    while(!found && pos < 101){
        if(num_list[pos] == key)
            found = true;
        pos++;
    }
    cout << "KEY : " << key << " ";
    if(pos == 101)
        cout << "does not exist" << endl;
    else
        cout << "exists in POS : " << pos - 1 << endl;
}

void binary_search(int* num_list, int key){
    int left = 0, right = 100, median, pos = -1;
    int* sorted_num_list = num_list;
    sort(sorted_num_list, sorted_num_list + 100);
    while(left <= right){
        median = (left + right) / 2;
        if(key < sorted_num_list[median]){
            right = median - 1;
        }
        else if(key > sorted_num_list[median]){
            left = median + 1;
        }
        else{
            pos = median;
            break;
        }
    }
    cout << "KEY : " << key << " ";
    if(pos == -1)
        cout << "does not exist" << endl;
    else
        cout << "exists in POS : " << pos << endl;
}

void interpolation_search(int* num_list, int key){
    int left = 0, right = 100, pos = 0;
    bool found = false;
    int* sorted_num_list = num_list;
    sort(sorted_num_list, sorted_num_list + 100);
    
    while(left <= right){
        pos = left + (right - left) * (key - sorted_num_list[left]) / (sorted_num_list[right] - sorted_num_list[left]);
        if(key < sorted_num_list[pos]){
            right = pos - 1;
        }
        else if(key > sorted_num_list[pos]){
            left = pos + 1;
        }
        else{
            found = true;
            break;
        }
    }
    cout << "KEY : " << key << " ";
    if(!found)
        cout << "does not exist" << endl;
    else
        cout << "exists in POS : " << pos << endl;
}
