package assignment3;

public class Square extends Rectangle{
	private double side;
	Rectangle sq;
	
	//Class methods
	public Square() {
		this.side = 1.0;
	}
	
	public Square(double side) {
		super(side, side);
		this.side = side;
	}
	
	public Square(double side, String colour, boolean filled) {
		super(side, side, colour, filled);
		this.side = side;
	}
	
	public double getSide() {
		return this.side;
	}
	
	public void setSide(double side) {
		this.side = side;
	}
	
	@Override
	public void setWidth(double size) {
		sq.setWidth(size);
	}
	
	@Override
	public void setLength(double size) {
		sq.setLength(size);
	}
	
	@Override
	public String toString() {
		return "Side of square: "+side+"; "+sq.toString();
	}
}
