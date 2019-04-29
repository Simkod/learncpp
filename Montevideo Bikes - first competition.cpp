#include <iostream>
#include <vector>

using namespace std;

void printMontevideo(vector<vector<int>> myvector)
{
    for (int i = 0; i < myvector.size(); ++i)
    {
        for (int j = 0; j < myvector[i].size(); ++j)
        {
            std::cout << myvector[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << endl;
}

int addupNonzeroBikes(vector<vector<int>> myvector)
{
    int sum = 0;
    for (int i = 0; i < myvector.size(); ++i)
    {
        for (int j = 0; j < myvector[i].size(); ++j)
        {
            sum += abs(myvector[i][j]);
        }

    }
    return sum;
};

int findSmallest(vector<vector<int>> myvector)
{
    int smallestValue = 0;
    int smallestrow;
    int smallestcolumn;

    for (int i = 0; i < myvector.size(); ++i)
    {
        for (int j = 0; j < myvector[i].size(); ++j)
        {
            if (myvector[i][j] < smallestValue)
            {
                smallestValue = myvector[i][j];
                smallestrow = i;
                smallestcolumn = j;
            }
        }
    }
    return smallestValue, smallestrow, smallestcolumn;
}

bool checkifvalueis0(int value)
{
    bool is0;
    if (value == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int totalcost = 0;
    //Read input from STDIN
    int numbersReaded = 0;
    int MontevideoRows;
    int* ptr_MontevideoRows = &MontevideoRows;
    int MontevideoColumns;
    int* ptr_MontevideoColumns = &MontevideoColumns;
    int input;
    int i = 0;
    int j = 0;
    vector<vector<int>> Montevideo;
    //vector<vector<int>> *ptr_Montevideo = &Montevideo;

    while (cin >> input)
    {
        if (numbersReaded == 0)
        {
            MontevideoRows = input;
            Montevideo.resize(MontevideoRows);
        }
        else if (numbersReaded == 1)
        {
            MontevideoColumns = input;
            for (int i = 0; i < MontevideoRows; ++i)
            {
                Montevideo[i].resize(MontevideoColumns);
            }

        }
        else if (numbersReaded >= 2)
        {
            Montevideo[i][j] = input;
            j++;
            if (j >= MontevideoColumns)
            {
                ++i;
                j = 0;
            }
        }
        ++numbersReaded;
    }

    printMontevideo(Montevideo);
    int sum = addupNonzeroBikes(Montevideo);

    while (sum > 0)    //Loop(until all field is 0 in the matrix)
    {
        //Find smallest negative value
        //findSmallest(Montevideo);
        
        int smallestValue = 0;
        int smallestrow;
        int smallestcolumn;
        int* ptr_smallestrow = &smallestrow;
        int* ptr_smallestcolumn = &smallestcolumn;
        int* ptr_smallestValue = &smallestValue;

        for (int i = 0; i < Montevideo.size(); ++i)
        {
            for (int j = 0; j < Montevideo[i].size(); ++j)
            {
                if (Montevideo[i][j] < smallestValue)
                {
                    smallestValue = Montevideo[i][j];
                    smallestrow = i;
                    smallestcolumn = j;
                }
            }
        }

        if (ptr_smallestValue != 0)
        {
            int below = 1;
            int above = -1;
            int right = 1;
            int left = -1;
            int rangeCounter = 1;

            //Loop(until the field of the smallest value is 0)
            while (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == false)
            {
                //Check fields around if they can fill up the negative values (neglect negatives, take care of corners, upper and down ends)

                //above
                if (*ptr_smallestrow + above >= 0)
                {
                    if (Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn] > 0)
                    {
                        if (Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                        {
                            int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                            Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn] -= abscurrentsmallest;
                            totalcost += abscurrentsmallest * abs(above);
                        }
                        else
                        {
                            totalcost += Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn] * abs(above);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn];
                            Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn] -= Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn];
                        }

                    }
                }
                if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                {
                    break;
                }

                //below
                if (*ptr_smallestrow + below <= MontevideoRows - 1)
                {
                    if (Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn] > 0)
                    {
                        if (Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                        {
                            int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                            Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn] -= abscurrentsmallest;
                            totalcost += abscurrentsmallest * abs(below);
                        }
                        else
                        {
                            totalcost += Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn] * abs(below);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn];
                            Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn] -= Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn];
                        }
                    }
                }
                if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                {
                    break;
                }

                //right
                if (*ptr_smallestcolumn + right <= MontevideoColumns - 1)
                {
                    if (Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + right] > 0)
                    {
                        if (Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + right] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                        {
                            int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + right] -= abscurrentsmallest;
                            totalcost += abscurrentsmallest * abs(right);
                        }
                        else
                        {
                            totalcost += Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + right] * abs(right);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + right];
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + right] -= Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + right];
                        }
                    }
                }
                if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                {
                    break;
                }

                //left
                if (*ptr_smallestcolumn + left >= 0)
                {
                    if (Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + left] > 0)
                    {
                        if (Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + left] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                        {
                            int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + left] -= abscurrentsmallest;
                            totalcost += abscurrentsmallest * abs(left);
                        }
                        else
                        {
                            totalcost += Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + left] * abs(left);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + left];
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + left] -= Montevideo[*ptr_smallestrow][*ptr_smallestcolumn + left];
                        }
                    }
                }
                if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                {
                    break;
                }

                //stepper
                if (rangeCounter >= 2)
                {
                    int borderForStepper = rangeCounter - 1;
                    for (int i = 1; i <= borderForStepper; ++i)
                    {
                        //up-right
                        if (*ptr_smallestrow + above >= 0 && *ptr_smallestcolumn + i <= MontevideoColumns - 1)
                        {
                            if (Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + i] > 0)
                            {
                                if (Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + i] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                                {
                                    int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                                    Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + i] -= abscurrentsmallest;
                                    totalcost += abscurrentsmallest * abs(above) * abs(i);
                                }
                                else
                                {
                                    totalcost += Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + i] * abs(above) * abs(i);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + i];
                                    Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + i] -= Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + i];
                                }
                            }
                        }
                        if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                        {
                            break;
                        }

                        //up-left
                        if (*ptr_smallestrow + above >= 0 && *ptr_smallestcolumn - i >= 0)
                        {
                            if (Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn - i] > 0)
                            {
                                if (Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn - i] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                                {
                                    int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                                    Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn - i] -= abscurrentsmallest;
                                    totalcost += abscurrentsmallest * abs(above) * abs(i);
                                }
                                else
                                {
                                    totalcost += Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn - i] * abs(above) * abs(i);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn - i];
                                    Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn - i] -= Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn - i];
                                }
                            }
                        }
                        if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                        {
                            break;
                        }

                        //right - down
                        if (*ptr_smallestrow + i <= MontevideoRows - 1 && *ptr_smallestcolumn + right <= MontevideoColumns - 1)
                        {
                            if (Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + right] > 0)
                            {
                                if (Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + right] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                                {
                                    int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                                    Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + right] -= abscurrentsmallest;
                                    totalcost += abscurrentsmallest * abs(i) * abs(right);
                                }
                                else
                                {
                                    totalcost += Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn +right] * abs(i) * abs(right);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + right];
                                    Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + right] -= Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + right];
                                }
                            }
                        }
                        if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                        {
                            break;
                        }

                        //right - up
                        if (*ptr_smallestrow - i >= 0 && *ptr_smallestcolumn + right <= MontevideoColumns - 1)
                        {
                            if (Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + right] > 0)
                            {
                                if (Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + right] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                                {
                                    int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                                    Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + right] -= abscurrentsmallest;
                                    totalcost += abscurrentsmallest * abs(i) * abs(right);
                                }
                                else
                                {
                                    totalcost += Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + right] * abs(i) * abs(right);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + right];
                                    Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + right] -= Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + right];
                                }
                            }
                        }
                        if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                        {
                            break;
                        }

                        //down - right
                        if (*ptr_smallestrow + below <= MontevideoRows - 1 && *ptr_smallestcolumn + i <= MontevideoColumns - 1)
                        {
                            if (Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + i] > 0)
                            {
                                if (Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + i] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                                {
                                    int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                                    Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + i] -= abscurrentsmallest;
                                    totalcost += abscurrentsmallest * abs(below) * abs(i);
                                }
                                else
                                {
                                    totalcost += Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + i] * abs(below) * abs(i);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + i];
                                    Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + i] -= Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + i];
                                }
                            }
                        }
                        if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                        {
                            break;
                        }

                        //down - left
                        if (*ptr_smallestrow + below <= MontevideoRows - 1 && *ptr_smallestcolumn - i >= 0)
                        {
                            if (Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn - i] > 0)
                            {
                                if (Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn - i] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                                {
                                    int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                                    Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn - i] -= abscurrentsmallest;
                                    totalcost += abscurrentsmallest * abs(below) * abs(i);
                                }
                                else
                                {
                                    totalcost += Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn - i] * abs(below) * abs(i);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn - i];
                                    Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn - i] -= Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn - i];
                                }
                            }
                        }
                        if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                        {
                            break;
                        }

                        //left - down
                        if (*ptr_smallestrow + i <= MontevideoRows -1 && *ptr_smallestcolumn + left >= 0)
                        {
                            if (Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + left] > 0)
                            {
                                if (Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + left] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                                {
                                    int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                                    Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + left] -= abscurrentsmallest;
                                    totalcost += abscurrentsmallest * abs(i) * abs(left);
                                }
                                else
                                {
                                    totalcost += Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + left] * abs(i) * abs(left);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + left];
                                    Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + left] -= Montevideo[*ptr_smallestrow + i][*ptr_smallestcolumn + left];
                                }
                            }
                        }
                        if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                        {
                            break;
                        }

                        //left - up
                        if (*ptr_smallestrow - i >= 0 && *ptr_smallestcolumn + left >= 0)
                        {
                            if (Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + left] > 0)
                            {
                                if (Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + left] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                                {
                                    int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                                    Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + left] -= abscurrentsmallest;
                                    totalcost += abscurrentsmallest * abs(i) * abs(left);
                                }
                                else
                                {
                                    totalcost += Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + left] * abs(i) * abs(left);
                                    Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + left];
                                    Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + left] -= Montevideo[*ptr_smallestrow - i][*ptr_smallestcolumn + left];
                                }
                            }
                        }
                        if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                        {
                            break;
                        }

                    }
                    if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                    {
                        break;
                    }
                }

                //first diagonal
                if (*ptr_smallestrow + above >= 0 && *ptr_smallestcolumn + right <= MontevideoColumns - 1)
                {
                    if (Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + right] > 0)
                    {
                        if (Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + right] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                        {
                            int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                            Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + right] -= abscurrentsmallest;
                            totalcost += abscurrentsmallest * abs(above) * abs(right);
                        }
                        else
                        {
                            totalcost += Montevideo[*ptr_smallestrow +above][*ptr_smallestcolumn + right] * abs(above) * abs(right);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow+ above][*ptr_smallestcolumn + right];
                            Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + right] -= Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + right];
                        }
                    }
                }
                if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                {
                    break;
                }

                //second diagonal
                if (*ptr_smallestrow + below <= MontevideoColumns - 1 && *ptr_smallestcolumn + right <= MontevideoColumns - 1)
                {
                    if (Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + right] > 0)
                    {
                        if (Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + right] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                        {
                            int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                            Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + right] -= abscurrentsmallest;
                            totalcost += abscurrentsmallest * abs(below) * abs(right);
                        }
                        else
                        {
                            totalcost += Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + right] * abs(below) * abs(right);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + right];
                            Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + right] -= Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + right];
                        }
                    }
                }
                if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                {
                    break;
                }

                //third diagonal
                if (*ptr_smallestrow + below <= MontevideoColumns - 1 && *ptr_smallestcolumn + left >= 0)
                {
                    if (Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + left] > 0)
                    {
                        if (Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + left] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                        {
                            int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                            Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + left] -= abscurrentsmallest;
                            totalcost += abscurrentsmallest * abs(below) * abs(left);
                        }
                        else
                        {
                            totalcost += Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + left] * abs(below) * abs(left);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + left];
                            Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + left] -= Montevideo[*ptr_smallestrow + below][*ptr_smallestcolumn + left];
                        }
                    }
                }
                if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                {
                    break;
                }

                //fourth diagonal
                if (*ptr_smallestrow + above >= 0 && *ptr_smallestcolumn + left >= 0)
                {
                    if (Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + left] > 0)
                    {
                        if (Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + left] >= abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]))
                        {
                            int abscurrentsmallest = abs(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += abscurrentsmallest;
                            Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + left] -= abscurrentsmallest;
                            totalcost += abscurrentsmallest * abs(above) * abs(left);
                        }
                        else
                        {
                            totalcost += Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + left] * abs(above) * abs(left);
                            Montevideo[*ptr_smallestrow][*ptr_smallestcolumn] += Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + left];
                            Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + left] -= Montevideo[*ptr_smallestrow + above][*ptr_smallestcolumn + left];
                        }
                    }
                }
                if (checkifvalueis0(Montevideo[*ptr_smallestrow][*ptr_smallestcolumn]) == true)
                {
                    break;
                }

                //setting movement variables for next round
                --above;
                ++below;
                ++right;
                --left;

                ++rangeCounter;
            }

        }

        //Count filling steps and costs
        //Add to total cost
        printMontevideo(Montevideo);
        sum = addupNonzeroBikes(Montevideo);
        
    }
    cout << totalcost;
    return 0;
}