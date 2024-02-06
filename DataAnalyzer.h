#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class DataAnalyzer {
	int* dataArray;														//points to dynamic array of integers
	int arraySize;														//size of array
public:
	DataAnalyzer(string filePath) {										//A constructor that takes the file path as a parameter and reads the data from the CSV file into the array
		ifstream file(filePath);										//open the file for reading
		
		if (file.is_open()) {											//check if the file is open			
			int count = 0;												//counter for number of lines in file
			string line;
			while (getline(file, line)) {
				count++;												//traverse file while incrementing line count
			}
			
			dataArray = new int[count];									//allocate memory for the dynamic array
			arraySize = count;											//assign line count to be the size of the array
			
			file.clear();												//reset the file pointer to the beginning
			file.seekg(0);
			
			int index = 0;												//read the data from the file into the array
			while (getline(file, line)) {
				dataArray[index] = stoi(line);							//convert the string to integer
				index++;
			}
			
			file.close();												//close the file
		}

		else {															//print an error message if the file is not open			
			cout << "Error: Unable to open file " << filePath << endl;
		}
	}

	~DataAnalyzer() {													//destructor 		
		delete[] dataArray;												//delete the dynamic array
	}
	
	int* getDataArray() {												//getter for DataArray
		return dataArray;
	}

	int getArraySize() {												//getter for ArraySize
		return arraySize;
	}





	void printDataArray() {												//print the data array
		for (int i = 0; i < arraySize; i++) {							
			cout << dataArray[i] << endl;								//traverse the array printing each element
		}		
	}

	float getMean() {													//calculate the mean of the data
		float sum = 0;													//stores sum of elements
		for (int i = 0; i < arraySize; i++) {
			sum += dataArray[i];										//add each element to the sum
		}
		float mean = sum / arraySize;									//ddivide the sum by arraySize to get the mean
		return mean;													//returns the mean
	}

	float getMedian() {													//calculate the median of the data
		int* sortedArray = insertionSort(dataArray, arraySize);			//sort the data using insertionSort()
																		//check if the array size is even or odd  
		if (arraySize % 2 == 0) {										//array size is even, the median is the average of the middle two values		
			int mid1 = arraySize / 2;									//index of the first middle value
			int mid2 = mid1 - 1;										//index of the second middle value
			float median = (sortedArray[mid1]+sortedArray[mid2]) / 2.0; //average of the middle two values
			return median;
		}
		else {															//array size is odd, the median is the middle value
			int mid = arraySize / 2;									//index of the middle value
			float median = sortedArray[mid];							//middle value
			return median;
		}
	}

	float getMode() {													//calculate the mode of the data
		int* sortedArray = insertionSort(dataArray, arraySize);			//sort the data using insertionSort()
																		//initialize variables to store the current mode and its frequency
		float mode = sortedArray[0];									//first element is assumed to be mode initially
		int frequency = 1;												//the frequency of the first element is 1
																		//initialize variables to store the maximum frequency and its corresponding value
		int maxFrequency = 1;											//the maximum frequency is 1 by default
		float maxFrequencyValue = mode;									//the value with the maximum frequency is the mode by default

		for (int i = 1; i < arraySize; i++) {							//loop through the array from the second element to the end
																		//compare the current element with the previous element
			if (sortedArray[i] == sortedArray[i - 1]) {				
				frequency++;											//current element is equal to the previous element, increment the frequency
			}
			else {			
				frequency = 1;											//the current element is different from the previous element, reset the frequency to 1
			}

			if (frequency > maxFrequency) {								//check if frequency is greater than the maximum frequency				
				maxFrequency = frequency;								//frequency is greater than the maximum frequency, update the maximum frequency and its value
				maxFrequencyValue = sortedArray[i];
			}
		}
		return maxFrequencyValue;										//return the value with the maximum frequency as the mode
	}

	float getStandardDeviation() {										//calculate the standard deviation of the data				
		float variance = getVariance();									//calculate the variance using getVariance()
		float standardDeviation = sqrt(variance);						//calculate the standard deviation by taking the square root of the variance
		return standardDeviation;										//return the standard deviation
	}

	float getVariance() {												//calculate the variance of the data		
		float mean = getMean();											//calculate the mean using getMean()		
		float sum = 0;													//initialize a variable to store the sum of the squared differences from the mean
		
		for (int i = 0; i < arraySize; i++) {							//loop through the array and calculate the squared difference for each element
			float difference = dataArray[i] - mean;						//difference between the element and the mean
			float squaredDifference = difference * difference;			//squared difference
			sum += squaredDifference;									//add the squared difference to the sum
		}

		float variance = sum / arraySize;								//calculate the variance by dividing the sum by the array size
		return variance;												//return the variance
	}

	int* bubbleSort(int* arr, int size) {								//sort the data using bubble sort
		int* copy = new int[size];										//create copy of the array to avoid modification to original array
		for (int i = 0; i < size; i++) {
			copy[i] = arr[i];
		}
	
		bool swapped;													//flag to indicate whether any swaps were made in current iteration
		
		for (int i = 0; i < size - 1; i++) {							//loop through the array from the beginning to the end
			
			swapped = false;											//set the flag to false initially
			
			for (int j = 0; j < size - i - 1; j++) {					//loop through the array from the beginning to the end - i - 1				
				if (copy[j] > copy[j + 1]) {							//compare the current element with the next element					
					int temp = copy[j];
					copy[j] = copy[j + 1];								//swap them if they are out of order
					copy[j + 1] = temp;					
					swapped = true;										//set flag to true to indicate that a swap was made
				}
			}
				
			if (!swapped) {												//if no swaps were made this iteration, the array is sorted and we can break out of the loop
				break;
			}
		}

		return copy;													//return the sorted copy
	}

	int* insertionSort(int* arr, int size) {							//sort the data using insertion sort
		int* copy = new int[size];										//create copy of the array to avoid modification to original array
		for (int i = 0; i < size; i++) {
			copy[i] = arr[i];
		}

		for (int i = 1; i < size; i++) {								//loop through the array from the second element to the end			
			int temp = copy[i];											//store the current element in a temporary variable
			int j = i - 1;												//initialize a variable to store the index of the previous element

			while (j >= 0 && copy[j] > temp) {							//loop through the sorted part of the array from right to left
				copy[j + 1] = copy[j];									//shift the larger element to the right
				j--;													//decrement the index of the previous element
			}

			copy[j + 1] = temp;											//insert the current element into its correct position
		}

		return copy;													//return the sorted copy
	}
	
	int binarySearch(int* arr, int left, int right, int key) {			//binary search function for binary search		
		if (left > right) {												//check if the array is empty or not			
			return -1;													//the array is empty, return -1 to indicate that the key was not found
		}
		
		int mid = (left + right) / 2;									//find the middle index of the array

		if (key == arr[mid]) {											//compare the key with the middle element			
			return mid;													//the key is equal to the middle element, return its index
		}
		else if (key < arr[mid]) {										//the key is smaller than the middle element, search in the left half of the array			
			return binarySearch(arr, left, mid - 1, key);
		}
		else {															//the key is larger than the middle element, search in the right half of the array
			return binarySearch(arr, mid + 1, right, key);
		}
	}
};