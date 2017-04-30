package com.toghrulseyid.week1;

import java.util.Scanner;

public class QuestionC {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextInt();
        int n = scanner.nextInt();
        String line;
        System.out.println("Case #1:");
        line = scanner.nextLine();
        while (n-- > 0) {
            line = scanner.nextLine();
            replaceAll(line.split(" "));
        }
    }

    private static void replaceAll(String[] chars) {
        for (String word : chars) {
            if (word.equals("studentin")) { //"studentin", "studierende"
                System.out.format("%s ", "studierende");

            } else if (word.equals("studenten")) { //"studenten", "studierende".
                System.out.format("%s ", "studierende");

            } else if (word.equals("student")) { //"student", "studierender".
                System.out.format("%s ", "studierender");

            } else {
                //["entin", "ierende"], ["enten", "ierende"],["ent", "ierender"]
                //array to hold replacements
                String[][] replacements = {{"entin", "ierende"},
                        {"enten", "ierende"},
                        {"ent", "ierender"}};

                //loop over the array and replace
                for (String[] replacement : replacements) {
                    word = word.replace(replacement[0], replacement[1]);
                }
                System.out.format("%s ", word);
            }
        }
        System.out.println();
    }
}