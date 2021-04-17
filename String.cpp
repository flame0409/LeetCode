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
     int i=0, j=s.size()-1;//左指针，右指针
     bool res = true;
     while(i<=j){

         char x = s[i]; char y = s[j];

         if(s[j]<=64||(s[j]>=91&&s[j]<=96)||s[j]>=123){
             j--;
             continue;
         }
         if(s[i]<=64||(s[i]>=91&&s[i]<=96)||s[i]>=123){
             i++;
             continue;
         }

         if(65<=s[i]&&s[i]<=90){//左大写
             if(s[j]!=s[i]&&s[j]!=s[i]+32){
                // cout<<s[j]<<"   "<<s[i]+32;                 
                 res = false;
                 break;
                 }
         }
         if(97<=s[i]&&s[i]<=122){
             if(s[j]!=s[i]&&s[j]!=s[i]-32){
                 res = false;
                 break;
             }
         }
         if(i>=j)break;
         i++;
         j--;
     }
     return res;
}

int main(){
    string str = "race a car";
    bool res = isPalindrome(str);
}