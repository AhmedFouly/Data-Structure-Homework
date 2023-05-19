#include <bits/stdc++.h>
using namespace std;

class Vector
{
private:
    int *arr = {nullptr};
    int size = {0};
    int capacity = {0};
public:
    Vector(int size): size(size)
    {
        if (size < 0)
        {
            size = 1;
            capacity = size*2;
        }
        arr = new int [capacity] {};
    }
    ~Vector()
    {
        delete []arr;
        arr = nullptr;
    }
    int get(int idx)
    {
        return idx;
    }
    void set(int idx, int value)
    {
        arr[idx] = value;
    }
    void print()
    {
        for (int i=0;i<size;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    int find(int value)
    {
        for (int i=0;i<size;i++)
        {
            if (arr[i]==value)
            {
                return i;
            }
        }
        return -1;
    }
    int get_front()
    {
        return arr[0];
    }
    int get_back()
    {
        return arr[size-1];
    }
    void push_back(int value)
    {
        if (size == capacity)
        {
            expand_capacity();
        }
        arr[size++]=value;
    }
    void expand_capacity()
    {
        capacity *= 2;
        cout << "Expanded Capacity to " << capacity << "\n";
        int *arr2 = new int[capacity] {};
        for(int i=0;i<size;i++)
        {
            arr2[i] = arr[i];
        }
        swap(arr, arr2);
        delete[] arr2;
    }
    void insert(int idx, int value)
    {
        if (size == capacity)
        {
            expand_capacity();
        }
        //Shift Right
        for (int i=size-1;i>=idx;i--)
        {
            arr[i+1] = arr[i];
        }
        arr[idx] = value;
        ++size;
    }
    void right_rotate()
    {
        int value = 0;
        //Take the last value > -1 and put it in the first index.
        for (int i=size-1;i>=0;i--)
        {
            if (arr[i] > -1)
            {
                value = arr[i];
                break;
            }
        }
        //Shift Right
        for (int i=size-1;i>=0;i--)
        {
            arr[i+1] = arr[i];
        }
        arr[0] = value;
    }
    void left_rotate()
    {
        int value = arr[0];
        //Shift Left
        for (int i=1;i<=size-1;i++)
        {
            arr[i-1] = arr[i];
            if (i==size-1)
            {
                arr[i]=value;
            }
        }
    }
    void right_rotate(int times)
    {
        //This is the trick , every size rotation get it to it's original
        //Form so we get rid of too much size rotations (i saw the code for this one)
        times%=size;
        for (int i=0;i<times;i++)
        {
            right_rotate();
        }
    }
    int pop(int idx)
    {
        int value = arr[idx];
        //Shift Right
        for (int i=idx;i<=size-1;i++)
        {
            arr[i] = arr[i+1];
        }
        size--;
        cout << "Returned value is " << value << "\n";
    }
    int find_transposition(int value)
    {
        int idx = find(value);
        if (!(idx == 0))
        {
            swap(arr[idx-1], arr[idx]);
        }
    }
};

int main()
{
    Vector v(5);
    v.set(0,1);
    v.set(1,2);
    v.set(2,3);
    v.set(3,4);
    v.set(4,5);
    v.print();
    /*v.right_rotate();
    v.print();
    v.right_rotate();
    v.print();
    v.push_back(6);
    v.print();
    v.push_back(6);
    v.print();
    v.push_back(6);
    v.print();
    v.right_rotate();
    v.print();
    v.left_rotate();
    v.print();*/
    /*v.pop(2);
    v.print();
    v.left_rotate();
    v.print();*/
    v.find_transposition(3);
    v.print();
    v.find_transposition(3);
    v.print();
    v.find_transposition(3);
    v.print();
    v.find_transposition(4);
    v.print();
    return 0;
}
