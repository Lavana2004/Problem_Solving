class Solution:
    def reverseWords(self, s: str) -> str:
        s=s.strip()
        w=s.split()
        rv=w[::-1]
        return " ".join(rv)