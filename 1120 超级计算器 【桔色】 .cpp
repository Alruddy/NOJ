#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    cout << (-2) % (-3) << endl;
    int a, b;
    char op;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &a, &b);
        getchar();
        scanf("%c", &op);
        getchar();
        int ans = 0;
        switch(op)
        {
            case '+':
                ans = a + b;
                break;
            case '-':
                ans = a - b;
                break;
            case '%':
                if(b < 0)
                {
                    ans = a % b;
                    while(ans > 0)
                        ans += b;
                }
                else
                {
                    ans = a % b;
                    while(ans < 0)
                        ans += b;
                }
                break;
            default:
                break;
        }
        printf("%d %c %d = %d\n", a, op, b, ans);

    }
    return 0;


}
