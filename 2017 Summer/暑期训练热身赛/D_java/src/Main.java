import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static int maxn = 5000;

    public static void main(String[] args) {
        String s1, s2;
        Scanner in = new Scanner(System.in);
        s1 = in.next();
        s2 = in.next();
        s1 = s1.toLowerCase();
        s2 = s2.toLowerCase();
        BigInteger[] init = new BigInteger[30];
        init[0] = new BigInteger("1");
        for(int i = 1; i < 26; i++) {
            init[i] = init[i - 1].multiply(new BigInteger("5000"));
        }
        BigInteger[][] a1 = new BigInteger[maxn][maxn];
        BigInteger[][] a2 = new BigInteger[maxn][maxn];
        for(int i = 0; i < s1.length(); i++) {
            a1[i][i] = init[(int)(s1.charAt(i) - 'a')];
            for(int j = i + 1; j < s1.length(); j++) {
                a1[i][j] = a1[i][j - 1].add(init[(int)(s1.charAt(j) - 'a')]);
            }
        }
        for(int i = 0; i < s2.length(); i++) {
            a2[i][i] = init[(int)(s2.charAt(i) - 'a')];
            for(int j = i + 1; j < s2.length(); j++) {
                a2[i][j] = a2[i][j - 1].add(init[(int)(s2.charAt(j) - 'a')]);
            }
        }

        int len = Math.min(s1.length(), s2.length());
        int ans = 0;
        for(int i = len; i >= 1; i--) {
            for(int j = 0; j < s1.length() - i + 1; j++) {
                for(int k = 0; k < s2.length() - i + 1; k++) {
                    if(a1[j][j + i - 1].equals(a2[k][k + i - 1])) {
                        ans = Math.max(ans, i);
                    }
                }
            }
        }
        System.out.println(ans);

    }

}
