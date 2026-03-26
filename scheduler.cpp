#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id, arrival, burst, waiting, turnaround;
};

// FCFS Scheduling
void fcfs(vector<Process> p) {
    cout << "\n--- FCFS Scheduling ---\n";
    
    int time = 0;
    for (int i = 0; i < p.size(); i++) {
        if (time < p[i].arrival)
            time = p[i].arrival;

        p[i].waiting = time - p[i].arrival;
        time += p[i].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;

        cout << "P" << p[i].id 
             << " WT: " << p[i].waiting 
             << " TAT: " << p[i].turnaround << endl;
    }
}

// SJF Scheduling (Non-preemptive)
void sjf(vector<Process> p) {
    cout << "\n--- SJF Scheduling ---\n";

    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.burst < b.burst;
    });

    int time = 0;
    for (int i = 0; i < p.size(); i++) {
        p[i].waiting = time;
        time += p[i].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;

        cout << "P" << p[i].id 
             << " WT: " << p[i].waiting 
             << " TAT: " << p[i].turnaround << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter arrival time and burst time for P" << i + 1 << ": ";
        cin >> p[i].arrival >> p[i].burst;
    }

    fcfs(p);
    sjf(p);

    return 0;
}
