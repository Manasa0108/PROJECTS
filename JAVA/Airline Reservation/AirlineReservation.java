import java.util.*;

import AirlineCore.*;

class AirlineReservation{
	private static ArrayList<Flight> fList = new ArrayList<Flight>();
	private static ArrayList<Passenger> pList = new ArrayList<Passenger>();
	private static Scanner input = new Scanner(System.in);
	
	private static void clearScreen() {  
	    System.out.print("\033[H\033[2J");  
	    System.out.flush();  
	}  
	
	private static void Wait(){
		System.out.print(" Press ENTER key to continue......");
		input.nextLine();
	}


	public static void main(String[] args){
		
			String name,email,phoneNumber,dob;
			String passportNo;
			String airline,flightNo;
			String source,destination;
			String arrival,departure;
			String catergory;

			int opt = -1;
			int no_b,no_e;
			float cost_b,cost_e;
			Ticket t;
			Passenger p;
			Flight f;

			while(opt != 7){
			try{
				clearScreen();
				System.out.println("\t\t\t\tAIRLINE RESERVATION SYSTEM\n");
				System.out.println(" 1 - Add Flight");
				System.out.println(" 2 - Cancel Flight");
				System.out.println(" 3 - Book Ticket");
				System.out.println(" 4 - Cancel Ticket");
				System.out.println(" 5 - View Flights");
				System.out.println(" 6 - Passenger Help Desk");
				System.out.println(" 7 - Exit");
				System.out.println(" -----------------------");
				System.out.print  (" Enter your choice : ");
				opt = input.nextInt();
				input.nextLine();

				switch(opt){
					case 1 :{
								clearScreen();
								System.out.println("\t\t\t\tFLIGHT ADDITION WINDOW\n");
								System.out.print(" Enter the Airline                 : ");
								airline = input.nextLine();
								System.out.print(" Enter the Flight Number           : ");
								flightNo = input.nextLine();
								System.out.print(" Enter the Source City             : ");
								source = input.nextLine();
								System.out.print(" Enter the Destination City        : ");
								destination = input.nextLine();
								System.out.print(" Enter departure[dd-mm-yyyy hh:mm] : ");
								departure = input.nextLine();
								System.out.print(" Enter arrival[dd-mm-yyyy hh:mm]   : ");
								arrival = input.nextLine();
								System.out.print(" No. Business class tickets        : ");
								no_b = input.nextInt();
								System.out.print(" Cost of Business class tickets    : ");
								cost_b = input.nextFloat();
								System.out.print(" No. Economy class tickets         : ");
								no_e = input.nextInt();
								System.out.print(" Cost of Economy class Ticket      : ");
								cost_e = input.nextFloat();
								input.nextLine();

								try{
									f = new Flight(flightNo,airline,source,destination,arrival,departure);
									f.generateTickets(no_b,no_e,cost_b,cost_e);
									fList.add(f);
									System.out.println("\n Successfully added flight!");
								}
								catch(InvalidDateException ide){
									System.out.println(ide);
								}
								
								Wait();

							}
							break;
					case 2:{
								clearScreen();
								System.out.println("\t\t\t\tFLIGHT CANCELLATION WINDOW");
								System.out.print  (" Enter the flight number to cancel: ");
								flightNo = input.nextLine();
								try{
									int index = -1;
									index  = FlightFunctions.search(fList,flightNo);
									System.out.println(fList.get(index));
									System.out.println(" Are you sure you want to cancel the flight? 1/0 ");
									opt = input.nextInt();
									input.nextLine();
									
									if(opt== 1){
										fList.remove(index);
										for(int i = 0 ; i < pList.size(); i++)
											if(pList.get(i).getTicket().getFlight().getFlightNo().equals(flightNo))
												pList.get(i).cancelTicket();
									}

								}
								catch(NoFlightsException nfe){
									System.out.println(nfe);
								}
							}
							break;
					case 3:{
								clearScreen();
								System.out.println("\t\t\t\tTICKET BOOKING WINDOW\n");
								System.out.print(" Enter the source: ");
								source = input.nextLine();
								System.out.print(" Enter the destination: ");
								destination = input.nextLine();
								try{
									ArrayList<Flight> fArr = FlightFunctions.searchSourceDestination(fList,source,destination);
									
									for(int i = 0 ; i < fArr.size() ; i++)
										System.out.println(fArr.get(i));
									
									System.out.print(" Enter flight number from above list: ");
									flightNo = input.nextLine();
									f = new Flight(flightNo);
									
									if(fArr.indexOf(f) == -1){
										System.out.print(" Please enter a valid flight number");
									}
									else{
										System.out.println(" Enter the number of tickets to book: ");
										int number = input.nextInt();
										input.nextLine();
											
										int index = fArr.indexOf(f);	
								
										if(number > 0){
											
											for(int i = 0 ; i < number ; i++){
												try{
													clearScreen();
													System.out.println("\t\t\t\tENTER PASSENGER DETAILS\n");
														
													System.out.print(" Enter the catergory[Business/Economy]: ");
													catergory = input.nextLine();

													t = fArr.get(index).bookTicket(catergory);

													System.out.print(" Enter the name       : ");
													name = input.nextLine();
													System.out.print(" Enter the DOB        : ");
													dob = input.nextLine();
													System.out.print(" Enter the email      : ");
													email = input.nextLine();
													System.out.print(" Enter the PH NO      : ");
													phoneNumber = input.nextLine();
													System.out.print(" Enter the passportNo : ");
													passportNo = input.nextLine();

													pList.add(new Passenger(name,dob,email,phoneNumber,passportNo,t));
												}
												catch(InsufficientTicketsException ite){
													System.out.println(ite);
												}		
											}
										}
										else{
											System.out.println(" Invalid Input!Please Try again!");
										}
									}
								}
								catch(NoFlightsException nfe){
									System.out.println(nfe);
								}
								Wait();
								}
							break;
					case 4:{
								clearScreen();
								System.out.println("\t\t\t\tTICKET CANCELLATION WINDOW\n");
								System.out.print(" Enter the passport number: ");
								passportNo = input.nextLine();
								p = new Passenger(passportNo);
								int index = pList.indexOf(p);
								
								if(index == -1){
									System.out.println(" No such passenger exists!");
								}
								else{
									System.out.print(" Are you sure you want to cancel your ticket? 1/0 ");
									opt = input.nextInt();
									if(opt == 1){
										pList.get(index).getTicket().setAvailable();
										pList.remove(index);
										System.out.println(" Successfully cancelled ticket!");
									}
								}
								Wait();	
							}
							break;
					case 5:{
									clearScreen();
									System.out.println("\t\t\t\tVIEW FLIGHTS\n");
									System.out.println(" 1 - Based on Source");
									System.out.println(" 2 - Based on Destination");
									System.out.println(" 3 - View All");
									System.out.println(" 4 - Back to Main Menu");
									System.out.println(" ------------------------");
									System.out.print  (" Enter your choice: ");
									opt = input.nextInt();
									input.nextLine();
									switch(opt){
										case 1: {
													clearScreen();
													System.out.print(" Enter the source: ");
													source = input.nextLine();
													try{
														FlightFunctions.searchSource(fList,source);
													}
													catch(NoFlightsException nfe){
														System.out.println(nfe);
													}
												}
												break;
										case 2: {
													clearScreen();
													System.out.print(" Enter the destination: ");
													destination = input.nextLine();
													try{
														FlightFunctions.searchDestination(fList,destination);
													}
													catch(NoFlightsException nfe){
														System.out.println(nfe);
													}
												}
												break;
										case 3: {
													clearScreen();
													try{
														FlightFunctions.display(fList);
													}
													catch(NoFlightsException nfe){
														System.out.println(nfe);
													}
												}
												break;
										case 4: break;
									}
							Wait();
							}
							break;
					case 6:{
								clearScreen();
								System.out.println("\t\t\t\tPASSENGER HELP DESK\n");
								System.out.println(" 1 - Based on Passport Number");
								System.out.println(" 2 - All Passengers");
								System.out.println(" 3 - Back to Main Menu");
								System.out.println(" ----------------------------");
								System.out.print  (" Enter your choice: ");
								opt = input.nextInt();
								input.nextLine();
								switch(opt){
									case 1 : {
												clearScreen();
												System.out.print(" Enter passportNo: ");
												passportNo = input.nextLine();
												p = PassengerFunctions.search(pList,passportNo);
												if(p == null)
													System.out.println(" \nNo Passengers Found!");
												else
													System.out.println(p);
											}	
											break;
									case 2 : {
												clearScreen();
												PassengerFunctions.display(pList);
											}
											break;
									case 3 : break;
									default: System.out.println("\n Invalid input!");
	 							
								}
								Wait();
							}
							break;
					case 7 : 
					default: break;
				}
			}
			catch(InputMismatchException ime){
				input.nextLine();
				opt = 8;
			}
		}
	}
}
