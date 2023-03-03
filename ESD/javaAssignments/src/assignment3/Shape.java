package assignment3;

public class Shape {
	private String colour;
	private boolean filled;
	
	//Class methods
	public Shape() {
		this.colour = "red";
		this.filled = true;
	}
	
	public Shape(String colour, boolean filled) {
		this.colour = colour;
		this.filled = filled;
	}
	
	public String getColour() {
		return colour;
	}
	
	public void setColour(String colour) {
		this.colour = colour;
	}
	
	public boolean isFilled() {
		return filled;
	}
	
	public void setFilled(boolean filled) {
		this.filled = filled;
	}
	
	@Override
	public String toString() {
		return "Colour: "+colour+" Filled: "+filled;
	}
}
