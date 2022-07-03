package com.company;
import java.util.*;

public class Uiie{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String str = s, nstr = "";
        char ch;
        String st = null;
        for (int i = 0; i < str.length(); i++) {
            ch = str.charAt(i);
            nstr = ch + nstr;
            st = nstr;
        }
//        System.out.println("Reversed word: " + nstr);
        if (s.equals(st)) {
            System.out.println("The word, " + s + ", is a palindrome." );
        } else {
            System.out.println("no match");
        }

    }
}
