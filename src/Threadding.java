//package com.company;
//
//class Threadd extends Thread{
//    @Override
//    public void run(){
//        int i = 0;
//        while (i<10) {
//            System.out.println("Thread 1");
//            i++;
//        }
//    }
//}
//class Threadd2 extends Thread{
//    @Override
//    public void run(){
//        int i = 0;
//        while (i<10) {
//            System.out.println("Thread 2");
//            i++;
//        }
//    }
//}
//
//public class Threadding {
//    public static void main(String[] args) {
//        Threadd t = new Threadd();
//        Threadd2 t2 = new Threadd2();
//        t.start();
//        t2.start();
//    }
//}


class neww implements Runnable{
    public void run(){
        int x = 0;
        while (x<10){
            System.out.println("Thread 1");
            x++;
        }
    }
}
class neww2 implements Runnable{
    public void run(){
        int x = 0;
        while (x<10){
            System.out.println("Thread 2");
            x++;
        }
    }
}
public class Threadding {
    public static void main(String[] args) {
        neww a = new neww();
        neww2 b = new neww2();
        Thread g = new Thread(a);
        Thread h = new Thread(b);
        g.start();
        h.start();
    }
}




