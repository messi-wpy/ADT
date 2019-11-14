package sort;

public class Example {


    public static void main(String[] args) {
        Comparable[]test={8,6,45,4,7,1,45,44,8,5,10,18,77,3};
        PrimarySorting primary=new PrimarySorting();
        AdvancedSorting advanced=new AdvancedSorting();
        advanced.heapSort(test);
        System.out.println(isSorted(test));
        show(test);

    }


    static boolean less(Comparable a,Comparable b){
        return a.compareTo(b)<0;
    }
     static void exch(Comparable[]a,int i,int j){
        Comparable temp=a[i];
        a[i]=a[j];
        a[j]=temp;

    }
    static void show(Comparable[]a){
        for (Comparable comparable : a) {
            System.out.println(comparable);
        }
    }
    static boolean isSorted(Comparable[]a){
        for (int i = 1; i <a.length ; i++) {
            if (less(a[i],a[i-1]))
                return false;
        }
        return true;
    }

}
