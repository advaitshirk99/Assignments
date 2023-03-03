package assignment3;

public class Rectangle extends Shape{
	private double length, width;
	Shape rect;
	
	public Rectangle() {
		length = width = 1.0;
	}
	
	public Rectangle(double width, double length) {
		this.length = length;
		this.width = width;
	}
	
	public Rectangle(double width, double length, String colour, boolean filled) {
		super(colour, filled);
		this.length = length;
		this.width = width;
	}
	
	public double getWidth() {
		return this.width;
	}
	
	public void setWidth(double width) {
		this.width = width;
	}
	
	public double getLength() {
		return this.length;
	}
	
	public void setLength(double length) {
		this.length = length;
	}
	
	public double getArea() {
		return (length * width);
	}
	
	public double getPerimeter() {
		return (2 * (width + length));
	}
	
	public String toString() {
		return "Rectangle length: "+length+"; width: "+width+"; "+rect.toString();
	}
}
