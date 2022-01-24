class MaxProduct {
    public static void main(String[] args) {
        MaxProduct mp = new MaxProduct();
        int[] intArray = {0,5,21,-7,64,30,43,52,3,72};

        System.out.println("**** max product ****");

        System.out.print("array: ");
        for (int i = 0; i < intArray.length; i++ )
            System.out.print(intArray[i] + " ");
        System.out.println("");

        String pairs = mp.start(intArray);
        System.out.println(pairs);
    }

    // find max product
    public String start(int[] intArray) {
        int maxProduct = 0;
        String pairs = "";

        for (int i = 0; i < intArray.length; i++) {
            for (int j = i + 1; j < intArray.length; j++) {
                if (intArray[i] * intArray[j] > maxProduct) {
                    maxProduct = intArray[i] * intArray[j];
                    pairs = "result: " + Integer.toString(intArray[i]) + " " + Integer.toString(intArray[j]);
                }
            }
        }

        return pairs;
    }
}


