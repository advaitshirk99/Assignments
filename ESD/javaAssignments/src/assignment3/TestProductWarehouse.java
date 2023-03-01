package assignment3;

public class TestProductWarehouse {
	
	public static void main(String[] args) {
		ProductWarehouse pw = new ProductWarehouse("Soap", 1000);
		
		//Testing getName, setName and toString method
		assert(pw.getName() == "Soap");
		pw.setName("Biscuits");
		assert(pw.getName()== "Biscuits");
		System.out.println(pw);
		
		//Testing getCapacity, getBalance
		assert(pw.getBalance() == 0);
		assert(pw.getCapacity() == 1000);
		
		//Testing howMuchSpaceLeft(), takeFromWarehouse(double amount), addToWarehouse(double amount) methods
		pw.addToWarehouse(400);
		assert(pw.howMuchSpaceLeft() == 600);
		assert(pw.takeFromWarehouse(200) == 200);
		assert(pw.howMuchSpaceLeft() == 800);
	}
}
