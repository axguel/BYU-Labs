/*
 * QSTester.cpp
 *
 *  Created on: Feb 17, 2016
 *      Author: aguel
 */





#include "QSTester.h"
#include <sstream>

//initializes
QSTest::QSTest()
{
    myArray = NULL;
    current_size = 0;
    total_size = 0;
}
//this clears all the memory
QSTest::~QSTest()
{
    clear();
}

//creates an array if the capacity is not 0
bool QSTest::createArray(int capacity)
{
    if (capacity < 1)
    {
        return false;
    }
    else
    {
        clear();
        myArray = new int[capacity];
        total_size = capacity;
        return true;
    }
}

//clears the entire array and sets values back to 0
void QSTest::clear()
{
    if (myArray != NULL)
    {
        delete[] myArray;
        myArray = NULL;
        current_size = 0;
        total_size = 0;
    }
}

//swaps the first and second values in the array
void QSTest::swap(int first, int second)
{
    int temp = myArray[first];
    myArray[first] = myArray[second];
    myArray[second] = temp;
}

//sorts the elements of the erray and does nothing when it is empty
void QSTest::sortAll()
{

    int last = current_size -1;
    if (current_size > 1)
    {
        sort(0, last);
    }
}

//this sorts the array
void QSTest::sort(int left, int right)
{
    if (right - left == 1)
    {
        if (myArray[right] > myArray[left])
        {
            return;
        }
        else
        {
            swap(right, left);
            return;
        }
    }

    if (right == left)
    {
        return;
    }

    if (left < 0 || right > current_size - 1 || right < left || left > right)
    {
        return;
    }

    int piv= medianOfThree(left, right);
    int newInd = partition(left, right, piv);
    sort(left, newInd - 1);
    sort(newInd + 1, right);
}


int QSTest::medianOfThree(int left, int right)
{//makes sure it is a valid array
    if (current_size < 0)
    {
        return -1;
    }
    if (left > right || left < 0 || right < left || right > current_size - 1 || left == right)
    {
        return -1;
    }
//calculates the average of the two indices
    int middle = (left + right) / 2;
//sorts the values at the left, middle, or right
    if (myArray[left] > myArray[middle])
    {
        swap(left, middle);
    }
    if (myArray[middle] > myArray[right])
    {
        swap(right, middle);
    }
    if (myArray[left] > myArray[middle])
    {
        swap(left, middle);
    }

    return middle;
}


int QSTest::partition(int left, int right, int pivotIndex)
{//checks for a valid array
    if (myArray == NULL)
    {
        return -1;
    }

    if ((current_size < 0) || (total_size <= 0))
    {
        return -1;
    }
    if ((left < 0) || (right < 0))
    {
        return -1;
    }
    if ((right > current_size - 1))
    {
        return -1;
    }
    if (!(left < right))
    {
        return -1;
    }
    if ((!(pivotIndex <= right)) || (!(pivotIndex >= left)) )
    {
        return -1;
    }
//calls swap to switch places of certain pivots
    swap(right, pivotIndex);
    int leftcopy = left;
    int rightcopy = right - 1;


//calculates which is emaller so it can pivot the correct one
    while (leftcopy < rightcopy)
    {
        while ((myArray[leftcopy] < myArray[right]))
        {
            leftcopy++;
        }

        while ((myArray[rightcopy] > myArray[right]))
        {
            rightcopy--;
        }

        if (leftcopy < rightcopy)
        {
            swap(leftcopy, rightcopy);
        }
    }

    if (leftcopy >= rightcopy)
    {
        swap(leftcopy, right);
        return leftcopy;
    }

    return leftcopy;
}

//prints out the array with commas and everything
string QSTest::getArray()
{
    stringstream ss;
    if (current_size == 0)
    {
        return "";
    }
    for (int i=0; i < current_size; i++)
    {
        if (i != current_size - 1)
        {
            ss << myArray[i] << ",";
        }
        else
        {
            ss << myArray[i];
        }
    }

    return ss.str();
}


int QSTest::getSize()
{
    return current_size;
}

//adds the value at the end of the array and does so unless the array is filled
void QSTest::addToArray(int value)
{
    if (current_size != total_size)
    {
        myArray[current_size] = value;
        current_size++;
    }
}


