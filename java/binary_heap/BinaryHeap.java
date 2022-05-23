/*




 **** binary heap ****

 */
package binary_heap;

public class BinaryHeap {
	int[] arr;
	int sizeOfTree;

	// constructor
	public BinaryHeap(int size) {
		// add 1 so that first cell of array can be left blank
		arr = new int[size + 1];
		this.sizeOfTree = 0;

		System.out.println("heap created....");
	}

	public int sizeOfArray() {
		return arr.length;
	}

	public int sizeOfTree() {
		System.out.println("size of tree: " + sizeOfTree);
		return sizeOfTree;
	}

	public boolean isHeapEmpty() {
		if (sizeOfTree <= 0) {
			System.out.println("tree empty....");
			return true;
		}
		else {
			System.out.println("tree not empty....");
			return false;
		}
	}

	public void deleteHeap() {
		arr = null;
		System.out.println("heap deleted....");
	}

	// insert new value in heap
	public void insertHeap(int value) {
		// +1 because size of tree points to last occupied cell of array
		System.out.println("inserting " + value + " in Heap...");
		arr[sizeOfTree + 1] = value;
		sizeOfTree++;
		heapifyBottomToTop(sizeOfTree);
		System.out.println("inserted " + value + " successfully in heap....");

		// levelOrder();
	}

	// peek the heap
	public void peek() {
		if (sizeOfTree == 0) {
			System.out.println("heap empty....");
		}
		else {
			System.out.println("head of heap: " + arr[1]);
		}
	}

	public int extractHeadOfHeap() {
		if (sizeOfTree == 0) {
			System.out.println("heap empty....");
			return -1;
		}
		else {
			System.out.println("head of heap: " + arr[1]);
			int extractedValue = arr[1];
			arr[1] = arr[sizeOfTree];
			sizeOfTree--;

			heapifyTopToBottom(1);

			System.out.println("successfully extracted value from heap....");
			// levelOrder();

			return extractedValue;
		}
	}

	public int extractHeadOfHeap2(String heapType) {
		if (isHeapEmpty()) {
			return -1;
		}
		else {
			int extractedValue = arr[1];
			arr[1] = arr[sizeOfTree];

			sizeOfTree--;
			heapifyTopToBottom2(1,heapType);

			return extractedValue;
		}
	}

	public void heapifyBottomToTop(int index) {
		int parent = index / 2;
		// root of tree and no heapifying is required
		if (index <= 1) {
			return;
		}
		// swap if current value is smaller than its parent
		if (arr[index] < arr[parent]) {
			int temp = arr[index];
			arr[index] = arr[parent];
			arr[parent] = temp;
		}

		heapifyBottomToTop(parent);
	}

	public void heapifyTopToBottom(int index) {
		int left  = index * 2;
		int right = (index * 2) + 1;
		int smallestChild = 0;

		// node has no child
		if (sizeOfTree < left) {
			return;
		}
		else if (sizeOfTree == left) {
			if (arr[index] > arr[left]) {
				int temp = arr[index];
				arr[index] = arr[left];
				arr[left] = temp;
			}

			return;
		}
		else {
			// both children are present
			if(arr[left] < arr[right]) {
				// find smallest child
				smallestChild = left;
			}
			else {
				smallestChild = right;
			}

			// swap if parent is greater than smallest child
			if (arr[index] > arr[smallestChild]) {
				int temp = arr[index];
				arr[index] = arr[smallestChild];
				arr[smallestChild] = temp;
			}
		}

		heapifyTopToBottom(smallestChild);
	}

	public void heapifyTopToBottom2(int index,String heapType) {
		int left = index * 2;
		int right = (index * 2) + 1;
		int swapChild = 0;

		// current node has no child
		if (sizeOfTree < left) {
			return;
		}

		if (heapType == "max") {
			// only left child of node
			if (sizeOfTree == left) {
				if (arr[index] < arr[left]) {
					int temp = arr[index];
					arr[index] = arr[left];
					arr[left] = temp;
				}

				return;
			}
			else {
				// both children are present
				if (arr[left] > arr[right]) {
					swapChild = left;
				}
				else {
					swapChild = right;
				}

				if (arr[index] < arr[swapChild]) {
					int temp = arr[index];
					arr[index] = arr[swapChild];
					arr[swapChild] = temp;
				}
			}
		}
		else if (heapType == "min") {
			// only left child of node
			if (sizeOfTree == left) {
				if (arr[index] > arr[left]) {
					int temp = arr[index];
					arr[index] = arr[left];
					arr[left] = temp;
				}

				return;
			}
			else {
				// both children are present
				if (arr[left] < arr[right]) {
					swapChild = left;
				}
				else {
					swapChild = right;
				}

				if (arr[index] > arr[swapChild]) {
					int temp = arr[index];
					arr[index] = arr[swapChild];
					arr[swapChild] = temp;
				}
			}
		}

		heapifyTopToBottom2(swapChild,heapType);
	}

	public void heapifyBottomToTop2(int index,String heapType) {
		int parent = index / 2;
		// root of tree and no heapifying is required
		if (index <= 1) {
			return;
		}

		if (heapType == "min") {
			if (arr[index] < arr[parent]) {
				int temp = arr[index];
				arr[index] = arr[parent];
				arr[parent] = temp;
			}
		}
		else if (heapType == "max") {
			if (arr[index] > arr[parent]) {
				int temp = arr[index];
				arr[index] = arr[parent];
				arr[parent] = temp;
			}
		}

		heapifyBottomToTop2(parent,heapType);
	}

	public void levelOrder() {
		// printing from 1 because 0th cell is dummy
		System.out.println("level-order traversal: ");
		for (int i = 1; i <= sizeOfTree; i++) {
			System.out.print(arr[i] + " ");
		}

		System.out.println("\n");
	}

	public void insert(int value,String heapType) {
		arr[sizeOfTree + 1] = value;
		sizeOfTree++;
		heapifyBottomToTop2(sizeOfTree,heapType);

		System.out.println("insert " + value + " successfully in heap....");
	}
}