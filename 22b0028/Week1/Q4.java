import java.util.*;
public class Q4{
    public static int DiffbtwDigits(int num){
        int currDiff = 0;
        int minValue = Integer.MAX_VALUE;
            int maxValue = Integer.MIN_VALUE;
            while(num>0){
                if(num % 10 <= minValue){
                    minValue =  num%10;
                }
                if(num % 10 >= maxValue){
                    maxValue = num % 10;
                }
                num = num/10;

            }
            
            currDiff = maxValue - minValue;
            return currDiff;

    }
    public static int luckyNum(int start,int end){
        int j;
        int maxDiff = 0;
        int currDiff = 0;
        int luckNum = 0; 
        for( j=start;j<=Math.min(end,start+100);j++){
            currDiff = DiffbtwDigits(j);
            if(currDiff>=maxDiff){
                maxDiff = currDiff;
                luckNum = j;
            }
        }

        return luckNum;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        Integer testcases = sc.nextInt();
        for(int i=0;i<testcases;i++){
            int start = sc.nextInt();
            int end = sc.nextInt();
            System.out.println(luckyNum(start,end));
        }
        sc.close();


    }
}