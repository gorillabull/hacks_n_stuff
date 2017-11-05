// 302Assign5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <time.h>
using namespace std;





class event
{
public:
	int arrival; 
	int departure;
	string ingate;
	string outgate;
	int flightNum;
	int gateNum;
	event()
	{
		arrival = 0;
		departure = 0;
		flightNum = 0;
		gateNum = 0;
	}
private:
};

event nullevent;

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H


#include <vector>
using namespace std;

// BinaryHeap class
//
// CONSTRUCTION: with an optional capacity (that defaults to 100)
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// deleteMin( minItem )   --> Remove (and optionally return) smallest item
// event findMin( )  --> Return smallest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************
// Throws UnderflowException as warranted


class BinaryHeap
{
public:
	explicit BinaryHeap(/*int capacity = 100*/)
		: currentSize(0)
	{
	}

	/*	explicit BinaryHeap(const vector<event> & items)
	: array(items.size() + 10), currentSize(items.size())
	{
	for (int i = 0; i < items.size(); i++)
	array[i + 1] = items[i];
	buildHeap();
	}
	*/

	bool isEmpty() const
	{
		return currentSize == 0;
	}

	/**
	* Find the smallest item in the priority queue.
	* Return the smallest item, or throw Underflow if empty.
	*/
	const event & findMin() const
	{

		if (!isEmpty())
		{
			return array[1];
		}
		return nullevent;
	}
	/**
	* Insert item x, allowing duplicates.
	*/
	void insert(const event & x)
	{
		/*if (currentSize == array.size() - 1)
		array.resize(array.size() * 2);
		*/

		// Percolate up
		int hole = ++currentSize;
		for (; hole > 1 && x.arrival < array[hole / 2].arrival; hole /= 2)
			array[hole] = array[hole / 2];
		array[hole] = x;
	}

	/**
	* Remove the minimum item.
	* Throws UnderflowException if empty.
	*/
	void deleteMin()
	{


		array[1] = array[currentSize--];
		percolateDown(1);
	}

	/**
	* Remove the minimum item and place it in minItem.
	* Throws Underflow if empty.
	*/
	void deleteMin(event & minItem)
	{


		minItem = array[1];
		array[1] = array[currentSize--];
		percolateDown(1);
	}

	void makeEmpty()
	{
		currentSize = 0;
	}

private:
	int                currentSize;  // Number of elements in heap
	event array[1000];        // The heap array

	/**
	* Establish heap order property from an arbitrary
	* arrangement of items. Runs in linear time.
	*/
	void buildHeap()
	{
		for (int i = currentSize / 2; i > 0; i--)
			percolateDown(i);
	}

	/**
	* Internal method to percolate down in the heap.
	* hole is the index at which the percolate begins.
	*/
	void percolateDown(int hole)
	{
		int child;
		event tmp = array[hole];

		for (; hole * 2 <= currentSize; hole = child)
		{
			child = hole * 2;
			if (child != currentSize && array[child + 1].arrival < array[child].arrival)
				child++;
			if (array[child].arrival < tmp.arrival)
				array[hole] = array[child];
			else
				break;
		}
		array[hole] = tmp;
	}
};

#endif


class BinaryHeap_depart
{
public:
	explicit BinaryHeap_depart(/*int capacity = 100*/)
		: currentSize(0)
	{
	}

	/*	explicit BinaryHeap(const vector<event> & items)
	: array(items.size() + 10), currentSize(items.size())
	{
	for (int i = 0; i < items.size(); i++)
	array[i + 1] = items[i];
	buildHeap();
	}
	*/

	bool isEmpty() const
	{
		return currentSize == 0;
	}

	/**
	* Find the smallest item in the priority queue.
	* Return the smallest item, or throw Underflow if empty.
	*/
	const event & findMin() const
	{
		if (!isEmpty())
		{
			return array[1];
		}
		return nullevent;
	}
	/**
	* Insert item x, allowing duplicates.
	*/
	void insert(const event & x)
	{
		/*if (currentSize == array.size() - 1)
		array.resize(array.size() * 2);
		*/

		// Percolate up de
		int hole = ++currentSize;
		for (; hole > 1 && x.departure < array[hole / 2].departure; hole /= 2)
			array[hole] = array[hole / 2];
		array[hole] = x;
	}

	/**
	* Remove the minimum item.
	* Throws UnderflowException if empty.
	*/
	void deleteMin()
	{


		array[1] = array[currentSize--];
		percolateDown(1);
	}

	/**
	* Remove the minimum item and place it in minItem.
	* Throws Underflow if empty.
	*/
	void deleteMin(event & minItem)
	{


		minItem = array[1];
		array[1] = array[currentSize--];
		percolateDown(1);
	}

	void makeEmpty()
	{
		currentSize = 0;
	}

private:
	int                currentSize;  // Number of elements in heap
	event array[1000];        // The heap array

	/**
	* Establish heap order property from an arbitrary
	* arrangement of items. Runs in linear time.
	*/
	void buildHeap()
	{
		for (int i = currentSize / 2; i > 0; i--)
			percolateDown(i);
	}

	/**
	* Internal method to percolate down in the heap.
	* hole is the index at which the percolate begins.
	*/
	void percolateDown(int hole)
	{
		int child;
		event tmp = array[hole];

		for (; hole * 2 <= currentSize; hole = child)
		{
			child = hole * 2;
			if (child != currentSize && array[child + 1].departure < array[child].departure)
				child++;
			if (array[child].departure < tmp.departure)
				array[hole] = array[child];
			else
				break;
		}
		array[hole] = tmp;
	}
};






int delay()
{//returns some number of minutes if there will be a delays 
	
	
	if ((std::rand() % 100 + 1)< 40) //40% to add some delay 
	{
		//Math.floor(Math.random() * (end - start + 1) + start);
		int add = std::rand() % 20 + 20; //add delay betvveen 20 and 40 
		return add;
	}
	return 0;
}


void fillEvents(BinaryHeap & h)
{
		int flightnum = 999;
		int ariv = 1;

	for (int i = 1; i <= 24; i++)
	{
		for (int  j = 1; j <=60; j++)
		{
			//add all events to the q for 24 hours 
			if (j==2)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv+ 60 + delay();
				//specific
				e.ingate = "LAX";
				e.outgate = "JFK";
				e.flightNum = flightnum++;

				h.insert(e);
			}

			if (j == 4)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "IAH";
				e.outgate = "MSP";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 11)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "SJC";
				e.outgate = "BOS";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 17)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "SFO";
				e.outgate = "ORD";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 28)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "TUL";
				e.outgate = "ONT";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 37)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "BNA";
				e.outgate = "SEA";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 49)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "HOS";
				e.outgate = "DEN";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 3)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "SMF";
				e.outgate = "RDU";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 9)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "ABQ";
				e.outgate = "ATL";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 14)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "PHB";
				e.outgate = "MIA";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 19)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "SLC";
				e.outgate = "AUS";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 33)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "DCA";
				e.outgate = "LAS";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 44)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "MAF";
				e.outgate = "AMA";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			if (j == 55)
			{
				//generic
				event e;
				e.arrival = ariv;
				e.departure = ariv + 60 + delay();
				//specific
				e.ingate = "EPL";
				e.outgate = "MEM";
				e.flightNum = flightnum++;

				h.insert(e);
			}
			ariv++;

		}
	}
}

int main()
{
	using namespace std;
	std::srand((unsigned)time(NULL)); //seed the rng 

	BinaryHeap heap;
	BinaryHeap_depart departs;

	fillEvents(heap);

	int elapsed = 1; 
	stack<int> availgates;

	std::cout << "enter number of gates for the simulation" << endl;
	
	int n = 0; //#gates
	std::cin >> n;
	for (int  i = 1; i <= n; i++)
	{
		availgates.push(i);
	}
	

	while (elapsed <= 60*24)
	{
		event occur = heap.findMin();

		if (occur.arrival == elapsed) //a flight arrives 
		{
			if (availgates.size() >= 1)
			{
				occur.gateNum = availgates.top();
				availgates.pop();
				departs.insert(occur); //add the flight to the departure q
				std::cout << "Flight number# " << occur.flightNum << " from " << occur.ingate << " to " << occur.outgate << " arrived and is expected to depart in 60 minutes" << endl;
				heap.deleteMin();
			}
			else
			{
				std::cout << "airport is full" << endl;
				break;
				return 0;
			}

		}

		//handle departures 
		
		event isDepart=departs.findMin();

		if (isDepart.departure==elapsed)//is anything departing this minute
		{
			availgates.push(isDepart.gateNum); //free the gate 
			departs.deleteMin();
			std::cout << "flight number " << isDepart.flightNum << " has departed " << endl;
			isDepart = departs.findMin();//check a second time 
			while (isDepart.departure == elapsed)	//see if any other flights depart at this time too 
			{
				 isDepart = departs.findMin();
				if (isDepart.departure == elapsed)//is anything departing this minute
				{
					availgates.push(isDepart.gateNum); //free the gate 
					departs.deleteMin();
				}
			}
		}
		elapsed++;
	}
	

	int x;
	std::cin >> x;
	return 0;
}

