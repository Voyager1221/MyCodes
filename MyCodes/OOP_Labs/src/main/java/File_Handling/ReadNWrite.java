/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package File_Handling;

/**
 *
 * @author admin
 */

import java.util.*;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileReader;
import java.io.FileNotFoundException;

public class ReadNWrite {
    FileWriter myWriter;
    FileReader myReader;
    
    public void writeInFile(){
        try{
            myWriter = new FileWriter("E:\\VS_Code_C_C++\\OOP_Labs\\src\\main\\java\\File_Handling\\NewFile.txt");
            
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the data to be added : ");
            String v1 = sc.nextLine();
            
            myWriter.write(v1);
            myWriter.close();
            System.out.println("Successfully wrote in the file.");
            
        }catch(IOException e){
            System.out.println("An error occured");
            e.printStackTrace();
        }
    }
    
    public void readInFile(){
        try{
            myReader = new FileReader("E:\\VS_Code_C_C++\\OOP_Labs\\src\\main\\java\\File_Handling\\NewFile.txt");
        
            Scanner sc = new Scanner(myReader);
            while(sc.hasNextLine()){
                String data = sc.nextLine();
                System.out.println(data);
            }
            sc.close();
        }catch(FileNotFoundException e){
            System.out.println("An error occured");
            e.printStackTrace();
        }
    }
    
    /*public int charCount(){
        String line;
        try{
            myReader = new FileReader("E:\\VS_Code_C_C++\\OOP_Labs\\src\\main\\java\\File_Handling\\NewFile.txt");
        
            Scanner sc = new Scanner(myReader);
            while((line = sc.)!= null){
            
        }
        }catch(){}
    }*/
}
