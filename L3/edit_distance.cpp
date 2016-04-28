#include <stdio.h>
#include <string>
using namespace std;

#define min2(a,b) ((a<b)?a:b)
#define min(a,b,c) (min2(min2(a,b),c))

int EditDist(string str1 , string str2 , int m ,int n);

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    printf("Number of operation: %d\n", EditDist( str1 , str2 , str1.length(), str2.length()));

    return 0;
}

int EditDist(string str1 , string str2 , int m ,int n)
{
    if (m == 0) return n;

    if (n == 0) return m;


    // Same value, so continue
    if (str1[m-1] == str2[n-1])
        return EditDist(str1, str2, m-1, n-1);

    return 1 + min (
                    EditDist(str1,  str2, m, n-1),        // Insert
                    EditDist(str1,  str2, m-1, n),        // Remove
                    EditDist(str1,  str2, m-1, n-1)       // Replace
                   );
}
