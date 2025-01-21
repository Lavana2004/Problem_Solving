class Solution {
public:
    int fib(int n) {
        int p1=0,p2=1;
        int c=0;
        if(n==0||n==1)
           return n;
        for(int i=2;i<=n;i++)
        {
            c=p1+p2;
            p1=p2;
            p2=c;
        }
        return p2;
    }
};