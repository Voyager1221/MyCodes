
/*
Assignment 7
Implement Java program to create a base class called shape. 

Use this class to store two double type values that could be used to compute the area of figures. 

Derive two specific classes called function get_data() to initialize base class data members and 
another member function display_area() to compute and display the area of figures.

Make classes to suit their requirements. 

Using these three classes, design a program that will accept dimension of a triangle or a rectangle 
interactively, and display the area. 

Remember the two values given as input will be treated as lengths of two sides in the case of 
rectangles, and as base and height in the case of triangles, and used as follows: 

Area of rectangle= x*y Area of triangle =1/2*x*y 

*/ 


import java.util.Scanner;

class Rectangle extends Shape{
double len, width, area;

    public Rectangle(){
        this.get_Data();
        this.len = x;
        this.width = y;
    }

    public void Area(){
        area = len*width;
        System.out.println("The length is : " +x);
        System.out.println("The breadth is : " +y);
        System.out.println("The area of rectangle is : " +area );
    }
}

class Triangle extends Shape{
double height, base, area;

    public Triangle(){
        this.get_Data();
        this.height = x;
        this.base = y;
    }

    public void Area(){
        area = (base*height)/(double)2;
        System.out.println("The height is : "+height);
        System.out.println("The base is :"+base);
        System.out.println("The area of rectangle is : "+area);
    }

}

public class Shape {
double x, y;    
    public void get_Data(){
        Scanner Obj = new Scanner(System.in);  // Create a Scanner object
        
        System.out.println("Enter the 1st dimension : ");
        String v1 = Obj.nextLine();  // Read user input
        this.x = Double.parseDouble(v1);
        
        System.out.println("Enter the 2nd dimension : ");
        String v2 = Obj.nextLine();
        this.y = Double.parseDouble(v2);
    }

    public static void main(String[] args){
        
        Rectangle rect = new Rectangle();
        rect.Area();

        Triangle tri = new Triangle();
        tri.Area();
    }
}
