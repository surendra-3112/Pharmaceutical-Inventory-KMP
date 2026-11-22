# Pharmaceutical-Inventory-KMP

# Pharmaceutical Inventory Batch Tracking System

## About the Project
This project implements a Pharmaceutical Inventory Batch Tracking System using the Knuth-Morris-Pratt (KMP) string matching algorithm in C.

It helps search medicine batch numbers and identify all medicine records containing the required batch number.

## Features
- Accepts multiple medicine records.
- Searches for a particular batch number.
- Uses the KMP algorithm for pattern matching.
- Displays all matching medicine IDs.
- Counts the total matching records.

## Algorithm Used
Knuth-Morris-Pratt (KMP) Algorithm

## Programming Language
C

## Time Complexity
- LPS Construction: O(m)
- Searching: O(n + m) per record
- Overall: O(N × (n + m))

## How to Run

Compile:
```bash
gcc medicine_batch_tracking.c -o medicine
```

Run:
```bash
./medicine
```

For Windows:
```bash
medicine.exe
```

## Author
Y Surendra Reddy
