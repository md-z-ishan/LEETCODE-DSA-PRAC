class Solution {
    public boolean isValidSudoku(char[][] board) {

        for(int i = 0; i < 9; i++) {
            boolean[] row = new boolean[9];
            boolean[] col = new boolean[9];

            for(int j = 0; j < 9; j++) {

                // row check
                if(board[i][j] != '.') {
                    int n = board[i][j] - '1';

                    if(row[n])
                        return false;

                    row[n] = true;
                }

                // column check
                if(board[j][i] != '.') {
                    int n = board[j][i] - '1';

                    if(col[n])
                        return false;

                    col[n] = true;
                }
            }
        }

        // 3 x 3 box check
        for(int r = 0; r < 9; r += 3) {
            for(int c = 0; c < 9; c += 3) {

                boolean[] box = new boolean[9];

                for(int i = r; i < r + 3; i++) {
                    for(int j = c; j < c + 3; j++) {

                        if(board[i][j] != '.') {
                            int n = board[i][j] - '1';

                            if(box[n])
                                return false;

                            box[n] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
}