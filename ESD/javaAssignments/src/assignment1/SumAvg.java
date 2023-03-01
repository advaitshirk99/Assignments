package assignment1;

public class SumAvg {
	int[] sumArr = new int[2]; //sumArr[0] ---> even, sumArr[1] ---> odd
	int[] avgArr = new int[2]; //avgArr[0] ---> even, avgArr[1] ---> odd
	int countEven=0, countOdd=0;
	
	public int[] Sum(int[] arr) {
		int len = arr.length; 
		for(int i=0; i<len; i++) {
			if(arr[i] % 2 == 0) {
				sumArr[0] += arr[i];
			}
			else sumArr[1] += arr[i];
		}
		return sumArr;
	}
	
	public int[] Average(int[] arr) {
		int len = arr.length; 
		for(int i=0; i<len; i++) {
			if(arr[i] % 2 == 0) {
				countEven +=1;
				avgArr[0] += arr[i];
			}
			else {
				countOdd +=1;
				avgArr[1] += arr[i];
			}
		}
		avgArr[0] /= countEven;
		avgArr[1] /= countOdd;
		return avgArr;
	}
}
