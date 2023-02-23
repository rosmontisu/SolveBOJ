using System;

namespace JustStudy
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            Queue<int> queue = new();
            for(int i = 1; i < N+1; i++)
                queue.Enqueue(i);

            //첫 번째 수는 디큐
            //두 번째 수는 디큐 후 다시 인큐
            //마지막 수가 나오면 함수 종료
            while(true)
            {
                if (queue.Count() == 1)
                {
                    Console.WriteLine(queue.Dequeue());
                    break;
                }
                queue.Dequeue();
                queue.Enqueue(queue.Dequeue());            
            }      
        }
    }
}
