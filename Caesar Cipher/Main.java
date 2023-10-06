// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
         Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the desired message: ");
        String message = scanner.nextLine();

        System.out.println("Enter the desired shift: ");
        int shift = scanner.nextInt();

        String encrypted = ceaseCipherEncryption(message, shift);
        System.out.println("your new message: " + encrypted);
    }

    //this function will encrypt a message given a string and a key for the shit

    /*
    * hello -> 7 shift -> olssv
    */

    private static String ceaseCipherEncryption(String message, int shift)
    {
        StringBuilder encryptedMessage = new StringBuilder();

        for(char c : message.toCharArray())
        {
            if (Character.isLetter(c)) {
                char base = Character.isLowerCase(c) ? 'a' : 'A';
                encryptedMessage.append((char) ((c - base + shift) % 26 + base));
            } else {
                encryptedMessage.append(c);
            }
        }
        return encryptedMessage.toString();
    }
}