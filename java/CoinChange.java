/*
One is given an integer array coins representing coins of different denominations and an integer amount representing total amount
of money.  Return the fewest number of coins that is needed to make up that amount.  If that amount of money cannot be made up by
any combination of coins, return -1.  One may assume that there are infinite numbers of each coin.

# example 1
input:
coins = [1,2,5], amount = 11

output:
3

explanation:
11 = 5 + 5 + 1

# example 2
input:
coins = [2], amount = 3

output:
-1

constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4



**** coin change ****

 */
import java.util.Arrays;

public class CoinChange {
  static int begin(int[] coins,int n) {
    Arrays.sort(coins);
    int index = coins.length - 1;
    int numCoins = 0;

    while (true) {
      int coinValue = coins[index];
      index--;
      // non-integers will be zero
      int maxAmount = (n / coinValue) * coinValue;

      if (maxAmount > 0) {
        System.out.println("coin value: " + coinValue + ", taken count: " + (n / coinValue));
        numCoins += (n / coinValue);
        n = n - maxAmount;
      }

      if (n == 0)
        break;
      else if (index == -1)
        return -1;
    }

    return numCoins;
  }

  public static void main(String[] args) {
    System.out.println("**** coin change ****");
    int[] coins1 = {1,2,5,10,12};
    int amount1 = 25;
    int numCoins1, numCoins2 = 0;

    int[] coins2 = {1,3,7,13,17};
    int amount2 = 41;

    CoinChange c = new CoinChange();
    System.out.println("coins1: " + Arrays.toString(coins1) + "\namount1: " + amount1);
    numCoins1 = c.begin(coins1,amount1);
    System.out.println("minimum coins1: " + numCoins1);

    System.out.println("\ncoins2: " + Arrays.toString(coins2) + "\namount2: " + amount2);
    numCoins2 = c.begin(coins2,amount2);
    System.out.println("minimum coins2: " + numCoins2);
  }
}
