#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) //returns the largest of the two
{
        if (a>b)
                return a;
        else
                return b;
}


void LCS(string X, string Y, int m, int n)
{
        int i, //iterate through first string
            j; //iterate through second string

        //2D array
        int L[m+1][n+1];

        for (i=0; i<=m; i++)
        {
                for (j=0; j<=n; j++)
                {
                        if (i == 0 || j == 0)
                                L[i][j] = 0;

                        else if (X[i-1] == Y[j-1])  //set to diagonal+1
                                L[i][j] = L[i-1][j-1] + 1;

                        else //get greater value between left and up
                                L[i][j] = max(L[i-1][j], L[i][j-1]);
                }
        }

        /*
        //display for testing purposes
        for (i=0; i<=m; i++)
        {
                for (j=0; j<=n; j++)
                        {
                                cout << L[i][j];
                        }
                cout << endl;
        }
        */

  cout << "The least common sequence is " << L[m][n] << " characters long." << endl;

}


int main()
{
        string first = "abcdaf";
        string second = "acbcf";
        //expected output between these two strings: 4
        int length1 = first.length();
        int length2 = second.length();

        LCS(first, second, length1, length2);

        return 0;
}
