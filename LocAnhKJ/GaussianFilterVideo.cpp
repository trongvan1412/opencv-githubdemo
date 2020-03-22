#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened()) {
		cout << "Error";
		return 1;
	}
	//add this code line, so that i will see change
	//int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	//int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	//VideoWriter video("FilterVideo.mp4",CV_FOURCC('M','P','4','2'),30,Size(frame_width,frame_height));

	while (true) {
		Mat frame;
		cap >> frame;
		//video.write(frame);
		if (frame.empty()) {
			break;
		}

		/*if (frame.channels() > 1) {
			cvtColor(frame, frame, CV_RGB2GRAY);
		}*/

		namedWindow("Original Video", WINDOW_FULLSCREEN);
		imshow("Original Video", frame);

		//Mat imG;
		//GaussianBlur(frame, imG, Size(11, 11), 0, 0, 4);
		////video.write(frame);
		//namedWindow("Filtered Video By GaussianFilter", WINDOW_FREERATIO);
		//imshow("Filtered Video By GaussianFilter", imG);

		//imwrite("D:\\GaussianFilterVideo.mp4", imG,);

		char c = (char)waitKey(15);
		if (c == 27) break;

	}
	cap.release();
	//video.release();
	destroyAllWindows();
	return 0;
}