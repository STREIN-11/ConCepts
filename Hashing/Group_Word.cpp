#include<bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

string getkey(string &str){
    bool visited[MAX_CHAR] = { false };

    for (int j = 0; j < str.length(); j++)
        visited[str[j] - 'a'] = true ;
    string key = "";
    for (int j=0; j < MAX_CHAR; j++)
        if (visited[j])
            key = key + (char)('a'+j);
    return key;
}

void sameword(string words[],int n){

    unordered_map <string, vector <int> > Hash;
    for (int i=0; i<n; i++)
    {
        string key = getkey(words[i]);
        Hash[key].push_back(i);
    }
    for (auto it = Hash.begin(); it!=Hash.end(); it++)
    {
      for (auto v=(*it).second.begin(); v!=(*it).second.end(); v++)
          cout << words[*v] << ", ";
      cout << endl;
    }
}
int main(){
    string words[] = { "may", "student", "students", "dog",
                 "studentssess", "god", "cat", "act", "tab",
                 "bat", "flow", "wolf", "lambs", "amy", "yam",
                 "balms", "looped", "poodle", "yo", "oy"};
    int n = sizeof(words)/sizeof(words[0]);
    sameword(words,n);

return 0;
}