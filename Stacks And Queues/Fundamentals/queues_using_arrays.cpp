#include <bits/stdc++.h>
using namespace std;
class QueueArray
{
private:
    int *que;
    int capacity;
    int front;
    int rear;
    int size = 0;

public:
    QueueArray(int size = 10)
    {
        capacity = size;
        que= new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(int val)
    {
        if (size >= capacity)
        {
            cout << "Overflow!! capacity reached max" << endl;
            exit(1);
        }

        if (rear == -1)
        {
            rear = 0;
            front = 0;
        }

        else
        {
            rear = (rear + 1) % capacity;
        }

        que[rear] = val;
        size++;
    }

    int pop()
    {
        if (size == 0)
        {
            cout << "No element found." << endl;
            exit(1);
        }

        int popped = que[front];

        if (size == 1)
        {
            front = -1, rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        size--;
        return popped;
    }

    int peek()
    {
        if (size == 0)
        {
            cout << "No element found." << endl;
            exit(1);
        }

        return que[front];
    }
};
int main()
{
    QueueArray queue;
    vector<string> commands = {"ArrayQueue", "push", "push",
                               "peek", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "push")
        {
            queue.push(inputs[i][0]);
            cout << "null ";
        }
        else if (commands[i] == "pop")
        {
            cout << queue.pop() << " ";
        }
        else if (commands[i] == "peek")
        {
            cout << queue.peek() << " ";
        }
        else if (commands[i] == "isEmpty")
        {
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        }
        else if (commands[i] == "ArrayQueue")
        {
            cout << "null ";
        }
    }
    return 0;
}

//Time Complexity: O(1) for all operations (push, pop, peek, isEmpty) since they involve simple index manipulations and array accesses.
//Space Complexity: O(1) since we are using a fixed-size array and a few variables.