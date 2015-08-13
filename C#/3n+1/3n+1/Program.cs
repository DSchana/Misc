using System;

namespace _3n_1
{
    class Program
    {
        static void Main(string[] args)
        {
            string n_in;
            int n;
            int count = 0;

            n_in = Console.ReadLine();

            Int32.TryParse(n_in, out n);

            while (n != 1)
            {
                if (n % 2 == 1)
                {
                    n = (3 * n) + 1;
                }
                else if (n % 2 == 0)
                {
                    n /= 2;
                }
                count++;
            }
            Console.WriteLine(count);
        }
    }
}
