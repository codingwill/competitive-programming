#include <bits/stdc++.h>

using namespace std;

/*
** Author: wkwkwill (Willy I. K)
** 22/05/2020 12:37 AM
*/

class MyCircularQueue 
{
private:
    //variables
    vector<int> v;
    int l, r;
    int size;
    bool empty, full;
    
    //functions
    int mod(int a, int b)
    {
        return (a % b + b) % b; //biar nilai indeksnya circular (termasuk indeks negatif), range {0, size-1}.
    }

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k)
    {
        v.resize(k);
        size = k;
        l = 0;
        r = 0;
        empty = true;
        full = false;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) 
    {
        if (!isFull())
        {
            empty = false;
            v[r] = value;
            r = mod((r+1), size);
            if (r == l) full = true;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() 
    {
        if (!isEmpty()) 
        {
            full = false;
            l = mod((l+1), size);
            if (l == r) empty = true;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() 
    {
        if (isEmpty()) return -1;
        return v[l];
    }
    
    /** Get the last item from the queue. */
    int Rear() 
    {
        if (isEmpty()) return -1;
        return v[mod(r-1, size)];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() 
    {
        return empty;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() 
    {
        return full;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
    MyCircularQueue q(3);
    q.enQueue(5);
    q.enQueue(3);
    q.enQueue(2);
    cout << (q.isFull() ? "True" : "False") << endl;
    cout << (q.isEmpty() ? "True" : "False") << endl;
    q.deQueue();
    q.deQueue();
    q.deQueue();
    cout << (q.isFull() ? "True" : "False") << endl;
    cout << (q.isEmpty() ? "True" : "False") << endl;
    cout << q.Front() << ' ' << q.Rear();
}