package assignment3;

public class Circle extends Shape{
	private double radius;
	Shape circ;
	
	//Class methods
	public Circle() {
		radius = 1.0;
	}	
	
	public Circle(double radius) {
		this.radius = radius;
	}
	
	public Circle(double radius, String colour, boolean filled) {
		super(colour, filled);
		circ = new Shape(colour, filled);
		this.radius = radius;
	}
	
	public double getRadius() {
		return this.radius;
	}
	
	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public double getArea() {
		return (Math.PI * Math.pow(radius, 2));
	}
	
	public double getPerimeter() {
		return (2 * Math.PI * radius);
	}
	
	public String toString() {
		return "Radius of circle: "+radius+"; "+circ.toString();
	}
}
