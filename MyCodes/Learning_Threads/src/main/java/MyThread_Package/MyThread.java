package MyThread_Package;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author admin
 */

public class MyThread extends Thread{
    Thread t;
    String name;
    long sleepTime;
    
    public MyThread(String tName, long time){
        t = new Thread(this);
        t.setName(tName);
        sleepTime = time;
        t.start();
    }
    
    public void run(){
        for(int i=0; i<10; i++){
            try{
                Thread.sleep(sleepTime);
            }
            catch(InterruptedException e){ System.out.println("Thread isn't interrupted.");}
            
            System.out.println(t.getName() + i);
        
        }
    }
}
