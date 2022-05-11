/*




**** bucket sort ****

 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class BucketSort {
    int arr[];

    public BucketSort(int arr[]) {
        this.arr = arr;
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

        System.out.println("]");
    }

    public void printBucket(ArrayList<Integer>[] buckets) {
        for (int i = 0; i < buckets.length; i++) {
            System.out.print("\nbucket #" + i + ": ");

            for (int j = 0 ; j < buckets[i].size(); j++) {
                System.out.print(buckets[i].get(j) + " ");
            }
        }

        System.out.println("");
    }

    public void start() {
        int numberOfBuckets = (int)Math.ceil(Math.sqrt(arr.length));
        int maxValue = Integer.MIN_VALUE;

        for (int value : arr) {
            if (value > maxValue) {
                maxValue = value;
            }
        }

        // initialize buckets of arrays
        ArrayList<Integer>[] buckets = new ArrayList[numberOfBuckets];
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new ArrayList<Integer>();
        }

        for (int value: arr) {
            // int bucketNumber = (int)Math.ceil(((int)value * numberOfBuckets) / (int)maxValue);
            int bucketNumber = (int)(value * numberOfBuckets) / (int)maxValue;

            // System.out.print(buckets.length);
            if (bucketNumber == buckets.length)
                bucketNumber--;

            buckets[bucketNumber].add(value);
        }

        System.out.print("buckets before sorting: ");
        printBucket(buckets);

        for (ArrayList<Integer> bucket: buckets) {
            Collections.sort(bucket);
        }

        System.out.print("buckets after sorting: ");
        printBucket(buckets);

        // rewrite array based on ascending buckets
        int index = 0;
        for (ArrayList<Integer> bucket: buckets) {
            for (int value : bucket) {
                arr[index] = value;
                index++;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("**** bucket sort ****");
        int[] arr1 = {125,92,0,-3,27,87,41,34,21,101};

        System.out.println("before sort: " + Arrays.toString(arr1));
        BucketSort b = new BucketSort(arr1);
        b.start();

        System.out.print("after sort: ");
        b.printArr(arr1);
    }
}
