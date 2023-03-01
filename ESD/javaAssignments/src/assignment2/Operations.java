package assignment2;
import java.util.*;

public class Operations {
	Drugs[] drugList = new Drugs[5];
	int count=0;
	
	public void insertDrug(int drug_id, int price, int stock_pos, String drug_name, String manufacturer) {
		drugList[count] = new Drugs();
		drugList[count].drug_id = drug_id;
		drugList[count].drug_name = drug_name;
		drugList[count].price = price;
		drugList[count].manufacturer = manufacturer;
		drugList[count].stock_pos = stock_pos;
		count++;
	}
	
	public void checkAvailability(int drug_id, String drug_name) {
		for(int i=0; i<count; i++){
			if(drugList[i].drug_id == drug_id && drugList[i].drug_name == drug_name) {
				displayDetails(drugList[i]);
				checkQuantity(drugList[i]);
				return;
			}
		}
		System.out.println("Drug ID:"+drug_id+" Drug Name:"+drug_name+" - Not found");
	}
	
	public void displayDetails(Drugs drug) {
		System.out.println("Drug ID:"+drug.drug_id+"\nDrug Name:"+drug.drug_name+"\nManufacturer:"+drug.manufacturer+"\nPrice:"+drug.price+"\nStock position:"+drug.stock_pos);
	}
	
	private void checkQuantity(Drugs drug) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter the required quantity:");
		int quant = scan.nextInt();
		if (quant <= drug.stock_pos) {
			System.out.println("Total price: "+ (quant*drug.price));
		}
		else System.out.println("Required quantities not in stock");
		scan.close();
	}
	
	public void updateDrug(int id, int quant, int price) {
		for(int i=0; i<count; i++) {
			if(id == drugList[i].drug_id) {
				drugList[i].stock_pos = quant;
				drugList[i].price = price;
				System.out.println("Updated drug details");
			}
		}
	}
}
