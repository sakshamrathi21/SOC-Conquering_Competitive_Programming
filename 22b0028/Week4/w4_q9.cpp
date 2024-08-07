#include<bits/stdc++.h>

using namespace std;


long long days(long long a,long long b,long long k){
    if(a >= k){
        return 1;
    }
    // cout << "a" << a << " b" << b << "\n";
    long long day =  (k - a) / (a - b);
    if( ((day*(a-b) ) +  a) >= k  && (((day - 1)*(a-b) ) +  a) < k){
            return day+1;
        }
    else if((((day+1)*(a-b) ) +  a) >= k  && (((day)*(a-b) ) +  a) < k){
        return day+2;
    }

    return 0;

}
int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int q;
        cin >> q;
        long long start = 0;
        long long end = 0;
        long long currEnd;
        long long currStart;
        stringstream s;
        while(q-- > 0){
            int event;
            cin >> event;
            if(event == 1){
                long long a,b,n;

                cin >> a >> b >> n;

                currStart =   n > 1 ?  a +  ((a-b)* (n-2)) + 1 : 1 ;
                currEnd =  a +  ((a-b)* (n-1)); 

                if(start == 0 && end == 0){
                    start = currStart;
                    end = currEnd;
                    s << "1" << " ";
                }
                else{
                    if((currEnd >= start || currStart <= end)){
                               
                        if(currEnd <= end && currStart >= start){
                            start = currStart;
                            end = currEnd;
                            s << "1" <<" ";

                        }
                        else if(currEnd <= end && currStart <=start && currEnd >= start){
                            end = currEnd;
                            s << "1" <<" ";
                        }
                        else if(currStart >= start && currEnd >= end && currStart <= end){
                            start = currStart;
                            s << "1" <<" ";
                        }
                        else if(currStart <= start && currEnd >= end){
                            s << "1" <<" ";
                        }
                        else{
                            s << "0" <<" ";
                        }
                }
                else{
                    s << "0" <<" ";
                }
            }


            }
            else {
                long long a,b;
                cin >> a >> b;
                if(start != 0 && end != 0){
                    long long dayStart = days(a, b, start);
                    long long dayEnd = days(a, b, end);
                    if(dayStart == dayEnd){
                        s << dayEnd <<" ";
                    }
                    else s << "-1" << " ";
                }
                else{
                   s << "-1" <<" "; 
                }
                

            }
        }
        cout << s.str() << "\n";
    }
}