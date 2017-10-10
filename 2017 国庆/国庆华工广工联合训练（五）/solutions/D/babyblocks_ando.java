import java.io.*;
import java.lang.*;
import java.util.*;

// niet zo heel efficient (used array kan je ook met dynamisch programmeren
// laten vollopen).

// gaat fout bij strings langer dan 40 characters oid
// (wanneer de faculteit van de lengte van de string niet meer in een long past)

// opmaak heb ik voor de grap in sander-style gedaan (geheel onleesbaar)

class Main extends babyblocks_ando {} // for DOMJudge
class babyblocks_ando {
	public static final int MAX_FAC=39;

	static long[] facts=new long[MAX_FAC+1];
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static StreamTokenizer tok=new StreamTokenizer(br);

	private static long leesInt() throws IOException{
		tok.nextToken();
		return (long) tok.nval;
	}

	private static String leesRegel() throws IOException {
		String s=br.readLine(); while(s.isEmpty()) s=br.readLine(); return s;
	}

	public static void main(String argv[]) throws IOException {
		makeFacts();
		long runCnt=leesInt();
		for(long i=0;i<runCnt;++i) run();
	}

	private static void makeFacts() {
		facts[0]=facts[1]=1;
		for(int i=2;i<=MAX_FAC;++i) facts[i]=i*facts[i-1];
		//for(int i=0;i<=MAX_FAC;++i) System.err.println(i + "  " + facts[i]);
	}

	private static void run() throws IOException {
		System.out.println(calcOrder(leesRegel()));
	}

	private static long calcOrder(String s) {
		if (s.length() > facts.length) {
		  System.err.println("word too long: " + s);
		}
		long r=0;
		for(int i=0;i<s.length()-1;++i) r+=charsLeft(s,i);
		return r;
	}

	private static long charsLeft(String s,int i) {
		int[] used=new int[26];
		for(int j=i;j<s.length();++j) used[s.charAt(j)-'A']++;
		long a=0,pfac=facts[s.length()-i-1];
		int c=s.charAt(i)-'A';
		for(int j=0;j<26;++j) if((used[j]!=0)&&(j<c)) {
			long n=1;
			for(int l=0;l<26;++l) if(used[l]!=0) n*=facts[used[l]-((l==j)?1:0)];
			a+=(long)((pfac+0.5)/n);
		}
		return a;
	}
}
