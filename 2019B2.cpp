#include <iostream>
#include <algorithm>
using namespace std;

int N;
int S[1000],E[1000],L[1000];
int num[1000];

bool cmp(int i,int j) {
    return i<j;
}

int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){        
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>S[i]>>E[i]>>L[i];
            num[i] = i;
        }


    }
    return 0;
}