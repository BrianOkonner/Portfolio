import java.util.*;

public class Heap implements PriorityQueue {

    protected int size;

    protected Object[] heap;

    protected Comparator comparator;


    // Postcondition: This PriorityQueue has been initialized.
    public Heap() {

        final int DEFAULT_INITIAL_CAPACITY = 11;
        
        heap = new Object [DEFAULT_INITIAL_CAPACITY];

    } // default constructor


    // Postcondition: This Heap has been initialized, and
    //                comp will be used for element comparisons.
    public Heap (Comparator comp) {

        this();
        comparator = comp;

    } // constructor with Comparator parameter


    // Postcondition: the number of elements in this Heap
    //                has been returned.
    public int size() {

        return size;

    } // method size


    // Postcondition: true has been returned if this Heap is
    //                empty.  Otherwise, false has been returned.
    public boolean isEmpty() {

        return size == 0;

    } // method isEmpty


    // Postcondition: element has been added to this Heap.
    //                The worstTime (n) is O (n),
    //                and averageTime (n) is constant.
    public void add (Object element) {

        if (++size == heap.length) {

            Object[] newHeap = new Object [2 * heap.length];
            System.arraycopy (heap, 0, newHeap, 0, size);
            heap = newHeap;

        } // if

        heap [size - 1] = element;
        percolateUp();
    } // method add


    // Precondition: This Heap is not empty.
    // Postcondition: The smallest-valued element in this Heap
    //                has been returned.  The worstTime (n) is constant.
    public Object getMin() {

        if (size==0)
            throw new NoSuchElementException ("Priority queue empty.");
        return heap [0];

    } // method getMin


    // Precondition: This Heap is not empty.
    // Postcondition: The smallest-valued element in this Heap
    //                has been removed and returned. The worstTime (n)
    //                is O (log n).
    public Object removeMin() {

        if (size==0)
            throw new NoSuchElementException ("Priority queue empty.");
        Object minElem = heap [0];
        heap [0] = heap [size - 1];
        heap [--size] = minElem;
        percolateDown (0);
        return minElem;

    } // method removeMin


    // Precondition: heap is a heap except, possibility, at index size - 1.
    // Postcondition: heapity has been restored to heap.
    protected void percolateUp(){

        int child = size - 1,
            parent;

        Object temp;

        while (child > 0) {

            parent = (child - 1) / 2;
            if (compare (heap [parent], heap [child]) <= 0)
                break;
            temp = heap [parent];
            heap [parent] = heap [child];
            heap [child] = temp;
            child = parent;

        } // while

    } // method percolateUp


    // Precondition: the complete binary tree rooted at start is a
    //               heap except, possibly, at index start.
    // Postcondition: heapity has been restored to heap
    protected void percolateDown (int start) {

        int child,
            parent = start;

        Object temp;

        while ((child = 2 * parent + 1) < size) {

            if (child < size-1 && compare (heap [child], heap [child+1]) > 0)
                child++; // child indexes smallest child
            if (compare (heap [parent], heap [child]) <= 0)
                break;
            temp = heap [child];
            heap [child] = heap [parent];
            heap [parent] = temp;
            parent = child;

        } // while

    } // method percolateDown


    // Postcondition: an int < 0, == 0 or > 0 has been returned,
    //                according to whether elem1 is less than,
    //                equal to or greater than elem2.
    protected int compare (Object elem1, Object elem2) {

	      return (comparator==null ? ((Comparable)elem1).compareTo(elem2)
				                         : comparator.compare (elem1, elem2));

    } // method compare

    public void heapSort (Object[ ] a) {

		    Object temp;

	 	    int length = a.length,
		        i;

		    heap = a;
        size = length;
		    for (i = length / 2 - 1; i >= 0; i--)
			      percolateDown (i);
		    while (size > 0)
			      removeMin( );
		    for (i= 0; i < length / 2; i++) {

			      temp = heap [i];
			      heap [i] = heap [length - i - 1];
			      heap [length - i - 1] = temp;

		    } // reversing heap
    System.out.println ("length = " + length);
    for (i = 0; i < length; i++)
    System.out.print (heap [i]);
	  } // method heapSort


} // class Heap
