import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class GUI extends JFrame {

    protected JTextArea outputArea;
    protected JTextField inputField;

    public GUI (Process process) {

        setSize (600, 400);
        JPanel panel = new JPanel();
        getContentPane().add (panel);

        JLabel inputLabel = new JLabel ("Input: ");
        panel.add (inputLabel);

        inputField = new JTextField (47);
        panel.add (inputField);
        inputField.setEditable (true);

        JLabel outputLabel = new JLabel ("Output: ");
        panel.add (outputLabel);

        outputArea = new JTextArea ("", 18, 47);
        outputArea.setEditable (false);
	      JScrollPane scrollPane = new JScrollPane (outputArea);
        panel.add (scrollPane);

        setVisible (true);

        addWindowListener (new GUIListener());
        inputField.addActionListener (new GUIListener (inputField, process));
    } // constructor


    // Postcondition: the output area is now blank.
    public void clear() {

        outputArea.setText ("");

    } // method clear

    
    // Postcondition: s has been converted to a string and output.
    public void print (Object s) {

        outputArea.append (s.toString());
        inputField.requestFocus();

    } // method print for objects


    // Postcondition: s has been converted to a string and output, and
    //                the next line has been advanced to.
    public void println (Object s) {

        print (s + "\n");

    } // method println for objects


    public void print (long i) {

        print (new Long (i));

    } // method print for longs


    public void println (long i) {

        print (i + "\n");

    } // method println for longs


    public void print (double x) {

        print (new Double (x));

    } // method print for doubles


    public void println (double x) {

        print (x + "\n");

    } // method println for doubles


    public void print (char c) {

        print (new Character (c));

    } // method print for chars


    public void println (char c) {

        print (c + "\n");

    } // method println for chars


    public void print (boolean b) {

        print (new Boolean (b));

    } // method print for booleans


    public void println (boolean b) {

        print (b + "\n");

    } // method println for booleans


    // Postcondition: the Input Line in this GUI window can no
    //                longer be written to.
    public void freeze() {

        inputField.setEditable (false);
     //   outputArea.setEnabled (false);

    } // method freeze


} // class GUI


