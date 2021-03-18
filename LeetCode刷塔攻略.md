# LeetCode刷塔攻略

## 1. 数组

### 1.1 485 最多1的和

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

### 1.2 495：提莫攻击

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



