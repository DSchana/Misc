import java.util.*;

public class CarLog{
    public int readInt(BufferedReader inFile){
	    String line = inFile.readLine ();
	    return Integer.parseInt(line);
    }

    public static void main(String []args)
    {
	BufferedReader inFile = null;
	int num;
	try
	{
	    inFile = new BufferedReader (new FileReader ("cars.txt"));
	}
	catch (IOException e)
	{
	}
	num = readInt(inFile);
	for(int i=0;i<num;i++)
	
    
	inFile.close();
    }
}


public class Offence{
    private String when;  
    private String sig;
    
    public Car(String wh,String id){
	when = wh;
	sig = id;
    }
    public String toString()
    {
	return "("+when+"--"+sig+")";
    }
} 

    
