class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer,Integer>m=new HashMap<>();
        HashSet<Integer> o=new HashSet<>();
        for(int num:arr)
        {
            m.put(num,m.getOrDefault(num,0)+1);
        }
        for(int f: m.values())
        {
            if(!o.add(f))
            {
                return false;
            }
        }
        return true;
    }
}