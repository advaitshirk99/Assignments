package assignment5;

import java.util.Random;

public class MatrixOp{
	private int[][] mat = new int[3][4];
	
	public MatrixOp() {
		Random random = new Random();
		for(int i=0; i<3; i++) {
			for(int j=0; j<4; j++) {
				this.mat[i][j] = random.nextInt(100);
			}
		}
	}
	
	public void printMatrix() {
		for(int i=0; i<3; i++) {
			for(int j=0; j<4; j++) {
				System.out.print(mat[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	public int[][] getMatrix(){
		return mat;
	}
}
