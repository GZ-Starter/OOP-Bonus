#include <iostream>
using namespace std;
int main() {
    int num;
    cout<<"Enter a 3-digit number: ";
    cin >> num;

    if (num < 100 || num > 999) {
        cout << "Please enter a 3-digit number." << endl;
        return 1;
    }
    int digit1 = num / 100;
    int digit2 = (num / 10) % 10;
    int digit3 = num % 10;

    cout << "All possible combinations of " << num << " are:" << endl;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            for (int k = 1; k <= 2; k++) {
                cout << digit1 << digit2 << digit3 << " ";
                swap(digit2, digit3);
            }
            swap(digit1, digit2);
            if(i==2)
            break;
        }
        swap(digit1, digit3);
    }

    return 0;
}
