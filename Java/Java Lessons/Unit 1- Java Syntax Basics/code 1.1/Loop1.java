/* Loop1.java
 * Tracks an investment of $1000 at 6% compounded anually
 * until it doubles */
public class Loop1{	
    public static void main(String [] args) 
    {
    	double money = 1000;
    	int year = 0;
        System.out.println("Year       Money");
		while(money < 2000){
			year += 1;
			money *= 1.06;
	        System.out.printf("%4d%12.2f\n", year, money);
		}
    }
}

