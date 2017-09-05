import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static BigInteger[][][] dp = new BigInteger[25][20][20];
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for(int i = 0; i <= 15; ++i) {
            for(int j = 0; j <= 15; ++j) {
                dp[0][i][j] = BigInteger.ONE;
            }
        }
        for(int i = 1; i <= 20; ++i) {
            for(int j = 0; j <= 15; ++j) {
                for(int k = 0; k <= 15; ++k) {
                    dp[i][j][k] = BigInteger.ZERO;
                    for(int p = 0; p <= j; ++p) {
                        for(int q = 0; q <= k; ++q) {
                            dp[i][j][k] = dp[i][j][k].add(dp[i - 1][p][q]);
                        }
                    }
                }
            }
        }
        int n, a, b;
        while(in.hasNext()) {
            n = in.nextInt();
            a = in.nextInt();
            b = in.nextInt();
            System.out.println(dp[n][a][b]);
        }
    }

}
