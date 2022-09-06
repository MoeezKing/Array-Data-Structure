#include <iostream>
using namespace std;
class MyArray
{
    int* array;
    int size;
    int length;
public:
    void setArray(int* array)
    {
        this->array = array;
    }
    void setSize(int size)
    {
        this->size = size;
    }
    void setLength(int length)
    {
        this->length = length;
    }
    int* getArray()
    {
        return array;
    }
    int getSize()
    {
        return size;
    }
    int getLength()
    {
        return length;
    }
    MyArray(int size = 15)
    {
        setSize(size);
        setLength(0);
       
            array = new int[size];

            for (int i = 0; i < size ; i++)
                array[i] = -9999;
        
    }
    bool isEmpty()
    {
        return (length == 0);
    }
    bool isFull()
    {
        return (length == size);
    }
    bool isSpaceAvaliable()
    {
        return (length != size);
    }
    bool insertAtBegining(int val)
    {
        if (isFull())
        {
            cout << "\nArray is full . No more value can be inserted .";
            return false;
        }
        if (isEmpty())
        {
            array[0] = val;
            length++;
            return true;
        }
        else
        {
            int index = length;
            while (index > 0)
            {
                array[index] = array[index - 1];
                index--;
            }
            this->array[0] = val;
            length++;
            return true;
        }
    }
    bool insertAtLast(int val)
    {
        if(isFull())
        {      
            cout << "\nArray is full . No more value can be inserted .";
            return false;
        }
        else
        {
            int index = 0;
            while (this->array[index] != -9999)// while loop to find the index where junk value -9999 is located
            {
                index++;
            }
            this->array[index] = val;
            length++;
            return true;
        }
    }
    void display()
    {
        cout << endl;
        if (isEmpty())
            cout << "\nArray is empty \n";
        for (int i = 0; (i <= size - 1)&&(array[i]!=-9999); i++)
            cout << array[i] << "\t";
        cout << endl;
    }
    bool removeFromLast()
    {
        if (isEmpty())
            return false;

        int index = length - 1;
        array[index] = -9999;
        length--;
        return true;
    }
    bool removeFromStart()
    {
        if (isEmpty())
            return false;

        int i = 0;
        while (i<length)//shifting left
        {
            array[i] = array[i + 1];
            i++;
        }
        array[length-1] = -9999;//filling with junk value(-9999)
        length--;
        return true;
    }
    int searchByValue(int value)//will return index
    {
        if (!isEmpty())
        {
            for (int index = 0; index < length; index++)
            {
                if (array[index] == value)
                    return index;
            }
            cout << "\nNo match for this value\n";
            return -9999;//junk
        }
        else
        {
            cout << "\nArray is empty,returning junk \n";
            return -9999;//junk
        }

    }
    int searchByIndex(int index)
    {
        if (index >=length)
        {
            cout << "\nIndex out of bound,-9999 ";
            return -9999;
        }
        else
        {
            return array[index];
        }
    }
    void update(int val, int index)
    {
        if (isEmpty())
            cout << "\nArray is empty\n";
            if (index >= length)
            {
                cout << "\nIndex out of bound,-9999\n ";
            }
            else
                array[index] = val;

    }
};
int main()
{
    MyArray ma(20);
   
    for (int i = 1; i <= 10; i++)
    {
       ma.insertAtBegining(i);
       ma.insertAtLast(i);
    }
    ma.insertAtBegining(199);
    

    ma.display();
    ma.removeFromStart();
    cout << endl;
    ma.display();

    cout << "\nvalue at index 7 is " << ma.searchByIndex(7);
    cout << "\n index of 101 is " << ma.searchByValue(101);
    ma.update(4, 7);
    cout << "\nvalue at index 7 is " << ma.searchByIndex(7);


    cout << "\n length is " << ma.getLength();

    for (int i = 1; i <= 19; i++)
        ma.removeFromLast();

    ma.display();
}
