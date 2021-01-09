#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

class Hash{ 
    int BUCKET; // # of buckets
    list<string> *table; // pointer to an array containing buckets
    
public: 
    Hash(int V); // Constructor
    void addWord(string key); // inserts a word into hash table
    bool checkWord(string key); // checks if key exists in the table
}; 
  
Hash::Hash(int bucket) { 
    this -> BUCKET = bucket; 
    table = new list<string>[BUCKET]; 
} 
  
void Hash::addWord(string key) { 
    int index = key[0] - 97; 
    table[index].push_back(key);  
} 
  
bool Hash::checkWord(string key) {
    bool found = false;
    int index = key[0] - 97; // hash index of key
    
    // find if key exists in (index)th of list
    list<string>::iterator it;
    for(it = table[index].begin(); it != table[index].end(); it++){
        if(*it == key){
            // found duplicated word
            found = true;
            break;
        }
    }
    return found;
}

vector<int> solution(int players, vector<string> words) {
    vector<int> answer{0, 0};
    Hash alphabet(26); // a ~ z
    string prevWord = words[0];
    alphabet.addWord(prevWord);
    
    for(int i = 1; i < words.size(); i++){
        string word = words[i];
        // check if the word form is right
        if(prevWord[prevWord.length() - 1] != word[0]){
            answer[0] = i % players + 1;
            answer[1] = i / players + 1;
            break;
        } else{
            // when the word form is right, check if it exists or not
            if(alphabet.checkWord(word) == false){
                // if 'word' is not found,
                alphabet.addWord(word);
                cout << "ADD WORD : " << word << endl;
            } else{
                // if 'word' is found,
                answer[0] = i % players + 1;
                answer[1] = i / players + 1;
                cout << "BREAKS HERE : " << word << endl;
                break;
            }
        }

        prevWord = word;
    }
    return answer;
}
