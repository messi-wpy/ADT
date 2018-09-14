import java.util.Scanner;

//f(0)=0,f(1)=1

public class Dynamic {
    //备忘录自顶向下
    public static int Fibonacci(int n){
        int []memo=new int[n+1];
        for (int i=0;i<=n;i++){
            memo[i]=-1;
        }
        return fib(n,memo);
    }

    private static int fib(int n, int[] memo) {
        if (memo[n]!=-1){
            return memo[n];
        }
        if (n<=2)
            memo[n]=1;
        else
            memo[n]=fib(n-1,memo)+fib(n-2,memo);
        return memo[n];
    }
//自底向上
    public static int f(int n){
        if(n<=1)
            return n;
        int a=0,b=1,c=0;
        for (int i=2; i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return  c;
    }

    //钢条切割
    public static int memoCut(int []p){
        int []r=new int[p.length+1];
        for (int i=0;i<p.length+1;i++){
            r[i]=-1;
        }
        return cut(p,p.length,r);

    }

    private static int cut(int[] p, int n, int[] r) {
        int q=-1;
        if (r[n]>=0)
            return r[n];
        if (n==0)
            return 0;
        else {
            for (int i=1;i<=n;i++)
                q=Math.max(q,cut(p,n-i,r)+p[i-1]);
        }
        r[n]=q;
        return q;
    }

    public static void main(String []orgs){
        Scanner s=new Scanner(System.in);
        int n;
        n=s.nextInt();
        System.out.print(Fibonacci(n)+"  "+f(n));
    }


}
