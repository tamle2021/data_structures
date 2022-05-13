/*
The greedy algorithm could be explained by the knapsack problem.  Given a set of items, each with a weight and a value, determine
a subset of items to include in a collection so that total weight is less than or equal to a given limit and total value is
large as possible.


**** fractional knapsack ****

 */

package knapsack;

import java.util.*;

public class FractionalKnapsack {
  static void start(ArrayList<KnapsackItem> items,int capacity) {
    Comparator<KnapsackItem> comparator = new Comparator<KnapsackItem>() {
      @Override
      public int compare(KnapsackItem o1,KnapsackItem o2) {
        if (o2.getRatio() > o1.getRatio())
          return 1;
        else return -1;
      }
    };

    Collections.sort(items,comparator);
    int usedCapacity = 0;
    double totalValue = 0;

    for (KnapsackItem item : items) {
      if (usedCapacity + item.getWeight() <= capacity) {
        usedCapacity += item.getWeight();
        System.out.println("taken => " + item);
        totalValue += item.getValue();
      }
      // in case item left over puts it over capacity
      else {
        int usedWeight = capacity - usedCapacity;
        double value = item.getRatio() * usedWeight;
        System.out.println("taken => index: " + item.getIndex() + ", value: " + value + ", weight: " + usedWeight + ", ratio: " + item.getRatio());
        usedCapacity += usedWeight;
        totalValue += value;

      }

      if (usedCapacity == capacity)
        break;
    }

    System.out.println("total value: " + totalValue);
  }
}
