class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder m= new StringBuilder();
        int ml=Math.max(word1.length(),word2.length());
        for(int i=0;i<ml;i++)
        {
            if(i<word1.length())
            {
                m.append(word1.charAt(i));
            }
            if(i<word2.length())
            {
                m.append(word2.charAt(i));
            }
        }
        return m.toString();
    }
}