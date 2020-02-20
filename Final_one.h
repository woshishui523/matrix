#include <stdio.h>
#include <math.h>

constexpr auto ii = 6;
constexpr auto jj = 15;
constexpr auto all = 112;


typedef struct {
	int num; //Ԫ���±�
	float fac[3]; //Ŀ��ÿ��Ԫ��ǰϵ��������Ŀ��
}element;

typedef struct {
	element ele[15]; //�������
	float num_check[15]; //��������
	float equation[7][16]; //���󣨰���b)
	element list_basic[7]; //��������
}Matrix;

typedef struct {
	float var[jj] = { 0 };
	float ans = 0;
}End;

//�������ú���

void Get_matrix(Matrix&matrix); //����matrix
void Get_check(Matrix&matrix, int&i_cross,int &j_cross, bool &all_win, int i_change, int j_change); //�õ�������
void Find_cross(Matrix&matrix, int&i_cross, int&j_cross, int i_change, int j_change);//Ѱ�ҽ�����
void solve(Matrix &matrix, int&i_cross, int&j_cross, int i_change, int j_change);//�������
void show(Matrix&matrix, End &end, int i_change, int j_change);//�ó����
void Get_matrix2(Matrix&matrix, int&i_change, int&j_change);//����matrix׼���ڶ��μ���
void For_check(Matrix&matrix, int i_change, int j_change);//�������

