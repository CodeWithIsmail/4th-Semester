#include <bits/stdc++.h>
using namespace std;

struct process
{
    string process_id;
    int arrival_time;
    int burst_time;
    int priority;
    int starting_time;
    int completion_time;
    int turn_around;
    int waiting_time;
    int remaining_time;
    bool arrived;
};

void print_gantt_chart(vector<process> process_order)
{
    int i, j;
    cout << "\n\t\t\t\t\t\t Gantt Chart\t\t\t\t\n\n";
    for (i = 0; i < process_order.size(); i++)
    {
        cout << "|";
        for (j = 0; j < process_order[i].burst_time / 2 - 1; j++)
            cout << "-";
        cout << process_order[i].process_id;
        for (j = 0; j < process_order[i].burst_time / 2 - 1; j++)
            cout << "-";
    }
    cout << "|\n";
    cout << "0";
    for (i = 0; i < process_order.size(); i++)
    {
        cout << " ";
        for (j = 0; j < process_order[i].burst_time - 3; j++)
            cout << " ";
        cout << process_order[i].completion_time;
    }
    cout << "\n\n\n";
}
int main()
{
    int number_of_process, i, j, quantum;
    cout << "Enter quantum time: ";
    cin >> quantum;
    freopen("process2.txt", "r", stdin);
    cin >> number_of_process;
    process processList[number_of_process];
    for (i = 0; i < number_of_process; i++)
    {
        cin >> processList[i].process_id >> processList[i].arrival_time >> processList[i].burst_time >> processList[i].priority;
        processList[i].remaining_time = processList[i].burst_time;
        processList[i].arrived = false;
    }

    int current_time = 0, count_done_process = 0;
    vector<process> process_order;
    queue<process> ready;
    while (count_done_process < number_of_process)
    {
        for (i = 0; i < number_of_process; i++)
        {
            if (processList[i].arrival_time <= current_time && processList[i].remaining_time > 0 && processList[i].arrived == false)
            {
                processList[i].arrived = true;
                ready.push(processList[i]);
            }
        }
        if (ready.empty())
        {
            current_time++;
            continue;
        }
        else
        {
            int last;
            if (process_order.size())
                last = process_order.back().completion_time;
            else
                last = 0;
            int wait = current_time - last;
            if (wait > 0)
            {
                process temp;
                temp.process_id = "I";
                temp.completion_time = current_time;
                temp.burst_time = wait;
                process_order.push_back(temp);
            }
        }
        process newTaken = ready.front();
        ready.pop();
        for (i = 0; i < number_of_process; i++)
        {
            if (newTaken.process_id == processList[i].process_id)
                break;
        }

        if (processList[i].remaining_time == processList[i].burst_time)
            processList[i].starting_time = current_time;
        int pos = min(processList[i].remaining_time, quantum);
        current_time += pos;
        processList[i].remaining_time -= pos;

        for (j = 0; j < number_of_process; j++)
        {
            if (processList[j].arrival_time <= current_time && processList[j].remaining_time > 0 && processList[j].arrived == false)
            {
                processList[j].arrived = true;
                ready.push(processList[j]);
            }
        }

        if (processList[i].remaining_time == 0)
        {
            processList[i].completion_time = current_time;
            processList[i].turn_around = processList[i].completion_time - processList[i].arrival_time;
            processList[i].waiting_time = processList[i].turn_around - processList[i].burst_time;
            count_done_process++;
        }
        else
            ready.push(processList[i]);

        process temp = processList[i];
        temp.burst_time = pos;
        temp.completion_time = current_time;
        process_order.push_back(temp);
    }

    int total_wait = 0, total_turn = 0;
    cout << "\n\nProcess id    Turn around time     Waiting time\n";
    cout << "-----------------------------------------------\n";
    for (i = 0; i < number_of_process; i++)
    {
        cout << processList[i].process_id << "\t\t" << processList[i].turn_around << "\t\t\t" << processList[i].waiting_time << "\n";
        total_turn += processList[i].turn_around;
        total_wait += processList[i].waiting_time;
    }
    cout << "\n";
    double avg_turn = (double)total_turn / number_of_process, avg_wait = (double)total_wait / number_of_process;
    cout << "Average turn around time: " << avg_turn << "\n"
         << "Average waiting time: " << avg_wait << "\n";

    print_gantt_chart(process_order);
}
