/*
One is a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed and
only constraint stopping all houses from being robbed is that adjacent houses have security systems connected which will automatically
contact the police if two adjacent houses were broken into on the same night.  Given an integer array nums representing the amount
of money of each house, return the maximum amount of money one can rob without alerting the authorities.

# example 1
input:
nums = [1,2,3,1]

output:
4

explanation:
Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount that can be robbed = 1 + 3 = 4.

# example 2
input:
nums = [2,7,9,3,1]

output:
12

explanation:
Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount that can be robbed = 2 + 9 + 1 = 12.

constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400




**** house robber ****

*/

import java.util.Arrays;

public class HouseRobber {
	public int findMaxTopDown(int[] houseAmount) {
		int dp[] = new int[houseAmount.length];
		return findMaxTopDown(dp,houseAmount, 0);
	}

	private int findMaxTopDown(int[] dp,int[] houseAmount,int currentIndex) {
		if (currentIndex >= houseAmount.length)
			return 0;
 
		if (dp[currentIndex] == 0) {
			int getCurrent = houseAmount[currentIndex] + findMaxTopDown(dp,houseAmount,currentIndex + 2);
			int skipCurrent = findMaxTopDown(dp,houseAmount,currentIndex + 1);
			dp[currentIndex] = Math.max(getCurrent,skipCurrent);
		}

		return dp[currentIndex];
	}
 
  public int findMaxBottomUp(int[] houseAmount) {
	    // +1 to handle zero house
		int[] dp = new int[houseAmount.length + 2];
	    // if there are no houses, robber can't steal
		dp[houseAmount.length] = 0;

		for (int i = houseAmount.length - 1; i >= 0; i--) {
			dp[i] = Math.max(houseAmount[i] + dp[i + 2],dp[i + 1]);
		}

		return dp[0];
	}

	public static void main(String[] args) {
		System.out.println("**** house robber ****");
		int[] amount1 = {2,7,9,3,1};
		int[] amount2 = {3,11,2,13,1,15};
		int result1,result2 = 0;

		HouseRobber hr = new HouseRobber();
		result1 = hr.findMaxTopDown(amount1);
		System.out.println("house amount1: " + Arrays.toString(amount1) + "\nresult1: " + result1);
		result2 = hr.findMaxBottomUp(amount2);
		System.out.println("house amount2: " + Arrays.toString(amount2) + "\nresult2: " + result2);
	}
}
