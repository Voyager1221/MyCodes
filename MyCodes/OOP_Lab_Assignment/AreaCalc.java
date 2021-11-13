package OOP_Lab_Assignment;

public class AreaCalc {
    int area;
    int a,b;
    AreaCalc(int a, int b){
        this.a = a;
        this.b = b;
    }

    public int calculator(){
        area = a*b;
        return area;
    }

}
