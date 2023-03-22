package assignment4;

public class BasicCalculator implements calculator {

	int cells[];
	int t;
	
	private BasicCalculator() {
		// TODO Auto-generated constructor stub
		cells=new int[2];
		t=0;
	}
	
	@Override
	public calculator put(int n) {
		// TODO Auto-generated method stub
			cells[t]=n;
			t=(t+1)%2;
		return this;
	}

	@Override
	public calculator add() {
		// TODO Auto-generated method stub
		cells[0]=cells[0]+cells[1];
		return this;
	}

	@Override
	public calculator sub() {
		// TODO Auto-generated method stub
		cells[0]=cells[0]-cells[1];
		return this;
	}

	@Override
	public calculator mul() {
		// TODO Auto-generated method stub
		cells[0]=cells[0]*cells[1];
		return this;
	}

	@Override
	public calculator div() {
		// TODO Auto-generated method stub
		if(cells[1]!=0)
		cells[0]=cells[0]/cells[1];
		return this;
	}

	@Override
	public calculator clear() {
		// TODO Auto-generated method stub
		cells[t]=0;
		return this;
	}

	@Override
	public calculator clearAll() {
		// TODO Auto-generated method stub
		cells[0]=cells[1]=0;
		t=0;
		return this;
	}

	@Override
	public int read() {
		// TODO Auto-generated method stub
		return cells[0];
	}

	@Override
	public calculator neg() {
		// TODO Auto-generated method stub
		cells[t]= cells[t]* -1;
		return this;
	}
	
	public static calculator getInstance() {
		
		BasicCalculator cal = new BasicCalculator();
		cal.clearAll();
		return cal;
	}

}
