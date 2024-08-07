import java.util.*;
public class Q1{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int nums[] = new int[n-1];
        for(int i=0;i<n-1;i++){
            nums[i] = sc.nextInt();
        }
        long  sumN = (long)n*(n+1)/2;
        long  sum = 0;
        for(int j=0;j<n-1;j++){
            sum += nums[j];
        }
        System.out.println(sumN - sum);
        sc.close();
    }
}