package assignment1;

public class Prime {
	public int isPrime(int num) {
		if(num ==1 ) return 1;
		for(int i=2; i<(num/2)+1; i++) {
			if(num % i == 0) return 1;
		}
		return 0;
	}
	
	public void printPrime(int[] arr) {
		int len = arr.length;
		for(int i=0; i<len; i++) {
			if(isPrime(arr[i]) == 0) System.out.print(arr[i] + " "); 
		}
	}
}
