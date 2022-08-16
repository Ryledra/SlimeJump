#include "engineMaths.h"

namespace engineMaths	
{
	GLfloat* addMatrix(GLfloat mat1 [], GLfloat mat2 [])	
	{
		int lenMat1 { sizeof(&mat1)/sizeof(&mat1[0]) };
		int lenMat2 { sizeof(&mat2)/sizeof(&mat2[0]) };
		if(lenMat1 == lenMat2)	
		{
			GLfloat outMat [lenMat1]; // = {0.0f} * lenMat1;
			for(int i { 0 }; i <= lenMat1; ++i)	
			{
				outMat[i] = mat1[i] + mat2[i];
			}
			return outMat;
		} else return mat1;
	}
}