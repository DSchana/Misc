using System;

namespace Arrays
{
    class Program
    {
        static void Main(string[] args)
        {
            // Declare a single dimensional array
            int[] array1 = new int[5];

            // Declare and set array element values
            int[] array2 = new int[] { 1, 2, 3, 4, 5 };

            // Alternate method
            int[] array3 = { 1, 2, 3, 4, 5 };

            // Declare 2 dimensional array
            int[,] multiDimensionalArray1 = new int[2, 4];

            // Declare and set multidimensional array
            int[,] multiDimensionalArray2 = { { 1, 2 }, { 1, 2, 3, 4 } };

            // Declare jagged array
            int[][] jaggedArray = new int[6][];

            // Set the values of the first array in the jagged array structure
            jaggedArray[0] = new int[4] { 1, 2, 3, 4 };
        }
    }
}
