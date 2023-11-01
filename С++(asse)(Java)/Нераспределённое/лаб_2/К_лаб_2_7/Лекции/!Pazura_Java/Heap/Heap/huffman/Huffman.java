import java.io.*;
import java.util.*;

public class Huffman implements Process {

    protected final int SIZE = 256;

    protected GUI gui;

    protected Entry[] leafEntries;

    protected Heap pq;

    protected String inFileName;

    protected BufferedReader fileReader;

    protected PrintWriter fileWriter;

    protected boolean readingInFileName;


    // Postcondition: This Huffman has been initialized.
    public Huffman() {

        final String IN_FILE_PROMPT =
            "In the Input line, please enter the name of the input file: ";

        gui = new GUI (this);
        readingInFileName = true;
        gui.print (IN_FILE_PROMPT);

    } // default constructor


    // Postcondition: The input line has been processed.
    public void processInput (String s) {

        final String OUT_FILE_PROMPT =
            "\n\nIn the Input line, please enter the name of the output file: ";

        final String CLOSE_WINDOW_PROMPT = "\n\nThe execution of this project "
            + "is complete. Please close this window when you are ready.";

        try {

            if (readingInFileName) {

                inFileName = s;
                fileReader = new BufferedReader (new FileReader (inFileName));
                gui.print (OUT_FILE_PROMPT);
                readingInFileName = false;

            } // if
            else {

                fileWriter = new PrintWriter (new FileWriter (s));
                createPQ();
                createHuffmanTree();
                calculateHuffmanCodes();
                saveToFile();
                gui.print (CLOSE_WINDOW_PROMPT);
                gui.freeze();

            } // else

        } // try
        catch (FileNotFoundException e) {

            gui.print (e.toString());

        } // catch FileNotFoundException
        catch (IOException e) {

            gui.print (e.toString());

        } // catch IOException

    } // method processInput


    // Postcondition: The pq has been created from info in the input file.
    public void createPQ() throws IOException {

        final String DEFAULT_TOTAL =
             "\nIf we use a fixed-length number of bits per character, " +
             "the message size in bits is ";

        Entry entry;

        int sum = 0,
            nChars = 0,
            nBitsPerChar;

        leafEntries = new Entry [SIZE];
        for (int i = 0; i < SIZE; i++) {

            leafEntries [i] = new Entry();
            leafEntries [i].freq = 0;

        } // initializing leafEntries and frequencies

        fillleafEntries();

        pq = new Heap();
        for (int i = 0; i < SIZE; i++) {

            entry = leafEntries [i];
            if (entry.freq > 0) {

                pq.add (entry);
                sum += entry.freq;
                nChars++;

            } // if

        } // counting chars and frequencies

        nBitsPerChar = (int)Math.ceil(Math.log (nChars) / Math.log (2));
        gui.println ("\n" + DEFAULT_TOTAL + (sum * nBitsPerChar));

    } // createPQ


    // Postcondition: The leafEntries array has been filled in from the info in
    //                the input file.
    public void fillleafEntries() throws IOException {

        Entry entry;

        String line;

        while ((line = fileReader.readLine()) != null) {

            for (int j = 0; j < line.length(); j++) {

                entry = leafEntries [(int)(line.charAt (j))];
                entry.freq++;
                entry.left = null;
                entry.right = null;
                entry.parent = null;

            } // for
            entry = leafEntries [(int)'\r'];
            entry.freq++;
            entry.left = null;
            entry.right = null;
            entry.parent = null;

        } // while

    } // method fillleafEntries


    // Postcondition: The Huffman tree has been created.
    public void createHuffmanTree() {

        Entry left,
              right,
              sum;

        while (pq.size() > 1) {

            left = (Entry)pq.removeMin();
            left.code = "0";

            right = (Entry)pq.removeMin();
            right.code = "1";

            sum = new Entry();
            sum.parent = null;
            sum.freq = left.freq  + right.freq;
            sum.left = left;
            sum.right = right;
            left.parent = sum;
            right.parent = sum;

            pq.add (sum);

        } // while

    } // createHuffmanTree


    // Postcondition: The Huffman codes have been calculated.
    public void calculateHuffmanCodes () {

        final String HUFFMAN_CODES = "\nHere are the Huffman codes, " +
            "including blanks and other whitespace characters: ";

        final String ENCODED_SIZE_MESSAGE =
            "\n\nThe size of the encoded message, in bits, is ";

        int total = 0;

        String code;

        Entry entry;

        gui.println (HUFFMAN_CODES);
        for (int i = 0; i < SIZE; i++) {

            code = "";
            entry = leafEntries [i];
            if (entry.freq > 0) {

             //   gui.print ((char)i + "  ");
                do {

                    code = entry.code + code;  // current bit prepended to code
                    entry = entry.parent;      // because we go up the tree

                } // do
                while (entry.parent != null);

                gui.println ((char)i + "  " + code);
                leafEntries [i].code = code;
                total += code.length() * leafEntries [i].freq;

            } // if

        } // for
        gui.println (ENCODED_SIZE_MESSAGE + total);

    } // calculateHuffmanCodes


    // Postcondition: The Huffman codes and encoded message have been
    //                saved to a file.
    public void saveToFile() throws IOException {

        Entry entry;

        String line;

        for (int i = 0; i < SIZE; i++) {

            entry = leafEntries [i];
            if (entry.freq > 0)
                fileWriter.println ((char)i + " " + entry.code);

        } // for
        fileWriter.println ("**");
        fileReader = new BufferedReader (new FileReader (inFileName));
        while ((line = fileReader.readLine()) != null) {

            for (int j = 0; j < line.length(); j++) {

                entry = leafEntries [(int)(line.charAt (j))];
                fileWriter.print (entry.code);

            } // for
            entry = leafEntries [(int)'\r'];
            fileWriter.print (entry.code);

        } // while
        fileWriter.close();

    } // saveToFile


} // class Huffman



