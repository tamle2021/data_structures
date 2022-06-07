package double_hashing;

class Main {
  public static void main(String[] args) {
	  System.out.println("**** double hashing ****");
	  DoubleHashing dh = new DoubleHashing(17);
      dh.insertKeyHashTable("The");
	  dh.insertKeyHashTable("slow");
	  dh.insertKeyHashTable("green");
	  dh.insertKeyHashTable("turtle");
	  dh.insertKeyHashTable("crawls");
	  dh.insertKeyHashTable("under");
	  dh.insertKeyHashTable("lazy");
	  dh.insertKeyHashTable("white");
	  dh.insertKeyHashTable("rabbit.");
	  dh.displayHashTable();
  }
}