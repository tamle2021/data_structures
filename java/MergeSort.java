/*




 **** merge sort ****

 */
import java.util.Arrays;

public class MergeSort {
  static void merge1(int[] A,int left,int middle,int right) {
    int[] leftTmpArray = new int[middle - left + 2];
    int[] rightTmpArray = new int[right - middle + 1];

    for (int i = 0; i <= middle - left; i++) {
      leftTmpArray[i] = A[left + i];
    }
    for (int i = 0; i < right - middle; i++) {
      rightTmpArray[i] = A[middle + 1 + i];
    }

    leftTmpArray[middle - left + 1] = Integer.MAX_VALUE;
    rightTmpArray[right - middle] = Integer.MAX_VALUE;

    int i = 0,j = 0;
    for (int k = left; k <= right; k++) {
      if (leftTmpArray[i] < rightTmpArray[j]) {
        A[k] = leftTmpArray[i];
        i++;
      }
      else {
        A[k] = rightTmpArray[j];
        j++;
      }
    }
  }

  public static void beginRecurse(int[] Array,int left,int right) {
    if (right > left) {
      int m = (left + right) / 2;
      // recursively call on smaller sections of array and build back up
      beginRecurse(Array,left,m);
      beginRecurse(Array,m + 1,right);
      merge1(Array,left,m,right);
    }
  }

  public static void printArr(int []array) {
    for (int i = 0; i < array.length; i++) {
      System.out.print(array[i] + " ");
    }
  }

  public static void main(String[] args) {
    System.out.println("**** merge sort ****");
    int[] arr = {9,7,25,0,14,71,5,-18,20};

    System.out.println("before sort: " + Arrays.toString(arr));
    MergeSort ms = new MergeSort();
    ms.beginRecurse(arr,0,arr.length - 1);
    System.out.println("after sort: " + Arrays.toString(arr));
  }
}
