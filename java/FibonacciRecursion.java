/*





**** fibonacci recursion ****

 */
public class FibonacciRecursion {
    public static void main(String[] args) {
        System.out.println("**** fibonacci recursion ****");
        System.out.println("*** starting from 1 ***");
        int num1 = 3;
        int num2 = 6;
        int num3 = 1;
        int num4 = 2;

        FibonacciRecursion fr = new FibonacciRecursion();
        var result1 = fr.beginRecurse(num1);
        var result2 = fr.beginRecurse(num2);
        var result3 = fr.beginRecurse(num3);
        var result4 = fr.beginRecurse(num4);
        System.out.println("fib num1: " + num1 + "\nresult1: " + result1);
        System.out.println("fib num2: " + num2 + "\nresult2: " + result2);
        System.out.println("fib num3: " + num3 + "\nresult3: " + result3);
        System.out.println("fib num4: " + num4 + "\nresult4: " + result4);
    }

    public int beginRecurse(int n) {
        if (n < 0) {
            return -1;
        }
        if (n == 0 || n == 1) {
            return n;
        }

        return beginRecurse(n - 1) + beginRecurse(n - 2);
    }
}
