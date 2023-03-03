package assignment3;

public class TestAllShapes {

	public static void main(String[] args) {
		Square sq1 =  new Square(10, "blue", true);
		Circle c1 = new Circle(5, "green", false);
		Square sq2 =  new Square(20);
		Circle c2 = new Circle(8);
		
		//Testing Square class methods
		assert(sq1.getSide() == 10);
		assert(sq2.getSide() == 20);
		sq1.setSide(11);
		sq2.setSide(22);

		assert(sq1.getArea() == 100.0);
		assert(sq2.getArea() == 400.0);
		assert(sq1.getColour() == "blue");
		assert(sq2.getColour() == "red");
		assert(sq1.isFilled() == true);
		assert(sq2.isFilled() == true);
		assert(sq1.getPerimeter() == 40.0);
		assert(sq2.getPerimeter() == 80.0);
		
		//Testing Circle class methods
		assert(c1.getRadius() == 5);
		assert(c1.getColour() == "green");
		assert(c1.isFilled() == false);
		assert(c1.getArea() == 78.53981633974483);
		assert(c2.getArea() == 201.06192982974676);
		assert(c2.getRadius() == 8);
		assert(c2.getColour() == "red");
		assert(c2.isFilled() == true);
	}

}
