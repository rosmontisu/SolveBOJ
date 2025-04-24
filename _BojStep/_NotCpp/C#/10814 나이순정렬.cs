using System;

namespace study_.net
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<(int, string)> userList = new List<(int, string)>();

            for (int i = 0; i < N; i++)
            {
                string[] s = Console.ReadLine().Split();
                userList.Add((int.Parse(s[0]), s[1]));
            }

            var answer = userList.OrderBy(x => x.Item1).ToList();
            for(int i = 0; i < N; i++)
                Console.WriteLine($"{answer[i].Item1} {answer[i].Item2}");
        }
    }
}
