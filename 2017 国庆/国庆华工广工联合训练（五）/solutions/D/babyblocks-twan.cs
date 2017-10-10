using System;

class BabyBlocks {
	static void Main () {
		int runs = Convert.ToInt32(Console.ReadLine());
		while (runs --> 0) {
			new BabyBlocks();
		}
	}
	BabyBlocks () {
		String s = Console.ReadLine();
		Console.WriteLine(solve(s));
	}
	long solve(String s) {
		// for each character determine
		//  1. how many times are all combinates of the part after it tried
		//  2. how long does each of these take? (i.e. how many permutations are there of the substring after it)
		
		long steps = 0;
		long[] permutations = new long[s.Length+1]; // how many permutations are there of the string from point [i..end]
		int[] copies = new int[26]; // how many copies do we have of each character after the current location?
		permutations[s.Length] = 1;
		for (int i = s.Length-1 ; i >= 0 ; --i) {
			int a = s[i]-'A';
			// steps needed where b is at the start of the substring instead of a
			for (int b = 0 ; b < a ; ++b) {
				if (copies[b] != 0) {
					long perms = permutations[i+1]
					           * copies[a]; // we have one more copy of a
					           * copies[a]; // we have one  copy of b
					steps += perms;
				}
			}
			// permutations of this substring starting at i
			int n = s.Length - i;
			copies[a]++;
			permutations[i] = permutations[i+1] * n / copies[a];
		}
		
		return 0;
	}
	long factorial(int n) {
		long fact = 1;
		for (int i = 1 ; i < n ; ++i) {
			fact *= i;
		}
		return fact;
	}
	
}
