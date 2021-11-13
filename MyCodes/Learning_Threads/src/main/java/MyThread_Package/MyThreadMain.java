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
public class MyThreadMain {
    public static void main(String[] args){
        MyThread t1 = new MyThread("A", 1000);
        MyThread t2 = new MyThread("B", 2000);
        MyThread t3 = new MyThread("C", 3000);
    }
}
