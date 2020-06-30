//Interface atau kerangka/outline/prototype 
//untuk penerapan class Stack
public interface StackBuatan<T>
{
    abstract boolean isEmpty();
    abstract T peek();
    abstract T pop();
    abstract void push(T item);
    abstract int size();
}