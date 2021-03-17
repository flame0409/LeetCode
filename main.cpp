#include <iostream>
#include <vector>
using namespace std;



//485最大连续1个数
int findMaxConsecutiveOnes(vector<int>& nums) {
    //cout<<nums.at(0)<<endl;
    int Cnt,max = 0;
    for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
        if(*it==1){
            Cnt++;}
        else{
            if(Cnt>=max)max = Cnt;
            Cnt = 0;
        }
    }
    cout<<Cnt;
    return max;
}
int main() {
    vector<int> list = {1,0,1,1,0,1};
    //cout<<findMaxConsecutiveOnes(list);
}
