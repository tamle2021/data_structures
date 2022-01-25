/*
Find if two arrays are permutations of each other.  Permutation is an arrangement where ordering matters and has same
number and value of elements.


**** permutation ****

 */
class Permutation {
    public static void main(String[] args) {
        Permutation p = new Permutation();
        int[] array1 = {4,9,11,-7,21,0};
        int[] array2 = {5,4,3,2,1,0};
        int[] array3 = {13,15,17,19};
        int[] array4 = {19,17,15,13};

        System.out.println("**** permutation ****");

        System.out.print("array 1: ");
        for (int i = 0; i < array1.length; i++)
            System.out.print(array1[i] + " ");
        System.out.print("\narray 2: ");
        for (int i = 0; i < array2.length; i++)
            System.out.print(array2[i] + " ");

        boolean result1 = p.begin(array1,array2);
        System.out.println("\nresult 1: " + result1 + "\n");

        System.out.print("array 3: ");
        for (int i = 0; i < array3.length; i++)
            System.out.print(array3[i] + " ");
        System.out.print("\narray 4: ");
        for (int i = 0; i < array4.length; i++)
            System.out.print(array4[i] + " ");

        boolean result2 = p.begin(array3,array4);
        System.out.println("\nresult 2: " + result2);
    }

    public boolean begin(int[] array1,int[] array2) {
        if (array1.length != array2.length ) {
            return false;
        }
        int sum1 = 0;
        int sum2 = 0;
        int mul1 = 1;
        int mul2 = 1;

        for (int i = 0; i < array1.length; i++) {
            sum1 += array1[i];
            sum2 += array2[i];
            mul1 *= array1[i];
            mul2 *= array2[i];
        }

        if (sum1 == sum2 && mul1 == mul2) {
            return true;
        }

        return false;
    }
}