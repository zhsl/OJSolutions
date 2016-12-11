class Solution(object):
    
    def isnum(self, s):
        for x in s:
            if (x<'0' or x>'9'):
                return False
        return True
        
    def isnumalpha(self, s):
        for x in s:
            if( (x>='0' and x<='9') or (x>='a' and x<='f') or (x>='A' and x<='F')):
                continue
            else: return False
        return True
    
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        if('.' in IP):
            row = IP.split('.')
            if(len(row)!=4):
                return "Neither"
            for x in row:
                if x == '' or self.isnum(x)==False:
                    return "Neither"
                xx=int(x)
                if( xx<0 or xx>255 or len(str(xx))!=len(x)):
                    return "Neither"
            return "IPv4"
        elif (':' in IP):
            row = IP.split(':')
            if(len(row)!=8):
                return "Neither"
            for x in row:
                if x == '' or self.isnumalpha(x)==False:
                    return "Neither"
                if(self.isnum(x)):
                    xx=int(x)
                    if(len(x)==1 and xx==0):
                        continue
                    if(len(x)>4):
                        return "Neither"
                else:
                    if(len(x)>4):
                        return "Neither"
            return "IPv6"
        return "Neither"
