package binary_heap;

public class Main {
    public static void main(String[] args) {
        System.out.println("**** binary heap ****");
        BinaryHeap bh = new BinaryHeap(5);
        bh.insert(11,"min");
        bh.insert(6,"min");
        bh.insert(17,"min");
        bh.insert(3,"min");

        bh.levelOrder();
        System.out.println("extract head of heap: ");
        bh.extractHeadOfHeap2("min");
        bh.levelOrder();

        bh.deleteHeap();

    }
}
