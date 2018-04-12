#include<stdio.h>  
#include<stdlib.h>

#define M 30
#define N 30

int Arr1[M][M] = {{0}};
int Arr2[N][N] = {{0}};
int newArr[M][M] = {{0}};
int Arr11[M] = {0};
int Arr22[N] = {0};
//向量内积的方法
//不能建立数组的引用。因为数组是一个由若干个元素所组成的集合，所以无法建立一个数组的别名。
int innerProduct(int Arr11[M],int Arr22[M])
{
    int newArr = 0;
    int i = 0;
    for( i = 0;i<M;++i)
    {
        newArr += Arr11[i]*Arr22[i];
        printf(" %d %d = %d\n",Arr11[i],Arr22[i],newArr);
    }
     printf(" ==============\n" );
    return newArr;
}

//主函数
int main()  
{  
    
    int i = 0,j = 0,k = 0;
    int row1,col1,row2,col2; //计算矩阵的行列
    //自动生成两个32*32的矩阵
    for(i = 0;i<M;++i)
    {
        for(j = 0;j<M;++j)
        {
            Arr1[i][j] = j;
             
        }
    }
    for(i = 0;i<N;++i)
    {
        for(j = 0;j<N;++j)
        {
            Arr2[i][j] = j;
           
        }
    }
    printf("Arr1[%d][%d] is:\n",M,M);
   for(i = 0;i<M;++i)
    {
        for(j = 0;j<M;++j)
        {
            printf("%d\t",Arr1[i][j]);
        }
        printf("\n");
    }
    printf("Arr2[%d][%d] is:\n",M,M);
    for(i = 0;i<M;++i)
    {
        for(j = 0;j<M;++j)
        {
            printf("%d\t",Arr2[i][j]);
        }
        printf("\n");
    }
    
    row1 = sizeof(Arr1)/sizeof(Arr1[0]);
    col1 = sizeof(Arr1[0])/sizeof(Arr1[0][0]);

    row2 = sizeof(Arr2)/sizeof(Arr2[0]);
    col2 = sizeof(Arr2[0])/sizeof(Arr2[0][0]);
  
   //将第一个矩阵的行和第二个矩阵的列分别存储，用来做向量的内积
    for( i = 0;i<row1;++i)
    {   
        for( j = 0;j<col2;++j)
        {
	        for(k = 0;k<col2;++k){
				Arr11[k] = Arr1[i][k];
				//printf("Arr1[%d][%d] %d\t",i,k,Arr1[i][k]);
		        Arr22[k] = Arr2[k][j];
		        //printf("Arr2[%d][%d] %d\t",k,j,Arr2[k][j]);
			}
           newArr[i][j] = innerProduct(Arr11,Arr22);
         }
    }

    //打印出新生成的矩阵
    printf("Array[%d][%d] is:\n",M,M);
    for(i = 0;i<M;++i)
    {
        for(j = 0;j<M;++j)
        {
            printf("%d\t",newArr[i][j]);
        }
        printf("\n");
    }
    return 0;  
} 