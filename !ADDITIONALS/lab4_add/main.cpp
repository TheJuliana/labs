#include <iostream>
#include <vector>
using std::cin;
using std::endl;
using std::cout;

int main() {
    int x = 0;
    int ticket[6];
    for (ticket[5] = 0; ticket[5] < 10; ticket[5]++) {
        for (ticket[4] = 0; ticket[4] < 10; ticket[4]++) {
            for (ticket[3] = 0; ticket[3] < 10; ticket[3]++) {
                for (ticket[2] = 0; ticket[2] < 10; ticket[2]++) {
                    for (ticket[1] = 0; ticket[1] < 10; ticket[1]++) {
                        for (ticket[0] = 0; ticket[0] < 10; ticket[0]++) {
                            if ((ticket[0] + ticket[1] + ticket[2]) == (ticket[3] + ticket[4] + ticket[5])) {
                                x++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << x << endl;
    return 0;
}
