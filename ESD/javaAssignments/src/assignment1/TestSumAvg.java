package assignment1;

public class TestSumAvg {

	public static void main(String[] args) {
		
		int[] arr = {12,92,21,77,89,45,68,69};
		SumAvg obj = new SumAvg();
		int[] newsum = obj.Sum(arr);
		int[] newavg = obj.Average(arr);
		System.out.println("Even sum: "+newsum[0] + "\nOdd sum: " + newsum[1]);
		System.out.println("Even average: "+newavg[0] + "\nOdd average: " + newavg[1]);
	}
}
