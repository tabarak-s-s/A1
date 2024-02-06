#include "pch.h"
#include <gtest/gtest.h>
#include "DataAnalyzer.h"




// Question 1: Data Analyzer

TEST(DataAnalyzer, Constructor1) {
	DataAnalyzer dataAnalyzer("data.csv");
	EXPECT_EQ(30, dataAnalyzer.getArraySize());
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, Constructor2) {
	DataAnalyzer dataAnalyzer("data.csv");
	EXPECT_NE(15, dataAnalyzer.getArraySize());
	EXPECT_TRUE(true);
}


TEST(DataAnalyzer, Mean1) {
	DataAnalyzer dataAnalyzer("data.csv");
	float mean = 31.8;
	EXPECT_EQ(mean, dataAnalyzer.getMean());
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, Mean2) {
	DataAnalyzer dataAnalyzer("data.csv");
	float mean = 23.2;
	EXPECT_NE(mean, dataAnalyzer.getMean());
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, Median1) {
	DataAnalyzer dataAnalyzer("data.csv");
	float median = 30;
	EXPECT_EQ(median, dataAnalyzer.getMedian());
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, Median2) {
	DataAnalyzer dataAnalyzer("data.csv");
	float median = 20;
	EXPECT_NE(median, dataAnalyzer.getMedian());
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, Mode1) {
	DataAnalyzer dataAnalyzer("data.csv");
	float mode = 12;
	EXPECT_EQ(mode, dataAnalyzer.getMode());
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, Mode2) {
	DataAnalyzer dataAnalyzer("data.csv");
	float mode = 20;
	EXPECT_NE(mode, dataAnalyzer.getMode());
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, StandardDeviation1) {
	DataAnalyzer dataAnalyzer("data.csv");
	int standardDeviation = 22.1456;
	EXPECT_EQ(standardDeviation, (int)dataAnalyzer.getStandardDeviation());
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, StandardDeviation2) {
	DataAnalyzer dataAnalyzer("data.csv");
	int standardDeviation = 20.1456;
	EXPECT_NE(standardDeviation, (int)dataAnalyzer.getStandardDeviation());
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, Variance1) {
	DataAnalyzer dataAnalyzer("data.csv");
	int variance = 490.427;
	EXPECT_EQ(variance, (int)dataAnalyzer.getVariance());
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, Variance2) {
	DataAnalyzer dataAnalyzer("data.csv");
	int variance = 354.27;
	EXPECT_NE(variance, (int)dataAnalyzer.getVariance());
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, BubbleSort1) {
	DataAnalyzer dataAnalyzer("data.csv");
	int* bubbleSortedArray = dataAnalyzer.bubbleSort(dataAnalyzer.getDataArray(), dataAnalyzer.getArraySize());
	int* sortedArray = new int[30] { 3, 5, 6, 7, 8, 8, 11, 12, 12, 12, 13, 15, 23, 27, 29, 31, 32, 34, 35, 37, 43, 51, 55, 56, 57, 61, 64, 64, 68, 75};
	for (int i = 0; i < 30; i++) {
		EXPECT_EQ(sortedArray[i], bubbleSortedArray[i]);
	}
	EXPECT_TRUE(true);
}


TEST(DataAnalyzer, InsertionSort) {
	DataAnalyzer dataAnalyzer("data.csv");
	int* insertionSortedArray = dataAnalyzer.insertionSort(dataAnalyzer.getDataArray(), dataAnalyzer.getArraySize());
	int* sortedArray = new int[30] { 3, 5, 6, 7, 8, 8, 11, 12, 12, 12, 13, 15, 23, 27, 29, 31, 32, 34, 35, 37, 43, 51, 55, 56, 57, 61, 64, 64, 68, 75 };
	for (int i = 0; i < 30; i++) {
		EXPECT_EQ(sortedArray[i], insertionSortedArray[i]);
	}
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, BinarySearch1) {
	DataAnalyzer dataAnalyzer("data.csv");
	int* sortedArray = dataAnalyzer.insertionSort(dataAnalyzer.getDataArray(), dataAnalyzer.getArraySize());
	int key = 7;
	int index = dataAnalyzer.binarySearch(sortedArray, 0, dataAnalyzer.getArraySize() - 1, key);
	EXPECT_EQ(3, index);
	EXPECT_TRUE(true);
}

TEST(DataAnalyzer, BinarySearch2) {
	DataAnalyzer dataAnalyzer("data.csv");
	int* sortedArray = dataAnalyzer.insertionSort(dataAnalyzer.getDataArray(), dataAnalyzer.getArraySize());
	int key = 23;
	int index = dataAnalyzer.binarySearch(sortedArray, 0, dataAnalyzer.getArraySize() - 1, key);
	EXPECT_EQ(12, index);
	EXPECT_TRUE(true);
}

