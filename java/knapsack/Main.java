package knapsack;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        System.out.println("**** fractional knapsack ****");
        ArrayList<KnapsackItem> items = new ArrayList<>();
        int[] value = {95,104,40,25,8};
        int[] weight = {24,30,44,5,11};
        int capacity = 105;

        for (int i = 0; i < weight.length; i++) {
            items.add(new KnapsackItem(i + 1,value[i],weight[i]));
        }

        FractionalKnapsack.start(items,capacity);
    }
}
