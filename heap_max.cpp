#include <iostream>
using namespace std;

// Creating the class 'myHeap'
class myHeap 
{
	private:
		int * data;
		int nextFreeSlot; // keeps track of the next free slot to insert a new element, -1 if array is full
		int size;

		// Function that returns the index of the left son of node 'i'
		int LeftSon(int i) // int 'i' is the object of the function, the parent of the son node
		{
			return (2*i + 1); // returning the index of the node
		}

		// Function that returns the index of the right son of node 'i'
		int RightSon(int i)// Returns the index of the right son of node i (2*i + 1) ; -1 if out of range
		{
		return (2*i + 2);	// returning the index of the node
		}

		// Function that returns the index of the parent of node 'i'
		int Parent(int i)
		{
			return (i - 1) / 2; // returning the index of the node
		}

		// Function that swaps the nodes
		int Swap(int i, int j) // swapping variable is used
		{
				int temp = data[i]; // swapping variable acts as a duplicate of one of the nodes and makes sure no data is lost
				data[i] = data[j]; // 'i' takes in the value of 'j'
				data[j] = temp;
				return 0;
		}

		// Function to change nodes upwards
		void heapUp(int i)
		{
		// case where the parent is less than the son
        if (i && data[Parent(i)] < data[i])
        {
            Swap(i, Parent(i));  // swapping 'i' and its parent
            heapUp(Parent(i)); // doing the same for the parent node
        }
    	}
	
		// Function to change nodes downwards
    	void heapDown(int i)
    	{
        	int left = LeftSon(i);
       	 	int right = RightSon(i);
        	int smallest = i;

        	if (left < size && data[left] < data[i]) 
			{
            	smallest = left;
        	}
 
        	if (right < size && data[right] < data[smallest]) 
			{
            	smallest = right;
        	}
		
        	if (smallest != i)
        	{
            	Swap(i, smallest);
            	heapDown(smallest); // repeat the same for the node
        	}
    	}
	
	public:

		// Function that creates the heap
		myHeap(int n)
		{
		    data = new int[n];
		    nextFreeSlot = 0;
			size = n;
		    
		}

		// Function that adds in a new element
		int push(int x)
		{
			// if the heap is full
			if (nextFreeSlot == -1)
			{
				return -1;
			}
			// if the heap is full
			else if (size == nextFreeSlot)
			{
				return -1;
			}
			// case where the heap is not full
			else
			{
				data[nextFreeSlot] = x; // 'x' goes into the next slot
				heapUp(nextFreeSlot); // that slots moves upwards in the heap
				nextFreeSlot++;
				
				return 1;
			}
		}

		// Function that removes elements from the heap
		int pop() 
		{
		    data[0] = data[nextFreeSlot-1];
			int temp = data[nextFreeSlot-1];
            nextFreeSlot--;

            heapDown(0);
		    return temp; 
		}
		
		// Function that displays the heap
		void print_heap()
		{
			cout << endl;
			for (int i = 0; i < nextFreeSlot; i++) // function repeats until the heap is finished
			{
				cout << "[" << data[i] << "] ";	
			}
			cout << endl;
		}
	
};
// Main function
int main() 
{
    myHeap heap(4); 
    heap.push(17);
    heap.push(9);
    heap.push(12);
    heap.push(19);

	heap.print_heap();
    return 0;
}