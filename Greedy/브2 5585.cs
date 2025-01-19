namespace Algorithm
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int n, answer = 0;
            n = int.Parse(Console.ReadLine());

            n = 1000 - n;

            int[] coins = new int[] { 500, 100, 50, 10, 5, 1 };

            for (int i = 0; i < 6; i++)
            {
                answer += (n / coins[i]);
                n %= coins[i];
            }

            Console.WriteLine(answer);
        }
    }
}
