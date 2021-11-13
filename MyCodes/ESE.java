import java.util.Vector;

public class ESE{
    public static void main(String args[]){
        Vector<String> vec = new Vector<>();
        vec.add("Python");
        vec.add("Java");
        vec.add("COBOL");
        vec.add("Java");
        if(vec.contains("Java")){
            System.out.println(vec.indexOf("Java"));
        }
        else{
            System.out.println("Java not found");
        }
    }
}

