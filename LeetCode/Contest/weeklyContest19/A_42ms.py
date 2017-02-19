class Solution(object):
    def convertTo7(self, num):
        """
        :type num: int
        :rtype: str
        """
        ret = ""
        t = num if num>0 else -num
        while(t>=7):
            ret=str(t%7)+ret
            t/=7
        ret=str(t)+ret
        if num<0:
            ret="-"+ret;
        return ret
