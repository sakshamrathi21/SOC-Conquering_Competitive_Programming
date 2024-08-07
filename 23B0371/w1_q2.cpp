#include <iostream>
#include <string>
using namespace std;

int main() {
    string dna;
    cin >> dna;
    
    int maxrepeat = 0, currentrepeat = 1;
    
    
    for (int i = 1; i < dna.size(); i++) {
        if (dna[i] == dna[i-1]) {
            
            currentrepeat++;
        } else {
           
            maxrepeat = max(maxrepeat, currentrepeat);
            currentrepeat = 1; 
        }
    }
    
    maxrepeat = max(maxrepeat, currentrepeat);
    
    cout << maxrepeat << endl;
    
    return 0;
}