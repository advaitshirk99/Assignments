package assignment3;

public class ProductWarehouse extends Warehouse{
	private String name;
	Warehouse wh;
	public ProductWarehouse(String name, double capacity){
		super(capacity);
		this.wh = new Warehouse(capacity);
		this.setName(name);
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	@Override
	public String toString() {
		return "Name: "+name+"; "+ wh.toString();
	}
}
