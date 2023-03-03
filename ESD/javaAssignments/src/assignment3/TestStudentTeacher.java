package assignment3;

public class TestStudentTeacher {

	public static void main(String[] args) {
		Student student = new Student("ABC", "abc road");
		Teacher teacher = new Teacher("ZYX", "zyx road");
		
		//Testing Teacher class methods
		assert(teacher.addCourse("Java") == true);
		assert(teacher.addCourse("Java") == false);
		assert(teacher.removeCourse("ESD") == false);
		assert(teacher.addCourse("ESD") == true);
		assert(teacher.removeCourse("ESD") == true);
		System.out.println(teacher);
		
		//Testing Student class methods
		student.addCourseGrade("Java", 9);
		student.addCourseGrade("ESD", 8);
		student.addCourseGrade("IoT", 8);
		student.addCourseGrade("DSA", 10);
		student.printGrades();
		assert(student.getAverageGrade() == 8.0);
		System.out.println(student);
	}
}
