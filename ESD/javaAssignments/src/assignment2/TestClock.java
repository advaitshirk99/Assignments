package assignment2;
import java.util.*;  
public class TestClock {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		Clock clk = new Clock();
		System.out.println("h:"+clk.hours+" m:"+clk.minutes+" s:"+clk.seconds+" mode:"+clk.mode);
		int[] time = new int[3];
		for(int i=0; i<3; i++) {
			time[i] = scan.nextInt();
		}
		scan.close();
		
		clk.setClock(time[0], time[1], time[2]);
		clk.setMode("PM");
		clk.checkValidity(time[0], time[1], time[2]);
	}
}
