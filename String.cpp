#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool detectCapitalUse(string word) {

    bool res = true;
    if(97<=word[0]&&word[0]<=122){
        for(int n=1; n<word.size(); n++){
            char q = word[n];
            if(97>word[n]||word[n]>122)
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

int main(){
    string str = "ffffffffffffffffffffF";
    bool res = detectCapitalUse(str);
}