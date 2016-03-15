#include < stdio.h >  
#include < opencv2\opencv.hpp >  
#include < opencv2\gpu\gpu.hpp>
#include < opencv2\stitching\stitcher.hpp >

#ifdef _DEBUG  
#pragma comment(lib, "opencv_core249d.lib")   
#pragma comment(lib, "opencv_imgproc249d.lib")   //MAT processing  
//#pragma comment(lib, "opencv_objdetect249d.lib")   
//#pragma comment(lib, "opencv_gpu249d.lib")  
//#pragma comment(lib, "opencv_features2d249d.lib")  
#pragma comment(lib, "opencv_highgui249d.lib")  
//#pragma comment(lib, "opencv_ml249d.lib")
#pragma comment(lib, "opencv_stitching249d.lib");

#else  
#pragma comment(lib, "opencv_core249.lib")  
#pragma comment(lib, "opencv_imgproc249.lib")  
//#pragma comment(lib, "opencv_objdetect249.lib")  
#pragma comment(lib, "opencv_gpu249.lib")  
//#pragma comment(lib, "opencv_features2d249.lib")  
#pragma comment(lib, "opencv_highgui249.lib")  
//#pragma comment(lib, "opencv_ml249.lib")  
#pragma comment(lib, "opencv_stitching249.lib")
#endif  


using namespace cv;  
using namespace std;


void main()  
{
	vector< Mat > vImg;
	
	vector< vector< Rect > > vvRect;
	Mat rImg;

	vImg.push_back( imread(".\\stitching_img\\shanghai01.jpg") );	
	vImg.push_back( imread(".\\stitching_img\\shanghai02.jpg") );
	vImg.push_back( imread(".\\stitching_img\\shanghai03.jpg") );	
	//vImg.push_back( imread(".\\stitching_img\\m3.jpg") );


	//Mat A = imread(".\\stitching_img\\m1.jpg");
	//imshow("a",A);
	//Mat B = imread("./B.jpg");
	//imshow("b",B);
	//waitKey(0);


	//vImg.push_back( imread("./A.jpg") );
	//vImg.push_back( imread("./B.jpg") );

	



	 


	/*
	vector< Rect > vRect1;
	vRect1.push_back( Rect(122,0,99,234) );s
	vRect1.push_back( Rect(122,234,99,234) );
	vRect1.push_back( Rect(220,0,99,234) );
	vRect1.push_back( Rect(220,234,99,234) );
	vvRect.push_back( vRect1 );

	vector< Rect > vRect2;
	vRect2.push_back( Rect(0,0,101,229) );
	vRect2.push_back( Rect(0,229,101,229) );
	vRect2.push_back( Rect(101,0,101,229) );
	vRect2.push_back( Rect(101,229,101,229) );
	vvRect.push_back( vRect2 );
	*/

	
	
	int c = gpu::getCudaEnabledDeviceCount();
	printf("Gpu Device %d\n", c);

	Stitcher stitcher = Stitcher::createDefault(1);


	unsigned long AAtime=0, BBtime=0;
	AAtime = getTickCount();

	//stitcher.stitch(vImg, vvRect, rImg);
	stitcher.stitch(vImg, rImg);

	BBtime = getTickCount();	
	printf("ProcessingTime %.2lf sec \n",  (BBtime - AAtime)/getTickFrequency() );

	imshow("Stitching Result", rImg);

	waitKey(0);

	imwrite("output.jpg", rImg);


	





	

}  