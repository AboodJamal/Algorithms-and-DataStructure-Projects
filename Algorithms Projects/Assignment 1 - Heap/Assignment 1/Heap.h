#include<iostream>
#include <iomanip> 
using namespace std;

class Heap
{
private:
	double* arrHeap;
	int cap;
	int n;
	int heapType; // 1 for max , 0 for min
	void resize();// same idea of the vector's function
public:
	// the default heap is Max-Heap .. heapType=1
	Heap(const int heapType1 = 1, int cap1 = 10) { arrHeap = new double[cap1]; heapType = heapType1;  cap = cap1;  };
	bool empty() const;
	void insert(const int& item); // insert withsaving the heap consistant
	void heapDelete();// remove the top value
	void heapify(); // works with shiftDown to keep the heap heaped
	void shiftDown(int index , int size);
	void shiftUp(int index, int size);
	int size() const;
	void typeChanger(); // change the heap type 

	void printHeap() const;

	void printChildren(int value)
	{
		for (int i = 0; i < n; i++)
		{
			if (arrHeap[i] == value)
			{
				if (i*2 +1 >=n )
				{
					cout << arrHeap[i] << " has no children"<<endl;
				}
				else
				{
					cout << arrHeap[i*2 +1]<<" ";
					if (i * 2 + 2 < n) 
					{
						cout << arrHeap[i * 2 + 2];   
					}
				}
				break;
			}
		}
		cout << endl;
	}

	void heapSort()
	{
		heapType = 1;
		heapify();
		for (int i = n-1; i >= 1; i--)
		{
			swap(arrHeap[0], arrHeap[i]);
			shiftDown(0,i-1);
		}
		if (arrHeap[0] > arrHeap[1])
			swap(arrHeap[0], arrHeap[1]);
	}

	void swap(double &v1 , double &v2)
	{
		double temp = v1;
		v1 = v2;
		v2 = temp;
	}

	
};


void Heap::resize()
{
	cap *= 2;
	double* k = new double[cap];
	for (int i = 0; i < n; i++)
		k[i] = arrHeap[i];
	delete[]arrHeap;
	arrHeap = k;
}
bool Heap::empty() const
{
	return n <= 0;
}
int Heap::size() const
{
	return n;
}
void Heap::insert(const int& item)
{
	// if the array is full
	if (n >= cap)
		resize();
	if (heapType == 1) // if it's min-heap
	{
		int index = n;

		while (index > 0 && item > arrHeap[(index-1) / 2])
		{
			arrHeap[index] = arrHeap[(index-1) / 2 ];
			index= (index - 1) / 2; 
		}
		n++;
		arrHeap[index] = item;
		return;
	}
	else // if it's min-heap
	{
		int index = n; 

		while (index > 0 && item < arrHeap[(index - 1) / 2])
		{
			arrHeap[index] = arrHeap[(index - 1) / 2];
			index = (index - 1) / 2;
		}
		n++;
		arrHeap[index] = item;
		return;
	}

}

void Heap::shiftDown(int index, int last)
{
	double temp = arrHeap[index];
	bool exit = false;
	while ((2*index +1)<= last-1 && !exit)
	{
		int LC_index = 2 * index + 1; // Left Child Index
		if (LC_index+1 < last && arrHeap[LC_index] < arrHeap[LC_index+1])
		{
			LC_index += 1;
		}
		if (arrHeap[LC_index] > temp)
		{
			arrHeap[index] = arrHeap[LC_index]; 
			index = LC_index; 
		}
		else
		{
			// exiting
			exit = true;
		}

	}
	arrHeap[index] = temp;	
}
void Heap::shiftUp(int index, int last)	
{
	double temp = arrHeap[index];
	bool exit = false;
	while ((2 * index + 1) <= last-1 && !exit)
	{
		int LC_index = 2 * index + 1; // Left Child Index
		if (LC_index + 1 < last  && arrHeap[LC_index] > arrHeap[LC_index + 1])
		{
			LC_index += 1;
		}
		if (arrHeap[LC_index] < temp)
		{
			arrHeap[index] = arrHeap[LC_index];
			index = LC_index;
		}
		else
		{
			// exiting
			exit = true;
		}

	}
	arrHeap[index] = temp;
}

void Heap::heapify()
{
	if (heapType == 1)
	{
		for (int i = (n / 2) - 1; i >= 0; i--) // n / 2 - 1   the last internal node ( node that has at least one child )
			{
				shiftDown(i, n);
			}
		return;
	}
	else if(heapType==0)
	{
		for (int i = (n / 2) - 1; i >= 0; i--) // n / 2 - 1   the last internal node ( node that has at least one child )
		{
			shiftUp(i, n); 
		}
		return;
	}
	
}

void Heap::typeChanger()
{
	if (heapType == 1)
	{
		heapType = 0;
		heapify();
		return;
	}
	else if (heapType==0)
	{
		heapType = 1; 
		heapify();  
		return;
	}
}

void Heap::heapDelete()
{
	arrHeap[0] = arrHeap[n - 1];
	n--;
	if(heapType==1)
		shiftDown(0,n);
	else 
		shiftUp(0, n);

}

void Heap:: printHeap() const
{
	int level = 0;
	int itemsInLevel = 1;
	for (int i = 0; i < n; i++)
	{
		cout << arrHeap[i] << " ";
	}
	cout << endl;
}