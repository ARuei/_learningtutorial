
#include<iostream>
#include<cstdio>

using namespace std;
int main() {

/*
 *  If there are fewer initializers in a brace-enclosed list than there are
 *  elements or members of an aggregate, or fewer characters in a string
 *  literal used to initialize an array of known size than there are elements
 *  in the array, the remainder of the aggregate shall be initialized implicitly
 *  the same as objects that have static storage duration.
 */
/*
 *  STATIC property to insure that all the other data
 *  that are not initialized will be 0
 */

    static int factorial[1002][5000] = { {0}, {1} };
/*
 * Testing the property of initializer

        static int factorial[10][20] = { {0}, {1} };

        for (int i=0;i<10;i++) {
            for (int j=0;j<20;j++){
                cout << factorial[i][j] << " ";}
            cout << endl;
        }
 */
    int idx = 0, ans[1002] = { 1, 1 };
 /*
  * e.x., Let i=5
  *
  * idx = 1 since 4!=24 and it points at how many positions we need
  *
  * Note that, 5!=120
  *************************************
  * First Loop:                       *
  *     [5][0] = [4][0] * 5 = 4*5 = 20*
  *     [5][1] = [4][1] * 5 = 2*5 = 10*
  *******************************************************************************
  * Note that, j == idx thus move forward to next position                      *
  * which means in the present largest position we have the value larger than 10*
  *                                                                             *
  * Second Loop: 1st                                                            *
  *     [5][0] = [5][0] % 10 = 0                                                *
  *     [5][1] = [5][0] + [5][1] = 12                                           *
  *                                                                             *
  * Second Loop: 2st                                                            *
  *     [5][1] = [5][1] % 10 = 1                                                *
  *     [5][2] = [5][1] + [5][2] = 12                                           *
  *******************************************************************************
  */

    for (int i = 2; i < 1002; i++) {

        for (int j = 0; j <= idx; j++) {

            factorial[i][j] = factorial[i - 1][j] * i;
        }

        for (int j = 0; j <= idx; j++) {

            if (factorial[i][j] >= 10) {

               /*
                * 1st: Make the present position to be remainder
                * 2nd: Make the next position to be quotient
                */
                int temp = factorial[i][j] / 10;
                factorial[i][j] %= 10; // 1st
                factorial[i][j + 1] += temp; // 2nd, using += since here may have some value calculated by first loop
               /*
                *  A way to increase the position
                *  If present is larger than ten, go to next position
                */
                if (j == idx) idx++;
            }

            ans[i] += factorial[i][j];
        }
    }

    int n;
    while ( cin>>n ) cout << ans[n] << endl;

    return 0;
}
