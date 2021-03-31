#include <iostream>
#include <algorithm> 
#include <vector>
#include<unordered_map>
//#include<math>
using namespace std;
#include<cstdio>
#include<algorithm>


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
        }
        else continue;
    }
    for(int x=1;x<=nums.size();x++){
        if(nums[x-1]>0){
            res.push_back(x);
        }
    }
    return res;
}

// 442 数组中重复的数据
vector<int> findDuplicates(vector<int>& nums) {
    int flag = nums.size()+1;
    vector<int> res;
    for(int x=0;x<nums.size();x++){
        nums[nums[x]%flag-1] += flag;
    }
    for(int x=0;x<nums.size();x++){
        if((nums[x]-2*flag)>0){
            cout<<x+1<<" ";
            res.push_back(x+1);
        }
    }
    return res;
}

//41 缺失的第一个正数

// int firstMissingPositive(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     bool flag = false;
//     for(int x = 0;x < nums.size();x++){
//         if(nums[x]>0){
//             if(nums[x]==1)flag=true;
//             if(nums[x]!=1&&flag==false)return 1;
//             if(x==nums.size()-1)return nums[x]+1;
//             if(nums[x+1]!=nums[x]+1&&nums[x+1]!=nums[x])return nums[x]+1;
            
//         }
//     }
//     if(nums[nums.size()-1]<=0)return 1;
// }
//274 H指数
int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int h=0;
    for(int x=citations.size(); x>0;x--){
        if(citations[citations.size()-1-x]>x) h++;
    }
    return h;
}
//453最小操作次数使数组元素相等
int minMoves(vector<int>& nums) {
    if(nums.size()==1)return 0;
    int minNum = nums[0];
    int sum=0;
    for(int &num: nums){
        minNum = min(minNum, num);
    }
    for(int x=0; x<nums.size(); x++){
        sum += nums[x]-minNum;
    }
    return sum;
}
//665 非递减数列
 bool checkPossibility(vector<int>& nums) 
    {
        if (nums.size() == 1)   return true;
        bool flag = nums[0] <= nums[1] ? true : false; 
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])  
            {
                if (flag)   
                {
                    if (nums[i + 1] >= nums[ i - 1])
                        nums[i] = nums[i + 1];
                    else                            
                        nums[i + 1] = nums[i];      
                    flag = false;                  
                }   
                else        
                    return false;
            }
        }
        return true;
}


//283. 移动零
void moveZeroes(vector<int>& nums) {
    // for(int x=0; x<nums.size(); x++){
    //     if(nums[x]==0){
    //     for(int y=x;y<nums.size();y++){
    //         if(nums[y]!=0){swap(nums[x],nums[y]);
    //         break;
    //         }
    //     }
    //     }
    // }
    //  for(int x=0; x<nums.size(); x++){
    //      cout<<nums[x]<<" ";
    //  }
    int right=0;
    for(int left=0; left<nums.size(); left++){
        if(nums[left]){
            swap(nums[right],nums[left]);
            right++;
        }
    }
    for(int x=0; x<nums.size(); x++){
         cout<<nums[x]<<" ";
     }
}


//118杨辉三角

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> Triangle;
    vector<int> row;
    for(int x=1; x<=numRows; x++){
        for (int y=1; y<=x; y++){
            //首尾加1
            if(row.size()==0) {row.emplace_back(1);continue;}
            if(y==x||y==1){row.emplace_back(1);continue;}
            row.emplace_back(Triangle[x-2][y-1]+Triangle[x-2][y-2]);
        }
        Triangle.emplace_back(row);
        row.clear();
    }

    for(int x=0;x<Triangle.size();x++){
        cout<<Triangle.size()<<endl;
    }

    return Triangle;
    
}

 vector<int> getRow(int rowIndex) {
     vector<int> row_1 = {1};
     vector<int> row_2 = {1,1};
     if(rowIndex == 0)return row_1;
     if(rowIndex == 1)return row_2;
     for(int x=1; x<=rowIndex; x++){
         row_1.swap(row_2);
         row_2.clear();
         for(int y=0; y<=x; y++){
            if(y==0 || y==x)row_2.emplace_back(1); 
            else
            row_2.emplace_back(row_1[y]+row_1[y-1]);  
         }
        
     }
     //for(int x=0;x<row_2.size();x++)cout<<row_2[x]<<" ";
     return row_2;
}

//598范围求和
int maxCount(int m, int n, vector<vector<int>>& ops) {
    if(ops.size()==0)return m*n;
    int min_a = m, min_b = n;
    for(int x=0; x<ops.size(); x++){
        min_a = min(min_a, ops[x][0]);
        min_b = min(min_b, ops[x][1]);
    }
    return min_a*min_b;

}

//189 旋转数组*****
void rotate(vector<int>& nums, int k) {
    // vector<int> newNum(nums.size());
    // for(int n=0; n<nums.size(); n++){
    //     if(n+k >= nums.size()){
    //         newNum[(n+k)%nums.size()]=nums[n];
    //     }
    //     else newNum[n+k] = nums[n];
    // }
    // newNum.swap(nums);

   int n = nums.size();
    k = k % n;
    int count = __gcd(k, n);
    for (int start = 0; start < count; ++start) {
        int current = start;
        int prev = nums[start];
        do {
            int next = (current + k) % n;
            swap(nums[next], prev);
            current = next;
        } while (start != current);
    }
    
}

//396 旋转函数
int maxRotateFunction(vector<int>& nums) {
    int res = 0;
    int max_res = INT_MIN;
    int sum_num = 0;
    for(int x = 0; x<nums.size(); x++){
        sum_num += nums[x];
        res += x*nums[x];
    }
    for(int x = nums.size()-1; x >= 0; x--){
        res = res + sum_num - nums[x]*nums.size();
        max_res = max(max_res, res);
    }
    return max_res;
}

int main() {
    vector<int> list = {4,3,2,6};
    //cout<<findMaxConsecutiveOnes(list);
    //vector<int> timeSeries = {1,2,3,4,5};
    //int duration = 5;
    //cout<<findPoisonedDuration(timeSeries, duration);
    //cout<<checkPossibility(list);
    cout<<maxRotateFunction(list);
}
