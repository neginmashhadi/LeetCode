import java.util.Arrays;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        int diff = arr[1]-arr[0];
        for(int i = 2; i < arr.length; i++)
        {
            if(arr[i]-arr[i-1] != diff)
            {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
            int arr[] = {3,5,1};
            boolean isArithmetic = canMakeArithmeticProgression(arr);
            System.out.println(isArithmetic);
    }
}