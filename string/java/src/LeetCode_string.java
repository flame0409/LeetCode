


class Solution {
    public int countSegments(String s) {
    	int segmentCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((i == 0 || s.charAt(i-1) == ' ') && s.charAt(i) != ' ') {
                segmentCount++;
            }
        }

        return segmentCount;
    }
    public int lengthOfLastWord(String s) {
    	int len = 0;
    	s = s.trim();
    	for(int x = s.length()-1; x>=0; x--) {
    		len++;
    		if(x-1<0||s.charAt(x-1)==' ')break;
    	}
    	return len;
    }
}

class Base64{
	
	private static char[] Base64ByteToStr = null;
    private static final int RANGE = 0xFF;
    private static byte[] StrToBase64Byte;

    static {
        Base64.Base64ByteToStr = new char[]{'v', 'w', 'x', 'r', 's', 't', 'u', 'o', 'p', 'q', '3', '4', '5', '6', '7', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'y', 'z', '0', '1', '2', 'P', 'Q', 'R', 'S', 'T', 'K', 'L', 'M', 'N', 'O', 'Z', 'a', 'b', 'c', 'd', 'U', 'V', 'W', 'X', 'Y', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', '8', '9', '+', '/'};
        Base64.StrToBase64Byte = new byte[0x80];
    }

    public Base64() {
        super();
    }
	
	public String Encode(byte[] plain) {
		int rest = 3;
		StringBuilder result = new StringBuilder();
		
		int loc = 0;
		for(loc = 0; loc <= plain.length; loc += 3) {
			byte[] group = new byte[4];
			byte b = 0;
			int len ;
			for(len = 0; len<=2; ++len) {
				if(loc+len <= plain.length-1) {
					group[len] = ((byte) ((plain[loc+len] & 0xFF)>>> len*2 + 2|b));
					b = ((byte)(((plain[loc+len]& 0xFF)<<(2-len)*2 + 2 & 0XFF)>>>2));
				}
				else {
					group[len] = b;
					b = 0x40;
				}
			}
			
			group[rest] = b;
			for(len = 0; len <= rest; len++) {
				if(group[len] <= 0x3F) {
					result.append(Base64.Base64ByteToStr[group[len]]);
				}
				else {
					result.append('=');
				}
			}
		}
		
		return result.toString();
	}
	
	
	
	public int Decode(String s) {
		return 0;
	}
	
}



public class LeetCode_string {
	public static void main(String[] args){
		String str = "05397c42f9b6da593a3644162d36eb01";
		var base = new Base64() ;
		String result = base.Encode(str.getBytes());
		System.out.print(result);
	}
}
