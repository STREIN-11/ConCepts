
import java.util.Scanner;

class Base{
    public int x;
    public int getX(){
        return x;
    }
    public void setX(int x){
        this.x = x;
    }
}
class Derive extends Base{
    public int y;

    public int getY() {
        return y;
    }
    public void setY(int y) {
        this.y = y;
    }
}
class Ulderive extends Derive{
    public int add(int g, int m){
        int a;
        a = g + m;
        return a;
    }
}

public class innheritance {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        Base c = new Base();
        Derive b = new Derive();
        Ulderive u = new Ulderive();

        System.out.print("Enter Number for Base class : ");
        int n1 = s.nextInt();
        System.out.print("Enter Number for Derived class : ");
        int n2 = s.nextInt();
        c.setX(n1);
        b.setY(n2);

        System.out.println("The Two assigned values are :  " + c.getX() + " , " + b.getY());
        int a = u.add(n1 , n2);
        System.out.println("Addition of Two assigned value is : " + a);

    }
}
