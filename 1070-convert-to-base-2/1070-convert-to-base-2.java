class Solution {
    public String baseNeg2(int n) {
        StringBuilder result=new StringBuilder();
        if(n==0) return "0";
        while(n!=0)
        { 
            int r=n%-2;
            int q=n/-2;
        if(r<0)
        {
            r+=2;
            q+=1;
        }
        result.append(r);
        n=q;
        }
        return result.reverse().toString();
    } 
}
