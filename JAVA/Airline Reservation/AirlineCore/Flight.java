package AirlineCore;

import java.text.SimpleDateFormat;
import java.util.*;

public class Flight{
	private String flightNo;
	private String airline;
	private String source;
	private String destination;
	private ArrayList <BusinessClassTicket> businessTicket = new ArrayList<BusinessClassTicket>();
	private ArrayList <EconomyClassTicket>  economyTicket =  new ArrayList<EconomyClassTicket>();
	private Date arrival;
	private Date departure;
	
	public Flight(String flightNo){
		this.flightNo = flightNo;
	}

	public Flight(String flightNo,String airline,String source,String destination,
	       String arrival,String departure)
		  throws InvalidDateException{
		
		SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy HH:mm");
		this.flightNo = flightNo;
		this.airline = airline;
		this.source = source;
		this.destination = destination;
		try{
			this.arrival = sdf.parse(arrival);
			this.departure = sdf.parse(departure);
		}
		catch(Exception e){
			throw new InvalidDateException();
		}

		if(this.departure.before(new Date()))
			throw new InvalidDateException();
		if(this.arrival.before(this.departure))
			throw new InvalidDateException();

	}

	public void generateTickets(int no_business,int no_economy,float b_cost,float e_cost){
		for(int i = 0 ; i < no_business ; i++)
			businessTicket.add(new BusinessClassTicket(this,i+1,b_cost));

		for(int i = 0 ; i < no_economy ; i++)
			economyTicket.add(new EconomyClassTicket(this,i+1,e_cost));
	}

	public Ticket bookTicket(String category) throws InsufficientTicketsException{
		if(category.equals("Business")){
			if(noBusinessLeft() == 0)
				throw new InsufficientTicketsException();
			for(int i = 0 ; i < businessTicket.size() ; i++)
				if(businessTicket.get(i).isAvailable()){
					businessTicket.get(i).bookTicket();
					return businessTicket.get(i);
				}
		}
		else{
			if(noEconomyLeft() == 0)
				throw new InsufficientTicketsException();
			for(int i = 0 ; i < economyTicket.size() ; i++)
				if(economyTicket.get(i).isAvailable()){
					economyTicket.get(i).bookTicket();
					return economyTicket.get(i);
				}
		}
		return null;
	}

	private int noEconomyLeft(){
		int count = 0;
		for(int i = 0 ; i < economyTicket.size() ; i++)
			if(economyTicket.get(i).isAvailable())
				count++;

		return count;
	}

	private int noBusinessLeft(){
		int count = 0;
		for(int i = 0 ; i < businessTicket.size() ; i++)
			if(businessTicket.get(i).isAvailable())
				count++;

		return count;
	}

	public String getSource(){
		return source;
	}

	public String getDestination(){
		return destination;
	}

	public String getFlightNo(){
		return flightNo;
	}

	public Date getArrival(){
		return arrival;
	}

	public Date getDeparture(){
		return departure;
	}

	@Override
	public boolean equals(Object o){
		if(this == o) return true;
		if(o == null) return false;
		Flight f = (Flight)o;
		if(flightNo.equals(f.getFlightNo()))
			return true;
		return false;
	}

	public String toString(){
		return " Airline                  : " + airline + "\n" +
			   " Flight Number            : " + flightNo + "\n\n" +
			   " Source                   : " + source + "\n" +
			   " Destination              : " + destination + "\n\n" +
			   " Departure                : " + departure + "\n" + 
			   " Arrival                  : " + arrival + "\n\n" +
			   " Economy Seats Available  : " + noEconomyLeft() + "\n" +
			   " COST                     : " + economyTicket.get(0).getPrice() + "\n\n" +
			   " Business Seats Available : " + noBusinessLeft() + "\n\n" +
			   " COST                     : " + businessTicket.get(0).getPrice() + "\n" +
			   " -------------------------------------------------";
	}
}