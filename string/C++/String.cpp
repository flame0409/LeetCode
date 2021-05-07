#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include <algorithm>

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

//58 最后一个单词长度
int lengthOfLastWord(string s) {
    int len = 0;
    for(int x = s.size()-1; x >= 0; x--){
        if(s[x]!=' '){//第一个不是‘ ’的字符
            len++;
            if(((x-1)<0)||s[x-1]==' ')return len;
        }
    }
    return len;
}

//344. 反转字符串
void reverseString(string s, int i, int j) {
    while(i<=j){
        swap(s[i], s[j]);
        i++;
        j--;
    }
}
//541.翻转字符串II
string reverseStr(string s, int k) {
    int len = s.size()/(2*k);//2k的次数
    cout<<len;
    int n = s.size()%(2*k);
    int loc = 0;
    for(int x=0; x<len; x++){
        reverseString(s, loc, loc+k-1);
        loc = loc+2*k;
    }
    if(s.size()%(2*k)<k){
        reverseString(s, loc, s.size()-1);
    }
    if(s.size()%(2*k)<(2*k)&&s.size()%(2*k)>=k){
        reverseString(s, loc, loc+k-1);
    }
    return s;
}
 string reverseStrII(string s, int k) {
    int i = 0,n=s.size();
    while (i < n) { // 指针没到字符串末尾进入循环
        if (i + k > n) { // 指针后面不够k个就全部反转
            reverse(s.begin()+i, s.end());
        } else {
            reverse(s.begin()+i, s.begin()+i+k);//reverse的第二个参数是指向要翻转范围的下一个
        }
        i += 2*k;
    }
    return s;
}
//翻转字符串中的单词
string reverseWords(string s) {
    int j=0;
    for(int i=0; i<s.size();i++){
        if(s[i]==' ')continue;
        if(s[i]!=' '){
            int j=0;
            while(s[i+j]!=' '&&(i+j)<s.size()){
                j++;
            }
           reverse(s.begin()+i, s.begin()+i+j);
            i=j+i;
        }
    }
    return s;
}
//151 翻转字符串里的单词
// string reverseWordss(string s) {
//     stringstream str;
//     string ans = "", temp;
//     str<<s;
//     while(str>>temp){
//         ans = " "+temp+ans;
//     }
//     if(ans!=""){
//         ans.erase(ans.begin());
//     }
//     return ans;
// }
string reverseWordII(string s){
    //1. 先翻转整个字符串
    //int i = 0, j = 0;
    reverse(s.begin(),s.begin()+s.size());
    //2. 翻转单词
    for(int i=0; i<s.size();i++){
        if(s[i]==' ')continue;
        if(s[i]!=' '){
            int j=0;
            while(s[i+j]!=' '&&(i+j)<s.size()){
                j++;
            }
           reverse(s.begin()+i, s.begin()+i+j);
            i=j+i;
        }
    }
    int j=0;
    while(j<s.size()-1){
        if(s[j]==' '){
            if(s[j+1]==' '){
                s.erase(s.begin()+j);
                continue;
            }
        }
        j++;
    }
    if(s[0]==' ')s.erase(s.begin());
    if(s[s.size()-1]==' '){cout<<"ok";s.erase(s.begin()+s.size()-1);}
    return s;
}




int main(){
    vector<char> strs = {'h','e','l','l','o'};
    string s = " hello world! ";
    // int x = lengthOfLastWord(s);
    // cout<<x;
    //reverseString(strs, 1, 4);
    cout<<reverseWordII(s);
}