package assignment5;

public class MatrixTest {

	public static void main(String[] args) {
		MatrixOp mat = new MatrixOp();
		int sum = 0; 
		System.out.println("Matrix: ");
		mat.printMatrix();
		int[][] newMat = mat.getMatrix();
		
		ThreadOp t1 = new ThreadOp(newMat, 0);
		ThreadOp t2 = new ThreadOp(newMat, 1);
		ThreadOp t3 = new ThreadOp(newMat, 2);
		System.out.println("Threads are created....");
		t1.start();
		// sum += t1.getSum();
		//System.out.println(sum1);
		t2.start();
		 //sum += t2.getSum();
		t3.start();
		 //sum += t3.getSum();
		
		try {
			t1.join();
			t2.join();
			t3.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("Threads are ready....");
		sum = t1.getSum()+t2.getSum()+t3.getSum();
		System.out.println("Final sum is: " + sum);
	}
}
