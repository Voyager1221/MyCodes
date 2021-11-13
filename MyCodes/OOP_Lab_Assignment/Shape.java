
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

package OOP_Lab_Assignment;

import java.util.Scanner;

class Rectangle extends Shape{
double len, width;

    public Rectangle(double len, double width){
        this.len = len;
        this.width = width;
    }

    public double Area(){
        return len*width;
    }
}

class Triangle extends Shape{
double height, base;

    public Triangle(double height, double base){
        this.height = height;
        this.base = base;
    }

    public double Area(){
        return 1/2*height*base;
    }

}

public class Shape {
double x, y;    
    public void get_Data(double x, double y){
        Scanner Obj = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter username");

        String v1 = Obj.nextLine();  // Read user input
        x = Double.parseDouble(v1);
        String v2 = Obj.nextLine();
        y = Double.parseDouble(v2);

    }

    public void main(String[] args){
        System.out.println("Value of x is : " + x);
        System.out.println("Value of y is : " + y);  // Output user input
    }
}
