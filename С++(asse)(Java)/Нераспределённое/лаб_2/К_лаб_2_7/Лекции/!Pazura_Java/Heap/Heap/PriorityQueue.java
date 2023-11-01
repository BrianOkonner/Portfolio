public interface PriorityQueue {

    // Postcondition: the number of elements in this PriorityQueue
    //                has been returned.
    public int size();


    // Postcondition: true has been returned if this PriorityQueue is
    //                empty.  Otherwise, false has been returned.
    public boolean isEmpty();


    // Postcondition: element has been added to this PriorityQueue.
    //                The worstTime (n) is O (n),
    //                and averageTime (n) is constant.
    public void add (Object element);


    // Precondition: This PriorityQueue is not empty.
    // Postcondition: The smallest-valued element in this PriorityQueue
    //                has been returned.
    public Object getMin();


    // Precondition: This PriorityQueue is not empty.
    // Postcondition: The smallest-valued element in this PriorityQueue
    //                has been removed and returned. The worstTime (n)
    //                is O (log n).
    public Object removeMin();


} // class PriorityQueue
