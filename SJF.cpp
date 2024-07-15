#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter no. of processes: ";
    cin >> n;
    vector<int> Arr(n), BT(n);

    cout << "Arrival times:\n";
    for (int i = 0; i < n; i++) {
        cin >> Arr[i];
    }

    cout << "Burst times:\n";
    for (int i = 0; i < n; i++) {
        cin >> BT[i];
    }

    vector<int> Bt(n), Ct(n);
    for (int i = 0; i < n; i++) {
        Bt[i] = BT[i];
    }

    int count = 0, j = 0;
    while (j < n) {
        int min = 1000, ind = -1;
        for (int i = 0; i < n; i++) {
            if (Bt[i] == min) {
                if (Arr[i] < Arr[ind]) {
                    ind = i;
                }
            } else if (Bt[i] < min) {
                if (Arr[i] <= count) {
                    min = Bt[i];
                    ind = i;
                }
            }
        }
        if (ind != -1) {
            Ct[ind] = BT[ind] + count;
            count += BT[ind];
            j++;
            Bt[ind] = 1001;
        } else {
            count++;
        }
    }

    vector<int> TAT(n), WT(n);

    for (int i = 0; i < n; i++) {
        TAT[i] = Ct[i] - Arr[i];
    }

    for (int i = 0; i < n; i++) {
        WT[i] = TAT[i] - BT[i];
    }

    cout << "\nProcess Table:\nPid\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << (i + 1) << "\t" << Arr[i] << "\t" << BT[i] << "\t" << Ct[i] << "\t" << TAT[i] << "\t" << WT[i] << "\n";
    }

    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += static_cast<float>(TAT[i]);
    }
    cout << "\nAverage TAT: " << sum / n;
    
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += static_cast<float>(WT[i]);
    }
    cout << "\nAverage WT: " << sum / n;

    return 0;
}
