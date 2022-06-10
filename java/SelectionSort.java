/*





**** selection sort ****

 */
import java.util.Arrays;

public class SelectionSort {
    static void start(int[] arr) {
        for (int j = 0; j < arr.length; j++) {
            int minimumIndex = j;
            for (int i = j + 1; i < arr.length; i++) {
                if (arr[i] < arr[minimumIndex]) {
                    minimumIndex = i;
                }
            }

            if (minimumIndex != j) {
                int temp = arr[j];
                arr[j] = arr[minimumIndex];
                arr[minimumIndex] = temp;
            }
        }
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        System.out.println("**** selection sort ****");
        int arr[] = {22,51,0,94,71,-11,13,17,39};

        System.out.println("before sort: " + Arrays.toString(arr));
        SelectionSort ss = new SelectionSort();
        ss.start(arr);
        System.out.println("after sort: " + Arrays.toString(arr));
    }
}