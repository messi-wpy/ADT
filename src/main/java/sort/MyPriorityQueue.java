package sort;

public class MyPriorityQueue <key extends Comparable<key>>{
    private key[] array;
    private int n=0;
    private int SIZE=100;
    public MyPriorityQueue(){
        array = (key[]) new Comparable[SIZE+1];
    }
    public MyPriorityQueue(int max){
        array = (key[]) new Comparable[max+1];
        SIZE=max;
    }

    public int length(){
        return n;
    }
    public boolean isEmpty(){
        return n==0;
    }

    public void insert(key v){
        if (n+1>SIZE){
            throw new ArrayIndexOutOfBoundsException("超过最大值");
        }
        array[++n]=v;
        swim(n-1);
    }
    public key delMax(){
        key v=array[1];
        Example.exch(array,1,n--);
        sink(1);
        return v;

    }


    /**
     * 堆算法的上浮
     * 前提是已有序,某个子节点比父节点大而打破了顺序
     * k/2--->父节点
     */
    private void swim(int k){
        while ( k>1 && Example.less(array[k/2],array[k])){
            Example.exch(array,k,k/2);
            k=k/2;
        }

    }

    /**
     * 堆的下沉算法
     * 2k  2k+1---> 左右子节点
     */
    private void sink(int start){
        while (2*start<=n){
            int j=2*start;
            if (j<n &&Example.less(array[j],array[j+1])){
                j=j+1;
            }
            if (!Example.less(array[start],array[j])){
                break;
            }
            Example.exch(array,j,start);
            start=j;
        }
    }

}
