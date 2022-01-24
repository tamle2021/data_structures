/*
Find if array contains duplicate.


**** is unique ****
 */
class IsUnique {
    public static void main(String[] args) {
        IsUnique iu= new IsUnique();
        int[] intArray1 = {4,0,-3,12,54,1,25};
        int[] intArray2 = {3,1,-4,11,55,2,11};

        System.out.println("**** is unique ****");

        System.out.print("array 1: ");
        for (int i = 0; i < intArray1.length; i++)
            System.out.print(intArray1[i] + " ");
        boolean result1 = iu.start(intArray1);
        System.out.println("\nresult 1: " + result1);

        System.out.print("array 2: ");
        for (int i = 0; i < intArray2.length; i++)
            System.out.print(intArray2[i] + " ");
        boolean result2 = iu.start(intArray2);
        System.out.println("\nresult 2: " + result2);
    }

    // does array contains duplicate
    public boolean start(int[] intArray) {
        for (int i  = 0; i < intArray.length; i++) {
            for (int j = i + 1; j < intArray.length; j++) {
                if (intArray[i] == intArray[j]) {
                    return false;
                }
            }
        }

        return true;
    }
}
