package GenericExamples;

public class GenericPair<T, S>
{
   private T first;
   private S second;

   public GenericPair(T firstElement, S secondElement)
   {
      first = firstElement;
      second = secondElement;
   }

   public T getFirst()
   {
      return first;
   }
   
   public S getSecond()
   {
      return second;
   }

   public GenericPair<S, T> swap() {
      GenericPair<S, T> temp = new GenericPair<>(this.getSecond(),this.getFirst());
      return temp;
   }

   public static void main(String[] args)
   {
      GenericPair<String, Integer> p = new GenericPair<>("Lucky Number", 13);
      GenericPair<Integer, String> q = p.swap();
      String s1 = (String) p.getFirst();
      System.out.println(s1);
      String s2 = q.getFirst().toString();
      System.out.println(s2);
   }

}
