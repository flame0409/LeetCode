#include <iostream>
#include <algorithm> 
#include <vector>
#include<unordered_map>
//#include<math>
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
//495 提莫攻击
/*
直接将本体转化为一个有条件的暴力加和，所以导致时间用时较多。
思路如下：
当两个攻击间隔大于duration时，对第一次攻击的duration累加在总时长上；
当两个攻击间隔不大于duration时，第二次攻击会刷新第一次攻击的时间，可视为第一次攻击的时间的缩短。再进行加和；

*/
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    /*
    duration:中毒时长
    timeSeries：时间序列
     */
    if(timeSeries.size()==0)return 0;
    int time= duration;
    for(int x=1; x<timeSeries.size();x++){
        cout<<time<<endl;
        //在范围外挨了下一箭
        //cout<<timeSeries[x]-(timeSeries[x-1]+duration);
        if(timeSeries[x]-(timeSeries[x-1]+duration)>=0)time = time + duration;
        //在范围内挨了下一箭
        if(timeSeries[x]-(timeSeries[x-1]+duration)<0){
            time =time + ((timeSeries[x]-timeSeries[x-1]));
            //cout<<"ok";
            }
    }
    return time;
}

//414 第三大的树
int thirdMax(vector<int>& nums) {
        // 最大的三个数字 max1,max2,max3, 其中max3就是结果
        long max1 = LONG_MIN;
        long max2 = LONG_MIN;
        long max3 = LONG_MIN;

        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            // 考虑大于第三大的数字，而且和第一大第二大都不相同，忽略相同的情况
            if (nums[i] > max3 && nums[i] != max1 && nums[i] != max2)
            {
                if (nums[i] > max1)
                {
                    // 更新max1
                    max3 = max2;
                    max2 = max1;
                    max1 = nums[i];
                }
                else if (nums[i] > max2)
                {
                    // 更新max2
                    max3 = max2;
                    max2 = nums[i];
                }
                else max3 = nums[i];
            }
        }
        // 考虑不存在max3,则直接返回最大值
        return max3 == LONG_MIN ? max1 : max3;
}

//628 三个数的最大乘积
int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.begin()+nums.size());
    for(int x=0;x<nums.size();x++)cout<<nums[x]<<endl;
    if(nums[0]*nums[1]>=nums[nums.size()-2]*nums[nums.size()-3]&&(nums[nums.size()-1]>=0))return nums[0]*nums[1]*nums[nums.size()-1];
    else
    return (nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);
}

// //645 错误的集合
// vector<int> findErrorNums(vector<int>& nums) {
//     int sum=0 , len =nums.size() , c_Sum=(1+len)*len/2 , loss, repeat;

//     sort(nums.begin() , nums.end()); //将数组排序
//     for(int i=0 ; i<len-1 ; i++){
//         if(nums[i]==nums[i+1])
//             repeat =nums[i];//找出重复的
//     }
//     for(int i=0 ; i<len ;i++){
//         sum+=nums[i];
//     }
//     loss = repeat+(c_Sum-sum);
//     return {repeat , loss};
// }
// // 697 数组的度
// int findShortestSubArray(vector<int>& nums) {
//     unordered_map<int, vector<int>> mp;
//     int n = nums.size();
//     for (int i = 0; i < n; i++) {
//         if (mp.count(nums[i])) {
//             mp[nums[i]][0]++;
//             mp[nums[i]][2] = i;
//         } else {
//             mp[nums[i]] = {1, i, i};
//         }
//     }
//     int maxNum = 0, minLen = 0;
//     for (auto& [_, vec] : mp) {
//         if (maxNum < vec[0]) {
//             maxNum = vec[0];
//             minLen = vec[2] - vec[1] + 1;
//         } else if (maxNum == vec[0]) {
//             if (minLen > vec[2] - vec[1] + 1) {
//                 minLen = vec[2] - vec[1] + 1;
//             }
//         }
//     }
//     return minLen;
// }

//448 消失的数字 
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    for(int x=0; x<nums.size(); x++){
        if(nums[abs(nums[x])-1]>0){
            nums[abs(nums[x])-1] = -nums[abs(nums[x])-1];
            cout<<"get"<<nums[nums[x]-1]<<endl;;
        }
        else continue;
    }
    for(int x=1;x<=nums.size();x++){
        if(nums[x-1]>0){
            res.push_back(x);
            cout<<x<<" ";
        }
    }
    return res;
}

int main() {
    vector<int> list = {4,3,2,7,8,2,3,1};
    //cout<<findMaxConsecutiveOnes(list);
    //vector<int> timeSeries = {1,2,3,4,5};
    //int duration = 5;
    //cout<<findPoisonedDuration(timeSeries, duration);
    findDisappearedNumbers(list);
}
