/*





**** double hashing ****

 */
package double_hashing;

import java.util.ArrayList;

public class DoubleHashing {
	String[] hashTable;
	int numCellsUsedHashTable;

	// constructor
	DoubleHashing(int size) {
		hashTable = new String[size];
		numCellsUsedHashTable = 0;
	}

	public int simpleASCIIHashFn(String x,int M) {
		char ch[];
		ch = x.toCharArray();
		int i,sum;

        for (sum = 0, i = 0; i < x.length(); i++) {
			sum = sum + ch[i];
		}

		return sum % M;
	}

    // creates hash table and re-hash
	public void rehashKey(String string1) {
		numCellsUsedHashTable = 0;
		ArrayList<String> data = new ArrayList<String>();

        for (String s : hashTable) {
			if (s != null)
				data.add(s);
		}

        data.add(string1);
		hashTable = new String[hashTable.length * 2]; 
		for (String s : data) { 
			insertKeyHashTable(s);
		}
	}

    public void displayHashTable() {
        if (hashTable == null) {
            System.out.println("hash table does not exist....");
            return;
        }
        else {
            System.out.println("\n---------- hash table ---------");
            for (int i = 0; i < hashTable.length; i++) {
                System.out.println("index: " + i + " --- key: " + hashTable[i]);
            }
        }

        System.out.println(" ");
    }

    private int addDigitsTogether(int sum) {
      int value = 0;
      while (sum > 0) {
        value = sum % 10;
        sum = sum / 10;
      }

      return value;
    }

    public int secondHashFn(String x,int M) {
        char ch[];
        ch = x.toCharArray();
        int i,sum;

        for (sum = 0,i = 0; i < x.length(); i++) {
            sum += ch[i];
        }

        while (sum > hashTable.length) {
            sum = addDigitsTogether(sum);
        }

        return sum % M;
    }

    public double getLoadFactor() {
        return numCellsUsedHashTable * 1.0 / hashTable.length;
    }

    public void insertKeyHashTable(String value) {
        double loadFactor = getLoadFactor();

        if (loadFactor >= 0.75) {
            rehashKey(value);
        }
        else {
            int x = simpleASCIIHashFn(value,hashTable.length);
            int y = secondHashFn(value,hashTable.length);

            for (int i = 0; i < hashTable.length; i++) {
                int newIndex = (x + i * y) % hashTable.length;

                if (hashTable[newIndex] == null) {
                    hashTable[newIndex] = value;
                    System.out.println('"' + value + '"' + " inserted at location: " + newIndex);
                    break;
                }
                else {
                    System.out.println("index " + newIndex + " is occupied --- trying next empty....");
                }
      }
    }

    numCellsUsedHashTable++;
  }
}
