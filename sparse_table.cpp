#include <iostream>
#include <string>
using namespace std;

int N;
int a[10000];
int ST[10000][32][26];
// 状态转移方程: ST[i,j][ch] = ST[i,j-1][ch] + ST[i+2^(j-1), j-1][ch]

void init() {
    // 测试数据 ABAACCA
    string str = "ABAACCA";
    N = str.size();
    for(int i=0;i<str.size();i++){
        a[i] = str[i] - 'A';
    }

    // 初始化
    for(int i=0;i<N;i++){
        for(int ch=0;ch<26;ch++){
            if(a[i] == ch){
                ST[i][0][ch] = 1;
            }else{
                ST[i][0][ch] = 0;
            }
        }
    }

    // 递推,时间复杂度O(nlogn)
    for(int i=0;i<N;i++){
        for(int j=1;i+(1<<j)<N;j++){
            for(int ch=0;ch<26;ch++){
                ST[i][j][ch] = ST[i][j-1][ch] + ST[i+(1<<(j-1))][j-1][ch];
            }
        }
    }
}

int query(int l, int r, int ch){ // 在[l,r]中查询ch出现次数
    int len = l-r+1; // 区间长度
    int left = l;
    int ans = 0;
    // 接下来把这个区间划分成若干个长度为2^i区间的和
    for(int i=27;i>=0;i--){ // 最大不能超过2^28
        if ( (1<<i) <= len ){
            ans += ST[left][i][ch];
            len -= (1<<i);
            left += (1<<i);
        }
    }
    return ans;
}

int main() {

    return 0;
}