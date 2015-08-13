public class Test
{
    public static void main (String [] args)
    {
		String sent = "Halloween";
		int x = sent.length();
		String ans="";

		for(int i=0; i < x / 2; i++)
		{
			if(i%2==0){
				ans = ans + sent.charAt(i);
			}
			else{
				ans = sent.charAt(x-i-2)+ans;
			}
			sent = sent.substring(1);
			System.out.println(ans);
		}

       /* String nums = "0123456789";
        int spot;
        int x=0;
        for(int i=0;i<10;i++)
        {
            nums = nums.substring(0,i) + ((int)nums.charAt(i)-40) + nums.substring(i+1);
            x += Integer.parseInt(nums.substring(i+5,i+6));
            System.out.println(x);
        }
        System.out.println("Nums: " + nums);*/
    }
}
