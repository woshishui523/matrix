#include <stdio.h>
#include <math.h>

constexpr auto ii = 6;
constexpr auto jj = 15;
constexpr auto all = 112;


typedef struct {
	int num; //元素下标
	float fac[3]; //目标每个元素前系数，两个目标
}element;

typedef struct {
	element ele[15]; //储存变量
	float num_check[15]; //检验数表
	float equation[7][16]; //矩阵（包括b)
	element list_basic[7]; //基变量表
}Matrix;

typedef struct {
	float var[jj] = { 0 };
	float ans = 0;
}End;

//处理所用函数

void Get_matrix(Matrix&matrix); //构造matrix
void Get_check(Matrix&matrix, int&i_cross,int &j_cross, bool &all_win, int i_change, int j_change); //得到检验数
void Find_cross(Matrix&matrix, int&i_cross, int&j_cross, int i_change, int j_change);//寻找交点数
void solve(Matrix &matrix, int&i_cross, int&j_cross, int i_change, int j_change);//处理矩阵
void show(Matrix&matrix, End &end, int i_change, int j_change);//得出结果
void Get_matrix2(Matrix&matrix, int&i_change, int&j_change);//更改matrix准备第二次计算
void For_check(Matrix&matrix, int i_change, int j_change);//输出矩阵

