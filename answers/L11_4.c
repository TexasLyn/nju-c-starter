/* L11_4 参考答案 · 统计字母频率 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[205];
    int freq[26] = {0};

    fgets(s, 205, stdin);
    s[strcspn(s, "\n")] = '\0';

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c >= 'a' && c <= 'z') {
            freq[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            freq[c - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c:%d\n", 'a' + i, freq[i]);
        }
    }

    return 0;
}
