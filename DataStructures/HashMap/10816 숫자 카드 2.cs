// hash개념 문제 처음 공부해본거

using System;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System.Text;

namespace Namespace
{
    class CountSort
    {
        static void Main()
        {
            int[] arry = new int[20000001]; // N의 최대값 배열 선언
            int n = int.Parse(Console.ReadLine());
            string[] nstr = Console.ReadLine().Split(' '); // 내가 들고 있는 카드 N개

            int m = int.Parse(Console.ReadLine());
            string[] mstr = Console.ReadLine().Split(' '); // 찾을 카드 M개

            int nIdx = 10000000; // 1000만을 중심으로 +- 위아래로 수를 배열할 것
            StringBuilder stringBuilder = new StringBuilder();

            for (int i = 0; i < nstr.Length; i++)   // 카드 배열
            {                                       // i번째 문자열을 1000만을 중심으로 +1 위에 배열
                arry[nIdx + int.Parse(nstr[i])]++; 
                //배열의 숫자가 데이터의 값이고, 그 데이터가 있으니까 +1 해준다는거임.. 와
            }
            for (int i = 0; i < mstr.Length; i++) // 숫자 배열
            {
                stringBuilder.Append(arry[nIdx + int.Parse(mstr[i])] + " ");
            }
            Console.WriteLine(stringBuilder.ToString());
        }
    }
    
}