//#include <opencv2\highgui.hpp>
//#include <opencv2\imgproc.hpp>
//#include <opencv2\features2d.hpp>
//#include <iostream>
//#include <map>
//
//using namespace std;
//using namespace cv;
//
//void shiftDFT(Mat& fImage) {
//	Mat tmp, q0, q1, q2, q3;
//
//	int cx = fImage.cols / 2;
//	int cy = fImage.rows / 2;
//
//	q0 = fImage(Rect(0, 0, cx, cy));
//	q1 = fImage(Rect(cx, 0, cx, cy));
//	q2 = fImage(Rect(0, cy, cx, cy));
//	q3 = fImage(Rect(cx, cy, cx, cy));
//
//	q0.copyTo(tmp);
//	q3.copyTo(q0);
//	tmp.copyTo(q3);
//
//	q1.copyTo(tmp);
//	q2.copyTo(q1);
//	tmp.copyTo(q2);
//}
//
//Mat DFTFilter(const Mat& inputIMG, const Mat& dftFilter) {
//	Mat padded, result;
//	
//	Mat filter;
//	Mat toMerge[] = { dftFilter,dftFilter };
//
//	merge(toMerge, 2, filter);
//
//	int n = getOptimalDFTSize(inputIMG.cols);
//	int m = getOptimalDFTSize(inputIMG.rows);
//
//	copyMakeBorder(inputIMG, padded, 0, m - inputIMG.rows,0, n - inputIMG.cols,BORDER_CONSTANT,Scalar::all(0));
//
//	Mat planes[] = { Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F) };
//	Mat complexI;
//	merge(planes, 2, complexI);
//
//	dft(complexI, complexI);
//
//	shiftDFT(complexI);
//	mulSpectrums(complexI, filter, complexI, 0);
//	shiftDFT(complexI);
//	idft(complexI, complexI, DFT_SCALE);
//	split(complexI, planes);
//
//	result = planes[0](Rect(0, 0, inputIMG.cols, inputIMG.rows));
//	normalize(result, result, 0, 1, CV_MINMAX);
//
//	return result;
//}
//
//int main(int argc, char * argv) {
//	Mat img;
//
//	img = imread("a.jpg");
//
//	if (img.data != nullptr) {
//		
//		if (img.channels() > 1) {
//			cvtColor(img, img, CV_RGB2GRAY);
//		}
//
//		imshow("Anh goc", img);
//		Mat im6;
//		GaussianBlur(img, im6, Size(11, 11), 0, 0);
//		imshow("Anh da loc qua bo loc Gauss", im6);
//		imwrite("GaussianFilter.png",im6);
//
//		Mat im7;
//		medianBlur(img, im7, 3);
//		imshow("SD bo loc Median", im7);
//		imwrite("MedianFilter.png",im7);
//
//		Mat im8;
//		bilateralFilter(img, im8, 7, 5, 5, 4);
//		imshow("SD bo loc Bilateral", im8);
//		imwrite("BilateralFilter.png", im8);
//
//		int m = getOptimalDFTSize(img.cols);
//		int n = getOptimalDFTSize(img.rows);
//
//		Point center = Point(n / 2, m / 2);
//		Mat tmp = Mat::zeros(n, m, CV_32F);
//		int D0 = 50;
//
//		circle(tmp, cvPoint(tmp.cols / 2, tmp.rows / 2), D0, cvScalarAll(1.0), -1, 0, 0);
//
//		imshow("Bo loc ILPF", tmp);
//		Mat im11 = DFTFilter(img, tmp);
//		imshow("Ket qua loc ILPF", im11);
//		cvWaitKey(0);
//	}
//	return 0;
//}