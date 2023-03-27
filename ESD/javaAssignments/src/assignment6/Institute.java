package assignment6;

import java.util.*;

public class Institute {
	
	private String name;
	
    private List<Department> departments;
    
    public Institute(String name, List<Department> departments) {
    	this.name = name;
    	this.departments = departments;
    }
    
    public int getCountOfStudent() {
        int count = 0;
    	for(Department department : departments) {
    		List<Student> stud_list = department.getStudentList();
    		for(Student student : stud_list) {
    			count++;
    		}
    	}
        return count;
    }
}