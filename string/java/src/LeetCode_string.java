


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



public class LeetCode_string {
	public static void main(String[] args){
		String str = "Hello, my name is John";
		var s1 = new Solution() ;
		int x = s1.lengthOfLastWord(str);
		System.out.print(x);
	}
}
