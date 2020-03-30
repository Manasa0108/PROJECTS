package AirlineCore;

public class BusinessClassTicket implements Ticket{
	private int seatNo;
	private float price;
	private char location;//Aisle,Window
	private Flight f;
	private boolean booked = false;

	public BusinessClassTicket(Flight f,int seatNo,float price){
		this.f = f;
		this.seatNo = seatNo;
		this.price = price;
		setLocation();
	}

	public String spaces(String s){
		String k = "";
		for(int i = s.length();i<20;i++){
			//System.out.print(" ");
			k+=" ";
		}
		return k;   
	}
	public Flight getFlight(){
		return f;
	}

	public void bookTicket(){
		booked = true;
	}

	public boolean isAvailable(){
		return booked == false;
	}

	public void setAvailable(){
		booked = false;
	}


	public int getSeatNo(){
		return seatNo;
	}

	public float getPrice(){
		return price;
	}

	private void setLocation(){
		switch( (seatNo-1) % 2){
			case 0 : location = 'W'; break;
			case 1 : location = 'A'; break;
			default: location = '\0'; 
		}
	}


	public String toString(){
		return " FROM           : " + f.getSource() + spaces(f.getSource()) +      "DEPARTURE : " + f.getDeparture() + "\n" +
			   " DESTINATION    : " + f.getDestination() + spaces(f.getDestination()) + "ARRIVAL   : " + f.getArrival() + "\n\n" +
			   " --------------------------------------------------------------------------------" + "\n\n" +
			   " CLASS          : Business" + "\n" + 
			   " SEAT NO        : " + seatNo + " " + location + "\n" +
			   " PRICE          : " + price;
	}

}