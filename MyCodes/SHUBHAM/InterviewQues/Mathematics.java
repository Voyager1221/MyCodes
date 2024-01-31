import java.util.*;

class Mathematics{
    public int divide(int a, int b){
        int c = -1;
        try{
            c = a/b;
        }
        catch(Exception e){
            System.err.print("Exception");
        }
        finally{
            System.err.println("Finally");
        }
        return c;
    }
    public static void main(String[] args){
        Mathematics m1 = new Mathematics();
        m1.divide(4,0);
    }
}