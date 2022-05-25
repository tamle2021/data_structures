/*




 **** insertion sort ****

 */
import java.util.Arrays;

public class InsertionSort {
    static void begin(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int temp = arr[i];
            int j = i;
            // shifting elements to right
            while (j > 0 && arr[j - 1] > temp) {
                arr[j] = arr[j - 1];
                j--;
            }

            arr[j] = temp;
        }
    }

    public static void printArr(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        System.out.println("**** insertion sort ****");
        int[] arr = {9,11,14,0,91,-8,25,2,73,44};

        System.out.println("before sort: " + Arrays.toString(arr));
        InsertionSort is = new InsertionSort();
        is.begin(arr);
        System.out.println("after sort: " + Arrays.toString(arr));
    }
}
