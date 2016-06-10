import java.util.ArrayList;
import java.util.Scanner;

public class Josephus {

    public static void main ( String[] args)
    {
       int numberOfPeople, gap, newGap, counter;
       ArrayList<Integer> people = new ArrayList<Integer>();
       Scanner in = new Scanner(System.in);

       System.out.println("Enter the number of people: ");
       numberOfPeople = in.nextInt();
       in.nextLine();

       System.out.println("Enter the gap between people: ");
       gap = in.nextInt();
       
       for (int i = 1; i <= numberOfPeople; i++) {
           people.add(new Integer(i));
       }
       
       counter = gap - 1;
       newGap = gap;

       System.out.println("The order is: ");


       while (!(people.isEmpty())) {
          System.out.println(people.remove(counter));
          numberOfPeople = numberOfPeople - 1;
          if (numberOfPeople > 0)
             counter = (counter + gap - 1) % numberOfPeople;
       }
   }
}
