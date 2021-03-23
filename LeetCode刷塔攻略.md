# LeetCode刷塔攻略

## 1. 数组

### 1.1 数组遍历

#### 1.1.1 485 最多1的和

思路：遍历，有一就加Cnt，遇非1夹断，与当前最大maxCnt相比，大了替换小了不管！

```c++
int findMaxConsecutiveOnes(vector<int>& nums) {
     int Cnt = 0,maxCnt = 0;
    for(vector<int>::iterator it=nums.begin();it!=nums.end();it++){
        if(*it==1){
            Cnt++;}
        else{
            if(Cnt>=maxCnt)maxCnt = Cnt;
            Cnt = 0;
        }
    }
    maxCnt = max(Cnt, maxCnt);
    return maxCnt;
    }
```

#### 1.1.2 495：提莫攻击

解题思路
直接将本体转化为一个有条件的暴力加和，所以导致时间用时较多。
思路如下：
当两个攻击间隔大于duration时，对第一次攻击的duration累加在总时长上；
当两个攻击间隔不大于duration时，第二次攻击会刷新第一次攻击的时间，可视为第一次攻击的时间的缩短。再进行加和；

![image-20210318114214814](C:\Users\lenovo\AppData\Roaming\Typora\typora-user-images\image-20210318114214814.png)

代码

```c++
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        /*duration:中毒时长
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
};
```

#### 1.1.3 414 第三大的数

取三个数，分别存，一次遍历

但是如果转化为取第n个大的数: 初步考虑使用排序，最后遍历三个不同的

```C++
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
```

#### 1.1.4 628 三个数的最大乘积



```c++
int maximumProduct(vector<int>& nums) {
  sort(nums.begin(), nums.begin()+nums.size());
  for(int x=0;x<nums.size();x++)cout<<nums[x]<<endl;
  if(nums[0]*nums[1]>=nums[nums.size()-2]*nums[nums.size()-3]&&(nums[nums.size()-1]>=0))return nums[0]*nums[1]*nums[nums.size()-1];
  else
  return (nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);

}
```

### 1.2 数组元素

#### 1.2.1  错误的集合

```c++
vector<int> findErrorNums(vector<int>& nums) {

  int sum=0 , len =nums.size() , c_Sum=(1+len)*len/2 , loss, repeat;
  sort(nums.begin() , nums.end()); //将数组排序
  for(int i=0 ; i<len-1 ; i++){
    if(nums[i]==nums[i+1])
      repeat =nums[i];//找出重复的
  }
  for(int i=0 ; i<len ;i++){
    sum+=nums[i];
  }
  loss = repeat+(c_Sum-sum);
  return {repeat , loss};
}
```

#### 1.2.2 消失的数字

原地修改策略：如果数字x存在于数组中，则x对应的地址为nums[x],将对应位置的数字置为负数，完成之后遍历数组，如果对应地方为正数，则说明数组中此位置数字丢失。
这道题好做的原因还是数字介于1-n且都为正，这样就联系起来了数组下标和数组内容。

```c++
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


```

#### 1.2.3 数组中重复数据

**解题思路**
本解法由448拓展而来，建议和448结合食用，首先遍历一遍数组，由于数组中数据都是分布于1~n，所以我们第一次遍历时，遇到的数字都以他为下标进行重定向，比如对于没有重复的数组，x应该位于num[x-1]，那么我们可以利用这个位置对应关系来计数。每次遇到x就在nums[x-1]中加n+1,在遍历时取模。这样第二次遍历中，我们可以通过查看对应位置中有几个n+1来判断x出现了几次。

**代码**

```c++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
    int flag = nums.size()+1;
    vector<int> res;
    for(int x=0;x<nums.size();x++){
        nums[nums[x]%flag-1] += flag;
    }
    for(int x=0;x<nums.size();x++){
        if((nums[x]-2*flag)>0){
            res.push_back(x+1);
        }
    }
    return res;
}
};


```

