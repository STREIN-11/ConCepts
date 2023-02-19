import java.util.*;
import java.util.Scanner;

class MyException extends Exception{

}

public class Rough {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

//        System.out.print("Enter Your name : ");
//        String str = sg.nextLine();
//        System.out.println("yo" + str);

//        Scanner sc = new Scanner(System.in);
//        int b = 4;
//        double c = 4.0;
//        int a = sc.nextInt();
//        double d = sc.nextDouble();
//        sc.nextLine();
//        String s2 = sc.nextLine();
//        System.out.println(a + b);
//        System.out.println(d + c);
//        System.out.println("HackerRank " + s2);

//        try {
//            for (int i = 1; i <=5; i++) {
//                Thread.sleep(2000);
//                System.out.println(i);
//            }
//        }
//        catch (Exception e) {
//            System.out.println(e);
//        }
        Calendar c = Calendar.getInstance();
        System.out.println(c.getTimeZone());
//        c.add(Calendar.YEAR,4);
        System.out.println(c.getTime());
        System.out.println(c.get(Calendar.MONTH));









    }
}
