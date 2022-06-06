/*
Find the sum of digits in a number.

# example 1
input:
416

output:
11

explanation:
The sum of each individual number is 4 + 1 + 6 = 11.




**** sum of digits ****

 */
import java.util.Arrays;

public class SumOfDigits {
    public static void main(String[] args) {
        System.out.println("**** sum of digits ****");
        SumOfDigits q1 = new SumOfDigits();
        int num1 = 213;
        int num2 = 461122;

        System.out.println("num1: " + num1);
        int result1 = q1.startRecurse(num1);
        System.out.println("result1: " + result1);

        System.out.println("num2: " + num2);
        int result2 = q1.startRecurse(num2);
        System.out.println("result2: " + result2);
    }

    public int startRecurse(int n) {
        if (n == 0 || n < 0) {
            return 0;
        }

        return n % 10 + startRecurse(n / 10);
    }
}
