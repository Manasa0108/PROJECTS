package AirlineCore;

public abstract class Person{
	private String name;
	private String phoneNumber;
	private String dob;
    private String email;

	public Person(String name, String dob, String email,String phoneNumber){
		this.name = name;
		this.dob = dob;
		this.email = email;
		this.phoneNumber = phoneNumber;
	}
	public String getName(){
		return name;
	}

	public String getDoB(){
		return dob;
	}
	public String getEMail(){
		return email;
	}
}
