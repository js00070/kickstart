#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N,Q;
        int sum[26][1000] = {0};
        cin>>N>>Q;
        string str = "";
        cin>>str;
        // cout<<str<<endl;
        sum[str[0] - 'A'][0] = 1;
        for(int i=1;i<N;i++){
            for(int ch = 0;ch<26;ch++){
                sum[ch][i] = sum[ch][i-1];
            }
            sum[str[i] - 'A'][i] += 1;
        }
        // for(int ch=0;ch<3;ch++){
        //     for(int i=0;i<N;i++){
        //         cout<< sum[ch][i] <<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = 0;
        for(int q=0;q<Q;q++){
            int left, right;
            cin>>left>>right;
            int count[26] = {0};
            bool able = true;
            left--;
            right--;
            for(int i=0;i<26;i++){
                if(left == 0){
                    count[i] = sum[i][right];
                }else{
                    count[i] = sum[i][right] - sum[i][left - 1];
                }
            }
            // for(int i=0;i<26;i++){
            //     cout<<count[i]<<" ";
            // }
            // cout<<endl;
            if((right-left+1)%2 == 0){
                // 全是偶数个
                for(int i=0;i<26;i++){
                    if(count[i] % 2 == 1){
                        able = false;
                    }
                }
            }else{
                // 一个为奇数, 其余全为偶数
                bool findOdd = false;
                for(int i=0;i<26;i++){
                    if(findOdd) {// 若已经找到奇数
                        if(count[i]%2==1){
                            able = false;
                        }
                    }
                    if(count[i] % 2 == 1){
                        findOdd = true;
                    }
                }
            }
            if(able){
                ans++;
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}