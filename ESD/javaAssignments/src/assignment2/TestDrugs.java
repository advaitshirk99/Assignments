package assignment2;

public class TestDrugs {

	public static void main(String[] args) {
		
		Operations op = new Operations();
		op.insertDrug(123, 999, 1, "abc", "def");
		op.insertDrug(321, 888, 2, "xyz", "varsha");
		op.insertDrug(456, 777, 3, "pqr", "advait");
		op.insertDrug(789, 666, 4, "lmn", "saandesh");
		op.insertDrug(874, 555, 5, "std", "lmnop");

		op.checkAvailability(321, "xyz");
		op.updateDrug(321, 5, 1000);
	}
}
