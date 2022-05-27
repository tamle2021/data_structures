package number_factor;

class Main {
    public static void main(String[] args) {
        System.out.println("**** number factor ****");
        int n1 = 4;
        int n2 = 5;

        NumberFactor nf = new NumberFactor();
        System.out.println("n1 = " + n1 + "\nresult: " + nf.waysToGetNTopDown(4));
        System.out.println("n2 = " + n2 + "\nresult: " + nf.waysToGetNBottomUp(5));
    
    }

}
