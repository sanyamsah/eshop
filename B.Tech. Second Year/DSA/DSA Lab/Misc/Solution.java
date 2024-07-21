//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s1 = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s1[0]);
            int m = Integer.parseInt(s1[1]);
            char[][] grid = new char[n][m];
            for (int i = 0; i < n; i++) {
                String S = br.readLine().trim();
                for (int j = 0; j < m; j++) {
                    grid[i][j] = S.charAt(j);
                }
            }
            String word = br.readLine().trim();
            Solution obj = new Solution();
            int[][] ans = obj.searchWord(grid, word);
            for (int i = 0; i < ans.length; i++) {
                for (int j = 0; j < ans[i].length; j++) {
                    System.out.print(ans[i][j] + " ");
                }
                System.out.println();
            }
            if (ans.length == 0) {
                System.out.println("-1");
            }

        }
    }
}

// } Driver Code Ends

// User function Template for Java

class Solution {
    public static boolean isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    public boolean search(char[][] grid, int row, int col, String word, int index, int[] dx, int[] dy, int k) {
        if (index == word.length()) {
            return true;
        }
        if (!isValid(row, col, grid.length, grid[0].length) || grid[row][col] != word.charAt(index)) {
            return false;
        }
        int newrow = row + dx[k];
        int newcol = col + dy[k];
        int newk = (k + 1) % 8;
        return search(grid, newrow, newcol, word, index + 1, dx, dy, newk);
    }

    public int[][] searchWord(char[][] grid, String word) {
        // Code here

        List<int[]> result = new ArrayList<>();
        int m = grid.length;
        int n = grid[0].length;
        int flag = 0;
        int a = 0, b = 0;
        int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
        int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == word.charAt(0)) {

                    for (int k = 0; k < 8; k++) {
                        int newx = i + dx[k];
                        int newy = j + dy[k];
                        if (isValid(newx, newy, m, n) && search(grid, newx, newy, word, 1, dx, dy, k)) {
                            result.add(new int[] { i, j });
                            break;
                        }
                    }

                }
            }
        }
        int[][] resultArray = new int[result.size()][2];
        for (int i = 0; i < result.size(); i++) {
            resultArray[i] = result.get(i);
        }
        return resultArray;
    }
}