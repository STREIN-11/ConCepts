import java.util.Scanner;
public class Calculator_1 {
    public static int logic(int w,int x, int y){
        // Scanner sc = new Scanner(System.in);
        int z = 0;
        switch (w){
            case 1 -> System.out.println(x+y);
            case 2 -> System.out.println(x-y);
            case 3 -> System.out.println(x*y);
            case 4 -> System.out.println(x/y);
            default -> System.out.println("Check Your Input");
        }
        return z;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("1 - For Add");
        System.out.println("2 - For Subtract");
        System.out.println("3 - For Multiplication");
        System.out.println("4 - For Device");
        int d = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c;
        c = logic(d,a,b);
        System.out.println(c);
    }
}