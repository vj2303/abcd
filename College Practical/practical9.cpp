#include <iostream>
using namespace std;

#define MAX 10

int find(int, int);
void print(int, int);

int p[MAX], q[MAX], w[MAX][MAX], c[MAX][MAX], r[MAX][MAX];
string idnt[MAX];

void initialize(int n)
{
    for (int i = 0; i <= n; i++)
    {
        w[i][i] = q[i];
        c[i][i] = r[i][i] = 0;
    }
}

void calculateWeightsCosts(int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        w[i][j] = q[i] + q[j] + p[j];
        c[i][j] = q[i] + c[i][j - 1] + c[j][j];
        r[i][j] = j;
    }

    for (int m = 2; m <= n; m++)
    {
        for (int i = 0; i <= n - m; i++)
        {
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[i] + q[j];
            r[i][j] = find(i, j);
            c[i][j] = w[i][j] + c[i][r[i][j] - 1] + c[r[i][j]][j];
        }
    }
}

void print(int i, int j)
{
    if (i < j)
    {
        cout << idnt[r[i][j]] << endl;
        print(i, r[i][j] - 1);
        print(r[i][j], j);
    }
}

int find(int i, int j)
{
    int minCost = 2000;
    int minIndex = 0;

    for (int m = i + 1; m <= j; m++)
    {
        int cost = c[i][m - 1] + c[m][j];
        if (cost < minCost)
        {
            minCost = cost;
            minIndex = m;
        }
    }

    return minIndex;
}

int main()
{
    int n;

    cout << "Enter the number of identifiers: ";
    cin >> n;

    cout << "Enter identifiers: ";
    for (int i = 1; i <= n; i++)
        cin >> idnt[i];

    cout << "Enter success probabilities for identifiers: ";
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    cout << "Enter failure probabilities for identifiers: ";
    for (int i = 0; i <= n; i++)
        cin >> q[i];

    initialize(n);
    calculateWeightsCosts(n);

    cout << "\nThe final OBST is:\n";
    print(0, n);

    return 0;
}



/* output:----------------------------------------------------------------

enter a number of identifiers : 4

enter idntifiers : do if int while

enter success probability for identifiers : 3 3 1 1

enter failure probability  for identifiers : 2 3 1 1 1



 Weight        Cost          Root



2          0             0

3          0             0

1          0             0

1          0             0

1          0             0

8           2              1

7           3              2

3           1              3

3           1              4

9            11           2

11            12           2

7            8           3

10            13           2

15            19           3

11            21           2

 THE FINAL OBST IS :



if

do

int

while

--------------------------------

Process exited after 17.85 seconds with return value 0

Press any key to continue . . .*/
