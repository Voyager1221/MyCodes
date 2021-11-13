/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Time_Lag;

/**
 *
 * @author admin
 */

/* Question:
 * I'm watching a stream on YT and I'm lagging behind by time t.
 * What will the time taken to cope-up with the live stream, if I watch it at 2x speed.
*/
public class TimeLag {
    int lag;
    int t=0;
    public TimeLag(int time){
        lag = time;
    }
    public int lagCalc(int time){
        if(time/2==0 || time/4==0)
            return 1;
        
        t = t + lagCalc(time/2);//Maybe t isn't updating as every func returns value
        return t;
        //return lagCalc(time/2)+ lagCalc(time/4);
        
    }    
    public static void main(String[] args){
        TimeLag obj1 = new TimeLag(8);
        obj1.lagCalc(8);
        //System.out.println("Time req is "+obj1.lagCalc(300));
        System.out.println("Time req is "+obj1.t);
        //System.out.println(300/2);
        //System.out.println(1/2);
    }
}
