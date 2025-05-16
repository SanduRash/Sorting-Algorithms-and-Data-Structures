//Sandu Galbokka Hewa
// February 12
//Data Structures Project 1

#include <iostream>
#include <fstream>
#include <string>
#include <list>
//#include <cstdlib> 
#include <algorithm>
using namespace std;

string* arr; // Pointer to dynamically allocated array
int numElem; // Number of elements in the dataset

// Function prototypes for sorting algorithms
void merge(int lowest, int middle, int highest, string* arr);

void mergeSort(int lowest, int highest, string* arr);

void bubbleSort(int numElem, string* arr);

void quickSort(int begin, int numElem, string* arr);

void heapSort(string* arr, int lastNodeIndx, string* sortedArr);



int main(int argc, char * argv[])
{
  ifstream ifile(argv[1]);
  if (!ifile)
    {
      cout<< "Could not open file : "<<argv[1]<<endl;
      return 1;
    }

  // Determine sorting type from second argument
  string sortType;
  if (!argv[2])
    sortType = "sys";
  else
    sortType = argv[2];
    
// Check if we should print sorted array (third argument)
  bool printArr = false;
  if(argv[3])
    printArr = true;

  
  ifile >> numElem;
  
  
  if (sortType != "heap")// Sorting for non-heap algorithms
    {
      arr = new string[numElem];   // Read elements from file into the array
      for (int i = 0; i < numElem; i++)
	{
	  ifile >>arr[i];
	}

      // Apply the selected sorting algorithm
      if (sortType == "sys")
	{
	  sort(arr, arr+numElem); // Use built-in sort function
	}
      else if (sortType == "merge") // Merge Sort
	{
	  int lowest = 1;
	  mergeSort(lowest, numElem, arr);
	}
      else if (sortType == "bubble") // Bubble Sort
	{
	  bubbleSort(numElem, arr);
	}
      else if (sortType == "quick") // Quick Sort
	{
	  int lowest = 1;
	  quickSort(lowest, numElem, arr);
	}
          
    }
  else if (sortType == "heap")  // Heap Sort
    {
      string* heap = new string[numElem + 1];
      string hold;
      int parentIndex;
      int childIndex;
      string* sortedHeap=new string[numElem + 1];

      heap[0] = "null"; // Placeholder for 1-based indexing

      // Insert elements into heap
      for (int i = 1; i < numElem + 1; i++)
	{
	  ifile >>heap[i];
	  parentIndex = i/2;
	  childIndex = i;

	  // Place small heaps at top
	  while (!(parentIndex == 0) && (heap[childIndex] < heap[parentIndex]))
	    {
	      hold = heap[parentIndex];
	      heap[parentIndex] = heap[childIndex];
	      heap[childIndex] = hold;
	      childIndex = childIndex/2;
	      parentIndex = parentIndex/2;
	    }
	  
	}

      heapSort(heap, numElem, sortedHeap);

      
      if (printArr && (sortType == "heap"))
      {
	for (int i = 1; i < numElem+1; i++)
	  cout<<sortedHeap[i]<<endl;
      }
      
    }

  // Print sorted array if required (for non-heap sorts)
  if (printArr && !(sortType == "heap"))
    {
      for (int i = 0; i < numElem; i++)
	cout<<arr[i]<<endl;
    }

  
  return 0;
}

// Merges two sorted subarrays into one sorted array
void merge(int lowest, int middle, int highest, string* arr)
{
  int leftSize = middle - lowest + 1;
  int rightSize = highest - middle;

  // Temporary arrays for left and right halves
  string* leftarr = new string[leftSize];
  string* rightarr = new string[rightSize];

  for(int i=0; i<leftSize; i++)  // Copy elements to left array
    leftarr[i] = arr[lowest - 1 + i];

  for(int i=0; i<rightSize; i++)  // Copy elements to right array
    rightarr[i] = arr[middle + i];

  int i = 0;
  int j = 0;
  int k = lowest - 1;
  
  // Merge elements back into the original array in sorted order
  while(!(i == leftSize || j == rightSize))
    {
      if (leftarr[i] == rightarr[j])
	{
	  arr[k] = leftarr[i];
	  k++; i++;
	  arr[k] = rightarr[j];
	  k++; j++;
	}
      else if (leftarr[i] > rightarr[j])
	{
	  arr[k] = rightarr[j];
	  k++; j++;
	}
      else
	{
	  arr[k] = leftarr[i];
	  k++; i++;
	}

    }

  // Copy any remaining elements from left and right arrays
  while(!(i >= leftSize))
    {
      arr[k] = leftarr[i];
      k++; i++;
    }

  while(!(j >= rightSize))
    {
      arr[k] = rightarr[j];
      k++; j++;
    }
  
}



// Recursively sorts an array using merge sort
void mergeSort(int lowest, int highest, string* arr)
{
  
  if (lowest < highest)
    {
      int middle = (lowest + highest)/2 ;
     
      mergeSort(lowest, middle, arr);
      mergeSort(middle+1, highest, arr);
      merge(lowest, middle, highest, arr);
    }
  
 }


// Sorts an array using bubble sort
void bubbleSort(int numElem, string* arr)
{
    string hold;
    int numSwaps = 1;  // Counter to track swaps

    while (numSwaps != 0) {  // Keep sorting until no swaps occur
        numSwaps = 0;
        for (int i = 0; i < numElem - 1; i++) {
            if (arr[i] > arr[i + 1]) {  // Swap if elements are in the wrong order
                hold = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = hold;
                numSwaps++;
            }
        }
    }
}

void quickSort(int begin, int end, string* arr)
{ 
  if(begin < end)
    {
      
      int sizeOfArr = end - begin + 1;
      int randomIndex = begin + (rand() % sizeOfArr) ; // Pick a random pivot
      string pivot = arr[randomIndex - 1];

      // Partitioning step
      int l = 0;
      int m = 0;
      int r = 0;
      string* left = new string[sizeOfArr];
      string* right = new string[sizeOfArr];

      
     // Distribute elements into left, middle (pivot), and right arrays
      for (int i = begin-1; i<end; i++)
	{
	  if (arr[i] == pivot)
	    m++;
	  else if (arr[i] < pivot)
	    {
	      left[l] = arr[i];
	      l++;
	    }
	  else
	    {
	      right[r] = arr[i];
	  r++;
	    }
	}


      // Reassemble sorted array
      for (int i=0; i < l; i++)
	arr[i + begin -1] = left[i];
      
      for (int i = 0; i < m; i++)
	arr[i + begin + l -1] = pivot;

      for (int i = 0; i < r; i++)
	arr[i + begin + l + m - 1] = right[i];

      int pivotStart = begin + l;
      int pivotEnd = pivotStart + m - 1;
      
      quickSort(begin, pivotStart - 1, arr);
      quickSort(pivotEnd + 1, end, arr);
      
    }
}

void heapSort(string* arr, int numElem, string* sortedArr)
{
  int lastNodeIndx = numElem;
  int childIndx;
  int parentIndx;
  int minChildIndx;
  string hold;
  bool isParentMin;
  
  for(int i = 1; i<= numElem; i++)
    {
      isParentMin = false;
      sortedArr[i] = arr[1];// Move the smallest element to the sorted array
      arr[1] = arr[lastNodeIndx];  // Replace root with the last element
      lastNodeIndx--;
      
      parentIndx = 1;
      childIndx = parentIndx*2;

      
      while((childIndx <= lastNodeIndx) && !isParentMin)
	{

	  if (childIndx + 1 <= lastNodeIndx)
	    {
	      if((arr[parentIndx] >arr[childIndx]) || (arr[parentIndx] >arr[childIndx+1]) )
		{
		  if (arr[childIndx] < arr[childIndx+1])
		    minChildIndx = childIndx;
		  else 
		    minChildIndx = childIndx + 1;
		}
	      else
		isParentMin = true;
		
	    }
	  else
	    {
	      if (arr[parentIndx] >arr[childIndx])
		minChildIndx = childIndx;
	      else
		isParentMin = true;
	    }

	  // Restore heap property
	  if (!isParentMin)
	    {
	      hold = arr[parentIndx];
	      arr[parentIndx] = arr[minChildIndx];
	      arr[minChildIndx] = hold;
	      
	      parentIndx = minChildIndx;
	      childIndx = parentIndx*2;
	    }

	  
	}    
	
    }
    
}

