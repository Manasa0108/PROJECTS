package AirlineCore;

import java.util.*;

public class PassengerFunctions{
	public static Passenger search(ArrayList<Passenger> pList,String passportNo){
		for(int i = 0 ; i < pList.size() ; i++){
			if(pList.get(i).getPassportNo().equals(passportNo))
				return pList.get(i);
		}

		return null;
	}

	public static void display(ArrayList<Passenger> pList){
		if(pList.size() == 0){
			System.out.println(" No Passenger Found!");
		}

		for(int i = 0 ; i < pList.size(); i++)
			System.out.println(pList.get(i).display());
	}
}