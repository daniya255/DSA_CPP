#include <bits/stdc++.h>
using namespace std;
class ArrayStack
{
private:
    int *st;
    int capacity;
    int topInd;

public:
    ArrayStack(int size=10)
    {
        capacity = size;
        st = new int[size];
        topInd = -1;
    }

    bool isEmpty()
    {
        return topInd == -1;
    }

    void push(int val)
    {
        if (topInd < (capacity - 1))
        {
            st[++topInd]=val;
        }
        else
        {
            cout << "Stack overflow" << endl;
            return;
        }
    }

    int pop()
    {
        if (topInd == -1)
        {
            cout << "Stack underflow, no element to remove." << endl;
            return -1;
        }

        return st[topInd--];
    }

    int top()
    {
        if (topInd == -1)
        {
            cout << "No element to return." << endl;
            return -1;
        }

        return st[topInd];
    }

    ~ArrayStack()
    {
        delete[] st;
    }
};
int main()
{
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "push")
        {
            stack.push(inputs[i][0]);
            cout << "null ";
        }
        else if (commands[i] == "pop")
        {
            cout << stack.pop() << " ";
        }
        else if (commands[i] == "top")
        {
            cout << stack.top() << " ";
        }
        else if (commands[i] == "isEmpty")
        {
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        }
        else if (commands[i] == "ArrayStack")
        {
            cout << "null ";
        }
    }
    return 0;
}

//Time Complexity: O(1) for all operations (push, pop, top, isEmpty).
//Space Complexity: O(N), where N is the maximum capacity of the stack, as we are using an array to store the elements.