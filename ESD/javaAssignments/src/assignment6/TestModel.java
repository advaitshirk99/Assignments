package assignment6;

import java.util.ArrayList;
import java.util.List;

public class TestModel {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student s1 = new Student("abc",1,"ES");
		Student s2 = new Student("def",2,"ES");
		Student s3 = new Student("ghi",3,"ES");
		Student s4 = new Student("jkl",4,"ES");
		Student s5 = new Student("mno",1,"VLSI");
		Student s6 = new Student("pqr",2,"VLSI");
		Student s7 = new Student("stu",3,"VLSI");
		Student s8 = new Student("vwx",4,"VLSI");
		
		List<Student> es_studs = new ArrayList<Student>();
		es_studs.add(s1);
		es_studs.add(s2);
		es_studs.add(s3);
		es_studs.add(s4);
		
		List<Student> vlsi_studs = new ArrayList<Student>();
		vlsi_studs.add(s5);
		vlsi_studs.add(s6);
		vlsi_studs.add(s7);
		vlsi_studs.add(s8);
		
		
		Department d1 = new Department("ES", es_studs);
		Department d2 = new Department("VLSI", vlsi_studs);
		
		List<Department> depts = new ArrayList<Department>();
		depts.add(d1);
		depts.add(d2);
		Institute i = new Institute("MSIS", depts);
		
		System.out.println("No of students in the institute : " + i.getCountOfStudent());
	}
}
