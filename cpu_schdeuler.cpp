#include <bits/stdc++.h>
using namespace std;


bool cmp_SJF(pair<int, vector<int>> process1, pair<int, vector<int>> process2) {
    if (process1.second[2] != process2.second[2]) {
        return process1.second[2] < process2.second[2];
    }
    return process1.second[3] > process2.second[3];
}

void SJF(int totalBurstTime, vector<pair<int, vector<int>>> taskList, vector<pair<int, vector<int>>> &originalTaskList) {
    int timeQuantum = 0;
    int currentTime = 0;

    while (totalBurstTime > 0) {
        sort(taskList.begin(), taskList.end(), cmp_SJF);
        int taskToExecute = -1;

        for (int i = 0; i < taskList.size(); ++i) {
            if (taskList[i].second[1] <= currentTime) {
                taskToExecute = i;
                int j;
                for (j = 0; j < originalTaskList.size(); j++) {
                    if (originalTaskList[j].second[0] == taskList[i].second[0]) {
                        break;
                    }
                }
                originalTaskList[j].second.push_back(currentTime - originalTaskList[j].second[1]);
                originalTaskList[j].second.push_back(currentTime + originalTaskList[j].second[2]);
                originalTaskList[j].second.push_back(originalTaskList[j].second[6] - originalTaskList[j].second[1] - originalTaskList[j].second[2]);
                originalTaskList[j].second.push_back(originalTaskList[j].second[6] - originalTaskList[j].second[1]);
                break;
            }
        }

        if (taskToExecute == -1) {
            cout << "NOP" << " ";
            currentTime++;
            continue;
        }

        timeQuantum = taskList[taskToExecute].second[2];
        currentTime += timeQuantum;

        for (int i = 0; i < timeQuantum; ++i) {
            cout << "P" << taskList[taskToExecute].second[0] << " ";
        }

        totalBurstTime -= timeQuantum;
        taskList[taskToExecute].second[4] += timeQuantum;
        taskList.erase(taskList.begin() + taskToExecute);
    }
}


bool cmp_LJF(pair<int, vector<int>> process1, pair<int, vector<int>> process2){
    if(process1.second[2] != process2.second[2]){
        return process1.second[2] > process2.second[2];
    }
    return process1.second[3] > process2.second[3];
}


void LJF(int totalBurstTime, vector<pair<int, vector<int>>> taskList, vector<pair<int, vector<int>>> &originalTaskList) {
    int timeQuantum = 0;
    int currentTime = 0;

    while (totalBurstTime > 0) {
        sort(taskList.begin(), taskList.end(), cmp_LJF);
        int taskToExecute = -1;

        for (int i = 0; i < taskList.size(); ++i) {
            if (taskList[i].second[1] <= currentTime) {
                taskToExecute = i;
                int j;
                for (j = 0; j < originalTaskList.size(); j++) {
                    if (originalTaskList[j].second[0] == taskList[i].second[0]) {
                        break;
                    }
                }
                originalTaskList[j].second.push_back(currentTime - originalTaskList[j].second[1]);
                originalTaskList[j].second.push_back(currentTime + originalTaskList[j].second[2]);
                originalTaskList[j].second.push_back(originalTaskList[j].second[6] - originalTaskList[j].second[1] - originalTaskList[j].second[2]);
                originalTaskList[j].second.push_back(originalTaskList[j].second[6] - originalTaskList[j].second[1]);
                break;
            }
        }

        if (taskToExecute == -1) {
            cout << "NOP" << " ";
            currentTime++;
            continue;
        }

        timeQuantum = taskList[taskToExecute].second[2];
        currentTime += timeQuantum;

        for (int i = 0; i < timeQuantum; ++i) {
            cout << "P" << taskList[taskToExecute].second[0] << " ";
        }

        totalBurstTime -= timeQuantum;
        taskList[taskToExecute].second[4] += timeQuantum;
        taskList.erase(taskList.begin() + taskToExecute);
    }
}


bool cmp_SRJF(pair<int, vector<int>> process1, pair<int, vector<int>> process2){
    if(process1.second[2] != process2.second[2]){
        return process1.second[2] < process2.second[2];
    }
    return process1.second[3] > process2.second[3];
}

void SRJF(int totalBurstTime, vector<pair<int, vector<int>>> taskList, vector<pair<int, vector<int>>> &originalTaskList) {
    int currentTime = 0;
    int timeSlice = 0;
    int index;
    unordered_map<int, int> taskMap;

    while (totalBurstTime > 0) {
        sort(taskList.begin(), taskList.end(), cmp_SRJF);
        int taskToExecute = -1;

        for (int i = 0; i < taskList.size(); ++i) {
            if (taskList[i].second[1] <= currentTime) {
                taskToExecute = i;
                for (index = 0; index < originalTaskList.size(); index++) {
                    if (originalTaskList[index].second[0] == taskList[i].second[0]) {
                        if (taskMap.find(index) == taskMap.end()) {
                            taskMap[index] = 1;
                            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1]);
                        }
                        break;
                    }
                }
                break;
            }
        }

        if (taskToExecute == -1) {
            cout << "NOP" << " ";
            currentTime++;
            continue;
        }

        timeSlice = 1;
        currentTime += timeSlice;

        for (int i = 0; i < timeSlice; ++i) {
            cout << "P" << taskList[taskToExecute].second[0] << " ";
        }

        totalBurstTime -= timeSlice;
        taskList[taskToExecute].second[4] += timeSlice;

        if (timeSlice == taskList[taskToExecute].second[2]) {
            taskList.erase(taskList.begin() + taskToExecute);
            originalTaskList[index].second.push_back(currentTime);
            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1] - originalTaskList[index].second[2]);
            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1]);
        } else {
            taskList[taskToExecute].second[2] -= timeSlice;
        }
    }
}


bool cmp_LRJF(pair<int, vector<int>> process1, pair<int, vector<int>> process2){
    if(process1.second[2] != process2.second[2]){
        return process1.second[2] > process2.second[2];
    }
    return process1.second[3] > process2.second[3];
}

void LRJF(int totalBurstTime, vector<pair<int, vector<int>>> taskList, vector<pair<int, vector<int>>> &originalTaskList) {
    int timeSlice = 0;
    int currentTime = 0;
    int index;
    unordered_map<int, int> taskMap;

    while (totalBurstTime > 0) {
        sort(taskList.begin(), taskList.end(), cmp_LRJF);
        int taskToExecute = -1;

        for (int i = 0; i < taskList.size(); ++i) {
            if (taskList[i].second[1] <= currentTime) {
                taskToExecute = i;
                for (index = 0; index < originalTaskList.size(); index++) {
                    if (originalTaskList[index].second[0] == taskList[i].second[0]) {
                        if (taskMap.find(index) == taskMap.end()) {
                            taskMap[index] = 1;
                            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1]);
                        }
                        break;
                    }
                }
                break;
            }
        }

        if (taskToExecute == -1) {
            cout << "NOP" << " ";
            currentTime++;
            continue;
        }

        timeSlice = 1;
        currentTime += timeSlice;

        for (int i = 0; i < timeSlice; ++i) {
            cout << "P" << taskList[taskToExecute].second[0] << " ";
        }

        totalBurstTime -= timeSlice;
        taskList[taskToExecute].second[4] += timeSlice;

        if (timeSlice == taskList[taskToExecute].second[2]) {
            taskList.erase(taskList.begin() + taskToExecute);
            originalTaskList[index].second.push_back(currentTime);
            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1] - originalTaskList[index].second[2]);
            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1]);
        } else {
            taskList[taskToExecute].second[2] -= timeSlice;
        }
    }
}


bool cmp_FCFS(pair<int, vector<int>> process1, pair<int, vector<int>> process2){
    if(process1.second[1] != process2.second[1]){
        return process1.second[1] < process2.second[1];
    }
    return process1.second[3] > process2.second[3];
}

void FCFS(int totalBurstTime, vector<pair<int, vector<int>>> taskList, vector<pair<int, vector<int>>> &originalTaskList) {
    int timeSlice = 0;
    int currentTime = 0;

    while (totalBurstTime > 0) {
        sort(taskList.begin(), taskList.end(), cmp_FCFS);
        int taskToExecute = -1;

        for (int i = 0; i < taskList.size(); ++i) {
            if (taskList[i].second[1] <= currentTime) {
                taskToExecute = i;
                int index;

                for (index = 0; index < originalTaskList.size(); index++) {
                    if (originalTaskList[index].second[0] == taskList[i].second[0]) {
                        break;
                    }
                }

                originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1]);
                originalTaskList[index].second.push_back(currentTime + originalTaskList[index].second[2]);
                originalTaskList[index].second.push_back(originalTaskList[index].second[6] - originalTaskList[index].second[1] - originalTaskList[index].second[2]);
                originalTaskList[index].second.push_back(originalTaskList[index].second[6] - originalTaskList[index].second[1]);
                break;
            }
        }

        if (taskToExecute == -1) {
            cout << "NOP" << " ";
            currentTime++;
            continue;
        }

        timeSlice = taskList[taskToExecute].second[2];
        currentTime += timeSlice;

        for (int i = 0; i < timeSlice; ++i) {
            cout << "P" << taskList[taskToExecute].second[0] << " ";
        }

        totalBurstTime -= timeSlice;
        taskList[taskToExecute].second[4] += timeSlice;
        taskList.erase(taskList.begin() + taskToExecute);
    }
}


bool cmp_MLFQ(pair<int, vector<int>> process1, pair<int, vector<int>> process2){
    if (process1.first != process2.first){
        return process1.first > process2.first;
    }else if (process1.second[3] != process2.second[3]){
        return process1.second[3] > process2.second[3];
    }
    return process1.second[2] < process2.second[2];
}

void MLFQ(int totalBurstTime, vector<pair<int, vector<int>>> taskList, vector<pair<int, vector<int>>> &originalTaskList) {
    int currentTime = 0;
    int timeSlice = 0;
    int index;
    unordered_map<int, int> taskMap;

    while (totalBurstTime > 0) {
        sort(taskList.begin(), taskList.end(), cmp_MLFQ);
        int taskToExecute = -1;

        for (int i = 0; i < taskList.size(); ++i) {
            if (taskList[i].second[1] <= currentTime) {
                taskToExecute = i;
                for (index = 0; index < originalTaskList.size(); index++) {
                    if (originalTaskList[index].second[0] == taskList[i].second[0]) {
                        if (taskMap.find(index) == taskMap.end()) {
                            taskMap[index] = 1;
                            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1]);
                        }
                        break;
                    }
                }
                break;
            }
        }

        if (taskToExecute == -1) {
            cout << "NOP" << " ";
            currentTime++;
            continue;
        }

        timeSlice = min(taskList[taskToExecute].first / 2 + 1, taskList[taskToExecute].second[2]);
        currentTime += timeSlice;

        for (int i = 0; i < timeSlice; ++i) {
            cout << "P" << taskList[taskToExecute].second[0] << " ";
        }

        totalBurstTime -= timeSlice;
        taskList[taskToExecute].second[4] += timeSlice;

        for (int i = 0; i < taskList.size(); ++i) {
            if (i == taskToExecute) {
                continue;
            }
            taskList[i].first = taskList[i].second[3] + max(min(5, (currentTime - taskList[i].second[1] - taskList[i].second[4]) / 8), 0);
        }

        if (timeSlice == taskList[taskToExecute].second[2]) {
            taskList.erase(taskList.begin() + taskToExecute);
            originalTaskList[index].second.push_back(currentTime);
            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1] - originalTaskList[index].second[2]);
            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1]);
        } else {
            taskList[taskToExecute].second[2] -= timeSlice;
        }
    }
}

bool cmp_PS(pair<int, vector<int>> process1, pair<int, vector<int>> process2){
    if (process1.first != process2.first){
        return process1.first > process2.first;
    }
    return process1.second[2] < process2.second[2];
}

void PS(int totalBurstTime, vector<pair<int, vector<int>>> taskList, vector<pair<int, vector<int>>> &originalTaskList) {
    int currentTime = 0;
    int timeSlice = 0;
    int index;
    unordered_map<int, int> taskMap;

    while (totalBurstTime > 0) {
        sort(taskList.begin(), taskList.end(), cmp_PS);
        int taskToExecute = -1;

        for (int i = 0; i < taskList.size(); ++i) {
            if (taskList[i].second[1] <= currentTime) {
                taskToExecute = i;
                for (index = 0; index < originalTaskList.size(); index++) {
                    if (originalTaskList[index].second[0] == taskList[i].second[0]) {
                        if (taskMap.find(index) == taskMap.end()) {
                            taskMap[index] = 1;
                            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1]);
                        }
                        break;
                    }
                }
                break;
            }
        }

        if (taskToExecute == -1) {
            cout << "NOP" << " ";
            currentTime++;
            continue;
        }

        timeSlice = 1;
        currentTime += timeSlice;

        for (int i = 0; i < timeSlice; ++i) {
            cout << "P" << taskList[taskToExecute].second[0] << " ";
        }

        totalBurstTime -= timeSlice;
        taskList[taskToExecute].second[4] += timeSlice;

        if (timeSlice == taskList[taskToExecute].second[2]) {
            taskList.erase(taskList.begin() + taskToExecute);
            originalTaskList[index].second.push_back(currentTime);
            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1] - originalTaskList[index].second[2]);
            originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1]);
        } else {
            taskList[taskToExecute].second[2] -= timeSlice;
        }
    }
}


void RR(int totalBurstTime, vector<pair<int, vector<int>>> taskList, vector<pair<int, vector<int>>> &originalTaskList) {
    int currentTime = 0;
    int timeQuantum = 3;
    int taskToExecute = -1;
    queue<int> readyQueue;
    int index;
    unordered_map<int, int> taskMap;

    while (totalBurstTime > 0) {
        // Enqueue tasks that have arrived during the current time slice
        for (int i = 0; i < taskList.size(); ++i) {
            if (timeQuantum >= 1 && taskList[i].second[1] == currentTime - timeQuantum + 1) {
                readyQueue.push(i);
            }
        }
        for (int i = 0; i < taskList.size(); ++i) {
            if (timeQuantum >= 2 && taskList[i].second[1] == currentTime - timeQuantum + 2) {
                readyQueue.push(i);
            }
        }
        for (int i = 0; i < taskList.size(); ++i) {
            if (timeQuantum >= 3 && taskList[i].second[1] == currentTime - timeQuantum + 3) {
                readyQueue.push(i);
            }
        }

        // Process the current task
        if (taskToExecute != -1) {
            if (timeQuantum != taskList[taskToExecute].second[2]) {
                taskList[taskToExecute].second[2] -= timeQuantum;
                readyQueue.push(taskToExecute);
            } else {
                originalTaskList[index].second.push_back(currentTime);
                originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1] - originalTaskList[index].second[2]);
                originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1]);
            }
        }

        // If there are no tasks to execute, increment the current time
        if (readyQueue.empty()) {
            cout << "NOP" << " ";
            currentTime++;
            continue;
        }

        // Get the next task to execute
        taskToExecute = readyQueue.front();
        for (index = 0; index < originalTaskList.size(); index++) {
            if (originalTaskList[index].second[0] == taskList[taskToExecute].second[0]) {
                if (taskMap.find(index) == taskMap.end()) {
                    taskMap[index] = 1;
                    originalTaskList[index].second.push_back(currentTime - originalTaskList[index].second[1]);
                }
                break;
            }
        }
        readyQueue.pop();

        // Calculate the time quantum for the current task
        timeQuantum = min(3, taskList[taskToExecute].second[2]);
        currentTime += timeQuantum;

        // Print the task being executed
        for (int i = 0; i < timeQuantum; ++i) {
            cout << "P" << taskList[taskToExecute].second[0] << " ";
        }

        // Update total burst time and the executed task's remaining burst time
        totalBurstTime -= timeQuantum;
        taskList[taskToExecute].second[4] += timeQuantum;
    }
}


int countDigits(int number) {
    if (number == 0) {
        return 1;
    }
    int digitCount = 0;
    while (number) {
        digitCount++;
        number /= 10;
    }
    return digitCount;
}


void print(vector<pair<int, vector<int>>> &original){
    cout <<endl << endl<< "Table:";
    cout << endl;
    cout << "| Proc  | A T  | B T  | Pri  | R T  | C T  | W T  | TAT  |" << endl;
    int rt = 0;
    int ct = 0;
    int wt = 0;
    int tat = 0;
    for(int j = 0; j < original.size(); j++){
        cout << "| P";
        for(int i = 0; i < 9; i++){
            if(i==4){
                continue;
            }
            if(i == 5){
                rt+=original[j].second[i];
            }
            if(i == 6){
                ct+=original[j].second[i];
            }
            if(i == 7){
                wt+=original[j].second[i];
            }
            if(i == 8){
                tat+=original[j].second[i];
            }
            cout << original[j].second[i];
            for(int k = 0; k < 4-countDigits(original[j].second[i]); k++){
                cout << " ";
            }
            cout << " | ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Averages:" << endl;
    cout << "Average Response Time is " << rt*1.0/original.size() << "." << endl;
    cout << "Average Completion Time is " << ct*1.0/original.size() << "." << endl;
    cout << "Average Waiting Time is " << wt*1.0/original.size() << "." << endl;
    cout << "Average Turn Around Time is " << tat*1.0/original.size() << "." << endl;
    cout << endl << endl;
}

int main(){
    int no_of_processes;
    cout << "Number of processes to be scheduled are: ";
    cin >> no_of_processes;
    cout << endl;
    vector<pair<int, vector<int>>> processes(no_of_processes);
    cout << "AT = Arrival Time | BT = Burst Time | P = Priority (Scale 1 to 5)"<<endl;
    cout << "| Process | AT BT P" << endl;
    for (int i = 0; i < no_of_processes; ++i)
    {
        vector<int> process;
        process.push_back(i+1);

        cout << "| P" << i+1;
        for(int j = 0; j < 6-countDigits(i+1); j++){
            cout << " ";
        }
        cout << " | ";
        int AT;
        cin >> AT;
        process.push_back(AT);
        int BT;
        cin >> BT;
        process.push_back(BT);
        int P;
        cin >> P;
        process.push_back(P);
        process.push_back(0);
        processes[i].first=P;
        processes[i].second=process;
    }
    cout << endl;
    long long total_BT = 0;
    for (int i = 0; i < no_of_processes; ++i)
    {
        total_BT += processes[i].second[2];
    }

    cout << "Proc = Process | A T = Arrival Time | B T = Burst Time | Pri = Priority | R T = Response Time | C T = Completion Time | W T = Waiting Time | TAT = Turn Around Time"<<endl << endl << endl;
    vector<pair<int, vector<int>>> original(no_of_processes);
    copy(processes.begin(), processes.end(), original.begin());
    cout << "Shortest Job First" << endl << endl;
    cout << "Gantt Chart:" << endl;
    SJF(total_BT, processes, original);
    print(original);
    cout << "Shortest Remaining Job First" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    SRJF(total_BT, processes, original);
    print(original);
    cout << "Longest Job First" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    LJF(total_BT, processes, original);
    print(original);
    cout << "Longest Remaining Job First" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    LRJF(total_BT, processes, original);
    print(original);
    cout << "First Come First Serve" << endl << endl;
    cout << "Gantt Chart" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    FCFS(total_BT, processes, original);
    print(original);
    cout << "Round Robin" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    RR(total_BT, processes, original);
    print(original);
    cout << "Priority Scheduling" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    PS(total_BT, processes, original);
    print(original);
    cout << "Multi Level Feedback Queue" << endl << endl;
    cout << "Gantt Chart:" << endl;
    copy(processes.begin(), processes.end(), original.begin());
    MLFQ(total_BT, processes, original);
    print(original);
    return 0;
}
