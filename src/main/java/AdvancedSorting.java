import java.util.Random;

public class AdvancedSorting {


    /**
     * 归并排序nlog(n)
     * 但需要n的额外储存空间
     * 自顶向下
     * 分治思想
     */
    public void mergeSort(Comparable[]a){
        mergeSortHelp2(a,new Comparable[a.length],0,a.length-1);
    }
    private void mergeSortHelp(Comparable[]a,Comparable[]aux,int lo,int hi){
        if (lo>=hi)return;
        int mid=lo+(hi-lo)/2;
        mergeSortHelp(a,aux,lo,mid);
        mergeSortHelp(a,aux,mid+1,hi);
        merge(a,aux,lo,mid,hi);

    }

    private void merge(Comparable[]nums,Comparable[] aux,int lo,int mid,int hi){
        for (int i = lo; i <=hi ; i++) {
            aux[i]=nums[i];
        }
        int a,b;
        a=lo;
        b=mid+1;
        for (int i = lo; i <=hi ; i++) {
            if (a>mid)
                nums[i]=aux[b++];
            else if (b>hi)
                nums[i]=aux[a++];
            else if (Example.less(aux[a],aux[b]))
                nums[i]=aux[a++];
            else
                nums[i]=aux[b++];
        }
    }

    /**
     * merge改进
     * 当mid<=mid+1时就已有序
     */
    private void mergeSortHelp2(Comparable[]a,Comparable[]aux,int lo,int hi){
        if (lo>=hi)return;
        int mid=lo+(hi-lo)/2;
        mergeSortHelp(a,aux,lo,mid);
        mergeSortHelp(a,aux,mid+1,hi);
        if (Example.less(a[mid],a[mid+1]))
            return;
        merge(a,aux,lo,mid,hi);

    }

    /**
     * 自底向上的归并排序
     * @param a
     */
    public void mergeSort2(Comparable[]a){
        int n=a.length;
        Comparable[]aux=new Comparable[n];
        for (int size=1;size<n;size=size+size ) {
            for (int lo = 0; lo < n - size; lo+=size+size) {
                merge(a,aux,lo,lo+size-1,Math.min(lo+size+size-1,n-1));
            }
        }
    }

    /**
     * 快速排序nlog(n)
     * 比较次数少
     * 但是如果每次分割都是第一小，然后第二小...这样每次只从大数组中分割出一个，就会造成快拍效率
     * 极低，所以再输入前可以先将数组随机排序---偏爱随机性算法
     *
     */
    public void quickSort(Comparable[]a){
        quickSortHelp(a,0,a.length-1);

    }

    private void quickSortHelp(Comparable[]a,int lo,int hi){
        if (lo>=hi)return;
        int p=partition(a,lo,hi);
        quickSortHelp(a,lo,p-1);
        quickSortHelp(a,p+1,hi);
    }
    private int partition(Comparable[]a,int lo,int hi){
        int i=lo,j=hi;
        Comparable temp=a[i];
        while (lo<hi){
            while (lo<hi&&Example.less(temp,a[hi]))hi--;
            if (lo<hi){
                a[lo++]=a[hi];
            }
            while (lo<hi&&Example.less(a[lo],temp))lo++;
            if (lo<hi){
                a[hi--]=a[lo];
            }
        }
        a[lo]=temp;
        return lo;
    }


    /**
     * 堆排序
     * (大顶堆)
     * @param a:
     * 分两部分
     * 从下往上建立堆
     * 从上往下筛选
     * n/2是完全二叉树的最后一个根节点
     */
    public void heapSort(Comparable[]a){
        int n=a.length;
        for (int i = n/2; i >=0 ; i--) {
            sink(a,i,n);
        }
        for (int i = a.length-1; i >=0 ; i--) {
            Example.exch(a,0,i);
            sink(a,0,i);
        }

    }

    //下标从0开始
    private void sink(Comparable[]a,int start,int n){
        while (start*2+1<n){
            int j=start*2+1;
            if (j+1<n && Example.less(a[j],a[j+1]))
                j++;
            if (!Example.less(a[start],a[j]))
                break;
            Example.exch(a,j,start);
            start=j;

        }
    }

    private void swim(Comparable[]a,int k,int n){
        while (k/2>1){
            if (Example.less(a[k/2],a[k])) {
                Example.exch(a, k / 2, k);
                k=k/2;
            }
            else
                break;

        }

    }
}
