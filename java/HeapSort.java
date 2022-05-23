/*




**** heap sort ****

 */
import binary_heap.BinaryHeap;
import java.util.Arrays;

public class HeapSort {
    int[] arr = null;

    public HeapSort(int[] arr) {
        this.arr = arr;
    }

    public void sort() {
        BinaryHeap bh = new BinaryHeap(arr.length);
        for (int i = 0 ; i < arr.length; i++) {
            bh.insertHeap(arr[i]);
        }

        for (int i = 0; i < arr.length; i++) {
            arr[i] = bh.extractHeadOfHeap();
        }
    }

    public void printArray() {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+"  ");
        }
    }

    public static void main(String[] args) {
        System.out.println("**** heap sort ****");
        int[] arr = {4,9,0,22,-7,45,67,31};

        System.out.println("before sort: " + Arrays.toString(arr));
        HeapSort hs = new HeapSort(arr);
        hs.sort();
        System.out.println("after sort: " + Arrays.toString(arr));

    }

}
