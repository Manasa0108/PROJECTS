package AirlineCore;


public interface Ticket {
	public boolean isAvailable();
	public void setAvailable();
	public void bookTicket();
	public int getSeatNo();
	public Flight getFlight();
	public float getPrice();
	public String toString();
}