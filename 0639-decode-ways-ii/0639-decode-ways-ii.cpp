class Solution {
public:
    #define ll long long
    #define MOD 1000000007
    int numDecodings(string s) {
        int size = s.size();
        vector<int> dp(size+1,0);
        if(s[0]=='0')
        {
            return 0;
        }
        dp[0]=1;
        dp[1] = (s[0] == '*')?9:1;
        for(int i=2;i <= size;i++)
        {
            char cur = s[i-1],prev = s[i-2];
            
            if(cur == '*')
            {
                dp[i] = ((long)9*dp[i-1]%MOD)%MOD;
            }else if(cur != '0')
            {
                dp[i] = dp[i-1];
            }
            if(prev == '*')
            {
                if(cur == '*')
                {
                    dp[i] = (dp[i] + (long)15*dp[i-2]%MOD)%MOD;
                }else if(cur <= '6')
                {
                    dp[i] = (dp[i] + (long)2*dp[i-2]%MOD)%MOD;
                }else{
                    dp[i] = (dp[i] + dp[i-2])%MOD;
                }
            }else if(prev == '1'){
                if(cur == '*')
                {
                    dp[i] = (dp[i] + (long)9*dp[i-2]%MOD)%MOD;
                }else{
                    dp[i] = (dp[i] + dp[i-2])%MOD;
                }
            }else if(prev == '2')
            {
                if(cur == '*')
                {
                    dp[i] = (dp[i] + (long)6*dp[i-2]%MOD)%MOD;
                }else if(cur <= '6')
                {
                    dp[i] = (dp[i] + dp[i-2])%MOD;
                }
            }
        }
        return dp.back();
    }
};