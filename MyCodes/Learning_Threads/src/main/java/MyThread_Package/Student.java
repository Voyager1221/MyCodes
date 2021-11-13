/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package MyThread_Package;

/**
 *
 * @author admin
 */
public class Student implements Runnable{
    
    Runnable obj1;    
    //RunObj obj1;
    String question;
    Teacher te;
    
    public Student(Teacher te, String sName, String question){
        Thread t = new Thread(obj1);
        t.setName(sName);
        this.question = question;
        this.te = te;
        t.start(); 
        }
    
@Override
    public void run(){
        te.answerThisQuestion(question);
    }
}




