import java.util.Arrays;

public class PrimarySorting {

    /**
     * 冒泡排序 O(N^2)
     * 简单，效率不高
     * @param array
     */
    public void bubbleSort(Comparable[] array){
        boolean hasSorted=false;
        for (int i = 0; i <array.length ; i++) {
            hasSorted=true;
            for (int j = 0; j <array.length-i-1 ; j++) {
                if (Example.less(array[j+1],array[j])){
                    Example.exch(array,j+1,j);
                    hasSorted=false;
                }
            }
            if (hasSorted)
                return;
        }
    }

    /**
     * 选择排序O(n^2)
     * 数据移动最少 n次
     */
    public void selectSort(Comparable[]array){
        for (int i = 0; i <array.length ; i++) {
            int min=i;
            for (int j = i+1; j <array.length ; j++) {
                if (Example.less(array[j],array[min])){
                    min=j;
                }
                Example.exch(array,i,min);
            }
        }
    }

    /**
     * 插入排序：对部分有序的数组十分有效
     *
     */
    public void insertSort(Comparable[]nums){
        for (int i = 1; i <nums.length ; i++) {
            for (int j = i; j >0&&Example.less(nums[j],nums[j-1]); j--) {
                Example.exch(nums,j,j-1);
            }
        }

    }

    /**
     * 改进的插入排序
     * 不用交换，直接修改数组
     * @param nums
     */
    public void insertSort2(Comparable[]nums){
        for (int i = 1; i <nums.length ; i++) {
            Comparable temp=nums[i];
            int j=0;
            for ( j = i-1; j >=0&&Example.less(temp,nums[j]) ; j--) {
                nums[j+1]=nums[j];
            }
            nums[j]=temp;
        }

    }
    /**
     * 希尔排序：对插入排序的改进
     * 基本思想：是数组中任意间隔h的元素都是有序的
     * 利用局部有序，分组进行插入排序
     */
    public void shellSort(Comparable[]a){
        int n=a.length;
        int h=0;
        while (h<n/3)
            h=3*h+1;
        while (h>=1){
            for (int i = h; i <n ; i++) {
                for (int j = i; j >=h&&Example.less(a[j],a[j-h]) ; j-=h) {
                    Example.exch(a,j,j-h);
                }
            }
            h=h/3;


        }

    }


}
