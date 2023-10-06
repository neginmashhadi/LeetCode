// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {

    /**
     * there are two ways of solving this problem
     * 1) with O(row * col)
     * 2) with O(row + col)
     */

    //this code will be the one of O(n+m) since the grid is sorted
    //this is possible
    public static int countNegatives(int[][] grid) {
        int count = 0;
        int rowLength = grid.length;
        int colLength = grid[0].length;
        int row = 0;
        int col = colLength - 1; //we start at the end of row

        while (row < rowLength && col >= 0) {
            if (grid[row][col] < 0) {
                count += (rowLength - row);
                col--;
            } else {
                row++;
            }
        }

        return count;
    }


    /**
     * O(n * m)
     * the following has the big O notation of (row * col)
     */
    public int countNegatives2(int[][] grid) {
        int count = 0;
        for (int[] row : grid) {
            for (int elem : row) {
                if (elem < 0) {
                    count++;
                }
            }
        }
        return count;
    }


    public static void main(String[] args) {
        int grid[][] = {{4, 3, 2, -1},
                        {3, 2, 1, -1},
                        {1, 1, -1, -2},
                        {-1, -1, -2, -3}};

        int count = countNegatives(grid);
        System.out.println("The number of negative numbers in the grid is " + count);

    }
}