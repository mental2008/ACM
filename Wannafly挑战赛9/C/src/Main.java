import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        BigInteger MOD = new BigInteger("1000000007");

        Scanner in = new Scanner(System.in);
        while(in.hasNext()) {
            BigInteger input = in.nextBigInteger().mod(MOD);
            BigInteger one = BigInteger.valueOf(1);
            BigInteger two = BigInteger.valueOf(2);
            if(one.equals(input)) System.out.println(1);
            else if(two.equals(input)) System.out.println(2);
            else {
                for(int i = 3; i <= 100000; ++i) {
                    BigInteger temp = two.add(one).mod(MOD);
                    one = two.mod(MOD);
                    two = temp;
                    if(temp.equals(input)) {
                        System.out.println(i);
                        break;
                    }
                }
            }
        }
        in.close();

    }

}
