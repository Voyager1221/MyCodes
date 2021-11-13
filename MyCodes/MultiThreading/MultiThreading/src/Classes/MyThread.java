import java.util.*;

public class MyThread extends Thread {
    Thread t;
    String name;
    long sleepTime;

    public MyThread(String tName, long t1){
        t = new Thread(this);    
        t.setName(tName);
        sleepTime = t1;
        t.start();
    }    

    public void Run(){
        for(int i=0;i<10;i++){
            try{
                Thread.sleep(sleepTime);
            }catch(InterruptedException e){
                
            }
            System.out.println(t.getName() + i);
        }
    }
    
}
