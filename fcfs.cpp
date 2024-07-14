#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of jobs" << endl;
    cin >> n;

    vector<int> at(n), bt(n), ct(n), tat(n), wt(n);

    cout << "Enter the jobs with Arrival Time & Burst Time" << endl;
    cout << "  AT  BT" << endl;
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "-";
        cin >> at[i] >> bt[i];
    }

    int flag = 0, time = 0;
    float avgtat = 0, avgwt = 0;

    for (int i = 0; i < n; i++) {
        if (flag < at[i]) {
            time = at[i] - flag;
        }

        flag = flag + bt[i] + time;
        time = 0;
        ct[i] = flag;
        tat[i] = ct[i] - at[i];
        avgtat += tat[i];
        wt[i] = tat[i] - bt[i];
        avgwt += wt[i];
    }

    cout << "Table" << endl;
    cout << "  AT BT CT TAT WT" << endl;

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "-" << at[i] << " " << bt[i] << " " << ct[i] << " " << tat[i] << " " << wt[i] << endl;
    }

    cout << "AVGTAT=" << avgtat / n << " and AVGWT=" << avgwt / n << endl;

    return 0;
}
