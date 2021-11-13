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
import java.io.File;
import java.io.IOException;

public class CreateFile {
    
    public void createTheFile(){
        try{
            File obj = new File("E:\\VS_Code_C_C++\\OOP_Labs\\src\\main\\java\\File_Handling\\NewFile.txt");
            if(obj.createNewFile()){
                System.out.println("New File created");
            }else{
                System.out.println("Already exits");
            }
        }catch(IOException e){
            System.out.println("An error occured");
            e.printStackTrace();
        }
    }
    
    public void renameTheFile()
    {
        File oldName =
         new File("E:\\VS_Code_C_C++\\OOP_Labs\\src\\main\\java\\File_Handling\\NewFile.txt");
        File newName = 
         new File("E:\\VS_Code_C_C++\\OOP_Labs\\src\\main\\java\\File_Handling\\RenamedFile.txt");
  
        if (oldName.renameTo(newName)) 
            System.out.println("Renamed successfully");        
        else 
            System.out.println("Error");        
    }
    
    public void deleteTheFile(){
        
            File obj = new File("E:\\VS_Code_C_C++\\OOP_Labs\\src\\main\\java\\File_Handling\\NewFile.txt");
            if(obj.delete()){
                System.out.println("Deleted the file: "+obj.getName());
            }else{
                System.out.print("Already deleted");
            }
    }
}
