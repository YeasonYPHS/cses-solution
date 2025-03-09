#include <iostream>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)

const int M = 1e9+7;

int main(){
    optimizeIO();

    int nums[26]={},cnt=0,ptr=-1;
    
    char ch = getchar();
    while('A'<=ch && ch<='Z') {
        ++nums[ch-'A'];
        ch = getchar();
    }

    for(int i=0;i<26;++i){
        if(nums[i]&1) {
            ++cnt;
            ptr = i;
        }
    }

    if(cnt>1){
        cout << "NO SOLUTION\n";
        return 0;
    }
    

    for(int i=0;i<26;++i){
        if(i==ptr) continue;
        for(int j=0;j<nums[i]/2;++j) cout  << char('A'+i);
    }

    if(cnt>0) while(nums[ptr]--) cout << char('A'+ptr);

    for(int i=25;i>=0;--i){
        if(i==ptr) continue;
        for(int j=0;j<nums[i]/2;++j) cout  << char('A'+i);
    }
    
    return 0;
}