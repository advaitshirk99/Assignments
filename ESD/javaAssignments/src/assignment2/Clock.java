package assignment2;

public class Clock {
	
	int hours, minutes, seconds;
	String mode;
	Clock(){
		hours = minutes = seconds = 0;
		mode = "AM";
	}

	public void checkValidity(int h, int m, int s) {
		 if(h>12) System.out.println("Invalid hour");
		 if(m>59) System.out.println("Invalid minutes");
		 if(s>59) System.out.println("Invalid seconds");
	}
	
	public void setMode(String mode) {
		this.mode = mode;
	}
	
	public void	setClock(int hours, int minutes, int seconds){
		this.hours = hours;
		this.minutes = minutes;
		this.seconds = seconds;
	}	
}
