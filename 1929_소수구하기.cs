using System;
using System.Text;

namespace study_.net
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();

            int M = int.Parse(s[0]);
            int N = int.Parse(s[1]);

            StringBuilder sb = new StringBuilder();
            if (M == 1)
                M++;
            if (N != 1)
            {
                for (int i = M; i <= N; i++)
                    if (IsPrime(i))
                        sb.AppendLine(i.ToString());
                sb.Length--;
                Console.WriteLine(sb.ToString());
            }     
        }  

        public static bool IsPrime(int num)
        {
            for(ulong i = 2; i*i <= (ulong)num; i++)//i의 제곱이 num보다 작은가? = i가 제곱근보다 작은가?
                if ((ulong)num % i == 0)
                    return false;
            return true;
        }
    }
}
