import java.util.*;
public class Q2 {
    public static int reps(String str){
        int max = 1;
        int currMax = 1;
        for(int i=0;i<str.length()-1;i++){
            while(i<str.length()-1 && str.charAt(i) == str.charAt(i+1)){
                currMax += 1;
                i++;
            }
            
            max = Math.max(max, currMax);
            currMax = 1;
        }
        return max;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println(reps(str));
        sc.close();
    }
}
