/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package SimulatorSys;

/**
 *
 * @author admin
 */
import java.awt.*;
import java.awt.event.*;
import java.sql.ResultSet;
import javax.swing.*;
import java.util.*;

class BalanceEnquiry extends JFrame implements ActionListener {
    JTextField t1, t2;
    JButton b1, b2, b4;
    JLabel l1, l2, l3;
    String pin;

    BalanceEnquiry(String pin){
        this.pin = pin;

        //ImageIcon i1 = new ImageIcon(ClassLoader.getSystemResource("src/icons"));
        ImageIcon i1 = new ImageIcon("Images/atm.jpg");
        Image i2 = i1.getImage().getScaledInstance(1000,1180,Image.SCALE_DEFAULT);
        ImageIcon i3 = new ImageIcon(i2);
        JLabel l3 = new JLabel(i3);
        l3.setBounds(0,0,960,1080);
        add(l3);

        l1 = new JLabel();
        l1.setForeground(Color.WHITE);
        l1.setFont(new Font("System", Font.BOLD, 16));

        b1 = new JButton("BACK");   

        setLayout(null);

        l1.setBounds(190, 350, 400, 35);
        l3.add(b1);
        int balance = 0;
        try{
            Conn c1 = new Conn();
            //Tsble name to be added accordingly...Table name added.
            ResultSet rs = c1.s.executeQuery("SELECT * FROM bank WHERE PIN = '"+pin+"'");
            while(rs.next()){
                if(rs.getString("mode").equals("Deposit")){
                    balance += Integer.parseInt(rs.getString("amount"));
                }
                else{
                    balance -= Integer.parseInt(rs.getString("amount"));
                }
            }
        }
        catch(Exception e){}

        l1.setText("Your Current Account Balance is ₹ "+balance);

        b1.addActionListener(this);

        setSize(960, 1080);
        setUndecorated(true);
        setLocation(500, 0);
        setVisible(true);
        

    }

    public void actionPerformed(ActionEvent ae){
        setVisible(false);
        new Transactions(pin).setVisible(true);
    }
    
    public static void main(String[] args){
        new BalanceEnquiry("").setVisible(true);
    }
}

