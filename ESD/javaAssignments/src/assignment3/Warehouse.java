package assignment3;

public class Warehouse {
	//Class variables
	private double capacity, balance; 
	
	//Class methods
	public Warehouse(double capacity) {
		//Empty warehouse can store 1000 products
		this.capacity = capacity;
		this.balance = 0;
		
	}

	public double getCapacity() {
		return capacity;
	}

	public double getBalance() {
		return balance;
	}
	
	public double howMuchSpaceLeft() {
		return (capacity - balance);
	}
	
	public void addToWarehouse(double amount) {
		if((balance + amount) < capacity) {
			balance += amount;
			System.out.println("Added "+amount+" more products");
		}
		else System.out.println("Adding more items will exceed maximum capacity");
	}
	
	public double takeFromWarehouse(double amount) {
		if(balance >= amount) {
			balance -= amount;
			return amount;
		}
		System.out.println("Could only get "+balance+" products");
		return balance;
	}
	
	public String toString() {
		return "Max capacity: " + capacity + "; Balance: " + balance;
	}
}
