# Sorting Algorithms and Data Structures

## Project Overview
This project demonstrates an analysis and comparison of multiple sorting algorithms by measuring their execution times over different data sets. It was designed for CSC36000 to reinforce understanding of sorting algorithms and performance evaluation.

The program accepts a file of strings and sorts them using one of the following methods:

- Bubble Sort
- Merge Sort
- Quick Sort
- Heap Sort
- System/Library Sort

It also optionally prints the sorted output and can be benchmarked using system tools (time on Unix, Measure-Command in PowerShell).

## Objectives
- Implement and compare common sorting algorithms 
- Work with C++ data structures
- Collect performance data and plot runtime graphs
- Analyze time complexity with reference to theoretical bounds:
  - 𝑂(𝑛^2)
  - 𝑂(𝑛log⁡𝑛)

## How to run
Command Line Usage
```bash
g++ -std=c++17 -o project1 project1_Sandu.cpp
```
Timing the Program
- On Linux/macOS:
```bash
  time ./project1 rand/rand25.txt merge
```

## Runtime Graphs

### Random Data Set
[Random Data Plot](images/forRandDataSets.pdf)

### Sorted Data Set
[Sorted Data Plot](images/forSRTDataSets.pdf)


