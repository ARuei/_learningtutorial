#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {

    int n=nums.size();
    if(n==0)return 0;
    if(n==1)return 1;

    int res=0;
    vector<int> dp(n,1); // init with length 1
        
    for(int i=0;i<n;++i) {
        for(int j=0;j<i;++j) { // from beginning to index i 
            if(nums[j]<nums[i]) { 
            // if it is in increasing order, increases the value 

                dp[i]=max(dp[i],dp[j]+1); 
            }   
        }

        res = max(res,dp[i]);
    }

    return res;
}

int main () {

    int num;
    while (cin >> num) {

        vector<int> nums(num);
        for (int i=0; i<num; i++) {
            cin >> nums[i];
        }

        int ret = lengthOfLIS(nums);
        cout << ret << endl;
    }

    return 0;
}