using System.Diagnostics;

namespace lab
{
    class SHKRSRT
    {
        static int[] array(int n)
        {
            Random r = new Random();
            int[] array = new int[10];
            for (int i = 0; i < 10; i++)
            {
                array[i] = r.Next(20 * n);
            }
            return array;
        }
        static void SortArray(int[] array)
        {
            bool swapped = true;
            int start = 0;
            int end = array.Length;

            while (swapped == true)
            {
                swapped = false;
                for (int i = start; i < end - 1; ++i)
                {
                    if (array[i] > array[i + 1])
                    {
                        int temp = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = temp;
                        swapped = true;
                    }
                }
                if (swapped == false)
                    break;
                swapped = false;
                end = end - 1;
                for (int i = end - 1; i >= start; i--)
                {
                    if (array[i] > array[i + 1])
                    {
                        int temp = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = temp;
                        swapped = true;
                    }
                }
                start = start + 1;
            }
            for (int i = 0; i < array.GetLength(0); i++)
            {
                Console.Write($"{array[i]}; ");
            }
        }
        static void Main()
        {
            Stopwatch stopWatch = new Stopwatch();
            int m;
            Console.Write("Enter N: ");
            m = int.Parse(Console.ReadLine());
            int[] A = array(m);
            for (int i = 0; i < A.GetLength(0); i++)
            {
                Console.Write($"{A[i]}; ");
            }
            Console.WriteLine();
            stopWatch.Start();
            SortArray(A);
            Console.WriteLine();
            stopWatch.Stop();
            TimeSpan ts = stopWatch.Elapsed;
            Console.WriteLine(ts.TotalMilliseconds);
        }
    }
}