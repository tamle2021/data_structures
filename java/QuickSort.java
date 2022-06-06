/*





**** quick sort ****

 */
import java.util.Arrays;

public class QuickSort {
  // get pivot point
  static int partition(int[] array,int start,int end) {
    int pivot = end;
    int i = start - 1;
    for (int j = start; j <= end; j++) {
      if (array[j] <= array[pivot]) {
        i++;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }

    return i;
  }

  public static void beginRecurse(int[] array,int start,int end) {
    if (start < end) {
      int pivot = partition(array,start,end);
      beginRecurse(array,start,pivot - 1);
      beginRecurse(array,pivot + 1,end);
    }
  }

  public static void printArray(int[] array) {
      for (int i = 0; i < array.length; i++) {
          System.out.print(array[i] + " ");
      }
  }

  public static void main(String[] args) {
      System.out.println("**** quick sort ****");
      QuickSort qs = new QuickSort();
      int arr[] = {4,25,0,37,44,-11,19,89,7,9};

      System.out.println("before sort: " + Arrays.toString(arr));
      qs.beginRecurse(arr,0,arr.length - 1);
      System.out.println("after sort: " + Arrays.toString(arr));
  }
}
