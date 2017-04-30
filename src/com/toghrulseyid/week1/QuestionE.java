package com.toghrulseyid.week1;

import java.util.Scanner;

public class QuestionE {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int times = scanner.nextInt();
        int count = 0;
        String line;
        while (times-- > 0) {
            line = scanner.next();
            System.out.format("Case #%d: %d\n", (++count), parseString(line.toCharArray()));
        }

    }

    private static int i;

    private static long parseString(char[] array) {
        i = 0;
        long num1 = parseInt(array, array.length);

        /**
         * 1minus8times5plus3minus8times5minus35
         * */
        for (; i < array.length; i++) {
            if (Character.isLetter(array[i])) {
                if (array[i] == 'p') { //plus
                    i = i + 4;
                    num1 = num1 + parseInt(array, array.length);

                } else if (array[i] == 'm') { //minus
                    i = i + 5;
                    num1 = num1 - parseInt(array, array.length);

                } else if (array[i] == 't' && array[i + 1] == 'i') { // times
                    i = i + 5;
                    num1 = num1 * parseInt(array, array.length);

                } else if (array[i] == 't' && array[i + 11] == 'f') { //tothepowerof
                    i = i + 12;
                    num1 = (int) Math.pow(num1, parseInt(array, array.length));
                }
                i--;
            }
        }

        return num1;
    }

    private static StringBuilder stringBuilder;

    private static int parseInt(char[] array, int length) {
        stringBuilder = new StringBuilder("");
        while (i < length && Character.isDigit(array[i])) {
            stringBuilder.append(array[i]);
            ++i;
        }
        return Integer.parseInt(stringBuilder.toString());
    }
}
