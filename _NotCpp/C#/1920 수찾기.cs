using System;
using System.Text;

namespace JustStudy
{
    internal class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();
            int N = int.Parse(Console.ReadLine());

            //오름차순 정렬 리스트 ints 선언
            List<int> intN = new List<int>();
            string[] s = Console.ReadLine().Split();
            for(int i = 0; i < N; i++)
                intN.Add(int.Parse(s[i]));
            intN.Sort();

            //찾으려는 수의 목록 intM[i]
            int M = int.Parse(Console.ReadLine());
            s = Console.ReadLine().Split();
            int[] intM = new int[M];
            for (int i = 0; i < M; i++)
                intM[i] = int.Parse(s[i]);

            //검색 시작          
            for (int i = 0; i < M; i++)
            {
                int pointLeft = 0;
                int pointRight = intN.Count - 1;
                int pointM;

                while (true)
                {
                    pointM = (pointLeft + pointRight) / 2;
                    if (intN[pointM] == intM[i])
                    {
                        sb.AppendLine("1");
                        break;
                        //검색 성공
                    }
                    else if (intN[pointM] > intM[i])
                        pointRight = (pointM - 1);
                    else
                        pointLeft = (pointM + 1);

                    if(pointLeft > pointRight)
                    {
                        sb.AppendLine("0");
                        break;
                        //검색 실패
                    }
                }
            }
            Console.WriteLine(sb.ToString());
        }
    }
}
