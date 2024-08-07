import java.util.*;
public class Q3 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int testcases = sc.nextInt();
        for(int i=0;i<testcases;i++){
            long n = sc.nextLong();
            long k = sc.nextLong();
            if(n%2 == 0){
                System.out.println("YES");
            }
            else{
                if(k%2 == 0){
                    System.out.println("NO");
                }
                else{
                    System.out.println("YES");
                }
            }

        }
        sc.close();
    }
}
