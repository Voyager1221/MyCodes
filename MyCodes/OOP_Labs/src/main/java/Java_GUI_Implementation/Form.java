/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Java_GUI_Implementation;

/**
 *
 * @author admin
 */

import java.awt.Font;
import javax.swing.*;

public class Form {
    Form()
    {
        JFrame f=new JFrame("Learning system's features form");
        f.setSize(500, 550);
        JLabel l,l1,l2,l3,l4,l5;
        JTextField t1,t2,t3;
        l=new JLabel("Request Information");
        l.setBounds(90, 10, 350, 40);
        l.setFont(new Font("Raleway",Font.BOLD, 34));
        f.add(l);
        l1=new JLabel("First Name");
        l1.setBounds(50, 100, 100, 30);
        f.add(l1);
        t1=new JTextField();
        t1.setBounds(150, 100, 200, 30);
        f.add(t1);
        l2=new JLabel("Last Name");
        l2.setBounds(50, 150, 100, 30);
        f.add(l2);
        t2=new JTextField();
        t2.setBounds(150, 150, 200, 30);
        f.add(t2);
        l3=new JLabel("Email Address");
        l3.setBounds(50, 200, 100, 30);
        f.add(l3);
        t3=new JTextField();
        t3.setBounds(150, 200, 200, 30);
        f.add(t3);
        l4=new JLabel("Please keep me informed ");
        l4.setBounds(50, 250, 200, 30);
        f.add(l4);
        JCheckBox c=new JCheckBox();
        c.setBounds(50, 300, 15, 15);
        f.add(c);
        l5=new JLabel("I would like to have mails on learning features of the system.");
        l5.setBounds(80, 300, 400, 30);
        f.add(l5);
        JButton b =new JButton("Next");
        b.setBounds(150, 350, 150, 40);
        f.add(b);
        f.setLayout(null);
        f.setVisible(true);
    }
    public static void main(String[] args)
    {
        SwingUtilities.invokeLater(new Runnable()
        {
            public void run()
            {
                new Form();
            }
        });
    }
}
