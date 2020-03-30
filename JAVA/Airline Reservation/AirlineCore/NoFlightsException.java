package AirlineCore;

public class NoFlightsException extends Exception{
	public String toString(){
		return " No Flights Matching Requirements Found!\n";
	}
}
