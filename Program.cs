using System;

namespace Boj
{
    class Program
    {
        static void Main()
        {
            /*
            1. 본사의 총 층수 N,  아인이의 기숙사가 있는 층 S
            2. 각 층 가속기의 성능 a1 a2 a3 ... an
            3. 아인이가 출근시 사용한 커맨드 (+-0 으로 이루어진 문자열)
            
            즉, 가속기 커맨드 작동후의 층에서
            s층으로 다시 돌아가기 위한 커맨드를 출력하는 문제
            */

            string s = Console.ReadLine();
            int n = int.Parse(s[0]);        // 건물의 최고층
            int s = int.Parse(s[1]);        // 목적지

            s = Console.ReadLine();
            int[] accelerator = new int[n]; // 각 층별 가속기의 성능
            for (int i = 0; i < t; i++)
            {
                accelerator[i] = int.Parse(s[i]);
            }

            string command = Console.ReadLine(); // 입력 받은 커맨드

            int now_floor = 0;  // 현재 층수
            int speed = 0;      // 현재 속도

            for (int i = 0; i < command.Length; i++)
            {
                if (command[i] == "+")
                {
                    speed += accelerator[now_floor];
                    now_floor += speed;
                }
                else if (command[i] == "-")
                {
                    speed -= accelerator[now_floor];
                    now_floor += speed;
                }
                else
                {
                    now_floor += speed;
                }
            }
            Console.WriteLine(now_floor);


            // now_floor 에서 s 로 돌아가는 커맨드 뽑는코드

        }
    }
    
}