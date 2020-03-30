package AirlineCore;

public class InsufficientTicketsException extends Exception{
	public String toString(){
		return " No Tickets Available! Please Check again later!\n";
	}
}
