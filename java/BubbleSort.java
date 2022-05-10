/*



**** bubble sort ****

 */
import java.util.Arrays;

public class BubbleSort {
    // time complexity: O(n^2)
    public int[] start(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        return arr;
    }

    void printArr(int arr[]) {
        int n = arr.length;
        System.out.print("[");
        for (int i = 0; i < n; i++) {
            if (i == (n - 1))
                System.out.print(arr[i]);
            else
                System.out.print(arr[i] + ", ");
        }
        System.out.print("]");
        System.out.println("");
    }

    public static void main(String[] args) {
        System.out.println("**** bubble sort ****");
        int[] arr1 = {4,9,0,25,92,44,-7,11,3};
        // int[] result1 = {};

        BubbleSort b = new BubbleSort();
        System.out.print("before sort: ");
        b.printArr(arr1);
        b.start(arr1);
        System.out.println("after sort: " + Arrays.toString(arr1));
    }
}
