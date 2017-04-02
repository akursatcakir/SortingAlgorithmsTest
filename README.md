# SortingAlgorithmsTest
Operation time tests for sorting algorithms

You can test algorithms operation time on different array length and orders

Algorithms;
 - Selection Sort
 - Insertion Sort
 - Bubble Sort
 - Merge Sort
 - Quick Sort
 - Heap Sort

Test orders;
 - Random Sorted
 - Reverse Sorted
 - Sorted
 
Array lengths;
 - 10.000
 - 20.000
 - 30.000
 
You can change test lengths, orders, algorithms on SortingTest/SortingTest.cpp test() function;

#### For change algorithms;

 	test.algorithms.insert(tester::algorithm(algorithm_name, pointer_to_function));
- algorithm_name: string, Algorithm's name
- pointer_to_function: function pointer, Algorithm's entry function

Algorithm entry function must have void return type and 2 parameters;
+ first is int pointer for pass array
+ second is unsigned int for pass array length

ex:

	test.algorithms.insert(tester::algorithm("Selection", &sorting::selection));

#### For change array creators;

	test.creators.insert(tester::creator(order_name, pointer_to_array_creator_function));
- order_name: string, Order type's name
- pointer_to_array_creator_function: function pointer, Array creator function

Array creator function must have int pointer return type, returns created array and 1 parameters;
+ parameter is unsigned int for pass array length to be created

ex:

	test.creators.insert(tester::creator("Rastgele", &create::random));

#### For change lengths;

	test.counts.push_back(array_length);
- array_length: unsigned int, Array's length to be created for test.

ex:

	test.counts.push_back(10000);
	

Array creator functions on SortingTest/create.cpp and its header file is SortingTest/create.h
	
Algorithm functions on SortingTest/sorting.cpp and its header file is  SortingTest/sorting.h

You can send pull requests, thanks.
