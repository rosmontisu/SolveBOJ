using System;
using System.Collections;

namespace study_.net
{
    class Program2
    {
        static void Main(string[] args)
        {
            string[] strings = new string[100];
            //ArrayList arrayList = new ArrayList();

            int i = 0;
            while (true)
            {
                strings[i] = Console.ReadLine();
                if(strings[i] == "0")
                    break;
                i++;
                if(i > strings.Length)
                    Array.Resize(ref strings, i);
            }

            for(i = 0; i < strings.Length; i++)
            {
                string s = strings[i];//문자열에서 문자 추출
                if (s == "0")
                    break;
                for (int j = 0; j < strings[i].Length; j++)
                {         
                    if (j >= s.Length - 1 - j)
                    {
                        Console.WriteLine("yes");
                        break;
                    }
                                     
                    if (s[j] != s[s.Length-1-j])
                    {
                        Console.WriteLine("no");
                        break;
                    }
                }
            }            
        }
    }
}
