import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static final int maxn = 105;
    public static BigInteger[][] dp = new BigInteger[maxn][maxn];
    public static BigInteger[][] C = new BigInteger[maxn][maxn];
    public static int m, n, l;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for(int i = 0; i < maxn; i++) {
            C[i][0] = C[i][i] = BigInteger.ONE;
            for(int j = 1; j < i; j++) {
                C[i][j] = C[i - 1][j].add(C[i - 1][j - 1]);
            }
        }
        while(in.hasNext()) {
            m = in.nextInt();
            n = in.nextInt();
            l = in.nextInt();
            if(l > m) {
                System.out.println("mukyu~");
                continue;
            }
            BigInteger sum = BigInteger.valueOf(n).pow(m);
            //init
            for(int i = 0; i <= n; i++) {
                for(int j = 0; j <= m; j++) {
                    dp[i][j] = BigInteger.ZERO;
                }
            }
            dp[0][0] = BigInteger.ONE;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    for(int k = 0; k < l && k <= j; k++) {
                        dp[i][j] = dp[i][j].add(dp[i - 1][j - k].multiply(C[m - (j - k)][k]));
                    }
                }
            }
            BigInteger ans = BigInteger.ZERO;
            for(int i = 1; i <= n; i++) {
                ans = ans.add(dp[i][m]);
            }
            ans = sum.subtract(ans);
            BigInteger gcd = ans.gcd(sum);
            System.out.println(ans.divide(gcd) + "/" + sum.divide(gcd));
        }
        in.close();
    }
}
