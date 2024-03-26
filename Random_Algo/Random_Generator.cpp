#include <bits/stdc++.h>
using namespace std;

class RandomImp {
public:
    int random01Generator() {
        return rand() % 2;
    }
 
    // function will use the above
    // method and return numbers 
    // between 0 and 6 inclusive.
    void random06Generator() {
        int val = 7;
        while (val >= 7) {
            string res = "";
            for (int i = 0; i < 3; i++) {
                res += to_string(random01Generator());
            }
            bitset<3> bits(res);
            val = bits.to_ulong();
        }
        cout << val << endl;
    }
};
 
// Driver Code
int main() {
    srand(time(0));
    RandomImp r;
    r.random06Generator();
    return 0;
}