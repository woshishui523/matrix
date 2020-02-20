#include <stdio.h>
#include <math.h>
#include <string.h>
#include "Final_one.h"

int main() {
	Matrix matrix;
	bool all_win = true;
	End end;
	int choice = 1;
	int i_change = 0, j_change = 0;//横纵轴变化量
	int i_now = 1, j_now = 1;
	int i_cross = 1, j_cross = 1; //所要换入换出变量坐标
	int i_rel = ii + i_change, j_rel = jj + j_change;
	Get_matrix(matrix);
	for (Get_check(matrix, i_cross,j_cross, all_win, i_change, j_change); all_win == false; Get_check(matrix, i_cross,j_cross, all_win, i_change, j_change))
	{
		Find_cross(matrix, i_cross, j_cross, i_change, j_change);
		solve(matrix, i_cross, j_cross, i_change, j_change);
	}
	For_check(matrix, i_change, j_change);
	Get_matrix2(matrix, i_change, j_change);
	for (Get_check(matrix, i_cross,j_cross, all_win, i_change, j_change); all_win == false; Get_check(matrix,i_cross, j_cross, all_win, i_change, j_change))
	{
		Find_cross(matrix, i_cross, j_cross, i_change, j_change);
		solve(matrix, i_cross, j_cross, i_change, j_change);
	}
	For_check(matrix, i_change, j_change);
	if (all_win)
	{
		printf("恭喜你,成功了");
		show(matrix, end, i_change, j_change);
		printf("最优解为\n（");
		for (j_now = 1; j_now <= j_rel - 1; j_now++)
		{
			printf("%3.3f,", end.var[j_now]);
		}
		printf("%3.3f)\n 最优值为%3.3f \n", end.var[j_rel], end.ans);
	}

}

void Get_matrix(Matrix & matrix)
{
	int i_now, j_now;
	float element1[ii + 1][jj + 1] =
	{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,1,1,0,0,0,-1,-1,0,1,0,0,0,0,0,5,
		0,1,0,-1,1,0,0,0,-1,0,1,0,0,0,0,1,
		0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
		0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,
		0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,
		0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1
	};
	memcpy(matrix.equation, element1, sizeof(float) * all);

	float fac[2][15] = { 0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
	0,1,3,-1,2,-1,0,0,0,0,0,0,0,0,0 };

	for (i_now = 1; i_now <= jj - 1; i_now++) {
		matrix.ele[i_now].num = i_now;
		matrix.ele[i_now].fac[1] = fac[0][i_now];
		matrix.ele[i_now].fac[2] = fac[1][i_now];
		if (i_now >= 9)
			matrix.list_basic[i_now - 8] = matrix.ele[i_now];

	}




}

void Get_check(Matrix &matrix, int&i_cross,int &j_cross, bool &all_win, int i_change, int j_change)
{
	int i_now, j_now;
	int i_rel = ii + i_change, j_rel = jj + j_change;
	all_win = true;
	for (j_now = 1; j_now <= j_rel - 1; j_now++) {

		matrix.num_check[j_now] = matrix.ele[j_now].fac[1];
		for (i_now = 1; i_now <= i_rel; i_now++)
		{
			matrix.num_check[j_now] -= matrix.list_basic[i_now].fac[1] * matrix.equation[i_now][j_now];


		}
		if (matrix.num_check[j_now] < matrix.num_check[j_cross])
			j_cross = j_now;
		if (matrix.num_check[j_now] < 0)
			all_win = false;
		if (matrix.num_check[9] != 0 || matrix.num_check[10] != 0)
			all_win = false;
		if (j_cross == 5&&i_cross==1)
			all_win = true;
	}
}

void Find_cross(Matrix & matrix, int & i_cross, int & j_cross, int i_change, int j_change)
{
	int i_now, j_now;
	int i_rel = ii + i_change, j_rel = jj + j_change;
	bool word = true;
	float max_one = matrix.equation[1][1];

	for (i_now = 1, i_cross = 1; i_now <= i_rel; i_now++)
	{
		if (matrix.equation[i_now][j_cross] * matrix.equation[i_now][j_rel] > 0)
		{
			if (word)
				i_cross = i_now;
			if (matrix.equation[i_now][j_rel] / matrix.equation[i_now][j_cross] < matrix.equation[i_cross][j_rel] / matrix.equation[i_cross][j_rel])
				i_cross = i_now;
			word = false;
		}
	}
	if (word == true)
	{
		for (i_now = 1; i_now <= i_rel; i_now++)
		{
			if (matrix.equation[i_now][j_cross] != 0)
			{
				i_cross = i_now;
				break;
			}
		}
	}

}

void solve(Matrix & matrix, int & i_cross, int & j_cross, int i_change, int j_change)
{
	int  i_now, j_now;
	int i_rel = ii + i_change, j_rel = jj + j_change;
	float Ele;
	if (matrix.equation[i_cross][j_cross] != 1)
	{
		for (j_now = 1; j_now <= j_rel; j_now++)
		{
			if (matrix.equation[i_cross][j_cross] * matrix.equation[i_cross][j_now] != 0)
			{
				matrix.equation[i_cross][j_now] = matrix.equation[i_cross][j_now] / matrix.equation[i_cross][j_cross];
			}
		}
	}
	for (i_now = 1; i_now <= i_rel; i_now++)
	{
		if (i_cross != i_now && matrix.equation[i_now][j_cross] != 0)
		{
			Ele = matrix.equation[i_now][j_cross] / matrix.equation[i_cross][j_cross];
			for (j_now = 1; j_now <= j_rel; j_now++)
			{
				matrix.equation[i_now][j_now] = matrix.equation[i_now][j_now] - matrix.equation[i_cross][j_now] * Ele;
			}
		}


	}
	//更改变量
	matrix.list_basic[i_cross] = matrix.ele[j_cross];
	if (j_cross >= 9)
		matrix.list_basic[i_cross] = matrix.ele[j_cross - j_change];


}

void show(Matrix & matrix, End &end, int i_change, int j_change)
{
	int i_now, j_now;
	int i_rel = ii + i_change, j_rel = jj + j_change;
	for (i_now = 1; i_now <= i_rel; i_now++)
	{
		end.var[matrix.list_basic[i_now].num] = matrix.equation[i_now][j_rel];
		end.ans += matrix.ele[matrix.list_basic[i_now].num].fac[1] * matrix.equation[i_now][j_rel];
	}

}

void Get_matrix2(Matrix&matrix, int&i_change, int&j_change) {
	int i_now = 1;
	for (; i_now <= 6; i_now++)//变换矩阵
	{
		matrix.equation[i_now][9] = matrix.equation[i_now][11];
		matrix.equation[i_now][11] = matrix.equation[i_now][13];
		matrix.equation[i_now][10] = matrix.equation[i_now][12];
		matrix.equation[i_now][12] = matrix.equation[i_now][14];
		matrix.equation[i_now][13] = matrix.equation[i_now][15];
	}
	for (i_now = 1; i_now <= 14; i_now++)//变换目标函数
	{
		matrix.ele[i_now].fac[1] = matrix.ele[i_now].fac[2];
	}
	i_change = 0;
	j_change = -2;
}

void For_check(Matrix&matrix,int i_change,int j_change) {
	int i_now, j_now;
	int i_rel = ii + i_change, j_rel = jj + j_change;
	printf("       矩阵如下       \n");
	for (j_now = 1; j_now <= j_rel; j_now++)
	{
		if (j_now < 10)
		    printf("  第%d行  ", j_now);
		else
			printf("  第%d行 ", j_now);
		

	}
	printf("\n");
	for (i_now = 1; i_now <= i_rel; i_now++)
	{
		for (j_now = 1; j_now <= j_rel; j_now++)
		{
			if (matrix.equation[i_now][j_now] < 0)
				printf(" %3.3f  ", matrix.equation[i_now][j_now]);
			else
				printf("  %3.3f  ", matrix.equation[i_now][j_now]);

		}
		printf("\n");
	}
	for (i_now = 1; i_now <= i_rel; i_now++)
	{
		printf("第%d个X%d  ", i_now, matrix.list_basic[i_now].num);

	}
	printf("\n");
	for (j_now = 1; j_now <= j_rel; j_now++)
	{
		printf("X%d为%3.1f  ", j_now, matrix.num_check[j_now]);

	}
	printf("\n");

}


