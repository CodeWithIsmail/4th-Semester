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
};
bool comp(process p1, process p2)
{
    if (p1.burst_time == p2.burst_time)
        return p1.arrival_time <= p2.arrival_time;

    return p1.burst_time <= p2.burst_time;
}
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
    freopen("process1.txt", "r", stdin);
    int number_of_process, i, j;
    cin >> number_of_process;
    process processList[number_of_process];
    for (i = 0; i < number_of_process; i++)
    {
        cin >> processList[i].process_id >> processList[i].arrival_time >> processList[i].burst_time >> processList[i].priority;
        processList[i].remaining_time = processList[i].burst_time;
    }

    int current_time = 0, count_done_process = 0;
    vector<process> process_order;

    while (count_done_process < number_of_process)
    {
        deque<process> ready;
        for (i = 0; i < number_of_process; i++)
        {
            if (processList[i].arrival_time <= current_time && processList[i].remaining_time > 0)
            {
                ready.push_back(processList[i]);
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

        sort(ready.begin(), ready.end(), comp);
        process newTaken = ready.front();

        for (i = 0; i < number_of_process; i++)
        {
            if (newTaken.process_id == processList[i].process_id)
                break;
        }

        processList[i].starting_time = current_time;
        processList[i].remaining_time = 0;
        processList[i].completion_time = processList[i].starting_time + processList[i].burst_time;
        processList[i].turn_around = processList[i].completion_time - processList[i].arrival_time;
        processList[i].waiting_time = processList[i].starting_time - processList[i].arrival_time;
        current_time = processList[i].completion_time;
        count_done_process++;
        process_order.push_back(processList[i]);
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
