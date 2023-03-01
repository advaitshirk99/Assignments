package assignment3;

public class Student extends Person{
	private int numCourses =0;
	private String[] courses = new String[5];
	private int[] grades = new int[5];
	Person stud;
	
	//Class methods
	public Student(String name, String address) {
		super(name, address);
		this.stud = new Person(name, address);
	}
	
	public void addCourseGrade(String course, int grade) {
		this.courses[numCourses] = course;
		this.grades[numCourses++] = grade;
	}
	
	public void printGrades() {
		for(int i=0; i<numCourses; i++) {
			System.out.println(courses[i]+": "+grades[i]);
		}
	}
	
	public double getAverageGrade() {
		int sum=0;
		for(int i=0; i<numCourses; i++) sum += grades[i];
		return (sum/numCourses);		
	}
	
	public String toString() {
		return "Student: "+stud.name+"("+stud.address+")";
	}
}
