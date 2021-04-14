package com.company;

import static java.lang.System.exit;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int[] v = {102, 109, 99, 100, 127, 111, 50, 117, 58, 108, 82, 110, 83, 68, 59, 80, 80, 78, 98, 35, 99, 112, 100, 32, 109, 117, 69, 79, 115, 45, 114, 62, 93};
        System.out.println("Welcome to NPUCTF2020!");
        System.out.println("Input your flag:");
        Scanner scan = new Scanner(System.in);
        String str1 = scan.next();
        if(str1.length()!=v.length)
        {
            System.out.println("Invalid Format!");
            exit(1);
        }
        for (int i = 0; i < str1.length(); i++) {
            if ((str1.charAt(i) ^ i) != v[i]) {
                System.out.println("Wrong!");
                exit(1);
            }
        }
        System.out.println("Congratulations!");
        exit(0);
    }

}
