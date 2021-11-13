/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package MyThread_Package;

/**
 *
 * @author admin
 */

public class SynchronizedThreads {
    public static void main(String[]args){
        Teacher te1;
        Student s1,s2;
        

        te1 = new Teacher();
        s1 = new Student(te1, "A", "Please explain the concepts of threading");
        s2 = new Student(te1, "B", "How to handle expections for threading");
        Thread t1 = new Thread(s1);
        Thread t2 = new Thread(s2);
        t1.start();
        t2.start();
    }
}