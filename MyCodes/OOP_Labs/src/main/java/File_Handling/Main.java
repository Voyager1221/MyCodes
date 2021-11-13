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
import java.lang.*;

public class Main {
    public static void main(String[]args){
        Menu m = new Menu();

        int ch;
        
        CreateFile f = new CreateFile();
        FileInfo fi = new FileInfo();
        ReadNWrite rnw = new ReadNWrite();
        
        while(true){
            m.display();
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the choice : ");
            String v1 = sc.nextLine();
            ch = Integer.parseInt(v1);
            switch(ch){
            
                case 1:
                        f.createTheFile();
                          break;
                case 2:
                        rnw.writeInFile();
                        break;
                case 3:
                        f.renameTheFile();
                        break;
                        
                case 4:
                        System.out.println("Absolute path: "+fi.obj.getAbsolutePath());
                        break;
                        
                case 5:
                        System.out.println("Readability : "+ fi.obj.canRead());
                        System.out.println("Writability : "+ fi.obj.canWrite());
                        break;
                       
                case 6:
                        System.out.println("Diretory existance : "+fi.obj.exists());
                        break;
               
                case 7:
                        rnw.readInFile();
                        break;
                case 8:
                        System.out.println("No. of characters are : "+fi.obj.length());
                        break;
                        
                case 9:
                        f.deleteTheFile();
                        break;
                case 10:
                        System.exit(0);
            }
            
            FileInfo f2 = new FileInfo();
            System.out.println("The file name is: "+f2.obj.getName());
        }
    }
}
