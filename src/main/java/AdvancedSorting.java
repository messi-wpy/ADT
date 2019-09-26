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
     * 快速排序
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

}
