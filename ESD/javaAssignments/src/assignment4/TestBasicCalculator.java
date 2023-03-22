package assignment4;

public class TestBasicCalculator {

	public static void testAdd() {
		calculator cal= BasicCalculator.getInstance();
		
		assert(cal.put(10).put(30).add().read() == 40);
		assert(cal.put(101).put(-1).add().read() == 100);
		assert(cal.put(150).put(-50).add().read() == 100);
		assert(cal.put(150).put(50).add().read() == 200);
		
	}
	public static void testSub() {
		calculator cal= BasicCalculator.getInstance();
		
		assert(cal.put(100).put(30).sub().read() == 70);
		assert(cal.put(10).put(1).sub().read() == 9);
		assert(cal.put(15).put(-5).sub().read() == 20);
		
	}
	public static void testMul() {
		calculator cal= BasicCalculator.getInstance();
		
		assert(cal.put(10).put(30).mul().read() == 300);
		assert(cal.put(10).put(1).mul().read() == 10);
		assert(cal.put(15).put(5).neg().mul().read() == -75);
		
	}
	public static void testDiv() {
		calculator cal= BasicCalculator.getInstance();
		
		assert(cal.put(30).put(3).div().read() == 10);
		assert(cal.put(15).put(5).div().read() == 3);
		assert(cal.put(10).put(5).div().read() == 2);
		
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		testAdd();
		testSub();
		testMul();
		testDiv();
		
	}

}
