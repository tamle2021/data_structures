/*
Recursion is the process of defining a problem or solution to a problem in terms of a simpler version of itself.




 **** factorial recursion ****

 */
public class FactorialRecursion {
    public static void main(String[] args) {
        System.out.println("**** factorial recursion ****");
        FactorialRecursion fr = new FactorialRecursion();
        int num1 = 4;
        int num2 = 5;

        var result1 = fr.start(num1);
        var result2 = fr.start(num2);

        System.out.println("num1: " + num1 + "\nresult1: " + result1);
        System.out.println("num2: " + num2 + "\nresult2: " + result2);
    }

    public int start(int n) {
        if (n < 1) {
            return -1;
        }
        if (n == 0 || n == 1) {
            return 1;
        }

        return n * start(n - 1);
    }
}
