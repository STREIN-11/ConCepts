
import java.util.Scanner;
import java.util.Random;

public class Stone_paper {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("How many times You want to Play : ");
        int n = sc.nextInt();

        int i = 1;
        for (i=1; i<=n; i++){
            System.out.println(" ");
            System.out.println("1) Choose 1 for STONE");
            System.out.println("2) Choose 2 for PAPER");
            System.out.println("3) Choose 3 for SCISSOR");
            System.out.print("Enter Your Option : ");

            int a = sc.nextInt();
            Random ra = new Random();

            switch (a){
                case 1 -> System.out.println("You Choose : STONE");
                case 2 -> System.out.println("You Choose : PAPER");
                case 3 -> System.out.println("You Choose : SCISSOR");
                default -> System.out.println("Check Your Input");
            }
            int b = ra.nextInt(4);             // For Computer to select Random One ;
            switch (b){
                case 1 -> System.out.println("Computer : STONE");
                case 2 -> System.out.println("Computer : PAPER");
                case 3 -> System.out.println("Computer : SCISSOR");
            }
            if (a == b){
                System.out.println("Match Draw Play Again");
            }
            else if (a == 1 && b == 3 || a == 2 && b == 1 || a == 3 && b == 2){
                System.out.println("Congratulation! You Win");
            }
            else {
                System.out.println("Sorry! You Loose");
            }

            System.out.println("\nTotal you have played for " + n + " Times");
//            System.out.println("And the Result is : ");

        }
    }
}