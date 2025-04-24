int T = int.Parse(Console.ReadLine());

for (int i = 0; i < T; i++)
{
    int N = int.Parse(Console.ReadLine());
    string[] s = Console.ReadLine().Split();

    int[] nums = new int[N];
    for (int j = 0; j < N; j++)
        nums[j] = int.Parse(s[j]);

    //통나무 배열 정렬 완료
    //1, 2, 5, 7, 9, ... 이런 형태
    Array.Sort(nums);

    int[] answerArr = new int[N];
    int arrRightMax = N - 1;
    int testNum = 0;
    for(int j = 0; j < N; j++)
    {       
        if (!(testNum < N))                  // 중앙을 넘어가면 중지
            break;
        answerArr[j] = nums[testNum];         // 왼쪽 끝 넣기     
        testNum++;
        if (j == arrRightMax - j)                 // 만약 중앙의 값이라면? ex) 0 1 2 {3} 4 5 6
            break;
        answerArr[arrRightMax - j] = nums[testNum]; // 오른쪽 끝 넣기 
        testNum++;
    }

    int max = Math.Abs(answerArr[0] - answerArr[arrRightMax]);
    for (int k = 0; k < arrRightMax; k++)
    {
        if (Math.Abs(answerArr[arrRightMax - k] - answerArr[arrRightMax - k - 1]) > max)
            max = Math.Abs(answerArr[arrRightMax - k] - answerArr[arrRightMax - k - 1]);
    }

    Console.WriteLine(max);
}
