import java.util.*;

class Entry implements Comparable {

    int freq;
    String code;
    char id;
    Entry left,
          right,
          parent;

    public int compareTo (Object entry) {

        return freq - ((Entry)entry).freq;

    } // compareTo


} // class Entry
