


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
}



public class LeetCode_string {
	public static void main(String[] args){
		String str = "Hello, my name is John";
		Solution s1 = new Solution() ;
		int x = s1.countSegments(str);
		System.out.print(x);
	}
}
