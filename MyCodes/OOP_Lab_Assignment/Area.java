package OOP_Lab_Assignment;

import OOP_Lab_Assignment.AreaCalc;

/* class Shape {
    int a,b;
}

class Rectangle extends Shape{
} */

public class Area{

    public static void main(String[]args){
        int a=5, b=6;
        AreaCalc area = new AreaCalc(a,b);
        int  res= area.calculator();
        System.out.println(res);
    }

}