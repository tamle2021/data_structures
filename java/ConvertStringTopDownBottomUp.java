/*
find minimum count of edit operations using dynamic programming top-down approach to convert string
s1 and s2 are strings
convert string 2 to string 1 using delete, insert, or replace operations



**** convert string top down bottom up ****

*/
public class ConvertStringTopDownBottomUp {
    public int findMinimumOperationsTd(String s1,String s2) {
        Integer[][] dp = new Integer[s1.length() + 1][s2.length() + 1];
        return findMinimumOperationsTd(dp,s1,s2,0,0);
    }

    private int findMinimumOperationsTd(Integer[][] dp,String s1,String s2,int i1,int i2) {
        if (dp[i1][i2] == null) {
            // if reach end of s1, then insert all remaining characters of s2
            if (i1 == s1.length())
                dp[i1][i2] = s2.length() - i2;
            // if reach end of s2, then delete all remaining characters of s1
            else if (i2 == s2.length())
                dp[i1][i2] = s1.length() - i1;
            // strings have a matching character so recursively match for remaining lengths
            else if (s1.charAt(i1) == s2.charAt(i2))
                dp[i1][i2] = findMinimumOperationsTd(dp,s1,s2,i1 + 1,i2 + 1);
            else {
                int c1 = findMinimumOperationsTd(dp,s1,s2,i1 + 1,i2); // delete
                int c2 = findMinimumOperationsTd(dp,s1,s2,i1,i2 + 1); // insert
                int c3 = findMinimumOperationsTd(dp,s1,s2,i1 + 1,i2 + 1); // replace
                dp[i1][i2] = 1 + Math.min(c1,Math.min(c2,c3));
            }
        }

        return dp[i1][i2];
    }

    public int findMinimumOperationsBu(String s1,String s2) {
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];

        // if reach end of s1, then insert all remaining characters of s2
        for (int i1 = 0; i1 <= s1.length(); i1++)
            dp[i1][0] = i1;
        // if reach end of s2, then delete all remaining characters of s1
        for (int i2 = 0; i2 <= s2.length(); i2++)
            dp[0][i2] = i2;
        for (int i1 = 1; i1 <= s1.length(); i1++) {
            // if strings have a matching character, then recursively match for remaining lengths
            for (int i2 = 1; i2 <= s2.length(); i2++) {
                if (s1.charAt(i1 - 1) == s2.charAt(i2 - 1))
                    dp[i1][i2] = dp[i1 - 1][i2 - 1];
                else
                    dp[i1][i2] = 1 + Math.min(dp[i1 - 1][i2], // delete
                                     Math.min(dp[i1][i2 - 1], // insert
                                        dp[i1 - 1][i2 - 1])); // replace
            }
        }

        return dp[s1.length()][s2.length()];
    }

    public static void main(String[] args) {
        System.out.println("**** convert string top down bottom up ****");
        int result1, result2;
        String str1 = new String("lobster");
        String str2 = new String("123ster");
        String str3 = new String("ham");
        String str4 = new String("spam");

        ConvertStringTopDownBottomUp c = new ConvertStringTopDownBottomUp();
        result1 = c.findMinimumOperationsTd(str1,str2);
        System.out.println("convert from " + str2 + " to " + str1 + " => ");
        System.out.println("result1: " + result1);

        result2 = c.findMinimumOperationsBu(str3,str4);
        System.out.println("convert from " + str4 + " to " + str3 + " => ");
        System.out.println("result2: " + result2);
    }
}
