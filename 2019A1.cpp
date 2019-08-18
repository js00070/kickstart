#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T = 0;
    cin>>T;
    for(int t = 0;t<T;t++){
        int n,p;
        // int count[10004] = {0};
        int skill[100004] = {0};
        int sum[100004] = {0};
        // int energy[10004] = {0};
        // int sum[10004] = {0};
        // int bound_arr[10004] = {0}; // 最终培训为技能s的队员的所需初始技能门槛bound[s]，也就是说，必须技能大于bound[s]，才有资格被培训
        // int time[10004] = {0}; // 培训到s技能所花时间time[s]
        cin>>n>>p;
        for(int i=0;i<n;i++){
            cin>>skill[i];
            // count[skill[i]]++;
        }
        sort(skill,skill+n);
        sum[0] = 0;
        int answer = 0x7FFFFFFF;
        for(int i=1;i<=n;i++){
            sum[i] = sum[i-1] + skill[i-1];
        }
        for(int i=p-1;i<n;i++){
            answer = min(answer,p*skill[i] - (sum[i+1] - sum[i+1-p]));
        }

        // sum[0] = count[0];
        // energy[0] = 0;
        // for(int i=1;i<=10000;i++){
        //     sum[i] = count[i] + sum[i-1];
        //     energy[i] = energy[i-1] + sum[i-1];
        // }
        // int answer = 0x7FFFFFFF;
        // for(int i=1;i<=10;i++){
        //     printf("skill: %d, sum: %d\n", i,sum[i]);
        // }
        // for(int i=1;i<=10000;i++){
        //     if(sum[i] >= p){
        //         int bound = upper_bound(sum,sum + i + 1,sum[i]-p) - sum - 1; // 找到sum中第一个大于sum[i]-p的元素下标，再减一(最后一个小于等于的)
        //         if(bound == i){
        //             answer = 0;
        //             printf("answer is 0\n");
        //             break;
        //         }
        //         int bound_num = sum[i] - sum[bound];  // 达到门槛的人数
        //         int margin = bound_num - (sum[i] - sum[bound+1]); // 正好踩在门槛边缘上的人数
        //         // 应该满足 margin == count[bound+1]
        //         int surplus = bound_num - p; // 达到了门槛但会被不幸淘汰的人数
        //         time[i] = energy[i] - energy[bound] - (sum[bound]*(i-bound)) + (count[bound+1] - surplus) * (i-bound-1);
        //         if(i <=10){
        //             printf("bound=%d, margin=%d, surplus=%d, time[i]=%d\n",bound,margin,surplus,time[i]);
        //         }
        //     }else{
        //         time[i] = 0x7FFFFFFF;
        //     }
        // }
        // for(int i=1;i<=10000;i++){
        //     answer = min(answer,time[i]);
        // }
        
        printf("Case #%d: %d\n",t+1,answer);
    }
}