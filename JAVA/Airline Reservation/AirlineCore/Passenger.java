package AirlineCore;


public class Passenger extends Person{

	private String passportNo;
	private Ticket ticket;
	
	public Passenger(String passportNo){
		super(null,null,null,null);
		this.passportNo = passportNo;
	}

	public Passenger(String name,String dob,String email,String phoneNumber,String passportNo,Ticket ticket){
		super(name,dob,email,phoneNumber);
		this.passportNo = passportNo;
		this.ticket = ticket;
	}
	
	public String display(){
		return  " NAME           : " + getName() + "\n" +
			    " DATE OF BIRTH  : " + getDoB() + "\n" +
				" EMAIL ID       : " + getEMail() + "\n" +
				" ------------------------------\n\n";
	}

	@Override
	public boolean equals(Object o){
		if(this == o) return true;
		if(o == null) return false;
		Passenger p = (Passenger)o;
		return passportNo.equals(p.getPassportNo());
	}	


	public void cancelTicket(){
		ticket = null;
	}

	public String getPassportNo(){
		return passportNo;
	}

	

	public Ticket getTicket(){
		return ticket;
	}
	public String toString(){
		return 	((ticket == null)? " Sorry, your flight has been cancelled!" : ticket.toString()) + "\n" + 
				" NAME           : " + getName() + "\n" +
			    " DATE OF BIRTH  : " + getDoB() + "\n" +
				" EMAIL ID       : " + getEMail() + "\n" +
				" --------------------------------------------------------------------------------\n\n";
	}
}