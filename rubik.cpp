#include <iostream>
#include <fstream>
using namespace std;
int limit = 5;
//creating 12 states further
int ***makeMove(int ***current, int value)
{
    int ****array;
    array = new int ***[12];
    for (int i = 0; i < 12; i++)
    {
        array[i] = new int **[6];
        for (int j = 0; j < 6; j++)
        {
            array[i][j] = new int *[3];
            for (int k = 0; k < 3; k++)
            {
                array[i][j][k] = new int[3];
            }
        }
    }

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    array[i][j][k][l] = current[j][k][l];
                }
            }
        }
    }
    int temp[3];
    int k = 0;
    int m = 2;
    switch (value)
    {

    case 0:
        //up move anticlockwise
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (i == 0 && j == 0)
                    {
                        array[0][i][j][k] = current[i + 3][0][k];
                    }
                    else if (i == 1 && j == 0)
                    {
                        array[0][i][j][k] = current[i - 1][0][k];
                    }
                    else if (i == 2 && j == 0)
                    {
                        array[0][i][j][k] = current[i - 1][0][k];
                    }
                    else if (i == 3 && j == 0)
                    {
                        array[0][i][j][k] = current[i - 1][0][k];
                    }
                    else if (i == 4)
                    {
                        array[0][i][j][k] = current[i][k][j];
                    }
                    else
                    {
                        array[0][i][j][k] = current[i][j][k];
                    }
                }
            }
        }
        break;
    case 1:
        //up move clockwise
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                m = 2;
                for (int k = 0; k < 3; k++)
                {
                    if (i == 0 && j == 0)
                    {
                        array[1][i][j][k] = current[i + 1][0][k];
                    }
                    else if (i == 1 && j == 0)
                    {
                        array[1][i][j][k] = current[i + 1][0][k];
                    }
                    else if (i == 2 && j == 0)
                    {
                        array[1][i][j][k] = current[i + 1][0][k];
                    }
                    else if (i == 3 && j == 0)
                    {
                        array[1][i][j][k] = current[0][0][k];
                    }
                    else if (i == 4)
                    {
                        array[1][i][k][j] = current[i][j][m];
                        m--;
                    }
                    else
                    {
                        array[1][i][j][k] = current[i][j][k];
                    }
                }
            }
        }
        break;

    case 2:
        //down move clockwise
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (i == 0 && j == 2)
                    {
                        array[2][i][j][k] = current[i + 3][2][k];
                    }
                    else if (i == 1 && j == 2)
                    {
                        array[2][i][j][k] = current[i - 1][2][k];
                    }
                    else if (i == 2 && j == 2)
                    {
                        array[2][i][j][k] = current[i - 1][2][k];
                    }
                    else if (i == 3 && j == 2)
                    {
                        array[2][i][j][k] = current[i - 1][2][k];
                    }
                    else if (i == 5)
                    {
                        array[2][i][j][k] = current[i][k][j];
                    }
                    else
                    {
                        array[2][i][j][k] = current[i][j][k];
                    }
                }
            }
        }
        break;
    case 3:
        m = 2;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                m = 2;
                for (int k = 0; k < 3; k++)
                {
                    if (i == 0 && j == 2)
                    {
                        array[3][i][j][k] = current[i + 1][2][k];
                    }
                    else if (i == 1 && j == 2)
                    {
                        array[3][i][j][k] = current[i + 1][2][k];
                    }
                    else if (i == 2 && j == 2)
                    {
                        array[3][i][j][k] = current[i + 1][2][k];
                    }
                    else if (i == 3 && j == 2)
                    {
                        array[3][i][j][k] = current[0][2][k];
                    }
                    else if (i == 5)
                    {
                        array[3][i][k][j] = current[i][j][m];
                        m--;
                    }
                    else
                    {
                        array[3][i][j][k] = current[i][j][k];
                    }
                }
            }
        }

        break;
    case 4:

        k = 0;
        temp[0] = current[0][0][k];
        temp[1] = current[0][1][k];
        temp[2] = current[0][2][k];
        array[4][0][0][k] = current[5][2][2];
        array[4][0][1][k] = current[5][1][2];
        array[4][0][2][k] = current[5][0][2];
        array[4][5][0][2] = current[2][0][k];
        array[4][5][1][2] = current[2][1][k];
        array[4][5][2][2] = current[2][2][k];
        array[4][2][0][k] = current[4][2][k];
        array[4][2][1][k] = current[4][1][k];
        array[4][2][2][k] = current[4][0][k];
        array[4][4][0][k] = temp[0];
        array[4][4][1][k] = temp[1];
        array[4][4][2][k] = temp[2];

        for (int i = 2, k = 0; i >= 0; i--, k++)
        {
            for (int j = 0; j < 3; j++)
            {
                array[4][3][j][i] = current[3][k][j];
            }
        }
        break;
    case 5:

        k = 2;
        temp[0] = current[0][0][k];
        temp[1] = current[0][1][k];
        temp[2] = current[0][2][k];
        array[5][0][0][k] = current[5][2][0];
        array[5][0][1][k] = current[5][1][0];
        array[5][0][2][k] = current[5][0][0];
        array[5][5][0][0] = current[2][0][k];
        array[5][5][1][0] = current[2][1][k];
        array[5][5][2][0] = current[2][2][k];
        array[5][2][0][k] = current[4][2][k];
        array[5][2][1][k] = current[4][1][k];
        array[5][2][2][k] = current[4][0][k];
        array[5][4][0][k] = temp[0];
        array[5][4][1][k] = temp[1];
        array[5][4][2][k] = temp[2];

        for (int i = 2, k = 0; i >= 0; i--, k++)
        {
            for (int j = 0; j < 3; j++)
            {
                array[5][5][j][i] = current[5][k][j];
            }
        }

        break;
    case 6:
        k = 2;
        temp[0] = current[0][0][k];
        temp[1] = current[0][1][k];
        temp[2] = current[0][2][k];
        array[6][0][0][k] = current[4][0][k];
        array[6][0][1][k] = current[4][1][k];
        array[6][0][2][k] = current[4][2][k];
        array[6][4][0][k] = current[2][2][k];
        array[6][4][1][k] = current[2][1][k];
        array[6][4][2][k] = current[2][0][k];
        array[6][2][0][k] = current[5][0][0];
        array[6][2][1][k] = current[5][1][0];
        array[6][2][2][k] = current[5][2][0];
        array[6][5][2][0] = temp[0];
        array[6][5][1][0] = temp[1];
        array[6][5][0][0] = temp[2];
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0, i = 2; i >= 0; i--, j++)
            {
                array[6][5][j][k] = current[5][k][i];
            }
        }

        break;
    case 7:
        k = 0;
        temp[0] = current[0][0][k];
        temp[1] = current[0][1][k];
        temp[2] = current[0][2][k];
        array[7][0][0][k] = current[4][0][k];
        array[7][0][1][k] = current[4][1][k];
        array[7][0][2][k] = current[4][2][k];
        array[7][4][0][k] = current[2][0][k];
        array[7][4][1][k] = current[2][1][k];
        array[7][4][2][k] = current[2][2][k];
        array[7][2][0][k] = current[5][0][2];
        array[7][2][1][k] = current[5][1][2];
        array[7][2][2][k] = current[5][2][2];
        array[7][5][2][2] = temp[0];
        array[7][5][1][2] = temp[1];
        array[7][5][0][2] = temp[2];
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0, i = 2; i >= 0; i--, j++)
            {
                array[7][4][j][k] = current[5][k][i];
            }
        }

        break;
    case 8:
        k = 2;
        temp[0] = current[4][k][0];
        temp[1] = current[4][k][1];
        temp[2] = current[4][k][2];
        array[8][4][k][0] = current[3][2][k];
        array[8][4][k][1] = current[3][1][k];
        array[8][4][k][2] = current[3][0][k];
        array[8][3][0][k] = current[5][k][2];
        array[8][3][1][k] = current[5][k][1];
        array[8][3][2][k] = current[5][k][0];
        array[8][5][k][2] = current[1][0][0];
        array[8][5][k][1] = current[1][1][0];
        array[8][5][k][0] = current[1][2][0];
        array[8][1][0][0] = temp[0];
        array[8][1][1][0] = temp[1];
        array[8][1][2][0] = temp[2];

        for (int i = 2, k = 0; i >= 0; i--, k++)
        {
            for (int j = 0; j < 3; j++)
            {
                array[8][0][j][i] = current[0][k][j];
            }
        }

        break;
    case 9:
        k = 0;
        temp[0] = current[4][k][0];
        temp[1] = current[4][k][1];
        temp[2] = current[4][k][2];
        array[9][4][k][0] = current[3][0][k];
        array[9][4][k][1] = current[3][1][k];
        array[9][4][k][2] = current[3][2][k];
        array[9][3][0][k] = current[5][k][2];
        array[9][3][1][k] = current[5][k][1];
        array[9][3][2][k] = current[5][k][0];
        array[9][5][k][0] = current[1][0][2];
        array[9][5][k][1] = current[1][1][2];
        array[9][5][k][2] = current[1][2][2];
        array[9][1][0][2] = temp[0];
        array[9][1][1][2] = temp[1];
        array[9][1][2][2] = temp[2];

        for (int k = 0; k < 3; k++)
        {
            for (int j = 0, i = 2; i >= 0; i--, j++)
            {
                array[9][2][j][k] = current[2][k][i];
            }
        }

        break;
    case 10:
        k = 0;
        temp[0] = current[4][k][0];
        temp[1] = current[4][k][1];
        temp[2] = current[4][k][2];
        array[10][4][k][0] = current[1][0][2];
        array[10][4][k][1] = current[1][1][2];
        array[10][4][k][2] = current[1][2][2];
        array[10][1][0][2] = current[5][k][0];
        array[10][1][1][2] = current[5][k][1];
        array[10][1][2][2] = current[5][k][2];
        array[10][5][k][2] = current[3][0][k];
        array[10][5][k][1] = current[3][1][k];
        array[10][5][k][0] = current[3][2][k];
        array[10][3][0][k] = temp[0];
        array[10][3][1][k] = temp[1];
        array[10][3][2][k] = temp[2];

        for (int i = 2, k = 0; i >= 0; i--, k++)
        {
            for (int j = 0; j < 3; j++)
            {
                array[10][2][j][i] = current[2][k][j];
            }
        }
        break;
    case 11:
        k = 2;
        temp[0] = current[4][k][0];
        temp[1] = current[4][k][1];
        temp[2] = current[4][k][2];
        array[11][4][k][0] = current[1][0][0];
        array[11][4][k][1] = current[1][1][0];
        array[11][4][k][2] = current[1][2][0];
        array[11][1][0][0] = current[5][k][2];
        array[11][1][1][0] = current[5][k][1];
        array[11][1][2][0] = current[5][k][0];
        array[11][5][k][0] = current[3][0][k];
        array[11][5][k][1] = current[3][1][k];
        array[11][5][k][2] = current[3][2][k];
        array[11][3][0][k] = temp[0];
        array[11][3][1][k] = temp[1];
        array[11][3][2][k] = temp[2];

        for (int k = 0; k < 3; k++)
        {
            for (int j = 0, i = 2; i >= 0; i--, j++)
            {
                array[11][0][j][k] = current[0][k][i];
            }
        }
        break;
    }
    return array[value];
}
int ****getMoves(int ***current)
{
    int ****array;
    array = new int ***[12];
    for (int i = 0; i < 12; i++)
    {
        array[i] = new int **[6];
        for (int j = 0; j < 6; j++)
        {
            array[i][j] = new int *[3];
            for (int k = 0; k < 3; k++)
            {
                array[i][j][k] = new int[3];
            }
        }
    }

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    array[i][j][k][l] = current[j][k][l];
                }
            }
        }
    }
    int temp[3];
    int k = 0;
    int m = 2;
    //up move anticlockwise
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (i == 0 && j == 0)
                {
                    array[0][i][j][k] = current[i + 3][0][k];
                }
                else if (i == 1 && j == 0)
                {
                    array[0][i][j][k] = current[i - 1][0][k];
                }
                else if (i == 2 && j == 0)
                {
                    array[0][i][j][k] = current[i - 1][0][k];
                }
                else if (i == 3 && j == 0)
                {
                    array[0][i][j][k] = current[i - 1][0][k];
                }
                else if (i == 4)
                {
                    array[0][i][j][k] = current[i][k][j];
                }
                else
                {
                    array[0][i][j][k] = current[i][j][k];
                }
            }
        }
    }
    //up move clockwise
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m = 2;
            for (int k = 0; k < 3; k++)
            {
                if (i == 0 && j == 0)
                {
                    array[1][i][j][k] = current[i + 1][0][k];
                }
                else if (i == 1 && j == 0)
                {
                    array[1][i][j][k] = current[i + 1][0][k];
                }
                else if (i == 2 && j == 0)
                {
                    array[1][i][j][k] = current[i + 1][0][k];
                }
                else if (i == 3 && j == 0)
                {
                    array[1][i][j][k] = current[0][0][k];
                }
                else if (i == 4)
                {
                    array[1][i][k][j] = current[i][j][m];
                    m--;
                }
                else
                {
                    array[1][i][j][k] = current[i][j][k];
                }
            }
        }
    }
    //down move clockwise
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (i == 0 && j == 2)
                {
                    array[2][i][j][k] = current[i + 3][2][k];
                }
                else if (i == 1 && j == 2)
                {
                    array[2][i][j][k] = current[i - 1][2][k];
                }
                else if (i == 2 && j == 2)
                {
                    array[2][i][j][k] = current[i - 1][2][k];
                }
                else if (i == 3 && j == 2)
                {
                    array[2][i][j][k] = current[i - 1][2][k];
                }
                else if (i == 5)
                {
                    array[2][i][j][k] = current[i][k][j];
                }
                else
                {
                    array[2][i][j][k] = current[i][j][k];
                }
            }
        }
    }
    m = 2;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m = 2;
            for (int k = 0; k < 3; k++)
            {
                if (i == 0 && j == 2)
                {
                    array[3][i][j][k] = current[i + 1][2][k];
                }
                else if (i == 1 && j == 2)
                {
                    array[3][i][j][k] = current[i + 1][2][k];
                }
                else if (i == 2 && j == 2)
                {
                    array[3][i][j][k] = current[i + 1][2][k];
                }
                else if (i == 3 && j == 2)
                {
                    array[3][i][j][k] = current[0][2][k];
                }
                else if (i == 5)
                {
                    array[3][i][k][j] = current[i][j][m];
                    m--;
                }
                else
                {
                    array[3][i][j][k] = current[i][j][k];
                }
            }
        }
    }

    k = 0;
    temp[0] = current[0][0][k];
    temp[1] = current[0][1][k];
    temp[2] = current[0][2][k];
    array[4][0][0][k] = current[5][2][2];
    array[4][0][1][k] = current[5][1][2];
    array[4][0][2][k] = current[5][0][2];
    array[4][5][0][2] = current[2][0][k];
    array[4][5][1][2] = current[2][1][k];
    array[4][5][2][2] = current[2][2][k];
    array[4][2][0][k] = current[4][2][k];
    array[4][2][1][k] = current[4][1][k];
    array[4][2][2][k] = current[4][0][k];
    array[4][4][0][k] = temp[0];
    array[4][4][1][k] = temp[1];
    array[4][4][2][k] = temp[2];

    for (int i = 2, k = 0; i >= 0; i--, k++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[4][3][j][i] = current[3][k][j];
        }
    }

    k = 2;
    temp[0] = current[0][0][k];
    temp[1] = current[0][1][k];
    temp[2] = current[0][2][k];
    array[5][0][0][k] = current[5][2][0];
    array[5][0][1][k] = current[5][1][0];
    array[5][0][2][k] = current[5][0][0];
    array[5][5][0][0] = current[2][0][k];
    array[5][5][1][0] = current[2][1][k];
    array[5][5][2][0] = current[2][2][k];
    array[5][2][0][k] = current[4][2][k];
    array[5][2][1][k] = current[4][1][k];
    array[5][2][2][k] = current[4][0][k];
    array[5][4][0][k] = temp[0];
    array[5][4][1][k] = temp[1];
    array[5][4][2][k] = temp[2];

    for (int i = 2, k = 0; i >= 0; i--, k++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[5][5][j][i] = current[5][k][j];
        }
    }
    k = 2;
    temp[0] = current[0][0][k];
    temp[1] = current[0][1][k];
    temp[2] = current[0][2][k];
    array[6][0][0][k] = current[4][0][k];
    array[6][0][1][k] = current[4][1][k];
    array[6][0][2][k] = current[4][2][k];
    array[6][4][0][k] = current[2][2][k];
    array[6][4][1][k] = current[2][1][k];
    array[6][4][2][k] = current[2][0][k];
    array[6][2][0][k] = current[5][0][0];
    array[6][2][1][k] = current[5][1][0];
    array[6][2][2][k] = current[5][2][0];
    array[6][5][2][0] = temp[0];
    array[6][5][1][0] = temp[1];
    array[6][5][0][0] = temp[2];
    for (int k = 0; k < 3; k++)
    {
        for (int j = 0, i = 2; i >= 0; i--, j++)
        {
            array[6][5][j][k] = current[5][k][i];
        }
    }
    k = 0;
    temp[0] = current[0][0][k];
    temp[1] = current[0][1][k];
    temp[2] = current[0][2][k];
    array[7][0][0][k] = current[4][0][k];
    array[7][0][1][k] = current[4][1][k];
    array[7][0][2][k] = current[4][2][k];
    array[7][4][0][k] = current[2][0][k];
    array[7][4][1][k] = current[2][1][k];
    array[7][4][2][k] = current[2][2][k];
    array[7][2][0][k] = current[5][0][2];
    array[7][2][1][k] = current[5][1][2];
    array[7][2][2][k] = current[5][2][2];
    array[7][5][2][2] = temp[0];
    array[7][5][1][2] = temp[1];
    array[7][5][0][2] = temp[2];
    for (int k = 0; k < 3; k++)
    {
        for (int j = 0, i = 2; i >= 0; i--, j++)
        {
            array[7][4][j][k] = current[5][k][i];
        }
    }
    k = 2;
    temp[0] = current[4][k][0];
    temp[1] = current[4][k][1];
    temp[2] = current[4][k][2];
    array[8][4][k][0] = current[3][2][k];
    array[8][4][k][1] = current[3][1][k];
    array[8][4][k][2] = current[3][0][k];
    array[8][3][0][k] = current[5][k][2];
    array[8][3][1][k] = current[5][k][1];
    array[8][3][2][k] = current[5][k][0];
    array[8][5][k][2] = current[1][0][0];
    array[8][5][k][1] = current[1][1][0];
    array[8][5][k][0] = current[1][2][0];
    array[8][1][0][0] = temp[0];
    array[8][1][1][0] = temp[1];
    array[8][1][2][0] = temp[2];

    for (int i = 2, k = 0; i >= 0; i--, k++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[8][0][j][i] = current[0][k][j];
        }
    }
    k = 0;
    temp[0] = current[4][k][0];
    temp[1] = current[4][k][1];
    temp[2] = current[4][k][2];
    array[9][4][k][0] = current[3][0][k];
    array[9][4][k][1] = current[3][1][k];
    array[9][4][k][2] = current[3][2][k];
    array[9][3][0][k] = current[5][k][2];
    array[9][3][1][k] = current[5][k][1];
    array[9][3][2][k] = current[5][k][0];
    array[9][5][k][0] = current[1][0][2];
    array[9][5][k][1] = current[1][1][2];
    array[9][5][k][2] = current[1][2][2];
    array[9][1][0][2] = temp[0];
    array[9][1][1][2] = temp[1];
    array[9][1][2][2] = temp[2];

    for (int k = 0; k < 3; k++)
    {
        for (int j = 0, i = 2; i >= 0; i--, j++)
        {
            array[9][2][j][k] = current[2][k][i];
        }
    }
    k = 0;
    temp[0] = current[4][k][0];
    temp[1] = current[4][k][1];
    temp[2] = current[4][k][2];
    array[10][4][k][0] = current[1][0][2];
    array[10][4][k][1] = current[1][1][2];
    array[10][4][k][2] = current[1][2][2];
    array[10][1][0][2] = current[5][k][0];
    array[10][1][1][2] = current[5][k][1];
    array[10][1][2][2] = current[5][k][2];
    array[10][5][k][2] = current[3][0][k];
    array[10][5][k][1] = current[3][1][k];
    array[10][5][k][0] = current[3][2][k];
    array[10][3][0][k] = temp[0];
    array[10][3][1][k] = temp[1];
    array[10][3][2][k] = temp[2];

    for (int i = 2, k = 0; i >= 0; i--, k++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[10][2][j][i] = current[2][k][j];
        }
    }
    k = 2;
    temp[0] = current[4][k][0];
    temp[1] = current[4][k][1];
    temp[2] = current[4][k][2];
    array[11][4][k][0] = current[1][0][0];
    array[11][4][k][1] = current[1][1][0];
    array[11][4][k][2] = current[1][2][0];
    array[11][1][0][0] = current[5][k][2];
    array[11][1][1][0] = current[5][k][1];
    array[11][1][2][0] = current[5][k][0];
    array[11][5][k][0] = current[3][0][k];
    array[11][5][k][1] = current[3][1][k];
    array[11][5][k][2] = current[3][2][k];
    array[11][3][0][k] = temp[0];
    array[11][3][1][k] = temp[1];
    array[11][3][2][k] = temp[2];

    for (int k = 0; k < 3; k++)
    {
        for (int j = 0, i = 2; i >= 0; i--, j++)
        {
            array[11][0][j][k] = current[0][k][i];
        }
    }
    return array;
}
void loadState(int ***current, int value)
{
    ofstream fout;
    fout.open("state.txt");
    int ***move = makeMove(current, value);
    move=makeMove(move,7); 
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                fout << move[i][j][k] << " ";
            }
        }
    }
}
//loading the initial and final state from the file
void loadFromFile(int ***initial, int ***final)
{
    ifstream fin;
    fin.open("file.txt");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                fin >> initial[i][j][k];
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                fin >> final[i][j][k];
            }
        }
    }
}
//heuristic to get the matching elements of current and goal state
int matchHeuristic(int ***current, int ***final)
{
    int count = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (current[i][j][k] == final[i][j][k])
                {
                    count++;
                }
            }
        }
    }
    return count;
}
//A* algorithm that uses the heuristic function to move further
void aStar(int ***current, int ***final)
{
    bool check = false;
    int count = 0;
    while (check == false)
    {
        int ***getState;
        int maxMatchesIndex = 0;
        for (int i = 0; i < 12; i++)
        {
            getState = makeMove(current, i);
            count = matchHeuristic(getState, final);
            if (count>maxMatchesIndex)
            {
                maxMatchesIndex = i;
            }
        }
        check = true;
        getState = makeMove(current, maxMatchesIndex);
        current = getState;
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if (getState[j][k][l] != final[j][k][l])
                    {
                        check = false;
                    }
                }
            }
        }
        if(!check)
        {
            cout<<"Goal reached!"<<endl;
            break;
        }
    }
}

bool matchStates(int ***state, int ***final)
{
    bool checkit = true;
    for (int i = 0; i < 6 && checkit; i++)
    {
        for (int j = 0; j < 3 && checkit; j++)
        {
            for (int k = 0; k < 3 && checkit; k++)
            {
                if (state[i][j][k] != final[i][j][k])
                {
                    checkit = false;
                }
            }
        }
    }
    return checkit;
}
bool DLS(int ***src, int ***target, int limit)
{
    if (matchStates(src, target))
    {
        return true;
    }

    // If reached the maximum depth, stop recursing.
    if (limit <= 0)
    {
        return false;
    }
    int ****states=getMoves(src);
    // Recur for all the vertices adjacent to source vertex
    for (int i = 0; i<12;i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    cout<<states[i][j][k][l]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        cout<<endl;
        if (DLS(states[i], target, limit - 1) == true)
        {
            return true;
        }
    }

    return false;
}
//Iterative deepening that uses val levels as depth to check the final stage with intervals of levels
bool iterativeDeepening(int ***src, int ***target, int max_depth)
{
    // Repeatedly depth-limit search till the
    // maximum depth.
    for (int i = 0; i <= max_depth; i++)
        if (DLS(src, target, i) == true)
            return true;
    return false;
}
//main function
int main()
{
    int count = 0, value = 1;
    bool check = true;
    int ***initial, ***final;
    initial = new int **[6];
    for (int i = 0; i < 6; i++)
    {
        initial[i] = new int *[3];
        for (int j = 0; j < 3; j++)
        {
            initial[i][j] = new int[3];
        }
    }
    final = new int **[6];
    for (int i = 0; i < 6; i++)
    {
        final[i] = new int *[3];
        for (int j = 0; j < 3; j++)
        {
            final[i][j] = new int[3];
        }
    }
    loadFromFile(initial, final);
    //loadState(initial,5);
    if(iterativeDeepening(initial,final,3))
    {
        cout<<"Goal reached!"<<endl;
    }
    aStar(initial, final);
    return 0;
}