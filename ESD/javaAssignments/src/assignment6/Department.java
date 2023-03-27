package assignment6;

import java.util.*;

public class Department {
	private String name;
    private List<Student> no_of_student;
    
    public Department(String name,List<Student> no_of_student) {
    	this.name = name;
    	this.no_of_student = no_of_student;
    }

    public List<Student> getStudentList() {

        return no_of_student;
    }

}