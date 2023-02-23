using System;
using System.Text;

namespace JustStudy
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            StringBuilder sb = new StringBuilder();
            Stack<char> stack = new();
            for(int i = 0; i < T; i++)
            {
                string s = Console.ReadLine();

                stack.Clear();
                for (int j = 0; j < s.Length; j++)
                {
                    if (s[j] == '(')
                        stack.Push(s[j]);
                    else if (stack.Count > 0)
                        stack.Pop();
                    else
                    {
                        stack.Push(s[j]);
                        break;
                    }                                       
                }
                if (stack.Count == 0)
                    sb.AppendLine("YES");
                else
                    sb.AppendLine("NO");
            }
            Console.WriteLine(sb.ToString());           
        }
    }
}
