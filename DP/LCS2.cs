using System;

public class LCS2
{
    public static void Main()
    {
        string s1 = Console.ReadLine();
        string s2 = Console.ReadLine();

        int[,] dp = new int[s1.Length + 1, s2.Length + 1];

        for (int i = 1; i <= s1.Length; i++)
        {
            for (int j = 1; j <= s2.Length; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i, j] = dp[i - 1, j - 1] + 1;
                }
                else
                {
                    dp[i, j] = Math.Max(dp[i - 1, j], dp[i, j - 1]);
                }
            }
        }

        int lcsLength = dp[s1.Length, s2.Length];
        Console.WriteLine(lcsLength);

        if (lcsLength > 0)
        {
            char[] lcs = new char[lcsLength];
            int i = s1.Length, j = s2.Length, k = lcsLength - 1;

            while (i > 0 && j > 0)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    lcs[k] = s1[i - 1];
                    i--;
                    j--;
                    k--;
                }
                else if (dp[i - 1, j] > dp[i, j - 1])
                {
                    i--;
                }
                else
                {
                    j--;
                }
            }

            Console.WriteLine(new string(lcs));
        }
    }
}
