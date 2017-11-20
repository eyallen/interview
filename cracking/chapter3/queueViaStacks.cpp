#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

/*
 * Implement a queue using two stacks. Optimize for multiple dequeues in a row.
 */
template<class T>
class MyQueue
{
public:
    MyQueue()
    {
        _enqueue = stack<T>();
        _dequeue = stack<T>();
    }

    void Enqueue(T value)
    {
        // Ensure our enqueue stack is ready
        FillEnqueueStack();

        // Now we can safely add our value
        _enqueue.push(value);
    }

    T Dequeue()
    {
        // Ensure our dequeue stack is ready
        FillDequeueStack();

        // Now we can safely retrieve our value
        T ret = _dequeue.top();
        _dequeue.pop();
        return ret;
    }

private:
    void FillEnqueueStack()
    {
        return SwapStacks(_dequeue, _enqueue);
    }

    void FillDequeueStack()
    {
        return SwapStacks(_enqueue, _dequeue);
    }

    void SwapStacks(stack<T>& source, stack<T>& target)
    {
        while(!source.empty())
        {
            target.push(source.top());
            source.pop();
        }
        return;
    }

    stack<T> _enqueue;
    stack<T> _dequeue;
};

int main()
{
    MyQueue<int> queue = MyQueue<int>();
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    
    cout << queue.Dequeue() << endl;

    queue.Enqueue(6);

    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;
    cout << queue.Dequeue() << endl;
}