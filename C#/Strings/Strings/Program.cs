using System;

namespace Strings
{
    class Program
    {
        static void Main(string[] args)
        {
            // Declare without initializing
            string massage1;

            // initializa to null
            string message2 = null;

            // Initializa as empty string
            // Do not use th litteral ""
            string message3 = String.Empty;

            // Initialize with regular string literal
            string reg = "Reular literal";

            // Initialize with verbatium string literal
            string verb = @"Verbatium string literal";

            // In local variables (i.e. within a method body) 
            // you can use implicit typing. 
            var temp = "I'm still a strongly-typed System.String!";

            // Use the String constructor only when creating 
            // a string from a char*, char[], or sbyte*. See 
            // System.String documentation for details. 
            char[] letters = { 'A', 'B', 'C' };
            string alphabet = new string(letters);

            // Immutablity of strings //
            string s1 = "A string is more ";
            string s2 = "than the sum of its chars";
            s1 += s2;

            Console.WriteLine(s1);  // output: A string is more than the sum of its chars

            // Regular and verbatium string litterals //

            string columns = "Column 1\tColumn 2\tColumn 3";
            //Output: Column 1        Column 2        Column 3 

            string rows = "Row 1\r\nRow 2\r\nRow 3";
            /* Output:
              Row 1
              Row 2
              Row 3
            */

            string title = "\"The \u00C6olean Harp\", by Samuel Taylor Coleridge";
            //Output: "The Æolean Harp", by Samuel Taylor Coleridge

            string filePath = @"C:\Users\scoleridge\Documents\";
            //Output: C:\Users\scoleridge\Documents\ 

            string text = @"My pensive SARA ! thy soft cheek reclined
    Thus on mine arm, most soothing sweet it is
    To sit beside our Cot,...";
            /* Output:
            My pensive SARA ! thy soft cheek reclined
               Thus on mine arm, most soothing sweet it is
               To sit beside our Cot,... 
            */

            string quote = @"Her name was ""Sara.""";
            //Output: Her name was "Sara."

            // Format strings //

            // Get user input
            Console.WriteLine("Enter a number");
            string input = Console.ReadLine();

            // Convert inputed sring to int
            int j;
            Int32.TryParse(input, out j);

            // Write a different string each iteration. 
            string s;
            for (int i = 0; i < 10; i++)
            {
                // A simple format string with no alignment formatting.
                s = System.String.Format("{0} times {1} = {2}", i, j, (i * j));
                System.Console.WriteLine(s);
            }

            // Keep the consol window open in debug mode
            Console.ReadKey();

            // Substrings //

            string s3 = "visual C# express";
            Console.WriteLine(s3.Substring(7, 2));
            // Output: C#

            System.Console.WriteLine(s3.Replace("C#", "Basic"));
            // Output: "Visual Basic Express" 

            // Index values are zero-based 
            int index = s3.IndexOf("C");
            // index = 7

            // Accessing indevidual characters //

            string s5 = "printing backwards";

            for (int i = 0; i < s5.Length; i++)
            {
                System.Console.Write(s5[s5.Length - i - 1]);
            }
            // Output: sdrawkcab gnitnirP

            // Upper and Lower Cases //

            string question = "hOW DOES mICROSOFT wORD DEAL WITH THE cAPS lOCK KEY?";
            System.Text.StringBuilder sb = new System.Text.StringBuilder(question);

            for (int j = 0; j < sb.Length; j++)
            {
                if (System.Char.IsLower(sb[j]) == true)
                    sb[j] = System.Char.ToUpper(sb[j]);
                else if (System.Char.IsUpper(sb[j]) == true)
                    sb[j] = System.Char.ToLower(sb[j]);
            }
            // Store the new string. 
            string corrected = sb.ToString();
            System.Console.WriteLine(corrected);
            // Output: How does Microsoft Word deal with the Caps Lock key?

            // Using string builder for strings //
            System.Text.StringBuilder sb1 = new System.Text.StringBuilder("Rat: the ideal pet");
            sb1[0] = 'C';
            System.Console.WriteLine(sb1.ToString());
            System.Console.ReadLine();

            //Outputs Cat: the ideal pet

            // StringBuilder object is used to create a string from a set of numeric types

            System.Text.StringBuilder sb2 = new System.Text.StringBuilder();

            // Create a string composed of numbers 0 - 9 
            for (int i = 0; i < 10; i++)
            {
                sb2.Append(i.ToString());
            }
            System.Console.WriteLine(sb2);  // displays 0123456789 

            // Copy one character of the string (not possible with a System.String)
            sb2[0] = sb2[9];

            System.Console.WriteLine(sb2);  // displays 9123456789
        }
    }
}