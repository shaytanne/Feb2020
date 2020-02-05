
#define DEBUG 0

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool byRevAlphabet(string a, string b) { return tolower(a[0]) > tolower(b[0]);}
bool byStrLength(string a, string b) { return a.size() > b.size(); }

vector<string> MergeLists(vector<string> Original, vector<string> toAdd, vector<string> toDel){
    
    //make a copy of original list
    vector<string> Result(Original);
    

    // add to Result strings from Add List 
    // that don't already exist in Original
    for (string word : toAdd) {
        if (find(Result.begin(), Result.end(), word) == Result.end())
            Result.push_back(word);
    }


    // remove from Result strings in Delete List
    for (string word : toDel) {
        auto i_toDel = find(Result.begin(), Result.end(), word);

        if (i_toDel != Result.end())
            Result.erase(i_toDel);   
     }


    //arrange in reverse alphabetical order for tie cases
    sort(Result.begin(), Result.end(), byRevAlphabet);

#if DEBUG   //debugging block to check correct alph. sorting
    cout << "after alph reverse Result is: ";
    for (string s : Result)
        cout << s << " ";
    cout << endl << endl;
#endif

    //sort by decreasing string length
    sort(Result.begin(), Result.end(), byStrLength);
    
    return Result;
}