package AirlineCore;

import java.util.*;


public class FlightFunctions{
	public static void display(ArrayList<Flight> fList) throws NoFlightsException{
		if(fList.size() == 0)
			throw new NoFlightsException();

		for(int i = 0 ; i < fList.size() ; i++)
			System.out.println(fList.get(i));
	}

	public static int search(ArrayList<Flight> fList,String flightNo) throws NoFlightsException{
		int rval = -1;
		for(int i = 0 ; i < fList.size() ; i++)
			if(fList.get(i).getFlightNo().equals(flightNo))
				rval = i;
		if(rval == -1)
			throw new NoFlightsException();
		return rval;
	}

	public static void searchSource(ArrayList<Flight> fList,String source) throws NoFlightsException{
		int count = 0;
		for(int i = 0 ; i < fList.size() ; i++){
			Flight tmp = fList.get(i);
			if(tmp.getSource().equals(source)){
				count++;
				System.out.println(tmp);
			}
		}
		if(count == 0)
			throw new NoFlightsException();
	}


	public static void searchDestination(ArrayList<Flight> fList,String destination) throws NoFlightsException{
		int count = 0;
		for(int i = 0 ; i < fList.size() ; i++){
			Flight tmp = fList.get(i);
			if(tmp.getDestination().equals(destination)){
				count++;
				System.out.println(tmp);
			}
		}
		if(count == 0)
			throw new NoFlightsException();
	}


	public static ArrayList<Flight> searchSourceDestination(ArrayList<Flight> fList,String source,String destination)
	throws NoFlightsException{
		ArrayList<Flight> fArr = new ArrayList<Flight>();
		
		for(int i = 0 ; i < fList.size() ; i++){
			Flight tmp = fList.get(i);
			if(tmp.getDestination().equals(destination) && tmp.getSource().equals(source))
				fArr.add(tmp);
		}
		if(fArr.size() == 0)
			throw new NoFlightsException();

		return fArr;
	}
}