package assignment5;

public class ThreadOp extends Thread {
	private int sum=0;
	private int[] arr = new int[4];
	
	public ThreadOp(int[][] mat, int rowNum) {
		for(int i=0; i<4; i++) {
			this.arr[i] = mat[rowNum][i];
		}
	}
	
	public int getSum() {
		//System.out.println(sum);
		return this.sum;
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		//super.run();
		//this.sum = 0;
		for(int i=0; i<4; i++) {
			this.sum += arr[i];
		}
	}
}
