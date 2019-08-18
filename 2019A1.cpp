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
        printf("Case #%d: %d\n",t+1,answer);
    }
}