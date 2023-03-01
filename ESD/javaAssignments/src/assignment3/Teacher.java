package assignment3;

public class Teacher extends Person {
	
	private int numCourses=0;
	private String[] courses = new String[5];
	Person teacher;
	
	//Class methods
	public Teacher(String name, String address) {
		super(name, address);
		this.teacher = new Person(name, address);
	}
	
	public boolean addCourse(String course) {
		if(numCourses == 0) {
			courses[numCourses++] = course;
			return true;
		}
		
		for(int i=0; i<numCourses; i++) {
			if(courses[i] == course) return false;
		}
		courses[numCourses++] = course;
		return true;
	}
	
	public boolean removeCourse(String course) {
		if(numCourses == 0) return false;
		for(int i=0; i<numCourses; i++) {
			if(courses[i] == course) {
				courses[i] = "";
				numCourses--;
				return true;
			}
		}
		return false;
	}
	
	public String toString() {
		return "Teacher: "+name+"("+address+")";
	}
}
