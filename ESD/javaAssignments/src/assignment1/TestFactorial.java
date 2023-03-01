package assignment1;

public class TestFactorial {

	public static void main(String[] args) {
		Factorial fac = new Factorial();
		assert(fac.fact(5)==120);
		assert(fac.fact(5)==10);
	}
}
