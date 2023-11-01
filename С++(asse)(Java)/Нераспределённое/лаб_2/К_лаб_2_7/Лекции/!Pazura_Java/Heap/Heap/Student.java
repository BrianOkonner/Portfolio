import java.util.*;

public class Student implements Comparable {

    protected String name;

    protected double GPA;


    // Postcondition: this Student has been initialized from s.
    public Student (String s) {

        StringTokenizer tokens = new StringTokenizer (s);

        name = tokens.nextToken();
        GPA = Double.parseDouble (tokens.nextToken());

    } // constructor

    
    // Postcondition: an int <, == or > 0 has been returned depending
    //                on whether this Student's GPA is less than, equal
    //                to or greater than o1's GPA.
    public int compareTo (Object o1) {

        if (GPA < ((Student)o1).GPA)
            return -1;
        if (GPA ==((Student)o1).GPA)
            return 0;
        return 1;

    } // method compareTo

    
    // Postcondition: A string representing the student has been returned.
    public String toString() {

        return name + "  " + GPA;

    } // method toString


} // class Student
