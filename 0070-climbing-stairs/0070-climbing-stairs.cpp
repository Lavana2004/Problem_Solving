class Solution {
public:
    int climbStairs(int n) {
        if(n<=3)
        {
            return n;
        }
        int p1=2;
        int p2=3;
        int c=0;
        for(int i=3;i<n;i++)
        {
            c=p1+p2;
            p1=p2;
            p2=c;
        }
        return p2;

        
    }
};