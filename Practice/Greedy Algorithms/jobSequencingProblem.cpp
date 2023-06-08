#include<bits/stdc++.h>
using namespace std;

class Job {
    public:
    
    int deadline;
    int profit;
    int id;
    
    Job (int i, int d, int p) {
        id = i;
        deadline = d;
        profit = p;
    }

    // getter function for profit
    int getProfit() {
        return profit;
    } 
    
};

bool compareJobs (Job &j1, Job &j2) {
    return j1.getProfit() > j2.getProfit();
}

int main () {
    vector<vector<int>> jobsInfo{{4,20}, {1,10}, {1,40}, {1,30}};

    vector<Job> jobs;

    for (int i = 0; i < jobsInfo.size(); i++) {
        jobs.push_back(Job(i, jobsInfo[i][0], jobsInfo[i][1]));
    }

    sort(jobs.begin(), jobs.end(), compareJobs);
    // decreasing order of profit

    vector<int> seq;
    int time = 0;
    for (int i = 0; i < jobs.size(); i++) {
        Job curr = jobs[i];
        if (curr.deadline > time ) {
            seq.push_back(curr.id);
            time++;
        } 
    }

    // print sequence
    for (int i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    return 0;
}