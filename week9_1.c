#include <stdio.h>
#define n 9
void print_num(int array[n][n]) //ตาราง9x9
{
    int i,j;
    for(i=0 ; i<n ;i++)
    {
        for(j=0 ; j<n ; j++)
        {
            printf("%d  ",array[i][j]); //i=แถวนอน(row) j=แถวตั้ง(column)
        }
            printf("\n");
    }
}
//ตรวจสอบเลขแถวนอน-ตั้ง
int check_num(int table[n][n], int row, int col, int num)
{
    int x;
    for(x=0 ; x<9 ; x++)
    {
        if(table[x][col] == num) //เช็คแถวนอนตัวซ้ำ ถ้าเจอให้ออกรีเทิร์น0
        {
            return 0;
        }
    }
    for(x=0 ; x<9 ; x++)
    {
        if(table[row][x] == num) //เช็คแถวตั้งตัวซ้ำ ถ้าเจอให้ออกรีเทิร์น0
        {
            return 0;
        }
    }
    //เช็คว่าตัวเลขซ้ำในแต่ละบ้าน3x3ไหม ถ้าเจอให้ออกรีเทิร์น0
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    int i,j;
    for(i=0 ; i<3 ; i++) 
    {
        for(j=0 ; j<3 ; j++)
        {
            if(table[i + box_row][j + box_col] == num)
            {
                return 0;
            }
        }
    }
    return 1;
}
//ใส่คำตอบที่ไม่ซ้ำในแนวตั้งและแนวนอน
int answer_num(int table[n][n], int row, int col)
{
    if( row == n - 1 && col == n )
    {
        return 1;
    }
    if(col == n)
    {
        row++;
        col = 0;
    }
    if(table[row][col] >0 )
    {
        return answer_num(table,row,col+1);
    }
    
    int num;
    for(num=1; num <= n; num++)
    {
        if( check_num(table,row,col,num) == 1 )
        {
            table[row][col] = num;
            if(answer_num(table,row,col+1) ==1 )
            {
                return 1;
            }
        }
        table[row][col] = 0;
    }
    
    return 0;
}
//ใส่ตัวเลจตามโจทย์ และ 0 คือช่องว่าง
int main()
{
    int table[n][n] ={ { 9 , 1 , 0 , 7 , 0 , 0 , 0 , 0 , 0 },
                       { 0 , 3 , 2 , 6 , 0 , 9 , 0 , 8 , 0 },
                       { 0 , 0 , 7 , 0 , 8 , 0 , 9 , 0 , 0 },
                       { 0 , 8 , 6 , 0 , 3 , 0 , 1 , 7 , 0 },
                       { 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 6 },
                       { 0 , 5 , 1 , 0 , 2 , 0 , 8 , 4 , 0 },
                       { 0 , 0 , 9 , 0 , 5 , 0 , 3 , 0 , 0 },
                       { 0 , 2 , 0 , 3 , 0 , 1 , 4 , 9 , 0 },
                       { 0 , 0 , 0 , 0 , 0 , 2 , 0 , 6 , 1 } };

    if(answer_num(table,0,0) == 1)
    {
        print_num(table);
    }
    else
    {
        printf("Can't find the answer");
    }
    return 0;
}