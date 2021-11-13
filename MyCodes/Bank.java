public abstract class Bank {
    abstract void deposit();
    private abstract void withdraw(); //abstract method cannot be private as that method has to be overidden 
    public void balance(){}
}

class office extends Bank{
    void deposit(){

    }
}
