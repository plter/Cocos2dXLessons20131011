package cn.eoe.types;

public class Man extends People {

	public Man(int age) {
		super(age);
	}
	
	public void fuckWoman(){
		
	}
	
	
	@Override
	public int getAge() {
		System.out.println("Man get age");
		return super.getAge();
	}

}
