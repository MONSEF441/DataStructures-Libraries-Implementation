#pragma once

#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{

protected:
    int _Size = 0;


public:
    T* OriginalArray;
    T* _TempArray;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;

        _Size = Size;

        OriginalArray = new T[_Size];

    }

    ~clsDynamicArray()
    {

        delete[]  OriginalArray;

    }

    bool SetItem(int Index, T Value)
    {

        if (Index >= _Size || Index < 0)
        {
            return false;
        }

        OriginalArray[Index] = Value;
        return true;

    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);

    }

    T GetItem(int Index)
    {
        return OriginalArray[Index];

    }

    int Find(T Value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == Value)
            {
                return i;
            }
        }
        return -1;

    }

    void PrintList()

    {

        for (int i = 0; i <= _Size - 1; i++)
        {
            cout << OriginalArray[i] << " ";
        }

        cout << "\n";

    }
    void Reverse() 
    {
        _TempArray = new T[_Size];

        for (int i = 0; i < _Size ; i++)
        {
            _TempArray[i] = OriginalArray[_Size - i - 1];

        }
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }
    void Clear()
    {
        _Size = 0;
        _TempArray = new T[0];
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }
    void Resize(int NewSize)
    {
        if (NewSize == _Size)
            return;
        if (NewSize < 0)
        {
            NewSize = 0;
        };

        _TempArray = new T[NewSize];

        //limit the original size to the new size if it is less.
        if (NewSize < _Size)
            _Size = NewSize;

        //copy all data from original array until the size
        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize;

        delete[] OriginalArray;
        OriginalArray = _TempArray;



    }

    void DeleteItemAt(int Index)
    {
      
        while(Index+1<_Size)
        {
            OriginalArray[Index] = OriginalArray[Index + 1];
            Index++;
        
        }
        Resize(_Size - 1);
    }
    void DeleteFirstItem()
    {
        DeleteItemAt(0);
      
    }
    void DeleteLastItem()
    {
        DeleteItemAt(_Size - 1);
    }
    bool DeleteItem(T Value)
    {

        int Index = Find(Value);

        if (Index == -1)
        {
            return false;
        }

        DeleteItemAt(Index);
        return true;

    }

    bool InsertAt(T index, T value) {

        if (index > _Size || index < 0)
        {
            return false;
        }

        _Size++;

        _TempArray = new T[_Size];

        //copy all before index
        for (int i = 0; i < index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _TempArray[index] = value;

        //copy all after index
        for (int i = index; i < _Size - 1; i++)
        {
            _TempArray[i + 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;

    }

    void InsertAtBeginning(T value)
    {

        InsertAt(0, value);

    }


    bool InsertBefore(T index, T value)
    {
        if (index < 1)
            return InsertAt(0, value);
        else
            return InsertAt(index, value);

    }

    bool InsertAfter(T index, T value)
    {
        if (index >= _Size)
            return InsertAt(_Size - 1, value);
        else
            return InsertAt(index + 1, value);

    }

    bool InsertAtEnd(T value)
    {

        return InsertAt(_Size, value);

    }



};
