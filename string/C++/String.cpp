#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool detectCapitalUse(string word) {

    bool res = true;
    if(97<=word[0]&&word[0]<=122){
        for(int n=1; n<word.size(); n++){
            char q = word[n];
            if(97>word[n]||word[n]>122){}
            res=false;
            break;
        }
    }
    if(word[0]>=65&&word[0]<=90){
        if(word[1]>=65&&word[1]<=90){//全大写
            for(int n=2; n<word.size(); n++){
            if(65>word[n]||word[n]>90){
                res=false;
                break;
                }
            }
        }
        if(word[1]>=97&&word[1]<=122){//小写
            for(int n=2; n<word.size(); n++){
            if(word[n]<97||word[n]>122){
                res=false;
                break;
                }
            }
        }
    }
    return res;
}

//125 验证回文串
 bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
}

//14 最长公共前缀
  string longestCommonPrefix(vector<string>& strs) {
     if(strs.size()==0)return "";
     for(int x=0; x<strs[0].size(); x++){//由第一个字符开始
         for(int y=1; y< strs.size(); y++){
             if(strs[0][x]!=strs[y][x]||x == strs[y].size())
             return strs[0].substr(0, 0 + x);
         }
     }
     return strs[0];
}
//434 字符串单词数
int countSegments(string s) {
    int num = 0;
    for(int x = 0; x < s.size() ; x++ ){
        if((num == 0 || s[x-1] == ' ')&&s[x]!=' ')num++;
    }
    return num;
}


int main(){
    vector<string> strs = {"flower","flow","flight"};
    string s = "Hello, my name is John";
    int x = countSegments(s);
    cout<<x;
}