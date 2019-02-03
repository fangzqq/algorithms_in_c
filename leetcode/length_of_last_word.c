/* https://leetcode-cn.com/problems/length-of-last-word/
 * 最后一个单词的长度
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 如果不存在最后一个单词，请返回 0 。
*/

// int lengthOfLastWord(char* s) {
//     int i, ans = 0;
//     for (i = strlen(s) - 1; i >= 0; i--)
//     {
//         if (s[i] != ' ') ans++;
//         else if (ans) return ans;
//     }
//     return ans;
// }

#include <stdio.h>

int lengthOfLastWord(char* s)
{
    int len = 0;

    while(*s)
    {
        if (*s++ != ' ') ++len;
        else if (*s && (*s != ' ')) len = 0;
    }
    return len;
}


int main(void)
{
    char* s1 = "abc  def  gef  ";
    char* s2 = "abc  defgh  ";
    char* s3 = "abcedf  ";
    char* s4 = "  abcdefg";

    printf("s1 %i\n", lengthOfLastWord(s1));
    printf("s2 %i\n", lengthOfLastWord(s2));
    printf("s3 %i\n", lengthOfLastWord(s3));
    printf("s4 %i\n", lengthOfLastWord(s4));
}