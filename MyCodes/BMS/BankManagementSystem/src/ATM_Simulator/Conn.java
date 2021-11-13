package BMS.BankManagementSystem.src.ATM_Simulator;

import java.sql.*;

public class Conn {
    Connection c;
    Statement s;
    
    public Conn(){
        try{
            Class.forName("com.mysql.jdbc.Driver");
            c = DriverManager.getConnection("jdbc:mysql://localhost:3306/bank_ms", "root","Abcd19");
            s = c.createStatement();
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
  